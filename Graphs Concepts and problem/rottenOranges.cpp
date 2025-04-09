/*
Problem Statement:
------------------
You are given an m x n grid where each cell can have one of three values:
- 0 representing an empty cell,
- 1 representing a fresh orange,
- 2 representing a rotten orange.

Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange.
If this is impossible, return -1.

Time Complexity: O(n * m)
- We traverse each cell once in the worst case using BFS.

Space Complexity: O(n * m)
- Used for the visited matrix and queue in the worst case.

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int TotalTimeRottenOranges(vector<vector<int>> &grid) {
    int n = grid.size();          // Number of rows
    int m = grid[0].size();       // Number of columns

    // Queue will store: {{row, col}, time}
    queue<pair<pair<int, int>, int>> q;

    // Visited matrix to mark oranges that are rotten or processed
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // Direction arrays for up, right, down, left movement
    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};

    // Step 1: Push all initially rotten oranges into the queue
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 2) {
                q.push({{i, j}, 0});
                visited[i][j] = 2;  // Mark as visited/rotten
            }
        }
    }

    int maxTime = 0;

    // Step 2: BFS traversal
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int time = q.front().second;
        q.pop();

        maxTime = max(maxTime, time); // Update max time at each step

        // Check all 4 directions
        for (int i = 0; i < 4; i++) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];

            // Valid fresh orange: inside grid, is fresh, and not visited
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m
                && grid[newRow][newCol] == 1 && visited[newRow][newCol] == 0) {
                
                // Mark as rotten and push to queue with time+1
                q.push({{newRow, newCol}, time + 1});
                visited[newRow][newCol] = 2;
            }
        }
    }

    // Step 3: Check if any fresh orange remains
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && visited[i][j] != 2) {
                return -1; // Some fresh oranges never got rotten
            }
        }
    }

    return maxTime;
}

// Example usage
int main() {
    vector<vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    int result = TotalTimeRottenOranges(grid);
    cout << "Minimum time to rot all oranges: " << result << endl;
    return 0;
}
