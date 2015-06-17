/*
Single Number

60% Accepted
Given 2*n + 1 numbers, every numbers occurs twice except one, find it.

Have you met this question in a real interview? Yes
Example
Given [1,2,2,1,3,4,3], return 4

Challenge
One-pass, constant extra space.*/

#include "stdafx.h"
#include <vector>
#include <iostream>
using std::vector;

int singleNumber(vector<int> &A) {
	// write your code here
	int result = 0;
	for (int i = 0; i < A.size(); i++) {
		result ^= A[i];
	}
	return result;
}

int main() {
	vector<int> A{ 1, 2, 2, 1, 3, 4, 3 };
	
	std::cout << singleNumber(A);
	system("pause");
	return 0;
}