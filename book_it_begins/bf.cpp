#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

#define LOG printf

//------------------------------------------
// ГРАФОВЫЙ ИНТЕРПРЕТАТОР BRAINFUCK
//------------------------------------------

//------------------------------------------
// ОБОЛОЧКА: УМТ
//------------------------------------------
typedef struct { int state, action; } Step;

struct UTM
{
    int REG_S;   // Регистр текущего состояния (Phase)
    int REG_IN;  // Регистр входного сигнала (Input Symbol)
    int REG_OUT; // Регистр выходного действия (Action Symbol)
    Step** ROM;  // Указатель на таблицу переходов (Оцифрованный граф)
};

// Математический акт перехода: вершина графа -> вершина графа
void UTM_Step(struct UTM* machine)
{
    // Выбор строки в таблице отношений по текущему состоянию и входу
    Step node = machine->ROM[machine->REG_S][machine->REG_IN];

    // Обновление регистров
    machine->REG_S   = node.state;  // Выбор следующей вершины графа
    machine->REG_OUT = node.action; // Формирование команды для исполнителя
}
//------------------------------------------

//------------------------------------------
// ДОМЕННАЯ ОБОЛОЧКА: "МЕХАНИЗМЫ" BRAINFUCK
//------------------------------------------

// ОПРЕДЕЛЕНИЕ АЛФАВИТОВ (X и A)
// Входящий алфавит X (Состояние ячейки ленты)
enum BF_IN { IN_ZERO, IN_NZ };
const char* IN_NAMES[] = { "ZERO", "NZ" };

// Исходящий алфавит A (Действия исполнителя)
enum BF_ACTIONS { ACT_ADD, ACT_SUB, ACT_RIGHT, ACT_LEFT, ACT_OUT, ACT_IN, ACT_NOP };
const char* ACT_NAMES[] = { "ADD", "SUB", "RIGHT", "LEFT", "OUT", "IN", "NOP" };

// Выполняет действия в реальном мире.
// Реализует Биекцию между физикой (лентой) и математикой (регистрами УМТ)
struct BF_DSM // DSM - Domain-Specific Machine
{
    unsigned char* RAM;
    int head;     // Индекс выбранной ячейки в массиве памяти
    int n_states; // Номер последнего состояния (конец программы)
};

// "Аппаратная" обвязка специфичная для Brainfuck
void BF_Physical_Interface(struct UTM* utm, BF_DSM* bfm)
{
    switch (utm->REG_OUT)
    {
        //------------------------------------------
        // БЛОК ОПЕРАЦИЙ ALU
        //------------------------------------------
        case ACT_ADD:   bfm->RAM[bfm->head]++; break;
        case ACT_SUB:   bfm->RAM[bfm->head]--; break;
        //------------------------------------------
        // БЛОК ОПЕРАЦИЙ УПРАВЛЕНИЯ RAM (ВЫБОР АКТИВНОЙ ЯЧЕЙКИ)
        //------------------------------------------
        case ACT_RIGHT: bfm->head++; break;
        case ACT_LEFT:  bfm->head--; break;
        //------------------------------------------
        // БЛОК ДЛЯ ПРИЁМА/ОТПРАВЛЕНИЯ СИГНАЛОВ ИЗ/В АППАРАТУРУ
        //------------------------------------------
        case ACT_OUT:   putchar(bfm->RAM[bfm->head]); break;
        case ACT_IN:    bfm->RAM[bfm->head] = (unsigned char)getchar(); break;
        case ACT_NOP:   break; // Состояние покоя исполнителя
    }

    // 3. Физика -> Математика
    // Преобразуем состояние ячейки в индекс входного алфавита X = {0, 1} УМТ
    utm->REG_IN = (bfm->RAM[bfm->head] == 0) ? 0 : 1;
}
//------------------------------------------

//------------------------------------------
// ОБХОДЧИК ГРАФА ПРОГРАММЫ
//------------------------------------------
// Обходит маркированный (или "алгоритмический") граф
void BF_Graph_Traverser(struct UTM* utm, BF_DSM* bfm)
{
    LOG("\nОБХОД ГРАФА НАЧАТ\n");
    while(utm->REG_S < bfm->n_states - 1)
    {
        // 1. Переход по ребру графа, заданному таблицей FSM
        UTM_Step(utm);

        // 2. Математика -> Физика
        // Дешифруем REG_OUT в физические действия над агрегатами
        BF_Physical_Interface(utm, bfm);
    }
    LOG("\nОБХОД ГРАФА ЗАКОНЧЕН\n");
}
//------------------------------------------

