// brute force solution is getting all subrays and checking for each of the them 
// which would be having a time complexity of o(n^3)

// int maxsub( int arr[], int n){
//     int maxi = INT_MIN;
//     for( int i = 0; i<n; i++){
//         for( int j = i; i<n; i++){
//              int sum = 0;
//              for( int k = i; k<j; k++){
//                 sum+=arr[k];
//                 maxi = max(sum,maxi);
//              }
//         }
//     }
// }


// better solution is nothing but we can just simply remove the third loop from code
// reduce time complexity from 0(n^3) to some what about 0(n^2)

// int maxsub( int arr[], int n){
//     int maxi = INT_MIN;
//     for( int i = 0; i<n; i++){
//         int sum = 0;
//         for( int j = i; i<n; i++){
//                 sum+=arr[j];
//                 maxi = max(sum,maxi);
//         }
//     }
// }


//KADANE ALGORITHM ( Most optimal approach )// biog o(n)
#include<iostream>
using namespace std;
int maxSubarraySum( int arr[], int n){
    int sum = 0, maxi = INT8_MIN;
    for(int i = 0; i<n; i++){
        sum = sum +arr[i];

        if(sum>maxi){
            maxi = sum;
        }

        if(sum<0){
            sum = 0;
        }
    }
    if(maxi<0){
        maxi = 0;
    }
    return maxi;
}

int main()
{
    int arr[] = { -4,-3,-2,-1};
    int n = sizeof(arr) / sizeof(arr[0]);
    long long maxSum = maxSubarraySum(arr, n);
    cout << "The maximum subarray sum is: " << maxSum << endl;
    return 0;
}

// incase we gotta print the subarray with max sum 

// #include <bits/stdc++.h>
// using namespace std;

// long long maxSubarraySum(int arr[], int n) {
//     long long maxi = LONG_MIN; // maximum sum
//     long long sum = 0;

//     int start = 0;
//     int ansStart = -1, ansEnd = -1;
//     for (int i = 0; i < n; i++) {

//         if (sum == 0) start = i; // starting index

//         sum += arr[i];

//         if (sum > maxi) {
//             maxi = sum;

//             ansStart = start;
//             ansEnd = i;
//         }

//         // If sum < 0: discard the sum calculated
//         if (sum < 0) {
//             sum = 0;
//         }
//     }

//     //printing the subarray:
//     cout << "The subarray is: [";
//     for (int i = ansStart; i <= ansEnd; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << "]n";

//     // To consider the sum of the empty subarray
//     // uncomment the following check:

//     //if (maxi < 0) maxi = 0;

//     return maxi;
// }