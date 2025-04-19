/*
Problem Statement:
------------------
You are given an integer `n` representing the number of cities, an array `edges` 
where each element is of the form [u, v, w] representing an undirected edge 
between city u and city v with distance w, and an integer `distanceThreshold`.

Your task is to find the city with the smallest number of cities that are reachable 
through paths with distance at most `distanceThreshold`.

If there are multiple such cities, return the city with the greatest number.

Input:
- n: number of cities
- m: number of edges
- edges: a 2D vector representing the edges [u, v, weight]
- distanceThreshold: the threshold distance

Output:
- Return the city number with the smallest number of reachable neighbors 
  within the given distance threshold. In case of a tie, return the city 
  with the larger index.

Time Complexity: O(n^3)
Space Complexity: O(n^2)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findCity(int n, int m, vector<vector<int>> &edges, int distanceThreshold) {
    // Step 1: Initialize distance matrix with INT_MAX
    vector<vector<int>> distance(n, vector<int>(n, INT_MAX));

    // Step 2: Set distances for given edges
    for (auto it : edges) {
        int u = it[0], v = it[1], wt = it[2];
        distance[u][v] = wt;
        distance[v][u] = wt;  // Undirected graph
    }

    // Step 3: Set distance to self as 0
    for (int i = 0; i < n; i++) {
        distance[i][i] = 0;
    }

    // Step 4: Floyd-Warshall Algorithm to compute all-pairs shortest path
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (distance[i][k] == INT_MAX || distance[k][j] == INT_MAX)
                    continue;
                distance[i][j] = min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }

    // Step 5: Find city with the smallest number of reachable cities within the threshold
    int cntCity = n;     // Maximum possible initially
    int cityNo = -1;

    for (int city = 0; city < n; city++) {
        int cnt = 0;
        for (int adjCity = 0; adjCity < n; adjCity++) {
            if (distance[city][adjCity] <= distanceThreshold) {
                cnt++;
            }
        }

        // Update city if smaller count found or same count with greater index
        if (cnt <= cntCity) {
            cntCity = cnt;
            cityNo = city;
        }
    }

    return cityNo;
}

int main() {
    int n = 4;
    int m = 4;
    vector<vector<int>> edges = {
        {0, 1, 3},
        {1, 2, 1},
        {1, 3, 4},
        {2, 3, 1}
    };
    int distanceThreshold = 4;

    cout << "City with minimum reachable neighbors: " << findCity(n, m, edges, distanceThreshold) << endl;
    return 0;
}
