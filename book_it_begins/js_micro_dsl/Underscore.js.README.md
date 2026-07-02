---
created: 2026-06-05T22:22:10 (UTC +03:00)
tags: []
source: https://underscorejs.org/
author: 
---

# Underscore.js

> ## Excerpt
> Underscore
      is a JavaScript library that provides a whole mess of useful functional
      programming helpers without extending any built-in objects.
      It’s the answer to the question: “If I sit down in front of a
      blank HTML page, and want to start being productive immediately, what do I need?”
      … and the tie to go along with
      jQuery's tux and
      Backbone's suspenders.

---
[Underscore](https://github.com/jashkenas/underscore/) is a JavaScript library that provides a whole mess of useful functional programming helpers without extending any built-in objects. It’s the answer to the question: “If I sit down in front of a blank HTML page, and want to start being productive immediately, what do I need?” … and the tie to go along with [jQuery](https://jquery.com/)'s tux and [Backbone](https://backbonejs.org/)'s suspenders.

Underscore provides over 100 functions that support both your favorite workaday functional helpers: **map**, **filter**, **invoke** — as well as more specialized goodies: function binding, javascript templating, creating quick indexes, deep equality testing, and so on.

You may choose between monolithic and modular imports. There is a quick summary of the options below, as well as a more comprehensive discussion in [the article](https://juliangonggrijp.com/article/introducing-modular-underscore.html).

You can support the project by donating on [Patreon](https://patreon.com/juliangonggrijp). Enterprise coverage is available as part of the [Tidelift Subscription](https://tidelift.com/subscription/pkg/npm-underscore?utm_source=npm-underscore&utm_medium=referral&utm_campaign=enterprise).

_In most cases, you can replace the version number above by latest so that your embed will automatically use the latest version, or stable if you want to delay updating until an update has proven to be free of accidental breaking changes. Example:_  
https://cdn.jsdelivr.net/npm/underscore@latest/underscore-umd-min.js

_If you are hardcoding the path to the file within the package and you are unsure which build to use, it is very likely that you need underscore-umd.js or the minified variant underscore-umd-min.js._

_For functions with multiple aliases, the file name of the module is always the **first** name that appears in the documentation. For example, \_.reduce/\_.inject/\_.foldl is exported from underscore/modules/reduce.js. Modular usage is mostly recommended for creating a customized build of Underscore._

Underscore 1.x is backwards compatible with any engine that fully supports ES3, while also utilizing newer features when available, such as Object.keys, typed arrays and ES modules. We routinely run our unittests against the JavaScript engines listed below:

Underscore 2.x will likely remove support for some outdated environments.

## Collection Functions (Arrays or Objects)

`_.each(list, iteratee, [context])` Alias: **forEach** [source](https://underscorejs.org/docs/modules/each.html)  
Iterates over a **list** of elements, yielding each in turn to an **iteratee** function. The **iteratee** is bound to the **context** object, if one is passed. Each invocation of **iteratee** is called with three arguments: (element, index, list). If **list** is a JavaScript object, **iteratee**'s arguments will be (value, key, list). Returns the **list** for chaining.

```
_.each([1, 2, 3], alert);
=> alerts each number in turn...
_.each({one: 1, two: 2, three: 3}, alert);
=> alerts each number value in turn...
```

_Note: Collection functions work on arrays, objects, and array-like objects such as_ arguments, NodeList _and similar. But it works by duck-typing, so avoid passing objects with a numeric length property. It's also good to note that an each loop cannot be broken out of — to break, use **\_.find** instead._

`_.map(list, iteratee, [context])` Alias: **collect** [source](https://underscorejs.org/docs/modules/map.html)  
Produces a new array of values by mapping each value in **list** through a transformation function ([**iteratee**](https://underscorejs.org/#iteratee)). The iteratee is passed three arguments: the value, then the index (or key) of the iteration, and finally a reference to the entire list.

```
_.map([1, 2, 3], function(num){ return num * 3; });
=> [3, 6, 9]
_.map({one: 1, two: 2, three: 3}, function(num, key){ return num * 3; });
=> [3, 6, 9]
_.map([[1, 2], [3, 4]], _.first);
=> [1, 3]
```

`_.reduce(list, iteratee, [memo], [context])` Aliases: **inject**, **foldl** [source](https://underscorejs.org/docs/modules/reduce.html)  
Also known as **inject** and **foldl**, reduce boils down a **list** of values into a single value. **Memo** is the initial state of the reduction, and each successive step of it should be returned by **iteratee**. The iteratee is passed four arguments: the memo, then the value and index (or key) of the iteration, and finally a reference to the entire list.

If no memo is passed to the initial invocation of reduce, the iteratee is not invoked on the first element of the list. The first element is instead passed as the memo in the invocation of the iteratee on the next element in the list.

```
var sum = _.reduce([1, 2, 3], function(memo, num){ return memo + num; }, 0);
=> 6
```

`_.reduceRight(list, iteratee, [memo], [context])` Alias: **foldr** [source](https://underscorejs.org/docs/modules/reduceRight.html)  
The right-associative version of **reduce**. **Foldr** is not as useful in JavaScript as it would be in a language with lazy evaluation.

```
var list = [[0, 1], [2, 3], [4, 5]];
var flat = _.reduceRight(list, function(a, b) { return a.concat(b); }, []);
=> [4, 5, 2, 3, 0, 1]
```

`_.find(list, predicate, [context])` Alias: **detect** [source](https://underscorejs.org/docs/modules/find.html)  
Looks through each value in the **list**, returning the first one that passes a truth test (**predicate**), or undefined if no value passes the test. The function returns as soon as it finds an acceptable element, and doesn't traverse the entire list. **predicate** is transformed through [**iteratee**](https://underscorejs.org/#iteratee) to facilitate shorthand syntaxes.

```
var even = _.find([1, 2, 3, 4, 5, 6], function(num){ return num % 2 == 0; });
=> 2
```

`_.filter(list, predicate, [context])` Alias: **select** [source](https://underscorejs.org/docs/modules/filter.html)  
Looks through each value in the **list**, returning an array of all the values that pass a truth test (**predicate**). **predicate** is transformed through [**iteratee**](https://underscorejs.org/#iteratee) to facilitate shorthand syntaxes.

```
var evens = _.filter([1, 2, 3, 4, 5, 6], function(num){ return num % 2 == 0; });
=> [2, 4, 6]
```

`_.findWhere(list, properties)` [source](https://underscorejs.org/docs/modules/findWhere.html)  
Looks through the **list** and returns the _first_ value that [matches](https://underscorejs.org/#matches) all of the key-value pairs listed in **properties**.

If no match is found, or if **list** is empty, _undefined_ will be returned.

```
_.findWhere(publicServicePulitzers, {newsroom: "The New York Times"});
=> {year: 1918, newsroom: "The New York Times",
  reason: "For its public service in publishing in full so many official reports,
  documents and speeches by European statesmen relating to the progress and
  conduct of the war."}
```

`_.where(list, properties)` [source](https://underscorejs.org/docs/modules/where.html)  
Looks through each value in the **list**, returning an array of all the values that [matches](https://underscorejs.org/#matches) the key-value pairs listed in **properties**.

```
_.where(listOfPlays, {author: "Shakespeare", year: 1611});
=> [{title: "Cymbeline", author: "Shakespeare", year: 1611},
    {title: "The Tempest", author: "Shakespeare", year: 1611}]
```

`_.reject(list, predicate, [context])` [source](https://underscorejs.org/docs/modules/reject.html)  
Returns the values in **list** without the elements that the truth test (**predicate**) passes. The opposite of **filter**. **predicate** is transformed through [**iteratee**](https://underscorejs.org/#iteratee) to facilitate shorthand syntaxes.

```
var odds = _.reject([1, 2, 3, 4, 5, 6], function(num){ return num % 2 == 0; });
=> [1, 3, 5]
```

`_.every(list, [predicate], [context])` Alias: **all** [source](https://underscorejs.org/docs/modules/every.html)  
Returns _true_ if all of the values in the **list** pass the **predicate** truth test. Short-circuits and stops traversing the list if a false element is found. **predicate** is transformed through [**iteratee**](https://underscorejs.org/#iteratee) to facilitate shorthand syntaxes.

```
_.every([2, 4, 5], function(num) { return num % 2 == 0; });
=> false
```

`_.some(list, [predicate], [context])` Alias: **any** [source](https://underscorejs.org/docs/modules/some.html)  
Returns _true_ if any of the values in the **list** pass the **predicate** truth test. Short-circuits and stops traversing the list if a true element is found. **predicate** is transformed through [**iteratee**](https://underscorejs.org/#iteratee) to facilitate shorthand syntaxes.

```
_.some([null, 0, 'yes', false]);
=> true
```

`_.contains(list, value, [fromIndex])` Aliases: **include**, **includes** [source](https://underscorejs.org/docs/modules/contains.html)  
Returns _true_ if the **value** is present in the **list**. Uses **indexOf** internally, if **list** is an Array. Use **fromIndex** to start your search at a given index.

```
_.contains([1, 2, 3], 3);
=> true
```

`_.invoke(list, methodName, *arguments)` [source](https://underscorejs.org/docs/modules/invoke.html)  
Calls the method named by **methodName** on each value in the **list**. Any extra arguments passed to **invoke** will be forwarded on to the method invocation.

```
_.invoke([[5, 1, 7], [3, 2, 1]], 'sort');
=> [[1, 5, 7], [1, 2, 3]]
```

`_.pluck(list, propertyName)` [source](https://underscorejs.org/docs/modules/pluck.html)  
A convenient version of what is perhaps the most common use-case for **map**: extracting a list of property values.

```
var stooges = [{name: 'moe', age: 40}, {name: 'larry', age: 50}, {name: 'curly', age: 60}];
_.pluck(stooges, 'name');
=> ["moe", "larry", "curly"]
```

`_.max(list, [iteratee], [context])` [source](https://underscorejs.org/docs/modules/max.html)  
Returns the maximum value in **list**. If an [**iteratee**](https://underscorejs.org/#iteratee) function is provided, it will be used on each value to generate the criterion by which the value is ranked. _\-Infinity_ is returned if **list** is empty, so an [isEmpty](https://underscorejs.org/#isEmpty) guard may be required. This function can currently only compare numbers reliably. This function uses operator < ([note](https://underscorejs.org/#relational-operator-note)).

```
var stooges = [{name: 'moe', age: 40}, {name: 'larry', age: 50}, {name: 'curly', age: 60}];
_.max(stooges, function(stooge){ return stooge.age; });
=> {name: 'curly', age: 60};
```

`_.min(list, [iteratee], [context])` [source](https://underscorejs.org/docs/modules/min.html)  
Returns the minimum value in **list**. If an [**iteratee**](https://underscorejs.org/#iteratee) function is provided, it will be used on each value to generate the criterion by which the value is ranked. _Infinity_ is returned if **list** is empty, so an [isEmpty](https://underscorejs.org/#isEmpty) guard may be required. This function can currently only compare numbers reliably. This function uses operator < ([note](https://underscorejs.org/#relational-operator-note)).

```
var numbers = [10, 5, 100, 2, 1000];
_.min(numbers);
=> 2
```

`_.sortBy(list, iteratee, [context])` [source](https://underscorejs.org/docs/modules/sortBy.html)  
Returns a (stably) sorted copy of **list**, ranked in ascending order by the results of running each value through [**iteratee**](https://underscorejs.org/#iteratee). iteratee may also be the string name of the property to sort by (eg. length). This function uses operator < ([note](https://underscorejs.org/#relational-operator-note)).

```
_.sortBy([1, 2, 3, 4, 5, 6], function(num){ return Math.sin(num); });
=> [5, 4, 6, 3, 1, 2]

var stooges = [{name: 'moe', age: 40}, {name: 'larry', age: 50}, {name: 'curly', age: 60}];
_.sortBy(stooges, 'name');
=> [{name: 'curly', age: 60}, {name: 'larry', age: 50}, {name: 'moe', age: 40}];
```

`_.groupBy(list, iteratee, [context])` [source](https://underscorejs.org/docs/modules/groupBy.html)  
Splits a collection into sets, grouped by the result of running each value through **iteratee**. If **iteratee** is a string instead of a function, groups by the property named by **iteratee** on each of the values.

```
_.groupBy([1.3, 2.1, 2.4], function(num){ return Math.floor(num); });
=> {1: [1.3], 2: [2.1, 2.4]}

_.groupBy(['one', 'two', 'three'], 'length');
=> {3: ["one", "two"], 5: ["three"]}
```

`_.indexBy(list, iteratee, [context])` [source](https://underscorejs.org/docs/modules/indexBy.html)  
Given a **list**, and an [**iteratee**](https://underscorejs.org/#iteratee) function that returns a key for each element in the list (or a property name), returns an object with an index of each item. Just like [groupBy](https://underscorejs.org/#groupBy), but for when you know your keys are unique.

```
var stooges = [{name: 'moe', age: 40}, {name: 'larry', age: 50}, {name: 'curly', age: 60}];
_.indexBy(stooges, 'age');
=> {
  "40": {name: 'moe', age: 40},
  "50": {name: 'larry', age: 50},
  "60": {name: 'curly', age: 60}
}
```

`_.countBy(list, iteratee, [context])` [source](https://underscorejs.org/docs/modules/countBy.html)  
Sorts a list into groups and returns a count for the number of objects in each group. Similar to groupBy, but instead of returning a list of values, returns a count for the number of values in that group.

```
_.countBy([1, 2, 3, 4, 5], function(num) {
  return num % 2 == 0 ? 'even': 'odd';
});
=> {odd: 3, even: 2}
```

`_.shuffle(list)` [source](https://underscorejs.org/docs/modules/shuffle.html)  
Returns a shuffled copy of the **list**, using a version of the [Fisher-Yates shuffle](https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle).

```
_.shuffle([1, 2, 3, 4, 5, 6]);
=> [4, 1, 6, 3, 5, 2]
```

`_.sample(list, [n])` [source](https://underscorejs.org/docs/modules/sample.html)  
Produce a random sample from the **list**. Pass a number to return **n** random elements from the list. Otherwise a single random item will be returned.

```
_.sample([1, 2, 3, 4, 5, 6]);
=> 4

_.sample([1, 2, 3, 4, 5, 6], 3);
=> [1, 6, 2]
```

`_.toArray(list)` [source](https://underscorejs.org/docs/modules/toArray.html)  
Creates a real Array from the **list** (anything that can be iterated over). Useful for transmuting the **arguments** object.

```
(function(){ return _.toArray(arguments).slice(1); })(1, 2, 3, 4);
=> [2, 3, 4]
```

`_.size(list)` [source](https://underscorejs.org/docs/modules/size.html)  
Return the number of values in the **list**.

```
_.size([1, 2, 3, 4, 5]);
=> 5

_.size({one: 1, two: 2, three: 3});
=> 3
```

`_.partition(list, predicate)` [source](https://underscorejs.org/docs/modules/partition.html)  
Split **list** into two arrays: one whose elements all satisfy **predicate** and one whose elements all do not satisfy **predicate**. **predicate** is transformed through [**iteratee**](https://underscorejs.org/#iteratee) to facilitate shorthand syntaxes.

```
_.partition([0, 1, 2, 3, 4, 5], isOdd);
=> [[1, 3, 5], [0, 2, 4]]
```

`_.compact(list)` [source](https://underscorejs.org/docs/modules/compact.html)  
Returns a copy of the **list** with all falsy values removed. In JavaScript, _false_, _null_, _0_, _""_, _undefined_ and _NaN_ are all falsy.

```
_.compact([0, 1, false, 2, '', 3]);
=> [1, 2, 3]
```

## Array Functions

_Note: All array functions will also work on the **arguments** object. However, Underscore functions are not designed to work on "sparse" arrays._

`_.first(array, [n])` Aliases: **head**, **take** [source](https://underscorejs.org/docs/modules/first.html)  
Returns the first element of an **array**. Passing **n** will return the first **n** elements of the array.

```
_.first([5, 4, 3, 2, 1]);
=> 5
```

`_.initial(array, [n])` [source](https://underscorejs.org/docs/modules/initial.html)  
Returns everything but the last entry of the array. Especially useful on the arguments object. Pass **n** to exclude the last **n** elements from the result.

```
_.initial([5, 4, 3, 2, 1]);
=> [5, 4, 3, 2]
```

`_.last(array, [n])` [source](https://underscorejs.org/docs/modules/last.html)  
Returns the last element of an **array**. Passing **n** will return the last **n** elements of the array.

```
_.last([5, 4, 3, 2, 1]);
=> 1
```

`_.rest(array, [index])` Aliases: **tail**, **drop** [source](https://underscorejs.org/docs/modules/rest.html)  
Returns the **rest** of the elements in an array. Pass an **index** to return the values of the array from that index onward.

```
_.rest([5, 4, 3, 2, 1]);
=> [4, 3, 2, 1]
```

`_.flatten(array, [depth])` [source](https://underscorejs.org/docs/modules/flatten.html)  
Flattens a nested **array**. If you pass true or 1 as the **depth**, the array will only be flattened a single level. Passing a greater number will cause the flattening to descend deeper into the nesting hierarchy. Omitting the **depth** argument, or passing false or Infinity, flattens the array all the way to the deepest nesting level.

```
_.flatten([1, [2], [3, [[4]]]]);
=> [1, 2, 3, 4];

_.flatten([1, [2], [3, [[4]]]], true);
=> [1, 2, 3, [[4]]];

_.flatten([1, [2], [3, [[4]]]], 2);
=> [1, 2, 3, [4]];
```

`_.without(array, *values)` [source](https://underscorejs.org/docs/modules/without.html)  
Returns a copy of the **array** with all instances of the **values** removed.

```
_.without([1, 2, 1, 0, 3, 1, 4], 0, 1);
=> [2, 3, 4]
```

`_.union(*arrays)` [source](https://underscorejs.org/docs/modules/union.html)  
Computes the union of the passed-in **arrays**: the list of unique items, in order, that are present in one or more of the **arrays**.

```
_.union([1, 2, 3], [101, 2, 1, 10], [2, 1]);
=> [1, 2, 3, 101, 10]
```

`_.intersection(*arrays)` [source](https://underscorejs.org/docs/modules/intersection.html)  
Computes the list of values that are the intersection of all the **arrays**. Each value in the result is present in each of the **arrays**.

```
_.intersection([1, 2, 3], [101, 2, 1, 10], [2, 1]);
=> [1, 2]
```

`_.difference(array, *others)` [source](https://underscorejs.org/docs/modules/difference.html)  
Similar to **without**, but returns the values from **array** that are not present in the **other** arrays.

```
_.difference([1, 2, 3, 4, 5], [5, 2, 10]);
=> [1, 3, 4]
```

`_.uniq(array, [isSorted], [iteratee])` Alias: **unique** [source](https://underscorejs.org/docs/modules/uniq.html)  
Produces a duplicate-free version of the **array**, using _\===_ to test object equality. In particular only the first occurrence of each value is kept. If you know in advance that the **array** is sorted, passing _true_ for **isSorted** will run a much faster algorithm. If you want to compute unique items based on a transformation, pass an [**iteratee**](https://underscorejs.org/#iteratee) function.

```
_.uniq([1, 2, 1, 4, 1, 3]);
=> [1, 2, 4, 3]
```

`_.zip(*arrays)` [source](https://underscorejs.org/docs/modules/zip.html)  
Merges together the values of each of the **arrays** with the values at the corresponding position. Useful when you have separate data sources that are coordinated through matching array indexes.

```
_.zip(['moe', 'larry', 'curly'], [30, 40, 50], [true, false, false]);
=> [["moe", 30, true], ["larry", 40, false], ["curly", 50, false]]

```

`_.unzip(array)` Alias: **transpose** [source](https://underscorejs.org/docs/modules/unzip.html)  
The opposite of [zip](https://underscorejs.org/#zip). Given an **array** of arrays, returns a series of new arrays, the first of which contains all of the first elements in the input arrays, the second of which contains all of the second elements, and so on. If you're working with a matrix of nested arrays, this can be used to transpose the matrix.

```
_.unzip([["moe", 30, true], ["larry", 40, false], ["curly", 50, false]]);
=> [['moe', 'larry', 'curly'], [30, 40, 50], [true, false, false]]
```

`_.object(list, [values])` [source](https://underscorejs.org/docs/modules/object.html)  
Converts arrays into objects. Pass either a single list of \[key, value\] pairs, or a list of keys, and a list of values. Passing by pairs is the reverse of [pairs](https://underscorejs.org/#pairs). If duplicate keys exist, the last value wins.

```
_.object(['moe', 'larry', 'curly'], [30, 40, 50]);
=> {moe: 30, larry: 40, curly: 50}

_.object([['moe', 30], ['larry', 40], ['curly', 50]]);
=> {moe: 30, larry: 40, curly: 50}
```

`_.chunk(array, length)` [source](https://underscorejs.org/docs/modules/chunk.html)  
Chunks an **array** into multiple arrays, each containing **length** or fewer items.

```
var partners = _.chunk(_.shuffle(kindergarten), 2);
=> [["Tyrone", "Elie"], ["Aidan", "Sam"], ["Katrina", "Billie"], ["Little Timmy"]]
```

`_.indexOf(array, value, [isSorted])` [source](https://underscorejs.org/docs/modules/indexOf.html)  
Returns the index at which **value** can be found in the **array**, or _\-1_ if value is not present in the **array**. If you're working with a large array, and you know that the array is already sorted, pass true for **isSorted** to use a faster binary search ... or, pass a number as the third argument in order to look for the first matching value in the array after the given index. If isSorted is true, this function uses operator < ([note](https://underscorejs.org/#relational-operator-note)).

```
_.indexOf([1, 2, 3], 2);
=> 1
```

`_.lastIndexOf(array, value, [fromIndex])` [source](https://underscorejs.org/docs/modules/lastIndexOf.html)  
Returns the index of the last occurrence of **value** in the **array**, or _\-1_ if value is not present. Pass **fromIndex** to start your search at a given index.

```
_.lastIndexOf([1, 2, 3, 1, 2, 3], 2);
=> 4
```

`_.sortedIndex(array, value, [iteratee], [context])` [source](https://underscorejs.org/docs/modules/sortedIndex.html)  
Uses a binary search to determine the smallest index at which the **value** _should_ be inserted into the **array** in order to maintain the **array**'s sorted order. If an [**iteratee**](https://underscorejs.org/#iteratee) function is provided, it will be used to compute the sort ranking of each value, including the **value** you pass. The iteratee may also be the string name of the property to sort by (eg. length). This function uses operator < ([note](https://underscorejs.org/#relational-operator-note)).

```
_.sortedIndex([10, 20, 30, 40, 50], 35);
=> 3

var stooges = [{name: 'moe', age: 40}, {name: 'curly', age: 60}];
_.sortedIndex(stooges, {name: 'larry', age: 50}, 'age');
=> 1
```

`_.findIndex(array, predicate, [context])` [source](https://underscorejs.org/docs/modules/findIndex.html)  
Similar to [\_.indexOf](https://underscorejs.org/#indexOf), returns the first index where the **predicate** truth test passes; otherwise returns _\-1_.

```
_.findIndex([4, 6, 8, 12], isPrime);
=> -1 // not found
_.findIndex([4, 6, 7, 12], isPrime);
=> 2
```

`_.findLastIndex(array, predicate, [context])` [source](https://underscorejs.org/docs/modules/findLastIndex.html)  
Like [\_.findIndex](https://underscorejs.org/#findIndex) but iterates the array in reverse, returning the index closest to the end where the **predicate** truth test passes.

```
var users = [{'id': 1, 'name': 'Bob', 'last': 'Brown'},
             {'id': 2, 'name': 'Ted', 'last': 'White'},
             {'id': 3, 'name': 'Frank', 'last': 'James'},
             {'id': 4, 'name': 'Ted', 'last': 'Jones'}];
_.findLastIndex(users, {
  name: 'Ted'
});
=> 3
```

`_.range([start], stop, [step])` [source](https://underscorejs.org/docs/modules/range.html)  
A function to create flexibly-numbered lists of integers, handy for each and map loops. **start**, if omitted, defaults to _0_; **step** defaults to _1_ if **start** is before **stop**, otherwise _\-1_. Returns a list of integers from **start** (inclusive) to **stop** (exclusive), incremented (or decremented) by **step**.

```
_.range(10);
=> [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
_.range(1, 11);
=> [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
_.range(0, 30, 5);
=> [0, 5, 10, 15, 20, 25]
_.range(0, -10, -1);
=> [0, -1, -2, -3, -4, -5, -6, -7, -8, -9]
_.range(0);
=> []
```

## Function (uh, ahem) Functions

`_.bind(function, object, *arguments)` [source](https://underscorejs.org/docs/modules/bind.html)  
Bind a **function** to an **object**, meaning that whenever the function is called, the value of _this_ will be the **object**. Optionally, pass **arguments** to the **function** to pre-fill them, also known as **partial application**. For partial application without context binding, use [partial](https://underscorejs.org/#partial).

```
var func = function(greeting){ return greeting + ': ' + this.name };
func = _.bind(func, {name: 'moe'}, 'hi');
func();
=> 'hi: moe'
```

`_.bindAll(object, *methodNames)` [source](https://underscorejs.org/docs/modules/bindAll.html)  
Binds a number of methods on the **object**, specified by **methodNames**, to be run in the context of that object whenever they are invoked. Very handy for binding functions that are going to be used as event handlers, which would otherwise be invoked with a fairly useless _this_. **methodNames** are required.

```
var buttonView = {
  label  : 'underscore',
  onClick: function(){ alert('clicked: ' + this.label); },
  onHover: function(){ console.log('hovering: ' + this.label); }
};
_.bindAll(buttonView, 'onClick', 'onHover');
// When the button is clicked, this.label will have the correct value.
jQuery('#underscore_button').on('click', buttonView.onClick);
```

`_.partial(function, *arguments)` [source](https://underscorejs.org/docs/modules/partial.html)  
Partially apply a function by filling in any number of its **arguments**, _without_ changing its dynamic this value. A close cousin of [bind](https://underscorejs.org/#bind). You may pass \_ in your list of **arguments** to specify an argument that should not be pre-filled, but left open to supply at call-time. _Note: if you need \_ placeholders and a this binding at the same time, use both \_.partial and \_.bind_.

```
var subtract = function(a, b) { return b - a; };
sub5 = _.partial(subtract, 5);
sub5(20);
=> 15

// Using a placeholder
subFrom20 = _.partial(subtract, _, 20);
subFrom20(5);
=> 15
```

`_.memoize(function, [hashFunction])` [source](https://underscorejs.org/docs/modules/memoize.html)  
Memoizes a given **function** by caching the computed result. Useful for speeding up slow-running computations. If passed an optional **hashFunction**, it will be used to compute the hash key for storing the result, based on the arguments to the original function. The default **hashFunction** just uses the first argument to the memoized function as the key. The cache of memoized values is available as the cache property on the returned function.

```
var fibonacci = _.memoize(function(n) {
  return n < 2 ? n: fibonacci(n - 1) + fibonacci(n - 2);
});
```

`_.delay(function, wait, *arguments)` [source](https://underscorejs.org/docs/modules/delay.html)  
Much like **setTimeout**, invokes **function** after **wait** milliseconds. If you pass the optional **arguments**, they will be forwarded on to the **function** when it is invoked.

```
var log = _.bind(console.log, console);
_.delay(log, 1000, 'logged later');
=> 'logged later' // Appears after one second.
```

`_.defer(function, *arguments)` [source](https://underscorejs.org/docs/modules/defer.html)  
Defers invoking the **function** until the current call stack has cleared, similar to using **setTimeout** with a delay of 0. Useful for performing expensive computations or HTML rendering in chunks without blocking the UI thread from updating. If you pass the optional **arguments**, they will be forwarded on to the **function** when it is invoked.

```
_.defer(function(){ alert('deferred'); });
// Returns from the function before the alert runs.
```

`_.throttle(function, wait, [options])` [source](https://underscorejs.org/docs/modules/throttle.html)  
Creates and returns a new, throttled version of the passed function, that, when invoked repeatedly, will only actually call the original function at most once per every **wait** milliseconds. Useful for rate-limiting events that occur faster than you can keep up with.

By default, **throttle** will execute the function as soon as you call it for the first time, and, if you call it again any number of times during the **wait** period, as soon as that period is over. If you'd like to disable the leading-edge call, pass {leading: false}, and if you'd like to disable the execution on the trailing-edge, pass  
{trailing: false}.

```
var throttled = _.throttle(updatePosition, 100);
$(window).scroll(throttled);
```

If you need to cancel a scheduled throttle, you can call .cancel() on the throttled function.

`_.debounce(function, wait, [immediate])` [source](https://underscorejs.org/docs/modules/debounce.html)  
Creates and returns a new debounced version of the passed function which will postpone its execution until after **wait** milliseconds have elapsed since the last time it was invoked. Useful for implementing behavior that should only happen _after_ the input has stopped arriving. For example: rendering a preview of a Markdown comment, recalculating a layout after the window has stopped being resized, and so on.

At the end of the **wait** interval, the function will be called with the arguments that were passed _most recently_ to the debounced function.

Pass true for the **immediate** argument to cause **debounce** to trigger the function on the leading instead of the trailing edge of the **wait** interval. Useful in circumstances like preventing accidental double-clicks on a "submit" button from firing a second time.

```
var lazyLayout = _.debounce(calculateLayout, 300);
$(window).resize(lazyLayout);
```

If you need to cancel a scheduled debounce, you can call .cancel() on the debounced function.

`_.once(function)` [source](https://underscorejs.org/docs/modules/once.html)  
Creates a version of the function that can only be called one time. Repeated calls to the modified function will have no effect, returning the value from the original call. Useful for initialization functions, instead of having to set a boolean flag and then check it later.

```
var initialize = _.once(createApplication);
initialize();
initialize();
// Application is only created once.
```

`_.after(count, function)` [source](https://underscorejs.org/docs/modules/after.html)  
Creates a wrapper of **function** that does nothing at first. From the **count**\-th call onwards, it starts actually calling **function**. Useful for grouping asynchronous responses, where you want to be sure that all the async calls have finished, before proceeding.

```
var renderNotes = _.after(notes.length, render);
_.each(notes, function(note) {
  note.asyncSave({success: renderNotes});
});
// renderNotes is run once, after all notes have saved.
```

`_.before(count, function)` [source](https://underscorejs.org/docs/modules/before.html)  
Creates a wrapper of **function** that memoizes its return value. From the **count**\-th call onwards, the memoized result of the last invocation is returned immediately instead of invoking **function** again. So the wrapper will invoke **function** at most **count** - 1 times.

```
var monthlyMeeting = _.before(3, askForRaise);
monthlyMeeting();
monthlyMeeting();
monthlyMeeting();
// the result of any subsequent calls is the same as the second call
```

`_.wrap(function, wrapper)` [source](https://underscorejs.org/docs/modules/wrap.html)  
Wraps the first **function** inside of the **wrapper** function, passing it as the first argument. This allows the **wrapper** to execute code before and after the **function** runs, adjust the arguments, and execute it conditionally.

```
var hello = function(name) { return "hello: " + name; };
hello = _.wrap(hello, function(func) {
  return "before, " + func("moe") + ", after";
});
hello();
=> 'before, hello: moe, after'
```

`_.negate(predicate)` [source](https://underscorejs.org/docs/modules/negate.html)  
Returns a new negated version of the [**predicate**](https://underscorejs.org/#iteratee) function.

```
var isFalsy = _.negate(Boolean);
_.find([-2, -1, 0, 1, 2], isFalsy);
=> 0
```

`_.compose(*functions)` [source](https://underscorejs.org/docs/modules/compose.html)  
Returns the composition of a list of **functions**, where each function consumes the return value of the function that follows. In math terms, composing the functions _f()_, _g()_, and _h()_ produces _f(g(h()))_.

```
var greet    = function(name){ return "hi: " + name; };
var exclaim  = function(statement){ return statement.toUpperCase() + "!"; };
var welcome = _.compose(greet, exclaim);
welcome('moe');
=> 'hi: MOE!'
```

`_.restArguments(function, [startIndex])` [source](https://underscorejs.org/docs/modules/restArguments.html)  
Returns a version of the **function** that, when called, receives all arguments from and beyond **startIndex** collected into a single array. If you don’t pass an explicit **startIndex**, it will be determined by looking at the number of arguments to the **function** itself. Similar to ES6’s [rest parameters syntax](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Functions/rest_parameters).

```
var raceResults = _.restArguments(function(gold, silver, bronze, everyoneElse) {
  _.each(everyoneElse, sendConsolations);
});

raceResults("Dopey", "Grumpy", "Happy", "Sneezy", "Bashful", "Sleepy", "Doc");
// Sorry Sneezy, better next time!
// Sorry Bashful, better next time!
// Sorry Sleepy, better next time!
// Sorry Doc, better next time!
```

The **startIndex** is mainly useful if the number of arguments cannot be reliably determined from the **function** itself, for example because **function** was output by another function.

```
// The inner function from before.
function consoleNonWinners(gold, silver, bronze, everyoneElse) {
  _.each(everyoneElse, sendConsolations);
}

// This time, we transform it through another metafunction first.
// Snow White always wins gold!
var withSnowWhite = _.partial(consoleNonWinners, "Snow White");

// withSnowWhite.length is zero because _.partial does not remember the
// number of parameters for us. We fix this by passing an explicit
// startIndex.
var raceResults = _.restArguments(withSnowWhite, 2);

// Dopey degraded to silver, Grumpy degraded to bronze and Happy fell
// out of the prizes altogether. We will console him as well.
raceResults("Dopey", "Grumpy", "Happy", "Sneezy", "Bashful", "Sleepy", "Doc");
// Sorry Happy, better next time!
// Sorry Sneezy, better next time!
// Sorry Bashful, better next time!
// Sorry Sleepy, better next time!
// Sorry Doc, better next time!
```

## Object Functions

`_.keys(object)` [source](https://underscorejs.org/docs/modules/keys.html)  
Retrieve all the names of the **object**'s own enumerable properties.

```
_.keys({one: 1, two: 2, three: 3});
=> ["one", "two", "three"]
```

`_.allKeys(object)` [source](https://underscorejs.org/docs/modules/allKeys.html)  
Retrieve _all_ the names of **object**'s own and inherited properties.

```
function Stooge(name) {
  this.name = name;
}
Stooge.prototype.silly = true;
_.allKeys(new Stooge("Moe"));
=> ["name", "silly"]
```

`_.values(object)` [source](https://underscorejs.org/docs/modules/values.html)  
Return all of the values of the **object**'s own properties.

```
_.values({one: 1, two: 2, three: 3});
=> [1, 2, 3]
```

`_.mapObject(object, iteratee, [context])` [source](https://underscorejs.org/docs/modules/mapObject.html)  
Like [map](https://underscorejs.org/#map), but for objects. Transform the value of each property in turn.

```
_.mapObject({start: 5, end: 12}, function(val, key) {
  return val + 5;
});
=> {start: 10, end: 17}
```

`_.pairs(object)` [source](https://underscorejs.org/docs/modules/pairs.html)  
Convert an object into a list of \[key, value\] pairs. The opposite of [object](https://underscorejs.org/#object).

```
_.pairs({one: 1, two: 2, three: 3});
=> [["one", 1], ["two", 2], ["three", 3]]
```

`_.invert(object)` [source](https://underscorejs.org/docs/modules/invert.html)  
Returns a copy of the **object** where the keys have become the values and the values the keys. For this to work, all of your object's values should be unique and string serializable.

```
_.invert({Moe: "Moses", Larry: "Louis", Curly: "Jerome"});
=> {Moses: "Moe", Louis: "Larry", Jerome: "Curly"};
```

`_.create(prototype, props)` [source](https://underscorejs.org/docs/modules/create.html)  
Creates a new object with the given prototype, optionally attaching **props** as _own_ properties. Basically, Object.create, but without all of the property descriptor jazz.

```
var moe = _.create(Stooge.prototype, {name: "Moe"});
```

`_.functions(object)` Alias: **methods** [source](https://underscorejs.org/docs/modules/functions.html)  
Returns a sorted list of the names of every method in an object — that is to say, the name of every function property of the object.

```
_.functions(_);
=> ["all", "any", "bind", "bindAll", "clone", "compact", "compose" ...
```

`_.findKey(object, predicate, [context])` [source](https://underscorejs.org/docs/modules/findKey.html)  
Similar to [\_.findIndex](https://underscorejs.org/#findIndex) but for keys in objects. Returns the _key_ where the **predicate** truth test passes or _undefined_. **predicate** is transformed through [**iteratee**](https://underscorejs.org/#iteratee) to facilitate shorthand syntaxes.

`_.extend(destination, *sources)` [source](https://underscorejs.org/docs/modules/extend.html)  
Shallowly copy all of the properties **in** the **source** objects over to the **destination** object, and return the **destination** object. Any nested objects or arrays will be copied by reference, not duplicated. It's in-order, so the last source will override properties of the same name in previous arguments.

```
_.extend({name: 'moe'}, {age: 50});
=> {name: 'moe', age: 50}
```

`_.extendOwn(destination, *sources)` Alias: **assign** [source](https://underscorejs.org/docs/modules/extendOwn.html)  
Like **extend**, but only copies _own_ properties over to the destination object.

`_.pick(object, *keys)` [source](https://underscorejs.org/docs/modules/pick.html)  
Return a copy of the **object**, filtered to only have values for the allowed **keys** (or array of valid keys). Alternatively accepts a predicate indicating which keys to pick.

```
_.pick({name: 'moe', age: 50, userid: 'moe1'}, 'name', 'age');
=> {name: 'moe', age: 50}
_.pick({name: 'moe', age: 50, userid: 'moe1'}, function(value, key, object) {
  return _.isNumber(value);
});
=> {age: 50}
```

`_.omit(object, *keys)` [source](https://underscorejs.org/docs/modules/omit.html)  
Return a copy of the **object**, filtered to omit the disallowed **keys** (or array of keys). Alternatively accepts a predicate indicating which keys to omit.

```
_.omit({name: 'moe', age: 50, userid: 'moe1'}, 'userid');
=> {name: 'moe', age: 50}
_.omit({name: 'moe', age: 50, userid: 'moe1'}, function(value, key, object) {
  return _.isNumber(value);
});
=> {name: 'moe', userid: 'moe1'}
```

`_.defaults(object, *defaults)` [source](https://underscorejs.org/docs/modules/defaults.html)  
Returns **object** after filling in its undefined properties with the first value present in the following list of **defaults** objects.

```
var iceCream = {flavor: "chocolate"};
_.defaults(iceCream, {flavor: "vanilla", sprinkles: "lots"});
=> {flavor: "chocolate", sprinkles: "lots"}
```

`_.clone(object)` [source](https://underscorejs.org/docs/modules/clone.html)  
Create a shallow-copied clone of the provided _plain_ **object**. Any nested objects or arrays will be copied by reference, not duplicated.

```
_.clone({name: 'moe'});
=> {name: 'moe'};
```

`_.tap(object, interceptor)` [source](https://underscorejs.org/docs/modules/tap.html)  
Invokes **interceptor** with the **object**, and then returns **object**. The primary purpose of this method is to "tap into" a method chain, in order to perform operations on intermediate results within the chain.

```
_.chain([1,2,3,200])
  .filter(function(num) { return num % 2 == 0; })
  .tap(alert)
  .map(function(num) { return num * num })
  .value();
=> // [2, 200] (alerted)
=> [4, 40000]
```

`_.toPath(path)` [source](https://underscorejs.org/docs/modules/toPath.html)  
Ensures that **path** is an array. If **path** is a string, it is wrapped in a single-element array; if it is an array already, it is returned unmodified.

```
_.toPath('key');
=> ['key']
_.toPath(['a', 0, 'b']);
=> ['a', 0, 'b'] // (same array)
```

\_.toPath is used internally in has, get, invoke, property, propertyOf and result, as well as in [**iteratee**](https://underscorejs.org/#iteratee) and all functions that depend on it, in order to normalize deep property paths. You can override \_.toPath if you want to customize this behavior, for example to enable Lodash-like string path shorthands. Be advised that altering \_.toPath will unavoidably cause some keys to become unreachable; override at your own risk.

```
// Support dotted path shorthands.
var originalToPath = _.toPath;
_.mixin({
  toPath: function(path) {
    return _.isString(path) ? path.split('.') : originalToPath(path);
  }
});
_.get({a: [{b: 5}]}, 'a.0.b');
=> 5
```

`_.get(object, path, [default])` [source](https://underscorejs.org/docs/modules/get.html)  
Returns the specified property of **object**. **path** may be specified as a simple key, or as an array of object keys or array indexes, for deep property fetching. If the property does not exist or is undefined, the optional **default** is returned.

```
_.get({a: 10}, 'a');
=> 10
_.get({a: [{b: 2}]}, ['a', 0, 'b']);
=> 2
_.get({a: 10}, 'b', 100);
=> 100
```

`_.has(object, key)` [source](https://underscorejs.org/docs/modules/has.html)  
Does the object contain the given key? Identical to object.hasOwnProperty(key), but uses a safe reference to the hasOwnProperty function, in case it's been [overridden accidentally](https://www.pixelstech.net/article/1326986170-An-Object-is-not-a-Hash).

```
_.has({a: 1, b: 2, c: 3}, "b");
=> true
```

`_.property(path)` [source](https://underscorejs.org/docs/modules/property.html)  
Returns a function that will return the specified property of any passed-in object. path may be specified as a simple key, or as an array of object keys or array indexes, for deep property fetching.

```
var stooge = {name: 'moe'};
'moe' === _.property('name')(stooge);
=> true

var stooges = {moe: {fears: {worst: 'Spiders'}}, curly: {fears: {worst: 'Moe'}}};
var curlysWorstFear = _.property(['curly', 'fears', 'worst']);
curlysWorstFear(stooges);
=> 'Moe'
```

`_.propertyOf(object)` [source](https://underscorejs.org/docs/modules/propertyOf.html)  
Inverse of \_.property. Takes an object and returns a function which will return the value of a provided property.

```
var stooge = {name: 'moe'};
_.propertyOf(stooge)('name');
=> 'moe'
```

`_.matcher(attrs)` Alias: **matches** [source](https://underscorejs.org/docs/modules/matcher.html)  
Returns a predicate function that will tell you if a passed in object contains all of the key/value properties present in **attrs**.

```
var ready = _.matcher({selected: true, visible: true});
var readyToGoList = _.filter(list, ready);
```

`_.isEqual(object, other)` [source](https://underscorejs.org/docs/modules/isEqual.html)  
Performs an optimized deep comparison between the two objects, to determine if they should be considered equal.

```
var stooge = {name: 'moe', luckyNumbers: [13, 27, 34]};
var clone  = {name: 'moe', luckyNumbers: [13, 27, 34]};
stooge == clone;
=> false
_.isEqual(stooge, clone);
=> true
```

`_.isMatch(object, properties)` [source](https://underscorejs.org/docs/modules/isMatch.html)  
Tells you if the keys and values in **properties** are contained in **object**.

```
var stooge = {name: 'moe', age: 32};
_.isMatch(stooge, {age: 32});
=> true
```

`_.isEmpty(collection)` [source](https://underscorejs.org/docs/modules/isEmpty.html)  
Returns _true_ if **collection** has no elements. For strings and array-like objects \_.isEmpty checks if the length property is 0. For other objects, it returns _true_ if the object has no enumerable own-properties. Note that primitive numbers, booleans and symbols are always empty by this definition.

```
_.isEmpty([1, 2, 3]);
=> false
_.isEmpty({});
=> true
```

`_.isElement(object)` [source](https://underscorejs.org/docs/modules/isElement.html)  
Returns _true_ if **object** is a DOM element.

```
_.isElement(jQuery('body')[0]);
=> true
```

`_.isArray(object)` [source](https://underscorejs.org/docs/modules/isArray.html)  
Returns _true_ if **object** is an Array.

```
(function(){ return _.isArray(arguments); })();
=> false
_.isArray([1,2,3]);
=> true
```

`_.isObject(value)` [source](https://underscorejs.org/docs/modules/isObject.html)  
Returns _true_ if **value** is an Object. Note that JavaScript arrays and functions are objects, while (normal) strings and numbers are not.

```
_.isObject({});
=> true
_.isObject(1);
=> false
```

`_.isArguments(object)` [source](https://underscorejs.org/docs/modules/isArguments.html)  
Returns _true_ if **object** is an Arguments object.

```
(function(){ return _.isArguments(arguments); })(1, 2, 3);
=> true
_.isArguments([1,2,3]);
=> false
```

`_.isFunction(object)` [source](https://underscorejs.org/docs/modules/isFunction.html)  
Returns _true_ if **object** is a Function.

```
_.isFunction(alert);
=> true
```

`_.isString(object)` [source](https://underscorejs.org/docs/modules/isString.html)  
Returns _true_ if **object** is a String.

```
_.isString("moe");
=> true
```

`_.isNumber(object)` [source](https://underscorejs.org/docs/modules/isNumber.html)  
Returns _true_ if **object** is a Number (including NaN).

```
_.isNumber(8.4 * 5);
=> true
```

`_.isFinite(object)` [source](https://underscorejs.org/docs/modules/isFinite.html)  
Returns _true_ if **object** is a finite Number.

```
_.isFinite(-101);
=> true

_.isFinite(-Infinity);
=> false
```

`_.isBoolean(object)` [source](https://underscorejs.org/docs/modules/isBoolean.html)  
Returns _true_ if **object** is either _true_ or _false_.

```
_.isBoolean(null);
=> false
```

`_.isDate(object)` [source](https://underscorejs.org/docs/modules/isDate.html)  
Returns _true_ if **object** is a Date.

```
_.isDate(new Date());
=> true
```

`_.isRegExp(object)` [source](https://underscorejs.org/docs/modules/isRegExp.html)  
Returns _true_ if **object** is a RegExp.

```
_.isRegExp(/moe/);
=> true
```

`_.isError(object)` [source](https://underscorejs.org/docs/modules/isError.html)  
Returns _true_ if **object** inherits from an Error.

```
try {
  throw new TypeError("Example");
} catch (o_O) {
  _.isError(o_O);
}
=> true
```

`_.isSymbol(object)` [source](https://underscorejs.org/docs/modules/isSymbol.html)  
Returns _true_ if **object** is a [Symbol](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Symbol).

```
_.isSymbol(Symbol());
=> true
```

`_.isMap(object)` [source](https://underscorejs.org/docs/modules/isMap.html)  
Returns _true_ if **object** is a [Map](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Map).

```
_.isMap(new Map());
=> true
```

`_.isWeakMap(object)` [source](https://underscorejs.org/docs/modules/isWeakMap.html)  
Returns _true_ if **object** is a [WeakMap](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/WeakMap).

```
_.isWeakMap(new WeakMap());
=> true
```

`_.isSet(object)` [source](https://underscorejs.org/docs/modules/isSet.html)  
Returns _true_ if **object** is a [Set](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/Set).

```
_.isSet(new Set());
=> true
```

`_.isWeakSet(object)` [source](https://underscorejs.org/docs/modules/isWeakSet.html)  
Returns _true_ if **object** is a [WeakSet](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/WeakSet).

```
_.isWeakSet(WeakSet());
=> true
```

`_.isArrayBuffer(object)` [source](https://underscorejs.org/docs/modules/isArrayBuffer.html)  
Returns _true_ if **object** is an [ArrayBuffer](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/ArrayBuffer).

```
_.isArrayBuffer(new ArrayBuffer(8));
=> true
```

`_.isDataView(object)` [source](https://underscorejs.org/docs/modules/isDataView.html)  
Returns _true_ if **object** is a [DataView](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/DataView).

```
_.isDataView(new DataView(new ArrayBuffer(8)));
=> true
```

`_.isTypedArray(object)` [source](https://underscorejs.org/docs/modules/isTypedArray.html)  
Returns _true_ if **object** is a [TypedArray](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Global_Objects/TypedArray).

```
_.isTypedArray(new Int8Array(8));
=> true
```

`_.isNaN(object)` [source](https://underscorejs.org/docs/modules/isNaN.html)  
Returns _true_ if **object** is _NaN_.  
Note: this is not the same as the native **isNaN** function, which will also return true for many other not-number values, such as undefined.

```
_.isNaN(NaN);
=> true
isNaN(undefined);
=> true
_.isNaN(undefined);
=> false
```

`_.isNull(object)` [source](https://underscorejs.org/docs/modules/isNull.html)  
Returns _true_ if the value of **object** is _null_.

```
_.isNull(null);
=> true
_.isNull(undefined);
=> false
```

`_.isUndefined(value)` [source](https://underscorejs.org/docs/modules/isUndefined.html)  
Returns _true_ if **value** is _undefined_.

```
_.isUndefined(window.missingVariable);
=> true
```

## Utility Functions

`_.noConflict()` [source](https://underscorejs.org/docs/modules/noConflict.html)  
Give control of the global \_ variable back to its previous owner. Returns a reference to the **Underscore** object.

```
var underscore = _.noConflict();
```

The \_.noConflict function is not present if you use the EcmaScript 6, AMD or CommonJS module system to import Underscore.

`_.identity(value)` [source](https://underscorejs.org/docs/modules/identity.html)  
Returns the same value that is used as the argument. In math: f(x) = x  
This function looks useless, but is used throughout Underscore as a default iteratee.

```
var stooge = {name: 'moe'};
stooge === _.identity(stooge);
=> true
```

`_.constant(value)` [source](https://underscorejs.org/docs/modules/constant.html)  
Creates a function that returns the same value that is used as the argument of \_.constant.

```
var stooge = {name: 'moe'};
stooge === _.constant(stooge)();
=> true
```

`_.noop()` [source](https://underscorejs.org/docs/modules/noop.html)  
Returns undefined irrespective of the arguments passed to it. Useful as the default for optional callback arguments.

```
obj.initialize = _.noop;
```

`_.times(n, iteratee, [context])` [source](https://underscorejs.org/docs/modules/times.html)  
Invokes the given iteratee function **n** times. Each invocation of [**iteratee**](https://underscorejs.org/#iteratee) is called with an index argument. Produces an array of the returned values.

```
_.times(3, function(n){ genie.grantWishNumber(n); });
```

`_.random(min, max)` [source](https://underscorejs.org/docs/modules/random.html)  
Returns a random integer between **min** and **max**, inclusive. If you only pass one argument, it will return a number between 0 and that number.

```
_.random(0, 100);
=> 42
```

`_.mixin(object)` [source](https://underscorejs.org/docs/modules/mixin.html)  
Allows you to extend Underscore with your own utility functions. Pass a hash of {name: function} definitions to have your functions added to the Underscore object, as well as the OOP wrapper. Returns the Underscore object to facilitate chaining.

```
_.mixin({
  capitalize: function(string) {
    return string.charAt(0).toUpperCase() + string.substring(1).toLowerCase();
  }
});
_("fabio").capitalize();
=> "Fabio"
```

`_.iteratee(value, [context])` [source](https://underscorejs.org/docs/modules/iteratee.html)  
Generates a callback that can be applied to each element in a collection. \_.iteratee supports a number of shorthand syntaxes for common callback use cases. Depending upon value's type, \_.iteratee will return:

```
// No value
_.iteratee();
=> _.identity()

// Function
_.iteratee(function(n) { return n * 2; });
=> function(n) { return n * 2; }

// Object
_.iteratee({firstName: 'Chelsea'});
=> _.matcher({firstName: 'Chelsea'});

// Anything else
_.iteratee('firstName');
=> _.property('firstName');
```

The following Underscore methods transform their predicates through \_.iteratee: countBy, every, filter, find, findIndex, findKey, findLastIndex, groupBy, indexBy, map, mapObject, max, min, partition, reject, some, sortBy, sortedIndex, and uniq

You may overwrite \_.iteratee with your own custom function, if you want additional or different shorthand syntaxes:

```
// Support `RegExp` predicate shorthand.
var builtinIteratee = _.iteratee;
_.iteratee = function(value, context) {
  if (_.isRegExp(value)) return function(obj) { return value.test(obj) };
  return builtinIteratee(value, context);
};
```

`_.uniqueId([prefix])` [source](https://underscorejs.org/docs/modules/uniqueId.html)  
Generate a globally-unique id for client-side models or DOM elements that need one. If **prefix** is passed, the id will be appended to it.

```
_.uniqueId('contact_');
=> 'contact_104'
```

`_.escape(string)` [source](https://underscorejs.org/docs/modules/escape.html)  
Escapes a string for insertion into HTML, replacing &, <, \>, ", \`, and ' characters.

```
_.escape('Curly, Larry & Moe');
=> "Curly, Larry &amp; Moe"
```

`_.unescape(string)` [source](https://underscorejs.org/docs/modules/unescape.html)  
The opposite of [**escape**](https://underscorejs.org/#escape), replaces &amp;, &lt;, &gt;, &quot;, &#x60; and &#x27; with their unescaped counterparts.

```
_.unescape('Curly, Larry &amp; Moe');
=> "Curly, Larry & Moe"
```

`_.result(object, property, [defaultValue])` [source](https://underscorejs.org/docs/modules/result.html)  
If the value of the named **property** is a function then invoke it with the **object** as context; otherwise, return it. If a default value is provided and the property doesn't exist or is undefined then the default will be returned. If defaultValue is a function its result will be returned.

```
var object = {cheese: 'crumpets', stuff: function(){ return 'nonsense'; }};
_.result(object, 'cheese');
=> "crumpets"
_.result(object, 'stuff');
=> "nonsense"
_.result(object, 'meat', 'ham');
=> "ham"
```

`_.now()` [source](https://underscorejs.org/docs/modules/now.html)  
Returns an integer timestamp for the current time, using the fastest method available in the runtime. Useful for implementing timing/animation functions.

```
_.now();
=> 1392066795351
```

`_.template(templateString, [settings])` [source](https://underscorejs.org/docs/modules/template.html)  
Compiles JavaScript templates into functions that can be evaluated for rendering. Useful for rendering complicated bits of HTML from JSON data sources. Template functions can both interpolate values, using <%= … %>, as well as execute arbitrary JavaScript code, with <% … %>. If you wish to interpolate a value, and have it be HTML-escaped, use <%- … %>. When you evaluate a template function, pass in a **data** object that has properties corresponding to the template's free variables. The **settings** argument should be a hash containing any \_.templateSettings that should be overridden.

_\_.template allows the template author to insert arbitrary JavaScript code by design. This means that you should only pass template code and template settings from trusted authors. Passing untrusted input to \_.template **will** create a code injection vulnerability in your application or library!_

```
var compiled = _.template("hello: <%= name %>");
compiled({name: 'moe'});
=> "hello: moe"

var template = _.template("<b><%- value %></b>");
template({value: '<script>'});
=> "<b>&lt;script&gt;</b>"
```

You can also use print from within JavaScript code. This is sometimes more convenient than using <%= ... %>.

```
var compiled = _.template("<% print('Hello ' + epithet); %>");
compiled({epithet: "stooge"});
=> "Hello stooge"
```

If ERB-style delimiters aren't your cup of tea, you can change Underscore's template settings to use different symbols to set off interpolated code. Define an **interpolate** regex to match expressions that should be interpolated verbatim, an **escape** regex to match expressions that should be inserted after being HTML-escaped, and an **evaluate** regex to match expressions that should be evaluated without insertion into the resulting string. Note that if part of your template matches more than one of these regexes, the first will be applied by the following order of priority: (1) **escape**, (2) **interpolate**, (3) **evaluate**. You may define or omit any combination of the three. For example, to perform [Mustache.js](https://github.com/janl/mustache.js#readme)\-style templating:

```
_.templateSettings = {
  interpolate: /\{\{(.+?)\}\}/g
};

var template = _.template("Hello {{ name }}!");
template({name: "Mustache"});
=> "Hello Mustache!"
```

By default, **template** places the values from your data in the local scope via the with statement. However, you can specify a single variable name with the **variable** setting. This can significantly improve the speed at which a template is able to render.

```
_.template("Using 'with': <%= data.answer %>", {variable: 'data'})({answer: 'no'});
=> "Using 'with': no"
```

Precompiling your templates can be a big help when debugging errors you can't reproduce. This is because precompiled templates can provide line numbers and a stack trace, something that is not possible when compiling templates on the client. The **source** property is available on the compiled template function for easy precompilation.

```
<script>
  JST.project = <%= _.template(jstText).source %>;
</script>
```

  
It is possible to get the current Underscore version via \_.VERSION .

```
_.VERSION => 1.13.8
```

## Object-Oriented Style

You can use Underscore in either an object-oriented or a functional style, depending on your preference. The following two lines of code are identical ways to double a list of numbers. [source](https://underscorejs.org/docs/modules/underscore.html), [source](https://underscorejs.org/docs/modules/mixin.html)

```
_.map([1, 2, 3], function(n){ return n * 2; });
_([1, 2, 3]).map(function(n){ return n * 2; });
```

## Chaining

Calling chain will cause all future method calls to return wrapped objects. When you've finished the computation, call value to retrieve the final value. Here's an example of chaining together a **map/flatten/reduce**, in order to get the word count of every word in a song.

```
var lyrics = [
  {line: 1, words: "I'm a lumberjack and I'm okay"},
  {line: 2, words: "I sleep all night and I work all day"},
  {line: 3, words: "He's a lumberjack and he's okay"},
  {line: 4, words: "He sleeps all night and he works all day"}
];

_.chain(lyrics)
  .map(function(line) { return line.words.split(' '); })
  .flatten()
  .reduce(function(counts, word) {
    counts[word] = (counts[word] || 0) + 1;
    return counts;
  }, {})
  .value();

=> {lumberjack: 2, all: 4, night: 2 ... }
```

In addition, the [Array prototype's methods](https://developer.mozilla.org/en/JavaScript/Reference/Global_Objects/Array/prototype) are proxied through the chained Underscore object, so you can slip a reverse or a push into your chain, and continue to modify the array.

`_.chain(obj)` [source](https://underscorejs.org/docs/modules/chain.html)  
Returns a wrapped object. Calling methods on this object will continue to return wrapped objects until value is called.

```
var stooges = [{name: 'curly', age: 25}, {name: 'moe', age: 21}, {name: 'larry', age: 23}];
var youngest = _.chain(stooges)
  .sortBy(function(stooge){ return stooge.age; })
  .map(function(stooge){ return stooge.name + ' is ' + stooge.age; })
  .first()
  .value();
=> "moe is 21"
```

`_.chain(obj).value()` [source](https://underscorejs.org/docs/modules/underscore.html)  
Extracts the value of a wrapped object.

```
_.chain([1, 2, 3]).reverse().value();
=> [3, 2, 1]
```

## Links & Suggested Reading

[Underscore.lua](https://mirven.github.io/underscore.lua/), a Lua port of the functions that are applicable in both languages. Includes OOP-wrapping and chaining. ([source](https://github.com/mirven/underscore.lua))

[Dollar.swift](https://www.dollarswift.org/), a Swift port of many of the Underscore.js functions and more. ([source](https://github.com/ankurp/Dollar.swift))

[Underscore.m](https://underscorem.org/), an Objective-C port of many of the Underscore.js functions, using a syntax that encourages chaining. ([source](https://github.com/robb/Underscore.m))

[\_.m](https://kmalakoff.github.io/_.m/), an alternative Objective-C port that tries to stick a little closer to the original Underscore.js API. ([source](https://github.com/kmalakoff/_.m))

[Underscore.php](https://github.com/bdelespierre/underscore.php), a PHP port of the functions that are applicable in both languages. Tailored for PHP 5.4 and made with data-type tolerance in mind. ([source](https://github.com/bdelespierre/underscore.php))

[Underscore-perl](https://vti.github.io/underscore-perl/), a Perl port of many of the Underscore.js functions, aimed at on Perl hashes and arrays. ([source](https://github.com/vti/underscore-perl))

[Underscore.cfc](https://russplaysguitar.github.io/UnderscoreCF/), a Coldfusion port of many of the Underscore.js functions. ([source](https://github.com/russplaysguitar/underscorecf))

[Underscore.string](https://epeli.github.io/underscore.string/), an Underscore extension that adds functions for string-manipulation: trim, startsWith, contains, capitalize, reverse, sprintf, and more.

[Underscore-java](https://javadev.github.io/underscore-java/), a java port of the functions that are applicable in both languages. Includes OOP-wrapping and chaining. ([source](https://github.com/javadev/underscore-java))

Ruby's [Enumerable](https://ruby-doc.org/core/classes/Enumerable.html) module.

[Prototype.js](https://prototypejs.org/), which provides JavaScript with collection functions in the manner closest to Ruby's Enumerable.

Oliver Steele's [Functional JavaScript](https://osteele.com/sources/javascript/functional/), which includes comprehensive higher-order function support as well as string lambdas.

Michael Aufreiter's [Data.js](https://github.com/substance/data), a data manipulation + persistence library for JavaScript.

Python's [itertools](https://docs.python.org/library/itertools.html).

[PyToolz](https://toolz.readthedocs.org/), a Python port that extends itertools and functools to include much of the Underscore API.

[Funcy](https://github.com/Suor/funcy), a practical collection of functional helpers for Python, partially inspired by Underscore.

## Notes

  
Underscore functions that depend on ordering, such as [\_.sortBy](https://underscorejs.org/#sortBy) and [\_.sortedIndex](https://underscorejs.org/#sortedIndex), use JavaScript’s built-in [relational operators](https://developer.mozilla.org/en-US/docs/Web/JavaScript/Reference/Operators/Comparison_Operators#Relational_operators), specifically the “less than” operator <. It is important to understand that these operators are only meaningful for numbers and strings. You can throw any value to them, but JavaScript will convert the operands to string or number first before performing the actual comparison. If you pass an operand that cannot be meaningfully converted to string or number, it ends up being NaN by default. This value is unsortable.

Ideally, the values that you are sorting should either be all (meaningfully convertible to) strings or all (meaningfully convertible to) numbers. If this is not the case, you have two options:

-   [\_.filter](https://underscorejs.org/#filter) out all unsortable values first.
-   Pick a target type, i.e., either string or number, and pass an [iteratee](https://underscorejs.org/#iteratee) to your Underscore function that will convert its argument to a sensible instance of the target type. For example, if you have an array of numbers that you want to sort and that may occasionally contain null or undefined, you can control whether you want to sort these before or after all numbers by passing an iteratee to \_.sortBy that returns \-Infinity or +Infinity for such values, respectively. Or maybe you want to treat them as zeros; it is up to you. The same iteratee can also be passed to other Underscore functions to ensure that the behavior is consistent.

## Change Log

— <small><i>February 19, 2026</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.13.7...1.13.8) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.13.8/index.html)  

-   Fixes a security issue in \_.flatten and \_.isEqual that, under very specific circumstances, could allow for a Denial of Service (DoS) attack in server applications. This bug was present in all previous versions of Underscore. More details: [CVE-2026-27601](https://github.com/jashkenas/underscore/security/advisories/GHSA-qpx9-hpmf-5gmw).
-   Adds documentation for \_.VERSION.
-   Clarifies some terminology in the documentation for contributors.

— <small><i>July 24, 2024</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.13.6...1.13.7) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.13.7/index.html)  

-   Fixes a bug where Underscore might throw an error on load if the executing environment overrides the native DataView.
-   Adds a direct link to the corresponding source code for each function in the documentation.
-   Clarifies the documentation for the **step** argument of the range function.
-   Adds dark mode support to the home page.
-   Other infrastructural improvements to funding, testing and building.

— <small><i>September 24, 2022</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.13.5...1.13.6) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.13.6/index.html)  
Hotfix for version 1.13.5 to remove a postinstall script from the package.json, which unexpectedly broke many people's builds.

— <small><i>September 23, 2022</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.13.4...1.13.5) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.13.5/index.html)  

-   Adds a module sub-entry to the package.json’s exports.require condition. When a bundling tool, such as Rollup with recent versions of @rollup/plugin-node-resolve, takes the exports map very literally, this should prevent situations in which the final bundle includes multiple copies of Underscore in different module formats.
-   Updates to the testing infrastructure and development dependencies.
-   No code changes.

— <small><i>June 2, 2022</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.13.3...1.13.4) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.13.4/index.html)  

-   Fixes a compatibility issue with WebPack module federation.
-   Documentation improvements.

— <small><i>April 23, 2022</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.13.2...1.13.3) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.13.3/index.html)  

-   Fixes a compatibility issue with ExtendScript.
-   Various improvements to testing and continuous integration, including the addition of security scanning and a reduced carbon footprint.

— <small><i>December 16, 2021</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.13.1...1.13.2) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.13.2/index.html)  

-   Fixes a regression introduced in 1.9.0 that caused \_.sample and \_.shuffle to no longer work on strings.
-   Fixes an issue in IE8 compatibility code.
-   Makes the website mobile-friendly.
-   Various other minor documentation enhancements and a new test.

— <small><i>April 15, 2021</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.13.0...1.13.1) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.13.1/index.html)  

-   Restores the underscore.js alias committed to the GitHub repository.
-   Adds some build clarifications to the documentation.
-   No code changes.

— <small><i>April 9, 2021</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.13.0-3...1.13.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.13.0/index.html)  

-   Merges the changes from the 1.13.0-0 through 1.13.0-3 preview releases into the main release stream following version 1.12.1. As of this release, ESM support is 100%.
-   Adds a [security policy](https://github.com/jashkenas/underscore/security/policy) to the documentation.
-   Adds funding information to the documentation.

— <small><i>March 31, 2021</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.13.0-2...1.13.0-3) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.13.0-3/index.html)  

-   Adds a "module" exports condition to the package.json, which should theoretically help to avoid duplicate code bundling with exports\-aware build tools.
-   Re-synchronizes some comments and documentation text with the 1.12.x branch.

— <small><i>March 15, 2021</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.13.0-1...1.13.0-2) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.13.0-2/index.html)  

-   Fixes the same security issue in \_.template as the parallel 1.12.1 release.

— <small><i>March 15, 2021</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.12.0...1.12.1) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.12.1/index.html)  

-   Fixes a security issue in \_.template that could enable a third party to inject code in compiled templates. This issue affects all versions of Underscore between 1.3.2 and 1.12.0, inclusive, as well as preview releases 1.13.0-0 and 1.13.0-1. The fix in this release is also included in the parallel preview release 1.13.0-2. [CVE-2021-23358](https://cve.mitre.org/cgi-bin/cvename.cgi?name=CVE-2021-23358)
-   Restores an optimization in \_.debounce that was unintentionally lost in version 1.9.0 (same as in parallel preview release 1.13.0-0).
-   Various test and documentation enhancements (same as in parallel preview releases 1.13.0-0 and 1.13.0-1).

— <small><i>March 11, 2021</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.13.0-0...1.13.0-1) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.13.0-1/index.html)  

-   Fixes an issue that caused aliases to be absent among the named exports in the new native ESM entry point for Node.js 12+.
-   More test and documentation fixes and enhancements.

— <small><i>March 9, 2021</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.12.0...1.13.0-0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.13.0-0/index.html)  

-   Adds experimental support for native ESM imports in Node.js. You can now also do named imports or even deep module imports directly from a Node.js process in Node.js version 12 and later. Monolithic imports are recommended for use in production. State (such as mixed-in functions) is shared between CommonJS and ESM consumers.
-   Renames the UMD bundle to underscore-umd.js for consistency with the other bundle names. An alias named underscore.js is retained for backwards compatibility.
-   Restores an optimization in \_.debounce that was unintentionally lost in version 1.9.0.
-   Various test and documentation enhancements.

— <small><i>November 24, 2020</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.11.0...1.12.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.12.0/index.html)  

-   Adds the \_.get and \_.toPath functions. The latter can be overridden in order to customize the interpretation of deep property paths throughout Underscore. A future version of Underscore-contrib will be providing a ready-made function for this purpose; users will be able to opt in to string-based path shorthands such as 'a.0.b' and 'a\[0\]\["b"\]' by using that function from Underscore-contrib to override \_.toPath.
-   Fixes a bug in \_.isEqual that caused typed arrays to compare equal when viewing different segments of the same underlying ArrayBuffer.
-   Improves the compatibility of \_.isEqual, \_.isDataView, \_.isMap, \_.isWeakMap and \_.isSet with some older browsers, especially IE 11.
-   Significantly enhances the performance of \_.isEmpty and several members of the isType family of functions.
-   Speeds up \_.isEqual comparison of typed arrays and DataViews with idential buffer, byteOffset and byteLength.
-   Restores cross-browser testing during continuous integration to its former glory and adds documentation about engine compatibility.
-   Slims down the development dependencies for testing.

— <small><i>August 28, 2020</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.10.2...1.11.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.11.0/index.html) — [Article](https://juliangonggrijp.com/article/introducing-modular-underscore.html)  

-   Puts the source of every function in a separate module, following up on the move to EcmaScript 6 export notation in [version 1.10.0](https://underscorejs.org/#1.10.0). AMD and CommonJS versions of the function modules are provided as well. This brings perfect treeshaking to all users and unlocks the possibility to create arbitrary custom Underscore builds without code size overhead. modules/index.js is still present and the UMD bundle is still recommended for most users.  
    Since the modularization obfuscates the diff, piecewise diffs are provided below.
    -   [Changes before modularization](https://github.com/jashkenas/underscore/compare/1.10.2...3236023)
    -   [Modularization itself](https://github.com/jashkenas/underscore/compare/3236023...240d60a)
    -   [Changes after modularization](https://github.com/jashkenas/underscore/compare/240d60a...1.11.0)
-   Adds a monolithic bundle in EcmaScript 6 module format, underscore-esm.js, as a modern alternative to the monolithic UMD bundle. Users who want to use ES module imports in the browser are advised to use this new bundle instead of modules/index.js, because underscore-esm.js provides the complete Underscore interface in a single download.
-   Adds a modular version of the annotated source, reflecting the full internal structure of the primary source code.
-   Adds \_.isArrayBuffer, \_.isDataView and \_.isTypedArray functions, as well as support for the corresponding value types to \_.isEqual.
-   Adds the option to flatten arrays to a specific depth: \_.flatten(anArray, 3).
-   Adds \_.transpose as an alias to \_.unzip.
-   Fixes an inconsistency where Array.prototype methods on the Underscore wrapper would error when the wrapped value is null or undefined. These methods now perform a no-op on null values like the other Underscore functions.
-   Fixes a bug that caused \_.first and \_.last to return \[\] instead of undefined for empty arrays when used as an iteratee.
-   Fixes a regression introduced in version 1.9.0 that caused \_.bindAll to return undefined instead of the bound object.
-   Restores continuous integration testing with Travis CI.
-   Replaces stigmatizing “whitelist”/“blacklist” terminology in comments and documentation by neutral “allowed”/“disallowed” terminology.
-   Various clarifications and minor enhancements and fixes to the documentation, source comments and a test.

— <small><i>March 30, 2020</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.10.1...1.10.2) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.10.2/index.html)  

-   Fixes a bug introduced with 1.10.0, while using the legacy Node.js require API: var \_ = require("underscore").\_

— <small><i>March 30, 2020</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.10.0...1.10.1) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.10.1/index.html)  

-   Fixed relative links among the ES Modules to include the file extension, for web browser support.

— <small><i>March 30, 2020</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.9.2...1.10.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.10.0/index.html)  

-   Reformats the source code to use EcmaScript 6 export notation. The underscore.js UMD bundle is now _compiled from_ underlying source modules instead of _being_ the source. From now on, Rollup users have the option to import from the underlying source module in order to enable treeshaking.
-   Explicitly states in the documentation, and verifies in the unittests, that \_.sortedIndex(array, value) always returns the lower bound, i.e., the smallest index, at which value may be inserted in array.
-   Makes the notation of the \_.max unittest consistent with other unittests.
-   Fixes a bug that would cause infinite recursion if an overridden implementation of \_.iteratee attempted to fall back to the original implementation.
-   Restores compatibility with EcmaScript 3 and ExtendScript.

— <small><i>Jan 6, 2020</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.9.1...1.9.2) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.9.2/index.html)  

-   No code changes. Updated a test to help out [CITGM](https://github.com/nodejs/node/pull/31167#issuecomment-571022478).

— <small><i>May 31, 2018</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.9.0...1.9.1) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.9.1/index.html)  

-   Fixes edge-case regressions from 1.9.0, including certain forms of calling \_.first and \_.last on an empty array, and passing arrays as keys to \_.countBy and \_.groupBy.

— <small><i>April 18, 2018</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.8.3...1.9.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.9.0/index.html)  

-   Adds the \_.restArguments function for variadic function handling.
-   Adds the \_.chunk function for chunking up an array.
-   Adds a \_.isSymbol, \_.isMap, \_.isWeakMap, \_.isSet and \_.isWeakSet functions.
-   \_.throttle and \_.debounce return functions that now have a .cancel() method, which can be used to cancel any scheduled calls.
-   \_.property now accepts arrays of keys and indexes as path specifiers, for looking up a deep properties of a value.
-   \_.range now accepts negative ranges to generate descending arrays.
-   Adds support for several environments including: WebWorkers, browserify and ES6 imports.
-   Removes the component.json as the Component package management system is discontinued.
-   The placeholder used for partial is now configurable by setting `_.partial.placeholder`.
-   `_.bindAll` now accepts arrays or arguments for keys.
-   Three years of performance improvements.

— <small><i>April 2, 2015</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.8.2...1.8.3) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.8.3/index.html)  

-   Adds an \_.create method, as a slimmed down version of Object.create.
-   Works around an iOS bug that can improperly cause isArrayLike to be JIT-ed. Also fixes a bug when passing 0 to isArrayLike.

— <small><i>Feb. 22, 2015</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.8.1...1.8.2) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.8.2/index.html)  

-   Restores the previous old-Internet-Explorer edge cases changed in 1.8.1.
-   Adds a fromIndex argument to \_.contains.

— <small><i>Feb. 19, 2015</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.8.0...1.8.1) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.8.1/index.html)  

-   Fixes/changes some old-Internet Explorer and related edge case behavior. Test your app with Underscore 1.8.1 in an old IE and let us know how it's doing...

— <small><i>Feb. 19, 2015</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.7.0...1.8.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.8.0/index.html)  

-   Added \_.mapObject, which is similar to \_.map, but just for the values in your object. (A real crowd pleaser.)
-   Added \_.allKeys which returns _all_ the enumerable property names on an object.
-   Reverted a 1.7.0 change where \_.extend only copied "own" properties. Hopefully this will un-break you — if it breaks you again, I apologize.
-   Added \_.extendOwn — a less-useful form of \_.extend that only copies over "own" properties.
-   Added \_.findIndex and \_.findLastIndex functions, which nicely complement their twin-twins \_.indexOf and \_.lastIndexOf.
-   Added an \_.isMatch predicate function that tells you if an object matches key-value properties. A kissing cousin of \_.isEqual and \_.matcher.
-   Added an \_.isError function.
-   Restored the \_.unzip function as the inverse of zip. Flip-flopping. I know.
-   \_.result now takes an optional fallback value (or function that provides the fallback value).
-   Added the \_.propertyOf function generator as a mirror-world version of \_.property.
-   Deprecated \_.matches. It's now known by a more harmonious name — \_.matcher.
-   Various and diverse code simplifications, changes for improved cross-platform compatibility, and edge case bug fixes.

— <small><i>August 26, 2014</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.6.0...1.7.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.7.0/index.html)  

-   For consistency and speed across browsers, Underscore now ignores native array methods for forEach, map, reduce, reduceRight, filter, every, some, indexOf, and lastIndexOf. "Sparse" arrays are officially dead in Underscore.
-   Added \_.iteratee to customize the iterators used by collection functions. Many Underscore methods will take a string argument for easier \_.property\-style lookups, an object for \_.where\-style filtering, or a function as a custom callback.
-   Added \_.before as a counterpart to \_.after.
-   Added \_.negate to invert the truth value of a passed-in predicate.
-   Added \_.noop as a handy empty placeholder function.
-   \_.isEmpty now works with arguments objects.
-   \_.has now guards against nullish objects.
-   \_.omit can now take an iteratee function.
-   \_.partition is now called with index and object.
-   \_.matches creates a shallow clone of your object and only iterates over own properties.
-   Aligning better with the forthcoming ECMA6 Object.assign, \_.extend only iterates over the object's own properties.
-   Falsy guards are no longer needed in \_.extend and \_.defaults—if the passed in argument isn't a JavaScript object it's just returned.
-   Fixed a few edge cases in \_.max and \_.min to handle arrays containing NaN (like strings or other objects) and Infinity and \-Infinity.
-   Override base methods like each and some and they'll be used internally by other Underscore functions too.
-   The escape functions handle backticks (\`), to deal with an IE ≤ 8 bug.
-   For consistency, \_.union and \_.difference now only work with arrays and not variadic args.
-   \_.memoize exposes the cache of memoized values as a property on the returned function.
-   \_.pick accepts iteratee and context arguments for a more advanced callback.
-   Underscore templates no longer accept an initial data object. \_.template always returns a function now.
-   Optimizations and code cleanup aplenty.

— <small><i>February 10, 2014</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.5.2...1.6.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.6.0/index.html)  

-   Underscore now registers itself for AMD (Require.js), Bower and Component, as well as being a CommonJS module and a regular (Java)Script. An ugliness, but perhaps a necessary one.
-   Added \_.partition, a way to split a collection into two lists of results — those that pass and those that fail a particular predicate.
-   Added \_.property, for easy creation of iterators that pull specific properties from objects. Useful in conjunction with other Underscore collection functions.
-   Added \_.matches, a function that will give you a predicate that can be used to tell if a given object matches a list of specified key/value properties.
-   Added \_.constant, as a higher-order \_.identity.
-   Added \_.now, an optimized way to get a timestamp — used internally to speed up debounce and throttle.
-   The \_.partial function may now be used to partially apply any of its arguments, by passing \_ wherever you'd like a placeholder variable, to be filled-in later.
-   The \_.each function now returns a reference to the list for chaining.
-   The \_.keys function now returns an empty array for non-objects instead of throwing.
-   … and more miscellaneous refactoring.

— <small><i>September 7, 2013</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.5.1...1.5.2) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.5.2/index.html)  

-   Added an indexBy function, which fits in alongside its cousins, countBy and groupBy.
-   Added a sample function, for sampling random elements from arrays.
-   Some optimizations relating to functions that can be implemented in terms of \_.keys (which includes, significantly, each on objects). Also for debounce in a tight loop.
-   The \_.escape function no longer escapes '/'.

— <small><i>July 8, 2013</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.5.0...1.5.1) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.5.1/index.html)  

-   Removed unzip, as it's simply the application of zip to an array of arguments. Use \_.zip.apply(\_, list) to transpose instead.

— <small><i>July 6, 2013</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.4.4...1.5.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.5.0/index.html)  

-   Added a new unzip function, as the inverse of \_.zip.
-   The throttle function now takes an options argument, allowing you to disable execution of the throttled function on either the **leading** or **trailing** edge.
-   A source map is now supplied for easier debugging of the minified production build of Underscore.
-   The defaults function now only overrides undefined values, not null ones.
-   Removed the ability to call \_.bindAll with no method name arguments. It's pretty much always wiser to allow the names of the methods you'd like to bind.
-   Removed the ability to call \_.after with an invocation count of zero. The minimum number of calls is (naturally) now 1.

— <small><i>January 30, 2013</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.4.3...1.4.4) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.4.4/index.html)  

-   Added \_.findWhere, for finding the first element in a list that matches a particular set of keys and values.
-   Added \_.partial, for partially applying a function _without_ changing its dynamic reference to this.
-   Simplified bind by removing some edge cases involving constructor functions. In short: don't \_.bind your constructors.
-   A minor optimization to invoke.
-   Fix bug in the minified version due to the minifier incorrectly optimizing-away isFunction.

— <small><i>December 4, 2012</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.4.2...1.4.3) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.4.3/index.html)  

-   Improved Underscore compatibility with Adobe's JS engine that can be used to script Illustrator, Photoshop, and friends.
-   Added a default \_.identity iterator to countBy and groupBy.
-   The uniq function can now take array, iterator, context as the argument list.
-   The times function now returns the mapped array of iterator results.
-   Simplified and fixed bugs in throttle.

— <small><i>October 6, 2012</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.4.1...1.4.2) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.4.2/index.html)  

-   For backwards compatibility, returned to pre-1.4.0 behavior when passing null to iteration functions. They now become no-ops again.

— <small><i>October 1, 2012</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.4.0...1.4.1) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.4.1/index.html)  

-   Fixed a 1.4.0 regression in the lastIndexOf function.

— <small><i>September 27, 2012</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.3.3...1.4.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.4.0/index.html)  

-   Added a pairs function, for turning a JavaScript object into \[key, value\] pairs ... as well as an object function, for converting an array of \[key, value\] pairs into an object.
-   Added a countBy function, for counting the number of objects in a list that match a certain criteria.
-   Added an invert function, for performing a simple inversion of the keys and values in an object.
-   Added a where function, for easy cases of filtering a list for objects with specific values.
-   Added an omit function, for filtering an object to remove certain keys.
-   Added a random function, to return a random number in a given range.
-   \_.debounce'd functions now return their last updated value, just like \_.throttle'd functions do.
-   The sortBy function now runs a stable sort algorithm.
-   Added the optional fromIndex option to indexOf and lastIndexOf.
-   "Sparse" arrays are no longer supported in Underscore iteration functions. Use a for loop instead (or better yet, an object).
-   The min and max functions may now be called on _very_ large arrays.
-   Interpolation in templates now represents null and undefined as the empty string.
-   ~Underscore iteration functions no longer accept null values as a no-op argument. You'll get an early error instead.~
-   A number of edge-cases fixes and tweaks, which you can spot in the [diff](https://github.com/jashkenas/underscore/compare/1.3.3...1.4.0). Depending on how you're using Underscore, **1.4.0** may be more backwards-incompatible than usual — please test when you upgrade.

— <small><i>April 10, 2012</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.3.1...1.3.3) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.3.3/index.html)  

-   Many improvements to \_.template, which now provides the source of the template function as a property, for potentially even more efficient pre-compilation on the server-side. You may now also set the variable option when creating a template, which will cause your passed-in data to be made available under the variable you named, instead of using a with statement — significantly improving the speed of rendering the template.
-   Added the pick function, which allows you to filter an object literal with a list of allowed property names.
-   Added the result function, for convenience when working with APIs that allow either functions or raw properties.
-   Added the isFinite function, because sometimes knowing that a value is a number just ain't quite enough.
-   The sortBy function may now also be passed the string name of a property to use as the sort order on each object.
-   Fixed uniq to work with sparse arrays.
-   The difference function now performs a shallow flatten instead of a deep one when computing array differences.
-   The debounce function now takes an immediate parameter, which will cause the callback to fire on the leading instead of the trailing edge.

— <small><i>January 23, 2012</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.3.0...1.3.1) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.3.1/index.html)  

-   Added an \_.has function, as a safer way to use hasOwnProperty.
-   Added \_.collect as an alias for \_.map. Smalltalkers, rejoice.
-   Reverted an old change so that \_.extend will correctly copy over keys with undefined values again.
-   Bugfix to stop escaping slashes within interpolations in \_.template.

— <small><i>January 11, 2012</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.2.4...1.3.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.3.0/index.html)  

-   Removed AMD (RequireJS) support from Underscore. If you'd like to use Underscore with RequireJS, you can load it as a normal script, wrap or patch your copy, or download a forked version.

— <small><i>January 4, 2012</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.2.3...1.2.4) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.2.4/index.html)  

-   You now can (and probably should, as it's simpler) write \_.chain(list) instead of \_(list).chain().
-   Fix for escaped characters in Underscore templates, and for supporting customizations of \_.templateSettings that only define one or two of the required regexes.
-   Fix for passing an array as the first argument to an \_.wrap'd function.
-   Improved compatibility with ClojureScript, which adds a call function to String.prototype.

— <small><i>December 7, 2011</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.2.2...1.2.3) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.2.3/index.html)  

-   Dynamic scope is now preserved for compiled \_.template functions, so you can use the value of this if you like.
-   Sparse array support of \_.indexOf, \_.lastIndexOf.
-   Both \_.reduce and \_.reduceRight can now be passed an explicitly undefined value. (There's no reason why you'd want to do this.)

— <small><i>November 14, 2011</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.2.1...1.2.2) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.2.1/index.html)  

-   Continued tweaks to \_.isEqual semantics. Now JS primitives are considered equivalent to their wrapped versions, and arrays are compared by their numeric properties only <small>(#351)</small>.
-   \_.escape no longer tries to be smart about not double-escaping already-escaped HTML entities. Now it just escapes regardless <small>(#350)</small>.
-   In \_.template, you may now leave semicolons out of evaluated statements if you wish: <% }) %> <small>(#369)</small>.
-   \_.after(callback, 0) will now trigger the callback immediately, making "after" easier to use with asynchronous APIs <small>(#366)</small>.

— <small><i>October 24, 2011</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.2.0...1.2.1) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.2.1/index.html)  

-   Several important bug fixes for \_.isEqual, which should now do better on mutated Arrays, and on non-Array objects with length properties. <small>(#329)</small>
-   [James Burke](https://github.com/jrburke) contributed Underscore exporting for AMD module loaders, and [Tony Lukasavage](https://github.com/tonylukasavage) for Appcelerator Titanium. <small>(#335, #338)</small>
-   You can now \_.groupBy(list, 'property') as a shortcut for grouping values by a particular common property.
-   \_.throttle'd functions now fire immediately upon invocation, and are rate-limited thereafter <small>(#170, #266)</small>.
-   Most of the \_.is\[Type\] checks no longer ducktype.
-   The \_.bind function now also works on constructors, a-la ES5 ... but you would never want to use \_.bind on a constructor function.
-   \_.clone no longer wraps non-object types in Objects.
-   \_.find and \_.filter are now the preferred names for \_.detect and \_.select.

— <small><i>October 5, 2011</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.1.7...1.2.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.2.0/index.html)  

-   The \_.isEqual function now supports true deep equality comparisons, with checks for cyclic structures, thanks to Kit Cambridge.
-   Underscore templates now support HTML escaping interpolations, using <%- ... %> syntax.
-   Ryan Tenney contributed \_.shuffle, which uses a modified Fisher-Yates to give you a shuffled copy of an array.
-   \_.uniq can now be passed an optional iterator, to determine by what criteria an object should be considered unique.
-   \_.last now takes an optional argument which will return the last N elements of the list.
-   A new \_.initial function was added, as a mirror of \_.rest, which returns all the initial values of a list (except the last N).

— <small><i>July 13, 2011</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.1.6...1.1.7) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.1.7/index.html)  
Added \_.groupBy, which aggregates a collection into groups of like items. Added \_.union and \_.difference, to complement the (re-named) \_.intersection. Various improvements for support of sparse arrays. \_.toArray now returns a clone, if directly passed an array. \_.functions now also returns the names of functions that are present in the prototype chain.

— <small><i>April 18, 2011</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.1.5...1.1.6) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.1.6/index.html)  
Added \_.after, which will return a function that only runs after first being called a specified number of times. \_.invoke can now take a direct function reference. \_.every now requires an iterator function to be passed, which mirrors the ES5 API. \_.extend no longer copies keys when the value is undefined. \_.bind now errors when trying to bind an undefined value.

— <small><i>March 20, 2011</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.1.4...1.1.5) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.1.5/index.html)  
Added an \_.defaults function, for use merging together JS objects representing default options. Added an \_.once function, for manufacturing functions that should only ever execute a single time. \_.bind now delegates to the native ES5 version, where available. \_.keys now throws an error when used on non-Object values, as in ES5. Fixed a bug with \_.keys when used over sparse arrays.

— <small><i>January 9, 2011</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.1.3...1.1.4) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.1.4/index.html)  
Improved compliance with ES5's Array methods when passing null as a value. \_.wrap now correctly sets this for the wrapped function. \_.indexOf now takes an optional flag for finding the insertion index in an array that is guaranteed to already be sorted. Avoiding the use of .callee, to allow \_.isArray to work properly in ES5's strict mode.

— <small><i>December 1, 2010</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.1.2...1.1.3) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.1.3/index.html)  
In CommonJS, Underscore may now be required with just:  
var \_ = require("underscore"). Added \_.throttle and \_.debounce functions. Removed \_.breakLoop, in favor of an ES5-style un-_break_\-able each implementation — this removes the try/catch, and you'll now have better stack traces for exceptions that are thrown within an Underscore iterator. Improved the **isType** family of functions for better interoperability with Internet Explorer host objects. \_.template now correctly escapes backslashes in templates. Improved \_.reduce compatibility with the ES5 version: if you don't pass an initial value, the first item in the collection is used. \_.each no longer returns the iterated collection, for improved consistency with ES5's forEach.

— <small><i>October 15, 2010</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.1.1...1.1.2) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.1.2/index.html)  
Fixed \_.contains, which was mistakenly pointing at \_.intersect instead of \_.include, like it should have been. Added \_.unique as an alias for \_.uniq.

— <small><i>October 5, 2010</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.1.0...1.1.1) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.1.1/index.html)  
Improved the speed of \_.template, and its handling of multiline interpolations. Ryan Tenney contributed optimizations to many Underscore functions. An annotated version of the source code is now available.

— <small><i>August 18, 2010</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.0.4...1.1.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.1.0/index.html)  
The method signature of \_.reduce has been changed to match the ES5 signature, instead of the Ruby/Prototype.js version. This is a backwards-incompatible change. \_.template may now be called with no arguments, and preserves whitespace. \_.contains is a new alias for \_.include.

— <small><i>June 22, 2010</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.0.3...1.0.4) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.0.4/index.html)  
[Andri Möll](https://themoell.com/) contributed the \_.memoize function, which can be used to speed up expensive repeated computations by caching the results.

— <small><i>June 14, 2010</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.0.2...1.0.3) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.0.3/index.html)  
Patch that makes \_.isEqual return false if any property of the compared object has a NaN value. Technically the correct thing to do, but of questionable semantics. Watch out for NaN comparisons.

— <small><i>March 23, 2010</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.0.1...1.0.2) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.0.2/index.html)  
Fixes \_.isArguments in recent versions of Opera, which have arguments objects as real Arrays.

— <small><i>March 19, 2010</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/1.0.0...1.0.1) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.0.1/index.html)  
Bugfix for \_.isEqual, when comparing two objects with the same number of undefined keys, but with different names.

— <small><i>March 18, 2010</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.6.0...1.0.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/1.0.0/index.html)  
Things have been stable for many months now, so Underscore is now considered to be out of beta, at **1.0**. Improvements since **0.6** include \_.isBoolean, and the ability to have \_.extend take multiple source objects.

— <small><i>February 24, 2010</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.5.8...0.6.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.6.0/index.html)  
Major release. Incorporates a number of [Mile Frawley's](https://github.com/ratbeard) refactors for safer duck-typing on collection functions, and cleaner internals. A new \_.mixin method that allows you to extend Underscore with utility functions of your own. Added \_.times, which works the same as in Ruby or Prototype.js. Native support for ES5's Array.isArray, and Object.keys.

— <small><i>January 28, 2010</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.5.7...0.5.8) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.5.8/index.html)  
Fixed Underscore's collection functions to work on [NodeLists](https://developer.mozilla.org/En/DOM/NodeList) and [HTMLCollections](https://developer.mozilla.org/En/DOM/HTMLCollection) once more, thanks to [Justin Tulloss](https://github.com/JustinTulloss).

— <small><i>January 20, 2010</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.5.6...0.5.7) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.5.7/index.html)  
A safer implementation of \_.isArguments, and a faster \_.isNumber,  
thanks to [Jed Schmidt](https://jedschmidt.com/).

— <small><i>January 18, 2010</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.5.5...0.5.6) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.5.6/index.html)  
Customizable delimiters for \_.template, contributed by [Noah Sloan](https://github.com/iamnoah).

— <small><i>January 9, 2010</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.5.4...0.5.5) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.5.5/index.html)  
Fix for a bug in MobileSafari's OOP-wrapper, with the arguments object.

— <small><i>January 5, 2010</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.5.2...0.5.4) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.5.4/index.html)  
Fix for multiple single quotes within a template string for \_.template. See: [Rick Strahl's blog post](https://www.west-wind.com/Weblog/posts/509108.aspx).

— <small><i>January 1, 2010</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.5.1...0.5.2) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.5.2/index.html)  
New implementations of isArray, isDate, isFunction, isNumber, isRegExp, and isString, thanks to a suggestion from [Robert Kieffer](https://www.broofa.com/). Instead of doing Object#toString comparisons, they now check for expected properties, which is less safe, but more than an order of magnitude faster. Most other Underscore functions saw minor speed improvements as a result. [Evgeniy Dolzhenko](https://dolzhenko.org/) contributed \_.tap, [similar to Ruby 1.9's](https://ruby-doc.org/core-1.9/classes/Object.html#M000191), which is handy for injecting side effects (like logging) into chained calls.

— <small><i>December 9, 2009</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.5.0...0.5.1) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.5.1/index.html)  
Added an \_.isArguments function. Lots of little safety checks and optimizations contributed by [Noah Sloan](https://github.com/iamnoah) and [Andri Möll](https://themoell.com/).

— <small><i>December 7, 2009</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.4.7...0.5.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.5.0/index.html)  
**\[API Changes\]** \_.bindAll now takes the context object as its first parameter. If no method names are passed, all of the context object's methods are bound to it, enabling chaining and easier binding. \_.functions now takes a single argument and returns the names of its Function properties. Calling \_.functions(\_) will get you the previous behavior. Added \_.isRegExp so that isEqual can now test for RegExp equality. All of the "is" functions have been shrunk down into a single definition. [Karl Guertin](https://github.com/grayrest) contributed patches.

— <small><i>December 6, 2009</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.4.6...0.4.7) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.4.7/index.html)  
Added isDate, isNaN, and isNull, for completeness. Optimizations for isEqual when checking equality between Arrays or Dates. \_.keys is now <small><i><b>25%–2X</b></i></small> faster (depending on your browser) which speeds up the functions that rely on it, such as \_.each.

— <small><i>November 30, 2009</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.4.5...0.4.6) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.4.6/index.html)  
Added the range function, a port of the [Python function of the same name](https://docs.python.org/library/functions.html#range), for generating flexibly-numbered lists of integers. Original patch contributed by [Kirill Ishanov](https://github.com/kylichuku).

— <small><i>November 19, 2009</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.4.4...0.4.5) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.4.5/index.html)  
Added rest for Arrays and arguments objects, and aliased first as head, and rest as tail, thanks to [Luke Sutton](https://github.com/lukesutton)'s patches. Added tests ensuring that all Underscore Array functions also work on _arguments_ objects.

— <small><i>November 18, 2009</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.4.3...0.4.4) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.4.4/index.html)  
Added isString, and isNumber, for consistency. Fixed \_.isEqual(NaN, NaN) to return _true_ (which is debatable).

— <small><i>November 9, 2009</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.4.2...0.4.3) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.4.3/index.html)  
Started using the native StopIteration object in browsers that support it. Fixed Underscore setup for CommonJS environments.

— <small><i>November 9, 2009</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.4.1...0.4.2) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.4.2/index.html)  
Renamed the unwrapping function to value, for clarity.

— <small><i>November 8, 2009</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.4.0...0.4.1) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.4.1/index.html)  
Chained Underscore objects now support the Array prototype methods, so that you can perform the full range of operations on a wrapped array without having to break your chain. Added a breakLoop method to **break** in the middle of any Underscore iteration. Added an isEmpty function that works on arrays and objects.

— <small><i>November 7, 2009</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.3.3...0.4.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.4.0/index.html)  
All Underscore functions can now be called in an object-oriented style, like so: \_(\[1, 2, 3\]).map(...);. Original patch provided by [Marc-André Cournoyer](https://macournoyer.com/). Wrapped objects can be chained through multiple method invocations. A [functions](https://underscorejs.org/#object-functions) method was added, providing a sorted list of all the functions in Underscore.

— <small><i>October 31, 2009</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.3.2...0.3.3) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.3.3/index.html)  
Added the JavaScript 1.8 function reduceRight. Aliased it as foldr, and aliased reduce as foldl.

— <small><i>October 29, 2009</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.3.1...0.3.2) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.3.2/index.html)  
Now runs on stock [Rhino](https://www.mozilla.org/rhino/) interpreters with: load("underscore.js"). Added [identity](https://underscorejs.org/#identity) as a utility function.

— <small><i>October 29, 2009</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.3.0...0.3.1) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.3.1/index.html)  
All iterators are now passed in the original collection as their third argument, the same as JavaScript 1.6's **forEach**. Iterating over objects is now called with (value, key, collection), for details see [\_.each](https://underscorejs.org/#each).

— <small><i>October 29, 2009</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.2.0...0.3.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.3.0/index.html)  
Added [Dmitry Baranovskiy](https://github.com/DmitryBaranovskiy)'s comprehensive optimizations, merged in [Kris Kowal](https://github.com/kriskowal)'s patches to make Underscore [CommonJS](https://wiki.commonjs.org/wiki/CommonJS) and [Narwhal](https://narwhaljs.org/) compliant.

— <small><i>October 28, 2009</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.1.1...0.2.0) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.2.0/index.html)  
Added compose and lastIndexOf, renamed inject to reduce, added aliases for inject, filter, every, some, and forEach.

— <small><i>October 28, 2009</i></small> — [Diff](https://github.com/jashkenas/underscore/compare/0.1.0...0.1.1) — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.1.1/index.html)  
Added noConflict, so that the "Underscore" object can be assigned to other variables.

— <small><i>October 28, 2009</i></small> — [Docs](https://cdn.statically.io/gh/jashkenas/underscore/0.1.1/index.html)  
Initial release of Underscore.js.

