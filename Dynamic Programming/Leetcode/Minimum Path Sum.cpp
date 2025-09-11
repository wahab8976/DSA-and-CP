/*
64. Minimum Path Sum    --      https://leetcode.com/problems/minimum-path-sum/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 

Example 1:


Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200

*/

#include<vector>
using namespace std;
class Solution {
public:
    int solve(vector<vector<int>>& grid, int m, int n, vector<vector<int>>& dp) 
    {
        
        if (m < 0 || n < 0) 
                return 1e9;

        if (m == 0 && n == 0) 
                return grid[0][0];

        if (dp[m][n] != -1) 
                return dp[m][n];

        int leftExplore = solve(grid, m, n - 1, dp);
        int upExplore   = solve(grid, m - 1, n, dp);

        return dp[m][n] = grid[m][n] + min(leftExplore, upExplore);
    }

    int minPathSum(vector<vector<int>>& grid) 
    {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1));

        return solve(grid, rows - 1, cols - 1, dp);
    }
};

        // Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, 0));

        dp[0][0] = grid[0][0];

        for(int i = 0;i < rows; i++)
        {
            for(int j = 0; j < cols; j++){
                if(i == 0 && j == 0)    continue;

                int left = 1e9;
                if(j > 0) 
                        left = grid[i][j] + dp[i][j-1];
                int right = 1e9;
                if(i > 0) 
                        right = grid[i][j] + dp[i-1][j];
                dp[i][j] = min(left,right);
            }
        }

        return dp[rows-1][cols-1];
    }
};