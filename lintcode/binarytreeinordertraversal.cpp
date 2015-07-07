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

class Solution1 {
public:
	/**
	* @param root: The root of binary tree.
	* @return: Inorder in vector which contains node values.
	* inorder traversal without recursion
	* Time complexitiy O(n)
	* Space complexity O(n)
	*/
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
class Solution2 {
public:
	/**
	* @param root: The root of binary tree.
	* @return: Inorder in vector which contains node values.
	* inorder traversal recursively.
	* Time complexity O(n)
	* Space complexity O(n)
	*/
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		if (NULL == root)
			return result;
		vector<int> left = inorderTraversal(root->left);
		vector<int> right = inorderTraversal(root->right);
		result.insert(result.end(), left.begin(), left.end());
		result.push_back(root->val);
		result.insert(result.end(), right.begin(), right.end());
		return result;
	}
};
class Solution3 {
public:
	/**
	* @param root: The root of binary tree.
	* @return: Inorder in vector which contains node values.
	* inorder traversal using Morris Traversal:
	* Morris Traversal uses the tree as a threaded binary tree, 
	* using the predecessor and successor to navigate.
	* Time complexity O(n)
	* Space complexity O(1)
	*/
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		if (NULL == root)
			return result;
		TreeNode *curr = root;
		TreeNode *prev = NULL;
		while (curr) {
			if (NULL == curr->left) {
				result.push_back(curr->val);
				curr = curr->right;
			}
			else {
				//find predecessor
				prev = curr->left;
				while (prev->right != NULL && prev->right != curr)
					prev = prev->right;
				if (NULL == prev->right) {
					/* Make current as right child of its inorder predecessor */
					prev->right = curr;
					curr = curr->left;
				}
				else {
					/* Revert the changes made in if part to restore the original
					tree i.e., fix the right child of predecssor */
					prev->right = NULL;
					result.push_back(curr->val);
					curr = curr->right;
				}
			}
		}
		return result;
	}
};

//int main() {
//	TreeNode root(1);
//	root.left = &TreeNode(2);
//	root.right = &TreeNode(3);
//	Solution3 s;
//	vector<int> result = s.inorderTraversal(&root);
//	for each(int i in result)
//		std::cout << i << " ";
//	std::cout << std::endl;
//	system("pause");
//	return 0;
//}