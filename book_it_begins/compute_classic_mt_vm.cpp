// compute_classic_mt_vm.cpp
#include <string.h>
#include <conio.h>
#include <locale.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define MATCH_ if(0){;}
#define CASE_(x) else if((x))
#define DEFAULT_ else
#define LOG printf

//------------------------------------------
// 1. ХРЕСТОМАТИЙНАЯ МАШИНА ТЬЮРИНГА
//------------------------------------------
enum Action { MVL, MVR, HLT };

struct FSM_entry
{
    int current_state, in_symbol, next_state, out_symbol, action;
};

//------------------------------------------
// 2. ВИРТУАЛЬНАЯ МАШИНА (VM)
//------------------------------------------
enum OP_CODE
{
    JMP,
    JMP_F,
    CMP,        // Сравнить текущую ячейку с числом XX и выставить флаг F если равны
    SET,        // Записать число в текущую ячейку
    ADDR_INC,   // Инкремент шины адреса RAM
    ADDR_DEC,
    HLT_OP,

    OP_COUNT
};

// JMP(2), JMP_F(2), CMP(2), SET(2), ADDR_INC(1), ADDR_DEC(1), HLT_OP(1)
static const int OP_SIZE[OP_COUNT] = { 2, 2, 2, 2, 1, 1, 1 };

 // Соответствие: Action (действие) МТ -> Аппаратная команда (микрокод) CPU
static const int MAP_ACT_OP[] = { ADDR_DEC, ADDR_INC, HLT_OP };

// Регистры и память процессора VM
struct VM_context
{
    int
        REG_IP,     // Указатель команд
        REG_ADDR,   // Регистр выбранного адреса ОЗУ
        REG_F,      // Флаг сравнения
        *RAM,       // RAM, данные
        *ROM,       // ROM, код программы
        RAM_SIZE, ROM_SIZE; // Объём памяти RAM / ROM
};

//------------------------------------------
// 3. ИСПОЛНИТЕЛЬНЫЙ ЦИКЛ ПРОЦЕССОРА
//------------------------------------------
void VM_run(VM_context *CTX)
{
    int is_run = 1;
    while (is_run)
    {
        if (CTX->REG_IP < 0 || CTX->REG_IP >= CTX->ROM_SIZE || CTX->REG_ADDR < 0 || CTX->REG_ADDR >= CTX->RAM_SIZE)
        {
            LOG("ERR. CPU EXCEPTION: REG_IP/REG_ADDR OUT OF MEMORY BOUNDS (%d).\n", CTX->REG_IP);
            is_run = 0;
            break;
        }

        int op = CTX->ROM[CTX->REG_IP];

        if (op < 0 || op >= OP_COUNT)
        {
            LOG("ERR. CPU EXCEPTION: UNKNOWN OP_CODE '%d' AT ROM IP (%d).\n", op, CTX->REG_IP);
            is_run = 0;
            break;
        }

        switch (op)
        {
            case JMP:      { CTX->REG_IP = CTX->ROM[CTX->REG_IP + 1]; continue; }
            case JMP_F:
            {
                if (CTX->REG_F != 0)
                {
                    CTX->REG_IP = CTX->ROM[CTX->REG_IP + 1];
                    continue;
                }
            break;
            }
            case CMP:      { CTX->REG_F = (CTX->RAM[CTX->REG_ADDR] == CTX->ROM[CTX->REG_IP + 1]); break; }
            case SET:      { CTX->RAM[CTX->REG_ADDR] = CTX->ROM[CTX->REG_IP + 1]; break; }
            case ADDR_INC: { CTX->REG_ADDR++; break; }
            case ADDR_DEC: { CTX->REG_ADDR--; break; }
            case HLT_OP:   { is_run = 0; break; }
        }

        CTX->REG_IP += OP_SIZE[op];
    }
}


