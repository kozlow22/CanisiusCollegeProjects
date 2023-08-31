// Mike Kozlowski
// Project 8
// CSC281
// main.c++: the main program which constructs randomly generated arrays to be sorted
// by the quicksort functions in Quicksort.c++

#include "Quicksort.h"
#include "utilities.h"
#include <iostream>
#include <limits.h>
using namespace std;

int main(int argv, char* argc[]) {
	// initializing variables, along with setup
	cout.imbue(locale(""));
	int smallList1[20] = {0};
	int smallList2[20] = {0};
	int bigList1[50000] = {0};
	int bigList2[50000] = {0};
	int bigSwap1 = 0;
	int bigSwap2 = 0;
	int bigComp1 = 0;
	int bigComp2 = 0;
	int numTests = 1;
	int smallSwap1, smallSwap2, smallComp1, smallComp2;

	// generating random numbers for the arrays
	InitArray(smallList1, 20, 10000);
	ArrayCopy(smallList1, smallList2, 20);
	InitArray(bigList1, 50000, INT_MAX);
	ArrayCopy(bigList1, bigList2, 50000);

	// sort the smaller arrays
	quickOne(smallList1, 0, 19);
	smallSwap1 = swapCount;
	smallComp1 = comparisonCount;
	swapCount = 0;
	comparisonCount = 0;

	quickTwo(smallList2, 0, 19);
	smallSwap2 = swapCount;
	smallComp2 = comparisonCount;
	swapCount = 0;
	comparisonCount = 0;

	// sort the larger array the number of times specified
	for (int i = 0; i < numTests; i++) {
		quickOne(bigList1, 0, 49999);
		bigSwap1 += swapCount;
		bigComp1 += comparisonCount;
		swapCount = 0;
		comparisonCount = 0;

		quickTwo(bigList2, 0, 49999);
		bigSwap2 += swapCount;
		bigComp2 += comparisonCount;
		swapCount = 0;
		comparisonCount = 0;
	}
	
	// check to see if lists are properly sorted
	if (CheckList(smallList1, 20) == 0) {
		cout << "\nsmallList1 failed.\n";
	}
	if (CheckList(smallList2, 20) == 0) {
		cout << "\nsmallList2 failed.\n";
	}
	if (CheckList(bigList1, 50000) == 0) {
		cout << "\nbigList1 failed.\n";
	}
	if (CheckList(bigList2, 50000) == 0) {
		cout << "\nbigList2 failed.\n";
	}

	// display results neatly	
	cout << "\nHere is the randomized list after sorting with standard Quicksort:\n";
	for (int i = 0; i < 20; i++) {
		cout << smallList1[i] << ", ";
	}
	cout << "\nHere is the number of comparisons made sorting that list:\n" << smallComp1;
	cout << "\nHere is the number of swaps made sorting that list:\n" << smallSwap1;
	cout << "\nHere is the randomized list after sorting with modified Quicksort:\n";
	for (int i = 0; i < 20; i++) {
		cout << smallList2[i] << ", ";
	}
	cout << "\nHere is the number of comparisons made sorting that list:\n" << smallComp2;
	cout << "\nHere is the number of swaps made sorting that list:\n" << smallSwap2;
	
	cout << "\nHere are the average number of comparisons between Quicksort and modified Quicksort (displayed in that order)\n";
	cout << (bigComp1 / numTests) << ", " << (bigComp2 / numTests);
	cout << "\nHere are the average number of swaps between Quicksort and modified Quicksort (displayed in that order)\n";
	cout << (bigSwap1 / numTests) << ", " << (bigSwap2 / numTests);
	return 0;

}
