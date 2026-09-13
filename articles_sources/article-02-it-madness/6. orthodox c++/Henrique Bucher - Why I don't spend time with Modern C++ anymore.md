---
created: 2026-08-21T21:59:58 (UTC +03:00)
tags: []
source: https://archive.md/2016.05.17-214038/https://www.linkedin.com/pulse/why-i-dont-spend-time-modern-c-anymore-henrique-bucher-phd
author: 
---

https://archive.md/2016.05.17-214038/https://www.linkedin.com/pulse/why-i-dont-spend-time-modern-c-anymore-henrique-bucher-phd

# Why I don't spend time with Modern C++ anymore | Henrique Bucher, PhD | LinkedIn

> ## Excerpt
> archived 17 May 2016 21:40:38 UTC

---
### Modern C++, what is it, where it comes from?

For the past 10 years with the advent of C++11, and before that its respective initiatives (TR1, Boost), there was a big movement within the C++ development community towards moving projects to the new standard: Modern C++. That meant using features like auto, closures (lambda), variadic templates and many more. C++ certainly became a rich platform for experimentation, and several "Modern C++" libraries appeared. Those lucky to grasp the new idioms as SFINAE, tag dispatching, CRTP, type generator, safe bool and others, or at least those who can recite them, were hailed with the status of Gurus.

After 1970 with the introduction of Martin-Löf's [Intuitionistic Type Theory](https://archive.md/o/xYYvh/https://en.wikipedia.org/wiki/Intuitionistic_type_theory), an inbreed of abstract math and computer science, a period of intense research on new type languages as [Agda](https://archive.md/o/xYYvh/https://en.wikipedia.org/wiki/Agda_(programming_language)) and [Epigram](https://archive.md/o/xYYvh/https://en.wikipedia.org/wiki/Epigram_(programming_language)) started. This ended up forming the basic support layer for [functional programming](https://archive.md/o/xYYvh/https://en.wikipedia.org/wiki/Functional_programming) paradigms. All these theories are taught at college level and hailed as "the next new thing", with vast resources dedicated to them. It also formed an ecosystem of speakers that make a living out of hyping out this "next new thing" into Corporate America.  It is no surprise that those formed under this environment come out of college and drive the current C++ committee developments.

### The Performance-to-Functional POV Switch

After enough time, C++ became from the "fast language" to the "functional language" and performance was put aside.  It is currently well known that several systems within C++ are inherently slow like iostreams, strings and also lacking basic features like networking, and very basic ones like a simple string splitting routine. Ask anyone in the committee about why this has not been resolved in almost two decades and the response is always the same: nobody has ever cared to submit a paper or proposal.

