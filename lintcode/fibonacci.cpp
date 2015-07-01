/*
Fibonacci

32% Accepted
Find the Nth number in Fibonacci sequence.

A Fibonacci sequence is defined as follow:

The first two numbers are 0 and 1.
The i th number is the sum of i-1 th number and i-2 th number.
The first ten numbers in Fibonacci sequence is:

0, 1, 1, 2, 3, 5, 8, 13, 21, 34 ...

Have you met this question in a real interview?
Which company asked you this question?
Thanks for your feedback.
Example
Given 1, return 0

Given 2, return 1

Given 10, return 34

Note
The Nth fibonacci number won't exceed the max value of signed 32-bit integer in the test cases.
*/

#include "stdafx.h"
#include <vector>
using std::vector;
int fibonacci(int n) {
	if (1 >= n)
		return 0;
	if (2 == n)
		return 1;
	int last = 1, lastprev = 0;
	int now = 0;
	for (int i = 2; i < n; i++) {
		now = last + lastprev;
		lastprev = last;
		last = now;
	}
	return now;
}
int fibonacci2(int n) {
	vector<int> res(3);
	res[0] = 0;
	res[1] = 1;
	for (int i = 2; i <= n; i++) {
		res[i % 3] = res[(i - 1) % 3] + res[(i - 2) % 3];
	}
	//the index of vector is smaller than nth 
	return res[(n - 1) % 3];
}
//int main() {
//	fibonacci(10);
//}