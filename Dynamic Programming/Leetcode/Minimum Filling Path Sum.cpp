/*
931. Minimum Falling Path Sum           --              https://leetcode.com/problems/minimum-falling-path-sum/description/

Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

 

Example 1:


Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.
Example 2:


Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.
 

Constraints:

n == matrix.length == matrix[i].length
1 <= n <= 100
-100 <= matrix[i][j] <= 100
*/

#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

//      Recursive Memoization
class Solution {
public:
    int solve(vector<vector<int>>& matrix, int row, int col,vector<vector<int>>& dp) 
    {
        if (col < 0 || col >= matrix[0].size()) 
            return 1e9;
        if (row == 0)   
            return matrix[0][col];

        if(dp[row][col] != INT_MAX)    
            return dp[row][col];

        int up = matrix[row][col] + solve(matrix, row-1, col,dp);
        int left = matrix[row][col] + solve(matrix, row-1, col-1,dp);
        int right = matrix[row][col] + solve(matrix, row-1, col+1,dp);
        
        return dp[row][col] = min({up, left, right});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int ans = INT_MAX;
        
        vector<vector<int>> dp(rows,vector<int> (cols,INT_MAX));
        
        for (int col = 0; col < cols; col++) 
            ans = min(ans, solve(matrix, rows-1, col,dp));
        
        return ans;
    }
};

//      Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        
        for(int j = 0; j < cols; j++) 
            dp[0][j] = matrix[0][j];
        
        
        for(int i = 1; i < rows; i++) 
            for(int j = 0; j < cols; j++) 
            {
                int up = dp[i-1][j];
                int left = (j > 0) ? dp[i-1][j-1] : INT_MAX;
                int right = (j < cols-1) ? dp[i-1][j+1] : INT_MAX;
                
                dp[i][j] = matrix[i][j] + min({up, left, right});
            }
        
        
        // Minimum of last row
        int ans = INT_MAX;
        for(int j = 0; j < cols; j++) 
            ans = min(ans, dp[rows-1][j]);
        
        return ans;
    }
};