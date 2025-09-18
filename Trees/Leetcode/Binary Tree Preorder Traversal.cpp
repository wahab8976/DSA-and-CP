/*
114. Binary Tree Preorder Traversal  --  https://leetcode.com/problems/binary-tree-preorder-traversal/description/
*/

#include<vector>
#include<queue>
#include"Tree.h"
using namespace std;
//Recursive 
class Solution {
public:
    void print(TreeNode* node,vector<int>& res)
    {
        if(node == NULL)
            return;
        res.push_back(node->val);
        print(node->left,res);
        print(node->right,res);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        print(root,result);
        return result;
    }
};