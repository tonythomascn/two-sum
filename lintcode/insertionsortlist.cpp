/*
Insertion Sort List

32% Accepted
Sort a linked list using insertion sort.

Have you met this question in a real interview? Yes
Example
Given 1->3->2->0->null, return 0->1->2->3->null.
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
	* @param head: The first node of linked list.
	* @return: The head of linked list.
	*/
	ListNode *insertionSortList(ListNode *head) {
		ListNode* dummy = new ListNode(0);
		ListNode* node, *tmp;
		while (NULL != head) {
			node = dummy;
			while (NULL != node->next && node->next->val < head->val) {
				node = node->next;
			}
			tmp = head->next;
			head->next = node->next;
			node->next = head;
			head = tmp;
		}
		head = dummy->next;
		delete dummy;
		return head;
	}
};

//int main() {
//	ListNode* head = new ListNode(4);
//	head->next = new ListNode(2);
//	head->next->next = new ListNode(1);
//	head->next->next->next = new ListNode(3);
//	Solution s;
//	head = s.insertionSortList(head);
//}