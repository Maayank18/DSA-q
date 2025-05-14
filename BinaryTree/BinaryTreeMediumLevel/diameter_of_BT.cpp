// BRUTE FORCE APPROACH                               
#include <iostream>
#include <algorithm>

using namespace std;

// Node structure for
// the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

int height(Node * root){
    if( root == NULL) return 0;
    return 1+max(height(root->left), height(root->right));
}

int calculating_diamter(Node * root){
    if(root == NULL) return 0;

    int leftheight = height(root->left);
    int rightheight = height(root->right);

    int diameter = leftheight + rightheight;

    int leftdiamter = calculating_diamter(root->left);
    int rightdiameter = calculating_diamter(root->right);

    return max(diameter,max(leftdiamter,rightdiameter));
}

// Main function
int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    // Creating an instance of the Solution class

    // Calculate the diameter of the binary tree
    int diameter = calculating_diamter(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}


// OPTIMAL APPROACH 

                                
#include <iostream>
#include <algorithm>  // For max()
using namespace std;

// Definition of a TreeNode
struct Node {
    int val;
    Node* left;
    Node* right;

    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to calculate the height of the tree and update the diameter
int height(Node* node, int &diameter) {
    if (node == nullptr) {
        return 0;
    }

    // Recursively compute the height of left and right subtrees
    int lh = height(node->left, diameter);
    int rh = height(node->right, diameter);

    // Update the diameter with the maximum of current diameter or sum of left and right heights
    diameter = max(diameter, lh + rh);

    // Return the height of the current node's subtree
    return 1 + max(lh, rh);
}

// Function to compute the diameter of the binary tree
int diameterOfBinaryTree(Node* root) {
    int diameter = 0;
    height(root, diameter); // Call height function to update diameter
    return diameter;
}

// Driver Code
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    cout << "Diameter of the tree: " << diameterOfBinaryTree(root) << endl;

    return 0;
}

                                
                            
                                
                            