//------------------------------------------
// ДОМЕННАЯ МАШИНА (ИСПОЛНИТЕЛЬ ПРОГРАММ BF)
//------------------------------------------
void BF_Machine(struct UTM* utm, BF_DSM* bfm)
{
    // Выполнить программу значит обойти маркированный граф
    BF_Graph_Traverser(utm, bfm);
}
//------------------------------------------

//------------------------------------------
// ТРАНСПИЛЯТОР
//------------------------------------------
// Транспилятор  BF-код -> FSM матрица
/*
Таблица правил для составления Отношения δ:S×X→S×A

+---------+-----------+-----------+-------------+------------+
| КОМАНДА | ТЕКУЩЕЕ   | ВХОД (X)  | СЛЕДУЮЩЕЕ   | ВЫХОД (A)  |
|   BF    | СОСТОЯНИЕ | (Датчик)  | СОСТОЯНИЕ   | (Действие) |
+---------+-----------+-----------+-------------+------------+
|    +    |    Sn     |  0 (ZERO) |    Sn + 1   |  ACT_ADD   |
|    +    |    Sn     |  1 (NZ)   |    Sn + 1   |  ACT_ADD   |
+---------+-----------+-----------+-------------+------------+
|    -    |    Sn     |  0 (ZERO) |    Sn + 1   |  ACT_SUB   |
|    -    |    Sn     |  1 (NZ)   |    Sn + 1   |  ACT_SUB   |
+---------+-----------+-----------+-------------+------------+
|    >    |    Sn     |  0 (ZERO) |    Sn + 1   |  ACT_RIGHT |
|    >    |    Sn     |  1 (NZ)   |    Sn + 1   |  ACT_RIGHT |
+---------+-----------+-----------+-------------+------------+
|    <    |    Sn     |  0 (ZERO) |    Sn + 1   |  ACT_LEFT  |
|    <    |    Sn     |  1 (NZ)   |    Sn + 1   |  ACT_LEFT  |
+---------+-----------+-----------+-------------+------------+
|    .    |    Sn     |  0 (ZERO) |    Sn + 1   |  ACT_OUT   |
|    .    |    Sn     |  1 (NZ)   |    Sn + 1   |  ACT_OUT   |
+---------+-----------+-----------+-------------+------------+
|    ,    |    Sn     |  0 (ZERO) |    Sn + 1   |  ACT_IN    |
|    ,    |    Sn     |  1 (NZ)   |    Sn + 1   |  ACT_IN    |
+---------+-----------+-----------+-------------+------------+
|    [    |   S_open  |  0 (ZERO) |  S_close + 1|  ACT_NOP   |
|    [    |   S_open  |  1 (NZ)   |  S_open + 1 |  ACT_NOP   |
+---------+-----------+-----------+-------------+------------+
|    ]    |   S_close |  0 (ZERO) |  S_close + 1|  ACT_NOP   |
|    ]    |   S_close |  1 (NZ)   |  S_open + 1 |  ACT_NOP   |
+---------+-----------+-----------+-------------+------------+
*/
Step** bf_to_matrix(const char* code, int* n_states_)
{
    int n = (int)strlen(code), sp = -1;
    int* stack = (int*)malloc(n * sizeof(int));
    *n_states_ = n + 1;

    Step** matrix = (Step**)malloc((*n_states_) * sizeof(Step*));
    for (int i = 0; i < *n_states_; i++) matrix[i] = (Step*)malloc(2 * sizeof(Step));

    for (int i = 0; i < n; i++)
    {
        int next = i + 1;
        switch (code[i])
        {
            /* Команда | Текущее S | Вход (Σ) | След. S | Выход (A) */
            case '+':
                matrix[i][IN_ZERO] = (Step){next, ACT_ADD};
                matrix[i][IN_NZ]   = (Step){next, ACT_ADD};
                break;
            case '-':
                matrix[i][IN_ZERO] = (Step){next, ACT_SUB};
                matrix[i][IN_NZ]   = (Step){next, ACT_SUB};
                break;
            case '>':
                matrix[i][IN_ZERO] = (Step){next, ACT_RIGHT};
                matrix[i][IN_NZ]   = (Step){next, ACT_RIGHT};
                break;
            case '<':
                matrix[i][IN_ZERO] = (Step){next, ACT_LEFT};
                matrix[i][IN_NZ]   = (Step){next, ACT_LEFT};
                break;
            case '.':
                matrix[i][IN_ZERO] = (Step){next, ACT_OUT};
                matrix[i][IN_NZ]   = (Step){next, ACT_OUT};
                break;
            case ',':
                matrix[i][IN_ZERO] = (Step){next, ACT_IN};
                matrix[i][IN_NZ]   = (Step){next, ACT_IN};
                break;
            case '[':
                stack[++sp] = i; // Сохраняем адрес в PDA (стек)
                matrix[i][IN_NZ]   = (Step){next, ACT_NOP};
                /* matrix[i][IN_ZERO] будет прошит при встрече ']' */
                break;
            case ']':
            {
                int open = stack[sp--]; // Извлекаем адрес из PDA
                matrix[i][IN_ZERO] = (Step){next, ACT_NOP};
                matrix[i][IN_NZ]   = (Step){open + 1, ACT_NOP};
                /* Back-patching: прошивка выхода для соответствующей '[' */
                matrix[open][IN_ZERO] = (Step){next, ACT_NOP};
                break;
            }
        }
    }
    /* Финальное состояние (HALT) — петля на графе в себя без действия */
    matrix[n][IN_ZERO] = matrix[n][IN_NZ] = (Step){n, ACT_NOP};

    free(stack);
    return matrix;
}

