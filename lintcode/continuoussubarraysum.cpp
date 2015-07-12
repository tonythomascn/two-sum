/*
Continuous Subarray Sum

21% Accepted
Given an integer array, find a continuous subarray where the sum of numbers is the biggest. Your code should return the index of the first number and the index of the last number. (If their are duplicate answer, return anyone)

Have you met this question in a real interview? Yes
Example
Give [-3, 1, 3, -3, 4], return [1,4].
*/
#include "stdafx.h"
#include <vector>
using std::vector;
/**
* @param A an integer array
* @return  A list of integers includes the index of
*          the first number and the index of the last number
*/
vector<int> continuousSubarraySum(vector<int>& A) {
	int len = A.size();
	vector<int> res(2, 0);
	if (0 == len) return res;
	int start = 0, end = 0, lastMax = A[0];
	int maxV = lastMax;
	for (int i = 1;i<len;i++)
	{
		if (lastMax < 0)
		{
			start = i;
			lastMax = A[i];
		}
		else 
			lastMax = lastMax + A[i];
		end = i;
		if (lastMax > maxV)
		{
			//always store the maximum subarray index
			maxV = lastMax;
			res[0] = start;
			res[1] = end;
		}
	}
	return res;
}
//int main() {
//	vector<int> v{ -1,-2, -3 };
//	vector<int> i = continuousSubarraySum(v);
//}