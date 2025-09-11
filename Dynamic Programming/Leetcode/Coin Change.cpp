/*
518. Coin Change II     --      https://leetcode.com/problems/coin-change-ii/description/

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.

 

Example 1:

Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1
Example 2:

Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.
Example 3:

Input: amount = 10, coins = [10]
Output: 1
 

Constraints:

1 <= coins.length <= 300
1 <= coins[i] <= 5000
All the values of coins are unique.
0 <= amount <= 5000

*/
#include<vector>
using namespace std;

//      Recursive Memoization
class Solution {
public:
    int solve(int amount, int index, vector<int>& coins,vector<vector<int>>& dp) 
    {
        if (index == 0) 
        {
            if (amount % coins[0] == 0) // If total amount is divisible by coins at index 0 then there is one way possible. Eg. amount = 10 arr = [5]
                return 1;  
            else 
                return 0;   
        }

        if(dp[index][amount] != -1)     
            return dp[index][amount];

        int doNotPick = solve(amount, index-1, coins,dp);       // Skip the coin

        int pick = 0;
        if (amount >= coins[index])
            pick = solve(amount - coins[index], index, coins,dp);       // Choose the same coin again

        return dp[index][amount] = pick + doNotPick; 
    } 

    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int> (amount+1,-1));
        return solve(amount, n-1, coins,dp);
    }
};



//      Tabulation

class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<vector<long>> dp(n,vector<long> (amount+1,0));
        
        // BaseCase: For each index 0, if amount is divisible by element at 0 of amount, then it is 1 otherwise 0.
        for(int am = 0; am <= amount;am++)
        {
            if(am % coins[0] == 0)
                dp[0][am] = 1;
        }

        for(int index = 1;index < n;index++)
        {
            for(int am = 0;am <= amount;am++)
            {
                int doNotPick = dp[index-1][am]; 

                int pick = 0;
                if (am >= coins[index])
                    pick = dp[index][am - coins[index]];
                    
                dp[index][am] = long(pick) + long(doNotPick);
            }
        }
        return dp[n-1][amount];
    }
};

// Tabulation Space Optimized

class Solution {
public:
    int change(int amount, vector<int>& coins) 
    {
        int n = coins.size();
        vector<long> prev(amount+1,0);  // Previous Row

        for(int am = 0; am <= amount;am++)
        {
            if(am % coins[0] == 0)
                prev[am] = 1;
        }

        for(int index = 1;index < n;index++)
        {
            vector<long> current(amount+1,0);   // Current Row
            for(int am = 0;am <= amount;am++)
            {
                int doNotPick = prev[am]; 

                int pick = 0;
                if (am >= coins[index])
                    pick = prev[am - coins[index]];
                    
                prev[am] = long(pick) + long(doNotPick);
            }
            current = prev;     // Make current row as previous
        }
        return prev[amount];
    }
};