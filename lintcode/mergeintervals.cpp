/*
Merge Intervals

19 % Accepted
Given a collection of intervals, merge all overlapping intervals.

Have you met this question in a real interview ? Yes
Example
Given intervals = > merged intervals :

[[
	[1, 3], [1, 6],
		[2, 6], =>[8, 10],
		[8, 10], [15, 18]
		[15, 18]]
]
Challenge
O(n log n) time and O(1) extra space.
*/
#include "stdafx.h"
#include <vector>
#include <algorithm>
using std::vector;
/**
* Definition of Interval:
*/
class Interval {
public:
	int start, end;
	 Interval(int start, int end) {
		 this->start = start;
		 this->end = end;
	 }
};
/*
fetch every interval and insert into a new vector
Time complexity O(n), extra space O(n)
*/
class Solution1 {
public:
	/**
	* @param intervals: interval list.
	* @return: A new interval list.
	*/
	vector<Interval> merge(vector<Interval> &intervals) {
		vector<Interval> res;
		for (Interval i : intervals) {
			insert(res, i);
		}
		return res;
	}
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
/*
Sort the vector first using a user-define sort function, O(nlogn)
Merge the sorted vector, O(n)
Time complexity O(nlogn), extra space O(1)
*/
class Solution2 {
public:
	/**
	* @param intervals: interval list.
	* @return: A new interval list.
	*/
	vector<Interval> merge(vector<Interval> &intervals) {
		if (intervals.empty())
			return intervals;
		//O(nlogn)
		std::sort(intervals.begin(), intervals.end(), compareInterval);

		//O(n)
		vector<Interval>::iterator it1 = intervals.begin(), it2 = it1 + 1;
		while (it1 != intervals.end() && it2 != intervals.end()) {
			if (it2->start <= it1->end) {
				if (it1->end < it2->end)
					it1->end = it2->end;
				it2++;
			}
			else {
				it1 = intervals.erase(it1 + 1, it2);
				it2 = it1 + 1;
			}
		}
		if (it1 != intervals.end())
			intervals.erase(it1 + 1, it2);
		return intervals;
	}
	
	static bool compareInterval(Interval i1, Interval i2) {
		return i1.start < i2.start;
	}
};