//------------------------------------------
// 4. КОМПИЛЯТОР FSM ТАБЛИЦ В БАЙТКОД VM
//------------------------------------------
void VM_compile_bytecode(FSM_entry *FSM_TABLE, int FSM_SIZE, int *ROM, int *out_rom_size, int NUM_STATES)
{
/*
БЛОЧНО-ЛИНЕЙНОЕ ОТОБРАЖЕНИЕ ГРАФА FSM В КОМАНДЫ МАШИНЫ
МЕТОД ТАБЛИЦЫ ДИСПЕТЧЕРИЗАЦИИ
СУТЬ: Каждому состоянию FSM S_i ставится в соответствие блок условных проверок входящего символа IN.
При нахождении совпадения IN == In_xx выполнение переходит на обработчик пары { S_i, In_xx }.

СТРУКТУРА ТАБЛИЦЫ ДИСПЕТЧЕРИЗАЦИИ

 Блок состояния S_0 (Начальный адрес: map_state_ip[0] = 0)
 +---> [ Элемент 0: {S_0, IN_0} ] --(Не совпал)--> Переход на ip + 11
 |     +---(Совпал)--> [ Выполнить: SET -> ACT -> JMP к map_state_ip[next] ]
 |
 +---> [ Элемент 1: {S_0, IN_1} ] --(Не совпал)--> Переход на ip + 11
 |     +---(Совпал)--> [ Выполнить: SET -> ACT -> JMP к map_state_ip[next] ]
 |
 +---> [ Элемент 2: {S_0, IN_2} ] --(Не совпал)--> КОНЕЦ БЛОКА (Барьер: -1)

 Блок состояния S_1 (Начальный адрес: map_state_ip[1])
 +---> [ Элемент 3: {S_1, IN_0} ] --(Не совпал)--> Переход на ip + 11
...

//------------------------------------------

*/

    int
        // Адрес в ROM начала блока диспетчеризации для состояния S_i
        map_state_ip[NUM_STATES],
        // Адреса переходов по таблице диспетчерезации { S_i, In_xx },
        alt_ips[FSM_SIZE],
        ip = 0;

    memset(map_state_ip, -1, NUM_STATES * sizeof(int));

    for (int i = 0; i < FSM_SIZE; ++i)
    {
        int state = FSM_TABLE[i].current_state;

/*
В map_state_ip[state] храним начало блока диспетчеризации для состояния state

  Таблица FSM_TABLE
+--------------------------+
| i=0: S_FIND_ZERO, SY_1   | <--- Первая встреча S_FIND_ZERO
| i=1: S_FIND_ZERO, SY_0   |      Запись: map_state_ip[0] = 0
+--------------------------+
| i=2: S_FIND_END,  SY_1   | <--- Первая встреча S_FIND_END
| i=3: S_FIND_END,  SY_0   |      Запись: map_state_ip[1] = 22
+--------------------------+
*/
        if (map_state_ip[state] == -1) { map_state_ip[state] = ip; }
/*
alt_ips[i] записи альтернативных обработчиков в блоке диспетчеризации для текущего состояния

+----+-------------+--------+--------------+----------------------------------------+
| i  | Состояние   | Текущий| Значение     | Логика вычисления (почему именно так)  |
|    | (Граф FSM)  | IP     | в alt_ips[i] |                                        |
+----+-------------+--------+--------------+----------------------------------------+
| 0  | S_FIND_ZERO | 0      | 11           | i+1 (строка 1) — то же состояние.      |
|    |             |        |              | Переход в пределах блока: ip + 11.     |
|----+-------------+--------+--------------+----------------------------------------|
| 1  | S_FIND_ZERO | 11     | -1 (Барьер)  | i+1 (строка 2) — ДРУГОЕ состояние.     |
|    |             |        |              | Это конец блока S_FIND_ZERO. Ставим -1.|
|----+-------------+--------+--------------+----------------------------------------|
| 2  | S_FIND_END  | 22     | 33           | i+1 (строка 3) — то же состояние.      |
|    |             |        |              | Переход в пределах блока: ip + 11.     |
|----+-------------+--------+--------------+----------------------------------------|
| 3  | S_FIND_END  | 33     | -1 (Барьер)  | Строки таблицы закончились (i+1 == 4). |
|    |             |        |              | Это конец блока S_FIND_END. Ставим -1. |
+----+-------------+--------+--------------+----------------------------------------+
*/
        alt_ips[i] = ((i + 1 < FSM_SIZE) && (FSM_TABLE[i + 1].current_state == state)) ? (ip + 11) : -1;
        ip += 11;
    }

    ip = 0;
    // Цикл генерации байткода
    for (int i = 0; i < FSM_SIZE; ++i)
    {
/* Запись таблицы диспетчеризации. Соответствует строке FSM таблицы

 Массив BIN в ROM процессора:
 [0]   [1]           [2]     [3]     [4]   [5]           [6] ... [10]
+-----+-------------+-------+-------+-----+-------------+----+-----+----+

| CMP |  in_symbol  | JMP_F | ip + 6| JMP | alt_ips[i]  |SET | ... |JMP |
+-----+-------------+-------+-------+-----+-------------+----+-----+----+
 \_________________________________ /  \_______________/  \____________/
       Селектор совпадения (Диспетчер)   Ветка промаха      Ветка успеха

CMP: проверить входящий символ
JMP_F (совпал): перейти в ветку, где
                1. писать исходящий символ в RAM,
                2. выполнить HLT_OP | ADDR_INC | ADDR_DEC
                3. перейти к блоку диспетчеризации следующего состояния
JMP (не совпал): перейти к следующему обработчику в пределах блока диспетчеризации текущего состояния

Смещения в бинарном буфере:

 Индекс: |  0  | 1 |   2   | 3 |  4  | 5  |  6  | 7 |   8    |  9  | 10 |
---------+-----+---+-------+---+-----+----+--------+---+----------+-----+----+
 Команда:| CMP | 0 | JMP_F | 0 | JMP | -1 | SET | 0 | HLT_OP | JMP | -1 |
*/

        //------------------------------------------
        // БАЙТ-КОД
        int BIN[] = { CMP, 0, JMP_F, 0, JMP, -1, SET, 0, HLT_OP, JMP, -1 };
        //------------------------------------------

        //------------------------------------------
        // МЕНЯЕМ ПОЛЯ ПО СМЕЩЕНИЯМ
        BIN[1]  = FSM_TABLE[i].in_symbol;
        BIN[3]  = ip + 6;
        BIN[5]  = alt_ips[i];   // Если In_xx не совпал, переход к следующему обработчику в пределах блока диспетчеризации текущего состояния
        // In_xx совпал, обрабатываем запись
        BIN[7]  = FSM_TABLE[i].out_symbol; // Запись исходящего символа
        BIN[8]  = MAP_ACT_OP[FSM_TABLE[i].action]; // Подать сигнал аппаратуре HLT_OP | ADDR_INC | ADDR_DEC
        BIN[10] = map_state_ip[FSM_TABLE[i].next_state];  // Переход к блоку диспетчеризации следующего состояния
        //------------------------------------------

        //------------------------------------------
        // ПИШЕМ БЛОК В БУФФЕР С КОДОМ (EMIT)
        memcpy(&ROM[ip], BIN, sizeof(BIN));
        ip += sizeof(BIN)/sizeof(BIN[0]);
        //------------------------------------------
    }

    *out_rom_size = ip;
}


