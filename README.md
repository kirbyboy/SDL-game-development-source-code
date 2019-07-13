# SDL-game-development-source-code
All the chapters made by me, and they are working

This is all the chapters done by me of the book SDL Game Developments, with all the bugs(at least to make it working) fixed.

What is included in this source code and what not?

Included:<br />
All the sources that you need to make in the book to follow the same book, separated by chapters and some personal separations of the chapter that I think that made sense.<br />
A compile.sh that compiles the code in a command line, in linux, you need all the required libraries installed(SDL2, SDL2-mixer, SDL2-image, zlib...), I just didn't want to make a makefile.

Not included:<br />
tinyxml<br />
Base64.h/c<br />
Assets, this means you must create the folder assets inside every project that
needs it and add the needed files for the chapter.<br />
Chapters 8 and 9, they were basically a copy of the real code because the
book just tells you some hints, not the full code.<br />
You can get all of them from the official web of the book.

This code doesn't clean up correctly all the objects, it was not the scope of the
book or something I needed to follow the book.<br />
I did a fix to the state machine to make it working, if you follow the book 
as is intended, from chapter 5(I think, not sure right now) the state machine 
make the examples to crash(in linux it was an inmediate crash while in windows 
sometimes crashed and sometimes worked).  I was a temporary fix to continue the
book reading, if you do the chapters 8 and 9, it uses the same state machine but
it doesn't crashes, not sure why, i think it's because the objects are really
destroyed when are needed, but it still have some bugs, if you start a new 
play from the pause menu, it adds a new playState without deleting the old
playState, so there is a playState in memory that is never going to be used
or deleted until the game is closed.  If you understand all that i have written
here, congratulations, it looks like you understood the book.
