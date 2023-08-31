main:		main.o MyRandom.o utilities.o Quicksort.o
		g++ main.o MyRandom.o utilities.o Quicksort.o -o main


main.o:		main.c++ utilities.h Quicksort.h
		g++ -c main.c++


MyRandom.o:	MyRandom.h MyRandom.c++
		g++ -c MyRandom.c++

utilities.o:	utilities.c++ utilities.h MyRandom.h
		g++ -c utilities.c++


Quicksort.o:	Quicksort.c++ Quicksort.h utilities.h
		g++ -c Quicksort.c++
