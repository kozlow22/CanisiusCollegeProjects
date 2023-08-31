// Mike Kozlowski
// Project 10
// CSC281
// main.c++: the main program which will prompt a user for a file name, then 
// will graph details from that file, and a minimum spanning tree is found
// using Kruskal's method and saved as the same file name with a .mst extension,
// then will print the total weights of the nodes in the graph in the MST.

#include <iostream>
#include <fstream>
#include <string>
#include "edge.h"
#include "kruskals.h"
using namespace std;

int main(int argv, char* argc[]) {
	// initializing variables, along with setup
	cout.imbue(locale(""));
	string filename;
	string dump;
	int nodes, edges;
	int runner = 0;
	int totalWeight = 0;
	
	// opening file, setting up graph construction
	cout << "/nWhat is the name of the file?\n";
	cin >> filename;
	string mstName = filename + ".mst";

	ifstream file;
	file.open(filename);
	getline(file, nodes);
	getline(file, edges);
	Edge MST[edges], graph[edges];

	// constructing graph from file
	while (file) {
		graph[runner].start = file.get();
		graph[runner].start--;
		dump = file.get();
		graph[runner].end = file.get();
		graph[runner].end--;
		dump = file.get();
		graph[runner].weight = file.get();
		dump = file.get();
		runner++;
	}
	file.close();

	// send constructed graph to Kruskal's method
	findMST( nodes, graph, edges, MST );

	// now that the MST is constructed, write the MST to a new file
	ofstream saveMST(mstName);
	saveMST << nodes << "\n";
	saveMST << edges << "\n";
	for (int i = 0; i < edges; i++) {
		saveMST << (MST[i].start + 1) << " -> " << (MST[i].end + 1) << "\n";
		totalWeight += MST[i].weight;
	}
	saveMST.close();
	cout << "\nTotal weight in the MST: " << totalWeight << ".\n";
	return 0;
}
