/*
Remove Duplicates from Sorted Array

32% Accepted
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Have you met this question in a real interview? Yes
Example
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/
#include "stdafx.h"
#include <vector>
using std::vector;
/**
* @param A: a list of integers
* @return : return an integer
*/
int removeDuplicates(vector<int> &nums) {
	for (auto it = nums.begin(); it != nums.end();) {
		if ((it + 1) != nums.end() && *it == *(it + 1))
			nums.erase(it + 1);
		else
			it++;
	}
	return nums.size();
}
/*
Use two pointers to scan the whole array, the left side is the final no duplicate array.
but the final array still contains duplicate items on the right side.
*/
int removeDuplicates_v2(vector<int>&nums) {
	if (nums.empty())
		return 0;

	int left = 0;
	int right = 1;
	while (right < nums.size()) {
		if (nums[left] != nums[right]) {
			left++;
			nums[left] = nums[right];
		}
		right++;
	}
	return left + 1;
}
//int main() { 
//	vector<int> v{ 1, 1, 2 };
//	int i = removeDuplicates_v2(v);
//}