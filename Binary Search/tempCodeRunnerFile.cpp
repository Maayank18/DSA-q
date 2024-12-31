#include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int smallest_divisor( int arr[], int n, int threshhold){
//     for( int i = 1; i<INT_MAX; i++){
//         int sum = 0;
//         for( int j = 0; j<n; j++){
//             sum += (arr[j] + i - 1)/i;
//         }
//         if( sum <= threshhold){
//             return i;
//         }
//     }
// }

// int main(){
//     int n;
//     cout<<" enter the size of array  : ";
//     cin>>n;

//     int arr[n];

//     for(int i = 0; i<n; i++){
//         cin>>arr[i];
//     }

//     int threshhold;
//     cout<<" enter the threshhold value : ";
//     cin>>threshhold;

//     int result = smallest_divisor(arr,n,threshhold);

//     cout<<" the smallest divisor possible is: "<<result<<endl;

//     return 0;
// }