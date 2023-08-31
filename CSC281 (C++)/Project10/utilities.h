// Mike Kozlowski
// Project 5
// CSC281
// utilities.h: Header file for utilities class and CheckList/GreaterThan functions

#ifndef utilities_h
#define utilities_h

extern int comparisonCount;
extern int swapCount;
bool CheckList( int list[], int size );
bool GreaterThan( int a, int b );
void ArrayCopy ( int list[], int copy[], int size );
void InitArray ( int list[], int size, int maxRange );
void ResetArray ( int list[], int size );
void Swap( int list[], int left, int right );

#endif
