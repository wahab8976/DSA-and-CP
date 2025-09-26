/*
Symmetric Tree      --      https://leetcode.com/problems/symmetric-tree/description/

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
*/

#include"Tree.h"
#include <vector>   
using namespace std;    
class Solution {
public:
    bool solve(TreeNode* leftSubTree, TreeNode* rightSubTree)
    {
        // If both are null -> symmetric at this level
        if(leftSubTree == nullptr && rightSubTree == nullptr)
            return true;
        
        // If only one is null -> not symmetric
        if(leftSubTree == nullptr || rightSubTree == nullptr)
            return false;

        // If values are different -> not symmetric
        if(leftSubTree->val != rightSubTree->val)
            return false;

        // Check cross symmetry
        return solve(leftSubTree->left, rightSubTree->right) &&
               solve(leftSubTree->right, rightSubTree->left);
    }

    bool isSymmetric(TreeNode* root) 
    {
        if(root == nullptr)
            return true;

        return solve(root->left, root->right);
    }
};
