---
created: 2026-07-24T18:56:28 (UTC +03:00)
tags: []
source: https://web.archive.org/web/20110812181333/https://codequarterly.com/2011/hal-abelson/
author: 
---

# Code Quarterly

> ## Excerpt
> by Peter Seibel

---
## Hal Abelson Q&A

by Peter Seibel

Hal Abelson is perhaps best known to programmers as the co-author, along with Gerald Sussman, of the classic book _Structure and Interpretation of Computer Programs_. He and Sussman also created the MIT course of the same name, the legendary 6.001, which between 1980 and 2007 was one of four required courses taken by all MIT Department of Electrical Engineering and Computer Science students, teaching them how to think about programming and, incidentally, introducing them to the Scheme programming language.

Abelson is currently Class of 1922 Professor of Electrical Engineering and Computer Science at MIT and has been recognized within and outside of MIT for his contributions to computer science education. He was one of MIT’s six inaugural MacVicar Faculty Fellows, won MIT’s School of Engineering teaching award, the Bose Award, in 1992, and was awarded Taylor L. Booth Education Award by the IEEE Computer Society in 1995.

In 2007, Abelson helped create MIT’s new core curriculum for EECS students, in which 6.001 was replaced with a new course, 6.01. Among other changes, the new course switched languages from Scheme to Python, a change that drew much commentary from outside observers. In this interview Abelson discusses the motivations behind the curriculum changes and why the switch from Scheme to Python is one of the least significant changes.

Abelson has also long been involved in using computers for teaching non-programmers, having worked with Seymour Papert on the children’s programming language Logo and co-authoring the book _Turtle Geometry_. When I spoke with him, he was finishing a year-long sabbatical at Google, where he led the App Inventor project, building a development environment that allows non-programmers to develop apps for Android phones.

Finally, Abelson is an advocate for open culture and intellectual commons. He is a founding director of the Free Software Foundation, Creative Commons, and Public Knowledge and teaches MIT’s 6.805 “Ethics and Law on the Electronic Frontier” and co-authored the book _Blown to Bits_, an introduction to many of the topics covered in that course aimed at a more general audience.

Seibel: I’ll start where I pretty much always start, which is how did _you_ start? Where did you first get drawn into computers and learn to program?

Abelson: Gosh, I first programmed when I was in high school when I got a summer job at the Lakehurst Naval Air Station, which is famous as the place where the Hindenburg blew up. Not much famous for anything else. And they had gotten one of the early—I guess it was an IBM 709 computer—and you’d program it with punched paper tape. And you’d start off doing really, really simple stuff. People were just playing around with it.

Seibel: What year would that have been?

Abelson: God. Let me think. Maybe 1960. Maybe earlier. No, it must have been around 1960. Maybe 1961.

Seibel: Did they teach you to program or did you have some experience prior to that?

Abelson: I don’t think I had any experience, but nobody did, right? You went and played around with it and you read a book. I don’t remember what language we programmed in, probably FORTRAN. So that was the beginning. Then actually doing real programming was when I was an undergraduate at Princeton and became sort of the expert in this brand new language that was going to revolutionize all programming, which was called PL/I.

And Princeton was playing with this other waste of computer time called time-sharing. There was this thing called HASP. There was ASP and then HASP was, “half an ASP”. And then there were a whole bunch of people who were trying to convince the scientists there to move their programs from FORTRAN into PL/I because that was going to be the wave of the future. And then people playing around with time-sharing when everybody knew that the good use of computers was to solve Einstein’s equations by doing numerical stuff—all of the astrophysicists got extremely pissed when they took the computers down a couple of hours a day, away from doing useful things, and put them onto this waste of time, which was time-sharing.

So I became an expert in PL/I, the language of the future, and did support for faculty members who were trying to figure out how to do stuff in this language.

Seibel: What was your major as an undergrad?

Abelson: Math. I took _a_ computer science course when I was an undergraduate, but basically I did math.

Seibel: And from Princeton you went to MIT and got your PhD, also in math.

Abelson: Also in math, in something that has nothing to do with computers.

Seibel: And while you were doing your PhD were you also working with computers?

Abelson: When I showed up at MIT as a graduate student, it was 1969. That was the time, if you remember, when students were doing good things like marching and activism and taking over campus.

About two weeks after I got to MIT, the students occupied the president’s office, which I thought was great fun. It’s too bad students don’t do more of that now.

Seibel: Did you participate in the occupation?

Abelson: Well, I was a new graduate student. I said, “What the hell, I’m never going to get a chance to go sit in the president’s office.” So I wandered around to the president’s office and there were a whole bunch of people from Students for a Democratic Society sitting around on the floor. One of the people who was sitting around on the floor was somebody who I’d gone to high school with.

And I said, “I’m a new graduate student. I’m looking for a job. What’s a good place to go work?” And he said, “Well, why don’t you go over to the Artificial Intelligence Laboratory. They do good things.” So I wandered around there for a little bit and talked to people, and that’s pretty much how I got started.

Seibel: When you were doing your PhD in math did you really love that or was that just like, “Well, I signed up to do math, so I’m going to finish it, but what I really love is computers”?

Abelson: Well, I loved them both. My math PhD was in algebraic topology, which had nothing to do with computers. Then I got interested, through thinking about topology, in the relations with distributed computing and that eventually formed a bridge into doing something in computing.

Also I got a job as a graduate student working in the Logo lab, in Seymour Papert’s group, which was just starting up then, so I was hanging around the Artificial Intelligence Lab. And then simultaneously I started doing work doing research that was related to distributed computing. I came at it from the topology side.

What was happening then was MIT formed this thing that no longer exists called the Division for Study and Research in Education. That absorbed the Logo group so it seemed sort of natural to be partly in what was called the Education Division and then partly in math. And then I started doing more and more of the Logo stuff, and more and more of the distributed computing stuff, so that the Education Division thing morphed into an appointment in the Electrical Engineering and Computer Science department.

Seibel: Those two threads were separate—distributed computing and Logo?

Abelson: Right. They were tied in that they were both of interest in the Artificial Intelligence Lab. But they weren’t formally tied.

Seibel: MIT has this famous hacker culture, that Steven Levy wrote about in his book _Hackers_. He talked about this drawer full of code where anybody could pull out a listing and fix it.

Abelson: That was certainly true then.

Seibel: Did you ever find someone else’s code and hack on it, or did someone take your listing and do things with it that you never imagined?

Abelson: Not particularly with me, but that was the standard stuff. You know, this is all sitting on a completely open, shared file system. We didn’t even have logins in those days, or we didn’t have passwords. Actually there was a big huff—I think it was ARPA that was funding us said, you know, you’ve got all these accounts, you should have passwords on them. And a bunch of us said, what a crappy thing that is. But in general all the stuff was just shared and open. You didn’t even think of it like that. You didn’t think of it as my code and your code and somebody else’s. It was—this is the stuff we are all building together.

Everything was open and the most natural thing in the world is you took somebody’s program and it wasn’t quite right, and you’d change it.

Seibel: Okay. And with the AI lab, when you got your job, was that on Project MAC or was that yet going?

Abelson: It’s complicated. There was this thing called Project MAC, which was mostly about inventing time-sharing, and then after that they did a whole bunch of other things. And then at one point there was a fight about space, which is what most fights at universities are about, and somebody wanted to take away a couple of offices. Marvin Minsky was running the AI group inside Project MAC and he said, “Well, screw you. I’ll go form my own laboratory.” That was the beginning of the Artificial Intelligence Laboratory. When I showed up, there was Project MAC and the Artificial Intelligence Laboratory.

Then Project MAC changed its name to the Laboratory for Computer Science. Five, six, seven years ago the two laboratories decided to merge because there was no good reason to keep them separate.

![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABEAAAASCAYAAAC9+TVUAAACBUlEQVR4nGNgQAIODg4c7u7uQhAemC/j4OBU7ujoGAwRQQB7Z2dHe0fnqUA1BmABT09PPgdHxzkOTk7X7B2dfgLxRQcHZw8g/5y9o2MvSM7eySkXrBgIQkNDmYFqPjo4Ov13cHQ+DzKAHah4vpOTkzxIAdBkAUdH5zKggjcghXZ2LrpgcaBBIBoGgHrWgw1xcroE4jQAbYmESCGAjY2NoKOj0zSgwitAp1sCXdQJkYEAoKVmYEMcnOOBNji9ANpcBJHCBECXGAJdsR9o2S2gRieQV5ydnYWB/OVAXABWBDTkOdBfp8EcHAAYsF4gi4CB3A3UOB/oqlo7OzdFiCwQuLq6SgHDQQTCY2AEKqoB2vwIGB5PQWyQINCAKqAL2EDeAjrGCKQOJI4VAG2qBvsTGTs4JwNdkgU0+B5C3Pk0ksUIAIolRLQhYSenFlA0YhGfDdGJBIAmm2AoxI+vQ3QiAaCTndEUEcDOxyE6kQDQEH1MhXiwg3M+RCcSMDY2ZsUaJlix8xZQeoHoRAPADDUTUwMK/gSOQQcHFogOLACYgGTBCtE0A134FZjAKl1cXPgtLS05sUYvMgCGjT9Q429kQ0CBDpEFpXDHBUCx76BEChHBARwcXFyACp/ADIElcUiRARZ/DHQND0gML/Dx8eECJqgcoFcOAjVdALpgBhAfBubsWeiuAAAqgBshJvfZpgAAAABJRU5ErkJggg==)

Seibel: If you look at the way you thought about programming when you started out and the way you think about it now, can you sum up the big changes?

Abelson: It’s an immense change. Let me see if I can express that. When I first learned programming, and I think when most people first learn programming, they think it’s about the rules. So programming is about what’s an `if` statement look like and the fact that in FORTRAN if you say `DO`, you have to put a comma in the right place.

Certainly by now I don’t think about that at all—I don’t think about syntax at all when I program. It’s really about building abstractions and expressing ideas. That’s the kind of thing that Gerry Sussman and I did in our book. There’s one level where you say, “I have this stuff,” and the thing about programming is following the rules so I can do something that is a legal something. Whereas the other view of programming, which is certainly the one we put in our book, is that programming is about creating a language in which to express the things you want to do. It’s just a fundamentally different task.

Seibel: That book, _Structure and Interpretation of Computer Programs_, is famous as both a computer science book and as a Scheme book. Was Scheme itself a revelation that allowed you to write the book or was it just a useful tool for exploring these ideas that you had already?

Abelson: Well, Scheme existed before the book. But we made a lot of changes in Scheme in order to teach the course, so they kind of go hand-in-hand. The goal is that you want to make something that has very, very simple built-in rules and where the power is in the way you can combine things. A lot of Scheme was designed explicitly like that. One of the tenets of Scheme is that there’s only one way to name things. It’s very non-Schemey to say that there are identifiers that are used for functions and there are identifiers that are used for data structures and there are identifiers used for processes or whatever it is. The whole point in Scheme is that this is one uniform way to refer to things. At the end of the day they’re all procedures. They’re all objects.

