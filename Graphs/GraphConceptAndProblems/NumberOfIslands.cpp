/*
Problem Statement:
------------------
You are given a 2D grid of size n x m consisting of only 0s and 1s.
An island is a group of 1s (land) connected **8-directionally** (horizontal, vertical, and diagonal).
Your task is to count the total number of islands in the grid.

Example:
Input: 
grid = {{1,1,0,0,0},
        {0,1,0,0,1},
        {1,0,0,1,1},
        {0,0,0,0,0},
        {1,0,1,0,1}}

Output: 5
Explanation: There are 5 distinct islands in the grid.

---------------------------------------------------------
Time Complexity:
- O(N*M), where N = number of rows and M = number of columns.
  Each cell is visited once in BFS.

Space Complexity:
- O(N*M) for the visited matrix.
- O(N*M) in the worst case for the BFS queue.
---------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// BFS function to explore all connected 1s (island parts)
void bfs(int row, int col, vector<vector<int>> &visited,
         vector<vector<int>> &grid, int n, int m) {

    visited[row][col] = 1; // mark as visited
    queue<pair<int, int>> q;
    q.push({row, col}); // start BFS from this cell

    // Check all 8 possible directions (including diagonals)
    // MAY OR MAY NOT BE USED
    // for (int dr = -1; dr <= 1; dr++) {
    //     for (int dc = -1; dc <= 1; dc++) {
    //         if (dr == 0 && dc == 0) continue; // skip the current cell
    //     }
    // }

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // Explore all 8 neighbors
        for (int drow = -1; drow <= 1; drow++) {
            for (int dcol = -1; dcol <= 1; dcol++) {
                int nrow = r + drow;
                int ncol = c + dcol;

                // Check if the neighbor is within bounds, is land, and not visited
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !visited[nrow][ncol] && grid[nrow][ncol] == 1) {

                    visited[nrow][ncol] = 1; // mark it visited
                    q.push({nrow, ncol});    // push it to queue
                }
            }
        }
    }
}

// Function to count islands
int numIslands(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> visited(n, vector<int>(m, 0));
    int cnt = 0;

    // Traverse the grid
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            // If cell is unvisited land, it's a new island
            if (!visited[row][col] && grid[row][col] == 1) {
                cnt++; // increment island count
                bfs(row, col, visited, grid, n, m); // explore the island
            }
        }
    }

    return cnt;
}

// Driver code
int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 0, 1, 0, 1}
    };

    cout << "Number of islands: " << numIslands(grid) << endl;

    return 0;
}
