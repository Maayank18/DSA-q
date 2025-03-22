#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// TreeNode structure to represent a node of the binary tree
struct TreeNode {
    int val;          // Stores the value of the node
    TreeNode *left;   // Pointer to the left child
    TreeNode *right;  // Pointer to the right child
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}  // Constructor to initialize node
};

class Solution {
public:
    // Function to build a binary tree from preorder and inorder traversals
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Map to store the index of each value in the inorder traversal for quick lookup
        unordered_map<int, int> inMap;

        // Populate the map with indices of elements in the inorder vector
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        }

        // Call the helper function to recursively build the tree
        return buildTreeHelper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    }

private:
    // Helper function to recursively build the tree
    TreeNode* buildTreeHelper(vector<int>& preorder, int preStart, int preEnd, 
                              vector<int>& inorder, int inStart, int inEnd, 
                              unordered_map<int, int>& inMap) {
        // Base case: If there are no elements left to process, return NULL
        if (preStart > preEnd || inStart > inEnd) {
            return nullptr;
        }

        // Create a new node with the current root value from the preorder traversal
        TreeNode* root = new TreeNode(preorder[preStart]);

        // Find the position of this root node in the inorder traversal
        int inRoot = inMap[root->val];

        // Calculate the number of elements in the left subtree
        int numsLeft = inRoot - inStart;

        // Recursively build the left subtree
        root->left = buildTreeHelper(preorder, preStart + 1, preStart + numsLeft, 
                                     inorder, inStart, inRoot - 1, inMap);

        // Recursively build the right subtree
        root->right = buildTreeHelper(preorder, preStart + numsLeft + 1, preEnd, 
                                      inorder, inRoot + 1, inEnd, inMap);

        // Return the current root node
        return root;
    }
};

// Function to print the inorder traversal of a tree
void printInorder(TreeNode* root) {
    if (!root) {
        return;
    }
    printInorder(root->left);  // Visit left subtree
    cout << root->val << " ";  // Print current node value
    printInorder(root->right); // Visit right subtree
}

// Function to print the given vector
void printVector(vector<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main() {
    // Given inorder and preorder traversals
    vector<int> inorder = {9, 3, 15, 20, 7};
    vector<int> preorder = {3, 9, 20, 15, 7};
    
    // Print the given vectors
    cout << "Inorder Vector: ";
    printVector(inorder);
    
    cout << "Preorder Vector: ";
    printVector(preorder);
    
    // Create Solution object
    Solution sol;

    // Build the tree
    TreeNode* root = sol.buildTree(preorder, inorder);
    
    // Print the inorder traversal of the constructed tree
    cout << "Inorder of Constructed Binary Tree: " << endl;
    printInorder(root);
    cout << endl;

    return 0;
}
