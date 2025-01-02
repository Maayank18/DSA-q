// this problem basically aims to find the k th missing number in array
// eg[ 2,3,4,7,11] find k = 5th missing number 
// here [1,5,6,8,9,10] are missing and answer is 9

//BRUTE FORCE APPROACH

// #include <bits/stdc++.h>
// using namespace std;

// int missingK(vector < int > vec, int n, int k) {
//     for (int i = 0; i < n; i++) {
//         if (vec[i] <= k) k++; //shifting k
//         else break;
//     }
//     return k;
// }


// int main()
// {
//     vector<int> vec = {4, 7, 9, 10};
//     int n = 4, k = 4;
//     int ans = missingK(vec, n, k);
//     cout << "The missing number is: " << ans << "\n";
//     return 0;
// }


// BINARY SEARCH - but not a common binary serach as we dont like
// x x x tick tick tick -> thisis not the case 
// instead we are fidning between what lies what

#include<iostream>
using namespace std;

int kth( int arr[], int n, int k){
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid  = low+ (high-low)/2;

        int missed = arr[mid] - (mid + 1);

        if( missed < k){
            low = mid + 1; 
        }else{
            high = mid - 1;
        }
    }
    return high+1+k;
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    int arr[n];

    cout<<" enter the elements : ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int k;
    cout<<" enter the missing term to be found : ";
    cin>>k;

    int missing = kth(arr,n,k);

    cout<<" the missing kth positive term is : "<<missing<<endl;
    return 0;
}
