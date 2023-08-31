// Mike Kozlowski
// CSC281
// Project 10
// partition.c++: functions related to partitioning Edge lists for Kruskal's method for finding
// the minimum spanning tree of a graph, based on pseudocode written by Dr. Jeffrey McConnell

#include "partition.h"

void initPart(int parent[], int size) {
	for (int i = 0; i < size - 1; i++) {
		parent[i] = -1;
	}
}

void Union(int parent[], int i, int j) {
	int totalElements = parent[i] + parent[j];
	if (parent[i] >= parent[j]) {
		parent[i] = j;
		parent[j] = totalElements;
	} else {
		parent[j] = i;
		parent[i] = totalElements;
	}
}

int findRoot(int parent[], int s) {
	int result = s;
	while (parent[result] >= 0) {
		result = parent[result]
	}
	return result;
}
