#include <bits/stdc++.h>
using namespace std;

/*
    Brute Force Solution for 2-Sum Problem in a BST
    -------------------------------------------------
    Time Complexity: O(N^2) - Due to the nested loop for checking all pairs.
    Space Complexity: O(N) - Extra space used for storing inorder traversal.
*/

// Definition of a BST Node
struct Node {
    int data;
    Node* left, * right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to perform inorder traversal and store elements in a vector
void inorder(Node* root, vector<int>& arr) {
    if (!root) return;
    inorder(root->left, arr);  // Visit left subtree
    arr.push_back(root->data); // Store current node value
    inorder(root->right, arr); // Visit right subtree
}

// Brute force approach: Check all pairs for the target sum
bool findTarget(Node* root, int target) {
    vector<int> arr;
    inorder(root, arr);  // Get sorted elements in an array
    
    int n = arr.size();
    // Brute force approach: Nested loop to check all pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                return true; // Found a pair with the given sum
            }
        }
    }
    return false; // No valid pair found
}

// Testing the function
int main() {
    /* Construct the BST:
            5
           / \
          3   8
         / \   \
        2   4   10
    */
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(10);

    int target = 9;
    if (findTarget(root, target))
        cout << "Pair Found!" << endl;
    else
        cout << "No Pair Found!" << endl;

    return 0;
}



#include <bits/stdc++.h>
using namespace std;

/*
    Optimized Solution for 2-Sum Problem in a BST
    -------------------------------------------------
    Time Complexity: O(N) - Uses a two-pointer approach on sorted inorder traversal.
    Space Complexity: O(N) - Extra space used for storing inorder traversal.
*/

// Definition of a BST Node
struct Node {
    int data;
    Node* left, * right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to perform inorder traversal and store elements in a vector
void inorder(Node* root, vector<int>& arr) {
    if (!root) return;
    inorder(root->left, arr);  // Visit left subtree
    arr.push_back(root->data); // Store current node value
    inorder(root->right, arr); // Visit right subtree
}

// Optimized approach: Using Two-Pointer Technique
bool findTarget(Node* root, int target) {
    vector<int> arr;
    inorder(root, arr);  // Get sorted elements in an array
    
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return true; // Found a pair with the given sum
        else if (sum < target) left++; // Move left pointer to increase sum
        else right--; // Move right pointer to decrease sum
    }
    return false; // No valid pair found
}

// Testing the function
int main() {
    /* Construct the BST:
            5
           / \
          3   8
         / \   \
        2   4   10
    */
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(10);

    int target = 9;
    if (findTarget(root, target))
        cout << "Pair Found!" << endl;
    else
        cout << "No Pair Found!" << endl;

    return 0;
}




#include <bits/stdc++.h>
using namespace std;

/*
    Optimized Solution for 2-Sum Problem in a BST
    -------------------------------------------------
    Time Complexity: O(N) - Uses a two-pointer approach on sorted inorder traversal.
    Space Complexity: O(N) - Extra space used for storing inorder traversal.
*/

// Definition of a BST Node
struct Node {
    int data;
    Node* left, * right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Function to perform inorder traversal and store elements in a vector
void inorder(Node* root, vector<int>& arr) {
    if (!root) return;
    inorder(root->left, arr);  // Visit left subtree
    arr.push_back(root->data); // Store current node value
    inorder(root->right, arr); // Visit right subtree
}

// Optimized approach: Using Two-Pointer Technique
bool findTarget(Node* root, int target) {
    vector<int> arr;
    inorder(root, arr);  // Get sorted elements in an array
    
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == target) return true; // Found a pair with the given sum
        else if (sum < target) left++; // Move left pointer to increase sum
        else right--; // Move right pointer to decrease sum
    }
    return false; // No valid pair found
}

// Testing the function
int main() {
    /* Construct the BST:
            5
           / \
          3   8
         / \   \
        2   4   10
    */
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(10);

    int target = 9;
    if (findTarget(root, target))
        cout << "Pair Found!" << endl;
    else
        cout << "No Pair Found!" << endl;

    return 0;
}
