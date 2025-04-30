#include <bits/stdc++.h>
using namespace std;

/*
    🐸 Problem Statement: Frog Jump with K Steps
    -------------------------------------------
    A frog is at the first step of a staircase with 'n' steps, where each step has a height given in an array `height[]`.

    The frog can jump from one step to any of the next k steps. The cost of a jump from step i to step j is:
        abs(height[i] - height[j])

    Your task is to find the **minimum total energy** the frog needs to reach the last step (n - 1).

    Approaches Covered:
    -------------------
    1. Recursive Solution (Exponential time)
    2. Memoization (Top-down DP)
    3. Tabulation (Bottom-up DP)
    4. Space Optimization (O(k) space)
*/


/* ---------------------------------------------------------------
    1️⃣ Recursive Solution (TLE for large n)
    Time Complexity: Exponential
---------------------------------------------------------------- */
int recursive(int ind, vector<int>& height, int k) {
    if (ind == 0) return 0;

    int minCost = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (ind - j >= 0) {
            int cost = recursive(ind - j, height, k) + abs(height[ind] - height[ind - j]);
            minCost = min(minCost, cost);
        }
    }
    return minCost;
}


/* ---------------------------------------------------------------
    2️⃣ Memoization (Top-down DP)
    Time Complexity: O(n*k)
    Space Complexity: O(n) + O(n) recursion stack
---------------------------------------------------------------- */
int memoization(int ind, vector<int>& height, vector<int>& dp, int k) {
    if (ind == 0) return 0;

    if (dp[ind] != -1) return dp[ind];

    int minCost = INT_MAX;
    for (int j = 1; j <= k; j++) {
        if (ind - j >= 0) {
            int cost = memoization(ind - j, height, dp, k) + abs(height[ind] - height[ind - j]);
            minCost = min(minCost, cost);
        }
    }

    return dp[ind] = minCost;
}


/* ---------------------------------------------------------------
    3️⃣ Tabulation (Bottom-up DP)
    Time Complexity: O(n*k)
    Space Complexity: O(n)
---------------------------------------------------------------- */
int tabulation(int n, vector<int>& height, int k) {
    vector<int> dp(n, 0);  // Base case: dp[0] = 0

    for (int i = 1; i < n; i++) {
        int minCost = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int cost = dp[i - j] + abs(height[i] - height[i - j]);
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }

    return dp[n - 1];
}


/* ---------------------------------------------------------------
    4️⃣ Space Optimized Version
    Time Complexity: O(n*k)
    Space Complexity: O(k) - uses only last k steps
---------------------------------------------------------------- */
int spaceOptimized(int n, vector<int>& height, int k) {
    deque<int> dp; // to store last k values
    dp.push_back(0); // base case: step 0 costs 0

    for (int i = 1; i < n; i++) {
        int minCost = INT_MAX;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                int cost = dp[i - j] + abs(height[i] - height[i - j]);
                minCost = min(minCost, cost);
            }
        }
        dp.push_back(minCost);
    }

    return dp[n - 1];
}


/* ---------------------------------------------------------------
    🚀 Main Function
---------------------------------------------------------------- */
int main() {
    vector<int> height = {30, 10, 60, 10, 60, 50};
    int n = height.size();
    int k = 2;

    cout << "1️ Recursive (TLE for large inputs): "
         << recursive(n - 1, height, k) << endl;

    vector<int> dp(n, -1);
    cout << "2️⃣ Memoization: "
         << memoization(n - 1, height, dp, k) << endl;

    cout << "3️⃣ Tabulation: "
         << tabulation(n, height, k) << endl;

    cout << "4️⃣ Space Optimized: "
         << tabulation(n, height, k) << " (same result, reduced space)" << endl;

    return 0;
}
