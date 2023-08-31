// Mike Kozlowski
// CSC281
// Project 10
// partition.h: header file for partitioning routine functions located in partition.c++

#ifndef partition_h
#define partition_h

void initPart( int parent[], int size );
void Union( int parent[], int i, int j );
int findRoot( int parent[], int s );

#endif
