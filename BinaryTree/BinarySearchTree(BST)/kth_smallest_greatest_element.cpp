// BRUTE FORCE SOLUTION 
// TIME COMPLEXITY -> O(N) FOR TRAVERSING + O(NLOGN) FOR SORTING 
// SPACE COMPLEXITY -> O(N) STORING ELEMENTS IN VECTOR 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition of a Node in the BST
struct node {
    int value;
    node* left;
    node* right;
    
    node(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
};

// Function for PreOrder Traversal (stores values in the vector)
void PreOrderTraversal(node* root, vector<int>& arr) {
    if (root == NULL) return;

    arr.push_back(root->value); // Add current node value
    PreOrderTraversal(root->left, arr);  // Recur for left subtree
    PreOrderTraversal(root->right, arr); // Recur for right subtree
}

// Function to find k-th smallest element efficiently
int findingSmallest(vector<int>& arr, int k) {
    nth_element(arr.begin(), arr.begin() + (k - 1), arr.end()); // Partially sorts
    return arr[k - 1]; // Get the k-th smallest element
}

int main() {
    node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);

    vector<int> arr;
    PreOrderTraversal(root, arr);

    int k = 3; // Find the 3rd smallest element
    cout << "3rd smallest element: " << findingSmallest(arr, k) << endl;

    return 0;
}


// BETTER SOLUTION MAY INLCUDE THE USE OF INORDER TRAVEL
// beacuse in order itself returns a sorted list so we will save O(nlogn)


                                
#include <iostream>
using namespace std;

// Definition of a Node in the BST
struct node {
    int value;
    node* left;
    node* right;
    
    node(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
};

// Helper function for Inorder Traversal
void inorderTraversal(node* root, int& k, int& result) {
    if (root == NULL || k <= 0) return;

    // Traverse left subtree
    inorderTraversal(root->left, k, result);

    // Process current node
    k--; // Decrement k (count elements)
    if (k == 0) {
        result = root->value;
        return; // Stop further recursion
    }

    // Traverse right subtree
    inorderTraversal(root->right, k, result);
}

// Function to find the k-th smallest element
int findKthSmallest(node* root, int k) {
    int result = -1; // Default value if k is invalid
    inorderTraversal(root, k, result);
    return result;
}

// Driver Code
int main() {
    // Creating BST
    node* root = new node(5);
    root->left = new node(3);
    root->right = new node(7);
    root->left->left = new node(2);
    root->left->right = new node(4);
    root->right->left = new node(6);
    root->right->right = new node(8);

    int k = 3; // Find the 3rd smallest element
    cout << "The " << k << "rd smallest element is: " << findKthSmallest(root, k) << endl;

    return 0;
}
