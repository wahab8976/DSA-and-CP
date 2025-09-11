/*
416. Partition Equal Subset Sum         --      https://leetcode.com/problems/partition-equal-subset-sum/description/

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.
 

Constraints:

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

#include<vector>
using namespace std;

//      Recursive Memoization
class Solution {
public:
    bool solve(vector<int>& arr,int index,int sum,vector<vector<int>>& dp)
    {
        if(sum == 0)    return true;
        if(index == 0)
        {
            if(arr[0] == sum)
                return true;
            else
                return false;
        }

        if(dp[index][sum] != -1)    return dp[index][sum];

        bool doNotChoose = solve(arr,index - 1,sum,dp);
        bool choose = false;
        if(sum >= arr[index])
            choose = solve(arr,index - 1,sum - arr[index],dp);

        return dp[index][sum] = choose || doNotChoose;
    }

    bool canPartition(vector<int>& nums) 
    {
        // If Sum is odd, it is not possible
        int n = nums.size();
        int sum = 0;

        for(int i = 0;i < n;i++)    
            sum += nums[i];

        if(sum % 2) return false;   // Odd Sum

        // Dp array dp[index][sum+1]
        vector<vector<int>> dp(n,vector<int> (sum+1,-1));
        return solve(nums,n-1,sum/2,dp);
    }
};

//      Tabulation
class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        // If Sum is odd, it is not possible
        int n = nums.size();
        int sum = 0;

        for(int i = 0;i < n;i++)    
            sum += nums[i];

        if(sum % 2) 
                return false;   // Odd Sum

        // Dp array dp[index][sum+1]
        vector<vector<bool>> dp(n,vector<bool> (sum+1,false));

        for(int i = 0;i < n;i++)  
            dp[i][0] = true;    

        
        if(nums[0] <= sum) 
            dp[0][nums[0]] = true;

        for(int i=1;i<n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                bool doNotChoose = dp[i-1][j];
                bool choose = false;
                if(j >= nums[i])
                    choose = dp[i-1][j - nums[i]];
                dp[i][j] = doNotChoose || choose;
            }
        }

        return dp[n-1][sum/2];
    }
};


