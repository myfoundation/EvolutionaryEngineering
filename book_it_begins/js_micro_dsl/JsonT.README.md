---
created: 2026-06-06T00:37:48 (UTC +03:00)
tags: []
source: https://goessner.net/articles/jsont/
author: 
---

# JsonT - Transforming Json

> ## Excerpt
> JSON is a lightweight text format for data interchange. It is often better suited for structured data than XML.

---
#### |2006-01-30| e1 [#](https://goessner.net/articles/jsont/index.html#1 "permanent link") Transforming JSON

[JSON](http://json.org/) is a lightweight text format for data interchange. It is often better suited for structured data than XML.

A frequently requested task with JSON data is its transformation to other formats, especially to XML or HTML for further processing.

The most obvious way to achive this, is to use a programming language _(ECMAscript, Ruby,…)_ and the DOM-API.

In XML we can transform documents by another XML document containing transformation rules _(XSLT)_ and applying these rules using an XSLT-processor.

Adopting that concept I have been experimenting with a set of transformation rules _(written in JSON)_.

As a result in analogy to XML/XSLT the combination JSON/JSONT can be used to transform JSON data into any other format by applying a specific set of rules.

#### |2006-01-30| e2 [#](https://goessner.net/articles/jsont/index.html#2 "permanent link") Introducing JSONT

Let's start with a simple JSON object

```
{ "link": {"uri":"http://company.com", "title":"company homepage" }}
```

which we want to transform into a HTML link element.

```
<a href="http://company.com">company homepage</a>
```

For doing this we can write a corresponding rule

```
{ "link": "<a href=\"{link.uri}\">{link.title}</a>" }
```

and using a processor like `jsonT(data, rules)` we can apply the given rule to the JSON data resulting in the output string above.

#### |2006-01-30| e3 [#](https://goessner.net/articles/jsont/index.html#3 "permanent link") Basic Rules

A set of transformation rules is written using the object literal notation. So each rule is a name/value pair. The rule name usually is an expression for accessing an object member. The rule value is either a string or a function with a single argument, which are evaluated at transformation time.

_"name": "transformation string"_  
_"name": function(arg){ … }_

The transformation string itself can contain one or more expressions enclosed in curly braces

_{expr}_

which always resolve to a string value.

-   If _expr_ references a _rule name_, it results in either the _transformation string_ or the return value of the implicit _transformation function_ of that rule.
-   If _expr_ evaluates to a primitive data type, its value is converted to a string.
-   If _expr_ evaluates to an array/object, each array element/object member is processed accordingly.
-   The shortcut _$_ as part of the _expr_ is substituted by the _rule name_.
-   If _expr_ has the explicit form _@name(expr)_, the function belonging to the rule _name_ is called and its return value is converted to a string.

The outer JSON object can be accessed using the keyword _self_.

Rule names for array elements use the syntax _name\[\*\]_. When using the _$_ shortcut in _transformation string_, the '\*' resolves to the actual array index.

Object members, which have no transformation rule assigned and are not directly or indirectly referenced, as well as expressions evaluating to _undefined_ don't create output.

#### |2006-01-31| e4 [#](https://goessner.net/articles/jsont/index.html#4 "permanent link") Some examples

### vector geometry

```
{ "line": { "p1": {"x":2, "y":3},
            "p2": {"x":4, "y":5} }}
```

+

```
{ "self": "<svg>{line}</svg>",
  "line": "<line x1=\"{$.p1.x}\" y1=\"{$.p1.y}\"" +
                "x2=\"{$.p2.x}\" y2=\"{$.p2.y}\" />" }
```

\=

```
<svg><line x1="2" y1="3"x2="4" y2="5" /></svg>
```

### simple array

```
["red", "green", "blue"]
```

+

```
["self": "<ul>\n{$}</ul>",
 "self[*]": "  <li>{$}</li>\n"]
```

\=

```
<ul>
  <li>red</li>
  <li>green</li>
  <li>blue</li>
</ul>
```

### two-dimensional array and implicit function rule

```
{ "color": "blue",
  "closed": true,
  "points": [[10,10],[20,10],[20,20],[10,20]] }
```

+

```
{ "self": "<svg><{closed} stroke=\"{color}\" points=\"{points}\" />"+
          "</svg>",
  "closed": function(x){return x ? "polygon" : "polyline";}, 
  "points[*][*]": "{$} " }
```

\=

```
<svg><polygon stroke="blue" points="10 10 20 10 20 20 10 20 " /></svg>
```
