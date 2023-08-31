nums( [3,6,7,1,5,9,8,4,2] ).
lets( [h,d,g,f,s,k,l,j,a]).



mysort( L1, L2 ) :- mypermutation(L1, L2), sorted(L2), !.

mypermutation([],[]).
mypermutation(L, [H|T]) :-	myappend(V, [H|U], L), 
				myappend(V,U,W), 
				mypermutation(W,T).

sorted([]).
sorted([X]).
sorted([X,Y|Rest]) :- ordered(X,Y), sorted([Y|Rest]).

ordered(X,Y) :- atom(X), atom(Y), X @=< Y, !.
ordered(X,Y) :- integer(X), integer(Y), X =< Y, !.

myappend( [], L, L).
myappend([X|L1], L2, [X|L3]) :- myappend( L1, L2, L3).
