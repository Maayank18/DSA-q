#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition for a Binary Tree Node
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to get the Top View of a Binary Tree
vector<int> TopViewTraversal(TreeNode* root) {
    if (root == NULL) return {}; // Edge case: empty tree

    vector<int> ans;
    map<int, int> mpp; // Stores {Horizontal Distance -> Node Data}
    queue<pair<TreeNode*, int>> q; // BFS Queue: {Node, Horizontal Distance}

    q.push({root, 0}); // Root has Horizontal Distance 0

    while (!q.empty()) {
        auto front = q.front();
        q.pop();

        TreeNode* newNode = front.first;
        int HorizontalDistance = front.second;

        // Insert only the first node encountered at this horizontal distance
        if (mpp.find(HorizontalDistance) == mpp.end()) {
            mpp[HorizontalDistance] = newNode->data;
        }

        // Push left and right children with updated Horizontal Distance
        if (newNode->left) q.push({newNode->left, HorizontalDistance - 1});
        if (newNode->right) q.push({newNode->right, HorizontalDistance + 1});
    }

    // Collect results in order of horizontal distance
    for (auto it : mpp) {
        ans.push_back(it.second);
    }

    return ans;
}

// Utility function to insert nodes in Level Order
TreeNode* insertLevelOrder(vector<int> arr, int i, int n) {
    if (i >= n || arr[i] == -1) return NULL;  // -1 represents NULL node
    TreeNode* root = new TreeNode(arr[i]);
    root->left = insertLevelOrder(arr, 2 * i + 1, n);
    root->right = insertLevelOrder(arr, 2 * i + 2, n);
    return root;
}

// Driver Code
int main() {
    // Example tree: [1, 2, 3, 4, 5, -1, 6]
    vector<int> nodes = {1, 2, 3, 4, 5, -1, 6};
    TreeNode* root = insertLevelOrder(nodes, 0, nodes.size());

    // Get the Top View
    vector<int> result = TopViewTraversal(root);

    // Print Result
    cout << "Top View: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
