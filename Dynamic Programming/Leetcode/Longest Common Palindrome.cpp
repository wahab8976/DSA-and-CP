/*
516. Longest Palindromic Subsequence    --      https://leetcode.com/problems/longest-palindromic-subsequence/description/

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
Example 2:

Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
 

Constraints:

1 <= s.length <= 1000
s consists only of lowercase English letters.

*/

   // Similar to Longest Common Subsequence
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) 
    {   
        int m = s.size();
        int n = m;

        string s2 = s;
        reverse(s2.begin(),s2.end());

        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        
        for(int i = 1;i <= m;i++)
        {
            for(int j = 1; j <= n;j++)
            {
                if(s2[i-1] == s[j-1])
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