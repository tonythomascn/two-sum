/*
Merge Sorted Array II

34% Accepted
Merge two given sorted integer array A and B into a new sorted integer array.

Have you met this question in a real interview? Yes
Example
A=[1,2,3,4]

B=[2,4,5,6]

return [1,2,2,3,4,4,5,6]

Challenge
How can you optimize your algorithm if one array is very large and the other is very small?
*/
#include "stdafx.h"
#include <vector>
using std::vector;
/**
* @param A and B: sorted integer array A and B.
* @return: A new sorted integer array
*/
vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
	int i = 0, j = 0;
	vector<int> res;
	for (; i < A.size() && j < B.size();) {
		res.push_back(A[i] > B[j] ? A[i++] : B[j++]);		
	}
	while (i < A.size()) {
		res.push_back(A[i++]);
	}
	while (j < B.size()) {
		res.push_back(B[j++]);
	}
	return res;
}
//int main() {
//	vector<int> v{ 7 };
//	vector<int> v2{ 5, 7 };
//	vector<int> r = mergeSortedArray(v, v2);
//}