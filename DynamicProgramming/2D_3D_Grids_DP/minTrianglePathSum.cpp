#include<iostream>
#include<vector>
using namespace std;

//WAY 1 OF SOLVING - RECURSION 
// TC: Exponential — O(2^n) (as you explore all paths).
// SC: O(n) (due to recursion stack)

//recursive function 
// int f(int i, int j, int rows, int columns, vector<vector<int>> & triangle){

//     // base case 1 
//     if(i == rows-1) return triangle[i][j];
//     // there wont be any other base case as no out of bound condition there

//     int down = triangle[i][j] + f(i+1,j,rows,columns,triangle);
//     int diagonal = triangle[i][j] + f(i+1,j+1,rows,columns,triangle);

//     return min(down,diagonal);
// }

// int minimumTrianglePathSum(int i, int j, int rows, int columns, vector<vector<int>> &triangle){
//     return f(i,j,rows,columns,triangle);
// }

// int main(){
//     // a triangle with 4 rows and 4 columns
//     int n = 4;
//     int m = 4;
//     vector<vector<int>> triangle = {{1},{2,2},{3,6,7},{8,9,6,10}};
//     int ans = minimumTrianglePathSum(0,0,n,m,triangle);
//     cout<<" the minimum paths sum is : "<<ans<<endl;
//     return 0;
// }



// WAY 2 OF SOLVING IS MEMOISATION 
// TC -> Since each subproblem (i, j) is solved only once and stored in a dp[i][j] table, the total number of recursive calls is O(n²).
// 🔷 Final Time Complexity: O(n²)
// SC -> DP Table: You need a 2D dp table of size n x n ⇒ O(n²)
// Recursion Stack: The maximum depth of the recursive call stack is n (from top to bottom of the triangle) ⇒ O(n)
// Final Space Complexity: O(n²) (dominant term due to dp table)

// int f(int i, int j, int rows, int columns, vector<vector<int>> & triangle,
// vector<vector<int>>&dp){

//     // base case 1 
//     if(i == rows-1) return triangle[i][j];
//     // in dp we will be having another base case
//     if(dp[i][j] != -1) return dp[i][j];

//     int down = triangle[i][j] + f(i+1,j,rows,columns,triangle,dp);
//     int diagonal = triangle[i][j] + f(i+1,j+1,rows,columns,triangle,dp);

//     return dp[i][j] = min(down,diagonal);
// }

// int minimumTrianglePathSum(int i, int j, int rows, int columns, vector<vector<int>> &triangle,
// vector<vector<int>>&dp){
//     return f(i,j,rows,columns,triangle,dp);
// }

// int main(){
//     // a triangle with 4 rows and 4 columns
//     int n = 4;
//     int m = 4;
//     vector<vector<int>> triangle = {{1},{2,2},{3,6,7},{8,9,6,10}};
//     vector<vector<int>> dp(n,vector<int>(m,-1));
//     int ans = minimumTrianglePathSum(0,0,n,m,triangle,dp);
//     cout<<" the minimum paths sum (using dp) is : "<<ans<<endl;
//     return 0;
// }



// WAY 3 OF DOING IS USING TABULATION 
// THUMB RULE IS -> whatever u write for recursion tabulation is its jusst opposite 
// so here we go from n-1 to 0
// both Time and space complexity will be O(n²)

int f(int i, int j, int rows, int columns, vector<vector<int>> & triangle,
    vector<vector<int>>&dp){
    
        // as we are goin in oppsoite direction our 1st bases case will be 
        // marking everyone from last row
        for(int j = rows-1; j>=0; j--){
            dp[rows-1][j] = triangle[rows-1][j];
        }

        // now the last row has been marked we will work upon our remainng rows
        for(int i = rows-2; i>=0; i--){
            for(int j = i; j>=0; j--){
                int down = triangle[i][j] + dp[i+1][j];
                int diagonal = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down,diagonal);
            }
        }
        return dp[0][0];
    }
    
    int minimumTrianglePathSum(int i, int j, int rows, int columns, vector<vector<int>> &triangle,
    vector<vector<int>>&dp){
        return f(i,j,rows,columns,triangle,dp);
    }
    
    int main(){
        // a triangle with 4 rows and 4 columns
        int n = 4;
        int m = 4;
        vector<vector<int>> triangle = {{1},{2,2},{3,6,7},{8,9,6,10}};
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = minimumTrianglePathSum(0,0,n,m,triangle,dp);
        cout<<" the minimum paths sum (using TABULISATION) is : "<<ans<<endl;
        return 0;
    }




// Optional 4th way of doin it is SPACE OPTIMSATION WHERE THE 
// space may boil down to O(n)