//------------------------------------------
// 5. ПРОВЕРКА ЦЕЛОСТНОСТИ АВТОМАТА (INTEGRITY CHECK)
//------------------------------------------

/*
Функция для сложения двух чисел в унарной системе счисления.
Числа расположены подряд, числу соответствует количество палочек, разделённых 0: I0 - 1,  II0 - 2, III0 - 3,  ...
*/
void compute_add(int* buffer /* "лента" с данными для обработки (RAM) */, int buffer_size)
{
    enum State { S_FIND_ZERO, S_FIND_END, S_ERASE, S_HALT, NUM_STATES };
    enum Alphabet { SY_0, SY_1, SY_2 };

    FSM_entry FSM_TABLE[] =
    {
        { S_FIND_ZERO, SY_1, S_FIND_ZERO, SY_1, MVR },
        { S_FIND_ZERO, SY_0, S_FIND_END,  SY_1, MVR },
        { S_FIND_END,  SY_1, S_FIND_END,  SY_1, MVR },
        { S_FIND_END,  SY_0, S_ERASE,     SY_2, MVL },
        { S_ERASE,     SY_1, S_HALT,      SY_0, MVL },
        { S_HALT,      SY_1, S_HALT,      SY_1, HLT }
    };

    int
        FSM_SIZE = sizeof(FSM_TABLE) / sizeof(FSM_entry),
        ROM[2048],
        rom_size = 0;

    VM_compile_bytecode(FSM_TABLE, FSM_SIZE, ROM, &rom_size, NUM_STATES);

    // Начальное состояние машины
    VM_context CPU;
    CPU.REG_IP      = 0;
    CPU.REG_ADDR    = 0;
    CPU.REG_F       = 0;
    CPU.RAM         = buffer;
    CPU.ROM         = ROM;
    CPU.ROM_SIZE    = rom_size;
    CPU.RAM_SIZE    = buffer_size;

    VM_run(&CPU); // Запуск процессора
}

