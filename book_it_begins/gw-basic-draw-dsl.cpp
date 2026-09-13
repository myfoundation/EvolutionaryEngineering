// gw-basic-draw-dsl.cpp

/*
GW-BASIC (Microsoft, 1983), функция рисования DRAW, это `DSL` для рисования на экране. Принимает ассемблеро-подобный набор команд.

+---------+-------------------------+-----------------------------------+
| Команда | Физическое Действие     | Математика смещения Координат     |
+---------+-------------------------+-----------------------------------+
| U x     | Перо вверх на x         | Y = Y - x                         |
+---------+-------------------------+-----------------------------------+
| D x     | Перо вниз на x          | Y = Y + x                         |
+---------+-------------------------+-----------------------------------+
| L x     | Перо влево на x         | X = X - x                         |
+---------+-------------------------+-----------------------------------+
| R x     | Перо вправо на x        | X = X + x                         |
+---------+-------------------------+-----------------------------------+
| E x     | Вверх-вправо диагональ  | X = X + x, Y = Y - x              |
+---------+-------------------------+-----------------------------------+
| F x     | Вниз-вправо диагональ   | X = X + x, Y = Y + x              |
+---------+-------------------------+-----------------------------------+
| G x     | Вниз-влево диагональ    | X = X - x, Y = Y + x              |
+---------+-------------------------+-----------------------------------+
| H x     | Вверх-влево диагональ   | X = X - x, Y = Y - x              |
+---------+-------------------------+-----------------------------------+
| M x,y   | Абсолютный переход в x,y| X = x, Y = y                      |
+---------+-------------------------+-----------------------------------+
| M +x,-y | Относительный переход   | X = X + x, Y = Y - y              |
+---------+-------------------------+-----------------------------------+
| B cmd   | Префикс: без рисования  | Смещение согласно cmd             |
|         | только переместить перо | Перо поднято: Lines drawn = 0     |
+---------+-------------------------+-----------------------------------+
| N cmd   | Префикс: после движения | Смещение согласно cmd, затем:     |
|         | вернуть перо в исходную | X = X_start, Y = Y_start          |
+---------+-------------------------+-----------------------------------+
| A n     | Поворот на n*90 град.   | n=0..3;                           |
|         | (от 0 до 270 градусов)  | Угол = n * 90                     |
+---------+-------------------------+-----------------------------------+
| TA x    | Вращение осей на x      | X' = X*cos(x) - Y*sin(x)          |
|         | градусов                | Y' = X*sin(x) + Y*cos(x)          |
+---------+-------------------------+-----------------------------------+
| C n     | Выбор индекса цвета n   | Палитра[n];                       |
|         | для последующих линий   | Текущий_Цвет = n                  |
+---------+-------------------------+-----------------------------------+
| S n     | Установить масштаб n    | Коэффициент = n / 4               |
|         | (размер шага)           | Все dx, dy умножаются на (n / 4)  |
+---------+-------------------------+-----------------------------------+
| P f,b   | Заливка цветом f до     | Рекурсивный flood_fill в (X, Y)   |
|         | границы цвета b         | Граница остановки = b             |
+---------+-------------------------+-----------------------------------+
| X str$; | Выполнить подстроку     | Вызов вложенной макрокоманды      |
|         | макрокоманд из перемен. | Состояние VM сохраняется в стек   |
+---------+-------------------------+-----------------------------------+

(* =================================================================-- *)
(* СПЕЦИФИКАЦИЯ GW-BASIC DRAW DSL        *)
(* =================================================================-- *)

DrawScript    = { Separator } , [ CommandSequence ] , { Separator } ;

CommandSequence = Command , { Separator , Command } ;

Command       = [ Prefix , { Separator } ] , Action ;

Prefix        = "B" | "b" | "N" | "n" ;

Action        = VectorOp , [ Separator ] , SignedNumber
              | MoveOp , [ Separator ] , SignedNumber , Separator , SignedNumber
              | StateOp , [ Separator ] , Number
              | TurnOp , [ Separator ] , SignedNumber ;

VectorOp      = "U" | "u" | "D" | "d" | "L" | "l" | "R" | "r"
              | "E" | "e" | "F" | "f" | "G" | "g" | "H" | "h" ;

MoveOp        = "M" | "m" ;

StateOp       = "C" | "c" | "S" | "s" | "A" | "a" ;

TurnOp        = "TA" | "Ta" | "tA" | "ta" ;

SignedNumber  = [ Sign ] , Number ;

Sign          = "+" | "-" ;

Number        = Digit , { Digit } ;

Digit         = "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9" ;

Separator     = SeparatorChar , { SeparatorChar } ;

SeparatorChar = " " | "	" | "," ;

*/

