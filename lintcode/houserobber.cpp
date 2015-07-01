/*
House Robber

30% Accepted
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

Have you met this question in a real interview? Yes
Example
Given [3, 8, 4], return 8.

Challenge
O(n) time and O(1) memory.
*/
#include "stdafx.h"
#include <vector>
#include <algorithm>
using std::vector;
/**
* @param A: An array of non-negative integers.
* return: The maximum amount of money you can rob tonight
*/
long long houseRobber(vector<int> A) {
	long long best0 = 0, best1 = 0;
	long long temp;
	for (int i = 0; i < A.size(); ++i) {
		temp = best1 + A[i];
		best1 = best0;
		best0 = std::max(best0, temp);
	}
	return std::max(best0, best1);
}