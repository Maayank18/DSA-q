// divide the array in exactly two part such that sum of both subste is exactly same
// we can do something like find a subset whose sum is totalSum/2
// we can use the DP 14 lectures

#include<iostream>
#include<vector>
using namespace std;

bool checking(int n, int target, vector<int> &arr){
    if(n == 0){
        if(arr[0] == target){
            return true;
        }else{
            return false;
        }
    }

    if(target == 0) return true;

    bool notTake = checking(n-1,target,arr);

    bool Take = false;
    if(arr[n] < target){
        Take = checking(n-1,target-arr[n],arr);
    }

    return Take || notTake;
}

bool find(int n,vector<int>&arr){

    // finding sum of whole array
    int sumT = 0;
    for( int i = 0; i<=n; i++){
        sumT+=arr[i];
    }

    if (sumT % 2 != 0) return false; // can't divide into equal subsets

    int target = sumT/2; // this is our new target

    return checking(n,target,arr);
}

int main(){
    int n = 6;
    vector<int> arr = {2,3,3,3,4,5};
    bool Exist = find(n-1,arr);
    cout<<Exist;
    return 0;
}




/*
    Time Complexity (TC): O(n * target) 
        - Each state (n, target) is computed once
    Space Complexity (SC): O(n * target) for DP + O(n) recursion stack
*/

// Memoized function to check subset with sum = target
bool isSubsetSumMemo(int n, int target, vector<int>& arr, vector<vector<int>>& dp) {
    if (target == 0) return true;
    if (n == 0) return arr[0] == target;

    if (dp[n][target] != -1) return dp[n][target];

    bool notTake = isSubsetSumMemo(n - 1, target, arr, dp);
    bool take = false;
    if (arr[n] <= target)
        take = isSubsetSumMemo(n - 1, target - arr[n], arr, dp);

    return dp[n][target] = take || notTake;
}

bool canPartitionMemo(vector<int>& arr) {
    int totalSum = 0;
    for (int num : arr) totalSum += num;

    if (totalSum % 2 != 0) return false;  // Cannot divide odd sum into two equal parts

    int target = totalSum / 2;
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));

    return isSubsetSumMemo(n - 1, target, arr, dp);
}





/*
    Time Complexity (TC): O(n * target)
        - For each element and each target value, we compute once
    Space Complexity (SC): O(n * target)
        - 2D DP table
*/

bool canPartitionTab(vector<int>& arr) {
    int totalSum = 0;
    for (int num : arr) totalSum += num;

    if (totalSum % 2 != 0) return false;  // Cannot divide odd sum into two equal parts

    int target = totalSum / 2;
    int n = arr.size();
    vector<vector<bool>> dp(n, vector<bool>(target + 1, false));

    // Base case: sum = 0 is always possible
    for (int i = 0; i < n; i++) dp[i][0] = true;

    // Base case: first element can form subset if it equals to target
    if (arr[0] <= target)
        dp[0][arr[0]] = true;

    // Bottom-up DP table fill
    for (int i = 1; i < n; i++) {
        for (int t = 1; t <= target; t++) {
            bool notTake = dp[i - 1][t];
            bool take = false;
            if (arr[i] <= t)
                take = dp[i - 1][t - arr[i]];

            dp[i][t] = take || notTake;
        }
    }

    return dp[n - 1][target];
}







