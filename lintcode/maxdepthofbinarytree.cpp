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
#include <stack>
using std::stack;
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
		if (!root) return 0;
		stack<TreeNode*> visit;
		stack<int> depth;
		visit.push(root);
		depth.push(1);
		int maxdepth = 1;
		TreeNode* curr;
		int currdepth;
		while (!visit.empty()) {
			curr = visit.top();
			visit.pop();
			currdepth = depth.top();
			depth.pop();
			if (currdepth > maxdepth)
				maxdepth = currdepth;
			if (curr->left) {
				visit.push(curr->left);
				depth.push(currdepth + 1);
			}
			if (curr->right) {
				visit.push(curr->right);
				depth.push(currdepth + 1);
			}
		}
		return maxdepth;
	}
};