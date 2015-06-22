/*
Binary Tree Postorder Traversal

38% Accepted
Given a binary tree, return the postorder traversal of its nodes' values.

Have you met this question in a real interview? Yes
Example
Given binary tree {1,#,2,3},

1
\
2
/
3


return [3,2,1].

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
	* @return: Postorder in vector which contains node values.
	*/
public:
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> result;
		if (NULL == root)
			return result;
		stack<TreeNode*> stk;
		TreeNode* lastnode = NULL;
		//TreeNode* peeknode = NULL;
		while (1) {
			if (root) {
				stk.push(root);
				root = root->left;
			}
			else {
				root = stk.top();
				if (root->right != NULL && lastnode != root->right) {
					root = root->right;
				}
				else{
					lastnode = root;
					stk.pop();
					result.push_back(root->val);
					root = NULL;
					if (stk.empty()) break;
				}
			}
		}
		return result;
	}
};

//int main() {
//	TreeNode* root = new TreeNode(1);	
//	root->right = new TreeNode(2);
//	root->right->left = new TreeNode(3);
//	Solution s;
//	vector<int> result = s.postorderTraversal(root);
//	for each(int i in result)
//		std::cout << i << " ";
//	std::cout << std::endl;
//	system("pause");
//	return 0;
//}