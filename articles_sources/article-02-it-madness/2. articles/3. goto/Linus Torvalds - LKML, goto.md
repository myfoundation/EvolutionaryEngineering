https://lkml.org/lkml/2003/1/12/128

On Sun, 12 Jan 2003, Rob Wilkens wrote:

> I'm REALLY opposed to the use of the word "goto" in any code where it's
> not needed.

I think goto's are fine, and they are often more readable than largeamounts of indentation. That's _especially_ true if the code flow isn'tactually naturally indented (in this case it is, so I don't think usinggoto is in any way _clearer_ than not, but in general goto's can be quitegood for readability).

Of course, in stupid languages like Pascal, where labels cannot be descriptive, goto's can be bad. But that's not the fault of the goto, that's the braindamage of the language designer.

Linus



