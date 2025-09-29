/*
Binary Tree Left Side View    ==  https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

Given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

If the tree is empty, return an empty list.

Examples :

Input: root[] = [1, 2, 3, 4, 5, N, N]

Output: [1, 2, 4]
Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

Input: root[] = [1, 2, 3, N, N, 4, N, N, 5, N, N]

Output: [1, 2, 4, 5]
Explanation: From the left side of the tree, the nodes 1, 2, 4, and 5 are visible.

Constraints:
0 <= number of nodes <= 106
0 <= node -> data <= 105

*/

#include"Node.h"
#include <vector>
using namespace std;
class Solution {
  public:
    void solve(Node* node,vector<int>& ans,int level)
    {
        if(node == NULL)
            return;
            
        if(ans.size() == level)
            ans.push_back(node->data);
        
        solve(node->left,ans,level + 1);
        solve(node->right,ans,level + 1);
    }
  
    vector<int> leftView(Node *root) 
    {
        vector<int> ans;
        solve(root,ans,0);
        return ans;
    }
};