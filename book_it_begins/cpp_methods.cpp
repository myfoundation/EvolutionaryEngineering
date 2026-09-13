// cpp_methods.cpp

#include <conio.h>
#include <locale.h>

#define LOG printf

struct Vector { int x, y; };

// В С: указатель на структуру передается явно
void Vector_move_C(struct Vector* _this, int dx, int dy) {
    _this->x += dx; _this->y += dy;
}

// В С++: указатель на структуру (this) передается скрыто
struct VectorCpp {
    int x, y;
    void move_Cpp(int dx, int dy) {
        this->x += dx; this->y += dy;
    }
};

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    Vector v_c = {10, 20}; VectorCpp v_cpp = {10, 20};

    // Размер структур одинаков
    LOG("C/C++:   SIZE v_c=%d, SIZE v_cpp=%d\n", sizeof(v_c), sizeof(v_cpp));  // 8, 8

/*
  ВЫЗОВ В C (ЯВНЫЙ ПАРАМЕТР)       ВЫЗОВ В C++ (СКРЫТЫЙ ПАРАМЕТР)

Vector_move_C(&v_c, 5, 5);       v_cpp.move_Cpp(5, 5);
       │                               │
       V (Компиляция)                  V (Компиляция)
В стек/регистры:                 В стек/регистры:
1. Адрес объекта (&v_c)          1. Адрес объекта (&v_cpp) -> 'this'
2. Число 5                       2. Число 5
3. Число 5                       3. Число 5
       │                               │
       V                               V
Вызов функции по адресу          Вызов функции по адресу

*/

    Vector_move_C(&v_c, 5, 5); // Явный вызов в C
    v_cpp.move_Cpp(5, 5);      // Скрытый вызов в C++ (под капотом передается &v_cpp)

    LOG("C:   x=%d, y=%d\n", v_c.x, v_c.y);     // 15, 25
    LOG("C++: x=%d, y=%d\n", v_cpp.x, v_cpp.y); // 15, 25

    // Доказываем, что метод C++ — это обычная С-функция
    // Хак: Можно вызвать "метод" C++ как C-функцию, если
    // первым параметром в "метод" передать указатель на структуру.
    union
    {
        void (VectorCpp::*cpp_method)(int, int);
        void (*c_function)(VectorCpp*, int, int);
    } cpp_c;

    cpp_c.cpp_method = &VectorCpp::move_Cpp;
    cpp_c.c_function(&v_cpp, -5, -5);

    LOG("Hacked C++: x=%d, y=%d\n", v_cpp.x, v_cpp.y); // 10, 20

    getch();
    return 0;
}
