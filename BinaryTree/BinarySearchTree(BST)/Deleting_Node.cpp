#include <iostream>
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

// Function to find the rightmost node in the left subtree
node* findLastRight(node* root) {
    if (root->right == NULL) {
        return root;
    }
    return findLastRight(root->right);
}

// Helper function to delete a node and adjust the tree
node* helper(node* root) {
    if (root->left == NULL) return root->right; // Case 1: No left child
    if (root->right == NULL) return root->left; // Case 2: No right child
    
    node* RightChild = root->right;
    node* lastRight = findLastRight(root->left);
    lastRight->right = RightChild;
    return root->left;
}

// Function to delete a node from the BST
node* TreeAfterDeleting(node* root, int key) {
    if (root == NULL) return NULL;

    if (root->value == key) return helper(root);

    node* dummy = root;

    while (root != NULL) {
        if (root->value > key) {
            if (root->left && root->left->value == key) {
                root->left = helper(root->left);
                break;
            } else {
                root = root->left;
            }
        } else {
            if (root->right && root->right->value == key) {
                root->right = helper(root->right);
                break;
            } else {
                root = root->right;
            }
        }
    }
    return dummy;
}

// Function to insert a node into the BST
node* insert(node* root, int val) {
    if (root == NULL) return new node(val);
    
    if (val < root->value)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

// Function for inorder traversal (prints BST in sorted order)
void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

int main() {
    node* root = NULL;

    // Insert values into the BST
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    cout << "BST before deletion: ";
    inorder(root);
    cout << endl;

    // Deleting a node (e.g., 50)
    root = TreeAfterDeleting(root, 50);

    cout << "BST after deletion of 50: ";
    inorder(root);
    cout << endl;

    return 0;
}
