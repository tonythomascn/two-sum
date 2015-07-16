/*
Product of Array Exclude Itself Show result

25% Accepted
Given an integers array A.

Define B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1], calculate B WITHOUT divide operation.

Have you met this question in a real interview? Yes
Example
For A = [1, 2, 3], return [6, 3, 2].
*/
#include "stdafx.h"
#include <vector>
using std::vector;
/**
* @param A: Given an integers array A
* @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
* repeatively calculate every one, time complexity O(n^2), extra space O(1)
*/
vector<long long> productExcludeItself(vector<int> &nums) {
	vector<long long> result;
	long long product = 1;
	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < nums.size(); j++) {
			if (i != j)
				product *= nums[j];
		}
		result.push_back(product);
		product = 1;
	}
	return result;
}

/*
Calculate the left part and right part separately, time complexity O(n)
*/
vector<long long> productExcludeItself2(vector<int> &nums) {
	vector<long long> result(nums.size(), 1);
	for (int i = 1; i < nums.size(); i++) 
		result[i] = result[i - 1] * nums[i - 1];

	long long product = 1;
	for (int i = nums.size() - 1; i >= 0; i--) {
		result[i] *= product;
		product *= nums[i];
	}
	return result;
}