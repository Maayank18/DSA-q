/*
Problem Statement:
------------------
Given an undirected graph with `v` vertices, check whether the graph is **bipartite** or not.

A graph is bipartite if you can color it using **two colors** such that no two adjacent nodes have the same color.
This can also be thought of as: can the graph be divided into two sets such that no two nodes in the same set are connected?

We solve this using DFS coloring. If at any point a neighboring node has the same color, it's not bipartite.

---------------------------------------------------------
Time Complexity:
- O(V + E), where:
    V = number of vertices
    E = number of edges
  (We visit every node and edge once)

Space Complexity:
- O(V) for the visited array (stores color)
- O(V) for the recursion stack in worst case
---------------------------------------------------------
*/

#include <bits/stdc++.h>
using namespace std;

// DFS function to color nodes and check for bipartite violation
bool dfs(int node, int color, int visited[], vector<int> adj[]) {
    visited[node] = color; // mark current node with a color

    // Visit all adjacent nodes
    for (auto neighbor : adj[node]) {
        if (visited[neighbor] == -1) {
            // Assign opposite color to the neighbor
            if (!dfs(neighbor, !color, visited, adj)) return false;
        } else if (visited[neighbor] == color) {
            // If the neighbor has same color → not bipartite
            return false;
        }
    }

    return true; // no violations found
}

// Function to check if the graph is bipartite
bool isBipartite(int v, vector<int> adj[]) {
    int visited[v]; // -1 → unvisited, 0 or 1 → two colors
    for (int i = 0; i < v; i++) visited[i] = -1;

    // Handle disconnected graphs by checking all components
    for (int i = 0; i < v; i++) {
        if (visited[i] == -1) {
            if (!dfs(i, 0, visited, adj)) return false;
        }
    }

    return true; // all components are bipartite
}

// Driver code to test the function
int main() {
    int V = 4; // number of vertices
    vector<int> adj[V];

    // Creating the graph:
    // 0 -- 1
    // |    |
    // 3 -- 2
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(0);
    adj[0].push_back(3);

    if (isBipartite(V, adj))
        cout << "The graph is Bipartite.\n";
    else
        cout << "The graph is NOT Bipartite.\n";

    return 0;
}
