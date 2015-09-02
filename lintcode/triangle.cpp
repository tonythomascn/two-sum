/*
Triangle

26% Accepted
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

Have you met this question in a real interview? Yes
Example
For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
class Solution {
public:
    /**
     * @param triangle: a list of lists of integers.
     * @return: An integer, minimum path sum.
     */
    int minimumTotal(vector<vector<int> > &triangle) {
      if (triangle.empty() || triangle[0].empty())
      return 0;
      //assign the last row to the result as start
        vector<int> res(triangle[triangle.size() - 1]);
        //scan from the bottom to the top
        for (int i = triangle.size() - 2; i >= 0; i--){
          for (int j = 0; j < triangle[i].size(); j++){
            res[j] = min(res[j], res[j + 1]) + triangle[i][j];
          }
        }
        return res[0];
    }
};
