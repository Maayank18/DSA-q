#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// WAY ONE OF SOLVING -> RECURSION 
// TC -> 3^n = exponential
// SC -> O(n) = recursion stack space

// int f(int i, int j, vector<vector<int>> &grid){
    
//     // base case 1
//     // as we are starting from down to up and if we reach 0th row we return
//     if(i == 0) return grid[i][j];

//     // base case 2 for 1st adn alst column left diagonal and right diagonal
//     // will be out ofbound respectively
//     if(j<0 || j>grid[0].size()-1) return INT_MIN;

//     int up = grid[i][j] + f(i-1,j,grid);
//     int leftDiagonal = grid[i][j] + f(i-1,j-1,grid);
//     int rightDiagonal = grid[i][j] + f(i-1,j+1,grid);

//     return max(up,max(leftDiagonal,rightDiagonal));
// }

// int maxFallingPath(int n, int m, vector<vector<int>>&grid){
//     int maxi = -1e8;
//     for(int j = 0; j<m; j++){
//         maxi = max(maxi,f(n-1,j,grid));
//     }
//     return maxi;
// }

// int main(){
//     int n = 4;
//     int m = 4;
//     vector<vector<int>> grid = {{1,2,10,4},{100,3,2,1},{1,1,20,2},{1,2,2,1}};
//     int ans = maxFallingPath(n,m,grid);
//     cout<<"the max falling path is : "<<ans<<endl;
//     return 0;
// }



// WAY 2 FOR SOLVING WILL BE - Memoisation 
// ✅ Time Complexity (TC):O(N × M)
// There are N rows and M columns.
// For each cell (i, j), the function f(i, j) is computed only once and stored in dp[i][j].
// So, total number of unique calls = N × M.

// ✅ Space Complexity (SC):O(N × M) + O(N)
// O(N × M) for the dp table storing intermediate results.
// O(N) for the maximum recursion depth (from row n-1 up to 0), which consumes stack space.

// int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
//     if(j < 0 || j >= grid[0].size()) return INT_MIN;
//     if(i == 0) return grid[0][j];

//     // check memo table
//     if(dp[i][j] != -1) return dp[i][j];

//     int up = grid[i][j] + f(i-1, j, grid, dp);
//     int leftDiagonal = grid[i][j] + f(i-1, j-1, grid, dp);
//     int rightDiagonal = grid[i][j] + f(i-1, j+1, grid, dp);

//     // store and return
//     return dp[i][j] = max(up, max(leftDiagonal, rightDiagonal));
// }

// int maxFallingPath(int n, int m, vector<vector<int>>& grid){
//     vector<vector<int>> dp(n, vector<int>(m, -1)); // memo table
//     int maxi = INT_MIN;
//     for(int j = 0; j < m; j++){
//         maxi = max(maxi, f(n-1, j, grid, dp));
//     }
//     return maxi;
// }

// int main(){
//     int n = 4, m = 4;
//     vector<vector<int>> grid = {
//         {1, 2, 10, 4},
//         {100, 3, 2, 1},
//         {1, 1, 20, 2},
//         {1, 2, 2, 1}
//     };
//     int ans = maxFallingPath(n, m, grid);
//     cout << "The max falling path is: " << ans << endl;
//     return 0;
// }



// way 3 of doing it is TABULATION METHOD 
// ✅ Time Complexity (TC): O(N × M)
// You are filling each cell in a dp table of size N × M.
// For each cell (i, j), the values from the previous row are checked (up, left diagonal, right diagonal) 
// in constant time.

// ✅ Space Complexity (SC):O(N × M)
// A 2D dp array of size N × M is used to store results for each cell.
// ✅ No extra recursion stack or significant auxiliary space is used.

int maxFallingPath(int n, int m, vector<vector<int>>& grid) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    // Base case: copy the first row
    for (int j = 0; j < m; j++) {
        dp[0][j] = grid[0][j];
    }

    // Fill the dp table
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int up = dp[i - 1][j];

            int leftDiagonal;
            if (j - 1 >= 0) {
                leftDiagonal = dp[i - 1][j - 1];
            } else {
                leftDiagonal = INT_MIN;
            }

            int rightDiagonal;
            if (j + 1 < m) {
                rightDiagonal = dp[i - 1][j + 1];
            } else {
                rightDiagonal = INT_MIN;
            }

            dp[i][j] = grid[i][j] + max(up, max(leftDiagonal, rightDiagonal));
        }
    }

    // Find the max value in the last row
    int maxi = INT_MIN;
    for (int j = 0; j < m; j++) {
        if (dp[n - 1][j] > maxi) {
            maxi = dp[n - 1][j];
        }
    }

    return maxi;
}

int main() {
    int n = 4, m = 4;
    vector<vector<int>> grid = {
        {1, 2, 10, 4},
        {100, 3, 2, 1},
        {1, 1, 20, 2},
        {1, 2, 2, 1}
    };

    int ans = maxFallingPath(n, m, grid);
    cout << "The max falling path is: " << ans << endl;

    return 0;
}