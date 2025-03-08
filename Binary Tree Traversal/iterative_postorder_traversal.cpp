// This iterative scheme would be using two stack method for solving the iterative 
// method to find the postorder

#include <iostream>
#include<stack>
#include <vector>

using namespace std;

// Node structure for the binary tree
struct node {
    int data;
    node* left;
    node* right;
    // Constructor to initialize
    // the node with a value
    node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> posterOrderList(node * root){
    vector<int> postorder;
    if( root == NULL ) return postorder;
    stack<node*> st1, st2;
    st1.push(root);
    while(!st1.empty()){
        node * newnode = st1.top();
        st1.pop();
        st2.push(newnode);

        if(newnode->left) st1.push(newnode->left);
        if(newnode->right) st1.push(newnode->right);
    }

    while(!st2.empty()){
        postorder.push_back(st2.top()->data);
        st2.pop();
    }
    return postorder;
}

// Main function
int main()
{
    // Creating a sample binary tree
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);

    // Getting inorder traversal
    vector<int> result = posterOrderList(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    // Output each value in the
    // inorder traversal result
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}