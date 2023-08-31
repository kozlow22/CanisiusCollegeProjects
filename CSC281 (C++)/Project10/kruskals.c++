// Mike Kozlowski
// Project 10
// CSC281
// kruskals.c++: function which finds the minimum spanning tree using Kruskal's method, based
// on pseudocode written by Dr. Jeffrey McConnell

#include "kruskals.h"
#include "edge.h"
#include "Quicksort.h"
#include "partition.h"

void findMST(int size, Edge graph[], int numEdges, Edge MST[]) {
	int edgeCount = 0;
	int includedCount = 0;
	int parent[numEdges] = {0};
	
	qSort(graph, 0, (numEdges - 1));
	initPart(parent, size);
	
	while (edgeCount <= numEdges && includedCount <= size - 1) {
		int parent1 = findRoot(graph[edgeCount].start);
		int parent2 = findRoot(graph[edgeCount].end);
		if (parent1 != parent2) {
			MST += graph[edgeCount];
			includedCount++;
			Union( parent, parent1, parent2);
		}
		edgeCount++;
	}
}
