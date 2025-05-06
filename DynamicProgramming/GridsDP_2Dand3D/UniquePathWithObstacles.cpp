// ✅ Problem Statement Recap:
// Given a grid of size n x m with obstacles (–1 represents an obstacle),
// count the number of unique paths from the top-left corner (0,0) to the bottom-right corner (n-1,m-1).
// You can only move right or down and cannot step on obstacles.

#include <iostream>
#include <vector>
using namespace std;

// ------------------------ WAY 1: PURE RECURSION ------------------------
// Time Complexity: O(2^(n+m))   (exponential branching)
// Space Complexity: O(n + m)    (recursion stack depth)
int findingRec(int row, int col, vector<vector<int>>& grid) {
    // Base Case: out of bounds or obstacle
    if (row < 0 || col < 0 || grid[row][col] == -1) return 0;
    // Base Case: reached start
    if (row == 0 && col == 0) return 1;
    
    int fromUp = findingRec(row - 1, col, grid);
    int fromLeft = findingRec(row, col - 1, grid);
    return fromUp + fromLeft;
}

// ------------------------ WAY 2: MEMOIZATION (Top-Down) ------------------------
// Time Complexity: O(n * m)
// Space Complexity: O(n * m) for dp + O(n + m) recursion stack
int findingMemo(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp) {
    // Base Case: out of bounds or obstacle
    if (row < 0 || col < 0 || grid[row][col] == -1) return 0;
    // Base Case: reached start
    if (row == 0 && col == 0) return 1;

    if (dp[row][col] != -1) return dp[row][col];

    int fromUp = findingMemo(row - 1, col, grid, dp);
    int fromLeft = findingMemo(row, col - 1, grid, dp);
    return dp[row][col] = fromUp + fromLeft;
}

// ------------------------ WAY 3: TABULATION (Bottom-Up) ------------------------
// Time Complexity: O(n * m)
// Space Complexity: O(n * m)
int findingTab(int n, int m, vector<vector<int>>& grid) {
    vector<vector<int>> dp(n, vector<int>(m, 0));
    
    // Initialize starting cell
    if (grid[0][0] == -1) return 0;
    dp[0][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0) continue;
            if (grid[i][j] == -1) {
                dp[i][j] = 0;
            } else {
                int fromUp = (i > 0 ? dp[i-1][j] : 0);
                int fromLeft = (j > 0 ? dp[i][j-1] : 0);
                dp[i][j] = fromUp + fromLeft;
            }
        }
    }
    return dp[n-1][m-1];
}

int main() {
    int n = 3; // rows
    int m = 3; // columns
    vector<vector<int>> grid = {
        {0,  0,  0},
        {0, -1,  0}, // obstacle at (1,1) represented by -1
        {0,  0,  0}
    };
    
    // Recursion
    int ansRec = findingRec(n-1, m-1, grid);
    cout << "[Recursion] Total unique paths: " << ansRec << endl;
    
    // Memoization
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int ansMemo = findingMemo(n-1, m-1, grid, dp);
    cout << "[Memoization] Total unique paths: " << ansMemo << endl;
    
    // Tabulation
    int ansTab = findingTab(n, m, grid);
    cout << "[Tabulation] Total unique paths: " << ansTab << endl;
    
    return 0;
}
