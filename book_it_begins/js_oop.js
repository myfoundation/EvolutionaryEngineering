/*
 * Copyright (C) 2026 MasterMentor
 *
 * This library is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see https://www.gnu.org .
 */

/*
 #######   #######  ########               ##  ######  
##     ## ##     ## ##     ##              ## ##    ## 
##     ## ##     ## ##     ##              ## ##       
##     ## ##     ## ########               ##  ######  
##     ## ##     ## ##               ##    ##       ## 
##     ## ##     ## ##        ###    ##    ## ##    ## 
 #######   #######  ##        ###     ######   ######  
*/
 
//------------------------------------------
// OOP CLASS REALIZATION. PROOF OF CONCEPT (LANG:RU)
//------------------------------------------
/*
Реализация ООП в JS (ES3/Allman style).

Sources https://github.com/myfoundation/OmNom.js
VERSION 1.0.00    23:39 13.05.2026

1. new_clone()  - клонирует произвольный JavaScript объект
2. new_object() - реализует полиморфизм и множественное наследование
   var obj = new_object("[parentObj, [constructor_args], constructor_context], ...)
3. Для сохранения в поле _parents созданного экземпляра объекта копий экземпляров родительских объектов
   первым элементом в цепочке наследования ставить объект ObjectWithParentsClass.
4. Сервисные поля _constructor, _parents, _class_name можно сделать скрытыми (#_constructor, ...), но нам это не нужно.

	var class1 = 
	{
		a : 1,
		b : 2,
		_constructor : function ()
		{
			LOG('class1 _constructor()');
		},
	};
	var class2 = 
	{
		a : 3,
		c : 4,
		_constructor : function (new_a, new_c)
		{
			LOG('class2 _constructor() = ', new_a, new_c);
			LOG(arguments);

			this.a = new_a;
			this.c = new_c;
		},
	};
	var classN = 
	{
	};
	
	// Конструктор по умолчанию: new_object(class) или new_object([class])
	var obj_1 = new_object(class1); LOG(obj_1);
	// Множественное наследование: new_object([parent, [constructor_args], constructor_context], ...)
	var obj_2 = new_object(class1, [class2, [30, 40]], classN); LOG(obj_2);

	// Множественное наследование (с сохранением родительских структур)
	var obj_3 = new_object(ObjectWithParentsClass, class1, [class2, [70, 80]], classN); LOG(obj_3);
	IsObjectInstanceOf(obj_3, "class1");
	IsObjectInstanceOf(obj_3, "class4");
*/
//------------------------------------------


