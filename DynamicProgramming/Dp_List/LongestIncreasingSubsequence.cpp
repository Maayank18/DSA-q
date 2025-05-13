// what the question ask me is find the longest subsequence that is in increasing order
// eg = [10,9,3,5,2,6,7,8,1]
// we can have so many subsequences possible but the biggest is 3,5,6,7,8 of length 5
// and at end we want to retrun the length 



// // WAY 1 OF DOIN BY RECURSION
// // TC -> O(2^N)
// // SC -> O(N) = RECURSION STACK SPACE 
// #include<iostream>
// #include<vector>
// using namespace std;

// int f(int idx, int n, vector<int>&arr, int prevIdx){

//     int length = 0;

//     // BASE CASE IF OUR ARRAY GETS EXHAUSTED
//     if(idx == n) return 0;


//     // case where we can take that element 
//     // we know that we can always take out element at 0 index at before it we have -1
//     // also we have take any element if it is greater than its previous
//     // TAKE CASE
//     if(prevIdx == -1 || arr[idx] > arr[prevIdx]){
//         int take = 1 + f(idx+1,n,arr,idx);
//         length = max(length,take);
//     }

//     // not take case 
//     // if i am not taking the element just skip the index
//     int notTake = 0 + f(idx+1,n,arr,prevIdx);
//     length = max(length,notTake);


//     return length;
// }

// int main(){
//     int n = 9;
//     vector<int> arr = {10,9,3,5,2,6,7,8,1};
//     int previousIndex = -1;
//     int maxLength = f(0,n,arr,previousIndex);
//     cout<<" the longest increasing subsequence is : "<<maxLength<<endl;
//     return 0;
// }





// WAY 2 OF DOIN BY MEMOISATION
// TC -> O(N)
// SC -> O(N) = RECURSION STACK SPACE 
#include<iostream>
#include<vector>
using namespace std;

int f(int idx, int n, vector<int>&arr, int prevIdx, vector<vector<int>>&dp){

    int length = 0;

    // BASE CASE IF OUR ARRAY GETS EXHAUSTED
    if(idx == n) return 0;

    // base case 2
    if(dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx];

    // case where we can take that element 
    // we know that we can always take out element at 0 index at before it we have -1
    // also we have take any element if it is greater than its previous
    // TAKE CASE
    if(prevIdx == -1 || arr[idx] > arr[prevIdx]){
        int take = 1 + f(idx+1,n,arr,idx,dp);
        length = max(length,take);
    }

    // not take case 
    // if i am not taking the element just skip the index
    int notTake = 0 + f(idx+1,n,arr,prevIdx,dp);
    length = max(length,notTake);


    return dp[idx][prevIdx+1] = length;
}

int main(){
    int n = 9;
    vector<int> arr = {10,9,3,5,2,6,7,8,1};
    int previousIndex = -1;
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    int maxLength = f(0,n,arr,previousIndex,dp);
    cout<<" the longest increasing subsequence is : "<<maxLength<<endl;
    return 0;
}