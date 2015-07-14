/*
O(1) Check Power of 2
25%
Accepted

Using O(1) time to check whether an integer n is a power of 2.
Have you met this question in a real interview?
Example

For n=4, return true;

For n=5, return false;
Challenge

O(1) time
*/
#include "stdafx.h"
/*
* @param n: An integer
* @return: True or false
*/
bool checkPowerOf2(int n) {
	if (1 > n)
		return false;
	// powers of two have one and only one bit set in their binary representation
	return n && !(n & (n - 1));
}

//int main(){
//	bool a = checkPowerOf2(1);
//
//}