// brute force solution is getting all subrays and checking for each of the them 
// which would be having a time complexity of o(n^3) but we see that k is not much
//useful hence we can use i and j only for the better solutij O(n^2)

#include <iostream>
using namespace std;

int MaxSubArr ( int arr[], int n){
    int maxi = 0;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int sum = 0;
            for( int k = i; k<=j; k++){
                sum = sum+arr[k];
            }
            maxi = max(maxi,sum);
        }
    }
    return maxi;
}

int main() {
    int n;
    cout<<" enter the size of array : ";
    cin>>n;
    
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<" enter array by user : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i];
    }
    cout<<endl;
    
    int MaxSum = MaxSubArr(arr,n);
    
    cout<<" the sub array with maximum sum is : "<< MaxSum;
    return 0;
}


// better solution is nothing but we can just simply remove the third loop from code
// reduce time complexity from 0(n^3) to some what about 0(n^2)

#include <iostream>
using namespace std;

int MaxSubArr ( int arr[], int n){
    int maxi = 0;
    for(int i = 0; i<n; i++){
        int sum = 0;
        for(int j = i; j<n; j++){
            sum = sum+arr[j];
             maxi = max(maxi,sum);
        }
    }
    return maxi;
}

int main() {
    int n;
    cout<<" enter the size of array : ";
    cin>>n;
    
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<" enter array by user : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i];
    }
    cout<<endl;
    
    int MaxSum = MaxSubArr(arr,n);
    
    cout<<" the sub array with maximum sum is : "<< MaxSum;
    return 0;
}


//KADANE ALGORITHM ( Most optimal approach )// biog o(n)
#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int MaxSubArr ( int arr[], int n){
    int sum = 0;
    int maxi = 0;
    for(int i = 0; i<n; i++){
        sum = sum+arr[i];
        maxi = max(maxi,sum);
        if(sum<0){
            sum = 0;
        }
    }
    return maxi;
}

int main() {
    int n;
    cout<<" enter the size of array : ";
    cin>>n;
    
    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<" enter array by user : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i];
    }
    cout<<endl;
    
    int MaxSum = MaxSubArr(arr,n);
    
    cout<<" the sub array with maximum sum is : "<< MaxSum;
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