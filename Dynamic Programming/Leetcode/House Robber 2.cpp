/*
213. House Robber II    --      https://leetcode.com/problems/house-robber-ii/

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [2,3,2]
Output: 3
Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are adjacent houses.
Example 2:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 3:

Input: nums = [1,2,3]
Output: 3
 

Constraints:

1 <= nums.length <= 100
0 <= nums[i] <= 1000
*/

#include<vector>
using namespace std;

//      Recursive Memoization
class Solution {
public:
    int solve(vector<int> nums, int index, vector<int>& dp) 
    {
        if (index < 0) 
                return 0;

        if (dp[index] != -1) 
                return dp[index];

        int pick = nums[index] + solve(nums, index - 2, dp);
        int dontPick = solve(nums, index - 1, dp);

        return dp[index] = max(pick, dontPick);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0]; // only one house

        // Case 1: Rob houses [0 ... n-2]
        vector<int> dp1(n, -1);
        int case1 = solve(nums, n - 2, dp1);

        // Case 2: Rob houses [1 ... n-1]
        vector<int> dp2(n, -1);
        int case2 = solve(vector<int>(nums.begin() + 1, nums.end()), n - 2, dp2);

        return max(case1, case2);
    }
};