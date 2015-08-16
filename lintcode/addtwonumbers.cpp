/*
Add Two Numbers

24% Accepted
You have two numbers represented by a linked list, where each node contains a single digit. The digits are stored in reverse order, such that the 1's digit is at the head of the list. Write a function that adds the two numbers and returns the sum as a linked list.

Have you met this question in a real interview? Yes
Example
Given 7->1->6 + 5->9->2. That is, 617 + 295.

Return 2->1->9. That is 912.

Given 3->1->5 and 5->9->2, return 8->0->8.
*/

/*
* Definition for singly-linked list.
*/
#include "stdafx.h"
#include <cstdlib>
#include <cstdio>
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	/**
	* @param l1: the first list
	* @param l2: the second list
	* @return: the sum list of l1 and l2
	*/
	ListNode *addLists(ListNode *l1, ListNode *l2) {
		// write your code here
		long long n1 = getLength(l1);
		long long n2 = getLength(l2);
		//return the longer list if the short one is null
		if (0 == n1 || 0 == n2)
			return n1 >= n2 ? l2 : l1;

		long long longer = n1 >= n2 ? n1 : n2;
		ListNode * shorterlist = n1 >= n2 ? l2 : l1;
		ListNode * longerlist = n1 >= n2 ? l1 : l2;
		ListNode* l = new ListNode((shorterlist->val + longerlist->val) % 10);
		ListNode* cur = l;
		int extra = 10 <= shorterlist->val + longerlist->val ? 1 : 0;
		shorterlist = shorterlist->next;
		longerlist = longerlist->next;
		while (shorterlist) {
			cur->next = new ListNode((shorterlist->val + longerlist->val + extra) % 10);
			cur = cur->next;
			extra = 10 <= shorterlist->val + longerlist->val + extra ? 1 : 0;
			shorterlist = shorterlist->next;
			longerlist = longerlist->next;
		}

		if (n1 == n2) {
			if (extra) {
				cur->next = new ListNode(extra % 10);
				cur = cur->next;
			}
		}
		else {
			cur->next = new ListNode((longerlist->val + extra) % 10);
			cur = cur->next;
			longerlist = longerlist->next;
			while (longerlist) {
				cur->next = new ListNode((longerlist->val) % 10);
				cur = cur->next;
				longerlist = longerlist->next;
			}
		}
		return l;
	}

	long long getLength(ListNode *l) {
		long long result = 0;
		while (l) {
			l = l->next;
			result++;
		}
		return result;
	}

	void print(struct ListNode* head) {
		struct ListNode* p;
		for (p = head; p != NULL; p = p->next) {
			printf("%d->", p->val);
		}
		printf("null\n");
	}

	void destory(struct ListNode* l) {
		ListNode* tmp;
		while (l) {
			tmp = l;
			l = l->next;
			delete tmp;
		}
	}
};

class Solution2{
public:
  /**
  * @param l1: the first list
  * @param l2: the second list
  * @return: the sum list of l1 and l2
  */
  ListNode *addLists(ListNode *l1, ListNode *l2) {
    //use a dummy head to contain the result
    ListNode * dummy = new ListNode(0);
    ListNode * cur = dummy;
    int carry = 0;
    int val = 0;
    while (l1 || l2){
      //check l1 and l2 is NULL or not every time
      val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      carry = val / 10;
      cur->next = new ListNode(val % 10);
      if (l1)
        l1 = l1->next;
      if (l2)
        l2 = l2->next;
      cur = cur->next;
    }
    if (carry){
      cur->next = new ListNode(carry);
    }
    cur = dummy->next;
    delete dummy;
    return cur;
  }
};

//int main() {
//	Solution s;
//	ListNode* l1 = new ListNode(2);
//	ListNode* cur = l1;
//	cur->next = new ListNode(8);
//	cur = cur->next;
//	cur->next = new ListNode(2);
//	cur = cur->next;
//	cur->next = new ListNode(8);
//	cur = cur->next;
//	cur->next = new ListNode(2);
//	cur = cur->next;
//	cur->next = new ListNode(9);
//	cur = cur->next;
//	cur->next = new ListNode(6);
//	cur = cur->next;
//	cur->next = new ListNode(4);
//	cur = cur->next;
//	cur->next = new ListNode(5);
//	cur = cur->next;
//	cur->next = new ListNode(2);
//	cur = cur->next;
//	cur->next = new ListNode(5);
//	cur = cur->next;
//	cur->next = new ListNode(2);
//	cur = cur->next;
//	ListNode* l2 = new ListNode(5);
//	cur = l2;
//	cur->next = new ListNode(8);
//	cur = cur->next;
//	cur->next = new ListNode(9);
//	cur = cur->next;
//	cur->next = new ListNode(5);
//	cur = cur->next;
//	cur->next = new ListNode(6);
//	cur = cur->next;
//	cur->next = new ListNode(5);
//	cur = cur->next;
//	cur->next = new ListNode(1);
//	cur = cur->next;
//	cur->next = new ListNode(8);
//	cur = cur->next;
//	cur->next = new ListNode(7);
//	cur = cur->next;
//	cur->next = new ListNode(5);
//	cur = cur->next;
//	cur->next = new ListNode(5);
//	cur = cur->next;
//	ListNode* l3 = new ListNode(9);
//	cur = l3;
//	for (int i = 1; i < 45; i++) {
//		cur->next = new ListNode(9);
//		cur = cur->next;
//	}
//	ListNode* l4 = new ListNode(9);
//	cur = l4;
//	for (int i = 1; i < 45; i++) {
//		cur->next = new ListNode(9);
//		cur = cur->next;
//	}
//	s.print(s.addLists(l3, l4));
//	ListNode* l5 = new ListNode(3);
//	cur = l5;
//	cur->next = new ListNode(1);
//	cur = cur->next;
//	cur->next = new ListNode(5);
//	ListNode* l6 = new ListNode(5);
//	cur = l6;
//	cur->next = new ListNode(9);
//	cur = cur->next;
//	cur->next = new ListNode(2);
//	s.print(s.addLists(l5, l6));
//
//	s.destory(l1);
//	s.destory(l2);
//	s.destory(l3);
//	s.destory(l4);
//	s.destory(l5);
//	s.destory(l6);
//
//	system("pause");
//	return 0;
//}
