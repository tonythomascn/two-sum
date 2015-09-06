/*
Longest Common Substring

31% Accepted
Given two strings, find the longest common substring.

Return the length of it.

Have you met this question in a real interview? Yes
Example
Given A = "ABCD", B = "CBCE", return 2.

Note
The characters in substring should occur continuously in original string. This is different with subsequence.

Challenge
O(n x m) time and memory.
*/
#include <string>
#include <vector>
using std::vector;
using std::string;
class Solution {
public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     */
    int longestCommonSubstring(string &A, string &B) {
      vector<string> substring;
        for (int i = A.size(); i > 0; i--){
          for (int j = 0; j <= A.size() - i; j++){
            substring.push_back(A.substr(j, i));
            //printf("%s\n", A.substr(j,i).c_str());
          }
        }
        for (int i = 0; i < substring.size(); i++){
          if (string::npos != B.find(substring[i])){
            return substring[i].size();
          }
        }
        return 0;
    }
};
int main(){
  Solution s;
  string a = "ABCD";
  string b = "AB";
  printf("%d", s.longestCommonSubstring(a, b));
}
