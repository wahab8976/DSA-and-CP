/*
72. Edit Distance       --      https://leetcode.com/problems/edit-distance/description/

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character
 

Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 

Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
*/

#include<vector>
#include<string>
using namespace std;

//Recursive Memoization
class Solution {
public:
    int solve(string word1, string word2,int i,int j,vector<vector<int>>& dp)
    {
        if(i < 0)   
            return j+1;

        if(j < 0)
            return i+1;

        if(dp[i][j] != -1)
            return dp[i][j];

        if(word1[i] == word2[j])
            return solve(word1,word2,i - 1,j - 1,dp);
        else
            {
                int del = 1 + solve(word1,word2,i - 1,j,dp);
                int rep = 1 + solve(word1,word2,i - 1,j - 1,dp);
                int ins = 1 + solve(word1,word2,i, j - 1,dp);
                return dp[i][j] = min({del,rep,ins});
            }
    }

    int minDistance(string word1, string word2) 
    {
        vector<vector<int>> dp(word1.size(),vector<int> (word2.size(),-1));
        return solve(word1,word2,word1.size()-1,word2.size()-1,dp);    
    }
};

// Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        vector<vector<int>> dp(word1.size() + 1,vector<int> (word2.size() + 1,0));

        // Base cases
        for(int i =0 ;i <= word2.size();i++)
            dp[0][i] = i;

        for(int i =0 ;i <= word1.size();i++)
            dp[i][0] = i;

        for(int i = 1; i <= word1.size();i++)
        {
            for(int j = 1; j <= word2.size();j++)
            {
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
            }
        }
        return dp[word1.size()][word2.size()];
    }
};