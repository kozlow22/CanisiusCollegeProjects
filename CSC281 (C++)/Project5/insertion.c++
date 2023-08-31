// Mike Kozlowski
// Project 5
// CSC281
// insertion.c++: code which handles performing insertion sort for a given array and size of that array.
// Pseudocode written by Dr. Jeffrey McConnell

#include "utilities.h"
#include "insertion.h"

void sort( int list[], int N ) {
	int newElement, location;	
	for (int i = 1; i < N; i++) {
		newElement = list[i];
		location = i - 1;
		while ((location >= 0) && GreaterThan(list[location], newElement)) {
			// move any larger elements out of the way
			list[location + 1] = list[location];
			location = location - 1;
		}
		list[location + 1] = newElement;
	}
}
