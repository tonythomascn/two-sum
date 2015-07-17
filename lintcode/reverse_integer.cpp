/*
Reverse Integer

28% Accepted
Reverse digits of an integer. Returns 0 when the reversed integer overflows (signed 32-bit integer).

Have you met this question in a real interview? Yes
Example
Given x = 123, return 321

Given x = -123, return -321
*/
#include "stdafx.h"
#include <algorithm>
/**
* @param n the integer to be reversed
* @return the reversed integer
*/
int reverseInteger(int n) {
	bool positive = true;
	if (0 > n) {
		positive = false;
		n = -n;
	}
	long long tmp = 0;
	while (n) {
		tmp = tmp * 10 + n % 10;
		n /= 10;
	}
	if (tmp > INT_MAX) return 0;
	return positive ? tmp : -tmp;
}
