/*
Mike Kozlowski
CSC351
Project 1
2/2/23
Prolog program that generates numbers in the Fibonacci sequence and records them in fibData
in order to generate values higher than the stack size would allow. I had to consult the GNU Prolog documentation for longer than I would like to admit to get to this completely broken program. For some reason I'm having a lot of trouble understanding the basics of file input and output, as well as some other prolog basics. I will definitely need to consult with you for the next project that will utilize I/O in any way, and will spend more time reading the documentation.

Edit: Since the deadline was extended, I spent time reading the documentation and gave another crack at this project.
*/

:- dynamic(fib/2).

fib(X,Y) :- X1 is X-1, X2 is X-2, fib(X1,Y1), fib(X2,Y2), Y is Y1 + Y2,
	asserta(fib(X,Y)).
	
readit :-
	% Open the data stream, call helper predicate, then close the data stream.
	see(fibData),
	readhelp,
	seen.

readhelp :-
	% Read in X and Y from the file until X reaches the end of the file. After each X,Y pair, asserta them, and continue recursively until X reaches end of the file.
	read(X),
	read(Y),
	X\==end_of_file,
	asserta(fib(X,Y)),
	readhelp.
readhelp.
	
saveit :-
	% Open the data stream, call helper predicate, then close the data stream.
	tell(fibData),
	savehelp,
	told.
	
savehelp :-
	% Retract the last fib and write X followed by a period and newline, then do the same for Y.
	retract(fib(X,Y)),
	write(X),
	write('.\n'),
	write(Y),
	write('.\n'),
	savehelp.
savehelp.