// Mike Kozlowski
// Project 4 Main Program
// Program that generates 10 random numbers from 0 to 1 and arranges an array of size 10 with values 1-10 in random order
// CSC281

#include <iostream>
#include "MyRandom.h"
using namespace std;

int main(int argv, char* argc[]) {
	// Declare initial arrays, variables, and objects
	double doubleArray[10] = {0};
	int intArray[10] = {0};
	MyRandom r;

	// Call MyRandom to assign random numbers to the doubleArray using a for loop
	for (int i = 0; i < 10; i++) {
		doubleArray[i] = r.RanNum();
	}
	// Call MyRandom to assign random numbers to the intArray using method 3 in the textbook
	int location = 1;
	double skip;
	int freeCount = 10;
	for (int i = 0; i < 10; i++) {
		skip = (freeCount * r.RanNum() + 1);
		while (skip > 0) {
			location = ((location + 1) % 10);
			if (intArray[location] == 0) {
				skip = skip - 1;
			}
		}
		intArray[location] = i+1;
		freeCount = freeCount - 1;
	}
	// Display both arrays in a neat arrangement
	cout << "Array of random doubles:\n\t[ ";
	for (int i = 0; i < 10; i++) {
		cout << doubleArray[i] << " ";
	}
	cout << "]\nArray of numbers from 1 to 10:\n\t[ ";
	for (int i = 0; i < 10; i++) {
		cout << intArray[i] << " ";
	}
	cout << "]\n";
	return 0;
}
