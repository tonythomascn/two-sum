/*
Convert Sorted List to Binary Search Tree

26% Accepted
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
* Definition of ListNode
*/ 
#include "stdafx.h"
#include <vector>
#include <stack>
using std::stack;
using std::vector;
class ListNode {
 public:
     int val;
     ListNode *next;
     ListNode(int val) {
         this->val = val;
         this->next = NULL;
     }

};
/* Definition of TreeNode:
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
	* @param head: The first node of linked list.
	* @return: a tree node
	*/
	TreeNode *sortedListToBST(ListNode *head) {
		// write your code here
		if (NULL == head)
			return NULL;
		return sortedListToBST(head, 0, countsortedList(head) - 1);
	}
	TreeNode *sortedListToBST(ListNode* &head, int start, int end) {
		if (start > end)
			return NULL;
		int mid = start + (end - start) / 2;
		TreeNode * left = sortedListToBST(head, start, mid - 1);
		TreeNode* root = new TreeNode(head->val);
		root->left = left;
		head = head->next;
		root->right = sortedListToBST(head, mid + 1, end);
		return root;
	}
	int countsortedList(ListNode * head) {
		int i = 0;
		while (head) {
			head = head->next;
			i++;
		}
		return i;
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
//	ListNode*head = new ListNode(1);
//	head->next = new ListNode(2);
//	head->next->next = new ListNode(3);
//	head->next->next->next = new ListNode(4);
//	head->next->next->next->next = new ListNode(5);
//	Solution s;
//	vector<int> r = s.inorderTraversal(s.sortedListToBST(head));
//
//}