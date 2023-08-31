/*	
	Mike Kozlowski
	CSC351
	Project 3
	A program written in prolog that engages with a set dialog with the user,
	first reading rules from a saved file and then processing inputs from the
	user in the console to set new rules, new facts, and runs queries based
	on the database constructed from the dialog. Modified from code written by
	Dr. Jeffrey McConnell. use listing for testing
*/

talk :- write('Enter the file name: '),
	read(Filename),
	see(Filename),
	repeat,
	read_in(Sentence),
	write_out(Sentence),
	process(Sentence,Clause),
	Clause = stop,
	seen.
	
/*
	For processing the sentences, it checks	first the case in which a new
	fact is added, and adds it to the end of the database with assertz.
	Then does the same thing with the second case which adds a new rule
	with assertz. Finally, the third case in which it checks to	see if the
	query is true or not and ouputs that.
*/
process([X, is, a, Y, Punct], go) :- Fact =.. [X,Y],
	assertz(Fact),
    nl, write('New fact added.'), nl.
process([a, X, is, a, Y, Punct], go) :- Rule =.. [':-',X,Y],
	assertz(Rule),
	nl, write('New rule added.'), nl.
process([is, X, a, Y, Punct], go) :- Query =.. [X,Y],
	call(Query),
    nl, write('Query result: true'), nl;
    nl, write('Query result: unknown'), nl.
process([stop, Punct], stop).

/*	
	First check for an empty base case which will eventually end
	the loop, then otherwise set up	two cases - one is if the
	currently analyzed word (head) is one of the valid punctuation marks
	then recursively calls write_out with the remaining words (tail),
	and the	case for if the word is not punctuation, it prints the
	word and then a space before calling write_out with the	tail.
*/
write_out([]).
write_out([H|T]) :-
    member(H, ['.', '?', '!']),
    write(H),
    write_out(T).
write_out([H|T]) :-
    write(H),
    write(' '),
    write_out(T).


/* read in a sentence */
read_in([W|Ws]) :- get0(C),
			readword(C,W,C1),
			restsent(W,C1,Ws).

/*
	given a word and the character after it, read
	in the rest of the sentence.
*/

restsent(W,_,[]) :- lastword(W), !.
restsent(W,C,[W1|Ws]) :- readword(C,W1,C1), restsent(W1,C1,Ws).

/*
	read in a single word, given an initial character,
	and remembering what character came after the word.
*/
readword(C,W,C1) :- single_character(C), !, name(W,[C]), get0(C1).
readword(C,W,C2) :- in_word(C,NewC), !, get0(C1), restword(C1,Cs,C2),
			name(W,[NewC|Cs]).
readword(C,W,C2) :- get0(C1), readword(C1,W,C2).

restword(C,[NewC|Cs],C2) :- in_word(C, NewC), !, get0(C1), restword(C1,Cs,C2).
restword(C,[],C).

/* these characters form words on their own */
single_character(44).	/* , */
single_character(59).	/* ; */
single_character(58).	/* : */
single_character(63).	/* ? */
single_character(33).	/* ! */
single_character(46).	/* . */

/*
	these characters can appear within a word.  the second
	in_word clause converts characters to lower-case.
*/
in_word(C,C) :- C>96, C<123.		/* a through z */
in_word(C,L) :- C>64, C<91, L is C+32.	/* A through Z */
in_word(C,C) :- C>47, C<58.		/* 1 through 9 */
in_word(39,39).				/* ' */
in_word(45,45).				/* - */

/* these words terminate a sentence */
lastword('.').
lastword('!').
lastword('?').


