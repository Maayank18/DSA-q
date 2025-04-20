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









// directed 

/*
Problem Statement (Directed Graph):
------------------------------------
You are given a directed graph with `n` cities and `edges`, where each edge is 
represented by [u, v, w] meaning there is a directed edge from city u to city v 
with distance w.

Your goal is to find the city that has the **smallest number of reachable cities** 
within a given `distanceThreshold`. In case of a tie, return the city with the 
**greatest index**.

Input:
- n (int): Number of cities
- m (int): Number of directed edges
- edges (vector<vector<int>>): List of edges [from, to, weight]
- distanceThreshold (int): Max allowed distance to consider a city reachable

Output:
- An integer representing the city with the smallest number of reachable cities 
  within the given threshold (breaking ties by choosing the larger index).

Approach:
- Use Floyd-Warshall algorithm for All-Pairs Shortest Paths.
- Count how many cities are reachable from each city within the threshold.
- Track the city with the minimum count and maximum index.

Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findCityDirected(int n, int m, vector<vector<int>> &edges, int distanceThreshold) {
    // Step 1: Initialize distance matrix with INT_MAX
    vector<vector<int>> distance(n, vector<int>(n, INT_MAX));

    // Step 2: For directed graph, only one direction is updated
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        distance[u][v] = wt;
    }

    // Step 3: Distance from a node to itself is 0
    for (int i = 0; i < n; ++i) {
        distance[i][i] = 0;
    }

    // Step 4: Floyd-Warshall algorithm
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (distance[i][k] != INT_MAX && distance[k][j] != INT_MAX)
                    distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    // Step 5: Find city with minimum reachable cities within the threshold
    int minReachable = n;
    int cityNumber = -1;

    for (int city = 0; city < n; ++city) {
        int count = 0;
        for (int otherCity = 0; otherCity < n; ++otherCity) {
            if (distance[city][otherCity] <= distanceThreshold)
                count++;
        }

        // Prefer city with higher index in case of tie
        if (count <= minReachable) {
            minReachable = count;
            cityNumber = city;
        }
    }

    return cityNumber;
}

