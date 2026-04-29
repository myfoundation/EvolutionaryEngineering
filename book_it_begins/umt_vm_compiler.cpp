#include <stdlib.h>
#include <stdarg.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define LOG printf

//------------------------------------------
// КОМПИЛЯТОР ДЛЯ УНИВЕРСАЛЬНОЙ МАШИНЫ ТЬЮРИНГА (УМТ)
//------------------------------------------

//------------------------------------------
// СИСТЕМА КОМАНД VM
//------------------------------------------
typedef enum
{
    // Достаточный набор команд для УМТ
    LD_IN,   // Считать входной сигнал в регистр
    JMP,     // Безусловный переход. Перейти по адресу Y
    JMP_IF,  // Условный переход. Если вход == X, перейти по адресу Y, иначе — к следующей команде
    EXEC,    // Выполнить внешнее действие Z
    SET_S,   // Сменить номер состояния в регистре состояний
    LABEL,   // Маркер метки для JMP_IF
    BREAK,   // Точка останова (DEBUG)
    HALT,     // Остановка машины

    OpCodes_Total
} OpCode;

// Размеры команд (сколько ячеек памяти занимает команда вместе с аргументами)
const int OP_SIZE[] =
{
    1, // LD_IN
    2, // JMP <метка>
    3, // JMP_IF <условие> <метка>
    2, // EXEC <номер_действия>
    2, // SET_S <номер_состояния>
    2, // LABEL <номер_метки>
    1, // BREAK
    1  // HALT
};

// Названия команд для ассемблера и мониторинга
const char* MNEMONICS[] =
{
    "LD_IN", "JMP", "JMP_IF", "EXEC", "SET_S", "LABEL", "BREAK", "HALT"
};
//------------------------------------------

//------------------------------------------
// GENERATE & COMPLILE PROGRAM BY FSM TABLE
//------------------------------------------
typedef struct { int state, action; } Step;
struct Compiler
{
    char *ascii;    // Ассемблерный код
    int *bin;       // Байткод
    int *bin_p;
    char *ascii_p;
};

// Замена id переходов в байткоде на смещения
void set_jmps(int *base, int *end, int id_count)
{
    int *address_tab = (int*)malloc(id_count * sizeof(int));

    // Pass 1: Собираем адреса меток
    int *p = base;
    while (p < end)
    {
        if (*p == LABEL) address_tab[p[1]] = (int)(p - base);
        p += OP_SIZE[*p];
    }

    // Pass 2: Дизассемблируем код и заменяем id меток на смещения от base
    p = base;
    while (p < end)
    {
        OpCode op = (OpCode)*p;
        if (op == LABEL)  p[1] = (int)(p - base);
        if (op == JMP)    p[1] = address_tab[p[1]];
        if (op == JMP_IF) p[2] = address_tab[p[2]];
        p += OP_SIZE[op];
    }

    free(address_tab);
}

void emit(Compiler &C, OpCode op, ...)
{
    va_list ap;
    va_start(ap, op);

    //------------------------------------------
    // Компиляция байткода
    *C.bin_p++ = op;
    //------------------------------------------

    //------------------------------------------
    // Компиляция ассемблерного кода
    C.ascii_p += sprintf(C.ascii_p, "  %-7s", MNEMONICS[op]);
    for (int i = 0; i < OP_SIZE[op] - 1; i++)
    {
        int val = va_arg(ap, int);
        *C.bin_p++ = val;
        C.ascii_p += sprintf(C.ascii_p, (i == 0) ? " %-3d" : ", %-3d", val);
    }
    C.ascii_p += sprintf(C.ascii_p, "\n");
    //------------------------------------------

    va_end(ap);
}

