/*
Subarray Sum

22% Accepted
Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.

Have you met this question in a real interview? Yes
Example
Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3].

Note
There is at least one subarray that it's sum equals to zero.
*/
#include "stdafx.h"
#include <vector>
#include <unordered_map>
using std::unordered_map;
using std::vector;
/**
* @param nums: A list of integers
* @return: A list of integers includes the index of the first number
*          and the index of the last number
*/
vector<int> subarraySum(vector<int> nums) {
	// write your code here
	unordered_map<int, int> table;
	table[0] = -1;
	int sum = 0;
	for (int i = 0; i < nums.size(); i++) {
		sum += nums[i];
		if (!table.emplace(sum, i).second)
			return { table[sum] + 1, i };
	}
}
//int main() {
//	vector<int> v{ -4, 1, 2, -3, 4 };
//	v = subarraySum(v);
//}