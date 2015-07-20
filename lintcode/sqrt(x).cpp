/*
Sqrt(x)

23 % Accepted
Implement int sqrt(int x).

Compute and return the square root of x.

Have you met this question in a real interview ? Yes
Example
sqrt(3) = 1

sqrt(4) = 2

sqrt(5) = 2

sqrt(10) = 3

Challenge
O(log(x))
*/
#include "stdafx.h"
/**
* @param x: An integer
* @return: The sqrt of x
*/
int sqrt(int x) {
	int low = 1;
	int high = x / 2 + 1;
	int mid;
	while (low < high) {
		mid = low + (high - low) / 2;
		if (mid > x / mid)
			high = mid - 1;
		else
			low = mid + 1;
	}
	return low - 1;
}