/*
Problem Statement:
-------------------
Given a directed acyclic graph (DAG) with 'n' nodes and 'm' edges,
each edge having a weight, find the shortest path from node 0 to all other nodes.

Input:
- n: Number of vertices
- m: Number of edges
- edges: Each edge is represented as a triplet {u, v, wt} meaning there's an edge from u to v with weight wt

Output:
- A vector of size 'n' where ans[i] is the shortest distance from node 0 to i
- If node i is not reachable from 0, its distance should be -1

Time Complexity: O(N + M)
Space Complexity: O(N + M)
*/

#include <bits/stdc++.h>
using namespace std;

// Helper function: Topological sort using DFS
void topoSortDFS(int node, vector<pair<int, int>> adj[], int visited[], stack<int> &st) {
    visited[node] = 1;

    for (auto it : adj[node]) {
        int v = it.first;
        if (!visited[v]) {
            topoSortDFS(v, adj, visited, st);
        }
    }

    st.push(node); // Push the node once all its dependencies are processed
}

// Main function to find shortest path in DAG
vector<int> ShortestPathDirectedGraph(int n, int m, vector<vector<int>> &edges) {
    // Step 1: Create adjacency list from edge list
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adj[u].push_back({v, wt});
    }

    // Step 2: Perform Topological Sort
    int visited[n] = {0};
    stack<int> st;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            topoSortDFS(i, adj, visited, st);
        }
    }

    // Step 3: Initialize distance array
    vector<int> distance(n, 1e9);
    distance[0] = 0; // Assuming source is node 0

    // Step 4: Process nodes in topological order
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (distance[node] != 1e9) {  // not compulsary
            for (auto it : adj[node]) {
                int v = it.first;
                int wt = it.second;

                if (distance[node] + wt < distance[v]) {
                    distance[v] = distance[node] + wt;
                }
            }
        }
    }

    // Step 5: Mark unreachable nodes as -1
    for (int i = 0; i < n; i++) {
        if (distance[i] == 1e9) {
            distance[i] = -1;
        }
    }

    return distance;
}

// Driver Code
int main() {
    int n = 6; // number of nodes
    int m = 7; // number of edges

    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 4, 1}, {1, 2, 3},
        {4, 2, 2}, {2, 3, 6}, {4, 5, 4}, {5, 3, 1}
    };

    vector<int> result = ShortestPathDirectedGraph(n, m, edges);

    cout << "Shortest distances from node 0:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}
