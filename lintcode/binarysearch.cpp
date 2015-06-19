
/*
Easy Binary Search

28% Accepted
For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.

If the target number does not exist in the array, return -1.

Have you met this question in a real interview? Yes
Example
If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.

Challenge
If the count of numbers is bigger than 2^32, can your code work properly?
*/
#include "stdafx.h"
#include <vector>
#include <iostream>
using std::vector;

class Solution {
public:
	/**
	* @param nums: The integer array.
	* @param target: Target number to find.
	* @return: The first position of target. Position starts from 0.
	*/
	int binarySearch(vector<int> &array, int target) {
		int imax = array.size();
		int imin = 0;
		int imid = imin + (imax - imin) / 2;
		while(1) {
			if (array[imid] < target) {
				imin = imid + 1;
			}
			else if (array[imid] > target) {
				imax = imid - 1;
			}
			else {
				for (int j = imid; j >= 0; j--) {
					if (j == 0)
						return 0;
					if (array[j] != target)
						return j + 1;
				}
			}
			imid = imin + (imax - imin) / 2;
			if (imax == imin) {
				if (array[imid] != target)
					break;
			}
		}
		return -1;
	}
};

//int main() {
//	vector<int> array{4, 5, 9, 9, 12, 13, 14, 15, 15, 18};
//	Solution s;
//	std::cout << s.binarySearch(array, 10) << std::endl;
//	system("pause");
//	return 0;
//}