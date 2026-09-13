// lib_graph.js

var exports = {};

(function () 
{

var __each = function(obj, callback, context) { [].forEach.call(obj, callback, context); };

// 1. walkBFS (Итеративный обход в ширину)
function walkBFS(root, iteratee)
{
    if (!root) { return; }
    
    var queue = [root];
    while (queue.length)
    {
        var item = queue.shift();
        iteratee(item);
        
        __each(item.child || [], function(child) {
            queue.push(child);
        });
    }
}

// 2. walkBFS_Levels (Итеративный BFS с разделением по уровням)
function walkBFS_Levels(root, iteratee)
{
    if (!root) { return []; }
    
    var queue = [root];
    var ans = [];

    while (queue.length)
    {
        var len = queue.length;
        var level = [];
        
        for (var i = 0; i < len; i++)
        {
            var item = queue.shift();
            level.push(item);
            iteratee(item);
            
            __each(item.child || [], function(child) {
                queue.push(child);
            });
        }
        ans.push(level);
    }
    return ans;
}

// 3. walkPreOrder_Recursive (Прямой обход - Рекурсия)
function walkPreOrder_Recursive(root, iteratee)
{
    if (!root) { return; }
    
    iteratee(root);
    
    __each(root.child || [], function(child) {
        walkPreOrder_Recursive(child, iteratee);
    });
}

// 4. walkPreOrder_Iterative (Прямой обход - Стек)
function walkPreOrder_Iterative(root, iteratee)
{
    if (!root) { return; }
    
    var stack = [root];
    while (stack.length)
    {
        var item = stack.pop();
        iteratee(item);

        var children = item.child || [];
        // Цикл с конца обязателен, чтобы первый (левый) ребенок оказался на вершине стека
        for (var i = children.length - 1; i >= 0; i--)
        {
            stack.push(children[i]);
        }
    }
}

// 5. walkInOrder_Recursive (Центрированный обход - Рекурсия)
function walkInOrder_Recursive(root, iteratee)
{
    if (!root) { return; }
    
    var children = root.child || [];

    if (children.length > 0) 
    { 
        walkInOrder_Recursive(children[0], iteratee); 
    }

    iteratee(root);

    for (var i = 1; i < children.length; i++)
    {
        walkInOrder_Recursive(children[i], iteratee);
    }
}

// 6. walkInOrder_Iterative (Центрированный обход - Стек)
function walkInOrder_Iterative(root, iteratee)
{
    if (!root) { return; }

    var stack = [{ node: root, index: 0 }];
    while (stack.length)
    {
        var item = stack[stack.length - 1];
        var children = item.node.child || [];

        if (item.index === 0)
        {
            item.index = 1; // Следующий проход по этому узлу — вызов iteratee
            if (children.length > 0) 
            { 
                stack.push({ node: children[0], index: 0 }); 
            }
        }
        else if (item.index === 1)
        {
            iteratee(item.node);
            item.index = 2; // Следующий проход — перебор остальных детей
        }
        else
        {
            var childIdx = item.index - 1; // Трансляция состояния в индекс массива
            if (childIdx < children.length)
            {
                item.index++;
                stack.push({ node: children[childIdx], index: 0 });
            }
            else 
            { 
                stack.pop(); // Сам узел и все его дети полностью обработаны
            }
        }
    }
}

// 7. walkPostOrder_Recursive (Обратный обход - Рекурсия)
function walkPostOrder_Recursive(root, iteratee)
{
    if (!root) { return; }
    
    __each(root.child || [], function(child) {
        walkPostOrder_Recursive(child, iteratee);
    });
    
    iteratee(root);
}

// 8. walkPostOrder_Iterative (Обратный обход - Два стека)
function walkPostOrder_Iterative(root, iteratee)
{
    if (!root) { return; }

    var tempStack = [root];
    var mainStack = [];

    while (tempStack.length)
    {
        var item = tempStack.pop();
        mainStack.push(item);

        __each(item.child || [], function(child) {
            tempStack.push(child);
        });
    }

    for (var j = mainStack.length - 1; j >= 0; j--)
    {
        iteratee(mainStack[j]);
    }
}

var root = this;
if (typeof exports !== "undefined") 
{
    root = exports;
}

root.walkBFS = walkBFS;
root.walkBFS_Levels = walkBFS_Levels;
root.walkPreOrder_Recursive = walkPreOrder_Recursive;
root.walkPreOrder_Iterative = walkPreOrder_Iterative;
root.walkInOrder_Recursive = walkInOrder_Recursive;
root.walkInOrder_Iterative = walkInOrder_Iterative;
root.walkPostOrder_Recursive = walkPostOrder_Recursive;
root.walkPostOrder_Iterative = walkPostOrder_Iterative;

}).call(this);

