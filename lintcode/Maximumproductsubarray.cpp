/*
Maximum Product Subarray

31% Accepted
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

Have you met this question in a real interview? Yes
Example
For example, given the array [2,3,-2,4], the contiguous subarray [2,3] has the largest product = 6.
*/
#include "stdafx.h"
#include <vector>
#include <algorithm>
using std::vector;
/**
* @param nums: a vector of integers
* @return: an integer
*/
int maxProduct(vector<int>& nums) {
	if (0 == nums.size())
		return 0;
	int product = nums[0];
	int max = nums[0];
	int min = nums[0];
	int tmp;
	for (int i = 1; i < nums.size(); i++) {
		tmp = max;
		max = std::max(std::max(max * nums[i], nums[i]), min * nums[i]);
		min = std::min(std::min(tmp * nums[i], nums[i]), min * nums[i]);
		product = std::max(product, max);
	}
	return product;
}