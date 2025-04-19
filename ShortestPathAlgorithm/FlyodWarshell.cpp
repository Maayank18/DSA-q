/*
Problem Statement:
------------------
You are given a weighted directed graph represented as an adjacency matrix `matrix`,
where matrix[i][j] represents the weight of the edge from node i to node j.
If there is no edge from i to j, matrix[i][j] = -1.

Your task is to compute the **shortest distance** between every pair of vertices using
the Floyd-Warshall Algorithm.

If a pair (i, j) has no path, set the matrix[i][j] to -1.
Also, detect if a **negative weight cycle** exists.

Input:
- A 2D vector `matrix` of size n x n where n is the number of nodes.

Output:
- The same 2D vector is modified in-place to contain shortest distances.

Time Complexity: O(n^3)
Space Complexity: O(1) (in-place modification)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void FloydWarshall(vector<vector<int>> &matrix) {
    int n = matrix.size();
    int INF = 1e9;

    // Step 1: Replace -1 with INF (except for diagonal elements)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1 && i != j) {
                matrix[i][j] = INF;
            }
            if (i == j) matrix[i][j] = 0;
        }
    }

    // Step 2: Apply Floyd-Warshall algorithm
    // Try every node as an intermediate
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // Avoid integer overflow by checking if path through k is valid
                if (matrix[i][k] < INF && matrix[k][j] < INF) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    // Step 3: Detect negative weight cycle
    for (int i = 0; i < n; i++) {
        if (matrix[i][i] < 0) {
            cout << "Negative weight cycle detected.\n";
            return;
        }
    }

    // Step 4: Replace INF back to -1 to indicate no path
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == INF) {
                matrix[i][j] = -1;
            }
        }
    }
}


int main() {
    vector<vector<int>> matrix = {
        {0, 3, -1, 7},
        {8, 0, 2, -1},
        {5, -1, 0, 1},
        {2, -1, -1, 0}
    };

    FloydWarshall(matrix);

    cout << "Shortest distance matrix:\n";
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << "\n";
    }

    return 0;
}
