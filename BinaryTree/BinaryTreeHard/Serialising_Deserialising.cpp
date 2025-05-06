// 1. Serialization
// Serialization converts a binary tree into a string (or other data structure like an array).
//  A common method is preorder traversal where we store "null" (or "#") for NULL nodes.

// 2. Deserialization
// Deserialization reverses the process—converting the serialized string back into the
//  original binary tree.

#include <iostream>
#include <queue>
#include <sstream>
using namespace std;

// Define the structure of a tree node
class Node {
public:
    int value;
    Node* left;
    Node* right;

    // Constructor to initialize node
    Node(int x) : value(x), left(nullptr), right(nullptr) {}
};

// Function to serialize (convert tree to string)
string serializeBT(Node* root) {
    if (root == NULL) return "";  // If tree is empty, return an empty string

    string s = "";
    queue<Node*> q;
    q.push(root);

    // Perform level-order traversal using a queue
    while (!q.empty()) {
        Node* currNode = q.front();
        q.pop();

        if (currNode == NULL) {
            s.append("#,");  // Use "#" to represent NULL nodes
        } else {
            s.append(to_string(currNode->value) + ",");  // Store node value
            q.push(currNode->left);   // Push left child (even if NULL)
            q.push(currNode->right);  // Push right child (even if NULL)
        }
    }
    return s;  // Return serialized string
}

// Function to deserialize (convert string back to tree)
Node* deserializeBT(string data) {
    if (data.empty()) return NULL;  // If input string is empty, return NULL

    stringstream s(data);  // Convert string into a stream
    string str;
    
    // Read the first value to create the root node
    getline(s, str, ',');
    Node* root = new Node(stoi(str));
    
    queue<Node*> q;
    q.push(root);

    // Process the remaining values in the serialized string
    while (!q.empty()) {
        Node* currNode = q.front();
        q.pop();

        // Read left child value
        getline(s, str, ',');
        if (str == "#") {
            currNode->left = NULL;
        } else {
            Node* leftNode = new Node(stoi(str));  // Convert to int and create node
            currNode->left = leftNode;
            q.push(leftNode);
        }

        // Read right child value
        getline(s, str, ',');
        if (str == "#") {
            currNode->right = NULL;
        } else {
            Node* rightNode = new Node(stoi(str));  // Convert to int and create node
            currNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;  // Return the reconstructed binary tree
}

// Function to print level-order traversal of the tree
void printLevelOrder(Node* root) {
    if (root == NULL) return;
    
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        
        if (curr == NULL) {
            cout << "# ";
        } else {
            cout << curr->value << " ";
            q.push(curr->left);
            q.push(curr->right);
        }
    }
    cout << endl;
}

// Main function to test serialization and deserialization
int main() {
    // Creating a simple binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);

    // Serialize the tree
    string serializedTree = serializeBT(root);
    cout << "Serialized Tree: " << serializedTree << endl;

    // Deserialize the tree
    Node* newRoot = deserializeBT(serializedTree);
    cout << "Deserialized Tree (Level Order): ";
    printLevelOrder(newRoot);

    return 0;
}
