/*
Two Strings Are Anagrams

29% Accepted
Write a method anagram(s,t) to decide if two strings are anagrams or not.

Have you met this question in a real interview? Yes
Example
Given s="abcd", t="dcab", return true.

Challenge
O(n) time, O(1) extra space
*/
#include "stdafx.h"
#include <string>
using std::string;
/**
 * @param s: The first string
 * @param b: The second string
 * @return true or false
 */
bool anagram(string s, string t) {
	if (s.length() != t.length())
		return false;
	int stat[256] = { 0 };

	for (int i = 0; i < s.length(); i++){
		stat[s[i]]++;
		stat[t[i]]--;
	}
	for (int i = 0; i < 256; i++){
		if (stat[i])
			return false;
	}
	return true;
}
