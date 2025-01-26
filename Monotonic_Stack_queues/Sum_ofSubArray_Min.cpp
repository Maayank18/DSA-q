// To calculate the sum of subarray minimums using a brute force approach in C++,
// you can follow these steps:

// Generate all subarrays of the array.
// Find the minimum value in each subarray.
// Add these minimum values to get the final sum.

// TIME COMPLEXITY -> O(N^2)
// SPACE COMPLEXITY ->O(1)


#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int sumOfSubarrayMinimums( vector<int> arr){
    int n = arr.size();
    int totalSum = 0;

    for( int i = 0; i<n; i++){
        int minCount = INT_MAX;
        for( int j = i; j<n; j++){
            minCount = min(minCount,arr[j]);
            totalSum += minCount;
        }
    }
    return totalSum;
}

int main() {
    vector<int> arr = {3, 1, 2, 4}; // Example array
    cout << "Sum of subarray minimums: " << sumOfSubarrayMinimums(arr) << endl;
    return 0;
}