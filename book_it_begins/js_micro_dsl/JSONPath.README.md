---
created: 2026-06-06T00:19:29 (UTC +03:00)
tags: []
source: https://goessner.net/articles/JsonPath/
author: 
---

# JSONPath - XPath for JSON

> ## Excerpt
> A frequently emphasized advantage of XML is the availability of plenty tools to analyse, transform and selectively extract data out of XML documents. XPath is one of these powerful tools.

---
#### |2007-02-21| e1 [#](https://goessner.net/articles/JsonPath/index.html#e1 "permanent link") JSONPath - XPath for JSON

A frequently emphasized advantage of XML is the availability of plenty tools to analyse, transform and selectively extract data out of XML documents. [XPath](http://en.wikipedia.org/wiki/XPath) is one of these powerful tools.

It's time to wonder, if there is a need for something like XPath4JSON and what are the problems it can solve.

-   Data may be interactively found and extracted out of [JSON](http://json.org/) structures on the client without special scripting.
-   JSON data requested by the client can be reduced to the relevant parts on the server, such minimizing the bandwidth usage of the server response.

If we agree, that a tool for picking parts out of a JSON structure at hand does make sense, some questions come up. How should it do its job? How do JSONPath expressions look like?

Due to the fact, that JSON is a natural representation of data for the C family of programming languages, the chances are high, that the particular language has native syntax elements to access a JSON structure.

The following XPath expression

`/store/book[1]/title`

would look like

`x.store.book[0].title`

or

`x['store']['book'][0]['title']`

in Javascript, Python and PHP with a variable `x` holding the JSON structure. Here we observe, that the particular language usually has a fundamental XPath feature already built in.

The JSONPath tool in question should …

-   be naturally based on those language characteristics.
-   cover only essential parts of XPath 1.0.
-   be lightweight in code size and memory consumption.
-   be runtime efficient.

#### |2007-08-17| e2 [#](https://goessner.net/articles/JsonPath/index.html#e2 "permanent link") JSONPath expressions

JSONPath expressions always refer to a JSON structure in the same way as XPath expression are used in combination with an XML document. Since a JSON structure is usually anonymous and doesn't necessarily have a "root member object" JSONPath assumes the abstract name `$` assigned to the outer level object.

JSONPath expressions can use the _dot_–notation

`$.store.book[0].title`

or the _bracket_–notation

`$['store']['book'][0]['title']`

for input pathes. Internal or output pathes will always be converted to the more general _bracket_–notation.

JSONPath allows the _wildcard_ symbol \* for member names and array indices. It borrows the _descendant_ operator '..' from [E4X](http://en.wikipedia.org/wiki/E4X) and the _[array slice syntax](http://developer.mozilla.org/es4/proposals/slice_syntax.html)_ proposal `[start:end:step]` from [ECMASCRIPT 4](http://www.ecmascript.org/).

Expressions of the underlying scripting language `(<expr>)` can be used as an alternative to explicit names or indices as in

`$.store.book[(@.length-1)].title`

using the symbol '@' for the current object. Filter expressions are supported via the syntax `?(<boolean expr>)` as in

`$.store.book[?(@.price < 10)].title`

Here is a complete overview and a side by side comparison of the JSONPath syntax elements with its XPath counterparts.

<table><tbody><tr><td><strong>XPath</strong></td><td><strong>JSONPath</strong></td><td><strong>Description</strong></td></tr><tr><td>/</td><td>$</td><td>the root object/element</td></tr><tr><td>.</td><td>@</td><td>the current object/element</td></tr><tr><td>/</td><td>. or []</td><td>child operator</td></tr><tr><td>..</td><td>n/a</td><td>parent operator</td></tr><tr><td>//</td><td>..</td><td>recursive descent. JSONPath borrows this syntax from E4X.</td></tr><tr><td>*</td><td>*</td><td>wildcard. All objects/elements regardless their names.</td></tr><tr><td>@</td><td>n/a</td><td>attribute access. JSON structures don't have attributes.</td></tr><tr><td>[]</td><td>[]</td><td>subscript operator. XPath uses it to iterate over element collections and for <a href="http://www.w3.org/TR/xpath#predicates">predicates</a>. In Javascript and JSON it is the native array operator.</td></tr><tr><td>|</td><td>[,]</td><td>Union operator in XPath results in a combination of node sets. JSONPath allows alternate names or array indices as a set.</td></tr><tr><td>n/a</td><td>[start:end:step]</td><td>array slice operator borrowed from ES4.</td></tr><tr><td>[]</td><td>?()</td><td>applies a filter (script) expression.</td></tr><tr><td>n/a</td><td>()</td><td>script expression, using the underlying script engine.</td></tr><tr><td>()</td><td>n/a</td><td>grouping in Xpath</td></tr></tbody></table>

XPath has a lot more to offer (Location pathes in not abbreviated syntax, operators and functions) than listed here. Moreover there is a remarkable difference how the subscript operator works in Xpath and JSONPath.

-   Square brackets in XPath expressions always operate on the _node set_ resulting from the previous path fragment. Indices always start by 1.
-   With JSONPath square brackets operate on the _object_ or _array_ addressed by the previous path fragment. Indices always start by 0.

#### |2007-08-18| e3 [#](https://goessner.net/articles/JsonPath/index.html#e3 "permanent link") JSONPath examples

Let's practice JSONPath expressions by some more examples. We start with a simple JSON structure built after an XML example representing a bookstore (original [XML file](http://coli.lili.uni-bielefeld.de/~andreas/Seminare/sommer02/books.xml)).

```
{ "store": {
    "book": [ 
      { "category": "reference",
        "author": "Nigel Rees",
        "title": "Sayings of the Century",
        "price": 8.95
      },
      { "category": "fiction",
        "author": "Evelyn Waugh",
        "title": "Sword of Honour",
        "price": 12.99
      },
      { "category": "fiction",
        "author": "Herman Melville",
        "title": "Moby Dick",
        "isbn": "0-553-21311-3",
        "price": 8.99
      },
      { "category": "fiction",
        "author": "J. R. R. Tolkien",
        "title": "The Lord of the Rings",
        "isbn": "0-395-19395-8",
        "price": 22.99
      }
    ],
    "bicycle": {
      "color": "red",
      "price": 19.95
    }
  }
}
```

<table><tbody><tr><td><strong>XPath</strong></td><td><strong>JSONPath</strong></td><td><strong>Result</strong></td></tr><tr><td><code>/store/book/author</code></td><td><code>$.store.book[*].author</code></td><td>the authors of all books in the store</td></tr><tr><td><code>//author</code></td><td><code>$..author</code></td><td>all authors</td></tr><tr><td><code>/store/*</code></td><td><code>$.store.*</code></td><td>all things in store, which are some books and a red bicycle.</td></tr><tr><td><code>/store//price</code></td><td><code>$.store..price</code></td><td>the price of everything in the store.</td></tr><tr><td><code>//book[3]</code></td><td><code>$..book[2]</code></td><td>the third book</td></tr><tr><td><code>//book[last()]</code></td><td><code>$..book[(@.length-1)]</code><br><code>$..book[-1:]</code></td><td>the last book in order.</td></tr><tr><td><code>//book[position()&lt;3]</code></td><td><code>$..book[0,1]</code><br><code>$..book[:2]</code></td><td>the first two books</td></tr><tr><td><code>//book[isbn]</code></td><td><code>$..book[?(@.isbn)]</code></td><td>filter all books with isbn number</td></tr><tr><td><code>//book[price&lt;10]</code></td><td><code>$..book[?(@.price&lt;10)]</code></td><td>filter all books cheapier than 10</td></tr><tr><td><code>//*</code></td><td><code>$..*</code></td><td>all Elements in XML document. All members of JSON structure.</td></tr></tbody></table>

#### |2007-08-22| e4 [#](https://goessner.net/articles/JsonPath/index.html#e4 "permanent link") JSONPath implementation

JSONPath is implemented in Javascript for clientside usage and ported over to PHP for use on the server.

### Usage

All you need to do is downloading either of the files

-   [jsonpath.js](http://code.google.com/p/jsonpath/)
-   [jsonpath.php](http://code.google.com/p/jsonpath/)

include it in your program and use the simple API consisting of one single function.

`jsonPath(obj, expr [, args])`

**parameters:**

`obj (object|array)`:

Object representing the JSON structure.

`expr (string)`:

JSONPath expression string.

`args (object|undefined)`:

Object controlling path evaluation and output. Currently only one member is supported.

`args.resultType ("VALUE"|"PATH")`:

causes the result to be either matching values _(default)_ or normalized path expressions.

**return value:**

`(array|false)`:

Array holding either values or normalized path expressions matching the input path expression, which can be used for lazy evaluation. `false` in case of no match.

**Javascript Example**:

```
var o = { /*...*/ },  // the 'store' JSON object from above
    res1 = jsonPath(o, "$..author").toJSONString(),
    res2 = jsonPath(o, "$..author", {resultType:"PATH"}).toJSONString();
```

**PHP example**:

We need here to convert the JSON string to a PHP array first. I am using [Michal Migurski](http://mike.teczno.com/)'s [JSON parser](http://mike.teczno.com/json.html) for that.

```
require_once('json.php');      // JSON parser
require_once('jsonpath.php');  // JSONPath evaluator

$json = '{ ... }';  // JSON structure from above

$parser = new Services_JSON(SERVICES_JSON_LOOSE_TYPE);
$o = $parser->decode($json);
$match1 = jsonPath($o, "$..author");
$match2 = jsonPath($o, "$..author", array("resultType" => "PATH"));
$res1 = $parser->encode($match1);
$res2 = $parser->encode($match2);
```

**results**

Both _Javascript_ and _PHP_ example result in the following JSON arrays (as strings):

```
res1:
[ "Nigel Rees",
  "Evelyn Waugh",
  "Herman Melville",
  "J. R. R. Tolkien"
]
res2:
[ "$['store']['book'][0]['author']",
  "$['store']['book'][1]['author']",
  "$['store']['book'][2]['author']",
  "$['store']['book'][3]['author']"
]
```

Please note, that the return value of `jsonPath` is an array, which is also a valid JSON structure. So you might want to apply `jsonPath` to the resulting structure again or use one of your favorite array methods as `sort` with it.

#### |2007-08-24| e5 [#](https://goessner.net/articles/JsonPath/index.html#e5 "permanent link") Issues

-   Currently only single quotes allowed inside of JSONPath expressions.
-   Script expressions inside of JSONPath locations are currently not recursively evaluated by `jsonPath`. Only the global `$` and local `@` symbols are expanded by a simple regular expression.
-   An alternative for `jsonPath` to return `false` in case of _no match_ may be to return an empty array in future.