But you asked whether it’s Scheme or computer science. We don’t write about Scheme very much really, other than we say, “Hey, that’s the natural way to think about this stuff.”

Seibel: Which is sort of the flip side of my question: to what extent could you have written the same book using a different language?

Abelson: I could imagine—well, in fact I have done the very beginning of it using Python because Python at least has first-class procedures and has a single namespace, pretty much. Anything else, the mechanics of the languages just get in the way of the ideas. What we try to do is we want to get to the ideas as soon as possible. There should be nothing that stops you from writing a procedure as your first experience.

It’s partly the language and partly how you think about it. It’s still the case that if you pick up most books on programming, how to write a procedure—or a function or whatever they call it—comes about thirty percent of the way through the book, and the first twenty pages are about, “Well, there’s these different data types and there are floating point numbers and there’s strings and there’s this and that,” and then people act as if that’s the stuff of what programming is about. But that’s just totally boring.

Seibel: _Structure and Interpretation of Computer Programs_ was the textbook for the legendary 6.001 course at MIT that all EECS students had to take. How did that course come about?

Abelson: That was a long time ago. Way before my time there was the original lambda calculus course that was the genesis of all of this. But that never became the MIT first course that everyone took. Before 6.001 there is a different course—I want to say 6.031—that was sort of a weird course when I first got involved in it. It did ALGOL and then it did Lisp.

Lisp was about, hey, we can build this interpreter and that interpreter and the other interpreter, and you could make this one with dynamic scoping and this one with lexical scoping. Even having taught it twice I couldn’t get it into my head. “Was it the J interpreter that did that or the D interpreter?”

So the department went through, “Let’s invent the core curriculum.” It might have been ’78 or ’79. Then Gerry Sussman and I got the ability to do the new course, which was going to be called 6.001. We basically did it without telling people what we were doing, which is why they let us.

Seibel: What do you think they would have objected to?

Abelson: Oh, people object to whatever you do. We did a lot of work over the summer and then Gerry said, “Hey, you know, Guy Steele and I made this language Scheme.” We worked on that and built a new implementation, I guess the first real implementation.

Our big idea was that we were going to do Scheme and then ALGOL. In ALGOL we were going to do static scoping and I forget what else. Everyone said “Okay, because you’re doing the really important thing which is the ALGOL,” because that was the real computer science.

Around July I remember Gerry saying, “This is stupid. Scheme already is lexically scoped; what are we going to be teaching people when we do ALGOL?” So we said, how about we just don’t do ALGOL at all? And then we said, yeah, but we should do something else, so it’s not just a whole semester of Scheme. That’s why there’s a Prolog chapter in the book.

Seibel: Implementing Prolog in Scheme, you mean?

Abelson: Right, it’s implementing Prolog. And it’s not, of course, all of Prolog. Again, we said, we’ll use Scheme as the vehicle but show off the different programming paradigms.

Seibel: You were involved in the revision to the MIT core computer science curriculum, a few years ago, which replaced 6.001 with 6.01. In the Lisp world people are like, “Oh, they’re switching from Scheme to Python. The sky is falling.”

Abelson: Well, that’s all superficial. The main thing is 6.01 is not a course about programming. It’s not a course about software. It’s not even a course about computers. The main change was that we said the first course in the department should be a much broader course about what’s going on in the department. That’s hard for the programming people to understand.

6.001 was really a course in software. It’s how you think about software, how you think about programming. In the new department structure, 6.01 is specifically not that and it’s not that intentionally. Now, that might or might not have been a good choice, but what we said is, we are going to switch. Before, when you entered the department what you got was a very deep course in thinking about the structure of programming and computer science—abstraction and modularity.

We said, we are not going to do that anymore. Instead we’re going to show the breadth of the department. That’s the basic choice. We’re going to talk about programming, we’re going to talk about circuit theory, we’re going to talk about signal processing, and we’re going to talk about probabilistic reasoning.

It’s just a different course. We could have done it in Scheme and I sort of wish we had. And for random reasons we didn’t. But the thing that ties it together—if you had fifteen seconds to describe the whole course—it’s still about abstraction and modularity. The beginning of that course is not very different from the beginning of 6.001 other than you do it in Python. But at that point, where you’re not building interpreters yet, you can pretty much do this stuff in Python. You have to contend with Python’s broken notion of lambda but other than that it’s not really that different.

The course basically says, “Look, the way you build things, there’s an engineering discipline.” And that’s exactly what was in 6.001. It says, you think about what are the primitives, what are the means of combination, and what are the means of abstraction. The course starts out and we show that around programming in Python. Of course we don’t go in as deep, but we even do the same examples, Fibonacci and how you do a numerical derivative by passing a function. Then we do some objects and classes, which you can do earlier in Python.

Then we do that in circuit theory, and we say, “Look, it’s the same thing. You have resistors and capacitors and stuff, and there’s a means of combination called ‘wire stuff together’, and there’s a means of abstraction called ‘you make a Thévenin equivalent to a circuit’, and then there are common patterns for doing things.” And then we do it in signal process. You say there are these primitive things that are called filters, and there’s a means of combination, making block diagrams, and there’s a means of abstraction, which is a system function.

So just like in programming I can take some complicated thing and say, “Oh, it’s a black box called a procedure and I don’t have to look at its insides,” in signal processing I can say, “Oh, there’s this black box and I don’t have to worry that this thing is done with an op-amp and two resistors versus something else.” It’s abstracted by the system function, and there are lots of realizations for that just as there are lots of ways to implement a procedure and keep the same API.

And then we do the same thing in probability, although, it doesn’t actually hang together as much then, but we do want to do probabilistic reasoning. So it’s basically taking what fundamentally is the same philosophical paradigm as the previous course, but instead of going deep, it goes broad and tries to say, “Well, this notion of abstraction really cuts across all of engineering.” Which of course is a lie too because there are places that it doesn’t work at all. But that’s what that course is about. Now, whether it’s good or not, I don’t know.

Seibel: And the department that it’s in is actually the Department of Electrical Engineering and Computer Science?

Abelson: Right. It’s basically one department, so this was a statement that, in fact, MIT wants to keep this as one department. The way it used to be one department is that everybody had to take these four courses. There was software and circuits and signal processing and architecture. What’s changed in the curriculum—partly in response to the pressure that there’s just so many more things to do—is we took the core, the stuff that everybody has to take, and greatly shrunk that.

Seibel: So the reason to do a breadth-first course first is because there’s going to be less in the core.

Abelson: Right. The reality is, if you come in to MIT and your goal is to learn as little about circuits as possible, in the old curriculum, there was a whole semester of circuit theory. In the new curriculum, it’s the three weeks that we do where the message is, “Well, you get to wire some stuff together, and hey, you can make a Thévenin equivalent of something because that’s the abstraction of the circuit.”

Seibel: I’m sorry. What was that word?

Abelson: A Thévenin equivalent. He was a French electrical engineer. If you have a circuit that’s put together by linear components and you put a voltage through and you measure an amperage, or vice versa, whatever is in this mess, you’d get the same behavior with an appropriately chosen resistor and a voltage source. That’s called a Thévenin equivalent.

It’s used in a way that’s really comfortable in programming. If somebody looks at some circuit, analyzing it, they will say, “What’s the Thévenin equivalent of this?” And that’s the thing on which you’d do the analysis. It really is the same abstraction story.

Seibel: So you’re giving people a breadth-first taste of the department, so they can then choose what they want to do. It actually sounds like despite the introductory course being more breadth-first, it will actually enable people to specialize more.

Abelson: That’s exactly right.

Seibel: So the statement that this is one department is not actually a statement that computer programmers of tomorrow need to know more about circuit theory. They can actually know less.

Abelson: And conversely. If you are interested in devices and you hate anything that has to do with this computer junk, in the previous curriculum you had to sit through all of 6.001 and learn all of those things. Now you get the beginning of the abstraction story. About five weeks into the course, when we switch from doing programming stuff to doing circuit stuff, half the class goes, “Oh my God, finally,” and half the class says, “Oh God, what is this crap?”

The ideas are merged of course. One of the ways you analyze these circuits is you write programs to analyze them. In signal processing, for example, when you learn to make a differential equation model of something and pump something through it, there’s basically a representation that says, “Here’s the rational function that is the system.” There’s another representation that says, “Here’s the stream process where I put in a bunch of samples and out comes the thing.”

Then there are transformers that go between those two representations, and that’s straight Python programming. They have to build the class that takes a rational function and then turns that into the stream processing program. We try hard to make the relation go across these things.

![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABEAAAASCAYAAAC9+TVUAAACBUlEQVR4nGNgQAIODg4c7u7uQhAemC/j4OBU7ujoGAwRQQB7Z2dHe0fnqUA1BmABT09PPgdHxzkOTk7X7B2dfgLxRQcHZw8g/5y9o2MvSM7eySkXrBgIQkNDmYFqPjo4Ov13cHQ+DzKAHah4vpOTkzxIAdBkAUdH5zKggjcghXZ2LrpgcaBBIBoGgHrWgw1xcroE4jQAbYmESCGAjY2NoKOj0zSgwitAp1sCXdQJkYEAoKVmYEMcnOOBNji9ANpcBJHCBECXGAJdsR9o2S2gRieQV5ydnYWB/OVAXABWBDTkOdBfp8EcHAAYsF4gi4CB3A3UOB/oqlo7OzdFiCwQuLq6SgHDQQTCY2AEKqoB2vwIGB5PQWyQINCAKqAL2EDeAjrGCKQOJI4VAG2qBvsTGTs4JwNdkgU0+B5C3Pk0ksUIAIolRLQhYSenFlA0YhGfDdGJBIAmm2AoxI+vQ3QiAaCTndEUEcDOxyE6kQDQEH1MhXiwg3M+RCcSMDY2ZsUaJlix8xZQeoHoRAPADDUTUwMK/gSOQQcHFogOLACYgGTBCtE0A134FZjAKl1cXPgtLS05sUYvMgCGjT9Q429kQ0CBDpEFpXDHBUCx76BEChHBARwcXFyACp/ADIElcUiRARZ/DHQND0gML/Dx8eECJqgcoFcOAjVdALpgBhAfBubsWeiuAAAqgBshJvfZpgAAAABJRU5ErkJggg==)

Seibel: That comes to another aspect of teaching computer science, or programming. Do you think these days to really be a good electrical engineer or whatever, you have to know how to program?

Abelson: Certainly a lot of tools involve programming. But there are lots of people who have nothing to do with that. If you’re really down doing device physics I mean, sure, you’re working with simulations and programming and things, but I don’t think you have to know how to program.

Seibel: I worked on a project for a while providing a programming environment for biologists. It started with a guy who was a computer science professor and then switched to wet lab biology. And his biologist peers were just astounded by what he could do with just a little bit of programming—they were doing these horrible things in Excel. So his take was that biologists have so much data, and they need to analyze it in such ad hoc ways that they have to learn to program to get a grip on it.

Abelson: It might be. I don’t know. They might just have some really bad tools. Certainly there are people that have demonstrated some very powerful things with systems like the ones you’re talking about, and it’s also true that there is this abstraction, modularity way of thinking about things. You can recognize various biologists who are systems biologists who think that way. You can see that. That’s not quite programming as much as a computing way of looking at the world.

