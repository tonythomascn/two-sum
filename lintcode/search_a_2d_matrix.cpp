/*
Search a 2D Matrix

28% Accepted
Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Have you met this question in a real interview? Yes
Example
Consider the following matrix:

[
[1, 3, 5, 7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
Given target = 3, return true.

Challenge
O(log(n) + log(m)) time
*/
#include "stdafx.h"
#include <vector>
using std::vector;
/**
* @param matrix, a list of lists of integers
* @param target, an integer
* @return a boolean, indicate whether matrix contains target
* Time complexity O(m*n)
*/
bool searchMatrix1(vector<vector<int> > &matrix, int target) {
	int m = matrix.size();
	if (0 == m)
		return false;
	int n = matrix[0].size();
	if (0 == n)
		return false;
	for (int i = 0; i < m; i++) {
		if (target < matrix[i][n - 1]) {
			for (int j = 0; j < n; j++) {
				if (target == matrix[i][j])
					return true;
			}
		}
	}
	return false;
}
/*
Time complexity O(max(m,n))
*/
bool searchMatrix(vector<vector<int> > &matrix, int target) {
	int m = matrix.size();
	if (0 == m)
		return false;
	int n = matrix[0].size();
	if (0 == n)
		return false;
	int m_low = 0, n_low = 0;
	int m_high = m - 1, n_high = n - 1;
	int m_mid, n_mid;
	//find which row the targe may locate
	while (m_low < m_high) {
		m_mid = m_low + (m_high - m_low) / 2;
		if (target == matrix[m_mid][n - 1]) {
			return true;
		}
		else if (target < matrix[m_mid][n - 1]) {
			m_high = m_mid - 1;
		}
		else {
			m_low = m_mid + 1;
		}
	}
	//if target is larger than the largest element
	if (m_low >= m)
		return false;
	//search in the target row
	while (n_low < n_high) {
		n_mid = n_low + (n_high - n_low) / 2;
		if (target == matrix[m_low][n_mid]) {
			return true;
		}
		else if (target < matrix[m_low][n_mid]) {
			n_high = n_mid - 1;
		}
		else {
			n_low = n_mid + 1;
		}
	}
	return false;
}
/*
Treat the matrix as a 1D array, apply binary search on it.
Time complexity O(log(m*n)), which is O(logm + logn)
*/
bool searchMatrix2(vector<vector<int> > &matrix, int target) {
	int m = matrix.size();
	if (0 == m)
		return false;
	int n = matrix[0].size();
	if (0 == n)
		return false;
	int low = 0;
	int high = m * n - 1;
	int mid;
	while (low <= high){
		mid = low + (high - low) / 2;
		if (target == matrix[mid / n][mid % n]) {
			return true;
		}
		else if (target > matrix[mid / n][mid % n])
			low = mid + 1;
		else
			high = mid - 1;
	}
	return false;
}