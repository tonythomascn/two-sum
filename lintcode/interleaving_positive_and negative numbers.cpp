/*
Interleaving Positive and Negative Numbers
18%
Accepted

Given an array with positive and negative integers. Re-range it to interleaving with positive and negative integers.
Have you met this question in a real interview?
Example

Given [-1, -2, -3, 4, 5, 6], after re-range, it will be [-1, 5, -2, 4, -3, 6] or any other reasonable answer.
Note

You are not necessary to keep the original order of positive integers or negative integers.
Challenge

Do it in-place and without extra memory.
*/

#include "stdafx.h"
#include <vector>
using std::vector;
/**
* @param A: An integer array.
* @return: void
*/
void rerange(vector<int> &A) {
	int end;
	int tmp;
	for (int start = 0; start < A.size() - 1; ) {
		while (start < A.size()) {
			if (A[start] * A[start + 1] > 0) {
				start++;
				break;
			}
			start++;
		}
		for (end = start + 1; end < A.size(), A[start] * A[end] > 0; end++)
			;
		if (start < A.size() && end < A.size()) {
			tmp = A[start];
			A[start] = A[end];
			A[end] = tmp;
			start++;
		}
	}
}
int main() {
	vector<int> v{ -13,-8,-12,-15,-14,35,7,-1,11,27,10,-7,-12,28,18 };
	rerange(v);
}