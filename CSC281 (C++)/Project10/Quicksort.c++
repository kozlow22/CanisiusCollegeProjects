// Mike Kozlowski
// Project 8
// CSC281
// Quicksort.c++: Functions to sort a list using two different Pivotlist methods given in
// pseudocode by Dr. Jeffrey McConnell

#include "Quicksort.h"
#include "utilities.h"
#include "edge.h"
using namespace std;

void qSort( Edge edge[], int first, int last ) {
	if (GreaterThan(last, first)) {
		int pivot = pivotOne(edge, first, last);
		qSort(edge, first, pivot-1);
		qSort(edge, pivot+1, last);
	}
}

int pivotOne( Edge edge[], int first, int last ) {
	int upper, lower;
	int pivotValue = list[first];
	int pivotPoint = first;

	for (int i = first + 1; i <= last; i++) {
		if (GreaterThan(pivotValue, edge[i].weight)) {
			pivotPoint++;
			Swap(edge, pivotPoint, i);	
		}
	}
	Swap(edge, first, pivotPoint);
	return pivotPoint;
}
