/*
Longest Common Prefix

28% Accepted
Given k strings, find the longest common prefix (LCP).

Have you met this question in a real interview? Yes
Example
For strings "ABCD", "ABEF" and "ACEF", the LCP is "A"

For strings "ABCDEFG", "ABCEFG" and "ABCEFA", the LCP is "ABC"
*/
#include <vector>
using std::string;
using std:vector;
class Solution {
public:
    /**
     * @param strs: A list of strings
     * @return: The longest common prefix
     */
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty())
          return "";
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); i++){
          prefix = findLongestCommonPrefix(prefix, strs[i]);
        }
        return prefix;
    }
    string findLongestCommonPrefix(string a, string b){
      for (int i = 0; i < a.size() && i < b.size(); i++){
        if (a[i] != b[i])
          return a.substr(0, i);
      }
      return a.size() >= b.size() ? b : a;
    }
};
