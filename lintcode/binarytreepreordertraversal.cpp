/*
Binary Tree Preorder Traversal

41% Accepted
Given a binary tree, return the preorder traversal of its nodes' values.

Have you met this question in a real interview? Yes
Example
Given binary tree {1,#,2,3}:

1
\
2
/
3
return [1,2,3].

Challenge
Can you do it without recursion?
*/

/**
* Definition of TreeNode:
*/
#include "stdafx.h"
#include <cstdlib>
#include <vector>
#include <iostream>
#include <stack>
using std::vector;
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
	/**
	* @param root: The root of binary tree.
	* @return: Inorder in vector which contains node values.
	*/
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		if (NULL == root)
			return result;
		stack<TreeNode*> stk;
		stk.push(root);
		while (1) {
			if (!stk.empty()) {
				root = stk.top();
				stk.pop();
			}
			else
				break;
			result.push_back(root->val);
			if (root->right)
				stk.push(root->right);
			if (root->left)
				stk.push(root->left);
		}
		return result;
	}
};

int main() {
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	Solution s;
	vector<int> result = s.preorderTraversal(root);
	for each(int i in result)
		std::cout << i << " ";
	std::cout << std::endl;
	system("pause");
	return 0;
}