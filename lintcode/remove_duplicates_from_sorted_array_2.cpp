/*
Remove Duplicates from Sorted Array II

29% Accepted
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/
#include "stdafx.h"
#include <vector>
using std::vector;
/**
* @param A: a list of integers
* @return : return an integer
*/
int removeDuplicates2(vector<int> &nums) {
	for (auto it = nums.begin(); it != nums.end();) {
		if ((it + 1) != nums.end() && *it == *(it + 1)) {
			if ((it + 2) != nums.end() && *it == *(it + 2)) {
				nums.erase(it + 2);
			}
			else
				it++;
		}
		else
			it++;
	}
	return nums.size();
}
/*
Use two pointers to scan the whole array, the left side is the final with one duplicate array.
but the final array still contains duplicate items on the right side.
*/
int removeDuplicates2_v2(vector<int>&nums) {
	if (nums.empty())
		return 0;

	const int k = 2;

	int left = 0;
	int right = 1;
	while (right < nums.size()) {
		if (nums[left] != nums[right] ||
			(0 > left - k + 1 || nums[left] != nums[left - k + 1])) {
			left++;
			nums[left] = nums[right];
		}
		right++;
	}
	return left + 1;
}