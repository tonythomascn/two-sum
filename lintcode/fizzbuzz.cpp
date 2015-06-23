/*
Fizz Buzz

80% Accepted
Given number n. Print number from 1 to n. But:

when number is divided by 3, print "fizz".
when number is divided by 5, print "buzz".
when number is divided by both 3 and 5, print "fizz buzz".
Have you met this question in a real interview? Yes
Example
If n = 15, you should return:

["1", "2", "fizz", "4", "buzz", "fizz", "7", "8", "fizz", "buzz", "11", "fizz", "13", "14", "fizz buzz"]
*/
#include "stdafx.h"
#include <vector>
#include <string>

using std::string;
using std::vector;
/**
* param n: As description.
* return: A list of strings.
*/
vector<string> fizzBuzz(int n) {
	vector<string> results;
	for (int i = 1; i <= n; i++) {
		if (i % 15 == 0) {
			results.push_back("fizz buzz");
		}
		else if (i % 5 == 0) {
			results.push_back("buzz");
		}
		else if (i % 3 == 0) {
			results.push_back("fizz");
		}
		else {
			results.push_back(std::to_string(i));
		}
	}
	return results;
}