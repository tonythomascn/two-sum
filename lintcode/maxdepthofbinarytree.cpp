/*
Maximum Depth of Binary Tree

57% Accepted
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Have you met this question in a real interview? Yes
Example
Given a binary tree as follow:

1
/ \
2   3
/ \
4   5
The maximum depth is 3.

Tags Expand
*/

/**
* Definition of TreeNode:
*/ 
#include "stdafx.h"

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
	int maxDepth(TreeNode *root) {
		if (NULL == root)
			return 0;

		int left = 0;
		int right = 0;
		if (root->left)
			left += maxDepth(root->left);
		if (root->right)
			right += maxDepth(root->right);

		return (left > right ? left : right) + 1;
	}
};