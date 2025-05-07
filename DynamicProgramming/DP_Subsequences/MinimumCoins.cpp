/*
Problem Statement:
------------------
You are given an array `arr` of `n` coin denominations and a target value.
You need to determine the minimum number of coins required to make up the given target using any number of coins from `arr`.
Each coin can be used infinite times.

Example:
Input: arr = {1, 2, 3}, target = 8
Output: 3 (3 coins of 2+3+3 or 2+2+2+2 or 1+1+1+1+1+1+1+1)

Approach:
---------
1. Recursion (Exponential time)
2. Memoization (Top-Down DP)
3. Tabulation (Bottom-Up DP)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 1e9;

// ----------------------------
// 1. Recursive Approach
// ----------------------------
int recursive(int n, vector<int> &arr, int target) {
    // Base case: Only one denomination
    if (n == 0) {
        if (target % arr[0] == 0) return target / arr[0];
        return INF;
    }

    // Don't take current coin
    int notTake = recursive(n - 1, arr, target);

    // Take current coin if possible
    int take = INF;
    if (arr[n] <= target) {
        // n to take a coin as many time as possible
        take = 1 + recursive(n, arr, target - arr[n]);
    }

    return min(take, notTake);
}
// TC: O(2^target) in worst case
// SC: O(target) recursion stack (if skewed), O(1) otherwise

// ----------------------------
// 2. Memoization (Top-Down)
// ----------------------------
int memoization(int n, vector<int> &arr, int target, vector<vector<int>> &dp) {
    if (n == 0) {
        if (target % arr[0] == 0) return target / arr[0];
        return INF;
    }

    if (dp[n][target] != -1) return dp[n][target];

    int notTake = memoization(n - 1, arr, target, dp);

    int take = INF;
    if (arr[n] <= target) {
        take = 1 + memoization(n, arr, target - arr[n], dp);
    }

    return dp[n][target] = min(take, notTake);
}
// TC: O(n * target)
// SC: O(n * target) for dp + O(target) recursion stack

// ----------------------------
// 3. Tabulation (Bottom-Up)
// ----------------------------
int tabulation(int n, vector<int> &arr, int target) {
    vector<vector<int>> dp(n, vector<int>(target + 1, INF));

    // Fill base case for row 0
    for (int t = 0; t <= target; ++t) {
        if (t % arr[0] == 0) dp[0][t] = t / arr[0];
    }

    // Bottom-up filling
    for (int i = 1; i < n; ++i) {
        for (int t = 0; t <= target; ++t) {
            int notTake = dp[i - 1][t];
            int take = INF;
            if (arr[i] <= t) {
                take = 1 + dp[i][t - arr[i]];
            }
            dp[i][t] = min(take, notTake);
        }
    }

    return dp[n - 1][target];
}
// TC: O(n * target)
// SC: O(n * target) — can be optimized to O(target) with rolling array

// ----------------------------
// Main function to test all
// ----------------------------
int main() {
    int n = 3;
    vector<int> arr = {1, 2, 3};
    int target = 8;

    // Recursive
    int ans_rec = recursive(n - 1, arr, target);
    cout << "Minimum coins (Recursive): ";
    if (ans_rec >= INF) cout << -1 << endl;
    else cout << ans_rec << endl;

    // Memoization
    vector<vector<int>> dp(n, vector<int>(target + 1, -1));
    int ans_memo = memoization(n - 1, arr, target, dp);
    cout << "Minimum coins (Memoization): ";
    if (ans_memo >= INF) cout << -1 << endl;
    else cout << ans_memo << endl;

    // Tabulation
    int ans_tab = tabulation(n, arr, target);
    cout << "Minimum coins (Tabulation): ";
    if (ans_tab >= INF) cout << -1 << endl;
    else cout << ans_tab << endl;

    return 0;
}
