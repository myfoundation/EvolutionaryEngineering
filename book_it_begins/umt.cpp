#include <conio.h>
#include <ctype.h>
#include <locale.h>

#define LOG printf

//------------------------------------------
// УНИВЕРСАЛЬНАЯ МАШИНА ТЬЮРИНГА (УМТ)
//------------------------------------------
#define ROW(...) (Step[]){ __VA_ARGS__ }

struct Step
{
    int state;    /* S' */
    int action;  /* A  */
};

/* Функция для связи Универсальной Машины Тьюринга с внешним миром */
typedef void (*Action_Handler)(int state, int action);

Action_Handler action_handler;  // Обработчик исходящих сигналов
int state; // Текущее состояние эмулируемой машины
Step **ROM; // Программа для УМТ

void UMT_Run(int in)
{
    Step step = ROM[state][in];
    action_handler(step.state, step.action);
    state = step.state;
}

/* --- Загрузчик программы в УМТ (ROM Loader) --- */
void Load_ROM(Step **rom, int S0_state, Action_Handler ah)
{
	ROM = rom;
	state = S0_state;
	action_handler = ah;
}
//------------------------------------------

//------------------------------------------
// СПЕЦИАЛИЗИРОВННЫЙ АВТОМАТ (ОБЁРТКА НАД ЛОГИКОЙ УМТ)
//------------------------------------------

typedef enum { S0, S1, S2, ERR } State;
typedef enum { M, V, T, P, O } Input;
typedef enum { A0, A1, A2, A3, A4, A5, A6, A7 } Action;

const char* Actions[] = { "ПРИЕМ", "ФРОД", "ОЖИДАТЬ", "ВЗЛОМ", "ОТКАЗ", "ВЫДАЧА", "СЕРВИС", "ВОЗВРАТ" };
const char* States[] = { "БАЛАНС 0", "БАЛАНС 1", "БАЛАНС 2", "БЛОКИРОВКА" };

// Программа для УМТ
Step *Machine_Limonad[] =
{
                    /*     M       V      T        P      O    */
    /* S0  */ [0] = ROW({1, 0}, {3, 3}, {0, 4}, {0, 2}, {0, 4}),
    /* S1  */ [1] = ROW({2, 0}, {3, 3}, {0, 1}, {1, 2}, {0, 7}),
    /* S2  */ [2] = ROW({0, 5}, {3, 3}, {0, 1}, {2, 2}, {0, 7}),
    /* ERR */ [3] = ROW({3, 6}, {3, 6}, {3, 6}, {3, 6}, {3, 6})
};

/* Обработчик сигналов: здесь происходят физические действия */
void Exec_Action(int state, int action)
{
    LOG("\nACTION: %s -> NEXT STATE: %s\n", Actions[action], States[state]);
}

void machine_loop()// Рабочий цикл машины
{
    while (state != ERR)
    {
        LOG("[%s] > ", States[state]);

        int c = toupper(getche());

        int in = (c=='M') ? M :
                   (c=='V') ? V :
                   (c=='T') ? T :
                   (c=='P') ? P :
                   (c=='O') ? O : -1;

        if(in == -1) continue;

        /* Исполнение шага автомата на УМТ */
        UMT_Run(in);
    }
}
//------------------------------------------

int main(void)
{
    setlocale(LC_ALL, "en_US.UTF-8");

    LOG("--- ЛИМОНАД-УМТ-1960 ---\nВВЕДИТЕ СИГНАЛ: M - монета, V - вскрытие, T - противоход, P - пусто, O - отмена. \n");

    Load_ROM(Machine_Limonad, S0, Exec_Action); // Загрузить программу в УМТ
    machine_loop(); // Запустить специализированный автомат

    LOG("\n--- МАШИНА ОСТАНОВЛЕНА ---\n");

    getch();
    return 0;
}


