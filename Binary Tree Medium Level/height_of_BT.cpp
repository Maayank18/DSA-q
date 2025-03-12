// here the current node also will be considered to have a height 
        //             (A)  <- Level 0
        //            /   \
        //          (B)   (C)  <- Level 1
        //         /   \    \
        //       (D)   (E)  (F)  <- Level 2
        //      /   \     \
        //    (G)   (H)   (I)  <- Level 3
        //            \
        //           (J)  <- Level 4

// this particular tree has a hieght of 4 but we are also considering the root node too
// hence here thre height will be 5:-  A -> B -> D -> H -> J


// THIS IS TYPE 1 TO SOLVE WHERE WE CAN USE THE RECURSIVE CODE 
// Here we wont be having time complexity BUT we are using extra stack
// hum kya kar rahe hai is basically at every root we are fidning the 
// possibility of extension like kya ye height badh rahi hai if yes add one 
// also first we are traversing left and then we are going right

#include<iostream>
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

int Height_Of_BT(Node * root){
    if( root == NULL) return 0;

    int leftHeight = Height_Of_BT(root->left);
    int rightHeight = Height_Of_BT(root->right);

    return 1+max(leftHeight,rightHeight);
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    
    int height = Height_Of_BT(root);

    cout << "Maximum depth of the binary tree: " << height << endl;

    return 0;
}


// SECOND METHOD TO SOLVE USING THE LEVEL WISE METHOD
// here what we will be doing is like traversing level wise using the concept of queue 
// datastructure

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

int Height_Of_BT(Node * root){
    queue<Node*>q;
    q.push(root);
    int height = 0;

    while(!q.empty()){
        int levelsize = q.size();

        for(int i = 0; i<levelsize; i++){
            Node* newnode = q.front();
            q.pop();

            if(newnode -> left) q.push(newnode->left);
            if(newnode -> right) q.push(newnode->right);
        }
        height++;
    }
    return height;
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    
    int height = Height_Of_BT(root);

    cout << "Maximum depth of the binary tree: " << height << endl;

    return 0;
}
