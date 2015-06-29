/*
Longest Increasing Continuous subsequence

25% Accepted
Give you an integer array (index from 0 to n-1, where n is the size of this array)，find the longest increasing continuous subsequence in this array. (The definition of the longest increasing continuous subsequence here can be from right to left or from left to right)

Have you met this question in a real interview? Yes
Example
For [5, 4, 2, 1, 3], the LICS is [5, 4, 2, 1], return 4.

For [5, 1, 2, 3, 4], the LICS is [1, 2, 3, 4], return 4.

Note
O(n) time and O(1) extra space.
*/
#include "stdafx.h"
#include <vector>
#include <algorithm>
using std::vector;
/**
* @param A an array of Integer
* @return  an integer
*/
int longestIncreasingContinuousSubsequence(vector<int>& A) {
	if (2 > A.size()) {
		return A.size();
	}
	//assume the array is increasing
	bool fromLeft = true;
	int curr = 1;
	int res = 0;
	for (int i = 1; i < A.size(); i++) {
		if (A[i] > A[i - 1]) {
			if (!fromLeft) {
				res = res < curr ? curr : res;
				curr = 2;	
			}
			else {
				curr++;
			}
			fromLeft = true;
		}
		else if (A[i] < A[i - 1]) {
			if (fromLeft) {
				res = res < curr ? curr : res;
				curr = 2;	
			}
			else
				curr++;
			fromLeft = false;
		}
	}
	res = res < curr ? curr : res;
	return res;
}