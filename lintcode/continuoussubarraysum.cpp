/*
Continuous Subarray Sum

21% Accepted
Given an integer array, find a continuous subarray where the sum of numbers is the biggest. Your code should return the index of the first number and the index of the last number. (If their are duplicate answer, return anyone)

Have you met this question in a real interview? Yes
Example
Give [-3, 1, 3, -3, 4], return [1,4].
*/
#include "stdafx.h"
#include <vector>
using std::vector;
/**
* @param A an integer array
* @return  A list of integers includes the index of
*          the first number and the index of the last number
*/
vector<int> continuousSubarraySum(vector<int>& A) {
	vector<int> res;
	if (0 == A.size())
		return res;
	if (1 == A.size()) {
		res.push_back(0);
		res.push_back(0);
		return res;
	}
	int sum = 0;
	int start = 0;
	int end = 0;
	int max = INT_MIN;
	for (int i = 0; i < A.size(); i++) {
		sum += A[i];
		if (sum > max) {
			max = sum;
			end = i;
		}
		if (0 > sum) {
			sum = 0;
		}
	}
	sum = 0;
	for (int i = end; i >= start; i--) {
		sum += A[i];
		if (sum == max) {
			start = i;
			break;
		}
	}
	res.push_back(start);
	res.push_back(end);
	return res;
}
int main() {
	vector<int> v{ -4,5,-4,5,-4,5,-4,5,-4,5,-4,5,-4,5,-4,5,-4,5,-1000 };
	vector<int> i = continuousSubarraySum(v);
}