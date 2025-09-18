/*
102. Binary Tree Level Order Traversal      --      https://leetcode.com/problems/binary-tree-level-order-traversal/description/    

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
Example 2:

Input: root = [1]
Output: [[1]]
Example 3:

Input: root = []
Output: []
 

Constraints:

The number of nodes in the tree is in the range [0, 2000].
-1000 <= Node.val <= 1000
*/

#include<vector>
#include<queue>
#include"Tree.h"
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;

        if(root == NULL)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            vector<int> level;

            for(int i = 0; i < size; i++)
            {
                TreeNode* node = q.front();
                q.pop();

                if(node->left != NULL)
                    q.push(node->left);
                
                if(node->right != NULL)
                    q.push(node->right);

                level.push_back(node->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};

