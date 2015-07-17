/*
Remove Element

34% Accepted
Given an array and a value, remove all occurrences of that value in place and return the new length.

The order of elements can be changed, and the elements after the new length don't matter.

Have you met this question in a real interview? Yes
Example
Given an array [0,4,4,0,0,2,4,4], value=4

return 4 and front four elements of the array is [0,0,0,2]
*/
#include "stdafx.h"
#include <vector>
using std::vector;
/**
*@param A: A list of integers
*@param elem: An integer
*@return: The new length after remove
Scan the array, if same, erase it
*/
int removeElement(vector<int> &A, int elem) {
	for (auto it = A.begin(); it != A.end();) {
		if (elem == *it)
			it = A.erase(it);
		else
			it++;
	}
	return A.size();
}
/*
Scan the array, move the not the same ones to the left side
*/
int removeElement2(vector<int>& A, int elem) {
	int index = 0;
	for (int i = 0; i < A.size(); i++) {
		if (A[i] != elem) {
			A[index++] = A[i];
		}
	}
	return index;
}
//int main() { 
//	vector<int> v{ 1, 1, 2 };
//	int i = removeElement(v, 1);
//}