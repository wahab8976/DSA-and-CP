/*
78. Subsets     --      https://leetcode.com/problems/subsets/description/

Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
 

Constraints:
1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

*/

#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        int len = nums.size();
        int combos = pow(2,len);    // No. of required Combinations in binary
        vector<vector<int>> ans;

        for(int i = 0; i < combos ;i++)
        {
            vector<int> subsets;
            // Generate all combinations possible for that length
            for(int j = 0; j < len; j++)
            {
                // Mask all combinations with array wherever bit is ON
                if(i & (1<<j))
                    subsets.push_back(nums[j]);
            }
            ans.push_back(subsets);
        }
        return ans;
    }
};