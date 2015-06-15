/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

pure c in double linked list
*/
#include <stdio.h>
struct item_t{
int key;
int value;
struct item_t* prev;
struct item_t* next;
};
int size = 0;
int maxsize = 0;
struct item_t * head = NULL;
struct item_t * tail = NULL;

void lruCacheInit(int capacity) {
	maxsize = capacity;
}

void lruCacheFree() {
	struct item_t *tmp = head;
	struct item_t *del;
	while (tmp) {
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	head = NULL;
	tail = NULL;
	size = 0;
}

void lruTouch(struct item_t* node) {
	if (node == tail)
		return;

	if (node == head && node->next) {
		head = node->next;
		head->prev = NULL;
	}

	if (node->next) {
		if (node->prev)
			node->prev->next = node->next;
		else
			;
	}
	if (node->prev && node->next)
		node->next->prev = node->prev;
	
	if (tail) {
		tail->next = node;
		node->prev = tail;
	}
	tail = node;
	tail->next = NULL;

	if (!head)
		head = node;
}

void print() {
	struct item_t * tmp = head;
	while (tmp) {
		printf("<%d, %d> ", tmp->key, tmp->value);
		tmp = tmp->next;
	}
	printf("\n");
}

int lruCacheGet(int key) {
	struct item_t * tmp = tail;
	while (tmp) {
		if (key == tmp->key) {
			lruTouch(tmp);
			return tmp->value;
		}
		tmp = tmp->prev;
	}
	return -1;
}

void lruCacheSet(int key, int value) {
	struct item_t * tmp = tail;
	int found = 0;
	while (tmp) {
		if (tmp->key == key) {
			found = 1;
			break;
		}
		tmp = tmp->prev;
	}

	if (!found) {
		if (size == maxsize) {
			tmp = head;
			if (head->next) {
				head->next->prev = NULL;
				head = head->next;
			}
		}
		else {
			tmp = (struct item_t*)malloc(sizeof(struct item_t));
			if (!tmp)
				return;
			size++;
		}
		tmp->next = NULL;
		tmp->prev = NULL;
		tmp->key = key;
		tmp->value = value;
	}
	else {
		tmp->value = value;
	}
	lruTouch(tmp);
}


int main() {
	lruCacheInit(3);
	lruCacheSet(2, 1);
	print();
	lruCacheSet(2, 2);
	print();
	printf("%d\n", lruCacheGet(2));
	lruCacheSet(1, 1);
	print();
	lruCacheSet(4, 1);
	print();
	printf("%d\n", lruCacheGet(2));
	lruCacheSet(3, 1);
	print();
	printf("%d\n", lruCacheGet(2));
	lruCacheSet(4, 1);
	print();
	printf("%d\n", lruCacheGet(2));
	lruCacheFree();
	system("pause");
	return 0;
}