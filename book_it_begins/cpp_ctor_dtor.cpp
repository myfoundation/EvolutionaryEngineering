// cpp_ctor_dtor.cpp

#include <conio.h>
#include <locale.h>

#define LOG printf

/*
ГРАФ В С++ (Множественный выход)    ГРАФ В С (Идиома ядра ОС)

      [ Вход ]                         [ Вход ]
         |                                |
         V                                V
  RAII_Cpp obj;                    RAII_C_ctor();
         |                                |
         V                                V
 +--------------------------+     +--------------------------+
 |      switch (val)        |     |      switch (val)        |
 +--------------------------+     +--------------------------+
   |1    |2    |3  (default)        |1    |2    |3  (default)
   |     |     |       |            |     |     |       |
   V     V     V       V            V     V     V       V
[Dtor] [Dtor] [Dtor] [Work]       RET=-1 RET=-2 RET=-3  [Work]
ret -1 ret -2 ret -3   |            |     |     |       |
                       V            +-----+-----+       V
                    [Dtor]                | (goto)    RET=0
                    ret 0                 V             |
                                      cleanup: <--------+
                                   RAII_C_dtor();
                                          |
                                          V
                                      return RET;


*/

// Имитация ресурса
struct ResourceC   { int dummy; };
struct ResourceCpp {
    ResourceCpp()  { LOG("Ctor C++\n"); }
    ~ResourceCpp() { LOG("Dtor C++\n"); }
};
void ResourceC_ctor(struct ResourceC* r) { LOG("Ctor C\n"); }
void ResourceC_dtor(struct ResourceC* r) { LOG("Dtor C\n"); }

// --- В СТИЛЕ C++ (Как видит программист) ---
int test_cpp(int val) {
    ResourceCpp obj; // Скрытый Ctor

    switch (val) {
        case 1:  return -1; // Скрытый Dtor; return -1;
        case 2:  return -2; // Скрытый Dtor; return -2;
        case 3:  return -3; // Скрытый Dtor; return -3;
        default: break;
    }
    return 0; // Скрытый Dtor; return 0;
}

// --- В СТИЛЕ С (Как это устроен граф под капотом) ---
int test_c(int val) {
    int RET = 0;
    struct ResourceC obj;
    ResourceC_ctor(&obj); // Явный Ctor

    switch (val) {
        case 1:  RET = -1; goto cleanup;
        case 2:  RET = -2; goto cleanup;
        case 3:  RET = -3; goto cleanup;
        default: break;
    }

cleanup: // Единый узел графа, куда сходятся ВСЕ стрелки
    ResourceC_dtor(&obj); // Явный Dtor
    return RET;
}

int main() {
    LOG("--- Test C++ ---\n"); test_cpp(2);
    LOG("\n--- Test C ---\n");   test_c(2);

    getch();
    return 0;
}
