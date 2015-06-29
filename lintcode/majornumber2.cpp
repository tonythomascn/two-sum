/*
Majority Number II Show result

25% Accepted
Given an array of integers, the majority number is the number that occurs more than 1/3 of the size of the array.

Find it.

Have you met this question in a real interview? Yes
Example
Given [1, 2, 1, 2, 1, 3, 3], return 1.

Note
There is only one majority number in the array.

Challenge
O(n) time and O(1) extra space.
*/
#include "stdafx.h"
#include <vector>
using std::vector;
/**
* @param nums: A list of integers
* @return: The majority number occurs more than 1/3.
*/
int majorityNumber2(vector<int> nums) {
	if (1 >= nums.size())
		return nums[0];
	int count1 = 0;
	int count2 = 0;
	int major1 = 0;
	int major2 = 0;
	for (int i = 0; i < nums.size(); i++) {
		if (0 != count1 && nums[i] == major1) {
			count1++;
		}
		else if (0 != count2 && nums[i] == major2) {
			count2++;
		}
		else if (0 == count1) {
			major1 = nums[i];
			count1 = 1;
		}
		else if (0 == count2) {
			major2 = nums[i];
			count2 = 1;
		}

		else {
			count1--;
			count2--;
		}
	}
	// count the two candiates.
	count1 = 0;
	count2 = 0;
	for (int num : nums) {
		if (num == major1) {
			count1++;
		}
		else if (num == major2) {
			count2++;
		}
	}
	return count1 > count2? major1 : major2;
}
int main() {
	vector<int> v{ 1,1,1,1,2,2,3,3,4,4,4 };
	majorityNumber2(v);
}