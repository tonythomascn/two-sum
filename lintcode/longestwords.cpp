/*
Longest Words

39% Accepted
Given a dictionary, find all of the longest words in the dictionary.

Have you met this question in a real interview? Yes
Example
Given

{
"dog",
"google",
"facebook",
"internationalization",
"blabla"
}
the longest words are(is) ["internationalization"].

Given

{
"like",
"love",
"hate",
"yes"
}
the longest words are ["like", "love", "hate"].

Challenge
It's easy to solve it in two passes, can you do it in one pass?
*/
#include "stdafx.h"
#include <string>
#include <vector>
using std::string;
using std::vector;
/**
* @param dictionary: a vector of strings
* @return: a vector of strings
*/
vector<string> longestWords(vector<string> &dictionary) {
	vector<string> result;
	if (1 >= dictionary.size())
		return dictionary;
	result.push_back(dictionary[0]);
	for (int i = 1; i < dictionary.size(); i++) {
		if (result[0].length() == dictionary[i].length()) {
			result.push_back(dictionary[i]);
		}
		else if (result[0].length() < dictionary[i].length()){
			result.clear();
			result.push_back(dictionary[i]);
		}
	}
	return result;
}