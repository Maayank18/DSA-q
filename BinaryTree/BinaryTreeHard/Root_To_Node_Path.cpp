// This problem basically aims to provide us a tree and a node value
// WHAT we have to do is that , we have to return the path from root of tree
// to that particular node 

/*
    This program finds the path from the root to a given node in a binary tree.

    Example Binary Tree:
    
            1
           / \
          2   3
         / \  / \
        4   5 6  7

    Suppose we want to find the path to node `5`, the output will be:
    Path from root to node 5: [1, 2, 5]

    Explanation:
    - Start from the root (1) and check if it's the target (5). It's not.
    - Move to the left subtree (2) and check if it's the target. It's not.
    - Move to the left child (4), but 4 is not the target, so backtrack.
    - Move to the right child (5), which is the target, so we store the path [1, 2, 5].
    - If the target is not found in a subtree, we backtrack (remove nodes from the path).
    - This approach ensures we find the root-to-node path efficiently.
*/

#include <iostream>
#include <vector>

using namespace std;

// Definition of a TreeNode (Binary Tree Node)
struct TreeNode {
    int val;             // Value of the node
    TreeNode* left;      // Pointer to the left child
    TreeNode* right;     // Pointer to the right child
    
    // Constructor to initialize the node with a value
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
    Function to find the path from the root to a given target node.
    
    - This function uses recursion to check each node.
    - If the node is found, we store the path in a vector.
    - If the node is not found in a subtree, we backtrack (remove the node from the path).
    
    Parameters:
    - root: Pointer to the current node in the binary tree.
    - path: Vector to store the path from root to target node.
    - target: The value of the node we are searching for.
    
    Returns:
    - true if the target node is found, false otherwise.
*/
bool findPath(TreeNode* root, vector<int>& path, int target) {
    if (root == NULL) return false; // If tree is empty or end of path reached, return false

    path.push_back(root->val); // Add current node to the path

    if (root->val == target) return true; // If the current node is the target, return true

    // Recur for left and right children
    if (findPath(root->left, path, target) || findPath(root->right, path, target))
        return true; // If the target is found in either subtree, return true

    // If the target is not found in the current path, remove this node (backtracking)
    path.pop_back();
    return false;
}

/*
    Function to get the path from root to a specific node.

    - Calls the recursive function `findPath()` to fill the path.
    - If the target node exists, it returns the path as a vector.
    - If the node does not exist in the tree, it returns an empty vector.

    Parameters:
    - root: Pointer to the root of the binary tree.
    - target: The value of the node we want to find.

    Returns:
    - A vector containing the path from root to the target node.
*/
vector<int> rootToNodePath(TreeNode* root, int target) {
    vector<int> path;
    if (findPath(root, path, target)) return path; // Return the found path
    return {}; // Return an empty vector if target node is not found
}

// Utility function to create a sample binary tree
TreeNode* createTree() {
    /*
        Binary Tree Structure:

                1
               / \
              2   3
             / \  / \
            4   5 6  7
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = createTree(); // Create the sample tree
    int target = 5; // Node we want to find the path to

    vector<int> path = rootToNodePath(root, target); // Get the root-to-node path

    // Display the path from root to the target node
    if (!path.empty()) {
        cout << "Path from root to node " << target << ": ";
        for (int val : path)
            cout << val << " ";
    } else {
        cout << "Node not found in the tree.";
    }

    return 0;
}
