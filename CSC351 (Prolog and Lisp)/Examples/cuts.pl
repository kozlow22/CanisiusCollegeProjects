/* cuts.pl*/


min1(X, Y, X) :- X =< Y.
min1(X, Y, Y).

min2(X, Y, X) :- X =< Y.
min2(X, Y, Y) :- X > Y.

min3(X, Y, X) :- X =< Y, !.
min3(X, Y, Y) :- X > Y.

min4(X, Y, X) :- X =< Y, !.
min4(X, Y, Y).


