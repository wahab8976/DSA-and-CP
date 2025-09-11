/*
63. Unique Paths II     --      https://leetcode.com/problems/unique-paths-ii/description/

You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.

Return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The testcases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
Example 2:


Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
 

Constraints:

m == obstacleGrid.length
n == obstacleGrid[i].length
1 <= m, n <= 100
obstacleGrid[i][j] is 0 or 1.

*/

#include<vector>
using namespace std;

//      Recursive Memoization 
class Solution {
public:
    int solve(vector<vector<int>>& grid,int r,int c,vector<vector<int>>& dp)
    {
        if(r == -1 || c == -1)  //Either row or Column is out of matrix
                return 0; 
        if(grid[r][c] == 1)     //Obstacle Found marked as 1
                return 0; 
        if(r == 0 && c == 0)    // Reached Destination
                return 1;

        if(dp[r][c] != -1)  
                return dp[r][c];

        int left = solve(grid,r,c-1,dp);
        int up = solve(grid,r-1,c,dp);

        return dp[r][c] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        vector<vector<int>> dp(rows,vector<int> (cols,-1));
        dp[0][0] = 1;

        return solve(obstacleGrid,rows - 1,cols - 1,dp);
    }
};


//      Tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows,vector<int> (cols,0));
        
        //If first element itself is an obstacle, No way possible for that place
        if(obstacleGrid[0][0] == 1)
            dp[0][0] = 0;
        else
            dp[0][0] = 1;

        for(int i = 0; i < rows;i++)
        {
            for(int j = 0; j < cols;j++)
            {
                if(i == 0 && j == 0) 
                        continue;

                if(obstacleGrid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;   // Skip remaining loop if there is an obstacle
                }

                int left = 0;
                int up = 0;
                if(j > 0)   
                        left = dp[i][j - 1];
                if(i > 0)   
                        up = dp[i - 1][j];
                dp[i][j] = left + up;
            }
        }
        return dp[rows-1][cols-1];
    }
};