/* =================================================================-- */
/* ТРАНСЛЯТОР GW-BASIC DRAW DSL (ISO C99, ALLMAN STYLE)  */
/* =================================================================-- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define MATCH_ if(0){;}
#define CASE_(x) else if((x))
#define DEFAULT_ else

#define LOG printf

#define WIDTH        128  /* Ширина растрового поля экрана */
#define HEIGHT       128  /* Высота растрового поля экрана */
#define MAX_ARGS     2    /* Максимум аргументов у команды */
#define PI           3.14159265358979323846

/* Коды операций байт-кода виртуальной машины */
typedef enum
{
    OP_ERR         = 0x00, /* Код ошибки / невалидный токен */
    OP_PREF_NODRAW = 0x10, /* Флаг 'B': сместить перо без рисования */
    OP_PREF_NOMOVE = 0x11, /* Флаг 'N': вернуть перо после движения */
    OP_VEC_U       = 0x20, /* Вектор: перо вверх (Y-) */
    OP_VEC_D       = 0x21, /* Вектор: перо вниз (Y+) */
    OP_VEC_L       = 0x22, /* Вектор: перо влево (X-) */
    OP_VEC_R       = 0x23, /* Вектор: перо вправо (X+) */
    OP_VEC_E       = 0x24, /* Вектор: диагональ вверх-вправо */
    OP_VEC_F       = 0x25, /* Вектор: диагональ вниз-вправо */
    OP_VEC_G       = 0x26, /* Вектор: диагональ вниз-влево */
    OP_VEC_H       = 0x27, /* Вектор: диагональ вверх-влево */
    OP_MOVE        = 0x30, /* Команда 'M': абсолютный/относительный ход */
    OP_SET_COLOR   = 0x40, /* Команда 'C': установить индекс цвета */
    OP_SET_SCALE   = 0x41, /* Команда 'S': установить масштаб шага */
    OP_SET_ANGLE   = 0x42, /* Команда 'A': поворот осей кратно 90 град. */
    OP_TURN_AXIS   = 0x43  /* Команда 'TA': вращение осей на произвольный угол */
} OpCode;

/* Дискретный вектор направления для ортогональных/диагональных ходов */
typedef struct
{
    signed char dx;       /* Шаг по оси X (-1, 0, 1) */
    signed char dy;       /* Шаг по оси Y (-1, 0, 1) */
} MoveVector;

/* Статическая конфигурация команды (Управляющая таблица) */
typedef struct
{
    unsigned char opcode; /* Идентификатор инструкции байт-кода */
    unsigned char args;   /* Требуемое количество аргументов (0..2) */
    MoveVector vec;       /* Направление (только для векторных команд) */
} Op_vm;

/* Физическое состояние исполнительной системы (Регистры VM) */
typedef struct
{
    double x;             /* Регистр X: текущая координата пера */
    double y;             /* Регистр Y: текущая координата пера */
    int angle;            /* Регистр ANGLE: угол вращения осей */
    int scale;            /* Регистр SCALE: множитель шага */
    int color;            /* Регистр COLOR: активный индекс цвета */
    int no_draw;          /* Регистр-префикс B: блокировка рисования */
    int no_move;          /* Регистр-префикс N: блокировка смещения пера */
    int width;
    int height;
    unsigned char *scr;   /* Буфер памяти плоскости экрана */
} DrawVM;

/* Глобальная статическая таблица трансляции ASCII-символов в свойства команд */
static const Op_vm ASCII_MAP[256] =
{
    ['U'] = { OP_VEC_U, 1, { 0, -1} }, ['u'] = { OP_VEC_U, 1, { 0, -1} },
    ['D'] = { OP_VEC_D, 1, { 0,  1} }, ['d'] = { OP_VEC_D, 1, { 0,  1} },
    ['L'] = { OP_VEC_L, 1, { -1, 0} }, ['l'] = { OP_VEC_L, 1, { -1, 0} },
    ['R'] = { OP_VEC_R, 1, {  1, 0} }, ['r'] = { OP_VEC_R, 1, {  1, 0} },
    ['E'] = { OP_VEC_E, 1, {  1,-1} }, ['e'] = { OP_VEC_E, 1, {  1,-1} },
    ['F'] = { OP_VEC_F, 1, {  1, 1} }, ['f'] = { OP_VEC_F, 1, {  1, 1} },
    ['G'] = { OP_VEC_G, 1, { -1, 1} }, ['g'] = { OP_VEC_G, 1, { -1, 1} },
    ['H'] = { OP_VEC_H, 1, { -1,-1} }, ['h'] = { OP_VEC_H, 1, { -1,-1} },
    ['M'] = { OP_MOVE,        2, { 0,  0} }, ['m'] = { OP_MOVE,        2, { 0,  0} },
    ['B'] = { OP_PREF_NODRAW, 0, { 0,  0} }, ['b'] = { OP_PREF_NODRAW, 0, { 0,  0} },
    ['N'] = { OP_PREF_NOMOVE, 0, { 0,  0} }, ['n'] = { OP_PREF_NOMOVE, 0, { 0,  0} },
    ['C'] = { OP_SET_COLOR,   1, { 0,  0} }, ['c'] = { OP_SET_COLOR,   1, { 0,  0} },
    ['S'] = { OP_SET_SCALE,   1, { 0,  0} }, ['s'] = { OP_SET_SCALE,   1, { 0,  0} },
    ['A'] = { OP_SET_ANGLE,   1, { 0,  0} }, ['a'] = { OP_SET_ANGLE,   1, { 0,  0} }
};

