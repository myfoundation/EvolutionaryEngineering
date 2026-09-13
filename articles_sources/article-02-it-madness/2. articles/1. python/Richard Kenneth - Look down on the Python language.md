
---
created: 2026-08-08T01:02:13 (UTC +03:00)
tags: []
source: https://richardeng.medium.com/why-do-most-programmers-and-engineers-detest-and-look-down-on-the-python-language-2f81a330035e
author: Richard Kenneth
---

# Why do most programmers and engineers detest and look down on the Python language?


From [this Quora answer](https://www.quora.com/Why-do-most-programmers-and-engineers-detest-and-look-down-on-the-Python-language/answer/Richard-Kenneth-Eng)…

Your question is based on a false premise. Most programmers and engineers do not detest Python.

However, there’s no question that many do, based on the many answers I’ve seen on Quora, as well as comments made elsewhere on the web.

There are several reasons for this. First of all, Python’s syntax is very polarizing. A great many developers don’t like using indentation as syntax. It removes freedom to format your code as you like. And it invites code alignment errors.

Second, Python’s OOP implementation is very crude. It hides instance variables and methods “in plain sight” by using underscore-prefixed names. This is, oh, so 1970s.

Also, how do you access the length attribute of an object? You might think **obj.len()**, but no. You use the global function **len()**. This is called “inconsistency.”

Third, because of Python’s use of indentation as syntax, Python’s lambdas are restricted to a single expression. You don’t find this in any other programming language.

Fourth, Python has peculiar variable scoping rules. When you’re used to most normal languages’ scoping rules, Python’s come off as jarring.

Fifth, Python’s notorious GIL interferes with efficient multithreading.

Sixth, pure Python code is as slow as molasses. This isn’t usually critical because Python is typically used as a “glue” language for integrating with C/C++/Fortran libraries. But when your application is real-time critical, Python just won’t cut it.

Seventh, Python’s use of half-open intervals is distinctly unintuitive. I get why some programmers like it, but it is unintuitive nonetheless. For example, **range(2, 6)** yields 2, 3, 4, and 5, but not 6.

Eighth, Python doesn’t support tail call elimination, so recursion can be problematic.

Ninth, in Python, all you have to do to create a variable is assign something to it. No declaration is needed. So if you assign “Bonaparte” to my\_lastname, a variable called “my\_lastname” is automatically created.

But if you should accidentally type “my\_lostname”, you may encounter a problem.

Such a problem is impossible in, say, Smalltalk because all variables must be declared. It’s not a serious problem, but when it does happen, it’s annoying. _Why didn’t Python protect me???_

These are just a few things off the top of my head. I’m sure there are more. Is it any wonder that many developers hate Python? Not most, just many.