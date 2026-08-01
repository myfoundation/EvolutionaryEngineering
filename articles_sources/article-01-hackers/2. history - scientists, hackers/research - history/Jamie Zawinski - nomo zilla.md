---
created: 2026-07-30T12:23:27 (UTC +03:00)
tags: []
source: https://www.jwz.org/gruntle/nomo.html
author: 
---

# nomo zilla

> ## Excerpt
> resignation and postmortem.
 
   © 1999 Jamie Zawinski
   <jwz@jwz.org>

---
**resignation and postmortem.**  
© 1999 [Jamie Zawinski](https://www.jwz.org/gruntle/) [<jwz@jwz.org>](https://www.jwz.org/about.html)

___

April 1st, 1999 will be my last day as an employee of the Netscape Communications division of America Online, and my last day working for mozilla.org.

Netscape has been a great disappointment to me for quite some time. When we started this company, we were out to change the world. And we did that. Without us, the change probably would have happened anyway, maybe six months or a year later, and who-knows-what would have played out differently. But we were the ones who actually did it. When you see URLs on grocery bags, on billboards, on the sides of trucks, at the end of movie credits just after the studio logos -- that was us, we did that. We put the Internet in the hands of normal people. We kick-started a new communications medium. We changed the world.

But we did that in 1994 and 1995. What we did from 1996 through 1999 was coast along, riding the wave caused by what we did before.

Why? Because the company stopped innovating. The company got big, and big companies just aren't creative. There exist counterexamples to this, but in general, great things are accomplished by small groups of people who are _driven_, who have unity of purpose. The more people involved, the slower and stupider their union is.

And there's another factor involved, which is that you can divide our industry into two kinds of people: those who want to go work for a company to make it successful, and those who want to go work for a successful company. Netscape's early success and rapid growth caused us to stop getting the former and start getting the latter.

In January 1998, Netscape hit one of of its blackest periods -- the first round of layoffs. It was quite a wake-up call. Netscape, darling of the computer industry, the fastest-growing company in the world, was not invincible.

More concretely, this was when we realized that we had finally lost the so called \`\`browser war.'' Microsoft had succeeded in destroying that market. It was no longer possible for anyone to sell web browsers for money. Our first product, our flagship product, was heading quickly toward irrelevance.

And then the unexpected happened: the executive staff decided to release the source code. I won't re-hash the history of the creation of the mozilla.org project, but suffice it to say that, coming as it did only two weeks after the layoffs, it was a beacon of hope to me. Here was Netscape doing something daring again: here was the company making the kind of change in strategy that I never thought they'd be able to make again. An act of desperation? Perhaps, but still a very interesting and unexpected one. It was so crazy, it just might work. I took my cue and ran with it, registering the domain that night, designing the structure of the organization, writing the first version of the web site, and, along with my co-conspirators, explaining to room after room of Netscape employees and managers how free software worked, and what we had to do to make it work.

At this point, I strongly believed that Netscape was no longer capable of shipping products. Netscape's engineering department had lost the single-minded focus we once had, on shipping something useful and doing it fast. That was no longer happening. Netscape was shipping garbage, and shipping it late.

And daring move or no, this was not going to change: Netscape no longer had the talent, either in engineering or management, to ship quality products. The magic was gone, as the magicians had either moved on to more compelling companies, or were having their voices lost in the din of the crowd, swamped by the mediocrity around them.

The Netscape I cared about was dead.

But I saw mozilla.org as a chance to jettison an escape pod -- to give the code we had all worked so hard on a chance to live on beyond the death of Netscape, and chance to continue to have some relevance to the world.

Beyond that, I saw it as a chance for the code to actually _prosper._ By making it not be a Netscape project, but rather, be a public project to which Netscape was merely a contributor, the fact that Netscape was no longer capable of building products wouldn't matter: the outsiders would show Netscape how it's done. By putting control of the web browser into the hands of anyone who cared to step up to the task, we would ensure that those people would keep it going, out of their own self-interest.

But that didn't happen. For whatever reason, the project was not adopted by the outside. It remained a Netscape project. Now, this was still a positive change -- it meant that Netscape was developing this project out in the open, in full view of the world, and the world was giving important and effective feedback. Netscape made better decisions as a result.

But it wasn't enough.

The truth is that, by virtue of the fact that the contributors to the Mozilla project included about a hundred full-time Netscape developers, and about thirty part-time outsiders, the project still belonged wholly to Netscape -- because only those who write the code truly control the project.

And here we are, a year later. And we haven't even shipped a beta yet.

In my humble but correct opinion, we should have shipped Netscape Navigator 5.0 no later than six months after the source code was released. But we (the mozilla.org group) couldn't figure out a way to make that happen. I accept my share of responsibility for this, and consider this a personal failure. However, I don't know what I could have done differently.

I can come up with a litany of excuses and explanations for why we are so late (heaven knows I've been making these excuses to the media for half the lifetime of the project.) Some of them are:

**Excuse #1:**

It's a really large project, and it takes a long time for a new developer to dive in and start contributing.

**Excuse #1a:**

Because of this, what happens is, someone will try to make a small change, find that it's taking them longer than a few hours, and will give up and do something else instead.

**Excuse #2:**

People only really contribute when they get something out of it. When someone is first beginning to contribute, they especially need to see some kind of payback, some kind of positive reinforcement, right away. For example, if someone were running a web browser, then stopped, added a simple new command to the source, recompiled, and had that same web browser _plus their addition_, they would be motivated to do this again, and possibly to tackle even larger projects.

We never got there. We never distributed the source code to a working web browser, more importantly, to _the web browser that people were actually using._ We didn't release the source code to the most-previous-release of Netscape Navigator: instead, we released what we had at the time, which had a number of incomplete features, and lots and lots of bugs. And of course we weren't able to release any Java or crypto code at all.

What we released was a large pile of interesting code, but it didn't much resemble something you could actually use.

**Excuse #3:**

The code was just too complicated and crufty and hard to modify, which is why people didn't contribute. This was a believable excuse for a while, which is why, six months ago, we switched from the old layout engine to the new layout engine (Gecko/Raptor). By being a cleaner, newly-designed code base, so the theory went, it was going to be easier for people to understand and contribute. And this did get us more contributors. But it also constituted an almost-total rewrite of the browser, throwing us back six to ten months. Now we had to rewrite the entire user interface from scratch before anyone could even browse the web, or add a bookmark.

**Excuse #4:**

It didn't contain a mail reader. There is surely a large class of users who would be interested in working on Communicator that are less interested in Navigator, but we never really found that out, since we never shipped the source code to communicator (for a number of reasons, none very good, some downright pathetic.) Now, as a result of the Gecko/Raptor rewrite, the mail/news reader is being rewritten as well. Maybe it will even ship someday.

**Excuse #5:**

Netscape failed to follow through on their own plans. During 1998, Netscape sunk a huge amount of engineering effort into doing the 4.5 release: working on a dead-end proprietary code base, the source of which would never be released to the world, and would never benefit from open source development. This was a huge blow to the Mozilla project, since for the first half of the year, we weren't even getting full-time participation from Netscape.

This isn't even so much an excuse as a stupid, terrible mistake, considering we should have learned our lessons about doing parallel development like this in the past, with the abortive \`\`Javagator'' project.

The worst part about all this is, for the last year, I've spent much of my time striving to convince people that mozilla.org is not netscape.com. I've told people again and again that the mozilla.org organization does not serve only the desires of the Netscape client engineering group, but rather, serves the desires of _all_ contributors to the Mozilla project, no matter who they are. And that's certainly true. But the fact is, there has been very little contribution from people who don't work for Netscape, making the distinction somewhat academic.

Now, to be fair, in this first year, we did do some very good things:

-   We showed the world how to operate a large software project out in the open. Whatever else happened, we did maintain a high level of communication between geographically and organizationally separate contributors and other interested parties. We transitioned from a secretive and proprietary development model to a very public one. We showed that it can be done.
-   Though we didn't get a whole lot of participation in the form of source code, we did get a lot of feedback about the directions the software was going. And the right feedback at the right time can easily be far more valuable than source code. By doing development out in the open, and \`\`living in a fishbowl,'' I believe that Netscape made better decisions about the directions of development than would have been made otherwise.
-   We released the source code to a number of ancillary tools, such as our [bug system](https://web.archive.org/web/19991004002042/http%3A//www.mozilla.org/bugs/), [source-control interface](https://web.archive.org/web/19990427100734/http%3A//www.mozilla.org/bonsai.html), and [build tools](https://web.archive.org/web/19990429122213/http%3A//www.mozilla.org/tinderbox.html). These are very good (and complete!) tools in their own right. Though they were critical to us in the development of Mozilla, and we created them in support of Mozilla, they are not tied to Mozilla, and others are finding them useful with their own non-Mozilla-related projects. These tools, and the development model they represent, are a valuable contribution in their own right.
-   And merely by being who we are and doing what we did, we played a big part in bringing the whole open source development model to the attention of the world at large. We didn't start the mainstream media interest in open source (Linux did that, mostly), but I think we did legitimize it in the eyes of a lot of people, and we did tell the story very well. Lending the Netscape name to this software development strategy brought it to the attention of people who might otherwise have dismissed it.

But despite all this, in the last year, we did not accomplish the goals that I wanted to accomplish. We did not take the Mozilla project and turn it into a network-collaborative project in which Netscape was but one of many contributors; and we did not ship end-user software. For me, _shipping_ is the thing.

Perhaps my goals were unreasonable; perhaps it should have been obvious to me when we set out on this project that it would take much longer than a year to reach these goals, if we ever did. But, it wasn't obvious to me then, or now. These are the goals I was aiming for, and they have not yet been met.

And so I'm giving up.

The Mozilla project has become too depressing, and too painful, for me to continue working on. I wanted Mozilla to become something that it has not, and I am tired of fighting and waiting to make it so. I have felt very ineffectual, and that's just not a good feeling.

For those of you who choose to continue, I wish you all the best of luck.

I must say, though, that it feels good to be [resigning from AOL](https://www.jwz.org/gruntle/aol.html) instead of resigning from Netscape. It doesn't really feel like quitting at all. I was the 20th person hired at Mosaic Communications Corporation (_All Praise the Company_), and of those twenty, only five remain. The [company](https://www.jwz.org/gruntle/nscpdorm.html) I helped build has been gone for quite some time. We, Netscape, did some extraordinary things. But we could have done so much more. I feel like we had a shot at greatness, and missed.

My biggest fear, and part of the reason I stuck it out as long as I have, is that people will look at the failures of mozilla.org as emblematic of open source in general. Let me assure you that whatever problems the Mozilla project is having are not because open source doesn't work. Open source does work, but it is most definitely not a panacea. If there's a cautionary tale here, it is that you can't take a dying project, sprinkle it with the magic pixie dust of \`\`open source,'' and have everything magically work out. Software is hard. The issues aren't that simple.

[Jamie Zawinski](https://www.jwz.org/gruntle/), 31-Mar-1999

___

[![[ up ]](data:image/gif;base64,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)](https://www.jwz.org/)
