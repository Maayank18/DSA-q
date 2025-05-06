#include <iostream>
#include <vector>
#include <algorithm>  // for std::max
using namespace std;

/*
-------------------------------------------------------------------------------------------------------
🧠 PROBLEM STATEMENT - NINJA TRAINING

A Ninja trains for 'n' days. Each day he can choose one of three activities:
  0 = Running
  1 = Fighting Practice
  2 = Learning New Moves

He earns points for each activity on each day, given in a 2D array `points[n][3]`.
However, he cannot perform the same activity on two consecutive days.

🔍 Objective:
  Compute the maximum total points the Ninja can earn in 'n' days under this constraint.
-------------------------------------------------------------------------------------------------------
*/

/// ======================= 1. RECURSIVE APPROACH (BRUTE FORCE) =======================
/// Time Complexity: O(3^n)    — exponential, tries all combinations
/// Space Complexity: O(n)     — recursion stack depth
int solveRec(int day, int lastTask, const vector<vector<int>>& points) {
    if (day == 0) {
        // On first day, pick the best activity ≠ lastTask
        int best = 0;
        for (int task = 0; task < 3; ++task) {
            if (task != lastTask)
                best = max(best, points[0][task]);
        }
        return best;
    }
    int best = 0;
    // Try each possible task not equal to yesterday's
    for (int task = 0; task < 3; ++task) {
        if (task == lastTask) continue;
        int pts = points[day][task]
                  + solveRec(day - 1, task, points);
        best = max(best, pts);
    }
    return best;
}
int ninjaTrainingRec(int n, const vector<vector<int>>& points) {
    // lastTask = 3 means “no restriction” on day 0
    return solveRec(n - 1, 3, points);
}

/// ======================= 2. MEMOIZATION (TOP-DOWN DP) =======================
/// Time Complexity: O(n * 4 * 3) = O(n)
/// Space Complexity: O(n * 4) for dp + O(n) recursion stack
int solveMem(int day, int lastTask,
             const vector<vector<int>>& points,
             vector<vector<int>>& dp) {
    if (dp[day][lastTask] != -1)
        return dp[day][lastTask];

    if (day == 0) {
        int best = 0;
        for (int task = 0; task < 3; ++task)
            if (task != lastTask)
                best = max(best, points[0][task]);
        return dp[day][lastTask] = best;
    }

    int best = 0;
    for (int task = 0; task < 3; ++task) {
        if (task == lastTask) continue;
        int pts = points[day][task]
                  + solveMem(day - 1, task, points, dp);
        best = max(best, pts);
    }
    return dp[day][lastTask] = best;
}
int ninjaTrainingMem(int n, const vector<vector<int>>& points) {
    // dp[day][lastTask] initialized to -1
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solveMem(n - 1, 3, points, dp);
}

/// ======================= 3. TABULATION (BOTTOM-UP DP) =======================
/// Time Complexity: O(n * 4 * 3) = O(n)
/// Space Complexity: O(n * 4)
int ninjaTrainingTab(int n, const vector<vector<int>>& points) {
    // dp[day][lastTask]: max points up to 'day' if yesterday did 'lastTask'
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base Case: Day 0
    dp[0][0] = max(points[0][1], points[0][2]);                   // if lastTask=0, can't do 0 today
    dp[0][1] = max(points[0][0], points[0][2]);                   // if lastTask=1, can't do 1 today
    dp[0][2] = max(points[0][0], points[0][1]);                   // if lastTask=2, can't do 2 today
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2])); // lastTask=3: no restriction

    for (int day = 1; day < n; ++day) {
        for (int last = 0; last < 4; ++last) {
            dp[day][last] = 0;
            for (int task = 0; task < 3; ++task) {
                if (task == last) continue;
                int pts = points[day][task] + dp[day - 1][task];
                dp[day][last] = max(dp[day][last], pts);
            }
        }
    }
    // Answer: no restriction on last task of final day
    return dp[n - 1][3];
}

/// ======================= 4. SPACE OPTIMIZATION =======================
/// Time Complexity: O(n * 4 * 3) = O(n)
/// Space Complexity: O(4) = O(1)
int ninjaTrainingOpt(int n, const vector<vector<int>>& points) {
    // prev[lastTask] holds dp for previous day
    vector<int> prev(4, 0), curr(4, 0);

    // Base Case: Day 0
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    for (int day = 1; day < n; ++day) {
        for (int last = 0; last < 4; ++last) {
            curr[last] = 0;
            for (int task = 0; task < 3; ++task) {
                if (task == last) continue;
                int pts = points[day][task] + prev[task];
                curr[last] = max(curr[last], pts);
            }
        }
        prev = curr;  // roll over
    }
    return prev[3];
}

/// ======================= DRIVER CODE =======================
int main() {
    vector<vector<int>> points = {
        {10, 40, 70},
        {20, 50, 80},
        {30, 60, 90},
        {40, 70, 100}
    };
    int n = points.size();

    cout << "1) Recursive:           "
         << ninjaTrainingRec(n, points) << "\n";
    cout << "2) Memoization:         "
         << ninjaTrainingMem(n, points) << "\n";
    cout << "3) Tabulation:          "
         << ninjaTrainingTab(n, points) << "\n";
    cout << "4) Space Optimization:  "
         << ninjaTrainingOpt(n, points) << "\n";

    return 0;
}
