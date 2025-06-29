#include <iostream>
#include <vector>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

vector<int> inOrder(Node * root){
    stack<Node*> st;
    vector<int> answer;
    Node * node = root;

    while(true){
        if( node != NULL){
            st.push(node);
            node = node -> left;
        }else{
            if( st.empty() ){
                break;
            }

            node = st.top();
            st.pop();
            answer.push_back(node->data);
            node = node -> right;
        }
    }
    return answer;
}

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting inorder traversal
    vector<int> result = inOrder(root);

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

                            
                        