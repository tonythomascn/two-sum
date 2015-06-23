/*
Delete Node in the Middle of Singly Linked List

31% Accepted
Implement an algorithm to delete a node in the middle of a singly linked list, given only access to that node.

Have you met this question in a real interview? Yes
Example
Given 1->2->3->4, and node 3. return 1->2->4
*/
/**
* Definition of ListNode
*/
#include "stdafx.h"
class ListNode {
 public:
     int val;
     ListNode *next;
     ListNode(int val) {
         this->val = val;
         this->next = NULL;
     }
};

class Solution {
public:
	/**
	* @param node: a node in the list should be deleted
	* @return: nothing
	*/
	void deleteNode(ListNode *node) {
		if (NULL == node)
			return;
		if (NULL == node->next) {
			node->val = 0;
			return;
		}
		node->val = node->next->val;
		ListNode* tmp = node->next;
		node->next = node->next->next;
		delete tmp;
	}
};
int main() {
	ListNode*node = new ListNode(1);
	node->next = new ListNode(2);
	node->next->next = new ListNode(3);
	node->next->next->next = new ListNode(4);
	Solution s;
	s.deleteNode(node);
}
