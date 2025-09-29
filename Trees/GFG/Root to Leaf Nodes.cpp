/*

Root to Leaf Path Nodes         --          https://www.geeksforgeeks.org/problems/root-to-leaf-paths/1

Given a Binary Tree, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

Note: The paths should be returned such that paths from the left subtree of any node are listed first, followed by paths from the right subtree.

Examples:

Input: root[] = [1, 2, 3, 4, 5, N, N]
ex-3
Output: [[1, 2, 4], [1, 2, 5], [1, 3]]
Explanation: All the possible paths from root node to leaf nodes are: 1 -> 2 -> 4, 1 -> 2 -> 5 and 1 -> 3
Input: root[] = [1, 2, 3]

Output: [[1, 2], [1, 3]]
Explanation: All the possible paths from root node to leaf nodes are: 1 -> 2 and 1 -> 3
Input: root[] = [10, 20, 30, 40, 60, N, N]

Output: [[10, 20, 40], [10, 20, 60], [10, 30]]
Explanation: All the possible paths from root node to leaf nodes are: 10 -> 20 -> 40, 10 -> 20 -> 60 and 10 -> 30
Constraints:
1 <= number of nodes <= 104
1 <= node->data <= 104
*/

#include "Node.h"
#include <vector>
using namespace std;
class Solution
{
public:
    bool isLeafNode(Node *node)
    {
        return (node->left == NULL && node->right == NULL);
    }

    void solve(Node *node, vector<int> &nodes, vector<vector<int>> &ans)
    {

        if (node == NULL)
            return;

        nodes.push_back(node->data);

        if (isLeafNode(node))
            ans.push_back(nodes); // If it's a leaf node, add the current path to the answer
        else
        {
            solve(node->left, nodes, ans);  // Solve for left subtree
            solve(node->right, nodes, ans); // Solve for right subtree
        }
        nodes.pop_back(); //  Backtracking step
    }
    vector<vector<int>> Paths(Node *root)
    {
        if (root == NULL)
            return {};

        vector<vector<int>> ans;
        vector<int> nodes;
        solve(root, nodes, ans);
        return ans;
    }
};