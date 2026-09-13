// js_sql.js

var LOG = function() { console.log.apply(console, arguments); };

// Декартово произведение
function cartesianProduct()
{
    return _.reduce(arguments, function(a, b)
    {
        return _.flatten(_.map(a, function(x)
        {
            return _.map(b, function(y)
            {
                return _.extend({}, x, y);
            });
        }), true);
    }, [{}]);
}


//------------------------------------------
// Исходные множества
//------------------------------------------

var tableA = [{ a1: 1 }];
var tableB = [{ b1: 10, b2: 11 }, { b1: 20, b2: 21 }];
var tableC = [
    { c1: 100, c2: 101, c3: 102 },
    { c1: 200, c2: 201, c3: 202 },
    { c1: 300, c2: 301, c3: 302 }
];

//------------------------------------------
// Пример 1. SELECT-FROM-WHERE
//------------------------------------------

// 1. FROM (Вычисление AxBxC)
var relationFrom = cartesianProduct(tableA, tableB, tableC);

LOG(relationFrom);

// 2. WHERE (Фильтрация по цепочке предикатов)
var relationWhere = _.filter(relationFrom, function(row)
{
    return row.a1 < row.b1 && row.c3 === 202;
});

LOG(relationWhere);

// 3. SELECT (Фильтрация подмножества атрибутов)
var result = _.map(relationWhere, function(row)
{
    return _.pick(row, 'a1', 'b1', 'b2', 'c1', 'c3');
});

LOG(result);

//------------------------------------------
// Пример 2. SELECT-UNION-SELECT
//------------------------------------------

var q1 = _.map(tableB, function(row)
{
    return {
        c1: row.b1,
        c2: row.b2,
        c3: null
    };
});

LOG(q1);

// 2. ПОДЗАПРОС Q2: Проекция схемы таблицы C
var q2 = _.map(tableC, function(row)
{
    return {
        c1: row.c1,
        c2: row.c2,
        c3: row.c3
    };
});

LOG(q2);

// 3. ПОДЗАПРОС Q3: Реляционное объединение (UNION)

// Объединить подмножества строк
var q3 = q1.concat(q2);

LOG(q3);

// Удалить если есть дубликаты
var q4 = _.uniq(q3, false, function(row)
{
    return _.map(_.keys(row).sort(), function(key)
    {
        return key + ':' + row[key];
    }).join(',');
});

LOG(q4);

//------------------------------------------
// Пример 3. SELECT-WHERE-IN
//------------------------------------------

// Множество значений для фильтрации строк
var includesMathSet = [10, 100, 300];

// Фильтрация таблицы q3
var filteredResult = _.filter(q3, function(row)
{
    return _.contains(includesMathSet, row.c1);
});

LOG(filteredResult);

