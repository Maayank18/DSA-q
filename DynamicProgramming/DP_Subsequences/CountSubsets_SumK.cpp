#include<iostream>
#include<vector>
using namespace std;


// WAY 1 IS SIMPLE RECURSION TECHNIQUE OF PICKA DN NO PICK
// TC -> O(2^N) = two choices available
// SC -> O(n) = auxillary stack space

// int subsets(int n, vector<int> &arr, int target){

//     // base case 1
//     if( target == 0 ) return 1;

//     // base case 2
//     if( n == 0 ){
//         return arr[0] == target;
//     }

//     int notPick = subsets(n-1,arr,target);
//     int Pick = 0;
//         if(arr[n] <= target){
//             Pick = subsets(n-1,arr,target-arr[n]);
//         }

//     return notPick + Pick;
// }

// int main(){
//     int n = 4;
//     vector<int> arr = {1,2,2,3};
//     int target = 3;
//     int totalCount = subsets(n-1,arr,target);
//     cout<<totalCount<<endl;
//     return 0;
// }




// way 2 of solving is MEMOISATION as it has overlapping sub problems
// TC -> o( n x target)
// SC -> o( n + sum) + o(n)


// int subsets(int n, vector<int> &arr, int target,vector<vector<int>> &dp){

//     // base case 1
//     if( target == 0 ) return 1;

//     // base case 2
//     if( n == 0 ){
//         return arr[0] == target;
//     }

//     // base case 3
//     if( dp[n][target] != -1) return dp[n];

//     int notPick = subsets(n-1,arr,target,dp);
//     int Pick = 0;
//         if(arr[n] <= target){
//             Pick = subsets(n-1,arr,target-arr[n],dp);
//         }

//     return dp[n][target] = notPick + Pick;
// }

// int main(){
//     int n = 4;
//     vector<int> arr = {1,2,2,3};
//     int target = 3;
//     vector<vector<int>> dp(n,vector<int>(target+1,-1));
//     int totalCount = subsets(n-1,arr,target,dp);
//     cout<<totalCount<<endl;
//     return 0;
// }





// way 3 of solving will be tabulation
// TC -> 
// SC -> 


int subsets(int n, vector<int>& arr, int target, vector<vector<int>>& dp) {
    // base case 1: There's always 1 way to achieve a sum of 0 (by picking no elements)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    // base case 2: if arr[0] is less than or equal to target, we can pick it
    if (arr[0] <= target) {
        dp[0][arr[0]] = 1;
    }

    // Fill the dp table
    for (int i = 1; i < n; i++) {  // loop over elements of arr
        for (int t = 0; t <= target; t++) {  // loop over all possible target values
            int notPick = dp[i-1][t];  // number of ways to achieve sum `t` without picking arr[i]
            int Pick = 0;
            if (arr[i] <= t) {  // if current element can contribute to the sum
                Pick = dp[i-1][t - arr[i]];  // number of ways to achieve sum `t - arr[i]`
            }
            dp[i][t] = notPick + Pick;  // total ways by either picking or not picking arr[i]
        }
    }

    return dp[n-1][target];  // return the result
}

int main(){
    int n = 4;
    vector<int> arr = {1,2,2,3};
    int target = 3;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    int totalCount = subsets(n-1,arr,target,dp);
    cout<<totalCount<<endl;
    return 0;
}