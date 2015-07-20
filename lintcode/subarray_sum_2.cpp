/*
Subarray Sum II

29% Accepted
Given an integer array, find a subarray where the sum of numbers is between two given interval. Your code should return the number of possible answer.

Have you met this question in a real interview? Yes
Example
Given [1,2,3,4] and interval = [1,3], return 4. The possible answers are:

[0, 0]
[0, 1]
[1, 1]
[2, 2]
*/
#include "stdafx.h"
#include <vector>
#include <numeric>
using std::vector;
/**
* @param A an integer array
* @param start an integer
* @param end an integer
* @return the number of possible answer
*/
int subarraySumII(vector<int>& A, int start, int end) {
	vector<int> B(A.size() + 1, 0);
	//for (int i = 0; i < A.size(); i++)
		//B[i + 1] = B[i] + A[i];
	std::partial_sum(A.cbegin(), A.cend(), B.begin() + 1);
	int result = 0;
	for (int i = 0; i < A.size(); i++) {
		for (int j = 0; j <= i; j++)
			if (B[i + 1] - B[j] >= start &&
				B[i + 1] - B[j] <= end)
			result++;
	}
	return result;
}

//int main() {
//	vector<int> v{ 1,2,3,4 };
//	int r = subarraySumII(v, 1, 3);
//}