/*
Recover Rotated Sorted Array

26% Accepted
Given a rotated sorted array, recover it to sorted array in-place.

Have you met this question in a real interview? Yes
Example
[4, 5, 1, 2, 3] -> [1, 2, 3, 4, 5]

Challenge
In-place, O(1) extra space and O(n) time.

Clarification
What is rotated array?

For example, the orginal array is [1,2,3,4], The rotated array of it can be [1,2,3,4], [2,3,4,1], [3,4,1,2], [4,1,2,3
*/
#include "stdafx.h"
#include <vector>
using std::vector;
/*
Move the one before the minimal to the end of the array
Time complexity O(n), extra space O(1)
*/
void recoverRotatedSortedArray(vector<int> &nums) {
	int min;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > nums[i + 1]) {
			min = i + 1;
			break;
		}
	}
	int temp;
	for (int i = 0; i < min; i++) {
		temp = nums[0];
		nums.erase(nums.begin());
		nums.emplace_back(temp);
	}
}
/*
After find the maximum and minimum, reverse the begin to the maximum, 
reverse the minimum to the end, then reverse the whole array.
Time complexity O(n), extra space O(1)
*/
void reverse(vector<int> &nums, int start, int end) {
	int tmp;
	while (start < end) {
		tmp = nums[start];
		nums[start] = nums[end];
		nums[end] = tmp;
		start++;
		end--;
	} 
}

void recoverRotatedSortedArray2(vector<int> &nums) {
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > nums[i + 1]) {
			reverse(nums, 0, i);
			reverse(nums, i + 1, nums.size() - 1);
			reverse(nums, 0, nums.size() - 1);
			return;
		}
	}
}
//int main() {
//	vector<int> v{ 4, 5, 1, 2, 3 };
//	recoverRotatedSortedArray(v);
//}