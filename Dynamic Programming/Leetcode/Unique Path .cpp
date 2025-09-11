/*
Unique Paths    --      https://leetcode.com/problems/unique-paths/

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.

 

Example 1:


Input: m = 3, n = 7
Output: 28
Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
 

Constraints:

1 <= m, n <= 100
*/

#include<vector>
using namespace std;

//      Recursive Memoization
class Solution {
public:
    int solve(int m,int n,vector<vector<int>>& dp)
    {
        if(m == -1 || n == -1)  
                return 0;
        if(dp[m][n] != -1)  
                return dp[m][n];

        int leftExplore = solve(m - 1,n,dp);
        int upExplore = solve(m,n - 1,dp);

        return dp[m][n] = leftExplore + upExplore;
    }

    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        dp[0][0] = 1;
        return solve(m-1,n-1,dp);
    }
};

//      Tabulation
class Solution {
public:
    int uniquePaths(int m, int n) 
    {

        vector<vector<int>> dp(m,vector<int> (n,-1));
        dp[0][0] = 1;

        for(int i = 0; i < m;i++)
        {
            for(int j = 0; j < n;j++)
            {
                if(i == 0 && j == 0)    
                        continue;

                int left = 0;
                int up = 0;
                if(i > 0)   
                    left = dp[i - 1][j];
                if(j > 0) 
                    up = dp[i][j-1];  
                dp[i][j] = left + up;
            }
        }
        return dp[m-1][n-1];
    }
};

//      Tabulation Space Optimized
class Solution {
public:
    int uniquePaths(int m, int n) {

        vector<int> prev(n,0);
        for(int i = 0; i < m;i++)
        {
            vector<int> curr(n,0);
            for(int j = 0; j < n;j++)
            {
                if(i == 0 && j == 0)    
                    curr[j] = 1;
                else{
                    int left = 0;
                    int up = 0;
                    if(j > 0)   
                        left = curr[j-1];
                    if(i > 0) 
                        up = prev[j];  
                    curr[j] = left + up;
                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
};