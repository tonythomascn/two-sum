/*
Majority Number

39% Accepted
Given an array of integers, the majority number is the number that occurs more than half of the size of the array. Find it.

Have you met this question in a real interview? Yes
Example
Given [1, 1, 1, 1, 2, 2, 2], return 1

Challenge
O(n) time and O(1) extra space
*/
#include "stdafx.h"
#include <vector>
using std::vector;
/**
* @param nums: A list of integers
* @return: The majority number
*/
int majorityNumber(vector<int> nums) {
	if (1 >= nums.size())
		return nums[0];
	int major = 0;
	int count = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (0 == count)
			major = nums[i];
		if (nums[i] == major)
			count++;
		else
			count--;
	}
	return major;
}