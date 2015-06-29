/*
Majority Number III

24% Accepted
Given an array of integers and a number k, the majority number is the number that occurs more than 1/k of the size of the array.

Find it.

Have you met this question in a real interview? Yes
Example
Given [3,1,2,3,2,3,3,4,4,4] and k=3, return 3.

Note
There is only one majority number in the array.

Challenge
O(n) time and O(k) extra space
*/
#include "stdafx.h"
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

/**
* @param nums: A list of integers
* @param k: As described
* @return: The majority number
* only have to find the relative more frequent number in the list
*/
int majorityNumber(vector<int> nums, int k) {
	if (1 >= nums.size())
		return nums[0];
	unordered_map<int, int> map;
	for (int i = 0; i < nums.size(); i++) {	
		if (map.find(nums[i]) != map.end()) {
			map[nums[i]]++;
		}
		else if (map.size() < k) {
			map[nums[i]] = 1;
		}
		else {
			//once a number not in the map located, decrease all count in the map
			for (auto it = map.begin(); it != map.end();) {
				it->second--;
				if (0 == it->second)
					map.erase(it++);
				else
					it++;
			}
		}
	}
	int majority = 0;
	int count = 0;
	//select the most majority one
	for (auto it = map.begin(); it != map.end(); it++) {
		if (it->second > count) {
			majority = it->first;
			count = it->second;
		}
	}
	return majority;
}