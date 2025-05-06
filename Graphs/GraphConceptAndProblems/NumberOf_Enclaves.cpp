#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem Statement:
------------------
Given a 2D grid of integers where:
- 0 represents water
- 1 represents land

We want to count the number of land cells (1s) that are completely enclosed — 
i.e., they cannot reach the boundary of the grid via any number of 4-directional (up, down, left, right) moves.

Time Complexity: O(n * m)
- Every cell is visited at most once.

Space Complexity: O(n * m)
- To keep track of visited cells and for queue used in BFS.
*/

int NotEscapingLands(vector<vector<int>> &grid) {
    int n = grid.size();         // Number of rows
    int m = grid[0].size();      // Number of columns
    int visited[n][m];           // To track visited cells

    // Initialize visited with 0
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            visited[i][j] = 0;

    queue<pair<int, int>> q;

    // Step 1: Push all boundary land cells into the queue
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If it's a boundary cell and it's land
            if (i == 0 || j == 0 || i == n - 1 || j == m - 1) {
                if (grid[i][j] == 1) {
                    q.push({i, j});        // Start BFS from here
                    visited[i][j] = 1;     // Mark as visited
                }
            }
        }
    }

    // Directions: up, right, down, left
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    // Step 2: BFS to mark all land cells that can escape (i.e., connected to boundary)
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            // If neighbor is within bounds, is land, and not visited
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                grid[nrow][ncol] == 1 && !visited[nrow][ncol]) {
                visited[nrow][ncol] = 1;
                q.push({nrow, ncol});
            }
        }
    }

    // Step 3: Count unvisited land cells (which cannot reach boundary)
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && visited[i][j] == 0) {
                count++;
            }
        }
    }

    return count;
}

// Driver Code
int main() {
    // Sample Grid
    vector<vector<int>> grid = {
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}
    };

    /*
    Visual representation:
    0 0 0 0
    1 0 1 0
    0 1 1 0
    0 0 0 0

    The 3 land cells in the middle (1s) cannot reach the boundary.
    So, the expected output = 3
    */

    int result = NotEscapingLands(grid);
    cout << "Number of enclosed land cells: " << result << endl;

    return 0;
}
