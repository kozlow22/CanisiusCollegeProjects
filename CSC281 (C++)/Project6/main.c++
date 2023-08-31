// Mike Kozlowski
// Project 6
// CSC281
// main.c++: The main program that will call the other functions in the project to use the
// two different shell sort functions.

#include "MyRandom.h"
#include "ShellSort.h"
#include "utilities.h"
#include "insertion.h"
#include <limits.h>
#include <iostream>
using namespace std;

int main(int argv, char* argc[]) {
	// Initializing objects and variables, along with setup
	cout.imbue(locale(""));
	int testOneShellOne[20] = {0};
	int testOneShellTwo[20] = {0};
	int testOneIns[20] = {0};
	int testTwoShellOne[50000] = {0};
	int testTwoShellTwo[50000] = {0};
	int testTwoIns[50000] = {0};
	int oneResultShellOne = 0;
	int oneResultShellTwo = 0;
	int oneResultIns = 0;
	int twoResultShellOne = 0;
	int twoResultShellTwo = 0;
	int twoResultIns = 0;
	int numTests = 1;
	int arrayCopy;
	MyRandom r;
	
	// Generating random numbers for the two arrays
	for (int i = 0; i < 20; i++) {
		testOneShellOne[i] = r.RanRange(1, 10000);
	}
	ArrayCopy(testOneShellOne, testOneShellTwo, 20);
	ArrayCopy(testOneShellOne, testOneIns, 20);

	for (int i = 0; i < 50000; i++) {
		testTwoShellOne[i] = r.RanRange(1, INT_MAX);
	}
	ArrayCopy(testTwoShellOne, testTwoShellTwo, 50000);
	ArrayCopy(testTwoShellOne, testTwoIns, 50000);

	// Sort large lists using a loop to get average comparisons
	for (int i = 0; i < numTests; i++) {
		shellOne(testTwoShellOne, 50000);
		shellTwo(testTwoShellTwo, 50000);
		insSort(testTwoIns, 50000, 0, 1);
		// Add the number of comparisons to running counter ccResult and reset global comparisonCount
		if (CheckList(testTwoShellOne, 50000) == 1) {
			twoResultShellOne += comparisonCount;
			comparisonCount = 0;
		} else {
			// if CheckList fails, escape loop
			cout << "ShellOne Failed.\n";
			i = numTests;
		}
		if (CheckList(testTwoShellTwo, 50000) == 1) {
			twoResultShellTwo += comparisonCount;
			comparisonCount = 0;
		} else {
			cout << "ShellTwo Failed.\n";
			i = numTests;
		}
		if (CheckList(testTwoIns, 50000) == 1) {
			twoResultIns += comparisonCount;
			comparisonCount = 0;
		} else {
			cout << "Insertion Failed.\n";
			i = numTests;
		}
		// Reset arrays to 0
		for (int i = 0; i < 50000; i++) {
			testTwoShellOne[i] = 0;
		}
		ArrayCopy(testTwoShellOne, testTwoShellTwo, 50000);
		ArrayCopy(testTwoShellOne, testTwoIns, 50000);

		// Generate new set of random numbers for the array
		for (int i = 0; i < 50000; i++) {
			testTwoShellOne[i] = r.RanRange(1, INT_MAX);
		}
		ArrayCopy(testTwoShellOne, testTwoShellTwo, 50000);
		ArrayCopy(testTwoShellOne, testTwoIns, 50000);
	}
	// Reset comparisonCount and then sort the smaller lists
	comparisonCount = 0;
	shellOne(testOneShellOne, 20);
	oneResultShellOne = comparisonCount;
	
	comparisonCount = 0;
	shellTwo(testOneShellTwo, 20);
	oneResultShellTwo = comparisonCount;

	comparisonCount = 0;
	insSort(testOneIns, 20, 0, 1);
	oneResultIns = comparisonCount;

	// Checks to see if the list was properly sorted
	if (CheckList(testOneShellOne, 20) == 0) {
		cout << "ShellOne failed.\n";
	}
	if (CheckList(testOneShellTwo, 20) == 0) {
		cout << "ShellTwo failed.\n";
	}
	if (CheckList (testOneIns, 20) == 0) {
		cout << "Insert failed.\n";
	}

	// Display results in a nicely formatted way
	cout << "\nHere is the randomized list after sorting with standard ShellSort:\n";
	for (int i = 0; i < 20; i++) {
		cout << testOneShellOne[i] << ", ";
	}
	cout << "\nHere is the number of comparisons made sorting that list:\n" << oneResultShellOne;
	cout << "\nHere is the randomized list after sorting with modified ShellSort:\n";
	for (int i = 0; i < 20; i++) {
		cout << testOneShellTwo[i] << ", ";
	}
	cout << "\nHere is the number of comparisons made sorting that list:\n" << oneResultShellTwo;
	cout << "\nHere is the randomized list after sorting with modified Insertion Sort:\n";
	for (int i = 0; i < 20; i++) {
		cout << testOneIns[i] << ", ";
	}
	cout << "\nHere is the number of comparisons made sorting that list:\n" << oneResultIns;
	cout << "\nHere are the average number of comparisons between Shell Sort,\nModified Shell Sort, and Modified Insertion Sort (displayed in that order)\n";
	cout << (twoResultShellOne / numTests) << ", " << (twoResultShellTwo / numTests) << ", " << (twoResultIns / numTests) << ".";
	return 0;
}
