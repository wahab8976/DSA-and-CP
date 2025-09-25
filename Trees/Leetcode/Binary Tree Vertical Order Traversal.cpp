#include"Tree.h"
#include<vector>
#include<map>
#include<queue>
using namespace std;

class Solution 
{
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        // Queue for BFS traversal
        // Each element: {node, {col, row}}
        // col = vertical index (left = -1, right = +1)
        // row = depth/level of the node
        queue<pair<TreeNode*,pair<int,int>>> BFS;

        // Nested map to store nodes:
        // col -> row -> multiset of node values
        // multiset is used to keep sorted values when multiple nodes share same (col,row)
        map<int,map<int,multiset<int>>> nodes; 

        if(root == NULL)
            return {};
        
        // Start BFS with root at column=0, row=0
        BFS.push({root,{0,0}});

        while(!BFS.empty())
        {
            auto it = BFS.front();
            BFS.pop();

            TreeNode* node = it.first;
            int col = it.second.first;   // vertical position
            int row = it.second.second;  // level/depth

            // Insert current node value into our structure
            nodes[col][row].insert(node->val);

            // Left child: move one column left (col-1), one row deeper (row+1)
            if(node->left != NULL)
                BFS.push({node->left,{col - 1,row + 1}});
            
            // Right child: move one column right (col+1), one row deeper (row+1)
            if(node->right != NULL)
                BFS.push({node->right,{col + 1,row + 1}});
        }

        // Collect results column by column
        vector<vector<int>> ans;
        for(auto& colPair : nodes) 
        {
            vector<int> colNodes;
            // Traverse rows in increasing order (top to bottom)
            for(auto& rowPair : colPair.second) 
            {
                // Insert all values (sorted automatically by multiset)
                colNodes.insert(colNodes.end(), rowPair.second.begin(), rowPair.second.end());
            }
            ans.push_back(colNodes);
        }
        
        return ans;
    }
};
