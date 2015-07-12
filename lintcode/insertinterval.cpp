/*
Insert Interval

22% Accepted
Given a non-overlapping interval list which is sorted by start point.

Insert a new interval into it, make sure the list is still in order and non-overlapping (merge intervals if necessary).

Have you met this question in a real interview? Yes
Example
Insert [2, 5] into [[1,2], [5,9]], we get [[1,9]].

Insert [3, 4] into [[1,2], [5,9]], we get [[1,2], [3,4], [5,9]].
*/

/**
* Definition of Interval:
*/
#include "stdafx.h"
#include <vector>
#include <algorithm>
using std::vector;
class Interval {
public:
	int start, end;
	Interval(int start, int end) {
		this->start = start;
		this->end = end;
	}
};
class Solution {
public:
	/**
	* Insert newInterval into intervals.
	* @param intervals: Sorted interval list.
	* @param newInterval: new interval.
	* @return: A new interval list.
	*/
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval>::iterator it = intervals.begin();
		while (it != intervals.end()) {
			if (newInterval.end < it->start) {
				//insert at the beginning
				intervals.insert(it, newInterval);
				return intervals;
			}
			else if (newInterval.start > it->end) {
				//seek util find approriate position
				it++;
			}
			else {
				//exchange with current element and try to make the new interval
				//the largest one and then insert to the end
				newInterval.start = std::min(newInterval.start, it->start);
				newInterval.end = std::max(newInterval.end, it->end);
				it = intervals.erase(it);
			}
		}
		intervals.insert(intervals.end(), newInterval);
		return intervals;
	}
};

//int main() {
//	vector<Interval> v{Interval(1, 5)};
//	//v.push_back(Interval(1, 2));
//	//v.push_back(Interval(5, 9));
//
//	Solution s;
//	v = s.insert(v, Interval(2, 3));
//}