/*
							
+---------------------------+------------------------+-------------------------------------------------------+
| Функция                   | Тип и способ           | Особенности и применение                              |
+---------------------------+------------------------+-------------------------------------------------------+
| [walkBFS]                 | [BFS], Итеративный     | Обход по уровням без сохранения структуры.            |
|                           | (Очередь)              | Минимальный расход памяти. Возвращает [undefined].    |
+---------------------------+------------------------+-------------------------------------------------------+
| [walkBFS_Levels]          | [BFS], Итеративный     | Группирует узлы по уровням глубины.                   |
|                           | (Очередь + счетчик)    | Возвращает двумерный массив [results].                |
+---------------------------+------------------------+-------------------------------------------------------+
| [walkPreOrder_Recursive]  | [DFS] (Pre-Order),     | Порядок: Корень -> Дети. Простая реализация.          |
|                           | Рекурсивный            | Риск переполнения стека вызовов на глубоких деревьях. |
+---------------------------+------------------------+-------------------------------------------------------+
| [walkPreOrder_Iterative]  | [DFS] (Pre-Order),     | Порядок: Корень -> Дети. Безопасен для глубоких       |
|                           | Итеративный (Стек)     | деревьев. Использует явный стек [stack].              |
+---------------------------+------------------------+-------------------------------------------------------+
| [walkInOrder_Recursive]   | [DFS] (In-Order),      | Порядок: Первый ребенок -> Корень -> Остальные дети.  |
|                           | Рекурсивный            | Применяется в бинарных деревьях поиска.               |
+---------------------------+------------------------+-------------------------------------------------------+
| [walkInOrder_Iterative]   | [DFS] (In-Order),      | Порядок: Первый ребенок -> Корень -> Остальные дети.  |
|                           | Итеративный            | Использует стек с флагами стадий [stage].             |
+                           | (Стек состояний)       |                                                       |
+---------------------------+------------------------+-------------------------------------------------------+
| [walkPostOrder_Recursive] | [DFS] (Post-Order),    | Порядок: Дети -> Корень. Применяется для удаления     |
|                           | Рекурсивный            | узлов и вычисления размеров снизу вверх.              |
+---------------------------+------------------------+-------------------------------------------------------+
| [walkPostOrder_Iterative] | [DFS] (Post-Order),    | Порядок: Дети -> Корень. Использует вспомогательный   |
|                           | Итеративный (Два стека)| массив [visitOrder] для реверсирования обхода.        |
+---------------------------+------------------------+-------------------------------------------------------+
							
ГРАФ

         +---+         
         | a |         
         +---+         
       /       \       
  +---+         +---+    
  | b |         | c |    
  +---+         +---+    
 /     \       /     \   
+---+ +---+  +---+ +---+
| d | | e |  | f | | g |
+---+ +---+  +---+ +---+


+---------------------------+-------------------------------+
| Порядок обхода            | Эталон (Ожидаемый результат)  |
+---------------------------+-------------------------------+
| [walkBFS]                 | ["a","b","c","d","e","f","g"] |
+---------------------------+-------------------------------+
| [walkBFS_Levels]          | ["a","b","c","d","e","f","g"] |
+---------------------------+-------------------------------+
| [walkPreOrder_Recursive]  | ["a","b","d","e","c","f","g"] |
+---------------------------+-------------------------------+
| [walkPreOrder_Iterative]  | ["a","b","d","e","c","f","g"] |
+---------------------------+-------------------------------+
| [walkInOrder_Recursive]   | ["d","b","e","a","f","c","g"] |
+---------------------------+-------------------------------+
| [walkInOrder_Iterative]   | ["d","b","e","a","f","c","g"] |
+---------------------------+-------------------------------+
| [walkPostOrder_Recursive] | ["d","e","b","f","g","c","a"] |
+---------------------------+-------------------------------+
| [walkPostOrder_Iterative] | ["d","e","b","f","g","c","a"] |
+---------------------------+-------------------------------+

*/

var lib = exports;

