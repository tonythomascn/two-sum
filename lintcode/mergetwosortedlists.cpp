/*
Merge Two Sorted Lists

38% Accepted
Merge two sorted (ascending) linked lists and return it as a new sorted list. The new sorted list should be made by splicing together the nodes of the two lists and sorted in ascending order.

Have you met this question in a real interview? Yes
Example
Given 1->3->8->11->15->null, 2->null , return 1->2->3->8->11->15->null.
*/
#include "stdafx.h"
/**
* Definition of ListNode
*/
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
	* @param ListNode l1 is the head of the linked list
	* @param ListNode l2 is the head of the linked list
	* @return: ListNode head of linked list
	*/
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		ListNode * dummy = new ListNode(0);
		ListNode * tmp = dummy;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				tmp->next = l1;
				l1 = l1->next;
			}
			else {
				tmp->next = l2;
				l2 = l2->next;
			}
			tmp = tmp->next;
		}
		if (l1)
			tmp->next = l1;
		if (l2) 
			tmp->next = l2;
		tmp = dummy->next;
		delete dummy;
		return tmp;
	}
};