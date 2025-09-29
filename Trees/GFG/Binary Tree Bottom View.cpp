/*
Bottom View of Binary Tree      --      https://www.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

Given a binary tree, return an array where elements represent the bottom view of the binary tree from left to right.

Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the later one in the level order traversal is considered. For example, in the below diagram, 7 and 34 both are the bottommost nodes at a horizontal distance of 0 from the root, here 34 will be considered.

For the above tree, the output should be 5 8 34 22 25

Examples :

Input: root[] = [1, 3, 2]

Output: [3 1 2]
Explanation: First case represents a tree with 3 nodes and 2 edges where root is 1, left child of 1 is 3 and right child of 1 is 2.

Thus bottom view of the binary tree will be 3 1 2.
Input: root[] = [10, 20, 30, 40, 60]
         
Output: [40 20 60 30]
Constraints:
1 <= number of nodes <= 105
1 <= node->data <= 105

*/

#include"Node.h"
#include<vector>
#include<map>
#include<queue>
using namespace std;
class Solution {
  public:
    vector<int> bottomView(Node *root) 
    {
        if(root == NULL)
            return {};
            
        map<int,int> mp;    // map<distance,node value>
        queue<pair<Node*,int>> BFS; // Queue<pair<node,distance from root>>
        
        BFS.push({root,0});
        
        while(!BFS.empty())
        {
            auto it = BFS.front();
            BFS.pop();
            
            Node* node = it.first;  // Node from Queue
            int distance = it.second;   // Distance between nodes
            
            mp[distance] = node->data;  // Update the node at every distance
            
            if(node->left != NULL)
                BFS.push({node->left,distance - 1});
                
            if(node->right != NULL)
                BFS.push({node->right,distance + 1});
            
        }
        
        vector<int> ans;
        for(auto m : mp)
            ans.push_back(m.second);
        
        return ans;
    }
};