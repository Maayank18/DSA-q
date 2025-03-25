#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    
    Node(int val) {
        value = val;
        left = right = NULL;
    }
};

// Function to find Floor in BST (Iterative)
int floor_Value(Node* root, int target) {
    int floor = -1; // Default value if floor doesn't exist

    while (root) {
        if (root->value == target) 
            return root->value; // Exact match found

        if (root->value < target) { 
            floor = root->value; // Update possible floor
            root = root->right;  // Move right to find a larger valid floor
        } else {
            root = root->left; // Move left if target is smaller
        }
    }
    return floor; // Return the stored floor value
}

// Driver Code
int main() {
    Node* root = new Node(8);
    root->left = new Node(4);
    root->right = new Node(12);
    root->left->left = new Node(2);
    root->left->right = new Node(6);
    root->right->left = new Node(10);
    root->right->right = new Node(14);

    int target = 5;
    cout << "Floor of " << target << " is: " << floor_Value(root, target) << endl;

    return 0;
}
