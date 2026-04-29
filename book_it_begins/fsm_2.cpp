#include <conio.h>
#include <ctype.h>
#include <locale.h>

#define LOG printf

typedef enum { S0, S1, S2, ERR } State;
typedef enum { M, V, T, P, O } Input;
typedef enum { A0, A1, A2, A3, A4, A5, A6, A7 } Action;

const char* Actions[] = { "ПРИЕМ", "ФРОД", "ОЖИДАТЬ", "ВЗЛОМ", "ОТКАЗ", "ВЫДАЧА", "СЕРВИС", "ВОЗВРАТ" };
const char* States[] = { "БАЛАНС 0", "БАЛАНС 1", "БАЛАНС 2", "БЛОКИРОВКА" };

int state;

// Функция-обертка, обработка исходящего сигнала
void process_step(int next_s, int act)
{
    LOG("\nACTION: %s -> NEXT STATE: %s\n", Actions[act], States[next_s]);
    state = next_s;
}

void machine_loop()
{
    while (state != ERR)
    {
        LOG("[%s] > ", States[state]);

        int c = toupper(getche());

        Input in;
        switch (c)
        {
            case 'M': in = M; break;
            case 'V': in = V; break;
            case 'T': in = T; break;
            case 'P': in = P; break;
            case 'O': in = O; break;
            default:  continue;
        }

        /* ЗАМЕНА ТАБЛИЦЫ НА SWITCH-ЛОГИКУ */
/*
      ПЕРЕХОД ПО РЕБРУ ИЗ УЗЛА Sn -> В УЗЕЛ Sn+1

            [M] ->[Sn+1] / A
          /
         /  [V] ->[Sn+1] / A
        /  /
[Sn] -------- [T] ->[Sn+1] / A
        \  \
         \  [P] ->[Sn+1] / A
          \
            [O] ->[Sn+1] / A
*/

        switch (state)
        {
            case S0:
                switch (in)
                {
                    case M: process_step(S1, A0); break;
                    case V: process_step(ERR, A3); break;
                    case T: process_step(S0, A4); break;
                    case P: process_step(S0, A2); break;
                    case O: process_step(S0, A4); break;
                }
                break;

            case S1:
                switch (in)
                {
                    case M: process_step(S2, A0); break;
                    case V: process_step(ERR, A3); break;
                    case T: process_step(S0, A1); break;
                    case P: process_step(S1, A2); break;
                    case O: process_step(S0, A7); break;
                }
                break;

            case S2:
                switch (in)
                {
                    case M: process_step(S0, A5); break;
                    case V: process_step(ERR, A3); break;
                    case T: process_step(S0, A1); break;
                    case P: process_step(S2, A2); break;
                    case O: process_step(S0, A7); break;
                }
                break;

            case ERR:
                switch (in)
                {
                    case M: process_step(ERR, A6); break;
                    case V: process_step(ERR, A6); break;
                    case T: process_step(ERR, A6); break;
                    case P: process_step(ERR, A6); break;
                    case O: process_step(ERR, A6); break;
                }
                break;
        }
    }
}

int main(void)
{
    setlocale(LC_ALL, "en_US.UTF-8");
    LOG("--- ЛИМОНАД-МТ-1960 ---\nВВЕДИТЕ СИГНАЛ: M - монета, V - вскрытие, T - противоход, P - пусто, O - отмена. \n");

    state = S0;
    machine_loop();

    LOG("\n--- МАШИНА ОСТАНОВЛЕНА ---\n");

    getch();
    return 0;
}

