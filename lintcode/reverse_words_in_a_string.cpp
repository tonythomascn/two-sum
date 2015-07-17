/*
Reverse Words in a String

23% Accepted
Given an input string, reverse the string word by word.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Have you met this question in a real interview? Yes
Example
Clarification
What constitutes a word?
A sequence of non-space characters constitutes a word.
Could the input string contain leading or trailing spaces?
Yes. However, your reversed string should not contain leading or trailing spaces.
How about multiple spaces between two words?
Reduce them to a single space in the reversed string.
*/
#include "stdafx.h"
#include <string>
using std::string;
/*
Reverse every word in the string,
reverse the whole string,
Get rid of the trailing spaces in the string.
Time complexity O(n), extra space O(1)
*/
class Solution {
public:
	void reverse(string &s, int start, int end) {
		unsigned char c;
		while (start < end) {
			c = s[start];
			s[start] = s[end];
			s[end] = c;
			start++;
			end--;
		}
	}
	/**
	* @param s : A string
	* @return : A string
	*/
	string reverseWords(string s) {
		if (s.empty())
			return s;
		int start = 0;
		for (int i = 0; i < s.size(); i++) {
			if (' ' == s[i]) {
				reverse(s, start, i - 1);
				start = i + 1;
			}
		}
		reverse(s, start, s.size() - 1);
		reverse(s, 0, s.size() - 1);
		int true_start = s.find_first_not_of(' ');
		if (std::string::npos != true_start)
			s = s.substr(true_start, s.size() - true_start + 1);
		return s;
	}

};