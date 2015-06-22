/*
limbing Stairs

39% Accepted
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Have you met this question in a real interview? Yes
Example
n=1, 1=1
n=2, 1+1=2=2
Given an example n=3 , 1+1+1=2+1=1+2=3
1+1+1+1=2+1+1=1+2+1=1+1+2=2+2=4

return 3

Tags Expand
*/
#include "stdafx.h"
	/**
	* @param n: An integer
	* @return: An integer
	*/
	int climbStairs(int n) {
		if (1 >= n)
			return n;
		int last = 1, lastprev = 1;
		int now = 0;
		for (int i = 2; i <= n; i++) {
			now = last + lastprev;
			lastprev = last;
			last = now;
		}
		return now;
	}
