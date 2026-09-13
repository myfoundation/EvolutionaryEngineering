/*

+-----------------------+-----------------------+-----------------------+
| Имя переменной        | Тип структуры данных  | Описание содержимого  |
+-----------------------+-----------------------+-----------------------+
| `[dataArray]`         | Массив массивов       | Первичные данные о    |
|                       | (до распаковки)       | сотрудниках           |
+-----------------------+-----------------------+-----------------------+
| `[dataArray2]`        | Массив объектов       |                       |
|                       |                       |                       |
+-----------------------+-----------------------+-----------------------+


+----+-------------------------------+----------------------------------+
| №  | Операция SQLike               | Описание действия                |
+----+-------------------------------+----------------------------------+
| 1  | `[Unpack]`                    | Распаковка `[dataArray]` в       |
|    |                               | массив объектов                  |
+----+-------------------------------+----------------------------------+
| 2  | `[Select (+ OrderBy)]`        | Выборка сотрудников с зарплатой  |
|    |                               | более `[50000]` по убыванию      |
+----+-------------------------------+----------------------------------+
| 3  | `[Select (As + Function)]`    | Выборка с конкатенацией имени и  |
|    |                               | фамилии через псевдоним          |
+----+-------------------------------+----------------------------------+
| 4  | `[SelectDistinct]`            | Выборка уникальных имен          |
+----+-------------------------------+----------------------------------+
| 5  | `[GroupBy (+ Having)]`        | Группировка по имени с агрегацией|
|    |                               | и фильтрацией групп              |
+----+-------------------------------+----------------------------------+
| 6  | `[Join (implicit)]`           | Неявное соединение двух таблиц   |
+----+-------------------------------+----------------------------------+
| 7  | `[Join]`                      | Явное соединение через `[On]`    |
+----+-------------------------------+----------------------------------+
| 8  | `[Join Using]`                | Соединение по совпадающим полям  |
+----+-------------------------------+----------------------------------+
| 9  | `[Natural Join]`              | Естественное соединение таблиц   |
+----+-------------------------------+----------------------------------+
| 10 | `[Left Join]`                 | Левое внешнее соединение         |
+----+-------------------------------+----------------------------------+
| 11 | `[Right Join]`                | Правое внешнее соединение        |
+----+-------------------------------+----------------------------------+
| 12 | `[Full Join]`                 | Полное внешнее соединение        |
+----+-------------------------------+----------------------------------+
| 13 | `[Cross Join]`                | Декартово произведение с лимитом |
+----+-------------------------------+----------------------------------+
| 14 | `[Union]`                     | Объединение уникальных строк     |
+----+-------------------------------+----------------------------------+
| 15 | `[Union All]`                 | Объединение всех строк           |
+----+-------------------------------+----------------------------------+
| 16 | `[Intersect]`                 | Пересечение уникальных строк     |
+----+-------------------------------+----------------------------------+
| 17 | `[Intersect All]`             | Пересечение всех строк           |
+----+-------------------------------+----------------------------------+
| 18 | `[Except]`                    | Разность уникальных строк        |
+----+-------------------------------+----------------------------------+
| 19 | `[Except All]`                | Разность всех строк              |
+----+-------------------------------+----------------------------------+
| 20 | `[Update]`                    | Увеличение зарплаты на `[5%]`    |
+----+-------------------------------+----------------------------------+
| 21 | `[InsertInto]`                | Добавление новой записи          |
+----+-------------------------------+----------------------------------+
| 22 | `[Select Into]`               | Копирование данных из одной      |
|    |                               | таблицы в другую                 |
+----+-------------------------------+----------------------------------+
| 23 | `[DeleteFrom]`                | Удаление записей с пустыми полями|
+----+-------------------------------+----------------------------------+
| 24 | `[Pack]`                      | Упаковка обратно в массив        |
|    |                               | массивов                         |
+----+-------------------------------+----------------------------------+


*/

var LOG = function() { console.log.apply(console, arguments); };

// Инициализация начальных таблиц
var dataArray = [
    ["Susanna", "Peterson", 55, 66000],
    ["Anette", "Irons", 26, 31000],
    ["Anette", "Steele", 62, 72000],
    ["Anette", "Steele", 50, 70000],
    ["John", "Green", 27, 80000],
    ["Debbi", "Jones", 58, 93000],
    ["George", "Green", 63, 40000],
    ["Anette", "Jones", 22, 76000],
    ["Susanna", "Black", 58, 52000],
    ["Debbi", "Jones", 44, 54000]
];

var dataArray2 = [
    { firstName: "Susanna", lastName: "Peterson", favColor: "green" },
    { firstName: "Anette", lastName: "Irons", favColor: "green" },
    { firstName: "Strange", lastName: "Mike", favColor: "red" }
];

// 1. Unpack (Распаковка массива массивов в массив объектов)
var q01 = SQLike.q(
{
    Unpack: dataArray,
    Columns: ['firstName', 'lastName', 'age', 'salary']
});
LOG(q01);

// 2. Select (+ order by)
var q02 = SQLike.q(
{
    Select: ['*'],
    From: dataArray,
    Where: function() { return this.salary > 50000; },
    OrderBy: ['salary', '|desc|']
});
LOG(q02);

// 3. Select, example 2 (Использование псевдонима и функции)
var q03 = SQLike.q(
{
    Select: [function() { return this.firstName + " " + this.lastName; }, '|as|', 'name'],
    From: dataArray,
    Where: function() { return this.salary > 50000; },
    OrderBy: ['salary', '|desc|']
});
LOG(q03);

