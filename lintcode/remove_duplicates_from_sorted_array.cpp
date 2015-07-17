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

//int main() {
//	vector<int> v{ 1, 1, 2 };
//	int i = removeDuplicates(v);
//}