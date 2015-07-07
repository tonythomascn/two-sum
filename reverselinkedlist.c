
 //Definition for singly-linked list.
 struct ListNode {
   int val;
     struct ListNode *next;
 };

#include <stdlib.h>
#include <stdio.h>
struct ListNode* reverseList(struct ListNode* head) {
	struct ListNode *curr = head;
	struct ListNode *next = NULL;
	struct ListNode *prev = NULL;

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
	return ;
}
void print(struct ListNode* head) {
	struct ListNode* p;
	for (p = head; p != NULL; p = p->next) {
		printf("%d->", p->val);
	}
	printf("null\n");
}

//int main() {
//	struct ListNode* list = (struct ListNode*)malloc(sizeof(struct ListNode));
//	list->next = NULL;
//	list->val = 0;
// 	push(list, 1);
//	push(list, 2);
//	push(list, 3);
//	push(list, 4);
//	print(list);
//	print(reverseList(list));
//
//	struct ListNode* tmp;
//	while (list) {
//		tmp = list;
//		list = list->next;
//		free(tmp);
//	}
//	system("pause");
//	return 0;
//}