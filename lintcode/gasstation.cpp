/*
Gas Station

29% Accepted
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Have you met this question in a real interview? Yes
Example
Given 4 gas stations with gas[i]=[1,1,3,1], and the cost[i]=[2,2,1,1]. The starting gas station's index is 2.

Note
The solution is guaranteed to be unique.

Challenge
O(n) time and O(1) extra space
*/

/**
* @param gas: a vector of integers
* @param cost: a vector of integers
* @return: an integer
*/
#include "stdafx.h"
#include <vector>
using std::vector;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
	if (gas.size() != cost.size())
		return -1;

	int total = 0;
	int currtotal = 0;
	int start = 0;
	for (int i = 0; i < gas.size(); i++) {
		currtotal += gas[i] - cost[i];
		total += currtotal;
		if (0 > currtotal) {
			start = i + 1;
			currtotal = 0;
		}
	}
	if (0 > total)
		return -1;
	return start;
}
//int main() {
//	vector<int> g{ 1, 1, 3, 1 };
//	vector<int> c{ 2, 2, 1, 1 };
//	printf("%d\n", canCompleteCircuit(g, c));
//
//}