var __each = function(obj, callback, context) { [].forEach.call(obj, callback, context); };
var LOG = function() { console.log.apply(console, arguments); };

//------------------------------------------
// ОБХОДЫ ГРАФА
//------------------------------------------

// граф в JSON
var graphJson = {
    "id": "a",
    "child": [
        {
            "id": "b",
            "child": [
                { "id": "d" },
                { "id": "e" }
            ]
        },
        {
            "id": "c",
            "child": [
                { "id": "f" },
                { "id": "g" }
            ]
        }
    ]
};

// Функция запуска теста (предоставлена пользователем, оформлена в стиле Allman)
var runTest = function(name, walkFn)
{
    var result = [];
    walkFn(graphJson, function(node)
    {
        result.push(node.id);
    });
    LOG(name);
    LOG("[" + result.join(",") + "]");
    LOG("");
    return result;
};

// Массив тест-кейсов с эталонными значениями
var testCases = [
    {
        name: "walkBFS",
        fn: lib.walkBFS,
        expected: ["a", "b", "c", "d", "e", "f", "g"]
    },
    {
        name: "walkBFS_Levels",
        fn: lib.walkBFS_Levels,
        expected: ["a", "b", "c", "d", "e", "f", "g"]
    },
    {
        name: "walkPreOrder_Recursive",
        fn: lib.walkPreOrder_Recursive,
        expected: ["a", "b", "d", "e", "c", "f", "g"]
    },
    {
        name: "walkPreOrder_Iterative",
        fn: lib.walkPreOrder_Iterative,
        expected: ["a", "b", "d", "e", "c", "f", "g"]
    },
    {
        name: "walkInOrder_Recursive",
        fn: lib.walkInOrder_Recursive,
        expected: ["d", "b", "e", "a", "f", "c", "g"]
    },
    {
        name: "walkInOrder_Iterative",
        fn: lib.walkInOrder_Iterative,
        expected: ["d", "b", "e", "a", "f", "c", "g"]
    },
    {
        name: "walkPostOrder_Recursive",
        fn: lib.walkPostOrder_Recursive,
        expected: ["d", "e", "b", "f", "g", "c", "a"]
    },
    {
        name: "walkPostOrder_Iterative",
        fn: lib.walkPostOrder_Iterative,
        expected: ["d", "e", "b", "f", "g", "c", "a"]
    }
];

// Итерация по тестам с использованием Underscore.js в стандарте ES3
__each(testCases, function(test)
{
    var actual = runTest(test.name, test.fn);
    
    // Верификация через сравнение JSON-строк
    var isPassed = JSON.stringify(actual) === JSON.stringify(test.expected);
    
    LOG("Verification for " + test.name + ":");
    LOG("Expected: " + JSON.stringify(test.expected));
    LOG("Actual:   " + JSON.stringify(actual));
    LOG("Status:   " + (isPassed ? "PASSED" : "FAILED"));
    LOG("------------------------------------------------");
    LOG("");
});

//------------------------------------------
// ЯЗЫК HALFTONE
//------------------------------------------

var halftone = "; halftone lang sample, past to https://arborjs.org/halfviz/\n\n";
// Генерация узлов
function halftone_print_node(node, CTX)
{
    if(Math.random() < 0.5) halftone += (node.id + "\n");
    else  halftone += (node.id + ' { color:red }; random >= 0.5\n');
}
// Генерация рёбер
function halftone_print_edge(node, CTX)
{
    halftone += (CTX.parent.id + ' -> ' + node.id + '\n');
}

// Обход графа
function halftone_walkPreOrder(node, iteratee, CTX)
{
    if (!node) { return; }

    iteratee(node, CTX ? CTX : { parent : { id: 'null' } });
    
    __each(node.child || [], function(child) {
        halftone_walkPreOrder(child, iteratee, { parent:node });
    });
}

// Генерация графа на языке Halftone
halftone_walkPreOrder(graphJson, halftone_print_node);
halftone_walkPreOrder(graphJson, halftone_print_edge);
LOG(halftone);

/*

; halftone lang sample, copy & past to https://arborjs.org/halfviz/

a { color:red }; random >= 0.5
b { color:red }; random >= 0.5
d { color:red }; random >= 0.5
e
c { color:red }; random >= 0.5
f
g
null -> a
a -> b
b -> d
b -> e
a -> c
c -> f
c -> g

*/
