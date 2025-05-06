#include <iostream>
using namespace std;

/**
 * Time Complexity: O(N) 
 * - We perform an inorder traversal, which takes O(N) time.
 * 
 * Space Complexity: O(1) 
 * - We only use a few pointers (first, middle, last, prevNode), so extra space usage is constant.
 * - The recursion stack space (O(H), where H is the height of the tree) is ignored in worst-case analysis.
 */

// Definition of a TreeNode
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Global pointers to track misplaced nodes
TreeNode *first = NULL, *middle = NULL, *last = NULL, *prevNode = NULL;

/**
 * Function to perform inorder traversal and detect swapped nodes
 * @param root - pointer to the current node
 */
void inorder(TreeNode* root) {
    if (!root) return;  // Base case: return if node is NULL

    // Recursive inorder traversal on left subtree
    inorder(root->left);

    // Detect misplaced nodes in inorder sequence
    if (prevNode && prevNode->val > root->val) {  
        if (!first) {  
            // First occurrence of a misplaced node
            first = prevNode;
            middle = root;
        } else {  
            // Second occurrence of a misplaced node
            last = root;
        }
    }
    prevNode = root;  // Move prevNode forward for next comparison

    // Recursive inorder traversal on right subtree
    inorder(root->right);
}

/**
 * Function to recover the BST by swapping misplaced nodes
 */
void recoverTree(TreeNode* root) {
    // Reset global pointers before traversal
    first = middle = last = prevNode = NULL;

    // Perform inorder traversal to find the swapped nodes
    inorder(root);

    // Swap the incorrect nodes to fix the BST
    if (first && last) {
        swap(first->val, last->val);  // Case: Non-adjacent swapped nodes
    }
    else if (first && middle) {
        swap(first->val, middle->val);  // Case: Adjacent swapped nodes
    }
}

/**
 * Helper function to print inorder traversal of BST
 * @param root - pointer to the root of the BST
 */
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Driver Code
int main() {
    // Creating a BST with two swapped nodes
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(2);  // Swapped nodes: 3 and 2

    // Print inorder traversal before recovery
    cout << "Inorder before recovery: ";
    printInorder(root);
    cout << endl;

    // Recover the BST
    recoverTree(root);

    // Print inorder traversal after recovery
    cout << "Inorder after recovery: ";
    printInorder(root);
    cout << endl;

    return 0;
}
