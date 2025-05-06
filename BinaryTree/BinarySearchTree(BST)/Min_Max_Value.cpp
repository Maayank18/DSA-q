// ITERATIVE SOLUTION 

#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    
    Node(int val) {
        value = val;
        left = right = NULL;
    }
};

// Function to find the minimum value in BST (Iterative)
int minValue(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return -1; // Assuming -1 is an invalid value
    }
    while (root->left != NULL) {
        root = root->left;
    }
    return root->value;
}

// Function to find the maximum value in BST (Iterative)
int maxValue(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return -1; // Assuming -1 is an invalid value
    }
    while (root->right != NULL) {
        root = root->right;
    }
    return root->value;
}

int main() {
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(5);
    root->left->right = new Node(12);
    root->right->right = new Node(25);

    cout << "Minimum Value: " << minValue(root) << endl;
    cout << "Maximum Value: " << maxValue(root) << endl;

    return 0;
}




// RECURSIVE SOLUTION 


#include <iostream>
using namespace std;

// Structure for a BST Node
struct Node {
    int value;
    Node* left;
    Node* right;
    
    Node(int val) {
        value = val;
        left = right = NULL;
    }
};

// Recursive function to find the minimum value in BST
int minValueRecursive(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return -1; // Assuming -1 is an invalid value
    }
    if (root->left == NULL) return root->value;
    return minValueRecursive(root->left);
}

// Recursive function to find the maximum value in BST
int maxValueRecursive(Node* root) {
    if (root == NULL) {
        cout << "Tree is empty!" << endl;
        return -1; // Assuming -1 is an invalid value
    }
    if (root->right == NULL) return root->value;
    return maxValueRecursive(root->right);
}

int main() {
    Node* root = new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(5);
    root->left->right = new Node(12);
    root->right->right = new Node(25);

    cout << "Minimum Value (Recursive): " << minValueRecursive(root) << endl;
    cout << "Maximum Value (Recursive): " << maxValueRecursive(root) << endl;

    return 0;
}
