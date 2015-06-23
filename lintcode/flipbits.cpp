/*
Flip Bits

29% Accepted
Determine the number of bits required to flip if you want to convert integer n to integer m.

Have you met this question in a real interview? Yes
Example
Given n = 31 (11111), m = 14 (01110), return 2.

Note
Both n and m are 32-bit integers.*/

/**
*@param a, b: Two integer
*return: An integer
*/
#include "stdafx.h"
int bitSwapRequired(int a, int b) {
	int cnt = 0;
	int c = a ^ b;
	while (c) {
		cnt++;
		c &= c - 1;
	}
	return cnt;
}

//int main() {
//	printf("%d\n", bitSwapRequired(31, 14));
//}