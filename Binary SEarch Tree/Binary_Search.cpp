#include <iostream>
using namespace std;

// Definition of a BST Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = NULL;
    }
};

// Function to search for a value in BST (Iterative)
bool searchBSTIterative(Node* root, int target) {
    while (root != NULL) {
        if (root->data == target)
            return true; // Found

        if (target < root->data)
            root = root->left; // Move to left subtree
        else
            root = root->right; // Move to right subtree
    }
    return false; // Not found
}

// Driver code
int main() {
    // Creating a sample BST manually
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->left->left = new Node(2);
    root->left->right = new Node(7);
    root->right->left = new Node(12);
    root->right->right = new Node(18);

    // Searching for elements
    int targets[] = {7, 20, 10, 18, 1};
    for (int target : targets) {
        if (searchBSTIterative(root, target))
            cout << "Element " << target << " found in BST" << endl;
        else
            cout << "Element " << target << " not found in BST" << endl;
    }

    return 0;
}
