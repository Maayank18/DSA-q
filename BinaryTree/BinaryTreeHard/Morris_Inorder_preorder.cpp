#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Morris Inorder Traversal
void morrisInorder(TreeNode* root) {
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            // If no left child, print current node and move right
            cout << curr->val << " ";
            curr = curr->right;
        } else {
            // Find the inorder predecessor (rightmost node in left subtree)
            TreeNode* pred = curr->left;
            while (pred->right != nullptr && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == nullptr) {
                // Make a thread (temporary link) from predecessor to current node
                pred->right = curr;
                curr = curr->left;
            } else {
                // If thread exists, remove it and print current node
                pred->right = nullptr;
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
}

// Main function to test Morris Inorder
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Morris Inorder Traversal: ";
    morrisInorder(root);
    cout << endl;

    return 0;
}





// PREORDER 

#include <iostream>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Morris Preorder Traversal
void morrisPreorder(TreeNode* root) {
    TreeNode* curr = root;

    while (curr != nullptr) {
        if (curr->left == nullptr) {
            // Print the current node and move right
            cout << curr->val << " ";
            curr = curr->right;
        } else {
            // Find the inorder predecessor (rightmost node in left subtree)
            TreeNode* pred = curr->left;
            while (pred->right != nullptr && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == nullptr) {
                // Make a thread from predecessor to current node
                cout << curr->val << " ";  // Print before moving left
                pred->right = curr;
                curr = curr->left;
            } else {
                // If thread exists, remove it
                pred->right = nullptr;
                curr = curr->right;
            }
        }
    }
}

// Main function to test Morris Preorder
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << "Morris Preorder Traversal: ";
    morrisPreorder(root);
    cout << endl;

    return 0;
}
