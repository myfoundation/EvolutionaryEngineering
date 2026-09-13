// cpp_virtual_2

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>

#define LOG printf

/*
   ПАМЯТЬ

       С++ ОБЪЕКТ (obj_cpp)                       С ОБЪЕКТ (obj_c)
   +--------------------------+            +--------------------------+
00 | [ vptr ] ----------------|---+    00  | [ vptr ] ----------------|---+
   |  Указывает на С++ vtable |   |        |  Указывает на С vtable   |   |
08 | [ data = 42 ]            |   |    08  | [ data = 99 ]            |   |
   +--------------------------+   |        +--------------------------+   |
                                  V                                       V
                       Вызов функции                           Вызов функции

*/

// --- C++ ЧАСТЬ ---
struct BaseCpp {
    int data;
    virtual void speak() { LOG("Base C++ [data=%d]\n", data); }
};

struct DerivedCpp : BaseCpp {
    DerivedCpp(int val) { data = val; }
    void speak() override { LOG("Derived C++ [data=%d]\n", data); }
};

// --- С ЧАСТЬ (ПОД КАПОТОМ) ---
struct BaseC;
struct BaseC { void** vptr; int data; };

typedef void (*SpeakFunc)(struct BaseC* _this);

void DerivedC_speak(struct BaseC* _this) { LOG("Derived C   [data=%d]\n", _this->data); }
void* DerivedC_vtable[] = { (void*)DerivedC_speak };

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    // 1. Создать объект C++
    BaseCpp* obj_cpp = new DerivedCpp(42);

    // 2. Создать объект С
    BaseC* obj_c = (BaseC*)malloc(sizeof(BaseC));
    obj_c->vptr = DerivedC_vtable;
    obj_c->data = 99;

    LOG("--- ВЗАИМНЫЕ ХАКИ ВЫЗОВОВ ФУНКЦИЙ ---\n\n");

    LOG("Вызов 1 (Стандарт C++): "); obj_cpp->speak();
    LOG("Вызов 2 (Стандарт C)  : "); ((SpeakFunc)obj_c->vptr[0])(obj_c);
    LOG("Вызов 3 (С == C++)    : "); ((BaseCpp*)obj_c)->speak();
    LOG("Вызов 4 (C++ == С)    : "); BaseC* fake_c = (BaseC*)obj_cpp; ((SpeakFunc)fake_c->vptr[0])(fake_c);

    // ВЫЗОВ 5,6: Чистая адресная арифметика: взять функцию из таблицы,
    // и передать ей первым аргументом «чужую» память.

    LOG("Вызов 5 (Метод C->Cpp): ");
    SpeakFunc c_method = (SpeakFunc)obj_c->vptr[0];  // Достать функцию С
    c_method((BaseC*)obj_cpp);                       // Вызвать её с C++ объектом. Выведет 42

    LOG("Вызов 6 (Метод Cpp->C): ");
    void** cpp_vtable = *(void***)obj_cpp;           // Достать vtable из C++ памяти
    SpeakFunc cpp_method = (SpeakFunc)cpp_vtable[0]; // Взять из нее 0-й метод
    cpp_method((BaseC*)obj_c);                       // Вызвать его с C объектом. Выведет 99

    free(obj_c); delete obj_cpp;

    getch();
    return 0;
}
