/*
1143. Longest Common Subsequence    --      https://leetcode.com/problems/longest-common-subsequence/description/

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.

Example 1:

Input: text1 = "abcde", text2 = "ace" 
Output: 3  
Explanation: The longest common subsequence is "ace" and its length is 3.
Example 2:

Input: text1 = "abc", text2 = "abc"
Output: 3
Explanation: The longest common subsequence is "abc" and its length is 3.
Example 3:

Input: text1 = "abc", text2 = "def"
Output: 0
Explanation: There is no such common subsequence, so the result is 0.
 

Constraints:

1 <= text1.length, text2.length <= 1000
text1 and text2 consist of only lowercase English characters.
*/

#include<vector>
#include<string>
using namespace std;
//  Recursive Memoization
class Solution {
public:

    int solve(string text1,string text2,int index1,int index2,vector<vector<int>>& dp)
    {
        if(index1 == 0 || index2 == 0)
            return 0;

        if(dp[index1][index2] != -1)
            return dp[index1][index2];

        if(text1[index1-1] == text2[index2-1])
            return dp[index1][index2] = 1 + solve(text1, text2, index1 - 1, index2 - 1,dp);

        int reduceLeft = solve(text1, text2, index1 - 1, index2,dp);
        int reduceRight = solve( text1, text2, index1, index2-1,dp);

        return dp[index1][index2] = max(reduceLeft,reduceRight);
    }
};


//  Tabulation
class Solution{
    public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.size();
        int n = text2.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        
        for(int i = 1;i <= m;i++)
        {
            for(int j = 1; j <= n;j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    int reduceLeft = dp[i-1][j];
                    int reduceRight = dp[i][j-1];
                    dp[i][j] = max(reduceLeft,reduceRight);
                }
            }
        }
        return dp[m][n];
    }
};

// Tabulation Space Optimized
class Solution{
    public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        int m = text1.size();
        int n = text2.size();
        vector<int> prev(n+1,0),curr(n+1,0);
            
        for(int i = 1;i <= m;i++)
        {
            for(int j = 1; j <= n;j++)
            {
                if(text1[i-1] == text2[j-1])
                {
                    curr[j] = 1 + prev[j-1];
                }else{
                    int reduceLeft = prev[j];
                    int reduceRight = curr[j-1];
                    curr[j] = max(reduceLeft,reduceRight);
                }
            }
            prev = curr;
        }
        return prev[n];
    }    
};

// Printing LCS using DP matrix     --      Only works when there are no duplicates, else use Bruteforce Backtracking
class Solution{
    public:
    string getLCS(vector<vector<int>>& dp, int m,int n,string s1)
    {
        int index = dp[m][n];
        string LCS = "";
        while (m > 0 && n > 0)
        {
            // If characters match, then it is part of LCS
            if (dp[m - 1][n] == dp[m][n - 1])
            {
                LCS = s1[m - 1] + LCS;
                m--;
                n--;
                index--;
            }
            else if (dp[m - 1][n] > dp[m][n - 1])
            {
                m--;
            }
            else {
                n--;
            }
        }
    }
};
