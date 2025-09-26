/*
199. Binary Tree Right Side View    ==  https://leetcode.com/problems/binary-tree-right-side-view/description/

Given the root of a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

 

Example 1:

Input: root = [1,2,3,null,5,null,4]

Output: [1,3,4]

Explanation:



Example 2:

Input: root = [1,2,3,4,null,null,null,5]

Output: [1,3,4,5]

Explanation:



Example 3:

Input: root = [1,null,3]

Output: [1,3]

Example 4:

Input: root = []

Output: []

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100

*/

#include"Tree.h"
#include <vector>
using namespace std;

class Solution {
public:
    void solve(TreeNode* node,vector<int>& nodesVal,int level)
    {
        if(node == NULL)
            return;
        
        if(nodesVal.size() == level)    //  if level is same as size, node already added
            nodesVal.push_back(node->val);
        
        solve(node->right,nodesVal,level + 1);
        solve(node->left,nodesVal,level + 1);
    }

    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        solve(root,ans,0);
        return ans;
    }
};