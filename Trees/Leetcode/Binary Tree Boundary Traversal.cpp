#include"Tree.h"
#include<vector>
using namespace std;

/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    // Utility function to check if a node is a leaf (no children)
    bool isLeafNode(Node* node)
    {
        return (node->left == NULL && node->right == NULL);
    }
    
    // Traverse the left boundary (excluding leaf nodes)
    void leftTraversal(Node* root, vector<int>& ans)
    {
        Node* node = root;
        if(node == NULL)
            return;
            
        // Keep going down until no more left/right children
        while(node != NULL)
        {
            // Add non-leaf node values
            if(!isLeafNode(node))
                ans.push_back(node->data);
                
            // Prefer left child if available, otherwise go right
            if(node->left != NULL)
                node = node->left;
            else
                node = node->right;
        }
    }
    
    // Traverse all the leaf nodes in left-to-right order
    void addLeaves(Node* root, vector<int>& ans)
    {
        if(isLeafNode(root))
        {
            ans.push_back(root->data);
            return;
        }
        
        // Recurse on left subtree
        if(root->left != NULL)
            addLeaves(root->left, ans);
        
        // Recurse on right subtree
        if(root->right != NULL)
            addLeaves(root->right, ans);
    }
    
    // Traverse the right boundary (excluding leaf nodes)
    void rightTraversal(Node* node, vector<int>& ans)
    {
        // Stack to store nodes (so we can reverse later)
        stack<int> temp;
        
        while(node != NULL)
        {
            // Add non-leaf nodes to stack
            if(!isLeafNode(node))
                temp.push(node->data);
            
            // Prefer right child if available, otherwise go left
            if(node->right != NULL)
                node = node->right;
            else
                node = node->left;
        }
        
        // Pop from stack to get correct bottom-to-top order
        while(!temp.empty())
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
