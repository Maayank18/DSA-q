// Ceil of a number in BST is the smallest value greater than or equal to that number.

//            8
//           / \
//          4   12
//        / \   / \
//       2   6 10 14

// ceil of value 5 is 6
  

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

// Function to find Ceil in BST (Iterative)
int CeilValue(Node* root, int target) {
    int ceil = -1; // Default value if ceil doesn't exist

    while (root) {
        if (root->value == target)
            return root->value; // If exact match, return directly

        if (root->value > target) { 
            ceil = root->value; // Update possible ceil
            root = root->left;  // Move left to find a smaller valid ceil
        } else {
            root = root->right; // Move right if target is greater
        }
    }
    return ceil; // Return the stored ceil value
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
    cout << "Ceil of " << target << " is: " << CeilValue(root, target) << endl;

    return 0;
}
