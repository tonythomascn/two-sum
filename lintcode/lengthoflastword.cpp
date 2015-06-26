/*
Length of Last Word

39% Accepted
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Have you met this question in a real interview? Yes
Example
Given s = "Hello World", return 5.

Note
A word is defined as a character sequence consists of non-space characters only.
*/
#include "stdafx.h"
#include <string>
using std::string;
/**
* @param s A string
* @return the length of last word
*/
int lengthOfLastWord(string& s) {
	int index = s.find_last_of(" ");
	if (std::string::npos == index)
		return s.length();
	else {
		return s.length() - index - 1;
	}
}