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
#include <queue>
#include <algorithm>
using std::queue;
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
		queue <std::pair< TreeNode*, int >> q;
		q.push(std::make_pair(root, 1));
		std::pair<TreeNode*, int> curr;
		while (!q.empty()) {
			curr = q.front();
			q.pop();
			if (!curr.first->left && !curr.first->right)
				return curr.second;
			if (curr.first->left)
				q.push(std::make_pair(curr.first->left, curr.second + 1));
			if (curr.first->right)
				q.push(std::make_pair(curr.first->right, curr.second + 1));
		}
	}
};
