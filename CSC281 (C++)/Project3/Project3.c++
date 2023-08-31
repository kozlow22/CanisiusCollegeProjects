/*
* Mike Kozlowski
* CSC 281
* Project 3
* 9/28/22
*/

//iostream to input/output from the console
#include <iostream>

using namespace std;

//global integers for counting the work of the algos
int pow1Counter;
int pow2Counter;

//first algo listed in the project description
int Power1( int x, int y ) {
	if( y == 0 ) {
		pow1Counter = pow1Counter + 1;
		return 1;
	} else {
		if( y % 2 == 0) {
			pow1Counter = pow1Counter + 1;
			return ( Power1( x, y/2 ) * Power1( x, y/2 ) );
		} else {
			pow1Counter = pow1Counter + 1;
			return ( x * Power1( x, y/2 ) * Power1( x, y/2 ) );
		}
	}
}

//second algo listed in the project description
int Power2( int x, int y ) {
	if( y == 0 ) {
		pow2Counter = pow2Counter + 1;
		return 1;
	} else {
		int temp = Power2( x, y/2);
		if( y % 2 == 0) {
			pow2Counter = pow2Counter + 1;
			return ( temp * temp );
		} else {
			pow2Counter = pow2Counter + 1;
			return ( x * temp * temp );
		}
	}
}

int main() {
	int x;
	int y;

	// taking input from the user for calculations
	cout << "Raise this number: " << endl;
	cin >> x;
	cout << "To this power: " << endl;
	cin >> y;


	// need to put the global variable output on a separate line
	// due to the recursive nature of the functions. 
	// otherwise, counters output as 0.
	cout << "For algo 1, the answer is: " << Power1( x, y );
	cout << ", and the work done is: " << pow1Counter << "." << endl;
	cout << "For algo 2, the answer is: " << Power2( x, y );
	cout << ", and the work done is: " << pow2Counter << "." << endl;
}