//  Преобразование FSM матрицы в текстовую таблицу
void matrix_to_string(Step** matrix, int n_states, char** num_table, char** mnem_table)
{
    char *p_n = *num_table = (char*)malloc(n_states * 64), *p_m = *mnem_table = (char*)malloc(n_states * 128);

    for (int i = 0; i < n_states; i++)
    {
        // Числовая таблица: [S_next_0 Act_0] [S_next_1 Act_1]
        p_n += sprintf(p_n, "%3d: [%3d %2d] [%3d %2d]\n", i,
            matrix[i][0].state, matrix[i][0].action, matrix[i][1].state, matrix[i][1].action);

        // Таблица мнемоник: [IF IN -> NEXT_S, ACTION]
        p_m += sprintf(p_m, "S%03d: [%-4s -> S%03d, %-5s] [%-4s -> S%03d, %-5s]\n", i,
            IN_NAMES[0], matrix[i][0].state, ACT_NAMES[matrix[i][0].action],
            IN_NAMES[1], matrix[i][1].state, ACT_NAMES[matrix[i][1].action]);
    }
}
//------------------------------------------

//------------------------------------------
// ЗАГРУЗКА И ЗАПУСК ПРОГРАММ ИНТЕРПРЕТАТОРА ЯЗЫКА BRAINFUCK
//------------------------------------------
unsigned char tape[30000]; // ПАМЯТЬ RAM

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "en_US.UTF-8");

    LOG("ИНТЕРПРЕТАТОР ЯЗЫКА BRAINFUCK. КОД ПОМЕСТИТЬ В КАВЫЧКИ, ПЕРВЫМ ПАРАМЕТРОМ ПРИ ЗАПУСКЕ ПРИГРАММЫ. ПРИМЕР: brainfuck.exe \"++.\"");

    char* code = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
    if (argc > 1) code = argv[1];

    //------------------------------------------
    // 1. Алгоритм с УМТ
    //------------------------------------------
    memset(tape, 0, sizeof(tape));
    int n_states;
    Step** FSM = bf_to_matrix(code, &n_states); // BF code -> FSM table

    // Вывод таблицы FSM на экран
    char *num_table, *mnem_table;
    matrix_to_string(FSM, n_states, &num_table, &mnem_table);
    LOG("\nТАБЛИЦА ПЕРЕХОДОВ УМТ:\n%s\n\nFSM:\n%s\n\nFSM МНЕМО-КОД:\n%s", code, num_table, mnem_table);
    free(num_table); free(mnem_table);

    LOG("\nЗАГРУЖАЮ ТАБЛИЦУ BF FSM В УМТ");
    UTM utm;
    utm.ROM     = FSM;
    utm.REG_S   = 0;
    utm.REG_IN  = 0;

    LOG("\nЗАПУСКАЮ ДОМЕННУЮ МАШИНУ\n");
    BF_DSM bfm;
    bfm.RAM     = tape;
    bfm.head    = 0;
    bfm.n_states = n_states;

    BF_Machine(&utm, &bfm);
    //------------------------------------------

    getch();
    return 0;
}
//------------------------------------------
