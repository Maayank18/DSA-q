#include<iostream>
#include<vector>
using namespace std;

// as let tehre be any number of moves the one thing is whenver they will move
// they will always be in same columns while moving up to down 
// J1 AND J2 because the only difference that we will see will be while checking columsn
// j1 -> alice, j2 -> bob
/*
Problem Statement:
Two players, Alice and Bob, start at the top row of a grid. Alice starts at the left-most column (j1 = 0), 
and Bob starts at the right-most column (j2 = columns - 1). They both move simultaneously to the next row. 
Each of them can move to three positions in the next row: directly below, one step left-diagonal down, or one step right-diagonal down.
They collect cherries represented by integers in the grid cells they pass.
If both land on the same cell, they collect the cherries only once.
Find the maximum number of cherries they can collect by the time they reach the last row.
*/

// Normal Recursion (without memoization)
// Time Complexity: O(3^rows * 3^rows) => exponential
// Space Complexity: O(rows) for recursion stack
int f(int i, int j1, int j2, int rows, int columns, vector<vector<int>> &grid){

    // base case 1 - out of bound
    if(j1 < 0 || j2 < 0 || j1 >= columns || j2 >= columns ){
        return -1e8;
    }

    // base case 2 - if we reached destination
    if(i == rows -1){
        if(j1 == j2){
            return grid[i][j1]; // or return grid[i][j2] as both reaches same place
        }else{
            return grid[i][j1] + grid[i][j2];
        }
    }

    int maxi = -1e8;
    // exploring all the paths simulataneouly
    for( int dj1 = -1; dj1 <= 1; dj1++){
        for( int dj2 = -1; dj2 <= 1; dj2++){
            int value =0;
            if( j1 == j2){
                value = grid[i][j1];
            }else{
                value = grid[i][j1] + grid[i][j2];
            }

            value = value + f(i+1,j1+dj1,j2+dj2,rows,columns,grid);
            maxi = max(maxi, value);
        }
    }
    return maxi;
}

int CherryPickupTotal(int rows, int columns, vector<vector<int>>&grid){
    return f(0,0,columns-1,rows,columns,grid);
}

// Memoization (top-down DP)
// Time Complexity: O(rows * columns * columns * 9)
// Space Complexity: O(rows * columns * columns) + O(rows) for recursion stack
int f_memo(int i, int j1, int j2, int rows, int columns, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp){
    if(j1 < 0 || j2 < 0 || j1 >= columns || j2 >= columns){
        return -1e8;
    }

    if(i == rows - 1){
        if(j1 == j2){
            return grid[i][j1];
        }else{
            return grid[i][j1] + grid[i][j2];
        }
    }

    if(dp[i][j1][j2] != -1){
        return dp[i][j1][j2];
    }

    int maxi = -1e8;
    for(int dj1 = -1; dj1 <= 1; dj1++){
        for(int dj2 = -1; dj2 <= 1; dj2++){
            int value = 0;
            if(j1 == j2){
                value = grid[i][j1];
            }else{
                value = grid[i][j1] + grid[i][j2];
            }
            value += f_memo(i+1, j1+dj1, j2+dj2, rows, columns, grid, dp);
            maxi = max(maxi, value);
        }
    }

    return dp[i][j1][j2] = maxi;
}

int CherryPickupMemo(int rows, int columns, vector<vector<int>>&grid){
    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(columns, vector<int>(columns, -1)));
    return f_memo(0, 0, columns-1, rows, columns, grid, dp);
}

// Tabulation (bottom-up DP)
// Time Complexity: O(rows * columns * columns * 9)
// Space Complexity: O(rows * columns * columns)
int CherryPickupTabu(int rows, int columns, vector<vector<int>>& grid){
    vector<vector<vector<int>>> dp(rows, vector<vector<int>>(columns, vector<int>(columns, 0)));

    // fill base case
    for(int j1 = 0; j1 < columns; j1++){
        for(int j2 = 0; j2 < columns; j2++){
            if(j1 == j2){
                dp[rows-1][j1][j2] = grid[rows-1][j1];
            }else{
                dp[rows-1][j1][j2] = grid[rows-1][j1] + grid[rows-1][j2];
            }
        }
    }

    for(int i = rows - 2; i >= 0; i--){
        for(int j1 = 0; j1 < columns; j1++){
            for(int j2 = 0; j2 < columns; j2++){
                int maxi = -1e8;
                for(int dj1 = -1; dj1 <= 1; dj1++){
                    for(int dj2 = -1; dj2 <= 1; dj2++){
                        int nj1 = j1 + dj1;
                        int nj2 = j2 + dj2;

                        if(nj1 >= 0 && nj2 >= 0 && nj1 < columns && nj2 < columns){
                            int value = 0;
                            if(j1 == j2){
                                value = grid[i][j1];
                            }else{
                                value = grid[i][j1] + grid[i][j2];
                            }
                            value += dp[i+1][nj1][nj2];
                            maxi = max(maxi, value);
                        }
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }

    return dp[0][0][columns-1];
}


// Driver code
int main() {
    int rows = 4, columns = 4;
    vector<vector<int>> grid = {
        {3, 1, 1, 2},
        {2, 5, 1, 1},
        {1, 5, 5, 1},
        {2, 1, 1, 1}
    };

    cout << "Normal Recursion: " << CherryPickupTotal(rows, columns, grid) << endl;
    cout << "Memoization: " << CherryPickupMemo(rows, columns, grid) << endl;
    cout << "Tabulation: " << CherryPickupTabu(rows, columns, grid) << endl;

    return 0;
}