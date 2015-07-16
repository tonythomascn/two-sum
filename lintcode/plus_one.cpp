/*
Plus One

29% Accepted
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.

Have you met this question in a real interview? Yes
Example
Given [1,2,3] which represents 123, return [1,2,4].

Given [9,9,9] which represents 999, return [1,0,0,0].
*/
#include "stdafx.h"
#include <vector>
using std::vector;
/**
* @param digits a number represented as an array of digits
* @return the result
*/
vector<int> plusOne(vector<int>& digits) {
	vector<int> res;
	if (0 == digits.size()) {
		res.push_back(1);
		return res;
	}

	int carry = 1;
	for (int i = digits.size() - 1; i >= 0; i--) {
		if (10 == digits[i] + carry) {
			res.insert(res.begin(), 0);
			carry = 1;
		}
		else {
			res.insert(res.begin(), digits[i] + carry);
			carry = 0;
		}
	}
	if (carry)
		res.insert(res.begin(), carry);
	return res;
}