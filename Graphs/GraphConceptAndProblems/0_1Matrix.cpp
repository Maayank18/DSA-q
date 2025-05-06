/*
Problem Statement:
Given a 2D binary matrix (only 0s and 1s), return a matrix where each cell contains the
distance to the nearest cell that contains 1. The distance is calculated using 4-directional 
Manhattan Distance (up, down, left, right).

Time Complexity: O(n * m)
Space Complexity: O(n * m)
Where n is the number of rows and m is the number of columns in the grid.
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to compute the nearest distance to cell having 1
vector<vector<int>> nearestCell(vector<vector<int>> grid) {
    int n = grid.size();            // Number of rows
    int m = grid[0].size();         // Number of columns

    vector<vector<int>> distance(n, vector<int>(m, 0));    // Final distance matrix
    vector<vector<int>> visited(n, vector<int>(m, 0));     // Visited matrix

    queue<pair<pair<int, int>, int>> q;  // Queue to perform BFS

    // Push all cells with 1 into the queue
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                q.push({{i, j}, 0});      // Starting point for BFS
                visited[i][j] = 1;        // Mark as visited
            }
        }
    }

    // Directions: up, right, down, left
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    // BFS to update distances
    while (!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        distance[row][col] = steps;   // Store distance in answer matrix

        // Check 4 directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = col + dcol[i];

            // Check bounds and whether it's unvisited
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0) {
                visited[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }

    return distance;
}

// Driver code to test the function
int main() {
    // Sample grid input
    vector<vector<int>> grid = {
        {0, 0, 1},
        {0, 1, 0},
        {0, 0, 0}
    };

    // Function call
    vector<vector<int>> result = nearestCell(grid);

    // Print the result matrix
    cout << "Distance to nearest 1 for each cell:\n";
    for (auto row : result) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
