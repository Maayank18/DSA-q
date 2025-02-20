#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct tree{
    int data;
    tree* left;
    tree* right;
    tree(int value){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

vector<int> iterativePreorderTraversal(tree* root){
    vector<int> ans;
    stack<tree*> st;
    st.push(root);

    while(!st.empty()){
        tree* node = st.top();
        st.pop();
        ans.push_back(node->data);

        if(node->right!=NULL){
            st.push(node->right);
        }

        if(node->left!=NULL){
            st.push(node->left);
        }
    }
    return ans;
}

int main() {
    // Creating the binary tree
    tree* root = new tree(1);
    root->left = new tree(2);
    root->right = new tree(3);
    root->left->left = new tree(4);
    root->left->right = new tree(5);
    root->right->left = new tree(6);
    root->right->right = new tree(7);

    // Get the preorder traversal list
    vector<int> traversal = iterativePreorderTraversal(root);

    // Print the traversal list
    cout << "Iterative Preorder Traversal: ";
    for (int val : traversal) {
        cout << val << " ";
    }

    return 0;
}