/* Растрирование линии (Алгоритм Брезенхема) */
static void draw_line(unsigned char *pixels, int w, int h, int x0, int y0, int x1, int y1, int col)
{
    int dx = abs(x1 - x0), dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1, sy = (y0 < y1) ? 1 : -1, err = dx - dy;
    while (1)
    {
        if (x0 >= 0 && x0 < w && y0 >= 0 && y0 < h) pixels[y0 * w + x0] = col;
        if (x0 == x1 && y0 == y1) break;
        int e2 = 2 * err;
        if (e2 > -dy) { err -= dy; x0 += sx; }
        if (e2 < dx) { err += dx; y0 += sy; }
    }
}

/* Автоматная функция: пропуск разделителей */
static void skip_spaces(const char** p)
{
    while (**p == ' ' || **p == '\t' || **p == ',')
    {
        (*p)++;
    }
}

/* Автоматная функция: выделение знака и числа */
static int parse_arg(const char** p, int* is_rel)
{
    skip_spaces(p);
    *is_rel = (**p == '+' || **p == '-');
    int sign = (**p == '-') ? -1 : 1;
    if (*is_rel)
    {
        (*p)++;
    }
    int val = (int)strtol(*p, (char**)p, 10);
    return sign * val;
}

/* Вычислительное ядро: автомат исполнения инструкций байт-кода */
static void execute_op(DrawVM* vm, unsigned char opcode, MoveVector vec, int v1, int r1, int v2, int r2)
{
    double old_x = vm->x;
    double old_y = vm->y;
    double nx = vm->x;
    double ny = vm->y;

    MATCH_
    CASE_(opcode >= OP_VEC_U && opcode <= OP_VEC_H)
    {
        /* Рассчитать смещение вектора с учетом регистра масштаба */
        double step = v1 * (vm->scale / 4.0);
        double dx_scaled = vec.dx * step;
        double dy_scaled = vec.dy * step;
        double rad = vm->angle * PI / 180.0;

        /* Применить матрицу поворота осей */
        nx = old_x + (dx_scaled * cos(rad) - dy_scaled * sin(rad));
        ny = old_y + (dx_scaled * sin(rad) + dy_scaled * cos(rad));
    }
    CASE_(opcode == OP_MOVE)
    {
        /* Вычислить координаты абсолютного или относительного перемещения */
        nx = r1 ? old_x + v1 : v1;
        ny = r2 ? old_y + v2 : v2;
    }
    CASE_(opcode == OP_SET_COLOR)
    {
        vm->color = v1;
    }
    CASE_(opcode == OP_SET_SCALE)
    {
        if (v1 > 0) vm->scale = v1;
    }
    CASE_(opcode == OP_SET_ANGLE)
    {
        vm->angle = (v1 * 90) % 360;
    }
    CASE_(opcode == OP_TURN_AXIS)
    {
        vm->angle = (vm->angle + v1) % 360;
    }

    /* Проверить условия изменения растра и регистров позиций */
    if ((opcode >= OP_VEC_U && opcode <= OP_MOVE))
    {
        if (!vm->no_draw)
        {
            draw_line(vm->scr, vm->width, vm->height, (int)round(old_x), (int)round(old_y), (int)round(nx), (int)round(ny), vm->color);
        }
        if (!vm->no_move)
        {
            vm->x = nx;
            vm->y = ny;
        }

        /* Автомат исполнил команду: теперь сбросить временные регистры префиксов */
        vm->no_draw = 0;
        vm->no_move = 0;
    }
}

