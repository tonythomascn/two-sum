/*
Nth to Last Node in List

43% Accepted
Find the nth to last element of a singly linked list.

The minimum number of nodes in list is n.

Have you met this question in a real interview? Yes
Example
Given a List  3->2->1->5->null and n = 2, return node  whose value is 1.
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
Get the length of singly linked list, then iterate to the nth node.
Time complexity O(n).
*/
class Solution {
public:
	/**
	* @param head: The first node of linked list.
	* @param n: An integer.
	* @return: Nth to last node of a singly linked list.
	*/
	ListNode *nthToLast(ListNode *head, int n) {
		ListNode * tmp = head;
		int count = 0;
		while (tmp) {
			count++;
			tmp = tmp->next;
		}
		if (count < n)
			return NULL;
		for (tmp = head; count > n; count--) {
			tmp = tmp->next;
		}
		return tmp;
	}
};
/*
Use two references, the first one iterates to the nth to the head.
Then the first iterates to the tail, along with the second one.
When the first reference reaches the tail, the second reference is at the nth node
to the last node in the list.
Time complexity O(n)
*/
class Solution2 {
public:
	/**
	* @param head: The first node of linked list.
	* @param n: An integer.
	* @return: Nth to last node of a singly linked list.
	*/
	ListNode *nthToLast(ListNode *head, int n) {
		ListNode * ref = head;
		ListNode * main = head;
		int count = 0;
		while (count < n) {
			if (NULL == ref)
				return NULL;
			count++;
			ref = ref->next;
		}
		while (ref) {
			ref = ref->next;
			main = main->next;
		}
		return main;
	}
};