/*
Unique Paths Show result

35% Accepted
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?

Have you met this question in a real interview? Yes
Example


Above is a 3 x 7 grid. How many possible unique paths are there?

Note
m and n will be at most 100.
*/
class Solution {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
        if (1 == m || 1 == n)
            return 1;
        //Recursive backtracking, very time-consuming, time complexity O(m*n), extra space O(m*n)
        return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
    }
};
class Solution1 {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
      //Dynamic programming, time complexity O(m*n), extra space O(m*n)
        vector<vector<int>> table(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++){
          for (int j = 1; j < n; j++)
            table[i][j] = table[i - 1][j] + table[i][j - 1];
        }
        //Recursive backtracking, very time-consuming
        return table[m - 1][n - 1];
    }
};
class Solution2 {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
      //Dynamic programming, we just store one tile every time time, complexity O(m*n), extra space O(n)
        vector<int> table(n, 1);
        for (int i = 1; i < m; i++){
          for (int j = 1; j < n; j++)
            table[j] = table[j] + table[j - 1];
        }
        //Recursive backtracking, very time-consuming
        return table[n - 1];
    }
};

class Solution2 {
public:
    /**
     * @param n, m: positive integer (1 <= n ,m <= 100)
     * @return an integer
     */
    int uniquePaths(int m, int n) {
      //Dynamic programming, we just store one tile every time time, complexity O(m*n), extra space O(n)
      int row = min(m, n);
      int col = max(m, n);
        vector<int> table(col, 1);
        for (int i = 1; i < row; i++){
          table[i] *= 2;
          for (int j = i + 1; j < col; j++)
            table[j] += table[j - 1];
        }
        //Recursive backtracking, very time-consuming
        return table[col - 1];
    }
};
