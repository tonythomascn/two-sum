/*
Coins in a Line II

25 % Accepted
There are n coins with different value in a line.Two players take turns to take one or two coins from left side until there are no more coins left.The player who take the coins with the most value wins.

Could you please decide the first player will win or lose ?

Have you met this question in a real interview ? Yes
Example
Given values array A = [1, 2, 2], return true.

Given A = [1, 2, 4], return false.
*/

#include "stdafx.h"
#include <vector>
using std::vector;
int max(int a, int b) {
	return a >= b ? a : b;
}
int min(int a, int b) {
	return a <= b ? a : b;
}
/**
* @param values: a vector of integers
* @return: a boolean which equals to true if the first player will win
*/
bool firstWillWin(vector<int> &values) {
	vector<int> P(5);
	int sum = 0;
	for (int i = values.size() - 1; i >= 0; --i) {
		sum += values[i];
		const int a = i + 1 < values.size() ? values[i + 1] : 0;
		const int b = i + 2 < values.size() ? P[(i + 2) % 5] : 0;
		const int c = i + 3 < values.size() ? P[(i + 3) % 5] : 0;
		const int d = i + 4 < values.size() ? P[(i + 4) % 5] : 0;
		// P[i] = max(values[i] + min(P[i + 2], P[i + 3]),
		//            values[i] + values[i + 1] + min(P[i + 3], P[i + 4]))
		P[i % 5] = max(values[i] + min(b, c), values[i] + a + min(c, d));
	}

	return P[0] > sum - P[0];
}

//int main() {
//	vector<int> v{ 1, 2, 4 };
//	bool result = firstWillWin(v);
//}