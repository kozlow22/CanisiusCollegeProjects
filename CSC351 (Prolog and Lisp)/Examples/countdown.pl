countdown(0).
countdown(N) :- N > 0, write(N), nl, M is N-1, countdown(M).

