

% a couple of rules
mother(X,Y) :- parent(X,Y), female(X).
father(X,Y) :- parent(X,Y), male(X).

grandparent(X, Z) :- parent(X,Y), parent(Y,Z).

sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.




% my maternal grandparents
parent(joseph,sylvia).
parent(lillian,sylvia).

/* my biological paternal grandparents */
parent(william,robert).
parent(helen,robert).

/* my adopted paternal grandparents */
parent(albert,jack).
parent(peg,jack).

/* me */
parent(robert,jeffrey).
parent(jack,jeffrey).
parent(sylvia,jeffrey).

/* my half-siblings */
parent(robert,scott).
parent(mary,scott).
parent(robert,gail).
parent(mary,gail).

/* Fred's family */
parent(alfred,fred).
parent(kay,fred).
parent(alfred,kit).
parent(kay,kit).
parent(johnH,johnF).
parent(kit,johnF).
parent(johnH,kathy).
parent(kit,kathy).

/* our family */
parent(jeffrey,barney).
parent(fred,barney).

/* sex identifications */
female(lillian).
female(helen).
female(peg).
female(sylvia).
female(mary).
female(gail).
female(kay).
female(kit).
female(kathy).
male(joseph).
male(william).
male(albert).
male(robert).
male(jack).
male(scott).
male(alfred).
male(johnH).
male(johnF).
male(jeffrey).
male(fred).
male(barney).


