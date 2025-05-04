// ✅ Problem Statement Recap:
// Given a grid of size n x m, count the number of unique paths from the top-left to
// the bottom-right corner moving only right or down.

#include<iostream>
#include<vector>
using namespace std;


// Way 1 of recursion 
// time complexity -> Each call branches into two (right and down), 
// leading to an exponential number of calls:  O(2^(n+m))
// space complexity -> SC=O(m+n)(due to call stack)

// int finding(int n, int m, vector<vector<int>> & grid){

//     //base case 1
//     // if they reach top left that is (0,0) the path exist
//     if(n == 0 && m == 0){return 1;}

//     //base case 2
//     //as we are only allowed to go up and left considering from down to top
//     // what if up goes beyond 0,-1,-2,... and left goes beyond 0,-1,-2,...
//     if(n < 0 || m < 0){return 0;}

//     // now doing stuffs to find out paths;
//     int up = finding(n-1,m,grid);
//     int left = finding(n,m-1,grid);

//     return up + left;
// }

// int allUniquePaths(vector<vector<int>>&grid){
//     int n = grid.size();
//     int m = grid[0].size();
//     return finding(n-1,m-1,grid);
// }

// int main(){
//     int n = 3;
//     int m = 3;
//     vector<vector<int>> grid(n,vector<int>(m));
//     int ans = allUniquePaths(grid);
//     cout<<" the toatl unique paths are : "<<ans;
//     return 0;
// }



// WAY 2 OF SOLVING 
// MEMOISATION -> checking if theer exist overlapping sub problems and we can make 
// sue of previous ouptut to calculate cuurent values ( IT IS TOP TO BOTTOM )

// ✅ Time Complexity (TC):
// There are m × n unique subproblems (i.e., one for each cell).
// Each subproblem is solved once, and each takes O(1) time
// (just adding two values: from top and left).
// TC = 𝑂(𝑚×𝑛)

// ✅ Space Complexity (SC):
// DP array: Stores m × n entries → O(m × n)
// Recursion stack depth: In the worst case, it's O(m + n) (from top-left to bottom-right)

// int finding(int n, int m, vector<vector<int>> & grid,vector<vector<int>> dp){

//     //base case 1 and 2 both stiils remain the same
//     if(n == 0 && m == 0){return 1;}
//     if(n < 0 || m < 0){return 0;}

//     //base case 3
//     // if that element has already beene encountered and calculated 
//     // there is no need to calculate that again
//     if(dp[n][m] != -1){
//         return dp[n][m];
//     }


//     // now again doi all the stuff
//     int up = finding(n-1,m,grid,dp);
//     int left = finding(n,m-1,grid,dp);

//     return dp[n][m] = up + left;

// }

// int allUniquePaths(vector<vector<int>>&grid){
//     int n = grid.size();
//     int m = grid[0].size();
//     vector<vector<int>> dp(n,vector<int>(m,-1));
//     return finding(n-1,m-1,grid,dp);
// }

// int main(){
//     int n = 3;
//     int m = 3;
//     vector<vector<int>> grid(n,vector<int>(m));
//     int ans = allUniquePaths(grid);
//     cout<<" the toatl unique paths are : "<<ans;
//     return 0;
// }



// WAY 3 OF SOLVING
// TABULISATION -> ( BOTTOM TO TOP APPROACH)
// here all of you base cases becomes your intial condition 

// ✅ Time Complexity (TC):
// You're iterating over each of the n * m cells once.
// Time Complexity = O(n×m) 

// ✅ Space Complexity (SC):
// You're using a dp table of size n x m
// Space Complexity = O(n×m)

int finding(int n, int m, vector<vector<int>> & grid,vector<vector<int>> dp){
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

        // Skip the starting cell (0,0) as we already initialized it with 1.
        if (i == 0 && j == 0) continue;

        int up = 0, left = 0;

        // If we are not in the first row, we can come from the cell directly above.
        if (i > 0) up = dp[i - 1][j];

        // If we are not in the first column, we can come from the cell to the left.
        if (j > 0) left = dp[i][j - 1];

        // Total number of ways to reach cell (i, j) is the sum of ways to reach
        // from the cell above (up) and from the cell to the left (left).
        dp[i][j] = up + left;
        }
    }

    // The answer will be the number of unique paths to reach the bottom-right cell.
    return dp[n - 1][m - 1];
}

int allUniquePaths(vector<vector<int>>&grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return finding(n,m,grid,dp);
}

int main(){
    int n = 3;
    int m = 3;
    vector<vector<int>> grid(n,vector<int>(m));
    int ans = allUniquePaths(grid);
    cout<<" the toatl unique paths are : "<<ans;
    return 0;
}




// 4th Way ofsolvin is 
// SPACE OPTMISISATION -> it is only possible if we have previous row or 
// previous column otherwise not