/*
Problem Statement:
Given a matrix containing 'X' and 'O', capture all regions that are surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region. 
Only 'O's connected to the border should *not* be flipped.

Time Complexity: O(n * m)
Space Complexity: O(n * m) for visited matrix and DFS stack

Approach:
1. Traverse the border and mark all connected 'O's using DFS.
2. After DFS, any 'O' not marked is surrounded and should be converted to 'X'.
*/

#include <iostream>
#include <vector>

using namespace std;

// Depth First Search to mark safe 'O's
void dfs(int row, int column, 
         vector<vector<int>> &visited, 
         vector<vector<char>> &mat, 
         int drow[], int dcol[]) {

    visited[row][column] = 1;
    int n = mat.size();
    int m = mat[0].size();

    // Explore all 4 directions: up, right, down, left
    for (int i = 0; i < 4; i++) {
        int nrow = row + drow[i];
        int ncol = column + dcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
            !visited[nrow][ncol] && mat[nrow][ncol] == 'O') {
            dfs(nrow, ncol, visited, mat, drow, dcol);
        }
    }
}

// Function to flip surrounded regions
vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
    vector<vector<int>> visited(n, vector<int>(m, 0));

    int drow[] = {-1, 0, 1, 0}; // possible direction of the rows
    int dcol[] = {0, 1, 0, -1}; // possible direction of column

    // Traverse first and last row
    for (int j = 0; j < m; j++) {
        if (!visited[0][j] && mat[0][j] == 'O') {
            dfs(0, j, visited, mat, drow, dcol);
        }
        if (!visited[n - 1][j] && mat[n - 1][j] == 'O') {
            dfs(n - 1, j, visited, mat, drow, dcol);
        }
    }

    // Traverse first and last column
    for (int i = 0; i < n; i++) {
        if (!visited[i][0] && mat[i][0] == 'O') {
            dfs(i, 0, visited, mat, drow, dcol);
        }
        if (!visited[i][m - 1] && mat[i][m - 1] == 'O') {
            dfs(i, m - 1, visited, mat, drow, dcol);
        }
    }

    // Flip unvisited 'O's to 'X'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && mat[i][j] == 'O') {
                mat[i][j] = 'X';
            }
        }
    }

    return mat;
}

// Driver Code
int main() {
    vector<vector<char>> mat = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };

    int n = mat.size();
    int m = mat[0].size();

    vector<vector<char>> result = fill(n, m, mat);

    cout << "Modified Matrix:\n";
    for (auto row : result) {
        for (auto ch : row) {
            cout << ch << " ";
        }
        cout << "\n";
    }

    return 0;
}
