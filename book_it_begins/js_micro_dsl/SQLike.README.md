

# SQLike, version 1.02, demo &amp; short reference

http://www.thomasfrank.se/SQLike/

Keywords are case-insensitive and insensitive to underscores. This means **GroupBy** can be written **GROUP\_BY** , **groupby** etc. **Where** clauses are written as functions. You can also use a function instead of a field name in **Select** and **Set** statements. In these functions the **this** -keyword points to the current row.

**Please note:**
- The queries below are run in sequence.
- The test data is random generated and differs each time you load this page.
- JavaScript debuggers (like Firebug) can slow down SQLike [JavaScript].

**SQLike, version 1.02, demo &amp; short reference**         1

**Some test data: dataArray**         2

**More test data: dataArray2**         2

**Unpack**         3

**Select (+ order by)**        4

**Select, example 2 (using &quot;as&quot; and a function instead of a field name)**        4

**Select Distinct**         5

**Group By (+ aggregate functions)**        6

**Join (implicit)**        6

**Join**         7

**Join Using**         7

**Natural Join**         8

**Left Join**         8

**Right Join**         9

**Full Join**         10

**Cross Join (+ use of &quot;limit&quot;)**        11

**Union**         13

**Union All**         14

**Intersect**         15

**Intersect All**         16

**Except**         16

**Except All**         17

**Update**         18

**Insert into**         18

**Select into**         19

**Delete from**         20

**Pack**         21

## [Some test data: dataArray](javascript:showHideExi(0);void(0))

This is the first part of our test data that we store in an array called &quot;dataArray&quot; (an array of arrays until it is unpacked, see below).

| 0 | 1 | 2 | 3 |
| --- | --- | --- | --- |
| Susanna | Peterson | 55 | 66000 |
| Anette | Irons | 26 | 31000 |
| Anette | Steele | 62 | 72000 |
| Anette | Steele | 50 | 70000 |
| John | Green | 27 | 80000 |
| Debbi | Jones | 58 | 93000 |
| George | Green | 63 | 40000 |
| Anette | Jones | 22 | 76000 |
| Susanna | Black | 58 | 52000 |
| Debbi | Jones | 44 | 54000 |

**JSON** :

[[&quot;Susanna&quot;, &quot;Peterson&quot;, 55, 66000], [&quot;Anette&quot;, &quot;Irons&quot;, 26, 31000], [&quot;Anette&quot;, &quot;Steele&quot;, 62, 72000], [&quot;Anette&quot;, &quot;Steele&quot;, 50, 70000], [&quot;John&quot;, &quot;Green&quot;, 27, 80000], [&quot;Debbi&quot;, &quot;Jones&quot;, 58, 93000], [&quot;George&quot;, &quot;Green&quot;, 63, 40000], [&quot;Anette&quot;, &quot;Jones&quot;, 22, 76000], [&quot;Susanna&quot;, &quot;Black&quot;, 58, 52000], [&quot;Debbi&quot;, &quot;Jones&quot;, 44, 54000]]

Rows: 10

## [More test data: dataArray2](javascript:showHideExi(1);void(0))

This is the second part of our test data that we store in an array called &quot;dataArray2&quot; (an array of objects).

| firstName | lastName | favColor |
| --- | --- | --- |
| Susanna | Peterson | green |
| Anette | Irons | green |
| Strange | Mike | red |

**JSON** :

[{&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Peterson&quot;, &quot;favColor&quot;:&quot;green&quot;}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Irons&quot;, &quot;favColor&quot;:&quot;green&quot;}, {&quot;firstName&quot;:&quot;Strange&quot;, &quot;lastName&quot;:&quot;Mike&quot;, &quot;favColor&quot;:&quot;red&quot;}]

Rows: 3

## [Unpack](javascript:showHideExi(2);void(0))

If your data is an array of arrays you need to unpack it into an array of objects, before querying it.

**Please note:** Unpack changes the orginal array.

SQLike.q(
   {
       Unpack: dataArray,
       Columns: [&#39;firstName&#39;,&#39;lastName&#39;,&#39;age&#39;,&#39;salary&#39;]
   }
)

| firstName | lastName | age | salary |
| --- | --- | --- | --- |
| Susanna | Peterson | 55 | 66000 |
| Anette | Irons | 26 | 31000 |
| Anette | Steele | 62 | 72000 |
| Anette | Steele | 50 | 70000 |
| John | Green | 27 | 80000 |
| Debbi | Jones | 58 | 93000 |
| George | Green | 63 | 40000 |
| Anette | Jones | 22 | 76000 |
| Susanna | Black | 58 | 52000 |
| Debbi | Jones | 44 | 54000 |

**JSON** :

[{&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Peterson&quot;, &quot;age&quot;:55, &quot;salary&quot;:66000}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Irons&quot;, &quot;age&quot;:26, &quot;salary&quot;:31000}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Steele&quot;, &quot;age&quot;:62, &quot;salary&quot;:72000}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Steele&quot;, &quot;age&quot;:50, &quot;salary&quot;:70000}, {&quot;firstName&quot;:&quot;John&quot;, &quot;lastName&quot;:&quot;Green&quot;, &quot;age&quot;:27, &quot;salary&quot;:80000}, {&quot;firstName&quot;:&quot;Debbi&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:58, &quot;salary&quot;:93000}, {&quot;firstName&quot;:&quot;George&quot;, &quot;lastName&quot;:&quot;Green&quot;, &quot;age&quot;:63, &quot;salary&quot;:40000}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:22, &quot;salary&quot;:76000}, {&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Black&quot;, &quot;age&quot;:58, &quot;salary&quot;:52000}, {&quot;firstName&quot;:&quot;Debbi&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:44, &quot;salary&quot;:54000}]

Rows: 10   Time taken:   JS 31 ms

## [**Select**](javascript:showHideExi(3);void(0)) [**(+ order by)**](javascript:showHideExi(3);void(0))

Selecting tuples where the salary&gt;50000.
Note that the where condition is in the form of a function that returns true or false. Also note the syntax &quot;|desc|&quot; for sorting in descending order.

SQLike.q(
   {
       Select: [&#39;\*&#39;],
       From: dataArray,
       Where: function(){return this.salary&gt;50000},
       OrderBy: [&#39;salary&#39;,&#39;|desc|&#39;]
   }
)

| firstName | lastName | age | salary |
| --- | --- | --- | --- |
| Debbi | Jones | 58 | 93000 |
| John | Green | 27 | 80000 |
| Anette | Jones | 22 | 76000 |
| Anette | Steele | 62 | 72000 |
| Anette | Steele | 50 | 70000 |
| Susanna | Peterson | 55 | 66000 |
| Debbi | Jones | 44 | 54000 |
| Susanna | Black | 58 | 52000 |

**JSON** :

[{&quot;firstName&quot;:&quot;Debbi&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:58, &quot;salary&quot;:93000}, {&quot;firstName&quot;:&quot;John&quot;, &quot;lastName&quot;:&quot;Green&quot;, &quot;age&quot;:27, &quot;salary&quot;:80000}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:22, &quot;salary&quot;:76000}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Steele&quot;, &quot;age&quot;:62, &quot;salary&quot;:72000}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Steele&quot;, &quot;age&quot;:50, &quot;salary&quot;:70000}, {&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Peterson&quot;, &quot;age&quot;:55, &quot;salary&quot;:66000}, {&quot;firstName&quot;:&quot;Debbi&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:44, &quot;salary&quot;:54000}, {&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Black&quot;, &quot;age&quot;:58, &quot;salary&quot;:52000}]

