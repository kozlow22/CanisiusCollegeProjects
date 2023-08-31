/* stars.pl */

drawstars(X) :- stars(1, X).

stars(X, X) :- dostars(X), nl, !.
stars(Row, Max) :- frontspace(Row, Max),
		dostars(Row), nl,
		Next is Row + 1,
		stars(Next, Max),
		frontspace(Row, Max),
		dostars(Row), nl.

dostars(1) :- write('*'), !.
dostars(X) :- write('*'),
		Xm is X - 1,
		dostars(Xm),
		write('*').

frontspace(X,X) :- !.
frontspace(Row, Max) :- write(' '),
			R1 is Row + 1,
			frontspace(R1, Max).
