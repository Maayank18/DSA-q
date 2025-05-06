/*
Problem Statement:
-------------------
You are given a binary matrix 'grid' of size n x m, where:
- `grid[i][j] = 1` represents a valid cell you can move to.
- `grid[i][j] = 0` represents a wall/obstacle.

You are also given a source cell and a destination cell.

Your task is to return the **minimum number of steps required to reach the destination**
from the source. You can move in **4 directions only**: up, down, left, and right.

If the destination is not reachable, return -1.

Input:
- grid: 2D vector of 0s and 1s
- source: pair<int, int> — {row, column} of starting cell
- destination: pair<int, int> — {row, column} of target cell

Output:
- int — the shortest path length from source to destination, or -1 if unreachable.

Time Complexity: O(N * M)
Space Complexity: O(N * M)
*/

#include <bits/stdc++.h>
using namespace std;

int shortestPathInBinaryMaze(vector<vector<int>> &grid, pair<int, int> source,
                             pair<int, int> destination) {
    // Queue for BFS traversal — stores: {distance from source, {row, col}}
    queue<pair<int, pair<int, int>>> q;

    int n = grid.size();
    int m = grid[0].size();

    // Distance matrix initialized with large number ("infinity")
    vector<vector<int>> distance(n, vector<int>(m, 1e9));

    // Distance from source to source is 0
    distance[source.first][source.second] = 0;

    // Push source into queue
    q.push({0, {source.first, source.second}});

    // Arrays to help move in 4 directions (up, right, down, left)
    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};

    // Start BFS
    while (!q.empty()) {
        auto it = q.front();     // Current cell
        int dist = it.first;     // Distance so far
        int row = it.second.first;
        int col = it.second.second;
        q.pop();

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int newRow = row + dRow[i];
            int newCol = col + dCol[i];

            // Check for valid cell
            if (newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < m &&
                grid[newRow][newCol] == 1 &&
                dist + 1 < distance[newRow][newCol]) {

                // Update distance if shorter path is found
                distance[newRow][newCol] = dist + 1;

                // If destination is reached, return the distance
                if (newRow == destination.first && newCol == destination.second) {
                    return dist + 1;
                }

                // Push the next cell into the queue
                q.push({dist + 1, {newRow, newCol}});
            }
        }
    }

    // If destination is not reachable
    return -1;
}


int main() {
    vector<vector<int>> grid = {
        {1, 1, 1, 1},
        {0, 0, 1, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 1}
    };

    pair<int, int> source = {0, 0};
    pair<int, int> destination = {3, 3};

    int result = shortestPathInBinaryMaze(grid, source, destination);
    cout << "Shortest path length = " << result << endl;

    return 0;
}