With [SG14](https://archive.md/o/xYYvh/https://github.com/WG21-SG14/SG14), which is a branch within the ISO Working group 21 (WG21) dedicated to games and high frequency tranding, the committee intends to give a channel for discussion from the general "low latency industry". However, given the discussions that there have been in the discussion groups, or the [Michael Wong's Standard](https://archive.md/o/xYYvh/https://wongmichael.com/tag/sg14/) (as funny as it sounds), there is visibly no appetite to implement the radical reforms that C++ needs in order to compete with "C++ with Classes" for the low latency applications.

### Why is it a problem really?

It is my personal experience reviewing many firms C++ code, both as an advisor for strategic investment initiatives and as a performance/optimization consultant, that "Modern C++" leads to unsatisfactory implementations in general. Not to say that it is not possible to create low latency, fast platforms based on Modern C++ but it creates many stumbling blocks that cast the team in paralysis or generates extremely [hard-to-optimize graphs](https://archive.md/o/xYYvh/https://youtu.be/FnGCDLhaxKU?t=34m43s) that C++ compilers have trouble with.  It is with extreme satisfaction to see Chandler Karruth's series of videos bring back the lost link (and a bit of sanity) between the C++ language and reality.

### Performance Loss

The first stumbling block is, as mentioned, the potential loss in performance due to more complex IR structures and passes in the compiler. This is where Fortran excels - because of the much simpler language, compilers are able to optimize it much more efficiently than the respective C/C++ code.  The ubiquitous understanding that templates and variadic templates will produce much faster assembly because the C++ code will automagically vanish during compilation **cannot be corroborated** by my personal experience in decades of HFT and gaming, by no reputable peer-reviewed publications nor by anyone with some knowledge of compiler optimization.  _This is an ongoing fallacy._ In fact, it is the opposite: smaller bits of code can be compiled, debugged and optimized by looking at the generated assembly much more efficiently than with templates and variadics. 

### Compilation times

The next stumbling block refers to compiling time. Templates and variadics notoriously increase the compilation time by orders of magnitude due to recompilation of a much higher number of files involved. While a simple, traditional C++ class will only be recompiled if the header files directly included by it are changed, in a Modern C++ setup one simple change will very often trigger a global recompilation. It is not rare to see Modern C++ applications taking 10 minutes to compile. With traditional C++, this number is counted in low seconds for a simple change. 

The time between when the developer is reasonably sure the code works and the time he gets to test the generated assembly is directly proportional to the quality of the code generated. If the developer can quickly try and test its application, it is more likely he will be able to nail all the possible edge cases he is worried about. When a recompilation takes ten minutes, not so much.

### Maintainability

The final stumbling block has to do with complexity. As Edger Djikstra once said,

> Simplicity is prerequisite for reliability.

If you have to hire a guru/expert to understand the code, either you have the wrong code or the wrong language.

If one reads with attention, the very fundamentals of [Djkstra's arguably most well known paper](https://archive.md/o/xYYvh/www.cs.utexas.edu/users/EWD/ewd02xx/EWD215.PDF), "Go-to Statements Considered Harmful" can be directly applied to templates and variadics: it is not that the feature itself is bad but its inherent structure leads to complex code that eventually brings down the most desired characteristic of a source code: easiness of understanding.

When one is programming trading systems that can send 100,000 firm orders per second over the wire from platforms with strategies being created and put in production over a two-day production cycle, you **_want_** simplicity. You _**need**_ simplicity. This leads to my one minute trading code rule:

> If you cannot figure out in one minute what a C++ file is doing,  assume the code is incorrect. 

### The Real Reason

But the real motivation why I do not spend much time with Modern C++ anymore, despite being pretty good at it at some point, is just that there is much more being developed in the industry that needs my attention.

C++ today is like Fortran: it reached its limits.  Nowadays there are interfaces so fast that [the very notion of "clock cycle" ceases to exist](https://archive.md/o/xYYvh/https://en.wikipedia.org/wiki/Clock_recovery) in certain parts of the system. The speed has gone so fast that at those speeds if two bits are sent  at the exact same time through two adjacent wires, they will likely get out of sync less than a meter away. 

To handle the type of speed that is being delivered in droves by the technology companies, C++ cannot be used anymore because it is inherently serial, even in massively multithreaded systems like GPUs. 

Today the "Modern Technologist" has to rely on a new set of languages: Verilog, VHDL. The new technologists have to be able to build their own CPUs, create their own virtual motherboards, otherwise they will be drowned by the avalanche of technological advancements in the coming years. Not because FPGAs are faster - they are not. They actually run 10x slower in frequency than top CPUs.

However all sorts of reconfigurable hardware are being deployed in the field. Intel is currently shipping Xeon CPUs with embedded FPGAs. IOT is going to become a multi-billion dollar market in the next five years, and it is largely propelled by little $10 FPGAs that will require an astounding amount of qualified technologists to program them. And programming on RTL is hundreds of times more complex than coding C++, believe me. If C++ has a learning curve, try to become an expert fpga programmer (Altera's transceiver toolkit alone is 700 pages long, Quartus is another 1,000 pages, not to mention all Xilinx tools and devices). 

But it is worth. Once you dominate these new ways to code, it opens up a huge avenue to express your ideas - and that is where the unicorns are born: by people that can see on both sides of the fence, higher than anyone else.

## Conclusion

In my personal view for what's worth, C++ is a tool that like Fortran, it is showing its age, accelerated by inaction from the ISO committee. Investing in being excellent in Modern C++ is becoming akin to excelling in Cobol or Fortran - a thoughtful exercise but with not much to gain. The new technologist has to resort to new tools in order to handle the new generation of technologies to be delivered in the next decades.  And there is just not enough time to learn.
