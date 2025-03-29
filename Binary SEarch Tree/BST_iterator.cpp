#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// BST Iterator Class
class BSTIterator {
private:
    stack<Node*> forwardStack;  // Stack for next() operation (inorder traversal)
    stack<Node*> backwardStack; // Stack for before() operation (reverse inorder traversal)

    // Push all left children for inorder traversal
    void pushLeft(Node* root) {
        while (root) {
            forwardStack.push(root);
            root = root->left;
        }
    }
    
    // Push all right children for reverse inorder traversal
    void pushRight(Node* root) {
        while (root) {
            backwardStack.push(root);
            root = root->right;
        }
    }

public:
    // Constructor initializes the iterator with a BST root
    BSTIterator(Node* root) {
        pushLeft(root);  // Initialize stack for forward traversal
        pushRight(root); // Initialize stack for reverse traversal
    }

    // Check if there's a next element (inorder traversal)
    bool hasNext() {
        return !forwardStack.empty();
    }

    // Check if there's a previous element (reverse inorder traversal)
    bool hasBefore() {
        return !backwardStack.empty();
    }

    // Get the next element in ascending order
    int next() {
        if (!hasNext()) throw runtime_error("No more elements");
        Node* temp = forwardStack.top();
        forwardStack.pop();
        pushLeft(temp->right); // Push left nodes of the right subtree
        return temp->data;
    }

    // Get the previous element in descending order
    int before() {
        if (!hasBefore()) throw runtime_error("No previous elements");
        Node* temp = backwardStack.top();
        backwardStack.pop();
        pushRight(temp->left); // Push right nodes of the left subtree
        return temp->data;
    }
};

// Function to test the BST Iterator
int main() {
    /* Construct the following BST:
            7
           / \
          3   15
             /  \
            9    20
    */
    Node* root = new Node(7);
    root->left = new Node(3);
    root->right = new Node(15);
    root->right->left = new Node(9);
    root->right->right = new Node(20);

    BSTIterator iterator(root);
    
    cout << "Inorder Traversal using next(): ";
    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    cout << endl;
    
    BSTIterator reverseIterator(root);
    cout << "Reverse Inorder Traversal using before(): ";
    while (reverseIterator.hasBefore()) {
        cout << reverseIterator.before() << " ";
    }
    cout << endl;
    
    return 0;
}
