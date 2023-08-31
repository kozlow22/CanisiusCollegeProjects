/* concatenate two terms */

concat(T1, T2, Result) :- name(T1,L1),
				name(T2,L2),
				append(L1,L2,NewList),
				name(Result,NewList).


