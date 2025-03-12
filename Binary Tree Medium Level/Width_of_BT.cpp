// MAXIMUM WIDTH OF A BINARY TREE -> what this means is number of nodes between any 2 
// nodes or in a much better language we can say maximum nodes in a 
// final level of BT
// BASIC FORMULA IS -> LAST INDEX - FIRST INDEX + 1

#include<iostream>
#include<queue>
using namespace std;

struct Node{
    int data;
    Node * left;
    Node * right;
    Node( int value ){
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

int widthOfBinaryTree(Node * root){
    queue<pair<Node*,int>>q;
    q.push({root,0});
    int maxWidth = 0;
    int last, first;

    while(!q.empty()){
        int size = q.size();  // number_of_Nodes_in_cuurent_level
        
        for(int i = 0; i<size; i++){
            int current_idx = q.front().second;
            Node * node = q.front().first; // storing the current node 
            q.pop();

            if(i == 0) first = current_idx;
            if(i == size-1) last = current_idx;

            if(node->left) q.push({node->left,2*current_idx + 1});
            if(node->right) q.push({node->right,2*current_idx + 2});

        }
        maxWidth = max(maxWidth,last-first+1);
    }
    return maxWidth;
}

// Driver code to test the function
int main() {
    /* Example Binary Tree:
    
           1
          / \
         3   2
        / \   \
       5   3   9
    
    Expected Output: Maximum width is 4
    */
    
    Node* root = new Node(1);
    root->left = new Node(3);
    root->right = new Node(2);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->right = new Node(9);

    cout << "Maximum width of the binary tree: " << widthOfBinaryTree(root) << endl;
    
    return 0;
}


