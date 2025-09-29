/*
Definition of a Binary Tree Node
Each node contains:
- an integer value (data)
- a pointer to the left child (left)
- a pointer to the right child (right)
Constructors are provided to:
1. Create an empty node with value 0
2. Create a node with a specific value
3. Create a node with a value and attach left and right children
*/

struct Node {
    int data;
    Node* left;
    Node* right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
