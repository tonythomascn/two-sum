/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

pure c in doubly linked list
*/
#include <stdio.h>
#define HASH 10000
struct Node{
int key;
int value;
struct Node* prev;
struct Node* next;
};
struct List {
	int count;
	struct Node*first;
	struct Node*last;
};
struct Node* array[HASH];
int maxsize = 0;
struct List *cachelist = NULL;

void lruCacheInit(int capacity) {
	maxsize = capacity;
	memset(&array, 0, HASH);
	cachelist = calloc(1, sizeof(struct List));
	cachelist->count = 0;
	cachelist->first = NULL;
	cachelist->last = NULL;
}

void lruCacheFree() {
	struct Node *cur;
	for (cur = cachelist->first; cur != NULL; cur = cur->next) {
		if (cur->prev)
			free(cur->prev);
	}
}

void lruPushBack(struct List*cachelist, struct Node* node) {
	if (cachelist->last == NULL) {
		cachelist->first = node;
		cachelist->last = node;
	}
	else {
		cachelist->last->next = node;
		node->prev = cachelist->last;
		cachelist->last = node;
	}
	return;
}


void lruTouch(struct List* cachelist, struct Node* node) {
	if (node == cachelist->last)
		return;

	if (node == cachelist->first && node->next) {
		cachelist->first = node->next;
		cachelist->first->prev = NULL;
	}

	if (node->next) {
		if (node->prev)
			node->prev->next = node->next;
	}
	if (node->prev) {
		if (node->next)
			node->next->prev = node->prev;
	}

	if (cachelist->last) {
		cachelist->last->next = node;
		node->prev = cachelist->last;
	}
	cachelist->last = node;
	cachelist->last->next = NULL;

	if (!cachelist->first)
		cachelist->first = node;
}



int lruCacheGet(int key) {
	if (array[key]) {
		lruTouch(cachelist, array[key]);
		//array[key] = tail;
		return array[key]->value;
	}
	return -1;
}

void lruCacheSet(int key, int value) {
	struct Node * tmp;
	if (!array[key]){
		if (cachelist->count == maxsize) {
			tmp = cachelist->first;
			array[cachelist->first->key] = NULL;
			if (cachelist->first->next) {
				cachelist->first->next->prev = NULL;
				cachelist->first = cachelist->first->next;
			}
		}
		else {
			tmp = (struct Node*)malloc(sizeof(struct Node));
			if (!tmp)
				return;
			cachelist->count++;
		}
		tmp->next = NULL;
		tmp->prev = NULL;
		tmp->key = key;
		tmp->value = value;
	}
	else {
		tmp = array[key];
		tmp->value = value;	
	}
	lruTouch(cachelist, tmp);
	array[key] = cachelist->last;
}

//void print() {
//	struct Node * tmp = cachelist->first;
//	while (tmp) {
//		printf("<%d, %d> ", tmp->key, tmp->value);
//		tmp = tmp->next;
//	}
//	printf("\n");
//}
//int main() {
//	lruCacheInit(4);
//	printf("-<2, %d>-\n", lruCacheGet(2));
//	lruCacheSet(2, 1);
//	print();
//	lruCacheSet(2, 2);
//	print();
//	printf("-<2, %d>-\n", lruCacheGet(2));
//	print();
//	lruCacheSet(1, 1);
//	print();
//	lruCacheSet(4, 1);
//	print();
//	printf("-<10, %d>-\n", lruCacheGet(10));
//	print();
//	lruCacheSet(3, 1);
//	print();
//	printf("-<4, %d>-\n", lruCacheGet(4));
//	print();
//	lruCacheSet(4, 1);
//	print();
//	printf("-<4, %d>-\n", lruCacheGet(4));
//	print();
//	lruCacheSet(5, 1);
//	print();
//	printf("-<5, %d>-\n", lruCacheGet(5));
//	print();
//	lruCacheSet(2, 1);
//	print();
//	printf("-<2, %d>-\n", lruCacheGet(2));
//	print();
//	lruCacheFree();
//	system("pause");
//	return 0;
//}