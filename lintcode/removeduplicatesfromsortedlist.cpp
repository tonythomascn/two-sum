/*
Remove Duplicates from Sorted List

39% Accepted
Given a sorted linked list, delete all duplicates such that each element appear only once.

Have you met this question in a real interview? Yes
Example
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
	* @param head: The first node of linked list.
	* @return: head node
	*/
	ListNode *deleteDuplicates(ListNode *head) {
		ListNode* next = NULL;
		ListNode* curr = head;
		ListNode* tmp;
		while (curr) {
			next = curr->next;
			if (next && curr->val == next->val) {
				tmp = next;
				curr->next = next->next;
				delete tmp;
			}
			else
				curr = curr->next;
		}
		return head;
	}
};