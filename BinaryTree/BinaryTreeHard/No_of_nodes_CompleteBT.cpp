#include <iostream>
#include <cmath> // For pow() function

using namespace std;

// Definition of a Tree Node
struct Node { 
    int data; 
    Node *left, *right;
    
    // Constructor to initialize a node
    Node(int val) : data(val), left(NULL), right(NULL) {} 
};

// Function to calculate the height of the leftmost path of the tree
int FindHeightLeft(Node* root) {
    int height = 0;
    while (root) { // Traverse down the left children
        height++;
        root = root->left;
    }
    return height; // Returns the height of the left subtree
}

// Function to calculate the height of the rightmost path of the tree
int FindHeightRight(Node* root) {
    int height = 0;
    while (root) { // Traverse down the right children
        height++;
        root = root->right;
    }
    return height; // Returns the height of the right subtree
}

// Function to count the number of nodes in a complete binary tree
int NumberNodesInCompleteBT(Node* root) {
    if (root == NULL) return 0; // Base case: Empty tree has 0 nodes

    // Find the leftmost and rightmost heights of the tree
    int leftHeight = FindHeightLeft(root);
    int rightHeight = FindHeightRight(root);

    // If left and right heights are equal, it means the tree is a perfect binary tree
    if (leftHeight == rightHeight) 
        return (1 << leftHeight) - 1; // 2^h - 1 nodes in a perfect binary tree

    // If not a perfect tree, count nodes recursively in left and right subtrees
    return 1 + NumberNodesInCompleteBT(root->left) + NumberNodesInCompleteBT(root->right);
}

// Function to create a sample complete binary tree for testing
Node* CreateSampleTree() {
    /* Example Tree:
              1
             / \
            2   3
           / \  /
          4   5 6
    */
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    
    return root;
}

// Driver Code
int main() {
    Node* root = CreateSampleTree(); // Create a sample complete binary tree
    
    cout << "Total number of nodes in the complete binary tree: " 
         << NumberNodesInCompleteBT(root) << endl;

    return 0;
}



// BRUTE FORCE -> using any of the simpest traversal counting each and every node 

#include <iostream>

using namespace std;

// Definition of a Tree Node
struct Node { 
    int data; 
    Node *left, *right;
    
    // Constructor to initialize a node
    Node(int val) : data(val), left(NULL), right(NULL) {} 
};

// Brute Force Function to Count Total Nodes (Simple Traversal)
int CountNodes(Node* root) {
    if (root == NULL) return 0; // Base case: No node
    
    // Count the current node + left subtree nodes + right subtree nodes
    return 1 + CountNodes(root->left) + CountNodes(root->right);
}

// Function to create a sample complete binary tree for testing
Node* CreateSampleTree() {
    /* Example Tree:
              1
             / \
            2   3
           / \  /
          4   5 6
    */
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    
    return root;
}

// Driver Code
int main() {
    Node* root = CreateSampleTree(); // Create a sample complete binary tree
    
    cout << "Total number of nodes in the complete binary tree: " 
         << CountNodes(root) << endl;

    return 0;
}
