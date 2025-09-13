/*
Frog Jump       ==      https://www.geeksforgeeks.org/problems/geek-jump/0
Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.

Example:

Input: heights[] = [20, 30, 40, 20] 
Output: 20
Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
jump from stair 0 to 1: cost = |30 - 20| = 10
jump from stair 1 to 3: cost = |20-30|  = 10
Total Cost = 10 + 10 = 20
Input: heights[] = [30, 20, 50, 10, 40]
Output: 30
Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
jump from stair 0 to 2: cost = |50 - 30| = 20
jump from stair 2 to 4: cost = |40-50|  = 10
Total Cost = 20 + 10 = 30
Constraints:

1 <= height.size() <= 105
0 <= height[i]<=104
*/

#include<vector>
#include<math.h>
using namespace std;

//  Recursive Memoization
class Solution {
  public:
    int solve(int index,vector<int>& height,vector<int>& dp)
    {
        if(dp[index] != -1)
            return dp[index];
            
        int left = solve(index-1,height,dp) + abs(height[index] - height[index-1]);
        int right = 1e9;
        if(index > 1)
                right = solve(index-2,height,dp) + abs(height[index] - height[index-2]);  
        
        return dp[index] = min(left,right);
    }
    
    int minCost(vector<int>& height) 
    {
        vector<int> dp(height.size(),-1);
        dp[0] = 0;
        return solve(height.size()-1,height,dp);
    }
};

//      Tabulation
class Solution {
  public:
    int minCost(vector<int>& height) 
    {
        vector<int> dp(height.size(),-1);
        dp[0] = 0;      // Base Case
        
        for(int i = 1;i < height.size();i++)
        {
            int prev = dp[i-1] + abs(height[i] - height[i-1]);
            int prev2 = 1e9;
            if(i > 1)
                prev2 = dp[i-2] + abs(height[i] - height[i-2]);
            
            dp[i] = min(prev,prev2);
        }
        return dp[height.size()-1];
    }
};