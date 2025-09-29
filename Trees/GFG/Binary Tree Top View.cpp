/*
Top View of Binary Tree     --      https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1

You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note:

Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only.
Examples:

Input: root[] = [1, 2, 3]

Output: [2, 1, 3]
Input: root[] = [10, 20, 30, 40, 60, 90, 100]

Output: [40, 20, 10, 30, 100]
Explanation: The root 10 is visible.
On the left, 40 is the leftmost node and visible, followed by 20.
On the right, 30 and 100 are visible. Thus, the top view is 40 20 10 30 100.
Input: root[] = [1, 2, 3, N, 4, N, N, N, 5, N, 6]
       1
     /   \
    2     3
     \
      4
       \
        5
         \
          6
Output: [2, 1, 3, 6]
Explanation: Node 1 is the root and visible.
Node 2 is the left child and visible from the left side.
Node 3 is the right child and visible from the right side.
Nodes 4, 5, and 6 are vertically aligned, but only the lowest node 6 is visible from the top view. Thus, the top view is 2 1 3 6.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105
*/
#include <map>
#include <vector>
#include <queue>
#include "Node.h"
using namespace std;
class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // BFS
        if (root == NULL)
            return {};

        // Queue<pair<node,distance from root>>
        queue<pair<Node *, int>> BFS;
        // map<distance,node value>
        map<int, int> mp;

        BFS.push({root, 0});

        while (!BFS.empty())
        {
            auto it = BFS.front();
            BFS.pop();
            Node *node = it.first;

            int distance = it.second;           // Distance between nodes
            if (mp.find(it.second) == mp.end()) // Element not Found. Only add if not found
            {
                mp[distance] = it.first->data;
            }

            if (node->left != NULL)
                BFS.push({node->left, distance - 1});
            if (node->right != NULL)
                BFS.push({node->right, distance + 1});
        }

        vector<int> ans;
        for (auto m : mp)
            ans.push_back(m.second);
        return ans;
    }
};