/*
* Mike Kozlowski
* CSC281
* Project 2
* 9/21/22
*/

// need iostream for cout, need math.h for calculations,
// need fstream to read in the sample files
#include <iostream>
#include <math.h>
#include <fstream>

using namespace std;

int main() {
	ifstream fileInput("sample6");
	int value;
	int calcLog;
	int sum = 0;
	int range[10] = {};
	double result[10] = {};

	// while loop operates until reaches end of file.
	// first, grabs the value and places into value.
	// next, calculates the log10 of the value.
	// finally, divides the value by the exp10 of the log10
	// in order to figure out which value the starting number is.
	// after calculating the first digit, checks increments the
	// value at that index in the range[] array.
	while (!fileInput.eof()) {
		fileInput >> value;
		calcLog = log10(value);	
		value = value / exp10(calcLog);

		if (value == 1) {
			range[1]++;
		}
		else if (value == 2) {
			range[2]++;
		}
		else if (value == 3) {
			range[3]++;
		}
		else if (value == 4) {
			range[4]++;
		}
		else if (value == 5) {
			range[5]++;
		}
		else if (value == 6) {
			range[6]++;
		}
		else if (value == 7) {
			range[7]++;
		}
		else if (value == 8) {
			range[8]++;
		}
		else {
			range[9]++;
		}
	}
	// closes file input stream
	fileInput.close();
	
	// calculates the sum of all first digits counted for
	// determining the average.
	for (int i = 1; i < 10; i++) {
		sum = range[i] + sum;
	}

	cout << "Number, Percentage of Occurence" << endl;

	// outputs the index followed by the average percentage  number of occurences
	// that the current index number appeared in the file
	for (int i = 1; i < 10; i++) {
		result[i] = static_cast<double>(range[i]) / static_cast<double>(sum) * 100;
		cout << i << ",    " << result[i] << "%" << endl;
	}

}
