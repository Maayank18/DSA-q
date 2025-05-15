// Each of every Dp has its own ways of solving it 
// like express in indexes , do stuffs adn return max/min

// BUT PARTITION IS ONE OF THE MOST DIFFICULT ONE 
// Steps to follow
// 1. Start with entire block/array -> f(i,j) , i = start, j= end
// 2. Try all possible partitions - most probably usng loops
// 3. return the best possible 2 partitions


// MATRIX CHAIN MULTIPLICATION
// this problem basically aims on finding 
// eg we are give 4 matrix 
// arr = [10,20,30,30,40] 10,20  20,30  30,30  ... are size of eaxh amrix
// chains goes like 10,20 can be multiplied by 20,30
// answer = 10 x 30 x common(20) = 6000 we need to minimize it up
// return min multiplication to multiply matix1 -> matrix 4 


// Simple recursion
// TC -> O(2ⁿ)
// SC -> O(n) (stack)
#include<iostream>
#include<vector>
using namespace std;

int f(int i, int j, vector<int>&arr){

    // base case
    if(i == j) return 0;


    int mini = 1e9;
    for(int k = i; k<j; k++){
        int steps = (arr[i-1]*arr[k]*arr[j]) + f(i,k,arr) + f(k+1,j,arr);
        mini = min(mini,steps);
    }
    return mini;
}

int main(){
    int n = 5; // means 4 arrays as 4 sizes are given
    vector<int> arr = {10,20,30,40,50};
    int minOperation = f(1,n-1,arr); // passing my i and j;
    cout<<" minimum multiplacation operations are : "<<minOperation<<endl;
    return 0;
}




// Memoisation technique 
// TC -> O(n x n) x n(almost cube solution)
// SC -> O(n^2) + O(n)
int f(int i, int j, vector<int>&arr, vector<vector<int>> &dp){

    // base case
    if(i == j) return 0;

    // base case 2 
    if(dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;
    for(int k = i; k<j; k++){
        int steps = (arr[i-1]*arr[k]*arr[j]) + f(i,k,arr,dp) + f(k+1,j,arr,dp);
        mini = min(mini,steps);
    }
    return dp[i][j] = mini;
}

// int main(){
//     int n = 5; // means 4 arrays as 4 sizes are given
//     vector<int> arr = {10,20,30,40,50};
//     vector<vector<int>> dp(n,vector<int>(n,-1));
//     int minOperation = f(1,n-1,arr,dp); // passing my i and j;
//     cout<<" minimum multiplacation operations are : "<<minOperation<<endl;
//     return 0;
// }




// TABULATION TECHNIQUE

#include <bits/stdc++.h>
using namespace std;

// Function to find the minimum number of operations for matrix multiplication
int matrixMultiplication(vector<int>& arr, int N) {
    // Create a DP table to store the minimum number of operations
    vector<vector<int>> dp(N, vector<int>(N, -1));

    // Initialize the diagonal elements of the DP table to 0
    for (int i = 0; i < N; i++) {
        dp[i][i] = 0;
    }

    // Loop for the length of the chain
    for (int len = 2; len < N; len++) {
        for (int i = 1; i < N - len + 1; i++) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;

            // Try different partition points to find the minimum
            for (int k = i; k < j; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    // The result is stored in dp[1][N-1]
    return dp[1][N - 1];
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    int n = arr.size();

    cout << "The minimum number of operations for matrix multiplication is " << matrixMultiplication(arr, n) << endl;

    return 0;
}