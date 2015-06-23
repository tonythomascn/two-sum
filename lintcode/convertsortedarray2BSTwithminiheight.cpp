/*
Convert Sorted Array to Binary Search Tree With Minimal Height

36% Accepted
Given a sorted (increasing order) array, Convert it to create a binary tree with minimal height.

Have you met this question in a real interview? Yes
Example
Given [1,2,3,4,5,6,7], return

4
/   \
2     6
/ \    / \
1   3  5   7
Note
There may exist multiple valid solutions, return any of them.
*/
/**
* Definition of TreeNode:
*/
#include "stdafx.h"
#include <vector>
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
public:
	/**
	* @param A: A sorted (increasing order) array
	* @return: A tree node
	*/
	TreeNode *sortedArrayToBST(vector<int> &A) {
		if (0 == A.size())
			return NULL;
		int root_val = A.size() / 2;
		TreeNode * root = new TreeNode(A[root_val]);
		vector<int> left(A.begin(), 
			0 != A.size() % 2 ? A.end() - root_val - 1: A.end() - root_val);
		vector<int> right(A.begin() + root_val + 1, A.end());
		root->left = sortedArrayToBST(left);
		root->right = sortedArrayToBST(right);
		return root;
	}

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
//	vector<int> v{ -1, 1 };
//	vector<int> v2{ 1,2,3,4,5,6,7 };
//	Solution s;
//	vector<int> r = s.inorderTraversal(s.sortedArrayToBST(v));
//	r = s.inorderTraversal(s.sortedArrayToBST(v2));
//
//}