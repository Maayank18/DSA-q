#include<iostream>
#include<vector>
using namespace std;

// WAY 1 OF SOLVING IS RECURSION
// TC ->O(2^n) -> for every move we have two option
// SC -> O(n) = recusion stack space

// alawys start checking for basecase from the parameters given in the fucntion

// bool isTarget(int n, vector<int> &arr, int target){

//     // base case 1 -> if my target == 0 hence it exist 
//     if(target == 0) return true;

//     // base case 2 -> if we are done checking and only one element is left
//     // then that has to be equal to our target
//     if(n == 0) return (arr[0] == target);


//     // now we will do our stuff
//     bool notTake = isTarget(n-1,arr,target);
//     bool Take = isTarget(n-1,arr,target-arr[n]);

//     return notTake || Take;
// }

// int main(){
//     int n = 4; // size of array
//     vector<int> arr = {1,2,3,4};
//     int target = 4;
//     bool ans = isTarget(n-1,arr,target);
//     return 0;
// }



// WAY 2 of SOLVING IS -> MEMOISATION
// TC -> O(n x target)
// SC -> O(nxtarget) + O(n)

// bool isTarget(int n, vector<int> &arr, int target, vector<vector<int>>& dp){

//     // base case 1 -> if my target == 0 hence it exist 
//     if(target == 0) return true;

//     // base case 2 -> if we are done checking and only one element is left
//     // then that has to be equal to our target
//     if(n == 0) return (arr[0] == target);

//     // base case 3 -> for checking sub dp
//     if(dp[n][target] != -1){
//         return dp[n][target];
//     }


//     // now we will do our stuff
//     bool notTake = isTarget(n-1,arr,target,dp);
//     bool Take = false;
//         if(arr[n] < target){   // if my target is greater i can pick 
//             Take = isTarget(n-1,arr,target-arr[n],dp);
//         }

//     return dp[n][target] =  notTake || Take;
// }

// int main(){
//     int n = 4; // size of array
//     vector<int> arr = {1,2,3,4};
//     int target = 4;
//     vector<vector<int>> dp(n, vector<int>(target + 1, -1));
//     bool ans = isTarget(n-1,arr,target,dp);
//     cout<<ans;
//     return 0;
// }



// WAY 3 IS TABULATION

bool isTarget(int n, vector<int> &arr, int target) {
    // Create DP table with default false values
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // Base Case 1: Target = 0 is always possible (empty subset)
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }

    // Base Case 2: If first element is within target, mark it true
    if (arr[0] <= target)
        dp[0][arr[0]] = true;

    // Fill the DP table
    for (int i = 1; i < n; i++) {
        for (int t = 1; t <= target; t++) {
            bool notTake = dp[i - 1][t]; // Exclude current element
            bool take = false;
            if (arr[i] <= t)
                take = dp[i - 1][t - arr[i]]; // Include current element

            dp[i][t] = take || notTake;
        }
    }

    return dp[n - 1][target];
}

int main(){
    int n = 4; // size of array
    vector<int> arr = {1,2,3,4};
    int target = 4;
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    bool ans = isTarget(n-1,arr,target,dp);
    cout<<ans;
    return 0;
}