Rows: 8   Time taken:   JS 2 ms

## [**Select, example 2**](javascript:showHideExi(4);void(0)) [**(using &quot;as&quot; and a function instead of a field name)**](javascript:showHideExi(4);void(0))

Still selecting tuples where the salary&gt;50000.
Note the use of a function in the select statement as well as the use of &quot;|as|&quot;.

SQLike.q(
   {
       Select: [function(){return this.firstName+&quot; &quot;+this.lastName},&#39;|as|&#39;,&#39;name&#39;],
       From: dataArray,
       Where: function(){return this.salary&gt;50000},
       OrderBy: [&#39;salary&#39;,&#39;|desc|&#39;]
   }
)

| name |
| --- |
| Debbi Jones |
| John Green |
| Anette Jones |
| Anette Steele |
| Anette Steele |
| Susanna Peterson |
| Debbi Jones |
| Susanna Black |

**JSON** :

[{&quot;name&quot;:&quot;Debbi Jones&quot;}, {&quot;name&quot;:&quot;John Green&quot;}, {&quot;name&quot;:&quot;Anette Jones&quot;}, {&quot;name&quot;:&quot;Anette Steele&quot;}, {&quot;name&quot;:&quot;Anette Steele&quot;}, {&quot;name&quot;:&quot;Susanna Peterson&quot;}, {&quot;name&quot;:&quot;Debbi Jones&quot;}, {&quot;name&quot;:&quot;Susanna Black&quot;}]

Rows: 8   Time taken:   JS 2 ms

## [Select Distinct](javascript:showHideExi(5);void(0))

Selecting distinct first names.

SQLike.q(
    {
        SelectDistinct: [&#39;firstName&#39;],
        From: dataArray,
        OrderBy: [&#39;firstName&#39;]
    }
)

| firstName |
| --- |
| Anette |
| Debbi |
| George |
| John |
| Susanna |

**JSON** :

[{&quot;firstName&quot;:&quot;Anette&quot;}, {&quot;firstName&quot;:&quot;Debbi&quot;}, {&quot;firstName&quot;:&quot;George&quot;}, {&quot;firstName&quot;:&quot;John&quot;}, {&quot;firstName&quot;:&quot;Susanna&quot;}]

Rows: 5   Time taken:   JS 2 ms

## [**Group By**](javascript:showHideExi(6);void(0)) [**(+ aggregate functions)**](javascript:showHideExi(6);void(0))

SQLike.q(
    {
        Select: [&#39;firstName&#39;,&#39;|count|&#39;,&#39;firstName&#39;,&#39;|sum|&#39;,&#39;salary&#39;,&#39;|min|&#39;,&#39;salary&#39;,&#39;|max|&#39;,&#39;salary&#39;,&#39;|avg|&#39;,&#39;salary&#39;],
        From: dataArray,
        GroupBy: [&#39;firstName&#39;],
        Having: function(){return this.count\_firstName&gt;1},
        OrderBy: [&#39;sum\_salary&#39;,&#39;|desc|&#39;]
   }
)

| firstName | count\_firstName | sum\_salary | min\_salary | max\_salary | avg\_salary |
| --- | --- | --- | --- | --- | --- |
| Anette | 4 | 249000 | 31000 | 76000 | 62250 |
| Debbi | 2 | 147000 | 54000 | 93000 | 73500 |
| Susanna | 2 | 118000 | 52000 | 66000 | 59000 |

**JSON** :

[{&quot;firstName&quot;:&quot;Anette&quot;, &quot;count\_firstName&quot;:4, &quot;sum\_salary&quot;:249000, &quot;min\_salary&quot;:31000, &quot;max\_salary&quot;:76000, &quot;avg\_salary&quot;:62250}, {&quot;firstName&quot;:&quot;Debbi&quot;, &quot;count\_firstName&quot;:2, &quot;sum\_salary&quot;:147000, &quot;min\_salary&quot;:54000, &quot;max\_salary&quot;:93000, &quot;avg\_salary&quot;:73500}, {&quot;firstName&quot;:&quot;Susanna&quot;, &quot;count\_firstName&quot;:2, &quot;sum\_salary&quot;:118000, &quot;min\_salary&quot;:52000, &quot;max\_salary&quot;:66000, &quot;avg\_salary&quot;:59000}]

Rows: 3   Time taken:   JS 2 ms

## [Join (implicit)](javascript:showHideExi(7);void(0))

SQLike.q(
   {
       Select: [&#39;\*&#39;],
       From: {t1:dataArray,t2:dataArray2},
       Where: function(){return this.t1.firstName==this.t2.firstName &amp;&amp; this.t1.lastName==this.t2.lastName}
   }
)

| t1\_firstName | t1\_lastName | t1\_age | t1\_salary | t2\_firstName | t2\_lastName | t2\_favColor |
| --- | --- | --- | --- | --- | --- | --- |
| Susanna | Peterson | 55 | 66000 | Susanna | Peterson | green |
| Anette | Irons | 26 | 31000 | Anette | Irons | green |

**JSON** :

[{&quot;t1\_firstName&quot;:&quot;Susanna&quot;, &quot;t1\_lastName&quot;:&quot;Peterson&quot;, &quot;t1\_age&quot;:55, &quot;t1\_salary&quot;:66000, &quot;t2\_firstName&quot;:&quot;Susanna&quot;, &quot;t2\_lastName&quot;:&quot;Peterson&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Irons&quot;, &quot;t1\_age&quot;:26, &quot;t1\_salary&quot;:31000, &quot;t2\_firstName&quot;:&quot;Anette&quot;, &quot;t2\_lastName&quot;:&quot;Irons&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}]

Rows: 2   Time taken:   JS 3 ms

## [Join](javascript:showHideExi(8);void(0))

SQLike.q(
   {
       Select: [&#39;\*&#39;],
       From: {t1:dataArray},
       Join: {t2:dataArray2},
       On: function(){return this.t1.firstName==this.t2.firstName &amp;&amp; this.t1.lastName==this.t2.lastName}
   }
)

| t1\_firstName | t1\_lastName | t1\_age | t1\_salary | t2\_firstName | t2\_lastName | t2\_favColor |
| --- | --- | --- | --- | --- | --- | --- |
| Susanna | Peterson | 55 | 66000 | Susanna | Peterson | green |
| Anette | Irons | 26 | 31000 | Anette | Irons | green |

**JSON** :

[{&quot;t1\_firstName&quot;:&quot;Susanna&quot;, &quot;t1\_lastName&quot;:&quot;Peterson&quot;, &quot;t1\_age&quot;:55, &quot;t1\_salary&quot;:66000, &quot;t2\_firstName&quot;:&quot;Susanna&quot;, &quot;t2\_lastName&quot;:&quot;Peterson&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Irons&quot;, &quot;t1\_age&quot;:26, &quot;t1\_salary&quot;:31000, &quot;t2\_firstName&quot;:&quot;Anette&quot;, &quot;t2\_lastName&quot;:&quot;Irons&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}]

Rows: 2   Time taken:   JS 2 ms

## [Join Using](javascript:showHideExi(9);void(0))

SQLike.q(
   {
       Select: [&#39;\*&#39;],
       From: {t1:dataArray},
       Join: {t2:dataArray2},
       Using: [&#39;firstName&#39;,&#39;lastName&#39;]
   }
)

| firstName | lastName | t1\_age | t1\_salary | t2\_favColor |
| --- | --- | --- | --- | --- |
| Susanna | Peterson | 55 | 66000 | green |
| Anette | Irons | 26 | 31000 | green |

**JSON** :

[{&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Peterson&quot;, &quot;t1\_age&quot;:55, &quot;t1\_salary&quot;:66000, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Irons&quot;, &quot;t1\_age&quot;:26, &quot;t1\_salary&quot;:31000, &quot;t2\_favColor&quot;:&quot;green&quot;}]

Rows: 2   Time taken:   JS 1 ms

## [Natural Join](javascript:showHideExi(10);void(0))

SQLike.q(
   {
       Select: [&#39;\*&#39;],
       From: {t1:dataArray},
       NaturalJoin: {t2:dataArray2},
       Where:function(){return this.t1.firstName!=&#39;Vicki&#39;}
   }
)

| firstName | lastName | t1\_age | t1\_salary | t2\_favColor |
| --- | --- | --- | --- | --- |
| Susanna | Peterson | 55 | 66000 | green |
| Anette | Irons | 26 | 31000 | green |

**JSON** :

[{&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Peterson&quot;, &quot;t1\_age&quot;:55, &quot;t1\_salary&quot;:66000, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Irons&quot;, &quot;t1\_age&quot;:26, &quot;t1\_salary&quot;:31000, &quot;t2\_favColor&quot;:&quot;green&quot;}]

Rows: 2   Time taken:   JS 0 ms

## [Left Join](javascript:showHideExi(11);void(0))

Same as LeftOuterJoin.

SQLike.q(
   {
       Select: [&#39;\*&#39;],
       From: {t1:dataArray},
       LeftJoin: {t2:dataArray2},
       On: function(){return this.t1.firstName==this.t2.firstName &amp;&amp; this.t1.lastName==this.t2.lastName}
   }
)

| t1\_firstName | t1\_lastName | t1\_age | t1\_salary | t2\_firstName | t2\_lastName | t2\_favColor |
| --- | --- | --- | --- | --- | --- | --- |
| Susanna | Peterson | 55 | 66000 | Susanna | Peterson | green |
| Anette | Irons | 26 | 31000 | Anette | Irons | green |
| Anette | Steele | 62 | 72000 | undefined | undefined | undefined |
| Anette | Steele | 50 | 70000 | undefined | undefined | undefined |
| John | Green | 27 | 80000 | undefined | undefined | undefined |
| Debbi | Jones | 58 | 93000 | undefined | undefined | undefined |
| George | Green | 63 | 40000 | undefined | undefined | undefined |
| Anette | Jones | 22 | 76000 | undefined | undefined | undefined |
| Susanna | Black | 58 | 52000 | undefined | undefined | undefined |
| Debbi | Jones | 44 | 54000 | undefined | undefined | undefined |

**JSON** :

[{&quot;t1\_firstName&quot;:&quot;Susanna&quot;, &quot;t1\_lastName&quot;:&quot;Peterson&quot;, &quot;t1\_age&quot;:55, &quot;t1\_salary&quot;:66000, &quot;t2\_firstName&quot;:&quot;Susanna&quot;, &quot;t2\_lastName&quot;:&quot;Peterson&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Irons&quot;, &quot;t1\_age&quot;:26, &quot;t1\_salary&quot;:31000, &quot;t2\_firstName&quot;:&quot;Anette&quot;, &quot;t2\_lastName&quot;:&quot;Irons&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Steele&quot;, &quot;t1\_age&quot;:62, &quot;t1\_salary&quot;:72000}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Steele&quot;, &quot;t1\_age&quot;:50, &quot;t1\_salary&quot;:70000}, {&quot;t1\_firstName&quot;:&quot;John&quot;, &quot;t1\_lastName&quot;:&quot;Green&quot;, &quot;t1\_age&quot;:27, &quot;t1\_salary&quot;:80000}, {&quot;t1\_firstName&quot;:&quot;Debbi&quot;, &quot;t1\_lastName&quot;:&quot;Jones&quot;, &quot;t1\_age&quot;:58, &quot;t1\_salary&quot;:93000}, {&quot;t1\_firstName&quot;:&quot;George&quot;, &quot;t1\_lastName&quot;:&quot;Green&quot;, &quot;t1\_age&quot;:63, &quot;t1\_salary&quot;:40000}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Jones&quot;, &quot;t1\_age&quot;:22, &quot;t1\_salary&quot;:76000}, {&quot;t1\_firstName&quot;:&quot;Susanna&quot;, &quot;t1\_lastName&quot;:&quot;Black&quot;, &quot;t1\_age&quot;:58, &quot;t1\_salary&quot;:52000}, {&quot;t1\_firstName&quot;:&quot;Debbi&quot;, &quot;t1\_lastName&quot;:&quot;Jones&quot;, &quot;t1\_age&quot;:44, &quot;t1\_salary&quot;:54000}]

Rows: 10   Time taken:   JS 2 ms

## [Right Join](javascript:showHideExi(12);void(0))

Same as RightOuterJoin.

SQLike.q(
   {
       Select: [&#39;\*&#39;],
       From: {t1:dataArray},
       RightJoin: {t2:dataArray2},
       On: function(){return this.t1.firstName==this.t2.firstName &amp;&amp; this.t1.lastName==this.t2.lastName}
   }
)

| t1\_firstName | t1\_lastName | t1\_age | t1\_salary | t2\_firstName | t2\_lastName | t2\_favColor |
| --- | --- | --- | --- | --- | --- | --- |
| Susanna | Peterson | 55 | 66000 | Susanna | Peterson | green |
| Anette | Irons | 26 | 31000 | Anette | Irons | green |
| undefined | undefined | undefined | undefined | Strange | Mike | red |

**JSON** :

[{&quot;t1\_firstName&quot;:&quot;Susanna&quot;, &quot;t1\_lastName&quot;:&quot;Peterson&quot;, &quot;t1\_age&quot;:55, &quot;t1\_salary&quot;:66000, &quot;t2\_firstName&quot;:&quot;Susanna&quot;, &quot;t2\_lastName&quot;:&quot;Peterson&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Irons&quot;, &quot;t1\_age&quot;:26, &quot;t1\_salary&quot;:31000, &quot;t2\_firstName&quot;:&quot;Anette&quot;, &quot;t2\_lastName&quot;:&quot;Irons&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t2\_firstName&quot;:&quot;Strange&quot;, &quot;t2\_lastName&quot;:&quot;Mike&quot;, &quot;t2\_favColor&quot;:&quot;red&quot;}]

Rows: 3   Time taken:   JS 3 ms

## [Full Join](javascript:showHideExi(13);void(0))

Same as FullOuterJoin.

SQLike.q(
   {
       Select: [&#39;\*&#39;],
       From: {t1:dataArray},
       FullJoin: {t2:dataArray2},
       On: function(){return this.t1.firstName==this.t2.firstName &amp;&amp; this.t1.lastName==this.t2.lastName},
       Where:function(){return this.t1.firstName!=&quot;George&quot;}
   }
)

| t1\_firstName | t1\_lastName | t1\_age | t1\_salary | t2\_firstName | t2\_lastName | t2\_favColor |
| --- | --- | --- | --- | --- | --- | --- |
| Susanna | Peterson | 55 | 66000 | Susanna | Peterson | green |
| Anette | Irons | 26 | 31000 | Anette | Irons | green |
| Anette | Steele | 62 | 72000 | undefined | undefined | undefined |
| Anette | Steele | 50 | 70000 | undefined | undefined | undefined |
| John | Green | 27 | 80000 | undefined | undefined | undefined |
| Debbi | Jones | 58 | 93000 | undefined | undefined | undefined |
| Anette | Jones | 22 | 76000 | undefined | undefined | undefined |
| Susanna | Black | 58 | 52000 | undefined | undefined | undefined |
| Debbi | Jones | 44 | 54000 | undefined | undefined | undefined |
| undefined | undefined | undefined | undefined | Strange | Mike | red |

**JSON** :

[{&quot;t1\_firstName&quot;:&quot;Susanna&quot;, &quot;t1\_lastName&quot;:&quot;Peterson&quot;, &quot;t1\_age&quot;:55, &quot;t1\_salary&quot;:66000, &quot;t2\_firstName&quot;:&quot;Susanna&quot;, &quot;t2\_lastName&quot;:&quot;Peterson&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Irons&quot;, &quot;t1\_age&quot;:26, &quot;t1\_salary&quot;:31000, &quot;t2\_firstName&quot;:&quot;Anette&quot;, &quot;t2\_lastName&quot;:&quot;Irons&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Steele&quot;, &quot;t1\_age&quot;:62, &quot;t1\_salary&quot;:72000}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Steele&quot;, &quot;t1\_age&quot;:50, &quot;t1\_salary&quot;:70000}, {&quot;t1\_firstName&quot;:&quot;John&quot;, &quot;t1\_lastName&quot;:&quot;Green&quot;, &quot;t1\_age&quot;:27, &quot;t1\_salary&quot;:80000}, {&quot;t1\_firstName&quot;:&quot;Debbi&quot;, &quot;t1\_lastName&quot;:&quot;Jones&quot;, &quot;t1\_age&quot;:58, &quot;t1\_salary&quot;:93000}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Jones&quot;, &quot;t1\_age&quot;:22, &quot;t1\_salary&quot;:76000}, {&quot;t1\_firstName&quot;:&quot;Susanna&quot;, &quot;t1\_lastName&quot;:&quot;Black&quot;, &quot;t1\_age&quot;:58, &quot;t1\_salary&quot;:52000}, {&quot;t1\_firstName&quot;:&quot;Debbi&quot;, &quot;t1\_lastName&quot;:&quot;Jones&quot;, &quot;t1\_age&quot;:44, &quot;t1\_salary&quot;:54000}, {&quot;t2\_firstName&quot;:&quot;Strange&quot;, &quot;t2\_lastName&quot;:&quot;Mike&quot;, &quot;t2\_favColor&quot;:&quot;red&quot;}]

Rows: 10   Time taken:   JS 1 ms

## [**Cross Join**](javascript:showHideExi(14);void(0)) [**(+ use of &quot;limit&quot;)**](javascript:showHideExi(14);void(0))

SQLike.q(
   {
       Select: [&#39;\*&#39;],
       From: {t1:dataArray},
       CrossJoin: {t2:dataArray2},
       Limit: 100
   }
)

| t1\_firstName | t1\_lastName | t1\_age | t1\_salary | t2\_firstName | t2\_lastName | t2\_favColor |
| --- | --- | --- | --- | --- | --- | --- |
| Susanna | Peterson | 55 | 66000 | Susanna | Peterson | green |
| Anette | Irons | 26 | 31000 | Susanna | Peterson | green |
| Anette | Steele | 62 | 72000 | Susanna | Peterson | green |
| Anette | Steele | 50 | 70000 | Susanna | Peterson | green |
| John | Green | 27 | 80000 | Susanna | Peterson | green |
| Debbi | Jones | 58 | 93000 | Susanna | Peterson | green |
| George | Green | 63 | 40000 | Susanna | Peterson | green |
| Anette | Jones | 22 | 76000 | Susanna | Peterson | green |
| Susanna | Black | 58 | 52000 | Susanna | Peterson | green |
| Debbi | Jones | 44 | 54000 | Susanna | Peterson | green |
| Susanna | Peterson | 55 | 66000 | Anette | Irons | green |
| Anette | Irons | 26 | 31000 | Anette | Irons | green |
| Anette | Steele | 62 | 72000 | Anette | Irons | green |
| Anette | Steele | 50 | 70000 | Anette | Irons | green |
| John | Green | 27 | 80000 | Anette | Irons | green |
| Debbi | Jones | 58 | 93000 | Anette | Irons | green |
| George | Green | 63 | 40000 | Anette | Irons | green |
| Anette | Jones | 22 | 76000 | Anette | Irons | green |
| Susanna | Black | 58 | 52000 | Anette | Irons | green |
| Debbi | Jones | 44 | 54000 | Anette | Irons | green |
| Susanna | Peterson | 55 | 66000 | Strange | Mike | red |
| Anette | Irons | 26 | 31000 | Strange | Mike | red |
| Anette | Steele | 62 | 72000 | Strange | Mike | red |
| Anette | Steele | 50 | 70000 | Strange | Mike | red |
| John | Green | 27 | 80000 | Strange | Mike | red |
| Debbi | Jones | 58 | 93000 | Strange | Mike | red |
| George | Green | 63 | 40000 | Strange | Mike | red |
| Anette | Jones | 22 | 76000 | Strange | Mike | red |
| Susanna | Black | 58 | 52000 | Strange | Mike | red |
| Debbi | Jones | 44 | 54000 | Strange | Mike | red |

**JSON** :

[{&quot;t1\_firstName&quot;:&quot;Susanna&quot;, &quot;t1\_lastName&quot;:&quot;Peterson&quot;, &quot;t1\_age&quot;:55, &quot;t1\_salary&quot;:66000, &quot;t2\_firstName&quot;:&quot;Susanna&quot;, &quot;t2\_lastName&quot;:&quot;Peterson&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Irons&quot;, &quot;t1\_age&quot;:26, &quot;t1\_salary&quot;:31000, &quot;t2\_firstName&quot;:&quot;Susanna&quot;, &quot;t2\_lastName&quot;:&quot;Peterson&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Steele&quot;, &quot;t1\_age&quot;:62, &quot;t1\_salary&quot;:72000, &quot;t2\_firstName&quot;:&quot;Susanna&quot;, &quot;t2\_lastName&quot;:&quot;Peterson&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Steele&quot;, &quot;t1\_age&quot;:50, &quot;t1\_salary&quot;:70000, &quot;t2\_firstName&quot;:&quot;Susanna&quot;, &quot;t2\_lastName&quot;:&quot;Peterson&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;John&quot;, &quot;t1\_lastName&quot;:&quot;Green&quot;, &quot;t1\_age&quot;:27, &quot;t1\_salary&quot;:80000, &quot;t2\_firstName&quot;:&quot;Susanna&quot;, &quot;t2\_lastName&quot;:&quot;Peterson&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Debbi&quot;, &quot;t1\_lastName&quot;:&quot;Jones&quot;, &quot;t1\_age&quot;:58, &quot;t1\_salary&quot;:93000, &quot;t2\_firstName&quot;:&quot;Susanna&quot;, &quot;t2\_lastName&quot;:&quot;Peterson&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;George&quot;, &quot;t1\_lastName&quot;:&quot;Green&quot;, &quot;t1\_age&quot;:63, &quot;t1\_salary&quot;:40000, &quot;t2\_firstName&quot;:&quot;Susanna&quot;, &quot;t2\_lastName&quot;:&quot;Peterson&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Jones&quot;, &quot;t1\_age&quot;:22, &quot;t1\_salary&quot;:76000, &quot;t2\_firstName&quot;:&quot;Susanna&quot;, &quot;t2\_lastName&quot;:&quot;Peterson&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Susanna&quot;, &quot;t1\_lastName&quot;:&quot;Black&quot;, &quot;t1\_age&quot;:58, &quot;t1\_salary&quot;:52000, &quot;t2\_firstName&quot;:&quot;Susanna&quot;, &quot;t2\_lastName&quot;:&quot;Peterson&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Debbi&quot;, &quot;t1\_lastName&quot;:&quot;Jones&quot;, &quot;t1\_age&quot;:44, &quot;t1\_salary&quot;:54000, &quot;t2\_firstName&quot;:&quot;Susanna&quot;, &quot;t2\_lastName&quot;:&quot;Peterson&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Susanna&quot;, &quot;t1\_lastName&quot;:&quot;Peterson&quot;, &quot;t1\_age&quot;:55, &quot;t1\_salary&quot;:66000, &quot;t2\_firstName&quot;:&quot;Anette&quot;, &quot;t2\_lastName&quot;:&quot;Irons&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Irons&quot;, &quot;t1\_age&quot;:26, &quot;t1\_salary&quot;:31000, &quot;t2\_firstName&quot;:&quot;Anette&quot;, &quot;t2\_lastName&quot;:&quot;Irons&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Steele&quot;, &quot;t1\_age&quot;:62, &quot;t1\_salary&quot;:72000, &quot;t2\_firstName&quot;:&quot;Anette&quot;, &quot;t2\_lastName&quot;:&quot;Irons&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Steele&quot;, &quot;t1\_age&quot;:50, &quot;t1\_salary&quot;:70000, &quot;t2\_firstName&quot;:&quot;Anette&quot;, &quot;t2\_lastName&quot;:&quot;Irons&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;John&quot;, &quot;t1\_lastName&quot;:&quot;Green&quot;, &quot;t1\_age&quot;:27, &quot;t1\_salary&quot;:80000, &quot;t2\_firstName&quot;:&quot;Anette&quot;, &quot;t2\_lastName&quot;:&quot;Irons&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Debbi&quot;, &quot;t1\_lastName&quot;:&quot;Jones&quot;, &quot;t1\_age&quot;:58, &quot;t1\_salary&quot;:93000, &quot;t2\_firstName&quot;:&quot;Anette&quot;, &quot;t2\_lastName&quot;:&quot;Irons&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;George&quot;, &quot;t1\_lastName&quot;:&quot;Green&quot;, &quot;t1\_age&quot;:63, &quot;t1\_salary&quot;:40000, &quot;t2\_firstName&quot;:&quot;Anette&quot;, &quot;t2\_lastName&quot;:&quot;Irons&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Jones&quot;, &quot;t1\_age&quot;:22, &quot;t1\_salary&quot;:76000, &quot;t2\_firstName&quot;:&quot;Anette&quot;, &quot;t2\_lastName&quot;:&quot;Irons&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Susanna&quot;, &quot;t1\_lastName&quot;:&quot;Black&quot;, &quot;t1\_age&quot;:58, &quot;t1\_salary&quot;:52000, &quot;t2\_firstName&quot;:&quot;Anette&quot;, &quot;t2\_lastName&quot;:&quot;Irons&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Debbi&quot;, &quot;t1\_lastName&quot;:&quot;Jones&quot;, &quot;t1\_age&quot;:44, &quot;t1\_salary&quot;:54000, &quot;t2\_firstName&quot;:&quot;Anette&quot;, &quot;t2\_lastName&quot;:&quot;Irons&quot;, &quot;t2\_favColor&quot;:&quot;green&quot;}, {&quot;t1\_firstName&quot;:&quot;Susanna&quot;, &quot;t1\_lastName&quot;:&quot;Peterson&quot;, &quot;t1\_age&quot;:55, &quot;t1\_salary&quot;:66000, &quot;t2\_firstName&quot;:&quot;Strange&quot;, &quot;t2\_lastName&quot;:&quot;Mike&quot;, &quot;t2\_favColor&quot;:&quot;red&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Irons&quot;, &quot;t1\_age&quot;:26, &quot;t1\_salary&quot;:31000, &quot;t2\_firstName&quot;:&quot;Strange&quot;, &quot;t2\_lastName&quot;:&quot;Mike&quot;, &quot;t2\_favColor&quot;:&quot;red&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Steele&quot;, &quot;t1\_age&quot;:62, &quot;t1\_salary&quot;:72000, &quot;t2\_firstName&quot;:&quot;Strange&quot;, &quot;t2\_lastName&quot;:&quot;Mike&quot;, &quot;t2\_favColor&quot;:&quot;red&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Steele&quot;, &quot;t1\_age&quot;:50, &quot;t1\_salary&quot;:70000, &quot;t2\_firstName&quot;:&quot;Strange&quot;, &quot;t2\_lastName&quot;:&quot;Mike&quot;, &quot;t2\_favColor&quot;:&quot;red&quot;}, {&quot;t1\_firstName&quot;:&quot;John&quot;, &quot;t1\_lastName&quot;:&quot;Green&quot;, &quot;t1\_age&quot;:27, &quot;t1\_salary&quot;:80000, &quot;t2\_firstName&quot;:&quot;Strange&quot;, &quot;t2\_lastName&quot;:&quot;Mike&quot;, &quot;t2\_favColor&quot;:&quot;red&quot;}, {&quot;t1\_firstName&quot;:&quot;Debbi&quot;, &quot;t1\_lastName&quot;:&quot;Jones&quot;, &quot;t1\_age&quot;:58, &quot;t1\_salary&quot;:93000, &quot;t2\_firstName&quot;:&quot;Strange&quot;, &quot;t2\_lastName&quot;:&quot;Mike&quot;, &quot;t2\_favColor&quot;:&quot;red&quot;}, {&quot;t1\_firstName&quot;:&quot;George&quot;, &quot;t1\_lastName&quot;:&quot;Green&quot;, &quot;t1\_age&quot;:63, &quot;t1\_salary&quot;:40000, &quot;t2\_firstName&quot;:&quot;Strange&quot;, &quot;t2\_lastName&quot;:&quot;Mike&quot;, &quot;t2\_favColor&quot;:&quot;red&quot;}, {&quot;t1\_firstName&quot;:&quot;Anette&quot;, &quot;t1\_lastName&quot;:&quot;Jones&quot;, &quot;t1\_age&quot;:22, &quot;t1\_salary&quot;:76000, &quot;t2\_firstName&quot;:&quot;Strange&quot;, &quot;t2\_lastName&quot;:&quot;Mike&quot;, &quot;t2\_favColor&quot;:&quot;red&quot;}, {&quot;t1\_firstName&quot;:&quot;Susanna&quot;, &quot;t1\_lastName&quot;:&quot;Black&quot;, &quot;t1\_age&quot;:58, &quot;t1\_salary&quot;:52000, &quot;t2\_firstName&quot;:&quot;Strange&quot;, &quot;t2\_lastName&quot;:&quot;Mike&quot;, &quot;t2\_favColor&quot;:&quot;red&quot;}, {&quot;t1\_firstName&quot;:&quot;Debbi&quot;, &quot;t1\_lastName&quot;:&quot;Jones&quot;, &quot;t1\_age&quot;:44, &quot;t1\_salary&quot;:54000, &quot;t2\_firstName&quot;:&quot;Strange&quot;, &quot;t2\_lastName&quot;:&quot;Mike&quot;, &quot;t2\_favColor&quot;:&quot;red&quot;}]

Rows: 30   Time taken:   JS 2 ms

## [Union](javascript:showHideExi(15);void(0))

SQLike.q(
  {
    Union:[
       {
           Select: [&#39;firstName&#39;,&#39;lastName&#39;],
           From: dataArray
       },
       {
           Select: [&#39;firstName&#39;,&#39;lastName&#39;],
           From: dataArray2
       }
     ]
  }
)

| firstName | lastName |
| --- | --- |
| Susanna | Peterson |
| Anette | Irons |
| Anette | Steele |
| John | Green |
| Debbi | Jones |
| George | Green |
| Anette | Jones |
| Susanna | Black |
| Strange | Mike |

**JSON** :

[{&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Peterson&quot;}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Irons&quot;}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Steele&quot;}, {&quot;firstName&quot;:&quot;John&quot;, &quot;lastName&quot;:&quot;Green&quot;}, {&quot;firstName&quot;:&quot;Debbi&quot;, &quot;lastName&quot;:&quot;Jones&quot;}, {&quot;firstName&quot;:&quot;George&quot;, &quot;lastName&quot;:&quot;Green&quot;}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Jones&quot;}, {&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Black&quot;}, {&quot;firstName&quot;:&quot;Strange&quot;, &quot;lastName&quot;:&quot;Mike&quot;}]

Rows: 9   Time taken:   JS 2 ms

## [Union All](javascript:showHideExi(16);void(0))

SQLike.q(
  {
    UnionAll:[
       {
           Select: [&#39;firstName&#39;,&#39;lastName&#39;],
           From: dataArray
       },
       {
           Select: [&#39;firstName&#39;,&#39;lastName&#39;],
           From: dataArray2
       }
     ]
  }
)

| firstName | lastName |
| --- | --- |
| Susanna | Peterson |
| Anette | Irons |
| Anette | Steele |
| Anette | Steele |
| John | Green |
| Debbi | Jones |
| George | Green |
| Anette | Jones |
| Susanna | Black |
| Debbi | Jones |
| Susanna | Peterson |
| Anette | Irons |
| Strange | Mike |

**JSON** :

[{&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Peterson&quot;}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Irons&quot;}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Steele&quot;}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Steele&quot;}, {&quot;firstName&quot;:&quot;John&quot;, &quot;lastName&quot;:&quot;Green&quot;}, {&quot;firstName&quot;:&quot;Debbi&quot;, &quot;lastName&quot;:&quot;Jones&quot;}, {&quot;firstName&quot;:&quot;George&quot;, &quot;lastName&quot;:&quot;Green&quot;}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Jones&quot;}, {&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Black&quot;}, {&quot;firstName&quot;:&quot;Debbi&quot;, &quot;lastName&quot;:&quot;Jones&quot;}, {&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Peterson&quot;}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Irons&quot;}, {&quot;firstName&quot;:&quot;Strange&quot;, &quot;lastName&quot;:&quot;Mike&quot;}]

Rows: 13   Time taken:   JS 2 ms

## [Intersect](javascript:showHideExi(17);void(0))

SQLike.q(
  {
    Intersect:[
       {
           Select: [&#39;firstName&#39;,&#39;lastName&#39;],
           From: dataArray
       },
       {
           Select: [&#39;firstName&#39;,&#39;lastName&#39;],
           From: dataArray2
       }
     ]
  }
)

| firstName | lastName |
| --- | --- |
| Susanna | Peterson |
| Anette | Irons |

**JSON** :

[{&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Peterson&quot;}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Irons&quot;}]

Rows: 2   Time taken:   JS 0 ms

## [Intersect All](javascript:showHideExi(18);void(0))

SQLike.q(
  {
    IntersectAll:[
       {
           Select: [&#39;firstName&#39;,&#39;lastName&#39;],
           From: dataArray
       },
       {
           Select: [&#39;firstName&#39;,&#39;lastName&#39;],
           From: dataArray2
       }
     ]
  }
)

| firstName | lastName |
| --- | --- |
| Susanna | Peterson |
| Anette | Irons |
| Susanna | Peterson |
| Anette | Irons |

**JSON** :

[{&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Peterson&quot;}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Irons&quot;}, {&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Peterson&quot;}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Irons&quot;}]

Rows: 4   Time taken:   JS 1 ms

## [Except](javascript:showHideExi(19);void(0))

**Except** can also be written as **Minus**.

SQLike.q(
  {
    Except:[
       {
           Select: [&#39;firstName&#39;,&#39;lastName&#39;],
           From: dataArray2
       },
       {
           Select: [&#39;firstName&#39;,&#39;lastName&#39;],
           From: dataArray
       }
     ]
  }
)

| firstName | lastName |
| --- | --- |
| Strange | Mike |

**JSON** :

[{&quot;firstName&quot;:&quot;Strange&quot;, &quot;lastName&quot;:&quot;Mike&quot;}]

Rows: 1   Time taken:   JS 1 ms

## [Except All](javascript:showHideExi(20);void(0))

SQLike.q(
  {
    ExceptAll:[
       {
           Select: [&#39;firstName&#39;,&#39;lastName&#39;],
           From: dataArray2
       },
       {
           Select: [&#39;firstName&#39;,&#39;lastName&#39;],
           From: dataArray
       }
     ]
  }
)

| firstName | lastName |
| --- | --- |
| Strange | Mike |

**JSON** :

[{&quot;firstName&quot;:&quot;Strange&quot;, &quot;lastName&quot;:&quot;Mike&quot;}]

Rows: 1   Time taken:   JS 0 ms

## [Update](javascript:showHideExi(21);void(0))

Raising the salary with 5% for everyone over 40 years old.
Note that the update condition is in the form of a function that changes a field/property.

**Please note:** Update changes the orginal array.

SQLike.q(
    {
        Update: dataArray,
        Set: function(){this.salary\*=1.05},
        Where: function(){return this.age&gt;40}
    }
)

| firstName | lastName | age | salary |
| --- | --- | --- | --- |
| Susanna | Peterson | 55 | 69300 |
| Anette | Irons | 26 | 31000 |
| Anette | Steele | 62 | 75600 |
| Anette | Steele | 50 | 73500 |
| John | Green | 27 | 80000 |
| Debbi | Jones | 58 | 97650 |
| George | Green | 63 | 42000 |
| Anette | Jones | 22 | 76000 |
| Susanna | Black | 58 | 54600 |
| Debbi | Jones | 44 | 56700 |

**JSON** :

[{&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Peterson&quot;, &quot;age&quot;:55, &quot;salary&quot;:69300}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Irons&quot;, &quot;age&quot;:26, &quot;salary&quot;:31000}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Steele&quot;, &quot;age&quot;:62, &quot;salary&quot;:75600}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Steele&quot;, &quot;age&quot;:50, &quot;salary&quot;:73500}, {&quot;firstName&quot;:&quot;John&quot;, &quot;lastName&quot;:&quot;Green&quot;, &quot;age&quot;:27, &quot;salary&quot;:80000}, {&quot;firstName&quot;:&quot;Debbi&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:58, &quot;salary&quot;:97650}, {&quot;firstName&quot;:&quot;George&quot;, &quot;lastName&quot;:&quot;Green&quot;, &quot;age&quot;:63, &quot;salary&quot;:42000}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:22, &quot;salary&quot;:76000}, {&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Black&quot;, &quot;age&quot;:58, &quot;salary&quot;:54600}, {&quot;firstName&quot;:&quot;Debbi&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:44, &quot;salary&quot;:56700}]

Rows: 10   Time taken:   JS 1 ms

## [Insert into](javascript:showHideExi(22);void(0))

Insert a new post into a table.

**Please note:** Changes the orginal array.

SQLike.q(
    {
        InsertInto: dataArray,
        Values: {firstName:&quot;Michael&quot;,lastName:&quot;Arvidson&quot;,age:55,salary:100000}
    }
)

| firstName | lastName | age | salary |
| --- | --- | --- | --- |
| Susanna | Peterson | 55 | 69300 |
| Anette | Irons | 26 | 31000 |
| Anette | Steele | 62 | 75600 |
| Anette | Steele | 50 | 73500 |
| John | Green | 27 | 80000 |
| Debbi | Jones | 58 | 97650 |
| George | Green | 63 | 42000 |
| Anette | Jones | 22 | 76000 |
| Susanna | Black | 58 | 54600 |
| Debbi | Jones | 44 | 56700 |
| Michael | Arvidson | 55 | 100000 |

**JSON** :

[{&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Peterson&quot;, &quot;age&quot;:55, &quot;salary&quot;:69300}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Irons&quot;, &quot;age&quot;:26, &quot;salary&quot;:31000}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Steele&quot;, &quot;age&quot;:62, &quot;salary&quot;:75600}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Steele&quot;, &quot;age&quot;:50, &quot;salary&quot;:73500}, {&quot;firstName&quot;:&quot;John&quot;, &quot;lastName&quot;:&quot;Green&quot;, &quot;age&quot;:27, &quot;salary&quot;:80000}, {&quot;firstName&quot;:&quot;Debbi&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:58, &quot;salary&quot;:97650}, {&quot;firstName&quot;:&quot;George&quot;, &quot;lastName&quot;:&quot;Green&quot;, &quot;age&quot;:63, &quot;salary&quot;:42000}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:22, &quot;salary&quot;:76000}, {&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Black&quot;, &quot;age&quot;:58, &quot;salary&quot;:54600}, {&quot;firstName&quot;:&quot;Debbi&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:44, &quot;salary&quot;:56700}, {&quot;firstName&quot;:&quot;Michael&quot;, &quot;lastName&quot;:&quot;Arvidson&quot;, &quot;age&quot;:55, &quot;salary&quot;:100000}]

Rows: 11   Time taken:   JS 1 ms

## [Select into](javascript:showHideExi(23);void(0))

Insert the posts selected into a table.

**Please note:** Changes the array specified by _into_.

SQLike.q(
    {
        Select: [&#39;\*&#39;],
        From: dataArray2,
        Into: dataArray
    }
)

| firstName | lastName | age | salary | favColor |
| --- | --- | --- | --- | --- |
| Susanna | Peterson | 55 | 69300 | undefined |
| Anette | Irons | 26 | 31000 | undefined |
| Anette | Steele | 62 | 75600 | undefined |
| Anette | Steele | 50 | 73500 | undefined |
| John | Green | 27 | 80000 | undefined |
| Debbi | Jones | 58 | 97650 | undefined |
| George | Green | 63 | 42000 | undefined |
| Anette | Jones | 22 | 76000 | undefined |
| Susanna | Black | 58 | 54600 | undefined |
| Debbi | Jones | 44 | 56700 | undefined |
| Michael | Arvidson | 55 | 100000 | undefined |
| Susanna | Peterson | undefined | undefined | green |
| Anette | Irons | undefined | undefined | green |
| Strange | Mike | undefined | undefined | red |

**JSON** :

[{&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Peterson&quot;, &quot;age&quot;:55, &quot;salary&quot;:69300}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Irons&quot;, &quot;age&quot;:26, &quot;salary&quot;:31000}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Steele&quot;, &quot;age&quot;:62, &quot;salary&quot;:75600}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Steele&quot;, &quot;age&quot;:50, &quot;salary&quot;:73500}, {&quot;firstName&quot;:&quot;John&quot;, &quot;lastName&quot;:&quot;Green&quot;, &quot;age&quot;:27, &quot;salary&quot;:80000}, {&quot;firstName&quot;:&quot;Debbi&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:58, &quot;salary&quot;:97650}, {&quot;firstName&quot;:&quot;George&quot;, &quot;lastName&quot;:&quot;Green&quot;, &quot;age&quot;:63, &quot;salary&quot;:42000}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:22, &quot;salary&quot;:76000}, {&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Black&quot;, &quot;age&quot;:58, &quot;salary&quot;:54600}, {&quot;firstName&quot;:&quot;Debbi&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:44, &quot;salary&quot;:56700}, {&quot;firstName&quot;:&quot;Michael&quot;, &quot;lastName&quot;:&quot;Arvidson&quot;, &quot;age&quot;:55, &quot;salary&quot;:100000}, {&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Peterson&quot;, &quot;favColor&quot;:&quot;green&quot;}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Irons&quot;, &quot;favColor&quot;:&quot;green&quot;}, {&quot;firstName&quot;:&quot;Strange&quot;, &quot;lastName&quot;:&quot;Mike&quot;, &quot;favColor&quot;:&quot;red&quot;}]

Rows: 14   Time taken:   JS 1 ms

## [Delete from](javascript:showHideExi(24);void(0))

Delete posts from a table.

**Please note:** Changes the array.

SQLike.q(
    {
        DeleteFrom: dataArray,
        Where:function(){return this.salary===undefined}
    }
)

| firstName | lastName | age | salary |
| --- | --- | --- | --- |
| Susanna | Peterson | 55 | 69300 |
| Anette | Irons | 26 | 31000 |
| Anette | Steele | 62 | 75600 |
| Anette | Steele | 50 | 73500 |
| John | Green | 27 | 80000 |
| Debbi | Jones | 58 | 97650 |
| George | Green | 63 | 42000 |
| Anette | Jones | 22 | 76000 |
| Susanna | Black | 58 | 54600 |
| Debbi | Jones | 44 | 56700 |
| Michael | Arvidson | 55 | 100000 |

**JSON** :

[{&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Peterson&quot;, &quot;age&quot;:55, &quot;salary&quot;:69300}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Irons&quot;, &quot;age&quot;:26, &quot;salary&quot;:31000}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Steele&quot;, &quot;age&quot;:62, &quot;salary&quot;:75600}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Steele&quot;, &quot;age&quot;:50, &quot;salary&quot;:73500}, {&quot;firstName&quot;:&quot;John&quot;, &quot;lastName&quot;:&quot;Green&quot;, &quot;age&quot;:27, &quot;salary&quot;:80000}, {&quot;firstName&quot;:&quot;Debbi&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:58, &quot;salary&quot;:97650}, {&quot;firstName&quot;:&quot;George&quot;, &quot;lastName&quot;:&quot;Green&quot;, &quot;age&quot;:63, &quot;salary&quot;:42000}, {&quot;firstName&quot;:&quot;Anette&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:22, &quot;salary&quot;:76000}, {&quot;firstName&quot;:&quot;Susanna&quot;, &quot;lastName&quot;:&quot;Black&quot;, &quot;age&quot;:58, &quot;salary&quot;:54600}, {&quot;firstName&quot;:&quot;Debbi&quot;, &quot;lastName&quot;:&quot;Jones&quot;, &quot;age&quot;:44, &quot;salary&quot;:56700}, {&quot;firstName&quot;:&quot;Michael&quot;, &quot;lastName&quot;:&quot;Arvidson&quot;, &quot;age&quot;:55, &quot;salary&quot;:100000}]

