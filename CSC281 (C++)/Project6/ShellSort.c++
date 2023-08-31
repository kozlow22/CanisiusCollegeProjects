// Mike Kozlowski
// Project 6
// CSC281
// ShellSort.c++: Implements two different shell sort algorithms in two different functions
// which differ in that one uses the pseudocode in the book and another modifies it by
// using two passes, with an increment of 1.72 * sqrt N and then a single call with 
// an increment of 1.

#include "ShellSort.h"
#include "insertion.h"
#include "utilities.h"
#include <math.h>
#include <iostream>
using namespace std;

void shellOne(int list[], int size) {
	double passes = log2(size);
	int increment = pow(2, passes) - 1;
	cout << increment;
	while (passes >= 1) {
		for (int start = 0; start > (increment - 1); start++) {
			insSort( list, size, start, increment );
		}
		passes = passes - 1;
	}
}

void shellTwo(int list[], int size) {
	int increment = 1.72 * sqrt(size);
	insSort( list, size, 0, increment );
	increment = 1;
	insSort( list, size, 0, increment );
}