Look at the stuff that Tom Knight at MIT worked on, basically the beginnings of synthetic biology. He’s certainly a programmer. Synthetic biology is really a weird engineer looking at biology stuff. It’s not a thing that a biologist would’ve come up with.

Seibel: So, to jump back to the _Structure and Interpretation of Computer Programs_ and using Scheme for that: as a pedagogical choice it was great because it was simple and it didn’t get in the way.

Abelson: And it’s expressive. In teaching programming, you should show people the different styles. If you teach people a course and you don’t talk about functional programming, you’re doing them a disservice. It’s like teaching literature and you leave out forty percent of the genres. We put in logic programming because we wanted to show people that genre. It’s a way of thinking about how to do stuff.

I think a lot of courses don’t take that attitude. Part of it is that you can do this in Scheme. There are lots of languages where it’s pretty hard to teach functional programming or logic programming. That’s part of why we chose Scheme as the language.

Seibel: How has teaching computer science changed? People must come in, maybe not knowing more, but with a lot more exposure to programming.

Abelson: Well some. We’ve dealt with that differently over the years. And with the switch to 6.01 we’re seeing something a little bit different. It used to be we’d take these polls: “Who in the class has ever programmed before?” The answer used to be everybody had programmed before, except four biology graduate students who were taking the course because they wanted to know something about programming. Then there were more people—as MIT broadened a little bit—who had no programming experience at all.

One of the ways we originally dealt with that is by doing functional programming so early. It was really quite intentional that by lecture two or lecture three we were talking about higher-order procedures, because nobody had really seen that before.

The trap in a place like MIT is the courses are actually pretty hard. Students will come into a course and if they spend the first two weeks saying, “Oh, I’ve seen that,” they’ll get used to the idea they never actually have to study anything in the course. And about week four, they’re killed.

Seibel: So you try and get it started faster so they don’t get lulled into complacency?

Abelson: Yeah, and there’s a little bit of leveling where you say, “None of you people have seen higher-order procedures before.” That’s not quite so true anymore. The last time we did a survey in 6.01, which was probably two years ago, there were people who had never programmed before, who really, really had never programmed before in the real sense of being unfamiliar with it and not having the standard facility with a computer. And really basic things people didn’t have, like when there’s a problem you’re working on they don’t have the sense that you should try a more simple version of the problem first—things that are independent of any language.

We have some students who fell into that category and we’ve been playing with various remedial things to do. I don’t actually know how that came out, because when I stopped teaching the course to come to Google we were right in the middle of playing with things like that. Then of course there are people who are super-sophisticated, people who have come to MIT after starting companies and doing other stuff.

Seibel: But they still have to take that course if they’re in that department?

Abelson: Very few people place it. It’s a hard course to place because it’s pretty unlikely that you both are going to be an expert programmer and know about signal processing.

And the course these days has a loose enough structure that people can sort of get by learning whatever tiny little bit of Python they don’t know. Most of them know Java, unfortunately.

Seibel: Unfortunately because it’s rendered them brain-damaged or—?

Abelson: Well it’s not quite brain-damaged. It’s this attitude—remember what I said about programming isn’t about the details of the syntax as opposed to the structure? As part of figuring out what we want to do in 6.01, I gave—not quite an entrance exam; we had to let you into the course—but a sort of self-calibration exam.

I put five questions on it. There was one question that said: we want to make a thing called an inverted index in order to look at a piece of text and identify which words are in it and their frequency. So I said what an inverted index was and said, “Build a thing that makes an inverted index.”

The second question was: write a program that takes in A, B, and C and gives you the answer to the quadratic equation Ax<sup>2</sup> + Bx + C = 0.

The third one said: write a program that takes in a bunch of coefficients of a polynomial and a value for X and print out the value of the polynomial.

The fourth one was a thing about how many ways can you make change for $2.35 given nickels and dimes and quarters. That was the test.

So the question for you is: for which of those questions did people turn in the largest amount of code? I said you could pick any language you want. Just write a program that does this and turn it in.

Seibel: My guess would be the change counting.

Abelson: The answer was the quadratic equation. Because what’s a quadratic equation program look like? The programs start with a bunch of system dot out dot open stuff. That’s followed by instructions like: I am going to ask you to type in three numbers and we are going to solve the equation Ax<sup>2</sup> + B = C. Please type in A. Parse the string. Type in B. Parse the string. Now I’m about to do this thing and, and, and, and, and. And it turns out to be two pages of code. When I made up that question, I couldn’t even imagine that they’re going to be doing stuff like this.

But that turns out to be the kind of experience, the programming experience that kids get in high school, and it’s all about this junk and not about the real ideas that are sitting there. That’s even at a place like MIT, and that’s even super, super top students.

Seibel: What do you think of courses that start with something like C or even assembly? Is that just a different way to do it, or is it misguided?

Abelson: I think it’s the wrong thing, but you know again, so much depends on the context and who the instructor is, and what kind of lessons you’re going to do. And there also really are people who like to understand stuff bottom-up. It’s not to my taste. To my taste the most important thing is the idea that you build on abstraction. That’s now becoming a very, very common view. But when we were first doing 6.001, that was hardly the common view.

Seibel: Do you think that may be why that course and that book are considered classics—because they really advanced that view when it wasn’t common?

Abelson: Yeah, I think so. There are a lot of things we consciously did—using Scheme was part of that. Using a language that had almost no syntax was part of that so you didn’t spend the first three weeks of the course explaining whether you put a bracket or a parenthesis, or how you break a line, or where you put a semicolon.

If you notice, one of the things that we did in the 6.001 book, which still bugs me that I don’t see it in books, is we start by defining a procedure. I think we add two numbers and name something and define a procedure. Whereas if you pick up most programming books these days, procedures are somewhere like chapter seven and the first chapter is well, let’s list all the data types in the language. There’s still a big difference in perspective.

Seibel: Right. Though presumably that’s partly, as you’ve said, because that book is not intended to teach you Scheme. It’s intended to teach you programming. Whereas you were just writing a book for someone who wants to learn Scheme, you might break it down a little more systematically.

Abelson: Right. But it’s still weird to me that I would start teaching programming by going through a litany of what are all the primitives in the language and what are the data types and all that stuff. For me, the first breakthrough is how do you put stuff together.

Seibel: Leaving aside whether you start there or not, how low-level do you think programmers ought to go? Does everybody need to learn C or some systems language?

Abelson: Or soldering irons?

Seibel: Yeah. Chip design or assembly. Whatever.

Abelson: Which programmers? Who are you thinking about? There are lots of programmers who I guess never go below the HTML level these days.

Seibel: Right. Clearly, if you’re going to hack kernels or things that actually are in C, obviously you need to know that stuff. But there’s people who say even if you’re going to be spending your whole life writing Java, or Ruby, or Python, you should still know what’s going on down at the chip. If you want to be a serious programmer, you really need to understand that stuff. And other people say that’s hooey: you operate at the layer of abstraction you operate at.

Abelson: I certainly think the second. Of course, there are people who need to know that stuff. There’s people who really need to know how to grind out real efficiency. There are people who need to have some understanding of what that is. But for most people who are programming, unless you want to be a real expert, you get by with the layer of abstraction you’re at.

Look at Google. There’s this insane, giant, distributed, opaque infrastructure that runs in the backend, and very few people have a real sense of what’s happening there, even inside Google. On the other hand, there are the real experts who keep this stuff running.

Seibel: It used to be that all programmers had to be able to operate at that level, because there weren’t such high-level languages.

Abelson: Well, it’s not only that they’re high-level languages. There are really very complicated distributed infrastructures. If I’m writing something, some of it may have to do with, “Did I use the right sorting algorithm?” But much more of it has to do with, “Have I distributed the data correctly?”

Seibel: How about math? How much math do programmers need?

Abelson: There’s a tremendous amount in this 6.001 book. That’s partly because we were writing it for MIT. You want to talk about higher-order procedures, so the obvious thing you can do is you can express the idea of an integral. So that’s an obstacle for lots of places. Remember, at MIT the context we were writing in is every person who took the course had just had a semester of calculus.

We actually did some versions for the Humanities faculty, where we didn’t do that at all, and we effectively started with the data structure chapter and then talked about the ideas for how do you structure and manipulate data, and then do abstractions over that.

Seibel: I was wondering when I re-read it. Talking about homogeneous second order linear differential equations probably plays at MIT, but maybe not everywhere.

Abelson: That’s right. When we wrote that we very much had MIT students in mind. It started out as the course notes of the class.

Seibel: So that explains why the book is the way it is. But in general for programmers, how much math and what kinds of math are important for working programmers to know?

Abelson: I don’t even know anymore. We have these arguments at MIT all the time. People say, well, there’s math. Other people say, well, what they really need to know are algebraic structures so you understand abstract data types, how you think about axiomatizing them. And then people say what you really need to know is what a mathematical proof is so you can think rigorously. And I don’t know what to say. These arguments have been going on for thirty or forty years.

Seibel: And have you ever had a position?

Abelson: Well, the last time I had a position I tended to say that they ought to be able to like a lot of math. I’ve never been partial to the thing that says they need to be able to do proofs, but that’s just taste. And again, these days the main thing you try to understand is abstraction. Maybe that’s related to proofs. You need to be able to say look, here’s this thing and here’s the rules for how it works. And then I don’t need to look below that layer most of the time in order to get started. And there are people who really get hung up on that.

Seibel: You mean people getting hung up trying to look under the layer they need to?

Abelson: Well, they say, ‘I can’t get this in my brain unless I can imagine it all the way down.’ That’s the thing you see students do. I was going to say math is the thing that helps you with that, but there might be lots of other things that help.

Seibel: Programming itself, perhaps being one of them. It seems to me that keeping those levels separate is the name of the game in programming.

Abelson: I totally agree with that.

Seibel: I think someone who couldn’t learn to do that would give up on programming at some point.

Abelson: And that’s what happens. People have no way to anchor themselves.

Seibel: So they go off and design chips or something.

Abelson: Right. Or they go into law school. Well, law’s interesting. That’s an example where you don’t have that abstraction.

Seibel: Yeah, and woe for the rest of us.

Abelson: Yeah, but it’s perfectly reasonable and they’re extremely brilliant people, who think like that. But that’s not the way programmers think.

Seibel: Right. Another part of “math” as it relates to programming these days is that lots of academic language research is focused on statically typed, pure functional languages like Haskell which are intended to be built on top of some kind of rigorous mathematical foundation.

Abelson: Yeah. That’s right. It’s all wonderful stuff, but you know—it’s kind of constraining sometimes. But there’s tremendous insights you get from that.

Seibel: Do you see that as a good way to start programming? Some people like to teach that as a first language.

Abelson: As an intro? I want students to make things as an intro.

Seibel: You mentioned before that one of the benefits of using Scheme is that you got to show lots of different styles of programming.

Abelson: That said, but remember, we start out in this almost purely functional style.

