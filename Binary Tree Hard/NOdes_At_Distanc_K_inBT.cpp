#include <bits/stdc++.h>
using namespace std;

// Definition of a Binary Tree Node
struct node {
    int val;
    node* left;
    node* right;

    node(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Function to mark the parent of each node in the tree.
 * 
 * @param root - Root of the binary tree
 * @param parentTracker - Map to store parent pointers of each node
 */
void markParent(node* root, map<node*, node*>& parentTracker) {
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* current = q.front();
        q.pop();

        // Store parent of left child
        if (current->left) {
            parentTracker[current->left] = current;
            q.push(current->left);
        }

        // Store parent of right child
        if (current->right) {
            parentTracker[current->right] = current;
            q.push(current->right);
        }
    }
}

/**
 * Function to find the target node in the binary tree.
 * 
 * @param root - Root of the binary tree
 * @param start - Value of the target node
 * @return node* - Pointer to the target node
 */
node* findTarget(node* root, int start) {
    if (root == NULL) return NULL;
    if (root->val == start) return root;

    node* leftSearch = findTarget(root->left, start);
    if (leftSearch) return leftSearch;

    return findTarget(root->right, start);
}

/**
 * Function to print all nodes at a distance `k` from the target node.
 * 
 * @param root - Root of the binary tree
 * @param start - Value of the target node
 * @param k - Distance from target node
 * @return vector<int> - List of node values at distance `k`
 */
vector<int> nodesAtDistanceK(node* root, int start, int k) {
    if (!root) return {}; // Edge case: If the tree is empty

    // Step 1: Map each node to its parent
    map<node*, node*> parentTracker;
    markParent(root, parentTracker);

    // Step 2: Find the target node
    node* target = findTarget(root, start);
    if (!target) return {}; // If target node is not found

    // Step 3: Perform BFS to find nodes at distance `k`
    map<node*, bool> visited; // To avoid revisiting nodes
    queue<node*> q;
    q.push(target);
    visited[target] = true;

    int distance = 0;

    while (!q.empty()) {
        int size = q.size();

        if (distance == k) break; // Stop when reaching distance `k`

        for (int i = 0; i < size; i++) {
            node* current = q.front();
            q.pop();

            // Check left child
            if (current->left && !visited[current->left]) {
                q.push(current->left);
                visited[current->left] = true;
            }

            // Check right child
            if (current->right && !visited[current->right]) {
                q.push(current->right);
                visited[current->right] = true;
            }

            // Check parent node
            if (parentTracker[current] && !visited[parentTracker[current]]) {
                q.push(parentTracker[current]);
                visited[parentTracker[current]] = true;
            }
        }

        distance++;
    }

    // Step 4: Collect all nodes at distance `k`
    vector<int> result;
    while (!q.empty()) {
        result.push_back(q.front()->val);
        q.pop();
    }

    return result;
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

    int startNode = 4; // Target node
    int k = 2; // Distance from target

    vector<int> result = nodesAtDistanceK(root, startNode, k);

    // Output result
    cout << "Nodes at distance " << k << " from node " << startNode << ": ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
