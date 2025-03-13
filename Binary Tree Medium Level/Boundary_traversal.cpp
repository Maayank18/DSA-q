#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to check if a node is a leaf node
bool leafNode(node* root) {
    return (root->left == nullptr && root->right == nullptr);
}

// Function to add left boundary (excluding leaf nodes)
void AddLeftBoundary(node* root, vector<int>& result) {
    node* currentNode = root->left;
    while (currentNode) {
        if (!leafNode(currentNode)) {
            result.push_back(currentNode->data);
        }
        if (currentNode->left) currentNode = currentNode->left;
        else currentNode = currentNode->right;
    }
}

// Function to add leaf nodes (only leaf nodes)
void AddLeafNodes(node* root, vector<int>& result) {
    if (root == nullptr) return;
    if (leafNode(root)) {
        result.push_back(root->data);
        return;
    }
    AddLeafNodes(root->left, result);
    AddLeafNodes(root->right, result);
}

// Function to add right boundary (excluding leaf nodes, stored in reverse order)
void AddRightNodes(node* root, vector<int>& result) {
    node* currNode = root->right;
    vector<int> temp; // Temporary stack-like storage
    while (currNode) {
        if (!leafNode(currNode)) {
            temp.push_back(currNode->data);
        }
        if (currNode->right) currNode = currNode->right;
        else currNode = currNode->left;
    }
    // Reverse order for bottom-up traversal
    for (int i = temp.size() - 1; i >= 0; i--) {
        result.push_back(temp[i]);
    }
}

// Function to perform boundary traversal
vector<int> BoundaryTraversal(node* root) {
    vector<int> result;
    if (root == nullptr) return result;

    // Add root node (only if it's not a leaf)
    if (!leafNode(root)) {
        result.push_back(root->data);
    }

    // Add left boundary
    AddLeftBoundary(root, result);

    // Add leaf nodes
    AddLeafNodes(root, result);

    // Add right boundary
    AddRightNodes(root, result); // Fixed function call

    return result;
}

// Driver code
int main() {
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->right->left = new node(8);
    root->left->right->right = new node(9);
    root->right->right->left = new node(10);
    root->right->right->right = new node(11);

    vector<int> boundary = BoundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int val : boundary) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
