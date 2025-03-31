#include <iostream>
#include <climits>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Structure to store information about each subtree
class NodeValue {
public:
    int maxNode, minNode, maxSize;

    // Constructor to initialize values
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    // Helper function to find the largest BST in the tree
    NodeValue largestBSTSubtreeHelper(TreeNode* root) {
        // Base case: An empty tree is a BST of size 0
        if (!root) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // Get values from left and right subtree
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);

        // Check if current node forms a BST with left and right subtrees
        if (left.maxNode < root->val && root->val < right.minNode) {
            // It is a BST, update min, max, and size of subtree
            return NodeValue(
                min(root->val, left.minNode),
                max(root->val, right.maxNode),
                left.maxSize + right.maxSize + 1
            );
        }

        // If not a BST, return [-inf, inf] so the parent can't be a valid BST
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    // Function to return the size of the largest BST in the tree
    int largestBSTSubtree(TreeNode* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};

// Driver Code to test the function
int main() {
    // Constructing the binary tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7); // Invalid BST node

    Solution sol;
    cout << "Size of the Largest BST: " << sol.largestBSTSubtree(root) << endl;

    return 0;
}
