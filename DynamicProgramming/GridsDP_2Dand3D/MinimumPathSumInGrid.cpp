#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// way 1 of solving this 
// recursion trying all paths and finfing minimum one 
// TC -> Exponential -> O(2^(n+m))
// SC -> O(n + m) (due to recursion stack)

int recur(int row, int column, vector<vector<int>> & grid){
    // base case 1
    if(row == 0 && column == 0){
        return grid[row][column]; // returning taht value also as it would add up
    }

    // base case 2
    // IF in case out of boundary return such a high number that it would never be acceptde
    // use 1e9 instead of maxint to avoid overflow
    if( row < 0 || column < 0){
        return 1e9;
    }

    // storing the cuurent number and then calculatinga all possible costs
    int up = grid[row][column] + recur(row-1,column,grid);
    int left = grid[row][column] + recur(row,column-1,grid);

    // retruning the minmum paths cost at every step
    return min(up,left);
}

int minimumPath(int row, int column, vector<vector<int>> &grid){
    return recur(row-1,column-1,grid);
}

int main(){
    int n = 3; // rows
    int m = 3; // columns
    vector<vector<int>> grid = {{1,2,3},{1,2,1},{1,1,1}};
    int ans = minimumPath(n,m,grid);
    cout<<" the minimum path sum in grid is : "<<ans<<endl;
    return 0;
}



// Way 2 of solving this would be 
// MEMOISATION - > using dp to optimise
// Time complexity -> So instead of re-computing the same cell multiple times as in plain
// recursion,memoization ensures we compute:
// One result per grid cell ⇒ n * m total.
// Time Complexity = 𝑂 (𝑛×𝑚) Time Complexity = O(n×m)

// SPace complexity - O(n * m) for the memoization table (dp[n][m]).
// O(n + m) for the recursion stack space, since the longest path from (0,0) to (n-1,m-1) 
// is at most n + m recursive calls deep.

int memo(int row, int column,vector<vector<int>>&grid,vector<vector<int>>&dp){

    // base case 1
    if(row == 0 && column == 0){
        return grid[row][column]; // returning taht value also as it would add up
    }

    // base case 2
    // IF in case out of boundary return such a high number that it would never be acceptde
    // use 1e9 instead of maxint to avoid overflow
    if( row < 0 || column < 0){
        return 1e9;
    }

    if(dp[row][column] != -1){  //checking if already encountered that element
        return dp[row][column];
    }

    int up = grid[row][column] + memo(row-1,column,grid,dp);
    int left = grid[row][column] + memo(row,column-1,grid,dp);

    return dp[row][column] = min(up,left);

}

int minimumPath(int row, int column, vector<vector<int>> &grid, vector<vector<int>>&dp){
    return memo(row-1,column-1,grid,dp);
}

int main(){
    int n = 3; int m = 3;
    vector<vector<int>> grid = {{1,2,3},{1,2,1},{1,1,1}};
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int ans = minimumPath(n,m,grid,dp);
    cout<<" the answer of minimum paths using memeosiation is :"<<ans<<endl;
    return 0;
}





// way 3 of doing is 
// TABULATION METHOD - bottom to top approach 


int tabu(int row, int column,vector<vector<int>>&grid,vector<vector<int>>&dp){

    for(int i = 0; i<row; i++){
        for(int j = 0; j<column ; j++){
            if(i == 0 && j == 0){
                dp[i][j] = grid[i][j];
            }else{
                int up = 1e9;
                int left = 1e9;
                if(i>0) up = grid[i][j] + dp[i-1][j];
                if(j>0) left = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(up,left);
            }
        }
    }
    return dp[row-1][column-1];
}

int minimumPath(int row, int column, vector<vector<int>> &grid, vector<vector<int>>&dp){
    return tabu(row,column,grid,dp);
}

int main(){
    int n = 3; int m = 3;
    vector<vector<int>> grid = {{1,2,3},{1,2,1},{1,1,1}};
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int ans = minimumPath(n,m,grid,dp);
    cout<<" the answer of minimum paths using tabualation is :"<<ans<<endl;
    return 0;
}