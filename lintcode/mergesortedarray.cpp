/*
Merge Sorted Array

36% Accepted
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Have you met this question in a real interview? Yes
Example
A = [1, 2, 3, empty, empty], B = [4, 5]

After merge, A will be filled as [1, 2, 3, 4, 5]

Note
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
*/
#include "stdafx.h"
/**
* @param A: sorted integer array A which has m elements,
*           but size of A is m+n
* @param B: sorted integer array B which has n elements
* @return: void
*/
void mergeSortedArray(int A[], int m, int B[], int n) {
	int counter = m + n - 1;
	int i = m - 1, j = n - 1;
	while (i >= 0 && j >= 0) {
		A[counter--] = A[i] > B[j] ? A[i--] : B[j--];
	}
	while (j >= 0) {
		A[counter--] = B[j--];
	}
}