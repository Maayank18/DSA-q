#include <iostream>
#include <climits>
using namespace std;

// Definition of a Node in the BST
struct node {
    int value;
    node* left;
    node* right;
    
    node(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
};

// Helper function to validate BST using inorder traversal
bool isBSTUtil(node* root, long long minVal, long long maxVal) {
    if (root == NULL) return true;

    // Check if current node violates the BST property
    if (root->value <= minVal || root->value >= maxVal) {
        return false;
    }

    // Recursively check left and right subtrees with updated min/max range
    return isBSTUtil(root->left, minVal, root->value) &&
           isBSTUtil(root->right, root->value, maxVal);
}

// Function to check if a tree is a valid BST
bool isValidBST(node* root) {
    return isBSTUtil(root, LLONG_MIN, LLONG_MAX);
}

// Driver Code
int main() {
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);

    if (isValidBST(root)) {
        cout << "The tree is a valid BST." << endl;
    } else {
        cout << "The tree is NOT a valid BST." << endl;
    }

    return 0;
}
