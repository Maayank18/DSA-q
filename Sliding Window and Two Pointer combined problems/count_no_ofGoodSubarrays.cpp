// This problem basiacly aims on finding total number of subarray with the sum k
// the only twist that lies here that we can use the odd numbers only to find sum
// and check them 
 
// IF WE CLOSELY OBSERVE LIKE IF WE CONVERT ALL THE ODD NUMBER TO 1 AND 
// EVEN NUMBER TO 0 AND FIDNTHE SUM IT WILL BE SAME AND HERE WE WILL ALMOST BE
// USING THE CONCEPT OF BINARY SUBARRAY PROBLEM IN THIS LIST

// BRUTE FORCE APPROACH 
// TIME COMPLEXITY -> O(N^2) + O(N) = O(N)
// SPACE COMPLEXITY -> O(1)
// #include<iostream>
// #include<vector>
// using namespace std;

// int countGoodSubArray(vector<int> arr, int k){
//     int n = arr.size();
//     int count = 0;
//     for(int i = 0; i<n; i++){
//         if(arr[i]%2 == 0){
//             arr[i] = 0;
//         }else{
//             arr[i] = 1;
//         }
//     }

//     for(int i = 0; i<n; i++){
//         int sum  = 0;
//         for(int j = i; j<n; j++){
//             sum += arr[j];
//             if(sum == k){
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// int main(){
//     vector<int> arr = {1,5,2,1,1};
//     int countt = countGoodSubArray(arr,3);
//     cout<<" the good array count is : "<<countt<<endl;
//     return 0;
// }


// A better approach can be inclusion of sliding window and two pointer approach

#include<iostream>
#include<vector>
using namespace std;

int countGoodSubArray(vector<int> arr, int k){
    int n = arr.size();
    int r = 0;
    int l = 0;
    int counter = 0;

    for(int i = 0; i<n; i++){
        if(arr[i]%2 == 0){
            arr[i] = 0;
        }else{
            arr[i] = 1;
        }
    }

    int sum = 0;

    while(r<n){
        sum+=arr[r];
        if(sum>k && l<=r){
            sum-=arr[l++];
        }
        if(sum == k) counter++; 
        r++;
    }
    return counter;
}

int main(){
    vector<int> arr = {1,5,2,1,1};
    int countt = countGoodSubArray(arr,3);
    cout<<" the good array count is : "<<countt<<endl;
    return 0;
}