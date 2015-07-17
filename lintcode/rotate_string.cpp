/*
Rotate String

22% Accepted
Given a string and an offset, rotate string by offset. (rotate from left to right)

Have you met this question in a real interview? Yes
Example
Given "abcdefg".

offset=0 => "abcdefg"
offset=1 => "gabcdef"
offset=2 => "fgabcde"
offset=3 => "efgabcd"
Challenge
Rotate in-place with O(1) extra memory.
*/
#include "stdafx.h"
#include <string>
using std::string;
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
* param A: A string
* param offset: Rotate string with offset.
* return: Rotated string.
*/
string rotateString(string A, int offset) {
	if (A.empty())
		return A;
	offset = offset % A.size();
	reverse(A, 0, A.size() - offset - 1);
	reverse(A, A.size() - offset, A.size() - 1);
	reverse(A, 0, A.size() - 1);
	return A;
}
/*
After get the final offset, just split the string into two parts and return the final one.
*/
string rotateString2(string A, int offset) {
	if (A.empty())
		return A;
	offset %= A.size();
	return A.substr(A.size() - offset, offset) + A.substr(0, A.size() - offset);
}