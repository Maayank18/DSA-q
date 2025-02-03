// This problem basiaclly aims to find the max points we can get from drawing 
// k cards in given array but the thing is either we can move from right
// to left or left to right that to consecutively
// what i was thinking was we can like use the concept of circular arr to
// generate some sort of consecutivenesss


// BRUTE FORCE APPROACH WHERE BASICALLY WE ARE USING O(N^2) TIME COMPLEXITY 
// AND SPACE O(1)

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int MaxSumOfKcards(vector<int> arr, int k) {
    int n = arr.size();
    int maxSum = INT_MIN;

    // Try all starting points
    for (int i = 0; i < n; i++) {
        int sum = 0;

        // Pick k elements in circular manner
        for (int j = 0; j < k; j++) {
            sum += arr[(i + j) % n]; // Wrap around using modulus
        }

        maxSum = max(maxSum, sum);
    }

    return maxSum;
}

int main(){
    vector<int> arr = {6,2,3,4,7,2,1,7,1};
    int maxxSum = MaxSumOfKcards(arr,4);
    cout<<" the max point we can get is : "<<maxxSum<<endl;
    return 0;
}


// BETTER / OPTIMAL WILL BE USING A SOMEHWERE CIRCULAR ARR AND SLIDNG WINDOW 
// APPROACH WHERE TIME CMPLAEXITY WILL BOIL DOWN TO O(N*K) AND SPACE O(1)

#include <iostream>
#include <vector>
#include <algorithm> // For max function
using namespace std;

int MaxSumOfKcards(vector<int>& arr, int k) {
    int n = arr.size();
    int sum = 0, maxSum = 0;

    // Step 1: Calculate the sum of the first 'k' elements
    for (int i = 0; i < k; i++) {
        sum += arr[i];
    }
    
    maxSum = sum; // Store the initial sum as max

    // Step 2: Slide the window across the array
    for (int i = k; i < n; i++) {
        sum += arr[i];           // Add the next element
        sum -= arr[i - k];       // Subtract the element going out of the window
        maxSum = max(maxSum, sum); // Update max sum if needed
    }

    return maxSum;
}

int main() {
    vector<int> arr = {6, 2, 3, 4, 7, 2, 1, 7, 1};
    int k = 3;  // Try with 3 consecutive elements
    cout << "Max sum of " << k << " consecutive elements in a linear array: " << MaxSumOfKcards(arr, k) << endl;
    return 0;
}
