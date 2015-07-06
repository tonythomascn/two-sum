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
#include <algorithm>
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
//O(nlogn)
int findMaxSub(vector<int> nums, int start, int end) {
	if (start == end)
		return nums[start];
	int mid = start + (end - start) / 2;
	//logn
	int leftMax = findMaxSub(nums, start, mid);
	int rightMax = findMaxSub(nums, mid + 1, end);
	int sum = 0;
	int midleftMax = nums[mid];
	//n
	for (int i = mid; i >= start; i--) {
		sum += nums[i];
		if (sum > midleftMax)
			midleftMax = sum;
	}
	int midrightMax = nums[mid + 1];
	sum = 0;
	for (int i = mid + 1; i <= end; i++) {
		sum += nums[i];
		if (sum > midrightMax)
			midrightMax = sum;
	}
	return std::max(std::max(leftMax, rightMax), midleftMax + midrightMax);
}
int maxSubArray2(vector<int> nums) {
	if (0 >= nums.size())
		return 0;
	//divde and conquer
	return findMaxSub(nums, 0, nums.size() - 1);
}

int main() {
	vector<int> v{ -1,-2,-3,-100,-1,-50 };
	int i = maxSubArray2(v);
}