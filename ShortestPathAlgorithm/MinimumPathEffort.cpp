#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

/*
Problem Statement:
You are given a 2D grid `height` where height[i][j] represents the height at cell (i, j).
You can move in 4 directions (up, down, left, right).
Your task is to find a path from the top-left cell (0, 0) to the bottom-right cell (n-1, m-1)
such that the maximum absolute difference in heights between two consecutive cells 
along the path is minimized.

Return the minimum effort (maximum absolute height difference) required for such a path.

Time Complexity: O(N * M * log(N * M)) → Due to priority queue operations
Space Complexity: O(N * M) → For the difference matrix and priority queue
*/

int MinimumEffort(vector<vector<int>> &height) {
    // Min-heap: {effort, {row, column}}
    priority_queue<pair<int, pair<int, int>>,
                   vector<pair<int, pair<int, int>>>,
                   greater<pair<int, pair<int, int>>>> pq;

    int n = height.size();
    int m = height[0].size();

    // Matrix to store the minimum effort required to reach each cell
    vector<vector<int>> difference(n, vector<int>(m, 1e9));
    difference[0][0] = 0; // Starting point has 0 effort
    pq.push({0, {0, 0}}); // Start with top-left cell

    // Direction vectors for up, right, down, left
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};

    while (!pq.empty()) {
        auto it = pq.top(); pq.pop();
        int diff = it.first; // Current path effort
        int row = it.second.first;
        int column = it.second.second;

        // If destination is reached, return the effort
        if (row == n - 1 && column == m - 1) {
            return diff;
        }

        // Explore all 4 directions
        for (int i = 0; i < 4; i++) {
            int newR = row + drow[i];
            int newC = column + dcol[i];

            // Check boundaries
            if (newR >= 0 && newR < n && newC >= 0 && newC < m) {
                // Calculate the effort of moving to the new cell
                int newEffort = max(diff, abs(height[row][column] - height[newR][newC]));

                // If this new effort is smaller, update and push to the queue
                if (newEffort < difference[newR][newC]) {
                    difference[newR][newC] = newEffort;
                    pq.push({newEffort, {newR, newC}});
                }
            }
        }
    }

    return 0; // If the destination is unreachable
}

int main() {
    int n, m;
    cout << "Enter number of rows and columns: ";
    cin >> n >> m;

    vector<vector<int>> height(n, vector<int>(m));
    cout << "Enter height matrix:\n";
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> height[i][j];

    int result = MinimumEffort(height);
    cout << "Minimum Effort Required: " << result << endl;

    return 0;
}
