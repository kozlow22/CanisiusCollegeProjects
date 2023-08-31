// Mike Kozlowski
// Project 6
// CSC281
// insertion.c++: code which handles performing insertion sort for a given array and size of that array.
// Pseudocode written by Dr. Jeffrey McConnell with modifications by Mike Kozlowski

#include "utilities.h"
#include "insertion.h"
#include <iostream>
using namespace std;

void insSort( int list[], int N, int start, int increment ) {
	int newElement, location;
	cout << "\ninsertion sort initiated.\n" << increment;
	for (int i = start; i < N; i + increment) {
		newElement = list[i];
		location = i - increment;
		while ((location >= start) && GreaterThan(list[location], newElement)) {
			// move any larger elements out of the way
			cout << "\n" << list[location + increment] << " set to " << list[location];
			list[location + increment] = list[location];
			location = location - increment;
		}
		list[location + increment] = newElement;
	}
}
