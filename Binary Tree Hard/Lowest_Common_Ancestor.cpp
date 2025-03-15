// BRUTE FORCE SOLUTION 

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
    Function to find the path from root to a given node.
    
    - If the target node is found, store the path and return true.
    - If not found in the current node, check in left and right subtrees.
    - If not found in either subtree, remove the node (backtracking).
    
    Parameters:
    - root: Pointer to the current node in the binary tree.
    - path: Vector to store the path from root to target node.
    - target: The value of the node we are searching for.

    Returns:
    - true if the target node is found, false otherwise.
*/
bool findPath(TreeNode* root, vector<TreeNode*>& path, int target) {
    if (root == NULL) return false; // If tree is empty or end of path reached

    path.push_back(root); // Add current node to the path

    if (root->val == target) return true; // If target found, return true

    // Recur in left and right subtrees
    if (findPath(root->left, path, target) || findPath(root->right, path, target))
        return true; // If target is found in subtree, return true

    // If not found, remove the current node from path (backtracking)
    path.pop_back();
    return false;
}

/*
    Function to find the Lowest Common Ancestor (LCA) using the path comparison method.

    Steps:
    - Get the path from the root to node `p`.
    - Get the path from the root to node `q`.
    - Compare the paths to find the last common node.

    Parameters:
    - root: Pointer to the root of the binary tree.
    - p, q: Values of the two nodes whose LCA needs to be found.

    Returns:
    - Pointer to the LCA node.
*/
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    vector<TreeNode*> path1, path2;

    // Get paths from root to p and q
    if (!findPath(root, path1, p) || !findPath(root, path2, q)) {
        return NULL; // If either node is not found, return NULL
    }

    // Compare both paths to find the last common node
    int i = 0;
    while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) {
        i++;
    }

    return path1[i - 1]; // Last common node is the LCA
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

    int node1 = 4, node2 = 5; // Nodes whose LCA is needed

    TreeNode* lca = lowestCommonAncestor(root, node1, node2);

    if (lca) {
        cout << "Lowest Common Ancestor of " << node1 << " and " << node2 << " is: " << lca->val << endl;
    } else {
        cout << "Nodes not found in the tree." << endl;
    }

    return 0;
}




// OPTIMAL SOLUTION 

#include <iostream>

using namespace std;

// Definition of a TreeNode (Binary Tree Node)
struct TreeNode {
    int val;             // Value of the node
    TreeNode* left;      // Pointer to the left child
    TreeNode* right;     // Pointer to the right child
    
    // Constructor to initialize the node with a value
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    /*
        Function to find the Lowest Common Ancestor (LCA) of two nodes in a Binary Tree.

        - If either `p` or `q` is found at the root, return root (Base Case).
        - Recur on left and right subtrees.
        - If both left and right return non-null values, root is the LCA.
        - Otherwise, return the non-null child (if only one side has a valid LCA).

        Time Complexity: O(N)  [Traverses each node once]
        Space Complexity: O(H) [Recursion stack, where H = height of the tree]
    */
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: If root is NULL, or if root is one of the nodes (p or q), return root
        if (root == NULL || root == p || root == q) {
            return root;
        }

        // Recursively search in left and right subtrees
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // Case 1: If both left and right return non-null, root is the LCA
        if (leftLCA != NULL && rightLCA != NULL) {
            return root;
        }

        // Case 2: If one side returns NULL, return the non-null side
        return (leftLCA != NULL) ? leftLCA : rightLCA;
    }
};

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

    Solution solution; // Create an instance of the Solution class

    TreeNode* node1 = root->left->left;  // Node 4
    TreeNode* node2 = root->left->right; // Node 5

    TreeNode* lca = solution.lowestCommonAncestor(root, node1, node2);

    if (lca) {
        cout << "Lowest Common Ancestor of " << node1->val << " and " << node2->val << " is: " << lca->val << endl;
    } else {
        cout << "Nodes not found in the tree." << endl;
    }

    return 0;
}
