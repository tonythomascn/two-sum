/*Partition List
30%
Accepted

Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2->null and x = 3,
return 1->2->2->4->3->5->null.
*/
#include "stdafx.h"
#include <algorithm>
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
	* @param x: an integer
	* @return: a ListNode
	*/
	ListNode *partition(ListNode *head, int x) {
		ListNode * dummy = new ListNode(INT_MIN);
		dummy->next = head;
		ListNode * curr = dummy;
		ListNode *start = NULL, *prev;
		while (curr){
			//find the very first node that is greater than x
			if (NULL == start && x <= curr->val)
				start = prev;
			else if (start && x > curr->val) {
				//when a node less than x found, concate it behind start
				prev->next = curr->next;
				curr->next = start->next;
				start->next = curr;
				start = start->next;
				curr = prev;
			}
			prev = curr;
			curr = curr->next;
		}
		head = dummy->next;
		delete dummy;
		return head;
	}
};
