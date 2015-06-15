/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.*/

#include <list>
#include <unordered_map>
#include <iostream>
using std::list;
using std::unordered_map;

class LRUCache {
public:
	LRUCache(int capacity) : capacity(capacity) {
	}

	int get(int key) {
		if (LRUMap.end() != LRUMap.find(key))
		{
			LRUList.splice(LRUList.begin(), LRUList, LRUMap[key]);
			return LRUMap[key]->second;
		}
		else
			return -1;
	}

	void set(int key, int value) {
		//find
		if (LRUMap.end() == LRUMap.find(key)) {
			//nope
			//check capacity
			if (LRUList.size() == capacity) {
				//pop front and push back
				LRUMap.erase(LRUList.back().first);
				LRUList.pop_back();
			}
			LRUList.push_front(std::make_pair(key, value));
			LRUMap[key] = LRUList.begin();
		}
		else {
			//Found it
			LRUMap[key]->second = value;
			LRUList.splice(LRUList.begin(), LRUList, LRUMap[key]);
		}
	}

	void print() {
		for each(std::pair<int, int> p in LRUList) {
			std::cout << "<" << p.first << ", " << p.second << "> ";
		}
		std::cout << std::endl;
	}

private:
	int capacity;
	list<std::pair<int, int>> LRUList;
	unordered_map<int, list<std::pair<int, int>>::iterator> LRUMap;
};
int main() {
	LRUCache c(2);
	c.set(2, 1);
	c.print();
	c.set(2, 2);
	c.print();
	std::cout << c.get(2) << std::endl;
	c.set(1, 1);
	c.print();
	c.set(4, 1);
	c.print();
	std::cout << c.get(2) << std::endl;
	system("pause");
	return 0;
}