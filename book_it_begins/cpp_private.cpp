// cpp_private.cpp

#include <conio.h>
#include <locale.h>

#define LOG printf

// В C++ поле password "надежно" скрыто от доступа
class VaultCpp
{
private:
    int secret_id;
    int password; // К этому полю нельзя обратиться как v.password
public:
    VaultCpp(int id, int pass) : secret_id(id), password(pass) {}
    void print() { LOG("ID: %d, PASS: %d\n", secret_id, password); }
};

// Как объект выглядит в памяти
struct VaultC
{
    int secret_id;
    int password;
};

int main()
{
    VaultCpp v(1, 12345);
    v.print(); // Выведет: ID: 1, PASS: 12345

    // v.password = 99999; // Компилятор выдаст ошибку
    
    // Взлом инкапсуляции через Си-указатели:
    // 1. Взять адрес объекта и привести к указателю на С-структуру
    struct VaultC* hack_view = (struct VaultC*)&v;
    hack_view->password = 77777; // Перезапись private-поля напрямую

    v.print(); // Выведет: ID: 1, PASS: 77777

    // 2. Альтернативный взлом через адресную арифметику (смещение в байтах):
    // Поле password идет вторым, сразу за secret_id (4 байта)
    int* raw_password_ptr = (int*)((char*)&v + sizeof(int));
    *raw_password_ptr = 99999; // Еще одна перезапись

    v.print(); // Выведет: ID: 1, PASS: 99999 — защита разрушена

    getch();
    return 0;
}
