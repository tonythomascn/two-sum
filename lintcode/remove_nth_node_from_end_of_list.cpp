/*
Remove Nth Node From End of List

30% Accepted
Given a linked list, remove the nth node from the end of list and return its head.

Have you met this question in a real interview? Yes
Example
Given linked list: 1->2->3->4->5->null, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5->null.
Note
The minimum number of nodes in list is n.

Challenge
O(n) time
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

/*
Use two pointer to find nth node from end of the list.
If the nth node happens to be the head, the new head has to be returned.
*/
class Solution {
public:
	/**
	* @param head: The first node of linked list.
	* @param n: An integer.
	* @return: The head of linked list.
	*/
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		if (!head)
			return head;
		ListNode * pointer = head;
		ListNode * del = head;
		for (int count = 1; count <= n; count++) {
			if (NULL == pointer)
				return head;
			pointer = pointer->next;
		}
		if (NULL == pointer) {
			del = head;
			head = head->next;
			delete del;
		}
		else {
			while (pointer->next) {
				pointer = pointer->next;
				del = del->next;
			}

			pointer = del->next;
			del->next = del->next->next;
			delete pointer;
		}
		return head;
	}
};

/*
Use two pointer to find the nth node from end of the list.
use a dummy head to deal the nth node happens to be the head situation.
*/
class Solution2 {
public:
	/**
	* @param head: The first node of linked list.
	* @param n: An integer.
	* @return: The head of linked list.
	*/
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode * dummy = new ListNode(0);
		dummy->next = head;
		for (int i = 0; i < n; i++) {
			if (NULL == head) {
				delete dummy;
				return NULL;
			}
			head = head->next;
		}
		ListNode*slow = dummy;
		while (head) {
			head = head->next;
			slow = slow->next;
		}
		head = slow->next;
		slow->next = slow->next->next;
		delete head;
		head = dummy->next;
		delete dummy;
		return head;
	}
};