Seibel: It’s functional, but these days, to a lot of people, _functional_ includes the notions of static typing and monads and all this category theory stuff.

Abelson: Well, I don’t call that functional. I call that statically typed.

Seibel: Do you see that as an interesting style? There’s functional programming, and logic programming, and procedural. Is statically typed functional just a slight variant of functional or is that a completely different style of programming with its own benefits and drawbacks.

Abelson: That’s sort of orthogonal. That’s the way in which you define modules that have particular behavior. To me, that’s a little bit more like object-oriented but the idea that it’s statically typed is not particularly interesting. That’s a question about what the compiler is doing.

Seibel: It does seem to affect the way people think. When I interviewed Simon Peyton Jones, who obviously likes Haskell a lot, he talked about how he thinks about a program—he really starts from types.

Abelson: Right. That’s when you’re doing types that have interesting properties. The problem is people confuse that with this totally boring thing about is something an integer or a floating point number.

Seibel: But in a language like Haskell the type system can express those higher-level types.

Abelson: Right. That’s the interesting part. I sit down and I say what are the data objects and what are the rules. Those are interesting worthwhile things. But that’s why it seems to me like that’s object-oriented; I’m defining the interface to it.

![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABEAAAASCAYAAAC9+TVUAAACBUlEQVR4nGNgQAIODg4c7u7uQhAemC/j4OBU7ujoGAwRQQB7Z2dHe0fnqUA1BmABT09PPgdHxzkOTk7X7B2dfgLxRQcHZw8g/5y9o2MvSM7eySkXrBgIQkNDmYFqPjo4Ov13cHQ+DzKAHah4vpOTkzxIAdBkAUdH5zKggjcghXZ2LrpgcaBBIBoGgHrWgw1xcroE4jQAbYmESCGAjY2NoKOj0zSgwitAp1sCXdQJkYEAoKVmYEMcnOOBNji9ANpcBJHCBECXGAJdsR9o2S2gRieQV5ydnYWB/OVAXABWBDTkOdBfp8EcHAAYsF4gi4CB3A3UOB/oqlo7OzdFiCwQuLq6SgHDQQTCY2AEKqoB2vwIGB5PQWyQINCAKqAL2EDeAjrGCKQOJI4VAG2qBvsTGTs4JwNdkgU0+B5C3Pk0ksUIAIolRLQhYSenFlA0YhGfDdGJBIAmm2AoxI+vQ3QiAaCTndEUEcDOxyE6kQDQEH1MhXiwg3M+RCcSMDY2ZsUaJlix8xZQeoHoRAPADDUTUwMK/gSOQQcHFogOLACYgGTBCtE0A134FZjAKl1cXPgtLS05sUYvMgCGjT9Q429kQ0CBDpEFpXDHBUCx76BEChHBARwcXFyACp/ADIElcUiRARZ/DHQND0gML/Dx8eECJqgcoFcOAjVdALpgBhAfBubsWeiuAAAqgBshJvfZpgAAAABJRU5ErkJggg==)

Seibel: Outside MIT, a lot of programmers are self-taught. I was an English major and have learned how to program on the fly. Do you have any advice for people who are self-taught? Is there anything they should do, or gaps they should be sure to fill in?

Abelson: Read a lot of good code. That’s the real issue—that people don’t read code.

Seibel: How do you read code? Given a piece of code that you have some reason to believe is good, how do you read it? Do you read top-down and stuff it all into your brain? Do you make diagrams?

Abelson: I try to look for the whole structure and sometimes it’s making diagrams. I tend to read it the way I write it, which is to try and get a top-down structure of what in general is going on. Then you say, “What’s a cool, interesting little piece of that?” and you see what that looks like in terms of style. Then you think about the constraints that each part puts on the other one. I typically do it that way. I get an orientation about what’s going on at all.

Seibel: Are there tricks as it gets bigger? Because in actual practice, lots of code now is big and often people aren’t just reading it for fun—they’re reading it because they have to understand it. Sometimes it’s big and hairy and full of kludges.

Abelson: Typically I’m reading because I’m grading students of mine. Sometimes it’s pretty awful. You think about, “Gee, how would I have structured this project, and how does this structure here match with what I would have done?” And typically it does not. And then you say, “Oh yeah, I see. They did that.” That’s how you get the structure in your head.

Seibel: When you read good code, what do you read for?

Abelson: Well, I like to look at the abstractions that people make, especially, “Wow, this is just great because you made this thing which not only does the job, but it’s really elegant and it’s extensible, and it’s done in a way that just will naturally expand and naturally be debuggable, and it just captures all the abstractions in the right way.” To me that’s what good code looks like.

Seibel: So you read student code for grading. Do you actually regularly read code? What was the last piece of code you read for fun?

Abelson: At Google you read a tremendous amount of code. You have to review code. That’s what I’ve been doing since I’ve been at Google, reading a lot of review stuff.

Seibel: I want to dig a little deeper on this. You, like many other people, say programmers should read code. Yet when I ask what code have you read for fun or edification, you—also like many other people—answer that you read students’ code, which is your job, and review code at Google, which is also your job. But it doesn’t sound like you sit down of an evening with a nice printout and read it.

Abelson: Not for a long time. I used to do that. I certainly did that when I was at MIT. When I was a grad student at MIT and learning how stuff works.

Seibel: And that also seems common—a lot of people I’ve talked to, did, in their so-called larval stage, read a bunch of code and learn a bunch of stuff. And then it seems that after a while they stop.

Abelson: Yeah. I think that’s right. Although one exception is when you want to learn stuff. The wonderful thing about the way the web started out is that you could read the code for any webpage. It’s certainly true that if I want to learn how to do some Javascript thing or make something that’s on a webpage, I find some nice page and read how it’s implemented.

Seibel: So let’s say, just for the sake of argument, that the advice to read code is really meant for newer programmers and that experienced programmers after a while stop reading code, other than tactical reading to figure out how something works. Are there pieces of code that you think new programmers should read? Code people should read because it’s the software equivalent of Shakespeare?

Abelson: Actually not. I mean, there’s stuff that made a big impression on me, but I don’t know that I would say everybody should read it.

Seibel: So if there aren’t specific things that you would canonize, can you give some advice about how to find things to read?

Abelson: Well, I’d say first of all it should be a thing that you’re interested in. Here’s a kind of program I’d like to write and here’s a really beautiful example that I see working. Then I would look at the code for that. I’m not sure I would go out in the abstract and say what’s beautiful code.

Seibel: I’m still curious about this split between what people say and what they actually do. Everyone says, “People should read code” but few people seem to actually do it. I’d be surprised if I interviewed a novelist and asked them what the last novel they had read was, and they said, “Oh, I haven’t really read a novel since I was in grad school.” Writers actually read other writers but it doesn’t seem that programmers really do, even though we say we should.

Abelson: Yeah. You’re right. But remember, a lot of times you crud up a program to make it finally work and do all of the things that you need it to do, so there’s a lot of extraneous stuff around there that isn’t the core idea.

Seibel: So basically you’re saying that in the end, most code isn’t worth reading?

Abelson: Or it’s built from an initial plan or some kind of pseudocode. A lot of the code in books, they have some very cleaned-up version that doesn’t do all the stuff it needs to make it work.

Seibel: I’m thinking of the preface to SICP, where it says, “programs must be written for people to read and only incidentally for machines to execute.” But it seems the reality you just described is that in fact, most programs are written for machines to execute and only incidentally, if at all, for people to read.

Abelson: Well, I think they start out for people to read, because there’s some idea there. You explain stuff. That’s a little bit of what we have in the book. There are some fairly significant programs in the book, like the compiler. And that’s partly because we think the easiest way to explain what it’s doing is to express that in code.

I think if people wrote in Scheme more, there would be more programs for people to read. I think if people wrote in C, there would be fewer programs for people to read.

Seibel: So is there anything we can do to make it possible to deliver software that works and operates in the real world and gets finished in a timely fashion while also improving its readability? You just said, write in Scheme instead of C. Is there anything else?

Abelson: I think much of language design is motivated by that.

Seibel: And do you think that languages have gotten better—do they actually allow more readable code?

Abelson: I think some. You can always crud things up. But I think a lot of the aesthetic around Python is that it should be readable. But the end result is people still write a lot of cruddy Python programs. You can certainly write a mess in any language, but you know, you can also be careful and write things reasonably. I think a lot of the stuff you were talking about—the kind of type stuff where you’re careful about how you define what the data types are, and they’re pretty high-level things that encapsulate stuff—that certainly helps.

But remember all the fights. Remember the fights about how horrible it was that you would do garbage collection. Because any sane programmer knew that you had to do manual memory management. That’s an example of not being readable.

Seibel: Meaning, garbage collection makes things more readable, because it takes away all the gorp having to do with memory management?

Abelson: Right. Because you build some level of abstraction, which takes something whose details are not germane to the ideas you’re trying to get across and then you build a language that suppresses that level of detail. MapReduce is another example of that. That could have been some complicated interface with filtering and mapping, and all kinds of stuff. And now people say, well, MapReduce. Then that becomes an idea that you can start using to build more complicated things.

Right now there are terrible problems with parallelism. And I don’t think there actually are any very good ideas. Maybe the π-calculus is the right thing. But I don’t think there’s really good stuff now going that has to do with that. And _nobody_ understands synchronization.

Seibel: Have you ever done literate programming à la Knuth or read literate programs?

Abelson: Not really. I know the words, but I don’t even know what it is really.

Seibel: What about Knuth’s magnum opus, _The Art of Computer Programming_? It seems like there are people who use it as a reference, a few people who have read the whole thing, and other people who just have it on the shelf. Where are you on that spectrum?

Abelson: When I was an undergraduate at Princeton, I took this one computer science course and it used Volume 1 of _The Art of Computer Programming_. That was in 1968 or something. And I’ve looked at Volume 2 and 3.

