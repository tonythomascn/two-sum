/*
Minimum Path Sum

33% Accepted
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Have you met this question in a real interview? Yes
Example
Note
You can only move either down or right at any point in time.
*/

#include "stdafx.h"
#include <vector>
#include <algorithm>
using std::vector;
/**
* @param grid: a list of lists of integers.
* @return: An integer, minimizes the sum of all numbers along its path
*/
int minPathSum(vector<vector<int> > &grid){
	if (0 == grid.size())
		return 0;
	if (0 == grid[0].size())
		return 0;
	int m = grid.size();
	int n = grid[0].size();
	std::vector<int> v(n, INT_MAX);
	v[0] = 0;
	for (int i = 0; i < m; i++){
		v[0] = v[0] + grid[i][0];
		for (int j = 1; j < n; j++){
			v[j] = std::min(v[j], v[j - 1]) + grid[i][j];
		}
	}
	return v[n - 1];
}
