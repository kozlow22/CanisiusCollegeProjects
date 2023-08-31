// Mike Kozlowski
// Project 4
// CSC281
// Pseudocode written by Dr. Jeffrey McConnell
// Header for constructors and functions in MyRandom class

#ifndef MyRandom_h
#define MyRandom_h

class MyRandom {
	public:
		// Random without an inputted seed	
		MyRandom();
		
		// Random based on seed given
		MyRandom(int parameter);
		
		// Generates random double from 0 to 1
		double RanNum();

		// Generates a random number given a range of numbers
		int RanRange(int rangeLow, int rangeHigh);		
	private:
		int a, m, q, r, high, low, test, seed;
};
#endif
