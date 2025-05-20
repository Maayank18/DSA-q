// our aim is to find the max sum of the sub array 
// but hereit can be discontinous like it is sub array not subset

// BRUTE FORCE APPROACH IS TRYING ALL THE SUB ARRAY 
// AND FINDING THE MAXIMUM SUM
// TC -> O(N^2)
// SC -> O(1)
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int f(int i,vector<int> &arr){
//     int n = arr.size();
//     int maxSum = INT_MIN;

//     for(int i = 0; i<n; i++){
//         int currMax = 0;
//         for(int j = i; j<n; j++){
//             currMax += arr[j];
//             maxSum = max(maxSum,currMax);
//         }
//     }
//     return maxSum;
// }

// int main(){
//     vector<int> arr = {-2,-3,4,-1,-2,1,5,-1};
//     int maxSumSubarray = f(0,arr);
//     cout<<" the max subset sum is : "<<maxSumSubarray<<endl;
//     return 0;
// }






// An optimal and optimised solution 
// KADANE ALGORITHM
// just a small edition here we will also include EMPTY SUB ARRAY 
// IF NO ARRAY FIND WITH POSITIVE SUM RETURN EMPTY 
// tc -> O(n)
// sc -> O(1)
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int f(vector<int> &arr){
//     int n = arr.size();
//     int maxSum = INT_MIN;
//     int sum = 0;
//     for(int i = 0; i<n; i++){
//         sum+=arr[i];

//         if(sum > maxSum){
//             maxSum = sum;
//         }

//         if(sum < 0){
//             sum = 0;
//         }
//     }

//     if(maxSum < 0){
//         return 0;
//     }

//     return maxSum;
// }

// int main(){
//     vector<int> arr = {-2,-3,4,-1,-2,1,5,-1};
//     int maxSumSubarray = f(arr);
//     cout<<" the max subset sum is : "<<maxSumSubarray<<endl;
//     return 0;
// }

// follow up print that particular sub array
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<int> maxSubarrayWithSum(vector<int>& arr) {
    int n = arr.size();

    int maxSum = INT_MIN;
    int sum = 0;

    int start = 0, ansStart = -1, ansEnd = -1;

    for (int i = 0; i < n; i++) {
        if (sum == 0) start = i; // potential start of a new subarray

        sum += arr[i];

        if (sum > maxSum) {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }

        if (sum < 0) {
            sum = 0;
        }
    }

    vector<int> result;
    if (ansStart == -1) return result; // all numbers negative, return empty

    for (int i = ansStart; i <= ansEnd; i++) {
        result.push_back(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -1};
    vector<int> result = maxSubarrayWithSum(arr);

    cout << "The maximum subarray is: ";
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}

