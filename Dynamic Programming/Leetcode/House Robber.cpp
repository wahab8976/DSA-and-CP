/*
House Robber    --      https://leetcode.com/problems/house-robber/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 400
*/

#include<vector>
using namespace std;

//      Recursive Memoization
class Solution {
public:
    int solve(vector<int>& nums,int index,vector<int>& dp)
    {
        if(index == -1) 
                return 0; // Add 0 if recursion call is out of bounds

        if(dp[index] != -1)   
                return dp[index];

        int pick = nums[index]+ solve(nums,index - 2,dp);
        int donotPick = solve(nums,index - 1,dp);   // Do nothing if decided, not to pick the element
        
        dp[index] = max(pick,donotPick);
        return dp[index];
    }
    int rob(vector<int>& nums) 
    {
        vector<int> dp(nums.size(),-1);
        dp[0] = nums[0];
        return solve(nums,nums.size()-1,dp);
    }
};

//      Tabulation
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        vector<int> dp(nums.size(),-1);
        dp[0] = nums[0];
        int n = nums.size();
        
        for(int i = 1; i < n;i++)
        {
            int pick = nums[i];
            if(i > 1) 
                pick += dp[i-2];

            int doNotPick = dp[i - 1]; 
            dp[i] = max(pick,doNotPick);
        }
        return dp[n-1];
    }
};

//      Tabulation Space Optimized
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        int prev1 = nums[0];
        int prev2 = 0;

        for(int i = 1; i < n;i++)
        {
            int pick = nums[i];
            if(i > 1) 
                pick += prev2;

            int doNotPick = prev1; 
            int curr = max(pick,doNotPick);

            prev2 = prev1;
            prev1 = curr;

        }
        return prev1;
    }
};