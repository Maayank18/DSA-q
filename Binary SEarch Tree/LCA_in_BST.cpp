#include <iostream>
using namespace std;

// Definition of a node in the BST
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int val) {
        value = val;
        left = right = NULL;
    }
};

// Function to find the Lowest Common Ancestor (LCA)
Node* LowestCommonAncestor(Node* root, Node* p, Node* q) {
    if (root == NULL) {
        return NULL;
    }

    int currentValue = root->value;

    // If both p and q are greater, search in the right subtree
    if (currentValue < p->value && currentValue < q->value) {
        return LowestCommonAncestor(root->right, p, q);
    }

    // If both p and q are smaller, search in the left subtree
    if (currentValue > p->value && currentValue > q->value) {
        return LowestCommonAncestor(root->left, p, q);
    }

    // If we reach here, this is the Lowest Common Ancestor
    return root;
}

// Function to insert a node in BST
Node* insert(Node* root, int value) {
    if (root == NULL) {
        return new Node(value);
    }

    if (value < root->value) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

// Driver code to test LCA function
int main() {
    Node* root = NULL;
    
    // Insert nodes into BST
    root = insert(root, 20);
    root = insert(root, 10);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 35);

    Node* p = root->left->left;  // Node with value 5
    Node* q = root->left->right; // Node with value 15

    Node* lca = LowestCommonAncestor(root, p, q);

    cout << "Lowest Common Ancestor of " << p->value << " and " << q->value << " is: " << lca->value << endl;

    return 0;
}
