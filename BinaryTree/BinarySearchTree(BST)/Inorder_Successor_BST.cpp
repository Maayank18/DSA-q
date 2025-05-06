/*
 * Function to find the inorder successor of a given node in a Binary Search Tree (BST).
 *
 * Time Complexity: O(h), where h is the height of the BST.
 *      - In the worst case (skewed BST), h = O(n).
 *      - In a balanced BST, h = O(log n).
 * Space Complexity: O(1) as we are using only a few extra variables.
 */

 #include <iostream>
 using namespace std;
 
 // Definition of a node in the BST
 struct Node {
     int value;
     Node* left;
     Node* right;
     
     Node(int val) {
         value = val;
         left = right = NULL;
     }
 };
 
 // Function to find the inorder successor of a node in BST
 Node* InorderSuccessor(Node* root, Node* p) {
     Node* successor = NULL; // Variable to store potential successor
 
     while (root != NULL) {
         if (p->value >= root->value) {
             // If the value of 'p' is greater than or equal to root, move to the right subtree
             root = root->right;
         } else {
             // If the value of 'p' is smaller than root, store current root as successor
             // and move to the left subtree to find a smaller potential successor
             successor = root;
             root = root->left;
         }
     }
 
     return successor; // Return the found successor or NULL if none exists
 }
 
 // Function to insert a node in the BST
 Node* insert(Node* root, int val) {
     if (root == NULL) return new Node(val);
 
     if (val < root->value)
         root->left = insert(root->left, val);
     else
         root->right = insert(root->right, val);
 
     return root;
 }
 
 // Function to find a node with a given value in BST
 Node* search(Node* root, int key) {
     if (root == NULL || root->value == key)
         return root;
     
     if (key < root->value)
         return search(root->left, key);
     
     return search(root->right, key);
 }
 
 // Driver code
 int main() {
     Node* root = NULL;
     
     // Insert nodes into the BST
     root = insert(root, 20);
     root = insert(root, 8);
     root = insert(root, 22);
     root = insert(root, 4);
     root = insert(root, 12);
     root = insert(root, 10);
     root = insert(root, 14);
 
     Node* target = search(root, 10); // Node whose inorder successor we need to find
 
     Node* successor = InorderSuccessor(root, target);
 
     if (successor)
         cout << "Inorder Successor of " << target->value << " is " << successor->value << endl;
     else
         cout << "Inorder Successor does not exist for " << target->value << endl;
 
     return 0;
 }
 