/*
Problem Statement:
------------------
You are given an undirected, weighted graph with 'n' nodes and 'm' edges.
Your task is to return the shortest path from node 1 (source) to node n (destination)
using Dijkstra’s algorithm.

If no such path exists, return {-1}.

Input:
- n: Total number of nodes (1-indexed)
- m: Total number of edges
- edges: A list of edges, where each edge is represented as {u, v, w}
         meaning there is an undirected edge between node u and node v with weight w

Output:
- A vector<int> representing the sequence of nodes in the shortest path from node 1 to node n
- If node n is unreachable from node 1, return {-1}

Constraints:
- 1 ≤ n ≤ 10^5
- 1 ≤ m ≤ 10^5
- 1 ≤ u, v ≤ n
- 1 ≤ w ≤ 10^5

Time Complexity:  O((N + M) * log N)
Space Complexity: O(N + M)
*/


#include <bits/stdc++.h>
using namespace std;

// Function to find the shortest path from node 1 to node n
vector<int> PrintingShortestPath(int n, int m, vector<vector<int>>& edges) {
    // ---------------- Step 1: Build Adjacency List ----------------
    // We're using 1-based indexing, so we define adj[n+1]
    // Each list at adj[u] contains pairs of (v, weight)
    vector<pair<int, int>> adj[n + 1]; 

    for (auto& it : edges) {
        int u = it[0]; // node 1
        int v = it[1]; // node 2
        int w = it[2]; // weight between u and v

        // Since the graph is undirected, add both u->v and v->u
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    // ---------------- Step 2: Initialize Dijkstra's Structures ----------------
    // Min-heap (priority queue) to always process the node with the smallest distance so far
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Distance array to store shortest distance from node 1 to every other node
    vector<int> distance(n + 1, 1e9); // initially set to "infinity"

    // Parent array to help us reconstruct the path later
    vector<int> parent(n + 1);

    // Initially, every node is its own parent (used for path reconstruction)
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    // Distance from node 1 to itself is 0
    distance[1] = 0;

    // Push the source node (1) into the priority queue with distance 0
    pq.push({0, 1}); // {distance, node}

    // ---------------- Step 3: Dijkstra's Algorithm ----------------
    while (!pq.empty()) {
        int dist = pq.top().first;  // current shortest distance
        int node = pq.top().second; // current node
        pq.pop();

        // Traverse all adjacent nodes
        for (auto& it : adj[node]) {
            int adjNode = it.first;      // neighboring node
            int edgeWeight = it.second;  // weight of the edge from node -> adjNode

            // Relaxation step:
            // If we found a shorter path to adjNode via current node
            if (dist + edgeWeight < distance[adjNode]) {
                distance[adjNode] = dist + edgeWeight; // update distance
                pq.push({distance[adjNode], adjNode}); // push updated distance to heap
                parent[adjNode] = node; // update parent to build the path later
            }
        }
    }

    // ---------------- Step 4: Check if Destination is Reachable ----------------
    // If distance to node n is still "infinity", it means it's not reachable
    if (distance[n] == 1e9) {
        return {-1}; // return -1 to indicate path doesn't exist
    }

    // ---------------- Step 5: Reconstruct the Path ----------------
    // Start from destination node n and go back to source (node 1) using parent array
    vector<int> path;
    int node = n;

    // Loop until we reach the source node
    while (parent[node] != node) {
        path.push_back(node);      // add current node to path
        node = parent[node];       // move to its parent
    }

    path.push_back(1);             // add the source node at the end

    // Since we built the path from n to 1, we reverse it to get 1 -> n
    reverse(path.begin(), path.end());

    // Return the reconstructed path
    return path;
}

int main() {
    int n = 5, m = 6;
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 4, 1},
        {2, 3, 3},
        {4, 3, 2},
        {3, 5, 6},
        {4, 5, 5}
    };

    vector<int> path = PrintingShortestPath(n, m, edges);

    cout << "Shortest Path from node 1 to node " << n << ":\n";
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}


