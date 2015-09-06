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
#include <algorithm>
using std::vector;
using std::string;
using std::max;
class Solution {
public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     * Basic implementation, break string A into all possible substrings and
     * find the longest substring exist or not in string B.
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
class Solution2 {
public:
    /**
     * @param A, B: Two string.
     * @return: the length of the longest common substring.
     * Dynamic programming, using one dimension table to contain the current longest common substring length.
     * The longest substring length is the longest among all the iterations.
     */
    int longestCommonSubstring(string &A, string &B) {
      if (A.size() < B.size())
        return longestCommonSubstring(B, A);

      vector<int> table(A.size(), 0);
      int longest = 0;
      int temp = 0;
        for (int i = 0; i < B.size(); i++){
          temp = 0;
          for (int j = A.size() - 1; j >= 0; j--){
            if (A[j] == B[i]){
              table[j] = j == 0 ? 1 : table[j - 1] + 1;
              temp = max(temp, table[j]);
            }
            else
              table[j] = 0;
              printf ("%d ", table[j]);
          }
          longest = max(temp, longest);
        }


        return longest;
    }
};
int main(){
  Solution2 s;
  string a = "ABCD";
  string b = "AB";
  printf("%d", s.longestCommonSubstring(a, b));
}
