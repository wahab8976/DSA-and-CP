/*
120. Triangle           --              https://leetcode.com/problems/triangle/description/

Given a triangle array, return the minimum path sum from top to bottom.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

 

Example 1:

Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
Example 2:

Input: triangle = [[-10]]
Output: -10
 

Constraints:

1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104

*/

#include<vector>
using namespace std;

//      Recursive Memoization
class Solution {
public:
    int solve(vector<vector<int>>& triangle,int row,int col,vector<vector<int>>& dp)
    {
        if(row == triangle.size()-1)    
            return triangle[row][col];

        if(dp[row][col] != 1e9)  
            return dp[row][col];

        int down = triangle[row][col] + solve(triangle,row+1,col,dp);
        int rightDown = triangle[row][col] + solve(triangle,row+1,col+1,dp);
        return dp[row][col] = min(down,rightDown);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,1e9));
        return solve(triangle,0,0,dp);    
    }
};

//      Tabulation
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int> (n,0));

        // Last n columns will be the base cases
        for(int i = 0; i < n;i++)
            dp[n - 1][i] = triangle[n - 1][i];

        for(int i = n - 2; i >= 0;i--)
        {
            for(int j = i;j >= 0;j--)
            {
                int down = triangle[i][j] + dp[i + 1][j];
                int downRight = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down,downRight);
            }
        }
        return dp[0][0];   
    }
};

        // Tabulation Space Optimized
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<int> dp(n,0);
        // Last n columns will be the base cases
        for(int i = 0; i < n;i++)
            dp[i] = triangle[n - 1][i];

        for(int i = n - 2; i >= 0;i--)
        {
            vector<int> current(n,0);
            for(int j = i;j >= 0;j--)
            {
                int down = triangle[i][j] + dp[j];
                int downRight = triangle[i][j] + dp[j+1];
                current[j] = min(down,downRight);
            }
            dp = current;
        }
        return dp[0];   
    }
};