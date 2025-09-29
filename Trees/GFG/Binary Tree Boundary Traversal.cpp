/*
Binary Tree Boundary Traversal      --      https://www.geeksforgeeks.org/boundary-traversal-of-binary

Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:

Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.

Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary.

Examples:

Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
Output: [1, 2, 4, 8, 9, 6, 7, 3]
Explanation:

Input: root[] = [1, N, 2, N, 3, N, 4, N, N]
Output: [1, 4, 3, 2]
Explanation:

Left boundary: [1] (as there is no left subtree)
Leaf nodes: [4]
Right boundary: [3, 2] (in reverse order)
Final traversal: [1, 4, 3, 2]
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

*/

#include "Node.h"
#include <vector>
#include<stack>
using namespace std;

class Solution
{
public:
    // Utility function to check if a node is a leaf (no children)
    bool isLeafNode(Node *node)
    {
        return (node->left == NULL && node->right == NULL);
    }

    // Traverse the left boundary (excluding leaf nodes)
    void leftTraversal(Node *root, vector<int> &ans)
    {
        Node *node = root;
        if (node == NULL)
            return;

        // Keep going down until no more left/right children
        while (node != NULL)
        {
            // Add non-leaf node values
            if (!isLeafNode(node))
                ans.push_back(node->data);

            // Prefer left child if available, otherwise go right
            if (node->left != NULL)
                node = node->left;
            else
                node = node->right;
        }
    }

    // Traverse all the leaf nodes in left-to-right order
    void addLeaves(Node *root, vector<int> &ans)
    {
        if (isLeafNode(root))
        {
            ans.push_back(root->data);
            return;
        }

        // Recurse on left subtree
        if (root->left != NULL)
            addLeaves(root->left, ans);

        // Recurse on right subtree
        if (root->right != NULL)
            addLeaves(root->right, ans);
    }

    // Traverse the right boundary (excluding leaf nodes)
    void rightTraversal(Node *node, vector<int> &ans)
    {
        // Stack to store nodes (so we can reverse later)
        stack<int> temp;

        while (node != NULL)
        {
            // Add non-leaf nodes to stack
            if (!isLeafNode(node))
                temp.push(node->data);

            // Prefer right child if available, otherwise go left
            if (node->right != NULL)
                node = node->right;
            else
                node = node->left;
        }

        // Pop from stack to get correct bottom-to-top order
        while (!temp.empty())
        {
            ans.push_back(temp.top());
            temp.pop();
        }
    }

    vector<int> boundaryTraversal(Node *root)
    {
        vector<int> ans;

        if (root == NULL)
            return ans;

        if (!isLeafNode(root))
            ans.push_back(root->data);

        leftTraversal(root->left, ans);

        addLeaves(root, ans);

        rightTraversal(root->right, ans);

        return ans;
    }
};
