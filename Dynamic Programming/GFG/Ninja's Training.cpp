/*
Ninja's Training        --      https://www.geeksforgeeks.org/problems/geeks-training/0

Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve .

Example:

Input: arr[]= [[1, 2, 5], [3, 1, 1], [3, 3, 3]]
Output: 11
Explanation: Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum merit point will be 11.
Input: arr[]= [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
Output: 6
Explanation: Geek can perform any activity each day while adhering to the constraints, in order to maximize his total merit points as 6.
Input: arr[]= [[4, 2, 6]]
Output: 6
Explanation: Geek will learn a new move to make his merit points as 6.
Constraint:
1 <=  n <= 105   
1 <=  arr[i][j] <= 100
*/

#include<vector>
using namespace std;

//  Recursive Memoization
class Solution {
  public:
    int solve(vector<vector<int>>& arr, int index, int lastSeen, vector<vector<int>>& dp) 
    {
        // Base case
        if(index == 0) 
        {
            int maxElement = 1e9;
            for(int i = 0; i < 3; i++) 
            {
                if(i != lastSeen) 
                    maxElement = max(maxElement, arr[0][i]);
            }
            return dp[0][lastSeen] = maxElement;
        }

        // Memoization check
        if(dp[index][lastSeen] != -1) 
                return dp[index][lastSeen];

        int maxSum = 0;
        for(int i = 0; i < 3; i++) 
        {
            if(i != lastSeen) 
            {
                int sum = arr[index][i] + solve(arr, index-1, i, dp);
                maxSum = max(maxSum, sum);
            }
        }
        return dp[index][lastSeen] = maxSum;
    }
    
    int maximumPoints(vector<vector<int>>& arr) 
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return solve(arr, n-1, 3, dp);
    }
};