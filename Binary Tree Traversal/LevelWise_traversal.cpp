#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> levelOrderTraversal(TreeNode* root){
    vector<int> result;
    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        result.push_back(node->data);

        // Enqueue left and right children if they exist
        if(node->left) q.push(node->left);  
        if(node->right) q.push( node->right);
    }
    return result;
}

int main() {
    // Creating the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Get the level order traversal list
    vector<int> traversal = levelOrderTraversal(root);

    // Print the traversal list
    cout << "Level Order Traversal: ";
    for (int val : traversal) {
        cout << val << " ";
    }

    return 0;
}