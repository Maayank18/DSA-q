// Pre order is basically -> root left right 

#include<iostream>
#include<vector>
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

void preorder ( node * root, vector<int> &arr){
    if(root == nullptr){
        return;
    }

    arr.push_back(root->data);
    preorder(root->left,arr);
    preorder(root->right,arr);
}

vector<int> preOrderlist(node*root){
    vector<int> arr;
    preorder(root,arr);
    return arr;
}

int main(){
    node * root = new node(1);
    root->left = new node(2);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->right = new node(3);
    root->right->left = new node(7);
    root->right->right = new node(8);
    root->right->right->right= new node(10);
    root->right->right->left= new node(9);

    vector<int> ans = preOrderlist(root);

    cout << "Preorder Traversal: ";
    // Output each value in the
    // preorder traversal result
    for(int val : ans) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}