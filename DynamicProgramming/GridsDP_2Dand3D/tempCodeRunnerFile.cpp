#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int f(int row, int column, vector<vector<int>> & grid){
    // base case 1
    if(row == 0 && column == 0){
        return grid[row][column]; // returning taht value also as it would add up
    }

    // base case 2
    // IF in case out of boundary return such a high number that it would never be acceptde
    if( row < 0 || column < 0){
        return INT_MAX;
    }

    // storing the cuurent number and then calculatinga all possible costs
    int up = grid[row][column] + f(row-1,column,grid);
    int left = grid[row][column] + f(row,column-1,grid);

    // retruning the minmum paths cost at every step
    return min(up,left);
}

int minimumPath(int row, int column, vector<vector<int>> &grid){
    return f(row-1,column-1,grid);
}

int main(){
    int n = 3; // rows
    int m = 3; // columns
    vector<vector<int>> grid = {{1,2,3},{1,2,1},{1,1,1}};
    int ans = minimumPath(n,m,grid);
    cout<<" the minimum path sum in grid is : "<<ans<<endl;
    return 0;
}