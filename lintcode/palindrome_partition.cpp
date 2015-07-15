/*
Palindrome Partitioning
22%
Accepted


Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

Have you met this question in a real interview?
Example

given s = "aab",
Return

[
["aa","b"],
["a","a","b"]
]

*/
#include "stdafx.h"
#include <vector>
#include <string>
using std::string;
using std::vector;
/*
Test string is Palindrome or not
*/
bool isPalindrome(string s, int start, int end){
	while (start < end){
		if (s[start] != s[end])
			return false;
		start++;
		end--;	
	}
	return true;
}
/*
When face the "return all", "get all ", "find all possible", "find the total number of", an idea is to use the recursion. 
We use DFS to search all the possibilities.
*/
void DFS(string s, int start, vector<string>& output, vector<vector<string>>& res){
	if (start == s.size()){
		res.push_back(output);
		return;
	}
		for (int i = start; i < s.size(); i++){
			if (isPalindrome(s, start, i)){
				output.push_back(s.substr(start, i - start + 1));
				DFS(s, i + 1, output, res);
				output.pop_back();
			}
		}
}
/**
* @param s: A string
* @return: A list of lists of string
*/
vector<vector<string>> partition(string s) {
	vector<vector<string>> res;
	vector<string> output;
	DFS(s, 0, output, res);
	return res;
}