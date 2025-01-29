// Sliding Window Maximum (SWM) Explanation
// The Sliding Window Maximum problem involves finding the maximum 
// value in every contiguous subarray (window) of size 𝑘
// k from a given array.

// Problem Statement
// Given an array arr of size n and an integer k, find the 
// maximum element in each sliding window of size k as it moves from left to right.

// Example
// Input:
// arr = [1, 3, -1, -3, 5, 3, 6, 7]
// k = 3

// Output:
// [3, 3, 5, 5, 6, 7]


//This is a brute force approach where we are basically using 2 loops approach
// TIME COMPLEXITY -> O(N-K) x O(k)
// SPACE COMPLEXITY -> O(N-K)

#include<iostream>
#include<vector>
using namespace std;

vector<int> SlidingWindowMaximum(vector<int> arr, int k){
    vector<int> ans;
    int n = arr.size();

    for(int i = 0; i<=n-k; i++){
        int maxi = arr[i];
        for(int j = i; j<i+k; j++){
            maxi = max(maxi,arr[j]);
        }
        ans.push_back(maxi);
    }
    return ans;
}

int main(){
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = SlidingWindowMaximum(arr,k);
    for( int nums : result){
        cout<<nums<<"";
    }
    return 0;

}