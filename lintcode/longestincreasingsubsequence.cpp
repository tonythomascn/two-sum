/*
Longest Increasing Subsequence

26% Accepted
Given a sequence of integers, find the longest increasing subsequence (LIS).

You code should return the length of the LIS.

Have you met this question in a real interview? Yes
Example
For [5, 4, 1, 2, 3], the LIS  is [1, 2, 3], return 3

For [4, 2, 4, 5, 3, 7], the LIS is [4, 4, 5, 7], return 4

Challenge
Time complexity O(n^2) or O(nlogn)

Clarification
What's the definition of longest increasing subsequence?

* The longest increasing subsequence problem is to find a subsequence of a given sequence in which the subsequence's elements are in sorted order, lowest to highest, and in which the subsequence is as long as possible. This subsequence is not necessarily contiguous, or unique.

* https://en.wikipedia.org/wiki/Longest_common_subsequence_problem
*/
#include "stdafx.h"
#include <vector>
using std::vector;
/**
* @param nums: The integer array
* @return: The length of LIS (longest increasing subsequence)
*/
int longestIncreasingSubsequence(vector<int> nums) {
	if (1 >= nums.size())
		return nums.size();

	int *arr = new int[nums.size()];
	memset(arr, 0, nums.size()*sizeof(int));
	for (int i = 1; i < nums.size(); i++) {
		for (int j = 0; j < i; j++) {			
			if (nums[i] >= nums[j] && arr[i] < arr[j] + 1)
				arr[i] = arr[j] + 1;
		}
	}

	int max = 0;	
	for (int i = 0; i < nums.size(); i++) {
		max = max < arr[i] ? arr[i] : max;
	}
	delete[] arr;
	return max + 1;
}
//int main() {
//	vector<int> v{ 10,1,11,2,12,3,11 };
//	longestIncreasingSubsequence(v);
//}