// 4. Select Distinct
var q04 = SQLike.q(
{
    SelectDistinct: ['firstName'],
    From: dataArray,
    OrderBy: ['firstName']
});
LOG(q04);

// 5. Group By (+ агрегатные функции)
var q05 = SQLike.q(
{
    Select: ['firstName', '|count|', 'firstName', '|sum|', 'salary', '|min|', 'salary', '|max|', 'salary', '|avg|', 'salary'],
    From: dataArray,
    GroupBy: ['firstName'],
    Having: function() { return this.count_firstName > 1; },
    OrderBy: ['sum_salary', '|desc|']
});
LOG(q05);

// 6. Join (implicit)
var q06 = SQLike.q(
{
    Select: ['*'],
    From: { t1: dataArray, t2: dataArray2 },
    Where: function() { return this.t1.firstName == this.t2.firstName && this.t1.lastName == this.t2.lastName; }
});
LOG(q06);

// 7. Join
var q07 = SQLike.q(
{
    Select: ['*'],
    From: { t1: dataArray },
    Join: { t2: dataArray2 },
    On: function() { return this.t1.firstName == this.t2.firstName && this.t1.lastName == this.t2.lastName; }
});
LOG(q07);

// 8. Join Using
var q08 = SQLike.q(
{
    Select: ['*'],
    From: { t1: dataArray },
    Join: { t2: dataArray2 },
    Using: ['firstName', 'lastName']
});
LOG(q08);

// 9. Natural Join
var q09 = SQLike.q(
{
    Select: ['*'],
    From: { t1: dataArray },
    NaturalJoin: { t2: dataArray2 },
    Where: function() { return this.t1.firstName != 'Vicki'; }
});
LOG(q09);

// 10. Left Join
var q10 = SQLike.q(
{
    Select: ['*'],
    From: { t1: dataArray },
    LeftJoin: { t2: dataArray2 },
    On: function() { return this.t1.firstName == this.t2.firstName && this.t1.lastName == this.t2.lastName; }
});
LOG(q10);

// 11. Right Join
var q11 = SQLike.q(
{
    Select: ['*'],
    From: { t1: dataArray },
    RightJoin: { t2: dataArray2 },
    On: function() { return this.t1.firstName == this.t2.firstName && this.t1.lastName == this.t2.lastName; }
});
LOG(q11);

// 12. Full Join
var q12 = SQLike.q(
{
    Select: ['*'],
    From: { t1: dataArray },
    FullJoin: { t2: dataArray2 },
    On: function() { return this.t1.firstName == this.t2.firstName && this.t1.lastName == this.t2.lastName; },
    Where: function() { return this.t1.firstName != "George"; }
});
LOG(q12);

// 13. Cross Join (+ limit)
var q13 = SQLike.q(
{
    Select: ['*'],
    From: { t1: dataArray },
    CrossJoin: { t2: dataArray2 },
    Limit: 100
});
LOG(q13);

// 14. Union
var q14 = SQLike.q(
{
    Union: [
        {
            Select: ['firstName', 'lastName'],
            From: dataArray
        },
        {
            Select: ['firstName', 'lastName'],
            From: dataArray2
        }
    ]
});
LOG(q14);

// 15. Union All
var q15 = SQLike.q(
{
    UnionAll: [
        {
            Select: ['firstName', 'lastName'],
            From: dataArray
        },
        {
            Select: ['firstName', 'lastName'],
            From: dataArray2
        }
    ]
});
LOG(q15);

// 16. Intersect
var q16 = SQLike.q(
{
    Intersect: [
        {
            Select: ['firstName', 'lastName'],
            From: dataArray
        },
        {
            Select: ['firstName', 'lastName'],
            From: dataArray2
        }
    ]
});
LOG(q16);

// 17. Intersect All
var q17 = SQLike.q(
{
    IntersectAll: [
        {
            Select: ['firstName', 'lastName'],
            From: dataArray
        },
        {
            Select: ['firstName', 'lastName'],
            From: dataArray2
        }
    ]
});
LOG(q17);

// 18. Except
var q18 = SQLike.q(
{
    Except: [
        {
            Select: ['firstName', 'lastName'],
            From: dataArray2
        },
        {
            Select: ['firstName', 'lastName'],
            From: dataArray
        }
    ]
});
LOG(q18);

// 19. Except All
var q19 = SQLike.q(
{
    ExceptAll: [
        {
            Select: ['firstName', 'lastName'],
            From: dataArray2
        },
        {
            Select: ['firstName', 'lastName'],
            From: dataArray
        }
    ]
});
LOG(q19);

// 20. Update (Увеличение зарплаты на 5% сотрудникам старше 40 лет)
var q20 = SQLike.q(
{
    Update: dataArray,
    Set: function() { this.salary *= 1.05; },
    Where: function() { return this.age > 40; }
});
LOG(q20);

// 21. Insert into
var q21 = SQLike.q(
{
    InsertInto: dataArray,
    Values: { firstName: "Michael", lastName: "Arvidson", age: 55, salary: 100000 }
});
LOG(q21);

// 22. Select into
var q22 = SQLike.q(
{
    Select: ['*'],
    From: dataArray2,
    Into: dataArray
});
LOG(q22);

// 23. Delete from
var q23 = SQLike.q(
{
    DeleteFrom: dataArray,
    Where: function() { return this.salary === undefined; }
});
LOG(q23);

// 24. Pack (Упаковка обратно в массив массивов)
var q24 = SQLike.q(
{
    Pack: dataArray,
    Columns: ['firstName', 'lastName', 'age', 'salary']
});
LOG(q24);

