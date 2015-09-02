/*
Unique Paths II

27% Accepted
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

Have you met this question in a real interview? Yes
Example
For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
The total number of unique paths is 2.

Note
m and n will be at most 100.
*/
class Solution {
public:
    /**
     * @param obstacleGrid: A list of lists of integers
     * @return: An integer
     */
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        if (obstacleGrid.empty() || 0 == obstacleGrid[0].empty() || 1 == obstacleGrid[0][0])
          return 0;
        int size = obstacleGrid[0].size();
        vector<int> table(size, 1);
        for (int j = 1; j < size; j++){
          if (1 == obstacleGrid[0][j])
            table[j] = 0;
          else
            table[j] = table[j - 1];
        }
        for (int i = 1; i < obstacleGrid.size(); i++){
          table[0] = 1 == obstacleGrid[i][j] ? 0 : table[0];
          for (int j = 1; j < size; j++){
              table[j] = 1 == obstacleGrid[i][j] ? 0 : table[j] + table[j - 1];
          }
        }
        return table[size - 1];
    }
};
