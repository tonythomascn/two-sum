/*
Anagrams

23% Accepted
Given an array of strings, return all groups of strings that are anagrams.

Have you met this question in a real interview? Yes
Example
Given ["lint", "intl", "inlt", "code"], return ["lint", "inlt", "intl"].

Given ["ab", "ba", "cd", "dc", "e"], return ["ab", "ba", "cd", "dc"].

Note
All inputs will be in lower-case
*/
#include <vector>
#include <string>
using std::string;
using std::vector;
using std::unordered_map;

class Solution{
public:
	/**
	 * @param strs: A list of strings
	 * @return: A list of strings
	 */
	vector<string> anagrams(vector<string> &strs) {
		unordered_map<string, vector<int>> m;
		vector<string> result;
		string key;
		for (int i = 0; i < strs.size(); i++){
			key = strs[i];
			std::sort(key.begin(), key.end());
			m[key].push_back(i);
		}
		for (auto it = m.begin(); it != m.end(); it++){
			if (1 < it->second.size()){
				for (int i = 0; i < it->second.size(); i++)
					result.push_back(strs[it->second[i]]);
			}
		}
		return result;
	}
};
