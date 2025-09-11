/*
322. Coin Change        --      https://leetcode.com/problems/coin-change/description/

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

 

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0
 

Constraints:

1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/

#include<vector>
using namespace std;

//      Recursive Memoization
class Solution {
public:
    int solve(vector<int>& coins,int amount,int index,vector<vector<int>>& dp)
    {
        if(index == 0)  // If amount is divisible by coins at 0, number of coins will be amount/coins at 0
        {
            if(amount % coins[0] == 0) 
                return amount / coins[0];
            else 
                return 1e9;
        }

        if(dp[index][amount] != -1)
            return dp[index][amount];

        int doNotPick = 0 + solve(coins,amount,index-1,dp);
        int pick = 1e9;

        if(amount >= coins[index])
            pick = 1 + solve(coins,amount - coins[index],index,dp);

        return dp[index][amount] = min(pick,doNotPick);
    }

    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        int ans = solve(coins, amount, n-1, dp);
        return (ans >= 1e9) ? -1 : ans;

    }
};


// Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,1e9));

        for(int i = 0; i <= amount;i++)
        {
            if(i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e9;
        }

        for(int index = 1; index < n;index++)
        {
            for(int am = 0; am <= amount;am++)
            {
                int doNotPick = dp[index-1][am];
                int pick = 1e9;
                if(am >= coins[index])
                    pick = 1 + dp[index][am - coins[index]];
                dp[index][am] = min(pick,doNotPick);
            }
        }
        
        if(dp[n-1][amount] >= 1e9)
            return -1;
        else
            return dp[n-1][amount];
    }
};
