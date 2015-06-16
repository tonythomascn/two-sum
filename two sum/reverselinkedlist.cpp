// Definition for singly-linked list.
#include <cstdlib>
#include <cstdio>
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public: 
	ListNode* reverseList(ListNode* head) {
		ListNode * curr = head;
		ListNode * next = NULL;
		ListNode * prev = NULL;

		while (curr) {
			next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			head = prev;
		}
		return head;
	}
	void push(struct ListNode *head, int val) {
		struct ListNode* node = (struct ListNode*)malloc(sizeof(struct ListNode));
		node->val = val;
		node->next = NULL;
		while (head->next) {
			head = head->next;
		}
		head->next = node;
		return;
	}
	void print(struct ListNode* head) {
		struct ListNode* p;
		for (p = head; p != NULL; p = p->next) {
			printf("%d->", p->val);
		}
		printf("null\n");
	}
};
int main() {
	Solution s;

	struct ListNode* list = new ListNode(0);
	s.push(list, 1);
	s.push(list, 2);
	s.print(s.reverseList(list));

	system("pause");
	return 0;
}