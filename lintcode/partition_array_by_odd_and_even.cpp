/*
Partition Array by Odd and Even
35%
Accepted

Partition an integers array into odd number first and even number second.
Have you met this question in a real interview?
Example

Given [1, 2, 3, 4], return [1, 3, 2, 4]
Challenge

Do it in-place.
*/
#include "stdafx.h"
#include <vector>
using std::vector;

/**
* @param nums: a vector of integers
* @return: nothing
*/
void partitionArray(vector<int> &nums) {
	if (1 >= nums.size())
		return;
	int start = 0;
	int end = nums.size() - 1;
	int tmp;
	while (start < end){
		if ((0 == nums[start] % 2) &&
			(1 == nums[end] % 2)){
			//if the start and end can swap
			tmp = nums[start];
			nums[start] = nums[end];
			nums[end] = tmp;
			start++;
			end--;
		}
		else{
			//start position is already an odd
			if (1 == nums[start] % 2)
				start++;
			//end position is already an even
			if (0 == nums[end] % 2)
				end--;
		}
	}
}