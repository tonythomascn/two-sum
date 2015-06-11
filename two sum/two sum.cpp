// two sum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <unordered_map>
using std::vector;
using std::unordered_map;

vector<int> twoSum(vector<int>& nums, int target);
int * twoSum(int* nums, int numsSize, int target);

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> nums{ 0,2,4,6,8,10,12,14,16,18,20,22,24 };
	vector<int> index = twoSum(nums, 6);
	for each (int i in index)
		printf(" %d", i);
	system("pause");
	return 0;
}
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> indexs(2);
	unordered_map<int, int> mp;
	for (int i = 0; i < nums.size(); i++){
			if (mp.find(target - nums[i]) != mp.end()) {
				indexs[0] = mp[target - nums[i]] + 1;
				indexs[1] = i + 1;
				return indexs;
			}
			mp[nums[i]] = i;
	}
	return indexs;
}
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> indexs(2);
	for (int i = 0; i < nums.size(); i++) {
		for (int j = i - 1; j >= 0; j--)
		if (target - nums[i] == nums[j]) {
			indexs[0] = j + 1;
			indexs[1] = i + 1;
			return indexs;
		}
	}
	return indexs;
}
int * twoSum(int* nums, int numsSize, int target)
{
	int *index = (int*)malloc(sizeof(int)*2);
	index[0] = 0;
	index[1] = 0;
	int i, j;
	for (i = numsSize - 1; i >= 0; i--) {
		if (nums[i] <= target || target < 0) {
			for (j = 0; j < numsSize; j++) {
				if (i != j) {
					if (target - nums[i] == nums[j]) {
						index[0] = i > j ? j + 1 : i + 1;
						index[1] = j > i ? j + 1 : i + 1;
						return index;
					}
				}
			}
		}
	}
	return index;
}