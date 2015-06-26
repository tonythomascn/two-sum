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
		// write your code here
		if (NULL == head || NULL == head->next)
			return head;

		ListNode* curr = head;
		ListNode* tmp;
		while (curr->next) {
			if (curr->val > curr->next->val) {
				tmp = curr->next;
				curr->next = curr->next->next;
				tmp->next = NULL;
				head = insertList(head, tmp);
				curr = head;
				continue;
			}
			curr = curr->next;
		}
		return head;
	}
	ListNode*insertList(ListNode* head, ListNode*node) {
		if (NULL == head) {
			return node;
		}
		ListNode*curr = head;
		while (curr) {
			if (curr->val <= node->val){				
				if (NULL != curr->next){
					if (curr->next->val > node->val) {
						node->next = curr->next;
						curr->next = node;
						break;
					}
				}
				else {
					curr->next = node;
					break;
				}
			}else {
				int tmp = curr->val;
				curr->val = node->val;
				node->val = tmp;
				node->next = curr->next;
				curr->next = node;
				break;
			}
			curr = curr->next;
		}
		return head;
	}
};

int main() {
	ListNode* head = new ListNode(4);
	head->next = new ListNode(2);
	head->next->next = new ListNode(1);
	head->next->next->next = new ListNode(3);
	Solution s;
	head = s.insertionSortList(head);
}