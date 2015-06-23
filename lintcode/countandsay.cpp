/*
Count and Say

27% Accepted
The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.

11 is read off as "two 1s" or 21.

21 is read off as "one 2, then one 1" or 1211.

Given an integer n, generate the nth sequence.

Have you met this question in a real interview? Yes
Example
Given n = 5, return "111221".

Note
The sequence of integers will be represented as a string.
*/

#include "stdafx.h"
#include <string>
using std::string;

/**
* @param n the nth
* @return the nth sequence
*/
string countAndSay(int n) {
	string original = "1";
	int count = 0;
	string result = "1";
	for (int i = 1; i < n; i++) {
		count = 0;
		result = "";
		for (int j = 0; j < original.length(); j++) {
			count++;
			if (j == original.length() || original[j] != original[j + 1]) {			
				result += std::to_string(count) + original[j];
				count = 0;
			}
		}
		original = result;
	}
	return result;
}
//int main() {
//	printf("%s", countAndSay(5));
//}