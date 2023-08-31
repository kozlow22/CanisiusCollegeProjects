// Mike Kozlowski
// Project 5
// CSC281
// main.c++: code which handles the main tasks assigned in Project 5 using utilities.c++ and
// insertion.c++. Creates an array of 20 integers and fills them with 20 random values between
// 1 and 10,000, and then sorts that list using insertion sort. Then creates an array of 50,000
// values between 1 and INT_MAX and does the same task for that array.

#include "insertion.h"
#include "utilities.h"
#include "MyRandom.h"
#include <limits.h>
#include <iostream>
using namespace std;

int main(int argv, char* argc[]) {
	// Initializing objects and variables, along with setup
	cout.imbue(locale(""));
	int testOne[20] = {0};
	int testTwo[50000] = {0};
	int ccResult = 0;
	int numTests = 3;
	MyRandom r;
	
	// Generating random numbers for the two arrays
	for (int i = 0; i < 20; i++) {
		testOne[i] = r.RanRange(1, 10000);
	}
	for (int i = 0; i < 50000; i++) {
		testTwo[i] = r.RanRange(1, INT_MAX);
	}
	// Sort the larger list using a loop to get average comparisons
	for (int i = 0; i < numTests; i++) {
		sort(testTwo, 50000);
		// Add the number of comparisons to running counter ccResult and reset global comparisonCount
		if (CheckList(testTwo, 50000) == 1) {
			ccResult += comparisonCount;
			comparisonCount = 0;
		} else {
			// if CheckList fails, escape loop
			i = numTests;
		}
		// Reset array to 0
		for (int i = 0; i < 50000; i++) {
			testTwo[i] = 0;
		}
		// Generate new set of random numbers for the array
		for (int i = 0; i < 50000; i++) {
			testTwo[i] = r.RanRange(1, INT_MAX);
		}
	}
	// Reset comparisonCount and then sort the smaller list
	comparisonCount = 0;
	sort(testOne, 20);
	// Checks to see if the list was properly sorted
	if (CheckList(testOne, 20) == 0) {
		cout << "Sort failed.\n";
	}
	
	// Display results in a nicely formatted way
	cout << "\nHere is the randomized list after sorting:\n";
	for (int i = 0; i < 20; i++) {
		cout << testOne[i] << ", ";
	}
	cout << "\n Here is the number of comparisons made sorting that list:\n" << comparisonCount;
	cout << ".\n Here is the average number of comparisons made after " << numTests << " runs of sorting the large list:\n";
	cout << (ccResult / numTests) << ".\n";
	return 0;
	
}
