// Mike Kozlowski
// Project 4
// CSC281
// Pseudocode written by Dr. Jeffrey McConnell
// Code for MyRandom class which can either generate a random number from 0 to 1 or
// generate a random number between a given range, both of which either using a set
// seed or using an inputted parameter for the seed
#include <limits.h>
#include "MyRandom.h"

// Constructs the MyRandom class with no inputted seed
MyRandom::MyRandom() {
	seed = INT_MAX / 2;
	a = 16807;
	m = 2147483647;
	q = m / a;
	r = m % a;
}

// Constructs the MyRandom class with a given seed
MyRandom::MyRandom(int parameter) {
	seed = parameter;
	a = 16807;
	m = 2147483647;
	q = m / a;
	r = m % a;
}

// Generates a random number between 0 and 1
double MyRandom::RanNum() {
	high = seed / q;
	low = seed % q;
	test = (a * low) - (r * high);
	if( test > 0 ) {		
		seed = test;		
	} else {		
		seed = test + m;
	}
	return seed / double(m);	
}

// uses RanNum to generate random numbers between a given range of numbers
int MyRandom::RanRange(int rangeLow, int rangeHigh) {				
	return( ( rangeHigh - rangeLow ) * RanNum() + rangeLow );
}