int compile(Compiler &C, Step **matrix, int n_states, int n_inputs, const char *in_mset)
{
/*
    Биекция "Граф -> Код":
    Архитектура: Линейный диспетчер с выносом обработчиков.

    Каждый узел графа разворчивается в 3 блока ассемблерных комманд

    1. Блок опроса (Inputs Handler)
    2. Блок диспетчера (Dispatcher): Компактный список JMP_IF для быстрой
       проверки входящих символов. Если ни одно не сработало — возврат в Блок опроса.
    3. Блок исполнения и перехода (Outputs Handler): Изолированные сегменты EXEC + JMP,
 */

    C.bin_p = C.bin;
    C.ascii_p = C.ascii;

    int id = 0;

    // "Дерево" на индексах: разметка всех точек входа
    int *ls = (int*)malloc(n_states * sizeof(int)); // метки обработки состояний
    int *ll = (int*)malloc(n_states * sizeof(int)); // метки блоков с циклом ожидания входящего сигнала
    for (int i = 0; i < n_states; i++) { ls[i] = id++; ll[i] = id++; }

    for (int s = 0; s < n_states; s++)
    {
        //------------------------------------------
        // 1. Установка текущго состояния и ожидание входящего сигнала
        emit(C, LABEL, ls[s]);
        emit(C, SET_S, s);
        emit(C, LABEL, ll[s]);
        emit(C, LD_IN);
        //------------------------------------------

        int start_br = id; // Запоминаем, с какого ID начинаются обработчики этого состояния. Сами обработчики вынесены за цикл опроса (линейная структура).

        //------------------------------------------
        // 2. Блок диспетчера: Генерация ребер (переходов)
        for (int i = 0; i < n_inputs; i++) emit(C, JMP_IF, in_mset[i], id++);
        emit(C, JMP, ll[s]); // Если ни одно условие не сработало, возвращаемся на LD_IN
        //------------------------------------------

        //------------------------------------------
        // 3. Блок генерации исходящих сигналов и перехода в блок Диспетчера следующего состояния
        for (int i = 0; i < n_inputs; i++)
        {
            emit(C, LABEL, start_br + i); // Используем сохраненную метку
            emit(C, EXEC, matrix[s][i].action);
            emit(C, JMP, ls[matrix[s][i].state]);
        }
        //------------------------------------------
    }

    emit(C, HALT);
    set_jmps(C.bin, C.bin_p, id); // Расчёт и установка смещений в JMP и JMP_IF

    free(ls); free(ll);
    return (int)(C.bin_p - C.bin);
}
//------------------------------------------

int save_bin(const char *fname, char *b, size_t n)
{
    FILE *f = fopen(fname, "wb");
    if (!f) return 0;
    size_t r = fwrite(b, 1, n, f);
    fclose(f);
    return r == n;
}

//------------------------------------------
// FSM ДЛЯ КОМПИЛЯЦИИ
//------------------------------------------
#define ROW(...) (Step[]){ __VA_ARGS__ }
Step *Machine_Limonad[] =
{
                    /*     M       V      T        P      O    */
    /* S0  */ [0] = ROW({1, 0}, {3, 3}, {0, 4}, {0, 2}, {0, 4}),
    /* S1  */ [1] = ROW({2, 0}, {3, 3}, {0, 1}, {1, 2}, {0, 7}),
    /* S2  */ [2] = ROW({0, 5}, {3, 3}, {0, 1}, {2, 2}, {0, 7}),
    /* ERR */ [3] = ROW({3, 6}, {3, 6}, {3, 6}, {3, 6}, {3, 6})
};
const char *Inputs = "MVTPO";
//------------------------------------------

