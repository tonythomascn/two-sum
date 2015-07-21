/*
Subtree

20% Accepted
You have two every large binary trees: T1, with millions of nodes, and T2, with hundreds of nodes. Create an algorithm to decide if T2 is a subtree of T1.

Have you met this question in a real interview? Yes
Example
T2 is a subtree of T1 in the following case:

1                3
/ \              /
T1 = 2   3      T2 =  4
/
4
T2 isn't a subtree of T1 in the following case:

1               3
/ \               \
T1 = 2   3       T2 =    4
/
4
Note
A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of n is identical to T2. That is, if you cut off the tree at node n, the two trees would be identical.
*/
#include "stdafx.h"

/**
* Definition of TreeNode:
*/
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
	* @param T1, T2: The roots of binary tree.
	* @return: True if T2 is a subtree of T1, or false.
	*/
	bool isSubtree(TreeNode *T1, TreeNode *T2) {
		//if only T2 is empty, then yes
		if (NULL == T2)
			return true;
		else if (NULL == T1)
			return false;
		else {  // T1 && T2
			return isIdentical(T1, T2) ||
				isSubtree(T1->left, T2) ||
				isSubtree(T1->right, T2);
		}
	}

	//Check two trees are identical 
	bool isIdentical(TreeNode *T1, TreeNode *T2) {
		//if both are empty, then yes
		if (NULL == T1 && NULL == T2)
			return true;

		//if only T1 is empty, then no
		if (T1 && T2)
		return T1->val == T2->val && 
			isIdentical(T1->left, T2->left) && isIdentical(T1->right, T2->right);
		return false;
	}
};