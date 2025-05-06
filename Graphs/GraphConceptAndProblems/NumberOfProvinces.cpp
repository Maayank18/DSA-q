/*
Problem Statement:
------------------
Given a 2D matrix 'adj' representing the adjacency matrix of an undirected graph
with 'v' vertices, return the number of connected components (also known as provinces).
A province is a group of directly or indirectly connected cities.

Time Complexity: O(V^2) - due to traversing the adjacency matrix
Space Complexity: O(V + E) - for the adjacency list and visited array
*/

#include <iostream>
#include <vector>
using namespace std;

// Depth First Search function to visit all connected nodes
void dfs(int node, vector<vector<int>>& adjList, vector<int>& visited) {
    visited[node] = 1;  // Mark the current node as visited

    // Visit all unvisited neighbors
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

// Function to count number of connected components (provinces)
int countingProvinces(vector<vector<int>> adj, int v) {
    // Convert adjacency matrix to adjacency list
    vector<vector<int>> adjList(v);
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (adj[i][j] == 1 && i != j) {
                adjList[i].push_back(j);
            }
        }
    }

    // Visited array to track visited nodes
    vector<int> visited(v, 0);
    int count = 0;

    // Perform DFS for each unvisited node
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            count++;  // Found a new province
            dfs(i, adjList, visited);
        }
    }

    return count;
}

// Example usage
int main() {
    vector<vector<int>> adj = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };
    int v = 3;

    cout << "Number of provinces: " << countingProvinces(adj, v) << endl;
    return 0;
}
