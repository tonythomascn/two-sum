/*
Matrix Zigzag Traversal

22% Accepted
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in ZigZag-order.

Have you met this question in a real interview? Yes
Example
Given a matrix:

[
[1, 2,  3,  4],
[5, 6,  7,  8],
[9,10, 11, 12]
]
return [1, 2, 5, 9, 6, 3, 4, 7, 10, 11, 8, 12]
*/
#include "stdafx.h"
#include <vector>
#include <algorithm>
using std::vector;
/**
* @param matrix: a matrix of integers
* @return: a vector of integers
*/
vector<int> printZMatrix(vector<vector<int> > &matrix) {
	vector<int> zigzag;
	const int m = matrix.size(), n = matrix[0].size();

	for (int i = 0; i < m + n - 1; i++) {
		if (0 == i % 2) {
			//on eventh lane, go from right to left
			for (int y = std::max(0, i - m + 1); y <= std::min(i, n - 1); y++)
				zigzag.emplace_back(matrix[i - y][y]);
		}
		else {
			//on oddth lane, go from left to right
			for (int x = std::max(0, i - n + 1); x <= std::min(i, m - 1); x++) 
				zigzag.emplace_back(matrix[x][i - x]);
		}
	}
	return zigzag;
}