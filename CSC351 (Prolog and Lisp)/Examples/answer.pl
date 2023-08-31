% answer.pl

getAnswer(Ans) :- repeat, write('answer yes or no: '), read(Ans), valid(Ans).

valid(yes).
valid(no).