(function () {

//------------------------------------------
// СЕРВИСНЫЕ ОБЕРТКИ
//------------------------------------------

var LOG = function() { console.log.apply(console, arguments); };

var __isArray = Array.isArray;

/**
 * Объединение свойств контейнеров без глубокого копирования. Модифицирует target
 *
 * @param {Object} target -  контейнер-назначение
 * @param {...Object} sources - один или несколько контейнеров-источников
 * @returns {Object} - модифицированный target.
 */
var __extend = function(target) { var sources = Array.prototype.slice.call(arguments, 1); return Object.assign.apply(Object, [target].concat(sources)); };

/**
 * Полное клонирование объекта
 *
 * @param {*} source - источник (примитив, массив или объект) для клонирования.
 * @param {Object|Array} [target] - возвращаемый контейнер
 * @returns {*} копия объекта
 */
var __cloneDeep = function(source, target)
{
    if (source === null || typeof source !== 'object') return source;
    if (!target) target = __isArray(source) ? [] : {};

    for (var key in source)
        if (Object.prototype.hasOwnProperty.call(source, key))
        {
            var val = source[key];

            if (val !== null && typeof val === 'object') target[key] = __cloneDeep(val, target[key]);
            else target[key] = val;
        }

    return target;
};

/**
 * Глубокое слияние (Deep Merge) структуры источника в структуру приемника.
 *
 * @param {Object} target - модифицируемый контейнер-приемник (куда).
 * @param {Object} source - контейнер-источник для наложения структур (откуда).
 * @returns {Object} - модифицированный контейнер.
 */
var __merge = function(target, source) { return __cloneDeep(source, target); };

/**
 * Клонирование контейнера с последовательным накладыванием свойств дополнительных контейнеров.
 *
 * @param {Object} mixed_from - объект-источник
 * @param {...Object} [merge_with] - дополнительные структуры для модификации результирующего клона.
 * @returns {Object} - модифицированный объект
 */
function new_clone(mixed_from, merge_with_0 /* merge_with_1, ..., ect */)
{
	var ret = __cloneDeep(mixed_from);

	for(var i = 1; i<arguments.length; i++) { ret = __merge(ret, arguments[i]); }
	return ret;
}

//------------------------------------------
// ЯДРО ОБЪЕКТНОЙ МОДЕЛИ
//------------------------------------------
/**
 * Компонент подсистемы RTTI ((Run-Time Type Information). Проверяет принадлежность экземпляра объекта к
 * классу по его имени (математическкая проверка принадлежности к множеству).
 *
 * @param {Object} obj - проверяемый экземпляр объекта.
 * @param {string} classname - Строковое имя искомого класса (значение свойства _class_name).
 * @returns {boolean} true, если объект был создан с участием этого класса; иначе false.
 */
function IsObjectInstanceOf(obj, class_name)
{
	if(typeof class_name != 'string') class_name = class_name['_class_name']; // Подан экземляр класса а не строка с именем
	if(obj['_parents'] && (class_name in obj['_parents'])) return true;
	return false;
}

/**
 * Маркерный класс. Добавляется первым элементом в цепочку 
 * наследования для активации  RTTI, ведения истории предков и метода super_call.
 *
 * @property {Object.<string, Object>} _parents - таблица оригинальных слепков родительских классов.
 * @property {function} _constructor - пустой инициализатор по умолчанию.
 * @property {string} _class_name - идентификатор класса.
 */
var ObjectWithParentsClass =
{ 
	_parents : {},
	_constructor : function() {},
	_class_name : 'ObjectWithParentsClass',
};

var __anon_idx = 0;

/**
 * Главный конструктор ядра (Диспетчер множественного наследования). 
 * Реализует математическое объединения множеств полей и методов. Переводит объект
 * в состояние "Данные", удаляя функции-инициализаторы.
 *
 * @param {...(Object|Array)} arguments - Цепочка наследования. Каждый аргумент — это либо объект класса 
 * (например, class1), либо массив конфигурации [class_object, [constructor_args], constructor_context].
 * @returns {Object} Экземпляр класса со всеми полями, методами и реестром предков.
 */
function new_object()
{
    var ret = {};

    for(var i = 0; i< arguments.length; i++)
    {
        // 1. Нормализация [Объект, Аргументы, Контекст]
	    var pi = arguments[i];

        // 2. Клонируем структуру класса
        var obj_p = __cloneDeep(__isArray(pi) ? pi[0] : pi); // parent_obj

        // 3. Добавление в текущее состояние экземпляра
        __merge(ret, obj_p);

        // 4. Вызов конструктора текущего звена
        if (ret._constructor)
        {
            var constr_ctx = (__isArray(pi) && pi[2] !== undefined) ? pi[2] : ret;
            ret._constructor.apply(constr_ctx, (__isArray(pi) && __isArray(pi[1])) ? pi[1] : []); // constr_args
        }

        // 5. Сохранение родительской структуры, для доступа к родительским свойствам и функциям как в С++
        if (ret['_parents'])
        {
            var p_name = obj_p['_class_name'] || ('AnonymousClass_#' + (++__anon_idx));
            ret['_parents'][p_name] = obj_p;
        }

        // 6. удаление имени класса и конструктора, чтобы повторить поведение класса с++
		delete ret['_class_name'];
        delete ret['_constructor'];
    };
    
    return ret;
}

/**
 * Компонент подсистемы полиморфизма.
 * Явноый вызов методов родителей аналогично Class::method в C++.
 * 
 * Функция извлекает оригинальный алгоритм из слепка 
 * родительского класса и выполняет его на контексте текущего 
 * экземпляра объекта. Используется для обхода затирания свойств, а так же разрешения 
 * конфликтов при множественном наследовании ("проблема ромба").
 *
 * @param {Object} current_instance - контекст текущего экземпляра класса (`this`), на котором будет выполнен метод.
 * @param {string} parent_class_name - строковый идентификатор родительского класса (значение свойства `_class_name`), из которого извлекается метод.
 * @param {string} method_name - имя вызываемого родительского метода.
 * @param {Array} [args] - массив аргументов, передаваемых в вызываемый метод. Если не передан, используется пустой массив.
 * @returns {*} Результат выполнения родительского метода.
 */
function super_call(current_instance, parent_class_name, method_name, args)
{
    var m;
	try { m = current_instance['_parents'][parent_class_name][method_name]; } catch (e) {};
    return m.apply(current_instance, args || []);
}
//------------------------------------------


  var root = this;
  if (typeof exports !== "undefined") root = exports;
  root.IsObjectInstanceOf      = IsObjectInstanceOf;
  root.ObjectWithParentsClass  = ObjectWithParentsClass;
  root.new_clone               = new_clone;
  root.new_object              = new_object;
  root.super_call              = super_call;

}).call(this)

