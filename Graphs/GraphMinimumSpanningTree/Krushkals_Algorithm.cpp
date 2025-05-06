/*
📌 Problem Statement:
----------------------
Implement Kruskal’s Algorithm to find the weight of the **Minimum Spanning Tree (MST)** 
of a given undirected weighted graph using the **Disjoint Set Union (DSU)** data structure.

🛠️ What’s Kruskal’s Algorithm?
- Sort all the edges by weight.
- Iterate through the sorted edge list and pick the edge if it does NOT form a cycle.
- Use DSU to detect cycles efficiently.

📊 Time Complexity:
- O(E * logE) + O(E * 4α) ≈ O(E logE), where E = number of edges, α = inverse Ackermann function

📦 Space Complexity:
- O(N + E) for DSU and edge storage

👨‍🔧 Input:
- v: Number of vertices
- adj: Adjacency list in the form adj[u] = {{v, wt}, {v2, wt2}, ...}

🔁 Output:
- Returns the total weight of the Minimum Spanning Tree
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ✅ Disjoint Set Class (Union by Size + Path Compression)
class DisjointSet {
    vector<int> parent, size;

public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUltimateParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUltimateParent(parent[node]); // Path compression
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if (ulp_u == ulp_v) return; // Already in same component

        // Attach smaller tree under larger one
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// 🌳 Kruskal's Algorithm Function
int KruskalAlgo(int v, vector<vector<int>> adj[]) {
    vector<pair<int, pair<int, int>>> edges; // {weight, {u, v}}

    // 🏗️ Convert adjacency list to edge list
    for (int i = 0; i < v; i++) {
        for (auto it : adj[i]) {
            int adjNode = it[0];
            int weight = it[1];
            int node = i;

            edges.push_back({weight, {node, adjNode}});
        }
    }

    // ✅ Sort edges based on weight
    sort(edges.begin(), edges.end());

    DisjointSet ds(v);
    int mstWeight = 0;

    // ⚙️ Pick the lightest edge that doesn't form a cycle
    for (auto it : edges) {
        int weight = it.first;
        int u = it.second.first;
        int v = it.second.second;

        // Only add edge if it connects two different components
        if (ds.findUltimateParent(u) != ds.findUltimateParent(v)) {
            mstWeight += weight;          // Add edge's weight to MST
            ds.unionBySize(u, v);         // Merge the sets
        }
    }

    return mstWeight;
}

int main() {
    int V = 4;
    vector<vector<int>> adj[V];

    // Example: Undirected edges {u, v, wt}
    adj[0].push_back({1, 10});
    adj[1].push_back({0, 10});
    adj[0].push_back({2, 6});
    adj[2].push_back({0, 6});
    adj[0].push_back({3, 5});
    adj[3].push_back({0, 5});
    adj[1].push_back({3, 15});
    adj[3].push_back({1, 15});
    adj[2].push_back({3, 4});
    adj[3].push_back({2, 4});

    cout << "MST Weight = " << KruskalAlgo(V, adj) << endl;

    return 0;
}

