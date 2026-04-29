#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>

#define LOG printf


//------------------------------------------
// РЕКУРСИВНЫЙ АЛГОРИТМ ИНТЕРПРЕТАТОРА BRAINFUCK НА С СТЕКЕ
//------------------------------------------
void interpret_bf_recursive(char* pc, unsigned char** head) // <- Здесь стек CPU использован неявно
{
    // char* pc - указатель в "ленте кода"
    // char** head - указатель в "ленте памяти", использован **, чтобы сделать "общую головку", которую двигают все автоматы

    while (*pc && *pc != ']')
    {
        switch (*pc++)
        {
            case '>': ++*head; break; // Инкрмент указателя на активную ячейку памяти
            case '<': --*head; break; // Декрмент указателя на активную ячейку памяти
            case '+': ++**head;  break; // Инкремент значения в активной ячеке памяти
            case '-': --**head;  break; // Декремент значения в активной ячеке памяти
            case '.': putchar(**head); break;
            case ',': **head = (unsigned char)getchar(); break;
            case '[':
            {
                if (**head)
                {
                    while (**head) interpret_bf_recursive(pc, head);
                }
                // Пропуск тела цикла для родительского автомата
                for (int l = 1; l; pc++) { l += (*pc == '[') - (*pc == ']'); }
                break;
            }
        }
    }
}
//------------------------------------------

//------------------------------------------
// ИТЕРАТИВНЫЙ АЛГОРИТМ ИНТЕРПРЕТАТОРА BRAINFUCK
//------------------------------------------
void interpret_bf_stack(char* in, unsigned char* head_)
{
    unsigned char* head = head_;

    int stack[8192], sp = -1;
    for (int i = 0; in[i]; i++)
    {
        switch (in[i])
        {
            case '>': ++head; break;
            case '<': --head; break;
            case '+': ++*head; break;
            case '-': --*head; break;
            case '.': putchar(*head); break;
            case ',': *head = getchar(); break;
            case '[':
                if (*head) stack[++sp] = i;
                else for (int l = 1; l; ) { char c = in[++i]; l += (c == '[') - (c == ']'); }
                break;
            case ']':
                if (*head) i = stack[sp];
                else sp--;
                break;
        }
    }
}
//------------------------------------------

unsigned char tape[30000]; // ПАМЯТЬ RAM


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "en_US.UTF-8");

    LOG("ИНТЕРПРЕТАТОР ЯЗЫКА BRAINFUCK. КОД ПОМЕСТИТЬ В КАВЫЧКИ, ПЕРВЫМ ПАРАМЕТРОМ ПРИ ЗАПУСКЕ ПРОГРАММЫ. ПРИМЕР: brainfuck.exe \"++.\"\n");

    char* code = "++++++++[>++++[>++>+++>+++>+<<<<-]>+>+>->>+[<]<-]>>.>---.+++++++..+++.>>.<-.<.+++.------.--------.>>+.>++.";
    if (argc > 1) code = argv[1];

    //------------------------------------------
    // 1. Алгоритм с рекурсией (С стек)
    //------------------------------------------
    LOG("\nСТАРТ: interpret_bf_recursive\n");
    memset(tape, 0, sizeof(tape));
    unsigned char* head = tape; // Отдать ячеку с начальным положением головки
    interpret_bf_recursive(code, &head);
    //------------------------------------------

    //------------------------------------------
    // 2. Алгоритм без рекурсии
    //------------------------------------------
    LOG("\nСТАРТ: interpret_bf_stack\n");
    memset(tape, 0, sizeof(tape));
    interpret_bf_stack(code, tape);
    //------------------------------------------

    getch();
    return 0;
}
