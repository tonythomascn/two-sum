/*
Search Insert Position

29% Accepted
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume NO duplicates in the array.

Have you met this question in a real interview? Yes
Example
[1,3,5,6], 5 → 2

[1,3,5,6], 2 → 1

[1,3,5,6], 7 → 4

[1,3,5,6], 0 → 0

Challenge
O(log(n)) time
*/
#include "stdafx.h"
#include <vector>
using std::vector;
int find(vector<int> &A, int start, int end, int target) {
	if (start > end)
		return start;
	int mid = start + (end - start) / 2;
	if (A[mid] == target)
		return mid;
	if (A[mid] > target)
		return find(A, start, mid - 1, target);
	if (A[mid] < target)
		return find(A, mid + 1, end, target);
}
/**
* param A : an integer sorted array
* param target :  an integer to be inserted
* return : an integer
*/
int searchInsert(vector<int> &A, int target) {
	return find(A, 0, A.size() - 1, target);
}