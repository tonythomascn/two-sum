/*
Easy Binary Tree Inorder Traversal

39 % Accepted
Given a binary tree, return the inorder traversal of its nodes' values.

Have you met this question in a real interview ? Yes
Example
Given binary tree{ 1,#,2,3 },

1
\
2
/
3


return[1, 3, 2].

Challenge
Can you do it without recursion ?
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
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		if (NULL == root)
			return result;
		stack<TreeNode*> stk;
		while (1) {
			if (root) {
				stk.push(root);
				root = root->left;
			}
			else {
				if (!stk.empty()) {
					root = stk.top();
					stk.pop();
					result.push_back(root->val);
					root = root->right;
				}
				else
					break;
			}
		}
		return result;
	}
};

//int main() {
//	TreeNode* root = new TreeNode(1);
//	root->left = new TreeNode(2);
//	root->right = new TreeNode(3);
//	Solution s;
//	vector<int> result = s.inorderTraversal(root);
//	for each(int i in result)
//		std::cout << i << " ";
//	std::cout << std::endl;
//	system("pause");
//	return 0;
//}