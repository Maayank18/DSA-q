#include<iostream>
#include<vector>
using namespace std;

// RECURSION APPROACH 

// Recursive function to calculate the maximum points
int f(int day, int last, vector<vector<int>> &points) {

    // Base case: If we are on the first day (day 0)
    if (day == 0) {
        int maxi = 0;

        // Try all tasks (0, 1, 2) except the one done on the last day
        for (int task = 0; task <= 2; task++) {
            if (task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    int maxi = 0;

    // For each possible task of the current day
    for (int task = 0; task <= 2; task++) {
        if (task != last) {
            // Points for current task + recursive call for previous day
            int point = points[day][task] + f(day - 1, task, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}

// Wrapper function to start the recursive calls
int ninjaTraining(int n, vector<vector<int>> &points) {
    // We use '3' as 'last' because 0, 1, 2 are valid tasks and 3 means no task restriction on the first day
    return f(n - 1, 3, points);
}


// MEMOISATION APPROACH OF DOING IT 


// Recursive function with memoization to compute maximum points
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
    
    // Base case: on day 0, choose the best task not equal to 'last'
    if (day == 0) {
        int maxi = 0;
        for (int task = 0; task <= 2; task++) {
            if (task != last) {
                maxi = max(maxi, points[0][task]);
            }
        }
        return maxi;
    }

    // If already computed, return the stored result
    if (dp[day][last] != -1)
        return dp[day][last];

    int maxi = 0;

    // Try all tasks not equal to 'last' and take the maximum
    for (int task = 0; task <= 2; task++) {
        if (task != last) {
            int point = points[day][task] + f(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }

    // Store the result in dp table and return it
    return dp[day][last] = maxi;
}

// Function to initialize dp and call recursive function
int ninjaTraining(int n, vector<vector<int>> &points) {
    // dp[day][last]: max points on 'day' when 'last' task was done the day before
    vector<vector<int>> dp(n, vector<int>(4, -1));
    
    // 'last' is 3 initially to indicate no task was done the previous day
    return f(n - 1, 3, points, dp);
}




// TABULATION

int ninjaTraining(int n, vector<vector<int>> &points) {
    // dp[day][last] stores max points from day 0 to day "day" 
    // where "last" is the activity done on the previous day (0, 1, 2, or 3 meaning 'none')
    vector<vector<int>> dp(n, vector<int>(4, 0));

    // Base Case: Day 0
    dp[0][0] = max(points[0][1], points[0][2]); // last = 0 => don't do 0 today
    dp[0][1] = max(points[0][0], points[0][2]); // last = 1 => don't do 1 today
    dp[0][2] = max(points[0][0], points[0][1]); // last = 2 => don't do 2 today
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]}); // last = 3 => can do any

    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }

    return dp[n - 1][3]; // last = 3 means no restriction on last task
}                 




// SPACE OPTIMISATION

int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<int> prev(4, 0);

    // Base Case: Day 0
    prev[0] = max(points[0][1], points[0][2]); // last = 0
    prev[1] = max(points[0][0], points[0][2]); // last = 1
    prev[2] = max(points[0][0], points[0][1]); // last = 2
    prev[3] = max({points[0][0], points[0][1], points[0][2]}); // last = 3

    for (int day = 1; day < n; day++) {
        vector<int> curr(4, 0);
        for (int last = 0; last < 4; last++) {
            curr[last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + prev[task];
                    curr[last] = max(curr[last], point);
                }
            }
        }
        prev = curr;
    }

    return prev[3]; // max points possible with no last task restriction
}