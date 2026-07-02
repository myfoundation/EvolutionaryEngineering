// boolean.cpp

#include <conio.h>
#include <locale.h>

#define LOG printf

/* Вывод подмножества по битовой маске */
void print_subset(const char* set[], int set_size, int mask)
{
    LOG("{ ");

    /* i-й бит установлен ? */
    for (int i = 0; i < set_size; ++i) { if (mask & (1 << i)) LOG("%s ", set[i]); }

    LOG("}\n");
}

/* Генератор булеана через битовые маски */
void generate_powerset(const char* set[], int set_size)
{
    int total_subsets = 1 << set_size; /* Общее количество подмножеств 2^set_size */
    for (unsigned int mask = 0; mask < total_subsets; ++mask) print_subset(set, set_size, mask);
}

int main(void)
{
    LOG("BOOLEAN = \n\n");

    const char* S[] = { "A", "B", "C", "D" }; /* Тестовое множество (строки) */
    int N = 4; /* Генерируем булеан для первых 3 элементов: { "A", "B", "C" } */

    generate_powerset(S, N);

    getch();
    return 0;
}
