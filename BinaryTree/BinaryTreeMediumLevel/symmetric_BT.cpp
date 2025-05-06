#include <iostream>

using namespace std;

// Definition of a Binary Tree Node
struct TreeNode {
    int val;               // Value of the node
    TreeNode* left;        // Pointer to left child
    TreeNode* right;       // Pointer to right child
    
    // Constructor to initialize node with value
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check if two trees are mirror images of each other
bool isMirror(TreeNode* t1, TreeNode* t2) {
    // If both subtrees are NULL, they are mirrors
    if (!t1 && !t2) return true;

    // If one of them is NULL but the other is not, they are not mirrors
    if (!t1 || !t2) return false;

    // Check three conditions:
    // 1. The values of the current nodes must be the same.
    // 2. The left subtree of the first tree must be a mirror of the right subtree of the second tree.
    // 3. The right subtree of the first tree must be a mirror of the left subtree of the second tree.
    return (t1->val == t2->val) && 
           isMirror(t1->left, t2->right) && 
           isMirror(t1->right, t2->left);
}

// Function to check if a tree is symmetric (a mirror of itself)
bool isSymmetric(TreeNode* root) {
    if (!root) return true; // An empty tree is symmetric by default
    return isMirror(root->left, root->right);
}

// Driver Code
int main() {
    /*
       Constructing the following symmetric binary tree:
        
               1
              / \
             2   2
            / \ / \
           3  4 4  3
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    // Checking if the tree is symmetric
    if (isSymmetric(root))
        cout << "The tree is symmetric." << endl;
    else
        cout << "The tree is not symmetric." << endl;

    return 0;
}
