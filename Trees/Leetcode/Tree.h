/*
Definition of a Binary Tree Node
Each node contains:
- an integer value (val)
- a pointer to the left child (left)
- a pointer to the right child (right)
Constructors are provided to:
1. Create an empty node with value 0
2. Create a node with a specific value
3. Create a node with a value and attach left and right children
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
