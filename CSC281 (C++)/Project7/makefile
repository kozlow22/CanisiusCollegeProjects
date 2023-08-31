main:		main.o MyRandom.o utilities.o HeapSort.o
		g++ main.o MyRandom.o utilities.o HeapSort.o -o main


main.o:		main.c++ utilities.h HeapSort.h
		g++ -c main.c++


MyRandom.o:	MyRandom.h MyRandom.c++
		g++ -c MyRandom.c++


utilities.o:	utilities.c++ utilities.h MyRandom.h
		g++ -c utilities.c++


HeapSort.o:	HeapSort.c++ HeapSort.h utilities.h
		g++ -c HeapSort.c++
