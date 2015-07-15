/*
Partition Array
25%
Accepted

Given an array nums of integers and an int k, partition the array (i.e move the elements in "nums") such that:

All elements < k are moved to the left
All elements >= k are moved to the right

Return the partitioning index, i.e the first index i nums[i] >= k.
Have you met this question in a real interview?
Example

If nums = [3,2,2,1] and k=2, a valid answer is 1.
Note

You should do really partition in array nums instead of just counting the numbers of integers smaller than k.

If all elements in nums are smaller than k, then return nums.length
Challenge

Can you partition the array in-place and in O(n)?
*/
#include "stdafx.h"
#include <vector>
using std::vector;

int partitionArray(vector<int> &nums, int k) {
	if (0 == nums.size())
		return 0;
	int start = 0;
	int end = nums.size() - 1;
	int tmp;

	int res = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (k > nums[i])
			res++;
	}
	if (res == nums.size())
		return res;

	while (start <= end) {
		while (nums[start] < k)
			start++;
		while (nums[end] >= k)
			end--;
		if (start < end) {
			tmp = nums[start];
			nums[start] = nums[end];
			nums[end] = tmp;
			start++;
			end--;
		}
	}
	return res;
}

//int main() {
//	vector<int> v{ 9,9,9,8,9,8,7,9,8,8,8,9,8,9,8,8,6,9 };
//	int i = partitionArray(v, 9);
//}