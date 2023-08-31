main:		main.o MyRandom.o utilities.o insertion.o ShellSort.o
		g++ main.o MyRandom.o utilities.o insertion.o ShellSort.o -o main


main.o:		main.c++ MyRandom.h utilities.h insertion.h ShellSort.h
		g++ -c main.c++


MyRandom.o:	MyRandom.h MyRandom.c++
		g++ -c MyRandom.c++


utilities.o:	utilities.c++ utilities.h
		g++ -c utilities.c++


insertion.o:	insertion.c++ insertion.h utilities.h
		g++ -c insertion.c++


ShellSort.o:	ShellSort.c++ ShellSort.h utilities.h insertion.h
		g++ -c ShellSort.c++
