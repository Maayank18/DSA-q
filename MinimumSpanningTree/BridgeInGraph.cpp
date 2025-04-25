/*
🔍 PROBLEM STATEMENT:
Given a connected undirected graph with `n` nodes labeled from 0 to n - 1 and a list of connections,
where each connection is an undirected edge between two nodes. Return all the critical connections 
in the graph. A critical connection is an edge that, if removed, will make some nodes unreachable 
from others (i.e., it will increase the number of connected components).

📌 INPUT:
- n: number of nodes
- connections: vector of edges [u, v]

📌 OUTPUT:
- Vector of critical connections (bridges)

⏱ TIME COMPLEXITY: O(N + E)
🗃 SPACE COMPLEXITY: O(N + E)
*/

#include <bits/stdc++.h>
using namespace std;

int timer = 1;

// 🔁 DFS helper to detect bridges using Tarjan's Algorithm
void dfs(int node, int parent, vector<int> &visited,
         vector<int> adj[], vector<int> &startingTime,
         vector<int> &lowestNeighbourValue, vector<vector<int>> &bridges) {

    visited[node] = 1;
    startingTime[node] = lowestNeighbourValue[node] = timer++;

    for (auto it : adj[node]) {
        if (it == parent) continue; // Skip the edge to parent

        if (!visited[it]) {
            dfs(it, node, visited, adj, startingTime, lowestNeighbourValue, bridges);
            lowestNeighbourValue[node] = min(lowestNeighbourValue[node], lowestNeighbourValue[it]);

            // If the lowest time reachable from neighbor is greater than start time of current node, it's a bridge
            if (lowestNeighbourValue[it] > startingTime[node]) {
                bridges.push_back({node, it});
            }
        } else {
            // Back edge found
            lowestNeighbourValue[node] = min(lowestNeighbourValue[node], startingTime[it]);
        }
    }
}

// 🚀 Main function to find all critical connections (bridges)
vector<vector<int>> criticalConnection(int n, vector<vector<int>> &connections) {
    vector<int> adj[n]; // Adjacency list

    // Create adjacency list
    for (auto it : connections) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    vector<int> visited(n, 0);
    vector<int> startingTime(n);         // Discovery time
    vector<int> lowestNeighbourValue(n); // Lowest reachable time
    vector<vector<int>> bridges;         // Store bridges

    // Start DFS from node 0
    dfs(0, -1, visited, adj, startingTime, lowestNeighbourValue, bridges);

    return bridges;
}

// ------------------------ 🧪 DRIVER CODE ------------------------

int main() {
    int n = 5;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}, {3, 4}
    };

    vector<vector<int>> result = criticalConnection(n, connections);

    cout << "🔗 Critical Connections (Bridges) in the Graph:\n";
    for (auto bridge : result) {
        cout << bridge[0] << " - " << bridge[1] << endl;
    }

    return 0;
}
