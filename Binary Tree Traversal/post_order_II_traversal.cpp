// this is another way of performing iterative postorder method using one stack

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;
    node( int value ){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> postOrderT( node * root){
    vector<int> ans;
    stack<node*> st;
    node * current = root;

    while(current!=NULL || !st.empty()){
        if(current!=NULL){
            st.push(current);
            current = current -> left;
        }else{
            node* temp = st.top()->right;
            if(temp == NULL){
                temp = st.top();
                st.pop();
                ans.push_back(temp->data);
                while(!st.empty() && temp == st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->data);
                }
            }else{
                current = temp;
            }
        }
    }
    return ans;
}

// Driver function
int main() {
    // Constructing a sample binary tree
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);

    // Calling postorder traversal
    vector<int> result = postOrderT(root);

    // Printing postorder traversal output
    cout << "Postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}