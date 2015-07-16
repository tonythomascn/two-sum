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
void recoverRotatedSortedArray(vector<int> &nums) {
	int min;
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] > nums[i + 1]) {
			min = i + 1;
			break;
		}
	}
	int minimal;
	for (int i = 0; i < min; i++) {
		minimal = nums[0];
		nums.erase(nums.begin());
		nums.emplace_back(minimal);
	}
}
//int main() {
//	vector<int> v{ 4, 5, 1, 2, 3 };
//	recoverRotatedSortedArray(v);
//}