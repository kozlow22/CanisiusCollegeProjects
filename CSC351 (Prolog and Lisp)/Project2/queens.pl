/*
Mike Kozlowski
CSC351
Project 2
2/21/23
A method for solving the "n-queens" problem by modifying code written by Dr. Jeffrey McConnell 
by inserting two predicates, "safe" and "attacked" which inform the algorithm if a square
is being attacked by another queen or not.
*/

queens(N,Queen_places) :- range(1,N,N_list),
			my_permutation(N_list,Queen_places),
			safe(Queen_places).
			print_board(Queen_places,N).

safe([Q|A]) :- safe(A),	attacked(Q,A,1).
% Safe can either have a queen (Q) or anything else (A). Checks to see if a square is safe by seeing if it's being attacked, initializes attacked with a distance of 1.
safe([]).
% Define safe just as having a single input.

attacked(Square,[Square2|Checked],Distance) :- Square2-Square=\=Distance, Square-Square2=\=Distance, Distanceplus1 is Distance + 1, attacked(Square,Checked,Distanceplus1).
% Attacked is recursive, and imports three different variables. When attacked is initially called from safe, safe will send the square that it's checking, along with a 1 for initializing the distance. As attacked is run, it checks if the distance is equal to either the initial square minus the square being checked, or the square being checked minus the initial square. It then increments the distance and recursively checks again using the new incremented distance, along with Checked.
attacked(_,[],_).
% Define attacked as having three inputs.

print_board(_,_).

my_permutation(Xs,[Z|Zs]) :- myselect(Z,Xs,Ys), my_permutation(Ys,Zs).
my_permutation([],[]).

myselect(X,[X|Xs],Xs).
myselect(X,[Y|Ys],[Y|Zs]) :- myselect(X,Ys,Zs).

range(M,N,[M|Ns]) :- M < N, M1 is M + 1, range(M1,N,Ns).
range(N,N,[N]).

