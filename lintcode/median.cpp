/*
Median

22% Accepted
Given a unsorted array with integers, find the median of it.

A median is the middle number of the array after it is sorted.

If there are even numbers in the array, return the N/2-th number after sorted.

Have you met this question in a real interview? Yes
Example
Given [4, 5, 1, 2, 3], return 3

Given [7, 9, 4, 5], return 5

Challenge
O(n) time.
*/
#include "stdafx.h"
#include <vector>
using std::vector;
void swap(vector<int>& nums, int hi, int lo) {
	int tmp = nums[hi];
	nums[hi] = nums[lo];
	nums[lo] = tmp;
}
int findMedian(vector<int> &A, int start, int end, int k){
	int i = start + 1, j = end;
	while (i <= j) {
		while (i <= j && A[i]< A[start]) i++;
		while (i <= j && A[j] >= A[start]) j--;
		if (i < j) swap(A, i, j);
	}
	swap(A, start, j);
	if (j + 1 == k) return A[j];
	else if (j + 1 > k) return findMedian(A, start, j, k);
	else return findMedian(A, j + 1, end, k);
}
/**
* @param nums: A list of integers.
* @return: An integer denotes the middle number of the array.
*/
int median(vector<int> &nums) {
	int n = nums.size();
	return findMedian(nums, 0, n - 1, n / 2 + (n & 1));
}

int main() {
	vector<int> v{ 4 };
	int i = median(v);
}