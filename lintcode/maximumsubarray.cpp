/*
Maximum Subarray

38% Accepted
Given an array of integers, find a contiguous subarray which has the largest sum.

Have you met this question in a real interview? Yes
Example
Given the array [−2,2,−3,4,−1,2,1,−5,3], the contiguous subarray [4,−1,2,1] has the largest sum = 6.

Note
The subarray should contain at least one number.

Challenge
Can you do it in time complexity O(n)?
*/
#include "stdafx.h"
#include <vector>
using std::vector;
/**
* @param nums: A list of integers
* @return: A integer indicate the sum of max subarray
*/
int maxSubArray(vector<int> nums) {
	int sum = 0;
	int max = INT_MIN;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (sum > max)
			max = sum;
		if (0 > sum) {
			sum = 0;
		}
	}
	return max;
}