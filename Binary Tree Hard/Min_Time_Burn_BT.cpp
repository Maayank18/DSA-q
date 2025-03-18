#include <bits/stdc++.h>
using namespace std;

// Definition of a Binary Tree Node
struct node {
    int val;         // Stores the value of the node
    node* left;      // Pointer to left child
    node* right;     // Pointer to right child

    // Constructor to initialize the node
    node(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Function to mark the parent of each node in the tree.
 * This helps in traversing upwards when burning the tree.
 *
 * @param root - Root of the binary tree
 * @param parentTracker - Map to store parent pointers of each node
 * @param target - Reference to store the node from where the burning starts
 * @param start - The value of the node where the fire starts
 */
void markParent(node* root, map<node*, node*>& parentTracker, node*& target, int start) {
    queue<node*> q; // Queue for level-order traversal
    q.push(root);   // Start with the root node

    while (!q.empty()) {
        node* current = q.front(); // Get the front node
        q.pop();

        // If this is the target node, store it
        if (current->val == start) target = current;

        // If left child exists, mark its parent and push to queue
        if (current->left) {
            parentTracker[current->left] = current; // Store parent
            q.push(current->left);
        }

        // If right child exists, mark its parent and push to queue
        if (current->right) {
            parentTracker[current->right] = current; // Store parent
            q.push(current->right);
        }
    }
}

/**
 * Function to compute the minimum time to burn the entire binary tree
 * starting from a given node.
 *
 * @param root - Root node of the binary tree
 * @param start - Value of the node from where the burning starts
 * @return int - Minimum time required to burn the entire tree
 */
int minimumTimeToBurn(node* root, int start) {
    if (root == NULL) return 0; // Edge case: If the tree is empty

    // Step 1: Create a mapping of each node to its parent
    map<node*, node*> parentTracker; // Map to store parent pointers
    node* target = NULL; // Target node where fire starts
    markParent(root, parentTracker, target, start); // Fill parent map

    // Step 2: Start BFS from the target node to burn the tree
    map<node*, bool> visited; // To track visited nodes
    queue<node*> q; // Queue for BFS
    q.push(target); // Start from the burning node
    visited[target] = true; // Mark it as visited

    int time = 0; // Counter to store time taken to burn the tree

    // BFS traversal to spread the fire
    while (!q.empty()) {
        int size = q.size(); // Number of nodes burning at the current time unit
        bool burned = false; // Flag to check if fire spreads in this iteration

        // Process all nodes burning at the current level
        for (int i = 0; i < size; i++) {
            node* current = q.front();
            q.pop();

            // Spread fire to the left child
            if (current->left && !visited[current->left]) {
                q.push(current->left);
                visited[current->left] = true;
                burned = true; // Fire has spread
            }

            // Spread fire to the right child
            if (current->right && !visited[current->right]) {
                q.push(current->right);
                visited[current->right] = true;
                burned = true; // Fire has spread
            }

            // Spread fire to the parent node
            if (parentTracker[current] && !visited[parentTracker[current]]) {
                q.push(parentTracker[current]);
                visited[parentTracker[current]] = true;
                burned = true; // Fire has spread
            }
        }

        // If any fire spread in this round, increment the time counter
        if (burned) time++;
    }

    return time; // Return total time taken to burn the entire tree
}

// Driver Code
int main() {
    // Constructing the binary tree
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    root->left->left->left = new node(8);
    root->left->left->right = new node(9);

    int startNode = 4; // Fire starts from node with value 4

    // Compute and print the minimum time required to burn the tree
    cout << "Minimum time to burn the tree: " << minimumTimeToBurn(root, startNode) << endl;

    return 0;
}