Rows: 11   Time taken:   JS 1 ms

## [Pack](javascript:showHideExi(25);void(0))

Repack an array of objects into an array of arrays - this saves some space if you want to send it as JSON via AJAX.

**Please note:** Pack changes the orginal array.

SQLike.q(
   {
       Pack: dataArray,
       Columns: [&#39;firstName&#39;,&#39;lastName&#39;,&#39;age&#39;,&#39;salary&#39;]
   }
)

| 0 | 1 | 2 | 3 |
| --- | --- | --- | --- |
| Susanna | Peterson | 55 | 69300 |
| Anette | Irons | 26 | 31000 |
| Anette | Steele | 62 | 75600 |
| Anette | Steele | 50 | 73500 |
| John | Green | 27 | 80000 |
| Debbi | Jones | 58 | 97650 |
| George | Green | 63 | 42000 |
| Anette | Jones | 22 | 76000 |
| Susanna | Black | 58 | 54600 |
| Debbi | Jones | 44 | 56700 |
| Michael | Arvidson | 55 | 100000 |

**JSON** :

[[&quot;Susanna&quot;, &quot;Peterson&quot;, 55, 69300], [&quot;Anette&quot;, &quot;Irons&quot;, 26, 31000], [&quot;Anette&quot;, &quot;Steele&quot;, 62, 75600], [&quot;Anette&quot;, &quot;Steele&quot;, 50, 73500], [&quot;John&quot;, &quot;Green&quot;, 27, 80000], [&quot;Debbi&quot;, &quot;Jones&quot;, 58, 97650], [&quot;George&quot;, &quot;Green&quot;, 63, 42000], [&quot;Anette&quot;, &quot;Jones&quot;, 22, 76000], [&quot;Susanna&quot;, &quot;Black&quot;, 58, 54600], [&quot;Debbi&quot;, &quot;Jones&quot;, 44, 56700], [&quot;Michael&quot;, &quot;Arvidson&quot;, 55, 100000]]

Rows: 11   Time taken:   JS 0 ms

