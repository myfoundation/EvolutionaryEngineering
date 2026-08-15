---
created: 2026-08-15T15:51:08 (UTC +03:00)
tags: [george washington university,gwu,gw,gw university,george washington,dc universities,dc colleges,education,higher education]
source: https://ospo.gwu.edu/python-wasnt-built-day-origin-story-worth-knowing
author: Authored by:

                                  Professor Lorena A. Barba
---

# Python Wasn't Built in a Day: An Origin Story Worth Knowing | The GW Open Source Program Office | The George Washington University

> ## Excerpt
> The history and evolution of the Python programming language, highlighting five counter-intuitive takeaways from the documentary "Python: The Documentary."

---
_Python code is running on Mars right now. It helped land the Perseverance rover, processes data from the Hubble telescope, and powers the AI systems reshaping our world. Today, it’s estimated that about_ [_23 million developers worldwide_](https://www.slashdata.co/post/global-developer-population-trends-2025-how-many-developers-are-there) _regularly use Python. Yet this global infrastructure began as one programmer's Christmas holiday project—or so the story goes._

 If you have any interest in programming, open source, or the history of technology, the new film ["Python: The Documentary"](https://www.youtube.com/watch?v=GfH4QL4VqJ0) is essential viewing. Through interviews of the main protagonists, it chronicles the language's journey from a small side project to a global phenomenon that runs on everything from laptops to the Mars rover.

The documentary dispels a popular myth with a far more illuminating reality. The usual story is that [Guido van Rossum](https://en.wikipedia.org/wiki/Guido_van_Rossum) invented Python over his Christmas holiday in 1989. We see in the film that while he started the work then, this was no sudden stroke of genius. It was the culmination of 3.5 years of prior work on a now-defunct predecessor, frustrating dead ends, and critical turning points that nearly ended the project altogether.

As someone who has spent years advocating for Python and being involved with the sustainability of open source software, I find the real story a masterclass in how innovation really works: not as a single, clean event, but as a messy, human process of trial, error, crisis, and evolution. Here are some surprising and impactful lessons from the film on how Python was really built.

## Five Counter-Intuitive Takeaways on How Python Was Really Built

#### Great Ideas Are Often a Rebound from Failure

Python was not born in a vacuum; it was derived from its predecessor, a project called ABC. This earlier language was born from frustration with a simple economic reality of the 1980s. Since computer time was far more expensive than programmer time, languages were designed to be computationally efficient rather than human-friendly. The ABC team dared to ask: what if we flipped that equation? At the Dutch research facility CWI, Guido’s mentor [Lambert Meertens](https://en.wikipedia.org/wiki/Lambert_Meertens) attempted to teach programming to artists, and found that many things about programming were easy if you're a scientist or engineer, but not obvious for others. This realization led the team to ask if they could design a better language. For three and a half years, Guido worked on ABC with an ambitious goal: to create a simple, easy-to-learn language for non-programmers like artists, abstracting away the details of computer hardware.

Ultimately, ABC flopped. In a pre-web world, distribution was a major hurdle. In the documentary, co-creator [Steven Pemberton](https://en.wikipedia.org/wiki/Steven_Pemberton) recalls: _"If anybody wanted a copy, they had to send us a letter and we'd send them a floppy disc."_ The project reached very few people and was eventually killed by management. This failure, however, became the catalyst for Python. 

While working on the Amoeba operating system, Guido found himself frustrated with C and realized a language with ABC's simplicity but the practicality for systems programming could be revolutionary. He recounts: _“I thought, well, oh man, if we just could program ABC instead of C, each of those utilities would be like half a page of code and I could write the entire suite of utilities in a couple of weeks instead of the years that it looked like it was going to take us.”_

In my work with and around open source projects, I've seen this pattern repeat: the most splendid innovations are often born from the ashes of a previous, well-intentioned failure. The key is to carry forward the right lessons—in Python's case, ABC's elegant syntax—while ruthlessly jettisoning what didn't work.

#### Open Source Often Needs a Lifeline to Survive Crises

Python faced a near-death experience during the dot-com bust. Guido and the core development team had left the non-profit CNRI to join a startup, BeOpen, which promised to fund their full-time work on the language. They released Python 2.0, but within months, the dream collapsed. The startup went bankrupt and stopped paying its employees, leaving the project's leadership scattered and its future in jeopardy. 

What followed was an "incredibly lucky rescue." A company called Digital Creations had built its entire commercial application server on Python. Their founder puts the stakes in stark terms in the film, making one of the most compelling business cases for open source support I’ve ever heard: _“…if Python died, you know who else would die? We'd die.” Recognizing this existential dependency, they hired the core Python team, ensuring the language's survival to protect their own business._ 

_“…if Python died, you know who else would die? We'd die.”_

For any OSPO, this is a key lesson: the long-term health of an open source project may depend on identifying and nurturing the commercial entities that would literally die without it. It’s about finding the partners for whom your survival is their survival.

#### Threats Can Come from Within

The painful, decade-long transition from Python 2 to Python 3 was surely the project's greatest internal crisis. To move the language forward, the core team made a series of changes that broke backwards compatibility. Yet they believed the community would transition in what they thought was an "extraordinarily generous" five-year timeframe.

The reaction was relentlessly negative. Many users refused to switch, insisting that their codebases worked perfectly fine. The project found itself supporting two incompatible versions, which was a massive burden on the entire ecosystem. As Guido himself admitted, he had not fully grasped Python’s success: “I think I severely underestimated how successful Python already was. How many people had written so much code in Python 2 that it would be hard for them to sort of put the effort to translate it to Python 3.”

The tide only turned after years of effort, the creation of migration tools, and a pivotal talk by Lisa Guo from Instagram at PyCon 2017. Her presentation was a turning point because it gave other engineers a concrete success story—complete with performance benefits—to show their management, finally creating the business case for migration. The film brilliantly illustrates a lesson we may teach our students about innovation: don’t underestimate the inertia of your own success.

#### Communities Require Intentional Effort

A healthy, inclusive community does not happen by accident; it requires deliberate effort. In 2011, a stark reality was uncovered: only 1% of the talks at PyCon, the main Python conference, were given by women.

In response, community leaders like [Jessica McKellar](https://en.wikipedia.org/wiki/Jessica_McKellar) initiated a conscious effort to support, encourage, and outreach to women who were interested in speaking. The results were dramatic. By 2016, the percentage of talks by women had soared to 40%. The effort went beyond conference stages. In 2015 Guido publicly stated his desire to mentor women to become core developers, yet by PyCon 2016 no one had taken him up on it. [Mariatta Wijaya](https://mariatta.ca/#about), after hearing both keynotes, decided to reach out. Her account is heartwarming: _“It was scary at first, like I just didn't feel  comfortable sharing my questions in public. I didn't want people to know that I don't  know how to do certain things…”_ This reflects what many would-be contributors feel at first. 

With Guido’s mentorship, Mariatta navigated the contribution process and became the first female core Python developer. She added: _“I never felt like I was  being judged. I think it does start with Guido.”_

Mariatta's journey from hesitant outsider to core developer reveals a profound truth: behind every statistic about diversity is a human being who needed just one person to believe in them. Building an inclusive community isn't about checking boxes. It's about recognizing that the next breakthrough, the next innovation, the next world-changing idea might come from someone who's currently too afraid to ask their first question in public.

The Python story is proof that building a sustainable community requires intentionally creating pathways for everyone to contribute.

#### The Benevolent Dictator Resigned, and the Project Matured

For most of its history, Python operated under the "Benevolent Dictator for Life" (BDFL) model, where Guido van Rossum had the final say. This was shattered after the brouhaha over the [walrus operator](https://www.mostlypython.com/remember-the-walrus-operator/): a debate over what looked like a sideways emoticon nearly brought down one of the world's most important programming languages!

The discussion, amplified on public platforms like Twitter, became intensely personal and vitriolic. The hostility led Guido to a breaking point. In what one participant calls a "rage quit," he abruptly resigned from his leadership role.

He wrote: _“Now that PEP 572 is done, I don't ever want to have to fight so hard for a PEP and find that so many people despise my decisions. ... I would like to remove myself entirely from the decision process. ... I'm basically giving myself a permanent vacation from being BDFL and you all will be on your own.”_

This crisis forced the project to mature. The core developers came together to create a new, democratic governance model: a five-person steering council. It raises the question about whether a founder-led 'benevolent dictator' model, while effective for getting a project off the ground, has a natural lifespan. True long-term sustainability requires a transition to a more resilient, community-owned governance structure.

## Fin: From Hobby Project to World-Changing Infrastructure

The real story of Python is not a simple tale of a lone genius. It is a messy, complicated, and deeply human story of rebounding from failure, surviving economic collapse, navigating internal division, and intentionally building a better community.

Tech history has several legends where a few people in a garage created a company that changed the world. The story of Python is the open-source equivalent. It shows how one person's "hobby project," when nurtured and sustained by a global community, can become a foundational piece of digital infrastructure: a tool that generates billions of dollars in economic value, helps land rovers on Mars, and powers the future of artificial intelligence. Guido says whimsically in the film: _"It exceeded my wildest expectations and it actually continues to do so."_ 

Today, as we grapple with the sustainability of open source infrastructure that powers our digital world, Python's story offers a blueprint. It shows us that the most enduring technologies aren't built by lone geniuses in isolation, but by communities willing to fail, learn, rescue each other, and evolve.

**The next time you import a Python library, remember: you're not just using code. You're participating in a 35-year conversation about how to build technology that serves humanity, rather than the other way around.**  
 

[](http://creativecommons.org/licenses/by/4.0/)  
Content licensed under Creative Commons Atribution International 4.0
