#include <iostream>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to modify the tree to satisfy the Children Sum Property
void ChangeTheTree(Node* root) {
    if (root == NULL) {
        return;
    }

    int child = 0;

    if (root->left) {
        child += root->left->data;
    }

    if (root->right) {
        child += root->right->data;
    }

    // Update root's data if needed
    if (child >= root->data) {
        root->data = child;
    } else {
        if (root->left) root->left->data = root->data;
        if (root->right) root->right->data = root->data;
    }

    // Recursive calls
    ChangeTheTree(root->left);
    ChangeTheTree(root->right);

    // Ensure the root has the correct sum after recursion
    int total = 0;
    if (root->left) total += root->left->data;
    if (root->right) total += root->right->data;

    if (root->left || root->right) root->data = total;
}

// Function to perform Inorder Traversal
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Driver Code
int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(20);
    root->left->left = new Node(10);
    root->left->right = new Node(15);
    root->right->right = new Node(10);

    cout << "Inorder Traversal before transformation: ";
    inorderTraversal(root);
    cout << endl;

    ChangeTheTree(root);

    cout << "Inorder Traversal after transformation: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}








// BRUTE FORCE BASIC APPROACH 

#include <iostream>
using namespace std;

// Definition of the Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to check if the Children Sum Property holds
bool checkChildrenSum(Node* root) {
    if (!root) return true;
    if (!root->left && !root->right) return true;

    int childSum = 0;
    if (root->left) childSum += root->left->data;
    if (root->right) childSum += root->right->data;

    return (root->data == childSum) && checkChildrenSum(root->left) && checkChildrenSum(root->right);
}

// Brute force approach: Keep updating the tree until it satisfies the Children Sum Property
void bruteForceChangeTree(Node* root) {
    if (root == NULL) return;

    while (!checkChildrenSum(root)) {  // Keep updating until the tree satisfies the condition
        if (root->left) bruteForceChangeTree(root->left);
        if (root->right) bruteForceChangeTree(root->right);

        int childSum = 0;
        if (root->left) childSum += root->left->data;
        if (root->right) childSum += root->right->data;

        if (childSum > root->data) {
            root->data = childSum;  // Update root's value to the sum of its children
        }
    }
}

// Function to perform Inorder Traversal
void inorderTraversal(Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// Driver Code
int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(20);
    root->left->left = new Node(10);
    root->left->right = new Node(15);
    root->right->right = new Node(10);

    cout << "Inorder Traversal before transformation: ";
    inorderTraversal(root);
    cout << endl;

    bruteForceChangeTree(root);

    cout << "Inorder Traversal after transformation: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
