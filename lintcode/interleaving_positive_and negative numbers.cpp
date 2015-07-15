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
#include <algorithm>
using std::vector;
/**
* @param A: An integer array.
* @return: void
*/
void rerange(vector<int> &A) {
	int positive = 0;
	for (auto i : A) {
		positive += i > 0 ? 1 : 0;
	}
	bool expectpositive = true;
	//if number of positive is less or equal to negative
	if (positive * 2 <= A.size())
		expectpositive = false;//let the negative start in the new array

	int pos = 0;
	int neg = 0;
	int i = 0;
	while (pos < A.size() && neg < A.size()) {
		while (pos < A.size() && A[pos] > 0)
			pos++;
		while (neg < A.size() && A[neg] < 0)
			neg++;

		if (expectpositive && 0 > A[i])
			std::swap(A[i], A[neg]);
		if (!expectpositive && 0 < A[i])
			std::swap(A[i], A[pos]);

		if (i == pos) pos++;
		if (i == neg) neg++;
		expectpositive = !expectpositive;
		i++;
	}
}
//int main() {
//	vector<int> v{ -13,-8,-12,-15,-14,35,7,-1,11,27,10,-7,-12,28,18 };
//	rerange(v);
//}