#include <iostream>
using namespace std;

// Structure for a BST Node
struct Node {
    int value;
    Node* left;
    Node* right;
    
    Node(int val) {  // Constructor to initialize a node
        value = val;
        left = right = NULL;
    }
};

// Function to insert a node into BST (Iterative)
Node* insertingNode(Node* root, int val) {
    if (root == NULL) 
        return new Node(val);  // If tree is empty, create the first node

    Node* current = root; // Pointer to traverse the tree

    while (true) {
        if (val <= current->value) { // If value is smaller, go left
            if (current->left != NULL) {
                current = current->left; // Move left
            } else {
                current->left = new Node(val); // Insert new node
                break; // Stop after insertion
            }
        } else { // If value is greater, go right
            if (current->right != NULL) {
                current = current->right; // Move right
            } else {
                current->right = new Node(val); // Insert new node
                break; // Stop after insertion
            }
        }
    }
    return root; // Always return the original root
}

// Function to print the BST in Inorder Traversal
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

// Driver Code
int main() {
    Node* root = NULL;
    root = insertingNode(root, 8);
    root = insertingNode(root, 4);
    root = insertingNode(root, 12);
    root = insertingNode(root, 2);
    root = insertingNode(root, 6);
    root = insertingNode(root, 10);
    root = insertingNode(root, 14);

    cout << "Inorder Traversal of BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
