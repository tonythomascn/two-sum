/*
Count 1 in Binary

54% Accepted
Count how many 1 in binary representation of a 32-bit integer.

Have you met this question in a real interview? Yes
Example
Given 32, return 1

Given 5, return 2

Given 1023, return 9

Challenge
If the integer is n bits with m 1 bits. Can you do it in O(m) time?
*/
/**
* @param num: an integer
* @return: an integer, the number of ones in num
*/
#include <cstdio>
#include <cstdlib>
#include "stdafx.h"
int countOnes(int num) {
	int result = 0;
	while (num) {
		if (num & 1)
			result++;
		num >>= 1;
	}
	return result;
}

int countOnes(int num) {
	int result = 0;
	for (; num > 0; num &= num - 1, result++) {
	}
	return result;
}

//int main() {
//	printf("%d\n", countOnes(32));
//	printf("%d\n", countOnes(5));
//	printf("%d\n", countOnes(1023));
//	///system("pause");
//	return 0;
//}