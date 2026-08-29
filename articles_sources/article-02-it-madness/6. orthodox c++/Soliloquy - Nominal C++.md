---
created: 2026-08-21T23:10:49 (UTC +03:00)
tags: []
source: https://archive.md/2016.08.07-162105/https://namandixit.github.io/blog/nominal-c++/
author: 
---

https://archive.md/2016.08.07-162105/https://namandixit.github.io/blog/nominal-c++/

# Nominal C++ – Soliloquy

> ## Excerpt
> archived 7 Aug 2016 16:21:05 UTC

---
C++ adherents vehemently claim that the only true way to use C++ is to delve in its complexity in the entirety. But does one have to?

_Edit: I just found about [Orthodox C++](https://archive.md/o/Jvz85/https://gist.github.com/bkaradzic/2e39896bc7d8c34e042b). Glad to know I am not the only one having these ideas._

## The Glorious Past

I have been using C (C99 mostly) for pretty much my entire programming life, and I believe that it is one of those few languages that managed to solve the problems they were meant to solve _and nothing else._ In C’s case, it was to make a portable assembly that provided the minimum abstractions that just worked and a simple enough model so that you knew to a certain degree exactly what your code and data was going to look like on the real hardware (as opposed to UML diagrams).

Sure, it has some problems; strings could have been handled better, the name of enums should have been retrievable programmatically and the pointer/array syntax could have been a little cleaner (what does \* mean, again?); but on the whole, C fixed what it set out to fix and most importantly, stopped there. It’s simple, efficient and learnable by mere mortal; except for a few undefined behaviours, it doesn’t really have any _gotchas_ that you need to worry about.

But as it happens every time, all good things must come to an end. Ever since I started game programming (and Linear Algebra in particular), the lack of function overloading was making my code a little kludged. My structs had multiple init methods, I had to invent ever-increasingly creative names for functions that did _almost_ the same thing but not really and remembering them all was turning into a pain. Now sure, these problems are nothing new and I had been solving them generally with Macros and Variadic functions since forever; but this time it had aggravated so much that the complexity was getting out of control. That is when I decided to jump the ship and started inching toward C++.

## Lost in the Vastness

I have worked with C++ before and it felt like working in a chocolate factory where you can eat as much as you want but then you find out that you are now diabetic. Things like inheritance and templates sound like the best-thing-ever when you are a novice programmer but after struggling with stupid error messages and strange performance penalties, you start wondering whether it was worth it in the first place (“Yes, it was!” screams a C++ fanatic). All in all, when I gave up C++ in favour of C, it felt like a breeze of fresh air. Programming was no longer about deciding class hierarchies and creating generic functions that solve every damn problem on earth, it was about laying out your data in a CPU-friendly manner and then devising algorithms that will transform that data to whatever form you want. With C, I solved my problem _and nothing else_; and that is a good thing.

So when I decided to move to C++, one thing was clear: [I only want the banana, the gorilla and the forest will have to find a different residence](https://archive.md/o/Jvz85/www.johndcook.com/blog/2011/07/19/you-wanted-banana/). With this in mind, I created a technical guideline for me to follow in order to retain my sanity and stay productive. Having said that, this is a Work In Progress and some parts might be misguided and/or flat-out wrong. Salt to taste.

## Brave New World

2.  **Minimum RAII**: Don’t use RAII. Wait… that was a bit harsh, let me rephrase. Instead of going for a constructor by default and thinking of Init functions when you need them, do the inverse. Make Init functions your go-to approach and use constructors only when you know what exactly you are doing and are 100% certain you are doing what you want to be doing and even more certain that your code is doing what you wanted it to do (Adapt the same advice for destructors as well). One reason is, in a complex system with many ways to initialize an object, you want different names to help you remember (and read) exactly what this one initialization is doing. Constructors all have the same name, which means this is impossible. But more importantly, there is no way to know whether a constructor even succeeded. “What?” you say, “Haven’t you heard of Exceptions? Living under a rock, have ya?” And to that, I say:
    
3.  **No Exceptions**: [Exceptions are GOTO](https://archive.md/o/Jvz85/www.joelonsoftware.com/items/2003/10/13.html) with a bright smile and nice dress. The only reason I ever used `goto` was to get out of deep loops and that is done in C++ by, obviously, `goto` itself. And besides, when you use return values for error checking, you know exactly where that checking happens. When you fire an exception, it is possible that you might have no idea who is going to handle it or is it even going to be handled. All this jumping around make control flow hard to follow and makes your program do things you never wanted it to do (Think HAL-9000). Yes, writing this:
    
    `if (function() != 0) do_this_thing();`
    
    is a couple of extra lines; but if they save your sanity, I say go for it.
    
4.  **Templates**: Frankly, use them if you have to; but first spend a while contemplating whether you really have to. Remember, you want to solve your problem, not every problem that has been or shall be encountered. Templates are powerful beings- they can make your code more readable, more generic, arguably faster and can increase the generated code size. Basically, Power comes with responsibility (or so says an old geezer).
    
    You know what? This is going slow; let me be brief and concise.
    
5.  **RTTI**: Don’t use it.
    
6.  **STL**: Don’t use it. (Note: I haven’t checked out EASTL though I have heard good things)
    
7.  **Multiple Inheritance**: Don’t use it. Personally, I even use single inheritance sparingly, but that might be too extreme for you.
    
8.  **Operator Overloading**: Use with discretion. The reason for overloading operators is code clarity, and if you are going to multiply images and divide OpenGL contexts, you are not invited to _any_ party. Ever.
    
9.  **New/Delete**: I’ll most probably implement a custom allocator anyway, so using these is just inviting trouble in future. But your mileage may vary.
    
10.  **Virtual Methods**: I don’t use inheritance a lot anyway, so polymorphism and virtual functions are pretty much out of the scene. Plus, they seem to [prevent inlining](https://archive.md/o/Jvz85/https://stackoverflow.com/a/2141784) too.
    

## Then what the hell do you use?

In order of decreasing amount of use: Function Overloading and Operator Overloading (and possibly Templates in near future).

## Picking up the pieces

Most of the problems have at least two solutions - the easy way or the correct way. Easy way gets things done for now, correct way improves you and makes you better at your job. C++ is a language designed for the masses. It tries to be everything from a low-level portable assembler to high-level metaprogramming language. It tries to create a path of least resistance toward the easy way, and I refuse to take the bait. [I’d rather be a good programmer in 10 years than a mediocre one in 21 days](https://archive.md/o/Jvz85/norvig.com/21-days.html).

Idiomatic C++ is a very different beast from idiomatic C, but I believe that it should be possible to use C++ as C with slightly better syntax. Of course, I can very well be wrong; but as Goethe said, [The dangers of life are infinite, and among them is safety](https://archive.md/o/Jvz85/www.azquotes.com/quote/552584).