/* Разбор строки DSL */
void DRAW(DrawVM* vm, const char* p)
{
    LOG("VM EXEC: %s\n", p);

    while (*p)
    {
        skip_spaces(&p);
        if (!*p)
        {
            break;
        }

        unsigned char symbol = (unsigned char)*p++;
        Op_vm cmd = ASCII_MAP[symbol];

        MATCH_
        CASE_(cmd.opcode == OP_PREF_NODRAW)
        {
            vm->no_draw = 1; /* Установить флаг в регистре VM */
        }
        CASE_(cmd.opcode == OP_PREF_NOMOVE)
        {
            vm->no_move = 1; /* Установить флаг в регистре VM */
        }
        CASE_(symbol == 'T' || symbol == 't')
        {
            if (*p == 'A' || *p == 'a')
            {
                p++;
                int r1 = 0;
                int v1 = parse_arg(&p, &r1);
                execute_op(vm, OP_TURN_AXIS, cmd.vec, v1, r1, 0, 0);
            }
        }
        CASE_(cmd.opcode != OP_ERR)
        {
            int v1 = 0, r1 = 0, v2 = 0, r2 = 0;
            if (cmd.args > 0) v1 = parse_arg(&p, &r1);
            if (cmd.args > 1) v2 = parse_arg(&p, &r2);

            execute_op(vm, cmd.opcode, cmd.vec, v1, r1, v2, r2);
        }
        DEFAULT_
        {
            p++;
        }
    }
}

/* Функция записи экрана в файл PBM */
void save_pbm(unsigned char* scr, int w, int h, const char* filename)
{
    FILE* f = fopen(filename, "w");
    if (!f) return;
    fprintf(f, "P1\n%d %d\n", w, h);
    for (int y = 0; y < h; y++)
    {
        for (int x = 0; x < w; x++)
        {
            fprintf(f, "%d%c", scr[y * w + x] ? 1 : 0, (x == w - 1) ? '\n' : ' ');
        }
    }
    fclose(f);

    LOG("FILE %s GENERATED.\n", filename);
}

/* Обязательный промышленный тест целостности и биекций системы */
void integrity_check(void)
{
    /* Создать изолированный контекст виртуальной машины */
    DrawVM* vm = (DrawVM*)calloc(1, sizeof(DrawVM));
    vm->width = WIDTH;
    vm->height = HEIGHT;
    vm->scr = (unsigned char*)calloc(1, vm->width * vm->height);
    vm->x = vm->width / 2.0;
    vm->y = vm->height / 2.0;
    vm->scale = 4;
    vm->color = 1;

    /* Тест 1: Замкнутый контур */
    DRAW(vm, "R20 D20 L20 U20");

    /* Тест 2: Префиксы и вращения осей через TA */
    DRAW(vm, "BM 20,20 S8 TA45 R10 L20 R10 TA-45 U10 D20 U10");
    assert(fabs(vm->x - 20.0) < 1e-6);
    assert(fabs(vm->y - 20.0) < 1e-6);

    /* Тест 3: Относительное перемещение по осям */
    DRAW(vm, "M +10,-5");
    assert(fabs(vm->x - 30.0) < 1e-6);
    assert(fabs(vm->y - 15.0) < 1e-6);

    save_pbm(vm->scr, vm->width, vm->height, "screen.pbm");
    free(vm->scr); free(vm);
    LOG("INTEGRITY CHECK PASSED.\n");
}

int main(int argc, char *argv[])
{
    LOG("------------------------------------------\n"
        "GW-BASIC (Microsoft, 1983) DRAW() DSL\n"
        "------------------------------------------\n"
        "1. PUT DSL AS 1-st QUOTED PARAM "
        "2. (THEN SCREEN WIDTH AND HEIGHT IF YOU NEED) \nAND SEE AS TEXT FILE screen.pbm \n"
        "3. F.E.: \"R20 D20 L20 U20\" 128 128\n\n"
        "------------------------------------------\nSTART\n"
        "------------------------------------------\n\n");

    if(argc > 1)
    {
        DrawVM* vm = (DrawVM*)calloc(1, sizeof(DrawVM));
        vm->width = (argc == 4) ? atoi(argv[2]):WIDTH;
        vm->height = (argc == 4) ? atoi(argv[3]):HEIGHT;
        vm->scr = (unsigned char*)calloc(1, vm->width * vm->height);
        vm->x = vm->width / 2.0;
        vm->y = vm->height / 2.0;
        vm->scale = 4;
        vm->color = 1;

        DRAW(vm, argv[1]);

        save_pbm(vm->scr, vm->width, vm->height, "screen.pbm");
        free(vm->scr); free(vm);
    }
    else
    {
        integrity_check();
    }

    return 0;
}
