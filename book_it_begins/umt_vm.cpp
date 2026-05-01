#include <stdlib.h>
#include <stdarg.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define LOG printf

//------------------------------------------
// УНИВЕРСАЛЬНАЯ МАШИНА ТЬЮРИНГА (УМТ)
//------------------------------------------

//------------------------------------------
// СИСТЕМА КОМАНД VM
//------------------------------------------
/*
ГРАММАТИКА АССЕМБЛЕРА (EBNF):
------------------------------------------
<program>     ::= { <instruction> }
<instruction> ::= "LD_IN"
                | "JMP" <address>
                | "JMP_IF" <condition> <address>
                | "EXEC" <action_id>
                | "SET_S" <state_id>
                | "LABEL" <label_id>
                | "BREAK"
                | "HALT"
<condition>   ::= <integer>  (* ASCII код символа *)
<address>     ::= <integer>
<action_id>   ::= <integer>
<state_id>    ::= <integer>
<label_id>    ::= <integer>
------------------------------------------
*/

typedef enum
{
    // Достаточный набор команд для УМТ
    LD_IN,   // Считать входной сигнал в регистр
    JMP,     // Безусловный переход. Перейти по адресу Y
    JMP_IF,  // Условный переход. Если вход == X, перейти по адресу Y, иначе — к следующей команде
    EXEC,    // Выполнить внешнее действие Z
    SET_S,   // Сменить номер состояния в регистре состояний
    LABEL,   // Маркер метки для JMP, JMP_IF
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
// Виртуальная машина
//------------------------------------------
struct UVM;
typedef void (*Signal_Handler)(UVM &VM);

struct UVM
{
    int IP;              // Instruction Pointer (Указатель на текущую команду)
    int REG_IN;          // Регистр входного сигнала
    int CUR_S;           // Регистр текущего состояния
    int REG_OUT;         // Регистр текущего действия (Action)
    int *ROM;            // Память машины
    int F_IS_RUN;        // Флаг остановки машины

    Signal_Handler in_signal_handler;       // Ожидание входящего сигнала. Должен быть записан в REG_IN
    Signal_Handler out_signal_handler;      // Генератор исходящих сигналов. Сигнал хранится в регистре REG_OUT
    Signal_Handler break_signal_handler;    // Сигнал отладчику
};

int VM_Step(UVM &VM) // Выполнение  команды
{
    int opcode = VM.ROM[VM.IP];
    int next_IP = VM.IP + OP_SIZE[opcode];

    LOG("\n[DBG] IP:%02d    %s", VM.IP, MNEMONICS[opcode]);

    switch (opcode)
    {
        case LD_IN:
        case BREAK:
        case HALT:
        case LABEL:
             break;
        case SET_S:
            VM.CUR_S = VM.ROM[VM.IP+1];
            break;
        case EXEC:
            VM.REG_OUT = VM.ROM[VM.IP+1];
            break;
        case JMP:
                next_IP = VM.ROM[VM.IP+1];
            break;
        case JMP_IF:
            if (VM.REG_IN == VM.ROM[VM.IP+1]) next_IP = VM.ROM[VM.IP+2];
            break;
    }

    VM.IP = next_IP;

    return opcode;
}

void machine_loop(UVM &VM)// Рабочий цикл машины
{
    while (VM.F_IS_RUN)
    {
        int opcode = VM_Step(VM);
        switch (opcode)
        {
            case HALT:
                VM.F_IS_RUN = 0;
                break;
            case LD_IN:
                VM.in_signal_handler(VM);
                break;
            case EXEC:
                VM.out_signal_handler(VM);
                break;
            case BREAK:
                // Точка остановки отладчика (breakpoint). Здесь можно вызвать сервисное меню или дамп памяти
                LOG("\n>>BREAKPOINT<<");
                VM.break_signal_handler(VM);
                break;
        }
    }
}

//------------------------------------------
// DISASSEMBLER
//------------------------------------------
void DISASSEMBLER(int *MEM, int RANGE_L, int RANGE_R)
{
    LOG("\n------- DISASSEMBLY START -------\nMEMBLOCK = [0x%X-0x%X]", RANGE_L, RANGE_R);
    int i = RANGE_L;
    while (i < RANGE_R)
    {
        int opcode = MEM[i];
        int is_valid = (opcode >= 0 && opcode < OpCodes_Total);
        int step = is_valid ? OP_SIZE[opcode] : 1;

        // Печать Мнемоники
        LOG("\nADR:%02d    %-8s", i, is_valid ? MNEMONICS[opcode] : "DATA");

        // Печать Аргументов
        for (int a = 1; a < step; a++) LOG(" %d", MEM[i + a]);
        if (!is_valid) LOG(" %d", opcode);
        i += step;
    }
    LOG("\n------- DISASSEMBLY END -------");
}
//------------------------------------------

//------------------------------------------
// GENERATE & COMPLILE PROGRAM BY FSM TABLE
//------------------------------------------
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
//------------------------------------------

//------------------------------------------
// ДОМЕННЫЙ АВТОМАТ (ОБЁРТКА НАД ЛОГИКОЙ УМТ)
//------------------------------------------
/*
ДИСКРЕТНАЯ МОДЕЛЬ (ГРАФ АВТОМАТА):
Множество состояний S = {S0, S1, S2, ERR}
Входной алфавит X = {M, V, T, P, O} (ASCII: 77, 86, 84, 80, 79)
Алфавит действий A = {A0, A1, A2, A3, A4, A5, A6, A7}
Функция переходов δ: S×X -> S
*/

/* --- Множество, нумерующее состояния автмата --- */
/* S0 – ожидание (0 жетон), S1 – накопление (1 жетон), S2 – предтерминальное (2 жетона), ERR – блокировка. */
typedef enum { S0, S1, S2, ERR } State;

/* --- Множество, нумерующее Входные символы (или Входной алфавит) --- */
/* М – монета, В – вскрытие, Т – противоход, П – пусто, О – отмена. */
typedef enum { M, V, T, P, O } Input;
typedef enum { _M = 'M', _V = 'V', _T = 'T', _P = 'P', _O = 'O' } _Input;
const char *Inputs = "MVTPO";

/* --- Множество, нумерующее Выходные символы (или Выходной алфавит) --- */
/* ПРИЕМ, ФРОД, ОЖИДАТЬ, ВЗЛОМ, ОТКАЗ, ВЫДАЧА, СЕРВИС, ВОЗВРАТ */
typedef enum { A0, A1, A2, A3, A4, A5, A6, A7 } Action;

const char* Actions[]       = { "ПРИЕМ", "ФРОД", "ОЖИДАТЬ", "ВЗЛОМ", "ОТКАЗ", "ВЫДАЧА", "СЕРВИС", "ВОЗВРАТ" };
const char* States[]        = { "БАЛАНС 0", "БАЛАНС 1", "БАЛАНС 2", "БЛОКИРОВКА" };
const char* In_Actions[]    = { "МОНЕТА", "ВСКРЫТИЕ", " ПРОТИВОХОД ", "ПУСТО", "ОТМЕНА" };

//------------------------------------------
// Программа для УМТ (Bytecode)
//------------------------------------------
/* --- Метки для адресации в ROM --- */
typedef enum
{
    LB_S0, LB_S0_BUSY, LB_S0_A2, LB_S0_A4,
    LB_S1, LB_S1_BUSY, LB_S1_A1, LB_S1_A2, LB_S1_A7,
    LB_S2, LB_S2_BUSY, LB_S2_A1, LB_S2_A2, LB_S2_A5, LB_S2_A7,
    LB_ER, LB_ER_LOOP
} Labels;

int ROM_LIMONAD[] =
{
    SET_S,  S0,
    BREAK,

    /* --- Состояние S0 (0 монет) --- */
    LABEL,  LB_S0,
    SET_S,  S0,
    LABEL,  LB_S0_BUSY,
    LD_IN,
    JMP_IF, _M, LB_S1,      // В S1 (через входную точку с EXEC A0)
    JMP_IF, _V, LB_ER,     // Взлом
    JMP_IF, _T, LB_S0_A4,
    JMP_IF, _P, LB_S0_A2,
    JMP_IF, _O, LB_S0_A4,
    JMP,  LB_S0_BUSY,      // Рекурсия ожидания

    LABEL,  LB_S0_A4, EXEC, A4, JMP, LB_S0_BUSY,
    LABEL,  LB_S0_A2, EXEC, A2, JMP, LB_S0_BUSY,

    /* --- Состояние S1 (1 монета) --- */
    LABEL,  LB_S1,
    SET_S,  S1,
    EXEC,   A0,              // Прием первой монеты
    LABEL,  LB_S1_BUSY,
    LD_IN,
    JMP_IF, _M, LB_S2,      // В S2 (через входную точку с EXEC A0)
    JMP_IF, _V, LB_ER,
    JMP_IF, _T, LB_S1_A1,
    JMP_IF, _P, LB_S1_A2,
    JMP_IF, _O, LB_S1_A7,
    JMP,  LB_S1_BUSY,

    LABEL,  LB_S1_A1, EXEC, A1, JMP, LB_S0,
    LABEL,  LB_S1_A2, EXEC, A2, JMP, LB_S1_BUSY,
    LABEL,  LB_S1_A7, EXEC, A7, JMP, LB_S0,

    /* --- Состояние S2 (2 монеты) --- */
    LABEL,  LB_S2,
    SET_S,  S2,
    EXEC,   A0,              // Прием второй монеты
    LABEL,  LB_S2_BUSY,
    LD_IN,
    JMP_IF, _M, LB_S2_A5,   // Выдача
    JMP_IF, _V, LB_ER,
    JMP_IF, _T, LB_S2_A1,
    JMP_IF, _P, LB_S2_A2,
    JMP_IF, _O, LB_S2_A7,
    JMP,  LB_S2_BUSY,

    LABEL,  LB_S2_A5, EXEC, A5, JMP, LB_S0,
    LABEL,  LB_S2_A1, EXEC, A1, JMP, LB_S0,
    LABEL,  LB_S2_A2, EXEC, A2, JMP, LB_S2_BUSY,
    LABEL,  LB_S2_A7, EXEC, A7, JMP, LB_S0,

    /* --- Состояние ERR --- */
    LABEL,  LB_ER,
    SET_S,  ERR,
    EXEC,   A3,             // Фиксация взлома
    EXEC,   A6,             // Сигнал сервиса
    HALT                    // Блокировка
};
//------------------------------------------

/* Обработчик сигналов: здесь происходят физические действия */
void Out_Action(UVM &VM)
{
    LOG("\nACTION: %s -> NEXT STATE: %s", Actions[VM.REG_OUT], States[VM.CUR_S]);

    if(VM.REG_OUT == A6)
    {
        LOG("\nБЛОКИРУЮ МАШИНУ.");
        VM.F_IS_RUN = 0;
    }
}

void In_Action(UVM &VM)
{
    LOG("\nЖДУ СИГНАЛ. STATE = [%s] > ", States[VM.CUR_S]);
    VM.REG_IN = toupper(getche()); // WAIT INPUT...
}

void Break_Action(UVM &VM)
{
    LOG("\nSTATE:IN:OUT = [%s] [%s] [%s]\nНажмите любую клавишу для продолжения...", States[VM.CUR_S], In_Actions[VM.REG_IN] , Actions[VM.REG_OUT]);
    getch();
}

// Загрузить файл с диска
char* load_bin(const char *fname, int *n)
{
    *n = 0;
    FILE *f = fopen(fname, "rb");
    if (!f) return NULL;
    fseek(f, 0, 2); long len = ftell(f); rewind(f);
    char *b = (len > 0) ? (char*)malloc(len) : NULL; // Проверка на пустой файл
    if (b) *n = fread(b, 1, len, f);
    if(*n!=len) { free(b); b = NULL; }
    fclose(f);
    return b;
}

int main()
{
    setlocale(LC_ALL, "en_US.UTF-8");

    LOG("--- КЛАССИЧЕСКАЯ VM C ИНЖЕНЕРНЫМ МОНИТОРОМ (1960) ---\n");

    //------------------------------------------
    // Загрузить программу
    //------------------------------------------
    LOG("\n------- LOAD ROM -------");
    LOG("\nЗАГРУЗИТЬ ROM С ЛЕНТЫ?: Y/N");
    int *ROM, ROM_LEN;
    if(toupper(getch()) == 'Y')
    {
        LOG("\nГРУЖУ: machine_limonad.bin");
        ROM = (int*)load_bin("machine_limonad.bin", &ROM_LEN);
        ROM_LEN = ROM_LEN / sizeof(int);
        if(!ROM)
        {
            LOG("\nERR: ФАЙЛ НЕ НАЙДЕН. КОНЕЦ РАБОТЫ.");
            return 0;
        }
    }
    else
    {
        LOG("\nИСПОЛЬЗУЮ ВСТРОЕННЫЙ ROM");
        ROM = ROM_LIMONAD;
        ROM_LEN = sizeof(ROM_LIMONAD) / sizeof(int);
        // Рассчитать метки переходов
        set_jmps(ROM, ROM+ROM_LEN, 1000);
    }

    DISASSEMBLER(ROM, 0, ROM_LEN); // Вывести программу на экран

    LOG("\nВВЕДИТЕ СИГНАЛ: M - монета, V - вскрытие, T - противоход, P - пусто, O - отмена. \n");

    //------------------------------------------
    // Инициализировать VM
    //------------------------------------------

    UVM VM;
    // Установить обработчики сигналов
    VM.out_signal_handler      = Out_Action;
    VM.in_signal_handler       = In_Action;
    VM.break_signal_handler    = Break_Action;

    // Установить начальное состояние
    VM.ROM        = ROM;
    VM.IP         = 0;
    VM.CUR_S      = S0;
    VM.REG_IN     = P;
    VM.REG_OUT    = A2;
    VM.F_IS_RUN   = 1;

    // Запустить цикл машины
    LOG("\n------- RUN PROGRAM -------");
    machine_loop(VM);
    LOG("\n--- МАШИНА ОСТАНОВЛЕНА ---\n");

    getch();
    return 0;
}

