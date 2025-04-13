/*
Problem Statement:
-------------------
Given a graph with 'v' vertices and a source vertex 'S', find the shortest distances 
from the source to all other vertices using Dijkstra’s algorithm. The graph has no 
negative edge weights.

Input:
- v: Number of vertices (0-indexed)
- adj: Adjacency list where each element is of the form adj[u] = {{v1, w1}, {v2, w2}, ...}
  meaning there is an edge from u to vi with weight wi.
- S: Source vertex

Output:
- A vector<int> where result[i] is the shortest distance from source 'S' to node 'i'.
- If a node is unreachable, it will still be 1e9 in the vector.

Time Complexity: O(E log V) — due to priority queue operations
Space Complexity: O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int v, vector<vector<pair<int, int>>> adj, int S) {
    // Min-heap: {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    vector<int> distance(v, 1e9); // Initialize all distances to "infinity" (1e9)
    distance[S] = 0;

    pq.push({0, S}); // Push source with distance 0

    while (!pq.empty()) {
        int dist = pq.top().first;  // current distance from source
        int node = pq.top().second; // current node
        pq.pop();

        for (auto it : adj[node]) {
            int edgeWeight = it.second;
            int neighborNode = it.first;

            // Relaxation step
            if (dist + edgeWeight < distance[neighborNode]) {
                distance[neighborNode] = dist + edgeWeight;
                pq.push({distance[neighborNode], neighborNode});
            }
        }
    }

    return distance;
}

// Driver Code Example
int main() {
    int v = 5; // number of vertices
    int source = 0;

    // Adjacency list: node -> {{neighbour, weight}, ...}
    vector<vector<pair<int, int>>> adj(v);

    // Example graph:
    adj[0].push_back({1, 2});
    adj[0].push_back({4, 1});
    adj[1].push_back({2, 3});
    adj[4].push_back({2, 2});
    adj[2].push_back({3, 6});
    adj[4].push_back({3, 5});

    vector<int> result = dijkstra(v, adj, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < v; i++) {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}
