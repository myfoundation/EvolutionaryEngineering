
#include <conio.h>
#include <ctype.h>
#include <locale.h>

#define LOG printf

/* --- Спецификация автомата --- */

/* --- Множество, нумерующее состояния автмата --- */
/* S0 – ожидание (0 жетон), S1 – накопление (1 жетон), S2 – предтерминальное (2 жетона), ERR – блокировка. */
typedef enum { S0, S1, S2, ERR } State;

/* --- Множество, нумерующее Входные символы (или Входной алфавит) --- */
/* М – монета, В – вскрытие, Т – противоход, П – пусто, О – отмена. */
typedef enum { M, V, T, P, O } Input;

/* --- Множество, нумерующее Выходные символы (или Выходной алфавит) --- */
/* ПРИЕМ, ФРОД, ОЖИДАТЬ, ВЗЛОМ, ОТКАЗ, ВЫДАЧА, СЕРВИС, ВОЗВРАТ */
typedef enum { A0, A1, A2, A3, A4, A5, A6, A7 } Action;

/* --- Коды действий --- */
const char* Actions[] = { "ПРИЕМ", "ФРОД", " ОЖИДАТЬ ", "ВЗЛОМ", "ОТКАЗ", "ВЫДАЧА", "СЕРВИС", "ВОЗВРАТ" };
/* --- Коды состояний --- */
const char* States[]  = { "БАЛАНС 0", "БАЛАНС 1", "БАЛАНС 2", "БЛОКИРОВКА" };

/* --- Таблица (или граф) переходов --- */
struct Step
{
    State next;    /* S' */
    Action action;  /* A  */
};

const Step Machine[4][5] =
{
    /*         M          V         T          P         O      */
    [S0] = {{S1, A0}, {ERR, A3}, {S0, A4}, {S0, A2}, {S0, A4}},
    [S1] = {{S2, A0}, {ERR, A3}, {S0, A1}, {S1, A2}, {S0, A7}},
    [S2] = {{S0, A5}, {ERR, A3}, {S0, A1}, {S2, A2}, {S0, A7}},
    [ERR]= {{ERR, A6}, {ERR, A6}, {ERR, A6}, {ERR, A6}, {ERR, A6}}
};

int state; // Текущее состояние машины
void machine_loop()// Рабочий цикл машины
{
    while (state != ERR)
    {
        LOG("[%s] > ", States[state]);

        /* Ожидание входящего сигнала */
        int c = toupper(getche());

        /* Декодирование физических сигналов в символы алфавита */
        int in = (c=='M') ? M :
                   (c=='V') ? V :
                   (c=='T') ? T :
                   (c=='P') ? P :
                   (c=='O') ? O : -1;

        if(in == -1) continue;

        /* Исполнение шага автомата */
        Step step = Machine[state][in];
        LOG("\nACTION: %s -> NEXT STATE: %s\n", Actions[step.action], States[step.next]);

        state = step.next;
    }
}

int main(void)
{
    setlocale(LC_ALL, "en_US.UTF-8");

    LOG("--- ЛИМОНАД-МТ-1960 ---\nВВЕДИТЕ СИГНАЛ: M - монета, V - вскрытие, T - противоход, P - пусто, O - отмена. \n");

    state = S0; // Начальное состояние машины
    machine_loop();

    LOG("\n--- МАШИНА ОСТАНОВЛЕНА ---\n");

    getch();
    return 0;
}

