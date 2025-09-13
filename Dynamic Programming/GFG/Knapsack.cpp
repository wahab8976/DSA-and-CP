

#include<vector>
using namespace std;

//  Recursive Memoization
class Solution {
  public:
    int solve(int W,vector<int>& val,vector<int>& wt,int index,vector<vector<int>>& dp)
    {
        if(index == 0)
        {
            if(wt[0] <= W)
                return val[0];
            else 
                return 0;
        }
        
        if(dp[index][W] != -1) 
            return dp[index][W];
        
        int doNotChoose = solve(W,val,wt,index-1,dp);
        
        int choose = 0;
        if(W >= wt[index])
            choose = val[index] + solve(W-wt[index],val,wt,index-1,dp);
            
        return dp[index][W] = max(choose,doNotChoose);
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) 
    {
        // dp vector dp[index][weight]
        vector<vector<int>> dp(wt.size()+1,vector<int> (W+1,0));
        
        for(int i = wt[0]; i <= W;i++)
            dp[0][i] = val[0];
        
        int n = wt.size();
        
        for(int index = 1; index < n ;index++)
        {
            for(int weight = 0;weight <= W;weight++)
            {
                int doNotChoose = dp[index-1][weight];
                int choose = 0;
                
                if(weight >= wt[index])
                    choose = val[index] + dp[index-1][weight - wt[index]];
                
                dp[index][weight] = max(choose,doNotChoose);
            }
        }
            
        return dp[n-1][W];
    }
}; 