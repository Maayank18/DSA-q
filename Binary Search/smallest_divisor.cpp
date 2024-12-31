// find th esmallest divisor givena thrshhold value whta is means is
// consider [1,2,5,9] and the threshold = 6;

// find the smallest divisor such that 1/d + 2/d + 5/d + 9/d ( taking all the ceil value)
// should sum up and be <= threshold value 

// eg, let d= 4 -> 1/4 + 2/4 + 5/4 + 9/4 = 7>6 hence not the answer 


// BRUTE FORCE SOLUTION

// #include<iostream>
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

// Optimal Solution somehwere refers to binary approach where we can observe that 
// till some point answer is valid and after that it is not so Binary serach works
// TIME COMPLEXITY OF SOMEWHAT O(log2(maxValue) x N)

#include<iostream>
using namespace std;

int max_num(int arr[], int n){
    int max = arr[0];
    for(int i = 0;i<n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int smallest_divisor(int arr[], int n, int threshhold){
    int maxValue = max_num(arr,n);
    int low = 1;
    int high = maxValue;

    while(low<=high){
        int mid = low+ (high-low)/2;

        int sum = 0;
        for( int i = 0; i<n; i++){
            sum += (arr[i] + mid - 1)/mid;
        }
        if( sum <= threshhold){
            return mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
}

int main(){
    int n;
    cout<<" enter the size of array  : ";
    cin>>n;

    int arr[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int threshhold;
    cout<<" enter the threshhold value : ";
    cin>>threshhold;

    int result = smallest_divisor(arr,n,threshhold);

    cout<<" the smallest divisor possible is: "<<result<<endl;

    return 0;
}

