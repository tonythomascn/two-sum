/*
Valid Parentheses

28% Accepted
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

Have you met this question in a real interview? Yes
Example
The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/
#include "stdafx.h"
#include <string>
#include <stack>
using std::stack;
using std::string;

/**
* @param s A string
* @return whether the string is a valid parentheses
*/
bool isValidParentheses(string& s) {
	if (s.empty())
		return true;
	stack<char> queue;
	for (int i = 1; i < s.size(); i++) {
		if (queue.empty())
			queue.push(s[i]);
		else if ('(' == queue.top() &&  ')' == s[i])
			queue.pop();
		else if ('[' == queue.top() && ']' == s[i])
			queue.pop();
		else if ('{' == queue.top() && '}' == s[i])
			queue.pop();
		else
			queue.push(s[i]);
	}
	if (queue.empty())
		return true;
	else
		return false;
}