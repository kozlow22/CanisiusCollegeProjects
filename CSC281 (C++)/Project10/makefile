main:		main.o kruskals.o partition.o Quicksort.o utilities.o
		g++ main.o kruskals.o partition.o Quicksort.o utilities.o -o main


main.o:		main.c++ utilities.h edge.h kruskals.h
		g++ -c main.c++


partition.o:	partition.c++ partition.h
		g++ -c partition.c++


Quicksort.o:	Quicksort.c++ Quicksort.h utilities.h edge.h
		g++ -c Quicksort.c++

utilities.o:	utilities.c++ utilities.h edge.h
		g++ -c utilities.c++
