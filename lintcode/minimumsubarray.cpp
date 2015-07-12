/*
Minimum Subarray

39% Accepted
Given an array of integers, find the subarray with smallest sum.

Return the sum of the subarray.

Have you met this question in a real interview? Yes
Example
For [1, -1, -2, 1], return -3

Note
The subarray should contain at least one integer.
*/

#include "stdafx.h"
#include <vector>
using std::vector;
/**
* @param nums: a list of integers
* @return: A integer denote the sum of minimum subarray
*/
int minSubArray(vector<int> nums) {
	int sum = 0;
	int min = INT_MAX;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (sum < min)
			min = sum;
		if (sum > 0)
			sum = 0;
	}
	return min;
}