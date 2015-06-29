/*
Minimum Depth of Binary Tree

32% Accepted
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.

Have you met this question in a real interview? Yes
Example
Given a binary tree as follow:

1

/     \

2       3

/    \

4      5

The minimum depth is 2
*/
/**
* Definition of TreeNode:
*/
#include "stdafx.h"
#include <climits>
#include <algorithm>
class TreeNode {
public:
	int val;
	TreeNode *left, *right;
	TreeNode(int val) {
		this->val = val;
		this->left = this->right = NULL;
	}
};
class Solution {
public:
	/**
	* @param root: The root of binary tree.
	* @return: An integer
	*/
	int minDepth(TreeNode *root) {
		if (NULL == root)
			return 0;
		int left = 0;
		if (root->left)
			left = minDepth(root->left);

		int right = 0;
		if (root->right)
			right = minDepth(root->right);

		if (0 == left)
			left = INT_MAX;
		if (0 == right)
			right = INT_MAX;
		return std::min(left, right) + 1;
	}
};
