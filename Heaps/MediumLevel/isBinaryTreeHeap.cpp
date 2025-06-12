// is binary tree a max heap or not
// 1. It should be complete binary tree
// 2. parent shoudl be >= child node in value

// how to figure out?
// the we know if we have a tree cbt 
//      80    
//     /  \  
//    60  70
//   / \     
//  40 30
// it is HEAP

//      80
//     /  \  
//    60  70
//       /  \     
//      40  30
// IT IS NOT heap INDEX >= SIZE 

// it is a complete binary tree 
// number of node = 5 and if we look at index all index are less than szie of arr 
//  in which the tree is tored 
//  so our check could be if the index of any element is greater than or equal to 
// the size of array hence not a cbt 


// step 1 check numebr of node O(N)
// step 2 cbt or not using inorder preorder postorder O(n)
// step 3 max heap condition O(n)



#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * left;
    node * right;

    node(int value){
        data = value;
        left = NULL;
        right = NULL;
    }
};




int count(node * root){
    if(!root){
        return 0;
    }

    return 1 + count(root->left) + count(root->right);
}

bool CBT(node * root, int index, int nodes){

    // important
    if(!root){
        return true;
    }

    // base condition
    if(index >= nodes) return false;

    // check left and right
    bool checkleft = CBT(root->left,2*index+1,nodes);
    bool checkright = CBT(root->right,2*index+2,nodes);

    return checkleft && checkright;

}

bool maxHeap(node * root){

    // either root is null
    // only left wil exist
    // only right child exist
    // either both child exist
    if(root->left){
        if(root->data < root->left->data){
            return false;
        }else{
            if(!maxHeap(root->left)){
                return 0;
            }
        }
    }

    if(root->right){
        if(root->data < root->right->data){
            return false;
        }else{
            return maxHeap(root->right);
        }
    }

    return true;
}

bool isMaxHeap(node * root){

    // count nodes in the tree
    int num = count(root);

    // CBT hai ya nhi
    bool ans = CBT(root,0,num);

    // check if every parent >= child
    if(ans == false){
        return false;
    }

    return maxHeap(root);
}

int main() {
    /*
              90
             /  \
           15    10
          /  \   /
         7   12  2
    */

    node* root = new node(90);
    root->left = new node(15);
    root->right = new node(10);
    root->left->left = new node(7);
    root->left->right = new node(12);
    root->right->left = new node(2);

    if (isMaxHeap(root)) {
        cout << "The binary tree is a Max Heap." << endl;
    } else {
        cout << "The binary tree is NOT a Max Heap." << endl;
    }

    return 0;
}