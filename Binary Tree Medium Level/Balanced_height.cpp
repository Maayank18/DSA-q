// What does balanced height means 
// at every given node the | height(left) - height(right) |  <= 1
// otherwise the tree is considered to be inbalanced 
//                    1
//                   / \
//                  2   3
//                 / \    \
//                4   5    6
//                          \
//                           7
// Eg of not balanced 


#include <iostream>
#include <cmath>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check balance and return height
int checkBalance(TreeNode* root) {
    if (!root) return 0;  // Base case: empty tree has height 0

    int leftHeight = checkBalance(root->left);
    if (leftHeight == -1) return -1;  // Left subtree is not balanced

    int rightHeight = checkBalance(root->right);
    if (rightHeight == -1) return -1;  // Right subtree is not balanced

    if (abs(leftHeight - rightHeight) > 1) return -1;  // If unbalanced, return -1

    return max(leftHeight, rightHeight) + 1;  // Return height of current node
}

// Function to check if the tree is balanced
bool isBalanced(TreeNode* root) {
    return checkBalance(root) != -1;
}

int main() {
    // Manually constructing the given binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    // Check if the tree is balanced
    if (isBalanced(root))
        cout << "The tree is balanced.\n";
    else
        cout << "The tree is not balanced.\n";

    return 0;
}
