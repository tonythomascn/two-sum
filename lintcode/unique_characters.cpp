/*
Unique Characters

44% Accepted
Implement an algorithm to determine if a string has all unique characters.

Have you met this question in a real interview? Yes
Example
Given "abc", return true.

Given "aab", return false.

Challenge
What if you can not use additional data structures?
*/
class Solution {
public:
    /**
     * @param str: a string
     * @return: a boolean
     */
    bool isUnique(string &str) {
      if (256 < str.size())
      return false;
      bool check[256];
      memset(check, false, 256);
      for (int i = 0; i < str.size(); i++){
          int val = str[i];
          if (check[val])
              return false;
          check[val] = true;
      }
      return true;
    }
};