/*
Функция меняет в буфере 0 на 1, 1 на 0, число 2 - маркер конца буфера
*/
void compute_inverse(int* buffer /* "лента" с данными для обработки (RAM) */, int buffer_size)
{
    enum State { S_SCAN, S_HALT, NUM_STATES } ;
    enum Alphabet { SY_0, SY_1, SY_2 };

    FSM_entry FSM_TABLE[] =
    {
        // Оператор if реализуется через индексный выбор строки таблицы таблицы по входному символу.

        // СОСТОЯНИЕ S_SCAN: Инверсия чисел (0->1, 1->0)
        { S_SCAN, SY_0, S_SCAN, SY_1, MVR }, // If 0 -> пишем 1, шаг вправо
        { S_SCAN, SY_1, S_SCAN, SY_0, MVR }, // If 1 -> пишем 0, шаг вправо
        { S_SCAN, SY_2, S_HALT, SY_2, MVL }, // If 2 -> уходим в S_HALT (из-за MVL HLT корректно перезапишет RAM)

        // СОСТОЯНИЕ S_HALT: Безусловный аппаратный останов
        { S_HALT, SY_0, S_HALT, SY_0, HLT }, // Если вернулись на ноль -> Останов
        { S_HALT, SY_1, S_HALT, SY_1, HLT }  // Если вернулись на единицу -> Останов
    };

    int
        FSM_SIZE = sizeof(FSM_TABLE) / sizeof(FSM_entry),
        ROM[2048],
        rom_size = 0;

    VM_compile_bytecode(FSM_TABLE, FSM_SIZE, ROM, &rom_size, NUM_STATES);

    // Начальное состояние машины
    VM_context CPU;
    CPU.REG_IP      = 0;
    CPU.REG_ADDR    = 0;
    CPU.REG_F       = 0;
    CPU.RAM         = buffer;
    CPU.ROM         = ROM;
    CPU.ROM_SIZE    = rom_size;
    CPU.RAM_SIZE    = buffer_size;

    VM_run(&CPU); // Запуск процессора
}

void integrity_check()
{
    //------------------------------------------
    // МТ №1
    //------------------------------------------
    // Тест 1: 2 + 3 (1 1 0 1 1 1 0 2) -> Должно стать 5 единиц (1 1 1 1 1 0 2)
    int buf1[] = {1, 1, 0, 1, 1, 1, 0, 2};
    int exp1[] = {1, 1, 1, 1, 1, 0, 2};
    compute_add(buf1, sizeof(buf1) / sizeof(buf1[0]));
    assert(memcmp(buf1, exp1, sizeof(exp1)) == 0);

    // Тест 2: 6 + 2 (1 1 1 1 1 1 0 1 1 0 2) -> Будет 8 единиц (1 1 1 1 1 1 1 1 0 2)
    int buf2[] = {1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 2};
    int exp2[] = {1, 1, 1, 1, 1, 1, 1, 1, 0, 2};
    compute_add(buf2, sizeof(buf2) / sizeof(buf2[0]));
    assert(memcmp(buf2, exp2, sizeof(exp2)) == 0);
    //------------------------------------------

    //------------------------------------------
    // МТ №2
    //------------------------------------------
    int buf0[] = {0, 1, 0, 1, 1, 1, 2}; // Инверсия цепочки 0-1-0-1-1-1
    int exp0[] = {1, 0, 1, 0, 0, 0, 2}; // Ожидаемый эталонный слепок RAM

    compute_inverse(buf0, sizeof(buf0) / sizeof(buf0[0]));
    assert(memcmp(buf0, exp0, sizeof(exp0)) == 0);
    //------------------------------------------

    LOG("VM INTEGRITY CHECK: PASSED\n");
}
//------------------------------------------

int main()
{
    LOG("CLASSIC TURING MACHINE 1936 FSM -> BYTECODE VM COMPILER\n");
    integrity_check();
    getch();
    return 0;
}
