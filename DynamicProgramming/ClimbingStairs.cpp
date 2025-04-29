#include<iostream>
#include<vector>
using namespace std;

/*
---------------------------------------------
📌 PROBLEM STATEMENT:
You are given a staircase with 'n' steps.
You can take either 1 step or 2 steps at a time.
Find the total number of distinct ways to reach the top.

🔁 This is a classic Dynamic Programming problem.

Example:
n = 3
Ways: [1+1+1], [1+2], [2+1] → Total = 3 ways
---------------------------------------------

🧠 Recurrence Relation:
f(n) = f(n-1) + f(n-2)

This is because:
- To reach the nth step, you could've come from (n-1)th step by taking 1 step,
- OR from (n-2)th step by taking 2 steps.
---------------------------------------------
*/


// 1️⃣ RECURSION (Brute-force)
// Time: O(2^n), Space: O(n) due to recursion stack
int climbStairsRecursive(int n) {
    if(n == 0 || n == 1) return 1;
    return climbStairsRecursive(n-1) + climbStairsRecursive(n-2);
}


// 2️⃣ MEMOIZATION (Top-Down DP)
// Time: O(n), Space: O(n) for dp + recursion stack
int climbStairsMemo(int n, vector<int>& dp) {
    if(n == 0 || n == 1) return 1;

    if(dp[n] != -1) return dp[n];  // If already computed, return the stored result

    // Store and return the result
    return dp[n] = climbStairsMemo(n-1, dp) + climbStairsMemo(n-2, dp);
}


// 3️⃣ TABULATION (Bottom-Up DP) – Preferred in interviews
// Time: O(n), Space: O(n)
int climbStairsTab(int n) {
    if(n == 0 || n == 1) return 1;

    vector<int> dp(n+1, 0); // dp[i] will store number of ways to reach i-th step
    dp[0] = 1;  // 1 way to stay at ground
    dp[1] = 1;  // 1 way to reach 1st step

    for(int i = 2; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}


// 🔁 BONUS: SPACE OPTIMIZED TABULATION
// Time: O(n), Space: O(1)
int climbStairsOptimized(int n) {
    if(n == 0 || n == 1) return 1;

    int prev2 = 1; // f(0)
    int prev1 = 1; // f(1)
    int curr = 0;

    for(int i = 2; i <= n; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}


int main() {
    int n;
    cout << "Enter the number of stairs: ";
    cin >> n;

    // 1. Recursive (not recommended for large n)
    cout << "\n🔁 Recursive approach result: ";
    cout << climbStairsRecursive(n);

    // 2. Memoization
    vector<int> dp(n+1, -1);
    cout << "\n🧠 Memoization approach result: ";
    cout << climbStairsMemo(n, dp);

    // 3. Tabulation
    cout << "\n📊 Tabulation approach result: ";
    cout << climbStairsTab(n);

    // 4. Space Optimized
    cout << "\n💡 Space Optimized approach result: ";
    cout << climbStairsOptimized(n);

    cout << "\n";

    return 0;
}