/*
######## ##     ##    ###    ##     ## ########  ##       ########  ######  
##        ##   ##    ## ##   ###   ### ##     ## ##       ##       ##    ## 
##         ## ##    ##   ##  #### #### ##     ## ##       ##       ##       
######      ###    ##     ## ## ### ## ########  ##       ######    ######  
##         ## ##   ######### ##     ## ##        ##       ##             ## 
##        ##   ##  ##     ## ##     ## ##        ##       ##       ##    ## 
######## ##     ## ##     ## ##     ## ##        ######## ########  ######  
*/

//------------------------------------------
// СПРАВКА
//------------------------------------------
/*
Как прочесть вывод туториала в консоли:
Вы увидите последовательную отработку конструкторов для каждого звена при множественном наследовании.
По умолчанию вызывается метод класса, указаный позже в аргументах new_object.
Метод super_call(экземпляр класса, "ИмяКлассаРодителя", "ИмяМетода") достаёт оригинальные функции любого родителя, решая конфликт пересечения множеств.
*/

var LOG = function() { console.log.apply(console, arguments); };
//------------------------------------------

LOG(
"//------------------------------------------\n" +
"//  ПРОВЕРКА НАСЛЕДОВАНИЯ И ПОЛИМОРФИЗМА     \n" +
"//------------------------------------------\n");

// ОПРЕДЕЛЕНИЕ КЛАССОВ (СТРУКТУР-ПРОТОТИПОВ)
var BaseGraphic = 
{
    _class_name: "BaseGraphic",
    _constructor: function() { LOG("-> Вызван BaseGraphic._constructor()"); },
    render: function() { LOG("-> Вызван BaseGraphic.render()"); }
};

var AdvancedUI = 
{
    version: 1,
    _class_name: "AdvancedUI",
    _constructor: function(ver) { this.version = ver; LOG("-> Вызван AdvancedUI BaseGraphic._constructor(" + ver + ")"); },
    render: function() { LOG("-> Вызван AdvancedUI.render()"); }
};

var myWidget = new_object(
    ObjectWithParentsClass, // Активируем _parents
    BaseGraphic, 
    [AdvancedUI, [2]]
);

LOG("--- Прямой вызов метода ---");
// Метод AdvancedUI затёр метод BaseGraphic
myWidget.render(); 

LOG("--- Разрешение конфликта через super_call ---");
// Вызываем оригинальный метод BaseGraphic из таблицы _parents
super_call(myWidget, "BaseGraphic", "render");

LOG("--- RTTI ---\nmyWidget наследован от BaseGraphic? " + IsObjectInstanceOf(myWidget, "BaseGraphic"));

LOG(
"//------------------------------------------\n" +
"//  ИТОГ                                    \n" +
"//------------------------------------------\n" +
"ООП ЭТО ОБЁРТКА В 14 СТРОК КОДА НАД ФУНКЦИЕЙ _merge"
);
