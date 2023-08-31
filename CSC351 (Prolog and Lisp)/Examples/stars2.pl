/* stars2.pl */

drawstars(Row, Plus) :- stars(1, Plus, Row), !.

stars(Max, Y, Max) :- dostars(Max, Y, Max), nl.
stars(Row, Y, Max) :- frontspace(Row, Max),
		dostars(Row, Y, Row), nl,
		Next is Row + 1,
		stars(Next, Y, Max),
		frontspace(Row, Max),
		dostars(Row, Y, Row), nl.

dostars(1, Y, Row) :- Test is (Row - Y) + 1,
		Test =:=1,
		display('+'), !.
dostars(1, Y, Row) :- Test is (Row - Y) + 1,
		Test =\= 1, 
		display('*'), !.
dostars(X, Y, Row) :- Test is (Row - Y) + 1,
		X =:= Test,
		display('+'),
		Xm is X - 1,
		dostars(Xm, Y, Row),
		display('+').
dostars(X, Y, Row) :- Test is (Row - Y) + 1,
		X =\= Test,
		display('*'),
		Xm is X - 1,
		dostars(Xm, Y, Row),
		display('*').

frontspace(X,X) :- !.
frontspace(Row, Max) :- display(' '),
			R1 is Row + 1,
			frontspace(R1, Max).
