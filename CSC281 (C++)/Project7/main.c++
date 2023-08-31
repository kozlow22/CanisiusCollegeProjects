// Mike Kozlowski
// Project 7
// CSC281
// main.c++: The program which creates the randomized arrays to be sorted using
// the new heapsort algorithm

#include "HeapSort.h"
#include "utilities.h"
#include <iostream>
#include <limits.h>
using namespace std;

int main(int argv, char* argc[]) {
	// Initializing variables, along with setup
	cout.imbue(locale(""));
	int smallList[20] = {0};
	int bigList[50000] = {0};
	int smallCount, max;
	int numTests = 1;
	int bigCount = 0;
	
	// Generating random numbers for the two array
	InitArray(smallList, 20, 10000);
	InitArray(bigList, 50000, INT_MAX);
	
	// Sort the small array
	for (int i = 10; i > 1; i--) {
		fixHeap(smallList, i, smallList[i], 10);
	}
	for (int i = 10; i > 2; i--) {
		max = smallList[1];
		fixHeap(smallList, 1, smallList[i], i-1);
		smallList[i] = max;
	}
	// Save comparisonCount and reset it for the large array
	smallCount = comparisonCount;
	comparisonCount = 0;

	// Checks to see if smallList was sorted properly
	if (CheckList(smallList, 20) == 0) {
		cout << "smallList Sort failed.\n";
	}
	// Sort the large array utilizing a loop to get average results
	for (int i = 0; i < numTests; i++) {
		for (int i = 25000; i > 0; i--) {
			fixHeap(bigList, i, bigList[i], 25000);
		}
		for (int i = 25000; i > 1; i--) {
			max = bigList[0];
			fixHeap(bigList, 0, bigList[i], i-1);
			bigList[i] = max;
		}
		// Checks to see if list was properly sorted, prints error and exits loop if not
		if (CheckList(bigList, 50000) == 0) {
			cout << "bigList Sort failed.\n";
			break;
		}
		ResetArray(bigList, 50000);
		InitArray(bigList, 50000, INT_MAX);
		bigCount += comparisonCount;
	}
	// Display results in a nicely formatted way
	cout << "\nHere is the randomized list after sorting:\n";
	for (int i = 0; i < 20; i++) {
		cout << smallList[i] << ", ";
	}
	cout << "\nHere is the number of comparisons made sorting that list:\n" << smallCount;
	cout << ".\nHere is the average number of comparisons made after " << numTests << " runs of sorting the large list:\n";
	cout << (bigCount / numTests) << ".\n";
	return 0;
}