Actually, when I was at Princeton, Knuth was visiting that year. If you remember, Knuth laid out the whole whatever it is, eight-volume, eight-book series. We found him walking around campus in ’68 and we said, “Hey, we’re undergraduates and we’re doing this project, and we hear that Volume 4 is going to be about compilers. We want to write a symbol table; could we use the manuscript for Volume 4 to do this?” Knuth said something like, “Well, it’s not quite done yet, but we’re really close. I’m sorry it’s not going to be in time for your class project.”[1](https://web.archive.org/web/20110812181333/https://codequarterly.com/2011/hal-abelson/#note_1)

![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABEAAAASCAYAAAC9+TVUAAACBUlEQVR4nGNgQAIODg4c7u7uQhAemC/j4OBU7ujoGAwRQQB7Z2dHe0fnqUA1BmABT09PPgdHxzkOTk7X7B2dfgLxRQcHZw8g/5y9o2MvSM7eySkXrBgIQkNDmYFqPjo4Ov13cHQ+DzKAHah4vpOTkzxIAdBkAUdH5zKggjcghXZ2LrpgcaBBIBoGgHrWgw1xcroE4jQAbYmESCGAjY2NoKOj0zSgwitAp1sCXdQJkYEAoKVmYEMcnOOBNji9ANpcBJHCBECXGAJdsR9o2S2gRieQV5ydnYWB/OVAXABWBDTkOdBfp8EcHAAYsF4gi4CB3A3UOB/oqlo7OzdFiCwQuLq6SgHDQQTCY2AEKqoB2vwIGB5PQWyQINCAKqAL2EDeAjrGCKQOJI4VAG2qBvsTGTs4JwNdkgU0+B5C3Pk0ksUIAIolRLQhYSenFlA0YhGfDdGJBIAmm2AoxI+vQ3QiAaCTndEUEcDOxyE6kQDQEH1MhXiwg3M+RCcSMDY2ZsUaJlix8xZQeoHoRAPADDUTUwMK/gSOQQcHFogOLACYgGTBCtE0A134FZjAKl1cXPgtLS05sUYvMgCGjT9Q429kQ0CBDpEFpXDHBUCx76BEChHBARwcXFyACp/ADIElcUiRARZ/DHQND0gML/Dx8eECJqgcoFcOAjVdALpgBhAfBubsWeiuAAAqgBshJvfZpgAAAABJRU5ErkJggg==)

Seibel: Suppose someone has taken 6.001 or they’ve read SICP and they understand all the good ideas. Now they’re going to build some big system. Should they choose Scheme? Should they not choose Scheme? Or does it not matter?

Abelson: Oh, at that point it doesn’t matter so much. That’s really a question of the development environment you have and the tools. Certainly at a place like Google, where you have these giant programs people are working on, the language is less important than the development environment and the procedures you have about checking each other’s code.

But that works when people have a general idea of what it’s about. For all I know I’m saying something that is false based on facts, but I would imagine it would be very hard for someone who knew nothing about functional programming to come up with a thing like MapReduce.

Seibel: A phenomenon we in the Common Lisp world experience a lot is that people who’ve had the _Structure and Interpretation of Computer Programming_ course at MIT or somewhere else as their sole exposure to Lisp, come away with this idea, “Oh, Lisp is this toy language that’s mostly used for implementing itself in itself and isn’t that wee and clever.”

Abelson: Right.

Seibel: Which for a Common Lisp person is sort of annoying because Common Lisp is this big, industrial ball of mud that you can do anything in.

Abelson: Right. Exactly. Again, the point of Scheme is to be really, really simple. If you look at the Scheme report, you know, it was very proudly very small as opposed to Common Lisp’s spec, which is a book.

But sure, at some point you have to build more and more infrastructure. I mean, the main thing that Scheme is missing is libraries. It doesn’t have good support for that.

Seibel: Have you kept up with the recent standardization efforts?

Abelson: Yeah. I’ve kept up and I don’t quite know what to think. The book is a lot larger. The manual is a lot larger. R6RS has become a very complicated language. Things are intellectually less clear. The number stuff is very complicated.

Seibel: And is it complicated in a useful way?

Abelson: I don’t know. That’s what I don’t know. But it’s mostly large. I think people eventually move to other languages once they get the point.

Seibel: So this gets to what you said before about making programs readable. If people wrote programs in Scheme rather than C, more software would be readable. And Scheme—at least until recently maybe—was a small and beautiful language.

But can real world programs be written in small beautiful languages? Or because of the gorp that comes in as a result of making things work in the real world, it is actually better to use a language that’s gorpier itself?

Abelson: I don’t know. That’s a great question. I don’t know. I guess what people really want to say is, you keep the beautiful core and then you make a whole bunch of libraries. I don’t have a better answer than that.

Seibel: Have you ever started out to write something in Scheme and then said, I’ve got to use something else?

Abelson: I’ve done some web page stuff where there is stuff in Scheme for putting together web pages which is very beautiful, but pretty limited at the end. But that was mostly because the library wasn’t flushed out. Occasionally you drop into something for speed. But generally the way I think about programs, they’re nicely expressed in Scheme. I can’t get over how hard it is to do callbacks in Java. I think even C# does it much better than that. I can’t believe that languages don’t have lambda in them.

![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABEAAAASCAYAAAC9+TVUAAACBUlEQVR4nGNgQAIODg4c7u7uQhAemC/j4OBU7ujoGAwRQQB7Z2dHe0fnqUA1BmABT09PPgdHxzkOTk7X7B2dfgLxRQcHZw8g/5y9o2MvSM7eySkXrBgIQkNDmYFqPjo4Ov13cHQ+DzKAHah4vpOTkzxIAdBkAUdH5zKggjcghXZ2LrpgcaBBIBoGgHrWgw1xcroE4jQAbYmESCGAjY2NoKOj0zSgwitAp1sCXdQJkYEAoKVmYEMcnOOBNji9ANpcBJHCBECXGAJdsR9o2S2gRieQV5ydnYWB/OVAXABWBDTkOdBfp8EcHAAYsF4gi4CB3A3UOB/oqlo7OzdFiCwQuLq6SgHDQQTCY2AEKqoB2vwIGB5PQWyQINCAKqAL2EDeAjrGCKQOJI4VAG2qBvsTGTs4JwNdkgU0+B5C3Pk0ksUIAIolRLQhYSenFlA0YhGfDdGJBIAmm2AoxI+vQ3QiAaCTndEUEcDOxyE6kQDQEH1MhXiwg3M+RCcSMDY2ZsUaJlix8xZQeoHoRAPADDUTUwMK/gSOQQcHFogOLACYgGTBCtE0A134FZjAKl1cXPgtLS05sUYvMgCGjT9Q429kQ0CBDpEFpXDHBUCx76BEChHBARwcXFyACp/ADIElcUiRARZ/DHQND0gML/Dx8eECJqgcoFcOAjVdALpgBhAfBubsWeiuAAAqgBshJvfZpgAAAABJRU5ErkJggg==)

Seibel: You’ve said that computer science is not about computers and you’ve also said it’s not a science. So, what is the relation in your mind between computer science and programming? Do you have to program to understand computer science or is programming just the brick-laying part of this grander enterprise?

Abelson: I don’t know. Do you have to be able to play an instrument in order to say something about music? There’s certainly people who do that. There are two points of view. One is you say, well, they’re not confused by the details of knowing what it’s actually like, and the other one is, well, they don’t actually have a gut, hands-on appreciation of what the stuff is that you’re saying things about. Certainly, in terms of computer science, there are lots of theoreticians who are outstandingly good and probably haven’t programmed in a long time. But if you look at someone like Knuth, there’s a guy who’s programmed and his theory grows out of that.

Seibel: So to ask it another way, is the purpose of studying computer science to figure out better ways to build software? Ultimately that’s the point, right? Otherwise it would just be math.

Abelson: Well, I don’t know. People have been arguing, probably since von Neumann—probably since Ada Lovelace—about what’s this computer science stuff, and I think people get hung up on it way too much. There’s this powerful phenomenon and there are all sorts of aspects about it, ranging from how it changes society to how you make things happen efficiently at the micro level. It’s funny when you say, “What’s the purpose of that?” I mean, what’s the purpose of doing physics?

Seibel: Well, _purpose_ is maybe a little philosophical. But if you ask a physicist, “What is physics about?”, it’s about understanding the natural universe.

Abelson: Right. Well, you know our take on it—computer science is about formalizing imperative knowledge. The essence of programming is about imperative knowledge. It’s about how to do things. If you really stretch it, it might be that a book on cooking is computer science. But that’s really stretching it. But it’s no different than what we say in the SICP lectures: Mathematics is about how you think about what’s true, following from various axioms. Computing is how you think about how to do things.

Seibel: So if computer science, like all other fields with _science_ in the name, isn’t a science what is it that we’re doing? Engineering? Art? Math? Something completely new?

Abelson: Well, it’s this funny mixture of formalizing knowledge and thinking of ways to do that and then looking at the results of this information communication stuff mixing up with culture and society and the way people interact with each other. And that’s all very complicated and very deep.

I think the future of computer science is at places like Cornell and Michigan and Maryland, where they figured out that they should merge their computer science departments with their information schools.

Seibel: Information schools as in library science?

Abelson: Yeah, they come out of library science. Cornell is a really good example of that. The computer science department, I believe, actually moved out of the school of engineering and now there’s an information/computing merger. I think that’s the direction this is going to go, and some of it will happen formally. Some will happen by people shifting their research focus.

Seibel: In the beginnings of computer science, it seems there were two ways it emerged: it either came out of the math department or it came out of the electrical engineering department. So you got either theoretical, mathy computer science departments or very systems-focused departments, like at Berkeley, building things like Unix.

Abelson: Right. And neither of those are where the important stuff is now. I think the interesting stuff is in this third area.

Seibel: Do you think that the skills required to be a programmer are the same now? Or can different kinds of people now succeed as programmers because there are different kinds of programming that really require different skills?

Abelson: I’m not sure I’m going to answer the question the way you meant it, but I think what’s really important right now is for programmers to know what’s worth making. That’s what I try and focus on in my class. You know some language and you know enough to see the importance of algorithms and you have to be able to look them up and things. But you also have to have some sense of what’s worth making. And that requires understanding about people, and understanding about society, and understanding about the context in which the program is going to be used. That’s what I try to teach when I teach programming.

Seibel: Do you feel like that’s a more recent development because of all of this infrastructure that’s out there—now people can make all sorts of things without spending their whole lives figuring out how to mash machine instructions together by hand?

Abelson: Right. And you end up reusing libraries and modules and all kinds of things.

Seibel: When did you start thinking about this?

Abelson: I really started thinking about it in the second half of the 90s. Because it occurred to me that I could give a programming assignment and some student in my class could write something and it could be used by 50,000 people. It’s this transition between when students write programs mostly for them and maybe the teacher to look at, versus, I could put up something on the web that’s actually useful and could attract a lot of interest. To me, that’s the big difference.

Seibel: Basically the advent of the web?

Abelson: Right. Your programming becomes a much more public act. I think that one of the things that I see in most computer science right now is most computer programming courses still don’t get that. They’re still back in the age of, ‘I’m going to write a program for one person to look at.’

Seibel: So what’s worth making?

Abelson: Make something interesting.

Seibel: And how do you get your students to explore what’s interesting?

Abelson: Well, you give them tools. You give them examples. At MIT, and actually most places, you can stay ahead and give people modules to use that are interesting.

Usually you try and find something feasible—students have these wonderful grandiose things that are great, and you have to find a part that they can make. Sometimes we do programming where you work with a client. That’s part of what you have to learn. That you sit down with a client who has some big idea, and part of what you need to do is shape that into something that actually works.

Seibel: Right. Are those ever in conflict? Certainly it seems in the real world they can be. A client says, I want you to come up with a computer model for some crazy derivative that’s going to make me rich and destroy the economy. Is that worth building?

Abelson: We don’t pick things like that. We have clients apply to us and we do a screening on the clients’ stuff.

A more likely example is you work for half a semester and the students come in and say, “Oh my God, we did exactly what the client said and now the client said that’s not what they wanted at all.” And we say, you know, that’s a good lesson about how you communicate with your client as you’re working.

Seibel: So first they have to cut it down to something that’s feasible, then you have these clients who have been screened to be hopefully more or less worthwhile things to be working on. Is there something that you do to teach your students so that when they go out in the broader world—when they have more skills so more things are feasible and where not all clients actually ask them for good things, that they have whatever intellectual or philosophical tools they need to answer that question of what’s worth building?

Abelson: Well, I tend not to do _that_ level in the programming courses. I teach courses on internet law—ethics and law where we look more at that, but those two courses don’t get combined particularly.

Seibel: Is that the same stuff you talk about in your book _Blown to Bits_?

Abelson: _Blown to Bits_ is sort of an offshoot—we took my ethics and law course, and then dumbed it down so we could teach it at Harvard, and then dumbed it down more so it could be a book. It was really simple at the end of the day. There was a beautiful explanation of Diffie-Hellman—Harry Lewis wrote it and it had one equation. I looked at this thing and said, “My God, what a beautiful, elegant, simple explanation of this thing.” Then the editor came through: “You can’t have an equation there. For every equation in the book you’re going to lose twenty percent of your readership.” So we really cut the technical stuff out of _Blown to Bits_.

The wonderful thing about teaching the ethics and law course at MIT is half of the students are very technically sophisticated. When they think about these things, some of them can actually do projects that are really pretty outstanding.

There’s a great example having to do with privacy that I’m still going around talking about. This was done three years ago, so right now it’s kind of interesting. Three years ago it just pulled us up short.

We had two undergraduates who basically did an analysis of the social networks of MIT undergraduates. What they showed, and by now you’ll say, “Well sure, of course,” was that you can see whether or not someone is gay with a pretty good probability of prediction, eighty-five percent, by looking at the proportion of their Facebook friends who are gay. In fact, I should be careful. That’s only true for males, not females.

They actually built the code and sucked in the Facebook data and did the analysis and they knew enough about probability and Bayesian reasoning to do this thing.

But the cool thing about that is, it says that personal privacy is not personal. The whole way that everybody is thinking about privacy regulation right now is, there’s some stuff about me, and then I get the choice of whether or not to expose that. But this is an example that says, if I’m gay and I decide to out myself, that’s giving the world lots of information about my friends.

So this whole way we think about what privacy means on the Web is rooted in a simplification that’s just wrong. We don’t actually know how to deal with that. The whole legal, regulatory system we have just doesn’t recognize that. That’s the striking thing.

But the other part of it is three years ago when they did this analysis, doing the analysis was striking. Now of course everybody says, “Well yeah, you can go look at Facebook members.” That’s what’s nice about teaching at MIT—you find students who really can do that.

Seibel: In a perfect world would you hope that all programmers would take something like your ethics and law course and have wrestled with those issues before they went out in the world and started slinging code?

Abelson: Well, I hardly want to say all. At MIT, our course is a senior elective. But typically it is taken by all kinds of people—say, by people wanting to go to law school. In general, what I like is for people to build on their technical experience.

An example of a very good project—a few years ago when people were just starting to use Twitter these students became some of the first Twitter users and did a really good security analysis of privacy in Twitter. Because they did understand that stuff, they could do a real technical analysis.

Seibel: Is that similar to Lawrence Lessig’s stuff about the relation between technical architecture and the results on society?

Abelson: I taught joint courses with Larry at Harvard and MIT when he was first writing that book, so yeah, there was this sense of the way the code and the architecture are designed constrains how it’s going to be used. That philosophy was throughout the course. But the stuff I was looking at ends up being a lot more technical than that.

Another example is when the subway in Boston first was going to put in RFID cards. We had students do a technical analysis of the RFID system and the privacy risks. They actually worked as volunteer staff for one of the state senators, talking with the people who run the T[2](https://web.archive.org/web/20110812181333/https://codequarterly.com/2011/hal-abelson/#note_2) in Boston and showing them some of the actual technical risks in the infrastructure they’d set up.

![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABEAAAASCAYAAAC9+TVUAAACBUlEQVR4nGNgQAIODg4c7u7uQhAemC/j4OBU7ujoGAwRQQB7Z2dHe0fnqUA1BmABT09PPgdHxzkOTk7X7B2dfgLxRQcHZw8g/5y9o2MvSM7eySkXrBgIQkNDmYFqPjo4Ov13cHQ+DzKAHah4vpOTkzxIAdBkAUdH5zKggjcghXZ2LrpgcaBBIBoGgHrWgw1xcroE4jQAbYmESCGAjY2NoKOj0zSgwitAp1sCXdQJkYEAoKVmYEMcnOOBNji9ANpcBJHCBECXGAJdsR9o2S2gRieQV5ydnYWB/OVAXABWBDTkOdBfp8EcHAAYsF4gi4CB3A3UOB/oqlo7OzdFiCwQuLq6SgHDQQTCY2AEKqoB2vwIGB5PQWyQINCAKqAL2EDeAjrGCKQOJI4VAG2qBvsTGTs4JwNdkgU0+B5C3Pk0ksUIAIolRLQhYSenFlA0YhGfDdGJBIAmm2AoxI+vQ3QiAaCTndEUEcDOxyE6kQDQEH1MhXiwg3M+RCcSMDY2ZsUaJlix8xZQeoHoRAPADDUTUwMK/gSOQQcHFogOLACYgGTBCtE0A134FZjAKl1cXPgtLS05sUYvMgCGjT9Q429kQ0CBDpEFpXDHBUCx76BEChHBARwcXFyACp/ADIElcUiRARZ/DHQND0gML/Dx8eECJqgcoFcOAjVdALpgBhAfBubsWeiuAAAqgBshJvfZpgAAAABJRU5ErkJggg==)

Seibel: In addition to teaching programming to MIT students, you’ve also been involved in a couple projects, first Logo and now App Inventor for Android, that seem like attempts to make programming more accessible to folks who might otherwise not think of programming as something they can do.

Abelson: When we were doing Logo, we were thinking about teaching mathematics—give kids a place where they can interact with stuff formally and think about bugs and how they get around them. So the notion of Logo, initially, wasn’t that you could make the computer do pretty things or stuff like that—it was putting kids in a place where thinking formally pays off.

If you look at the very original papers of Seymour Papert and Cynthia Solomon, they were called things like “Teaching Children Thinking”. That was the motivation all the way through. That was the motivation when Andy diSessa and I wrote _Turtle Geometry_. It was saying that by taking stuff and expressing it procedurally you can get at the fundamental ideas. In fact Gerry Sussman and Jack Wisdom wrote a book called _Structure and Interpretation of Classical Mechanics_, which is exactly the same motivation, but now in analytical mechanics.

Seibel: So that’s using programming as a way of exploring a topic.

Abelson: Partly exploring and partly expressing.

Seibel: But it gives you a way to understand a field that exists. Geometry exists. Classical mechanics exists. And some of the Logo stuff also had to do with grammar.

Abelson: Yeah, right, that was the original. When there were no displays, it was easier to do that.

Seibel: And math seems particularly well-suited to that. It’s a field that you can explore because it is a formal field. You use a different formalism so you can experience it in a way that’s very different.

Abelson: Right.

Seibel: What about the idea that learning to program is itself an interesting and different way of thinking? We all learn how to read and write. We all learn, hopefully, to do some math. Is programming another thing that teaches you a new way of thinking that’s useful, even for people who don’t end up being programmers?

Abelson: I think the important part of it is there are ways of organizing things. I guess you can call that programming. There’s the notion that things can be described recursively. It’s cool and powerful. But it has nothing to do with programming. Who are your ancestors? Your ancestors are your mother and your father and their ancestors. That’s just a cool thing, whether you’re writing a computer program or just as a way to wrap your mind around that idea.

Programming has a lot of stuff like that, mostly around, ‘Can I wrap something up and name it?’ ‘Can I parametrize stuff?’ Those are hard—well, maybe not hard, but certainly non-obvious ideas. Turing invented the idea of the subroutine, and it took somebody as smart as him to do that. It’s not like it was sitting around as an obvious thing.

Seibel: Let’s talk a bit about your latest project, App Inventor, a tool that allows non-programmers to build apps for Android phones.

Abelson: App Inventor is cool. The way App Inventor works is that you sit at a browser and there’s a GUI in the browser. And you want to put a button on the phone so you drag out a button and put it on the image of the phone. Then there’s another piece—I don’t know if you know Scratch; it’s sort of like that—where there are blocks and you drag them around and you hook them together. Then there’s the thing that goes from those blocks you drag around and the components you pick on the designer GUI, and it gets stuffed into the phone.

Seibel: So the blocks represent the program and the GUI is the GUI?

Abelson: Right. The GUI says, “I’ve got a button and it’s here, and I’ve got a label and it’s here. And, oh yeah, there’s an accelerometer and it’s part of this thing, but I don’t see it.” Then the blocks say, “Oh gee, the accelerometer is an object, and it has a method that says how fast are you falling or are you being shaken and there’s an event,” and the button has a thing that says, “Am I pressed?”

The architecture of that is, stuff that is happening in the GUI, through the browser, is written in Java with Google Web Toolkit. The blocks editor—the thing that looks like Scratch—is written in Java. The thing that’s the accelerometer is a very thin layer on top of the Android Java accelerometer component. These components are written in Java and run directly on Android.

Those blocks you push around get parsed essentially into a very thin layer over Scheme. There is an implementation of Scheme in Java called Kawa. The blocks get translated into Kawa then that gets compiled into Java and pushed to the phone. There’s actually an interactive way to do it, where you have a read-eval-print-loop running on the phone and then what passes on the wire between the computer and the phone is Scheme.

When you move blocks around on the computer, it’s parsing your blocks into Scheme, and it goes over the wire to a REPL that’s running on the phone.

Seibel: So you’re basically generating Scheme via blocks.

Abelson: Yeah, it’s just the syntax, if you like. There’s a little more crap because errors don’t come back, but that’s basically what’s going on. Then there’s some backend web server stuff, a little bit that’s done in Python.

I don’t know—what language is that in? It’s partly Java and a little bit of Python. The layer on the phone, that’s not pure Kawa—we’re a little more careful about things like runtime type errors. The problem is, when you’re pushing to a compiled environment like the phone and this language is for kids, you’d rather not have every runtime type error crash the application.

The phone is running a REPL in Kawa—actually, a slightly higher-level interface, but only slightly. It does things like more careful type checking before you pass arguments around. And a couple of operations that are in Scheme that are not in Kawa, like `foreach`.

Seibel: Type checking in the sense of, if you call `CAR`, make sure it’s a cons.

Abelson: Well, we do that, too, but mostly things like one of the things we did in Logo—we buried the difference between the character string “123” and the number 123. It does that same amount of conversion, a lot of automatic conversion, but it’s a really thin layer on top of Scheme.

So it’s all of those languages. You go back and forth. There’s a part that’s a Scheme program. The bulk of it is in Java. Some of the Java is doing Swing and some of the Java is using Google Web Toolkit.

Seibel: And the part that’s in Scheme, is that due to your influence? Did you start the project?

Abelson: I started the project, but actually the other guy—who is the development lead on it, a guy named Mark Friedman who actually used to be at MIT a long time ago—he said, “Well, the way to do this is, there’s this Kawa thing,” because we were thinking what’s the glue layer on the Android phone. Pretty early in the game we decided it needed an architecture something like that.

At the very beginning we looked at Python S60, I think—there are a couple of Pythons that people were writing for Android when we started the project a year and a half ago. But then this Kawa thing came up and we said, “Well, good, it’s Scheme. We know Scheme.”

Seibel: And you want a language running on the phone to give you a level of dynamism that you wouldn’t get by just shipping class files down to the phone?

Abelson: Yes. We understand the flexibility. It’s nice orthogonality in how you make the trade-offs. You can have procedures and higher-order procedures. With our architecture, for us that’s totally a question of what syntax we want to use in the blocks to represent higher-order procedures, because if you want to go pass that into the Scheme that’s running on the phone, you can do it.

In our case, the fact that we haven’t done it is for the same reason Mitch Resnick hasn’t done it in Scratch—it’s that we’re not sure how early we want to expose that to people.

Seibel: So I played a little bit with App Inventor, and it’s obviously designed to allow people to experience programming who maybe wouldn’t otherwise. Who are you really aiming that at?

Abelson: When we built it, we were thinking high school students and beginning college students, and that’s still true. But what’s happened is, now there’s a whole bunch of amateurs who’ve gotten interested in App Inventor, saying, “I’d like to be able to make some little application just for fun or just to share with my family or something.” Just to get the feeling, in this new world of computing, what it’s like to actually make something. I think that tends to be the majority of people we’re looking at now. The interested amateur who would like to do something.

Seibel: So, amateur in the sense that they’ve never programmed before, maybe akin to the people who learned to build websites back in the early 90s.

Abelson: Yeah. That’s a good analogy. It’s never going to be the professional stuff, but you get the feeling that, ”I made something.” I personalized it to me. I have some sense that I can control this technology. And maybe I make something that’s fun and useful.

Seibel: Right. So I have to say—and I don’t know how much of this is because I didn’t really become an expert at using it in the little time I spent playing with it, or just because I know how to program in other ways—but I found that although the visual programming with the blocks editor was pretty slick, it was still very painful to use.

Abelson: Because you feel like it’d just be easier if you could type?

Seibel: Right.

Abelson: Yeah. That’s the thing that we’re playing with now. The real value of the visual thing for beginners is that you don’t make syntax errors—it’s so constrained. The visual thing is tremendously constraining about what you can put together, and the flip side of that is that you want something that’s more flexible and easier to deal with. So we’re playing around with, is there an alternate text language? We might make a language that looks like Python or something. But at the moment, we’re looking at people who really need that beginning. That really, really makes a difference to people at the very beginning.

Seibel: Have you had people who’ve played with it enough that they’ve gotten to the point where they say, “Okay, this was very useful; I’m glad I had this, and it got me going at the beginning, but there’s got to be a better way to do this”? Or do folks stay happy with it?

Abelson: No. Experienced people say, “Well, this is really cool, and I see the point, but I really wish I could just type this program.” We’ll probably have some way that people can do that. It’s just that that’s not what we’re focused on right now.

Seibel: I was thinking even if you wanted to constrain it, perhaps something text-based, like a structure editor, à la Interlisp.

Abelson: Right. I’ve used some stuff like that where, as you type an expression, it immediately says, “Geez, that’s one of the primitives I know about.” And then in a totally textual way, it doesn’t let you make those kind of errors much.

The issue with App Inventor is that we’re simultaneously being pulled to make it more simple and more powerful. What you’re saying is a good example of that. You’re asking, is there a text-based input to it? The other side of the coin is, there’s a whole bunch of people who say that the system we have now is just way too complicated.

And then there are people like you, saying, “Gosh, why can’t I just write text and import it?” Or why can’t it do all of these other things? And why can’t it do everything that I know the Android phone can do?

Seibel: Right. Perhaps the answer is, you shouldn’t listen to people like me because if I really want to program, I know how to do it.

Abelson: Well, yeah. There’s really a question of how you position it. But it is true that even if we end up listening to people like you, our first task is to make that threshold lower.

App Inventor has a somewhat different motivation than Logo. If you go back to the mid-80s when personal computers first came out, there was just this enormous sense of you could give kids power over this thing. It was so cool.

Computers had been million-dollar machines—and those were the cheap ones. When the personal computer appeared, suddenly kids could take advantage of that power and be part of it and control it and learn to negotiate that world—that was just amazing. Most of the people who are in educational computing have that motivation.

But here’s the weird thing: these smart phones with location awareness, and all of the stuff about social networks—that’s the reality of computer technology for kids, and it’s the future of this stuff—but there just isn’t the thought that we can empower kids in this world of mobility in the same way that in the 80s we talked about empowering them in the world of personal computing.

It’s actually a little bit scary to me, because what it’s saying is that the next generation gets introduced to this technology purely as a consumer product. There just isn’t the idea that my cell phone is something I might want to program. There isn’t the idea that the way I interact with my friends is something that I could make or my friends could make. That’s what’s motivating App Inventor.

We can give people the idea that this stuff could be programmable—App Inventor is a demonstration of that. Then it’s cool if I actually do want to teach kids about technology and programming—it’s just cool you can do it with cell phones because, after all, these other computer things are boring things that nobody uses anymore, ancient technologies like email.

Seibel: It seems that maybe that tide is going to be hard to stem at this point—that there are going to be all these cool devices but they’re not going to be programmable; they’ll be sealed boxes that do what they do.

Abelson: Right. And it has real implications. One of the places that used App Inventor in the fall is Wellesley. We picked many schools that were doing this thing called CS0. I don’t know if you know that jargon—CS0 is the first computing course you give to people where they don’t know how to program, and you don’t actually expect them to go into computing. They learn a little bit about technology. That’s what CS0 is.

That’s the place these days—in colleges—where you can innovate, because nobody knows what they want to teach, and there’s a tremendous hunger for it. Everybody wants it. We picked CS0 because we wanted something that would happen in the fall. It’s not often you can introduce a thing and say, “Well, we don’t actually have this thing working yet, and it’s June, and we’re going to get a prototype for you by August, but we’d like you to teach a course in it.” That’s hard to do, but you can do it in CS0.

In any case, Wellesley did a CS0 course, a really nice example. It was a little bit about empowerment and a little bit about giving a sense of how this technology could work and what the issues were. The example I really like was, they built a polling application. There’s a really simple app on the phone; it goes over the net and gets the latest poll and says, “Here are four choices. Which one do you want?”

Then there’s a backend, which is a server side that let’s somebody say, “I want to open a new poll, and I want to collect the responses, and I want to see the results.” This really neat thing happened at Wellesley, because suddenly everybody is walking around campus with the ability to take instant polls on anything. But in class they would look at the other end. They said, “Oh, here’s the pie chart of how people picked their favorite female vocalist or something. And guess what: here’s how everybody voted.” And there was just a moment of shock that goes through the class.

Seibel: You mean voting was not anonymous.

Abelson: The idea was that it was their choice as the implementer of this system to decide whether or not it was anonymous. And either anonymous so they couldn’t see each other’s responses or anonymous so that the person running the poll couldn’t actually see how people voted. That sounds obvious to us, but to that group that’s a revelation because they have no idea how this technology works.

And that’s a little bit about what I mean by empowerment. I would assume that most people in the country have no idea that the person collecting the votes could see how people voted. So it comes down to a political thing which is, is this going to be a technology of empowerment, or is it going to be a consumer technology where you have no idea what is happening at the other end? App Inventor is a little bit motivated by that.

Seibel: So let’s say we end up in this world where companies just want to make money off of these things, and they don’t really care whether people can tinker with them. How bad is that? Maybe it’s a pity that these cool devices that are, in fact, general-purpose computers aren’t going to be an avenue for people to tinker, but maybe the people who are going to tinker are just going to tinker with something else. On the other hand, maybe we’ve come out of this golden moment when we had computers on our desks that were pretty general-purpose and people really could do stuff, and that’s ending.

Abelson: I think that expresses it really well. I remember people in the 80s even talking about it that way. I remember someone talking about how there was this golden moment in music when the piano first came out. Suddenly there was this thing that lots of people could have that could play both loud and soft, and it was this enormous thing. That was the period where Mozart arose and lots of composers arose. They were saying, “Well, gee, aren’t we now in a period that’s sort of like that with respect to this computing, and we can see all these new Mozarts of programming happening?”

I think it would be a little worse than unfortunate if we didn’t do that around these very intrusive, very personal devices. I guess we could give civics courses in what’s known about you when you vote online. We’re seeing now the equivalent of the civics course, going through with all these gyrations around Facebook and Buzz and all these things. But at the moment the attitude is, well, there are these horrible things happening which nobody understands.

Seibel: So you think if people had more ability to tinker, they would end up with a more natural understanding of these issues?

Abelson: Partly a more natural understanding. And they might make other things. You read—in terms of the Facebook thing—some blogs that say, “Well, the real way to do this is, there should be some distributed system where you just put up your own little server with your own information in that.” But the notion of lots and lots of people doing that, or even understanding what it means, is already just a fantasy.

Seibel: So you’re saying it would be good if more people understood, at least in theory, how to do that, or understood that there was a possibility to do these things in other ways?

Abelson: Right, basically if people had a sense of what’s going on, and had a sense that, “I’m more than just somebody who’s helpless in the face of people doing things I don’t understand.”

Seibel: Is there some level of understanding about programming and computers that you need to understand because so much of our lives is now mediated through them or controlled by them?

Abelson: There’s a whole buzzword called “computational thinking”. The National Academy pulled together a workshop of everybody talking about it. If you look in that, there’s a whole group saying exactly what you’re saying: you should be teaching about computing and computational thinking, because this is a world of technology, and people should have some understanding and mastery of their world.

Seibel: Do you think that’s reasonable?

Abelson: Well, I think it’s a wonderful, noble goal.

Seibel: There’s another perspective on this, though. You’ve taught computer science and programming to MIT students, which is already not a random sample of the population. And you mentioned that in the new course, the folks who really want to do circuit design hate the five weeks of programming. So it’s fine to say, everybody should learn a little bit about how to program and this way of thinking because it’s valuable and important. But then maybe that’s just not realistic. Donald Knuth told me that he thinks two percent of the population have brains wired the right way to think about programming.

Abelson: That same logic would lead you to say that one percent of the US’s population is wired to understand Mandarin. The reasoning there is equivalent.

Seibel: You think if we grew up in a culture where programming was somehow pervasive, everybody would be able to do it?

Abelson: Well, that was the original idea of Logo. Papert came up with this notion called Mathland. That’s what Mathland was. He said if you looked at schools teaching languages, you’d figure there was just this inherent, innate ability to learn French, and only two percent of the population of Americans had it. So he said, “What Logo is trying to build is the equivalent math country, where if you grew up there, you would speak math.”

Seibel: Right. But it’s not entirely clear that that theory ever played out the way he promised.

Abelson: It’s not entirely clear. I don’t know if you know a very famous French mathematician named Jean Dieudonné, one of the top French mathematicians in the 60s who later on got interested in education. And I remember Papert talking about Logo at a Math International conference. Dieudonné, who was _the_ big poobah there, basically said, “You’re entirely wrong. Your goal is completely wrong. You’re trying to do this education and make it intuitive, but in fact all you’re doing is providing people with a crutch so they’ll think they understand it and they really won’t, and the actual goal of math education should be to identify the two percent of the population who can really do it.” Papert, I think, just didn’t know how to respond. But there really is some truth in the middle there.

![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABEAAAASCAYAAAC9+TVUAAACBUlEQVR4nGNgQAIODg4c7u7uQhAemC/j4OBU7ujoGAwRQQB7Z2dHe0fnqUA1BmABT09PPgdHxzkOTk7X7B2dfgLxRQcHZw8g/5y9o2MvSM7eySkXrBgIQkNDmYFqPjo4Ov13cHQ+DzKAHah4vpOTkzxIAdBkAUdH5zKggjcghXZ2LrpgcaBBIBoGgHrWgw1xcroE4jQAbYmESCGAjY2NoKOj0zSgwitAp1sCXdQJkYEAoKVmYEMcnOOBNji9ANpcBJHCBECXGAJdsR9o2S2gRieQV5ydnYWB/OVAXABWBDTkOdBfp8EcHAAYsF4gi4CB3A3UOB/oqlo7OzdFiCwQuLq6SgHDQQTCY2AEKqoB2vwIGB5PQWyQINCAKqAL2EDeAjrGCKQOJI4VAG2qBvsTGTs4JwNdkgU0+B5C3Pk0ksUIAIolRLQhYSenFlA0YhGfDdGJBIAmm2AoxI+vQ3QiAaCTndEUEcDOxyE6kQDQEH1MhXiwg3M+RCcSMDY2ZsUaJlix8xZQeoHoRAPADDUTUwMK/gSOQQcHFogOLACYgGTBCtE0A134FZjAKl1cXPgtLS05sUYvMgCGjT9Q429kQ0CBDpEFpXDHBUCx76BEChHBARwcXFyACp/ADIElcUiRARZ/DHQND0gML/Dx8eECJqgcoFcOAjVdALpgBhAfBubsWeiuAAAqgBshJvfZpgAAAABJRU5ErkJggg==)

Seibel: On a different topic: you said before that, “Programming is about creating a language in which to express the things you want to do.” What do you mean by “create a language”? Because different programmers might hear that in very different ways. Some people would say if you define an API, you’re defining a new language.

Abelson: Well, I’d certainly say that. I think it’s the way you think about it. Going back to what’s written in the book, the way I think about it is, you define some primitive objects you’re going to work with and you talk about how they’re going to be combined. And then, if you’re lucky, you can talk about how those are going to be abstracted.

Say I want to build some sort of windowing thing. Then I ask, what are the pieces and how do I put them together? How do I put them on the screen? How do they interact? I’d certainly say that’s defining a language.

Seibel: So it’s not necessary to go the route of Lispers, who say, “Oh, the great thing about Lisp is it’s easy to define languages because you can define new syntax.”

Abelson: Right. It’s not only defining syntax. The great thing about Lisp is that there’s this very standard plumbing called functional composition. That’s the other part of a language—it’s not just the primitives—it’s how you compose them. And Lisp was particularly good at that.

Seibel: Though in most languages these days you can write functions and call them and so forth. Is it the higher-order functions that really make that powerful?

Abelson: Well, the higher-order functions help. Then you get to make the function an object that you can pass around. But it’s also that—and you can think of this as a plus or a minus—that if I write a function and I have to define what types it works on, then it’s less general unless I’m very careful about making things generic. If I defined—let’s take a stupid example—if I define _maximum_ and I have to worry about whether I’m taking maximum of integers or floating point numbers or singles or doubles or something, that becomes a thing that impedes me from using an idea like _maximum_. Although of course, Java has already fixed that because they’ve made it generic at that level. But there are more complicated things where you can’t just do that.

Seibel: And so basically the dynamic typing of Lisp allows you to do that?

Abelson: Right. Dynamic typing lets you do that. You can argue about genericity and polymorphic stuff. But what you need is to be able to look at the means of combination itself as something that can be general and not only restricted to a particular data type.

Seibel: And so the important means of combination here, in functions, is basically APPLY.

Abelson: Right. That’s why Lisp is good, because Lisp basically has this very general thing called functional composition, and people construct things out of that. It becomes pretty easy to make this interoperable stuff.

Seibel: Can you give me an example of a language that interferes with that?

Abelson: Most anything I do in Java interferes with that.

Seibel: But any method in Java can call any other method.

Abelson: If I know the type. I can’t write the idea—just to give you a stupid example—“Multiply something by four by adding it to itself four times.”

Seibel: So Java people would say, “Okay, if that’s really what you want to do, you can do that on any type that supports addition.” And you can define an interface, `Addable`. Maybe there’s a little bit of gorp you’ve got to do, but you can do it.

Abelson: That’s right. It’s the amount of gorp you’ve got to do. Compare that with Python, where I define four times _x_ as `x + x + x + x`. And if I meant strings to be concatenation, it does that. Of course, you can do that in Java if you try hard enough, but it’s not the most natural thing to do.

Seibel: Right. Though in Scheme, it’s not like this is free. You’d have to, as you do in the book, put in a layer of dispatching if you really want it to be general. You have to have tagged types or something to say what addition means.

Abelson: Right. I’d have to say what addition means. That’s because, well, in Scheme addition doesn’t mean anything for strings.

Seibel: What about macros? Scheme has macros but they don’t seem to be as much a part of the culture as they are in, say, Common Lisp.

Abelson: I stopped being part of the Scheme macro argument about ten years ago. I always thought macros were tremendously important. But there were a whole bunch of people who were much more careful about how they should work than I was—things like renaming and how all that should happen. I think they did a really good job. But it took a long time for it to come out.

Seibel: I guess the Schemers were willing to do without a standard until they could figure out “The Right Way” to do it.

Abelson: That’s right. There were arguments in the Scheme community that said, “Well, the point of Scheme is to figure out the right way to do it, whereas the point of Common Lisp was, you put any old junk into it.” There are people who held that position. But you want to do syntactic abstraction—macros let you do syntactic abstraction.

![](data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAABEAAAASCAYAAAC9+TVUAAACBUlEQVR4nGNgQAIODg4c7u7uQhAemC/j4OBU7ujoGAwRQQB7Z2dHe0fnqUA1BmABT09PPgdHxzkOTk7X7B2dfgLxRQcHZw8g/5y9o2MvSM7eySkXrBgIQkNDmYFqPjo4Ov13cHQ+DzKAHah4vpOTkzxIAdBkAUdH5zKggjcghXZ2LrpgcaBBIBoGgHrWgw1xcroE4jQAbYmESCGAjY2NoKOj0zSgwitAp1sCXdQJkYEAoKVmYEMcnOOBNji9ANpcBJHCBECXGAJdsR9o2S2gRieQV5ydnYWB/OVAXABWBDTkOdBfp8EcHAAYsF4gi4CB3A3UOB/oqlo7OzdFiCwQuLq6SgHDQQTCY2AEKqoB2vwIGB5PQWyQINCAKqAL2EDeAjrGCKQOJI4VAG2qBvsTGTs4JwNdkgU0+B5C3Pk0ksUIAIolRLQhYSenFlA0YhGfDdGJBIAmm2AoxI+vQ3QiAaCTndEUEcDOxyE6kQDQEH1MhXiwg3M+RCcSMDY2ZsUaJlix8xZQeoHoRAPADDUTUwMK/gSOQQcHFogOLACYgGTBCtE0A134FZjAKl1cXPgtLS05sUYvMgCGjT9Q429kQ0CBDpEFpXDHBUCx76BEChHBARwcXFyACp/ADIElcUiRARZ/DHQND0gML/Dx8eECJqgcoFcOAjVdALpgBhAfBubsWeiuAAAqgBshJvfZpgAAAABJRU5ErkJggg==)

Seibel: Do you still enjoy programming as much as you used to?

Abelson: Oh, I’m having a blast. That’s what I’m doing here at Google.

Seibel: You mean it’s more programming than you would normally get to do?

Abelson: Oh, way more. I’ve decided that from now on, I should be measuring the quality of my life by the ratio of the amount of time spent programming to the amount of time sitting in meetings.

Seibel: And where does teaching fit into that?

Abelson: Teaching is kind of like programming, but I’m not doing any teaching at Google so I haven’t thought about that. But I have wildly reduced my time sitting in meetings.

Seibel: And do you find at all that programming is a young person’s game? Are you a better programmer now than you used to be? The same? Or worse?

Abelson: I think I’m better. Until I came here, I’d never written any large Java programs. One of the things I’m learning here is the experience of working on these enormous programs. I just never experienced that before. Previously a large program to me was a hundred pages or something. Now that’s a tiny, little thing.

And a lot of that, of course, has to do with the tools and the organization. I never actually used this stuff before. It’s pretty impressive.

Seibel: Do you think you’ll go back and teach MIT students differently as a consequence?

Abelson: I don’t know. I don’t know, because the reality is we don’t have those tools for students, certainly not in the course that I’m doing. Maybe. I don’t know.

Seibel: Having just spent a year at Google, do you feel the software industry is a horrible mess or a brilliant engine of innovation? Or something in the middle? Sometimes it feels like, wow, we just run around reinventing the wheel, and doing things in horrible, broken ways, and that’s terrible, we should be doing much better. But on the other hand, there’s all this amazing stuff in the world today.

Abelson: Yeah, well, that’s it. We’re making all this hairy stuff. One of the things that I’ve started to understand in these languages is the incredible importance of the development environment. I couldn’t even begin to program in Java without Eclipse. I mean, it’s just such an enormously complex thing, and you are using imports and libraries and interfaces so much. I wouldn’t know how to manage it without an IDE. That’s the thing that I didn’t appreciate enough before coming to a place like Google.

I don’t quite know what to say. Everyone wants to do something greater, and greater, and greater, but we’re making this stuff that seems to work. It might be that all we’re doing is getting closer to the edge of the cliff and making the risk of failure more as we build on these things.

Seibel: Do you have any predictions or hopes for the future of our field?

Abelson: I’m really hung up on this convergence of computing and information science. I think you really need people who understand what kinds of programs are worthwhile making. Cornell has this nice phrase where they talk about programming inside the box and programming outside the box. And inside the box is where you focus on how compilers work and everything—how the stuff is put together—the classical stuff. And programming outside the box is, how do you make this stuff, and what’s its impact on the people using it, and what’s its impact on the world. My own hope for computer science is that we pay attention to what’s going on outside the box. I think that’s what needs to be really part of the education of people doing just any kind of computing.

[1](https://web.archive.org/web/20110812181333/https://codequarterly.com/2011/hal-abelson/#noteref_1) The first part of Volume 4 was released in 2011. —_Editor_

[2](https://web.archive.org/web/20110812181333/https://codequarterly.com/2011/hal-abelson/#noteref_2) The name of the Boston subway system