//------------------------------------------
// FSM -> C TRANSPILLER
//------------------------------------------
// SWITCH VERSION
void transpile_C_switch(char* p, Step **matrix, int n_states, int n_inputs, const char *in_mset)
{
    p += sprintf(p, "void machine_logic(int in_signal)\n{\n    switch (state)\n    {\n");

    for (int s = 0; s < n_states; s++)
    {
        p += sprintf(p, "        case S%d:\n        {\n            switch (in_signal)\n            {\n", s);
        for (int i = 0; i < n_inputs; i++)
        {
            // Биекция: Входной символ -> Ветвь Case -> Вызов функции перехода
            p += sprintf(p, "                case '%c':\n                {\n", in_mset[i]);
            p += sprintf(p, "                    process_step(S%d, A%d);\n", matrix[s][i].state, matrix[s][i].action);
            p += sprintf(p, "                    break;\n                }\n");
        }
        p += sprintf(p, "            }\n            break;\n        }\n");
    }
    p += sprintf(p, "    }\n}\n");
}

// GOTO VERSION
void transpile_C_goto(char* p, Step **matrix, int n_states, int n_inputs, const char *in_mset)
{
    p += sprintf(p, "void machine_logic(int in_signal)\n{\n    /* Диспетчер входа в фазу (State Entry Dispatcher) */\n");

    for (int s = 0; s < n_states; s++) p += sprintf(p, "    if (state == S%d) goto L_S%d;\n", s, s);

    p += sprintf(p, "    return;\n\n");

    for (int s = 0; s < n_states; s++)
    {
        p += sprintf(p, "L_S%d:\n{\n", s);
        for (int i = 0; i < n_inputs; i++)
        {
            p += sprintf(p, "    if (in_signal == '%c')\n    {\n        process_step(S%d, A%d);\n        return;\n    }\n",
                         in_mset[i], matrix[s][i].state, matrix[s][i].action);
        }
        p += sprintf(p, "    return;\n}\n\n");
    }

    p += sprintf(p, "}\n");
}

//------------------------------------------


int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");

    LOG("\n--- КОМПИЛЯТОР FSM ДЛЯ КЛАССИЧЕСКОЙ VM C ИНЖЕНЕРНЫМ МОНИТОРОМ (1960) ---\n");

    // Выделение буфера: ~1024 байт на каждое ребро графа
    int MEM_LEN = 4 * 5 * 1024 + 1024; // n_states * n_inputs * 1024

    char* ASM  = (char*)malloc(MEM_LEN);
    char* BIN  = (char*)malloc(MEM_LEN);
    char* C_CODE_1  = (char*)malloc(MEM_LEN);
    char* C_CODE_2  = (char*)malloc(MEM_LEN);

    //------------------------------------------
    // КОМПИЛЯЦИЙ В БАЙТКОД VM
    //------------------------------------------
    Compiler C;
    C.bin = (int*)BIN;
    C.ascii = ASM;
    int len = compile(C, Machine_Limonad, 4, 5, Inputs);
    //------------------------------------------

    //------------------------------------------
    // ТРАНСПИЛЯЦИЯ В С
    //------------------------------------------
    transpile_C_switch(C_CODE_1, Machine_Limonad, 4, 5, Inputs);
    transpile_C_goto(C_CODE_2, Machine_Limonad, 4, 5, Inputs);
    //------------------------------------------

    if(len)
    {
        LOG("\nКОМПИЛЯЦИЯ УСПЕШНА. ФАЙЛЫ:\nАССЕМБЛЕР - machine_limonad.asm\nБАЙТКОД FSM - machine_limonad.bin\nC-КОД (SWITCH) - machine_limonad_1.cpp\nC-КОД (GOTO) - machine_limonad_2.cpp");
        save_bin("machine_limonad.bin", BIN, len * sizeof(int));
        save_bin("machine_limonad.asm", ASM, strlen(ASM));
        save_bin("machine_limonad_1.cpp", C_CODE_1, strlen(C_CODE_1));
        save_bin("machine_limonad_2.cpp", C_CODE_2, strlen(C_CODE_2));
    }
    else
    {
        LOG("\nОШИБКА КОМПИЛЯЦИИ");
    }
    free(ASM); free(BIN); free(C_CODE_1); free(C_CODE_2);

    getch();
    return 0;
}



