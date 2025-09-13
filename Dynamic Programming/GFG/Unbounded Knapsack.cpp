/*
Knapsack with Duplicate Items       --      https://www.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/0

Given a set of items, each with a weight and a value, represented by the array wt and val respectively. Also, a knapsack with a weight limit capacity.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

Examples:

Input: val = [1, 1], wt = [2, 1], capacity = 3
Output: 3
Explanation: The optimal choice is to pick the 2nd element 3 times.
Input: val[] = [6, 1, 7, 7], wt[] = [1, 3, 4, 5], capacity = 8
Output: 48
Explanation: The optimal choice is to pick the 1st element 8 times.
Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
Output: 0
Explanation: We can't pick any element .hence, total profit is 0.
Constraints:
1 <= val.size() = wt.size() <= 1000
1 <= capacity <= 1000
1 <= val[i], wt[i] <= 100

*/


#include<vector>
using namespace std;

//  Recursive Memoization
class Solution {
  public:
    int solve(vector<int>& val,vector<int>& wt,int capacity,int index,vector<vector<int>>& dp)
    {
        if(index == 0)  
            return (capacity/wt[0]) * val[0];
        
        if(dp[index][capacity]  != -1)
            return dp[index][capacity];
            
        int doNotPick = solve(val,wt,capacity,index-1,dp);
        
        int pick = 0;
        if(capacity >= wt[index])
            pick = val[index] + solve(val,wt,capacity - wt[index],index,dp);
            
        return dp[index][capacity] = max(pick,doNotPick);
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        int n = val.size();
        vector<vector<int>> dp(n,vector<int> (capacity+1,-1));
        return solve(val,wt,capacity,n-1,dp);
    }
};

//      Tabulation
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        int n = val.size();
        vector<vector<int>> dp(n,vector<int> (capacity+1,0));
        
        for(int cap = 0; cap <= capacity;cap++)         // Base Case
            dp[0][cap] = cap/wt[0] * val[0];
        
        for(int index = 1;index < n;index++)
        {
            for(int cap = 0; cap <= capacity;cap++)
            {
                int doNotPick = dp[index-1][cap];
                int pick = 0;
                if(cap >= wt[index])
                    pick = val[index] + dp[index][cap - wt[index]];
                    
                dp[index][cap] = max(pick,doNotPick);
            }
        }
            
        return dp[n-1][capacity];
    }
};

// Tabulation Space Optimized
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        int n = val.size();
        vector<int> prev(capacity+1,0);
        
        for(int cap = 0; cap <= capacity;cap++)
            prev[cap] = (cap/wt[0]) * val[0];
        
        for(int index = 1;index < n;index++)
        {
            for(int cap = 0; cap <= capacity;cap++)
            {
                int doNotPick = prev[cap];
                int pick = 0;
                if(cap >= wt[index])
                    pick = val[index] + prev[cap - wt[index]];

                prev[cap] = max(pick,doNotPick);
            }
        }
            
        return prev[capacity];
    }
};