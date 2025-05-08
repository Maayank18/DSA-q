// Given an array nums of n integers and an integer target, 
// build an expression using the integers from nums where each integer
// can be prefixed with either a '+' or '-' sign. The goal is to
// achieve the target sum by evaluating all possible combinations of these
// signs. Determine the number of ways to achieve the target sum 
// and return your answer with modulo 109+7.


// important thing to oberve is it is much much much similar to partition 
// difference = target ptoblem 
// where s1 - s2 = target

// another way of solving this is assigning the "-","+" operation and here is 
// the code for that

// Example:
// Input: arr = {1, 1, 2, 3}, target = 1
// Output: 3
// Explanation: The expressions are: 
// (1 + 1 - 2 + 3), (1 - 1 + 2 - 3), (-1 + 1 + 2 - 3)



#include<iostream>
#include<vector>
using namespace std;

// ----------------------------
// 1. Recursive Approach
// ----------------------------
int countWaysRec(int i, int sum, vector<int> &arr, int target) {
    // Base case: all elements processed
    if (i == arr.size()) {
        return (sum == target) ? 1 : 0;
    }

    // Choose '+' sign
    int plus = countWaysRec(i + 1, sum + arr[i], arr, target);

    // Choose '-' sign
    int minus = countWaysRec(i + 1, sum - arr[i], arr, target);

    return plus + minus;
}
// TC: O(2^n)
// SC: O(n) recursion stack

// ----------------------------
// 2. Memoization (Top-Down)
// ----------------------------
int countWaysMemo(int i, int sum, vector<int> &arr, int target, vector<vector<int>> &dp, int offset) {
    if (i == arr.size()) {
        return (sum == target) ? 1 : 0;
    }

    if (dp[i][sum + offset] != -1) return dp[i][sum + offset];

    int plus = countWaysMemo(i + 1, sum + arr[i], arr, target, dp, offset);
    int minus = countWaysMemo(i + 1, sum - arr[i], arr, target, dp, offset);

    return dp[i][sum + offset] = plus + minus;
}
// TC: O(n * range), where range = sum of all elements
// SC: O(n * range)

// ----------------------------
// 3. Tabulation (Bottom-Up)
// ----------------------------
int countWaysTab(vector<int> &arr, int target) {
    int n = arr.size();
    int sum = 0;
    for (int x : arr) sum += x;

    // Check if target is out of possible range
    if (abs(target) > sum) return 0;

    int offset = sum; // to handle negative indices
    vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));

    // base case: 0 sum is one way (empty expression)
    dp[0][offset] = 1;

    for (int i = 1; i <= n; i++) {
        for (int s = -sum; s <= sum; s++) {
            if ((s + arr[i - 1] + offset) <= 2 * sum)
                dp[i][s + offset] += dp[i - 1][s + arr[i - 1] + offset];
            if ((s - arr[i - 1] + offset) >= 0)
                dp[i][s + offset] += dp[i - 1][s - arr[i - 1] + offset];
        }
    }

    return dp[n][target + offset];
}
// TC: O(n * sum)
// SC: O(n * sum)

// ----------------------------
// Main function
// ----------------------------
int main() {
    vector<int> arr = {1, 1, 2, 3};
    int target = 1;

    // Recursive
    int ways_rec = countWaysRec(0, 0, arr, target);
    cout << "Ways (Recursive): " << ways_rec << endl;

    // Memoization
    int total_sum = 0;
    for (int num : arr) total_sum += num;
    int offset = total_sum; // to handle negative sums in dp index
    vector<vector<int>> dp(arr.size(), vector<int>(2 * total_sum + 1, -1));
    int ways_memo = countWaysMemo(0, 0, arr, target, dp, offset);
    cout << "Ways (Memoization): " << ways_memo << endl;

    // Tabulation
    int ways_tab = countWaysTab(arr, target);
    cout << "Ways (Tabulation): " << ways_tab << endl;

    return 0;
}
