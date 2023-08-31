// Mike Kozlowski
// Project 5
// CSC281
// utilities.c++: CheckList function which takes a list and the size of the list
// and returns if the list is in increasing order or not, along with GreaterThan
// function, which takes two integers and will return true if the first is greater
// than the second and false in other cases. Also tracks global var comparisonCount
// to track efficiency.

#include "utilities.h"

int comparisonCount = 0;

// Checks to see if the list has been sorted in ascending order
bool CheckList(int list[], int size) {
	for (int i = 1; i < size; i++) {
		if (list[i - 1] > list[i]) {
			return false;
		}
	}
	 return true;
}

// Checks to see if given integer 1 is greater than given integer 2 and
// increments the comparisonCount global var to check for algorithm efficiency
bool GreaterThan(int a, int b) {
	comparisonCount++;
	if (a > b) {
		return true;
	}
	return false;
}
