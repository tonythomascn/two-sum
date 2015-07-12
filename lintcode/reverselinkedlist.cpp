/*
Reverse Linked List

41% Accepted
Reverse a linked list.

Have you met this question in a real interview? Yes
Example
For linked list 1->2->3, the reversed linked list is 3->2->1

Challenge
Reverse it in-place and in one-pass
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
/*
Iteratively
*/
class Solution {
public:
	/**
	* @param head: The first node of linked list.
	* @return: The new head of reversed linked list.
	*/
	ListNode *reverse(ListNode *head) {
		ListNode * curr = head;
		ListNode * next;
		ListNode * prev = NULL;
		while (curr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
		}
		head = prev;
		return head;
	}
};

/*
Recursion
*/
class Solution2 {
public:
	/**
	* @param head: The first node of linked list.
	* @return: The new head of reversed linked list.
	*/
	ListNode *reverse(ListNode *head) {
		if (NULL == head) return head;
		if (NULL == head->next) return head;
		ListNode * nextItem = head->next;
		head->next = NULL;
		ListNode* reverseRest = reverse(nextItem);
		nextItem->next = head;
		return reverseRest;
	}
};