// our aim is to convert a binary search tree to max heap
// point 1 -> each parent should be greater than child
// point 2 -> left side elements must be < right side elements

// first finding inorder traversal of the given bst
// and do the post order traversal fro given in order
// and hence our max heap is created
// time complexity -> O(n)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;

    node( int value){
        data = value;
        left = right = NULL;
    }
};

void inorder(node * root, vector<int> &ans){
    if(!root) return;

    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

void postorder(node * root, vector<int> &ans, int &index){ // Pass by reference
    if(!root) return;

    postorder(root->left, ans, index);
    postorder(root->right, ans, index);
    root->data = ans[index];
    index++;
}

void convertBSTToMaxHeap(node * root){
    vector<int> ans;
    inorder(root, ans);  // get sorted elements in inorder

    int index = 0;
    postorder(root, ans, index);  // assign in postorder to follow max-heap rules
}

// Helper function to check Max Heap property (postorder print)
void printPostorder(node* root){
    if (!root) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->data << " ";
}

int main() {
    // Creating BST manually
    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right = new node(3);
    root->right->left = new node(5);
    root->right->right = new node(7);

    convertBSTToMaxHeap(root);

    cout << "Postorder traversal of Max Heap:\n";
    printPostorder(root);
    cout << endl;

    return 0;
}
