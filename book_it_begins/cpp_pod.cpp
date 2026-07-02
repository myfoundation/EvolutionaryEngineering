// cpp_pod.cpp

#include <conio.h>
#include <stdio.h>
#include <cstdint>  // типы с фиксированной шириной
#include <cstddef>  // макрос offsetof
#include <type_traits> // std::is_pod

#define LOG printf

// Функция автоматического определения порядка байт
bool is_little_endian()
{
    uint16_t number = 0x0001;
    // Если в первом байте в памяти 0x01, это Little-Endian
    return (*((uint8_t*)&number) == 0x01);
}

// POD-структура
struct Packet
{
    uint8_t  id;       // 1 байт
    // Компилятор вставит 3 байта padding, чтобы выровнять val32 по адресу, кратному 4
    uint32_t val32;    // 4 байта
    uint16_t checksum; // 2 байта
    // Компилятор добавит еще 2 байта padding, чтобы общий размер структуры (12) был кратен 4

    // МОЖНО: невиртуальные функции
    void print() { LOG("id = %d\n", id); }
};

// Не POD-структура
struct NotPOD
{
    int x = 5;   // НЕЛЬЗЯ: компилятор создаёт конструктор для инициализации полей
    NotPOD() {}  // НЕЛЬЗЯ: пользовательский (нетривиальный) конструктор
    ~NotPOD() {} // НЕЛЬЗЯ: пользовательский (нетривиальный) деструктор
    virtual void print() {} // НЕЛЬЗЯ: добавляется указатель на vtable
};

int main()
{
    Packet pkt{ 0xAA, 0x12345678, 0xBBBB };

    // 1. Информация об архитектуре
    LOG("--- System Info ---\n");
    if (is_little_endian()) LOG("Byte Order: Little-Endian\n");
    else LOG("Byte Order: Big-Endian\n");

    if (std::is_pod<NotPOD>::value) LOG("NotPOD IS a valid POD structure.\n");
    else LOG("NotPOD IS NOT a POD structure.\n\n");

    if (std::is_pod<Packet>::value) LOG("Packet IS a valid POD structure.\n");
    else LOG("Packet IS NOT a POD structure.\n\n");

    LOG("Total struct size: %zu bytes (Expected 12 due to alignment)\n\n", sizeof(Packet));

    // 2. Значение поля, его адрес и смещение (offsets)
    LOG("--- Structure Layout ---\n");

    // %p — вывод адреса (указателя), %X —  числа в Hex
    LOG("pkt.id       | Address: %p | Offset: %zu | Value: 0x%X\n",
                (void*)&pkt.id, offsetof(Packet, id), pkt.id);

    LOG("pkt.val32    | Address: %p | Offset: %zu | Value: 0x%X\n",
                (void*)&pkt.val32, offsetof(Packet, val32), pkt.val32);

    LOG("pkt.checksum | Address: %p | Offset: %zu | Value: 0x%X\n",
                (void*)&pkt.checksum, offsetof(Packet, checksum), pkt.checksum);

    getch();
    return 0;
}
