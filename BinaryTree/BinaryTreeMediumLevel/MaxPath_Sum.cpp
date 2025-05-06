#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct node {
    int value;
    node* left;
    node* right;
    node(int x) : value(x), left(NULL), right(NULL) {}
};

// Helper function to find the maximum path sum
int findingMax(node* root, int &maxi) { // Pass maxi by reference
    if (root == NULL) return 0;

    // Ignore negative paths because they can't contribute to the max sum
    int leftSum = max(0, findingMax(root->left, maxi));
    int rightSum = max(0, findingMax(root->right, maxi)); // ✅ Fixed typo

    // Compute the max sum considering the current node as the root of a path
    maxi = max(maxi, root->value + leftSum + rightSum);

    // Return the max sum including the current node and one of its subtrees
    return root->value + max(leftSum, rightSum);
}

// Main function to get the maximum path sum
int MaxPathSum(node* root) {
    int maxi = INT_MIN;  // Variable to store the maximum path sum
    findingMax(root, maxi);
    return maxi;
}

// Driver Code
int main() {
    /*
        Example Tree:

                -10
                /  \
               9   20
                  /  \
                 15   7

        Expected Output: Maximum path sum is 42 (15 → 20 → 7)
    */
    
    node* root = new node(-10);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(7);

    cout << "Maximum Path Sum: " << MaxPathSum(root) << endl;

    return 0;
}
