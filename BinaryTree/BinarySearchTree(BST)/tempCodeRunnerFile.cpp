#include <iostream>
// using namespace std;

// // Definition of a Node in the BST
// struct node {
//     int value;
//     node* left;
//     node* right;
    
//     node(int val) {
//         value = val;
//         left = NULL;
//         right = NULL;
//     }
// };

// // Helper function for Inorder Traversal
// void inorderTraversal(node* root, int& k, int& result) {
//     if (root == NULL || k <= 0) return;

//     // Traverse left subtree
//     inorderTraversal(root->left, k, result);

//     // Process current node
//     k--; // Decrement k (count elements)
//     if (k == 0) {
//         result = root->value;
//         return; // Stop further recursion
//     }

//     // Traverse right subtree
//     inorderTraversal(root->right, k, result);
// }

// // Function to find the k-th smallest element
// int findKthSmallest(node* root, int k) {
//     int result = -1; // Default value if k is invalid
//     inorderTraversal(root, k, result);
//     return result;
// }

// // Driver Code
// int main() {
//     // Creating BST
//     node* root = new node(5);
//     root->left = new node(3);
//     root->right = new node(7);
//     root->left->left = new node(2);
//     root->left->right = new node(4);
//     root->right->left = new node(6);
//     root->right->right = new node(8);

//     int k = 3; // Find the 3rd smallest element
//     cout << "The " << k << "rd smallest element is: " << findKthSmallest(root, k) << endl;

//     return 0;
// }
