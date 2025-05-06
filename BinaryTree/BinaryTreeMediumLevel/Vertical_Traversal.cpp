// This particular code here basically only aims at the vertical traversal of the 
// binary tree WITHOUT MANAGING ANY EDGE CASES 
// edge cases like two nodes present at same level and 
// this particular code cant manage it for that there needs a modification


#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;
    node( int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> verticalTraversal( node * root){
    if( root == NULL){
        return {};
    }

    // it will map the horizontal distance with node value
    map<int,vector<int>> nodes;  

    // For level order traversal of the node and the horizontal distance 
    queue<pair<node*,int>> q; 

    q.push({root,0});

    while(!q.empty()){
        int levelSize = q.size();
        while(levelSize--){
            pair<node*, int> front = q.front();
            q.pop();

            node * currNode = front.first;
            int hd = front.second;

            nodes[hd].push_back(currNode -> data);

            if(currNode -> left) q.push({currNode->left,hd-1});
            if(currNode -> right) q.push({currNode->right,hd+1});
        }
    }

    vector<int> result;
    for(auto it : nodes ){
        for( int value : it.second){
            result.push_back(value);
        }
    }

    return result;
}

int main() {
    // Manually constructing the given binary tree
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->right->right->right = new node(7);


    vector<int> finalTraversal = verticalTraversal(root);

    for( auto it : finalTraversal){
        cout << it << " ";
    }
    return 0;
}



// The case where the edge cases are also handled with a little bit of modification

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to perform vertical traversal
vector<vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {}; // Edge case: empty tree

    // Map: {Horizontal Distance -> {Level -> Sorted Node Values}}
    map<int, map<int, multiset<int>>> nodes;
    
    // Queue for BFS traversal {Node, (HD, Level)}
    queue<pair<TreeNode*, pair<int, int>>> q;
    q.push({root, {0, 0}}); // Root node starts at HD = 0, Level = 0

    while (!q.empty()) {
        auto front = q.front();
        q.pop();
        TreeNode* node = front.first;
        int hd = front.second.first; // Horizontal Distance
        int level = front.second.second; // Depth Level

        // Insert node into map
        nodes[hd][level].insert(node->val);

        // Push left child with HD - 1
        if (node->left) q.push({node->left, {hd - 1, level + 1}});
        
        // Push right child with HD + 1
        if (node->right) q.push({node->right, {hd + 1, level + 1}});
    }

    // Extract sorted values
    vector<vector<int>> result;
    for (auto& hd : nodes) {
        vector<int> col;
        for (auto& level : hd.second) {
            col.insert(col.end(), level.second.begin(), level.second.end());
        }
        result.push_back(col);
    }
    
    return result;
}

// Utility function to create a binary tree from level order
TreeNode* insertLevelOrder(vector<int> arr, int i, int n) {
    if (i >= n || arr[i] == -1) return NULL; // -1 represents NULL node
    TreeNode* root = new TreeNode(arr[i]);
    root->left = insertLevelOrder(arr, 2 * i + 1, n);
    root->right = insertLevelOrder(arr, 2 * i + 2, n);
    return root;
}

// Driver code
int main() {
    // Example tree: [1, 2, 3, 4, 5, 6, 7]
    vector<int> nodes = {1, 2, 3, 4, 5, 6, 7};
    TreeNode* root = insertLevelOrder(nodes, 0, nodes.size());

    // Perform vertical traversal
    vector<vector<int>> result = verticalTraversal(root);

    // Print the result
    for (auto col : result) {
        for (int num : col) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
