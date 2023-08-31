// Mike Kozlowski
// Project 7
// CSC281
// HeapSort.c++: actual code for heap sort algorithm as described in pseudocode by Dr. Jeffrey McConnell

#include "HeapSort.h"
#include "utilities.h"

int vacant, largerChild;

void fixHeap(int list[], int root, int key, int bound) {
	vacant = root;
	while ((2 * vacant + 1) <= (bound)) {
		largerChild = 2 * vacant + 1;
		if ((largerChild < bound) && GreaterThan(list[largerChild + 1], list[largerChild])) {
			largerChild = largerChild + 1;
		}
		if (key > list[largerChild]) {
			break;
		} else {
			list[vacant] = list[largerChild];
			vacant = largerChild;
		}
	}
	list[vacant] = key;
}
