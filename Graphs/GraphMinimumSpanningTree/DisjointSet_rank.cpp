/*
🧠 Problem Statement:
----------------------
Implement the Disjoint Set Union (DSU) data structure using:
1. Union by Rank optimization
2. Path Compression optimization

👉 This structure allows us to:
- Find the representative (ultimate parent) of a set.
- Merge two sets efficiently.
- Solve problems like cycle detection in graphs, Kruskal’s algorithm, grouping, etc.

🕒 Time Complexity:
- Nearly O(1) per operation (amortized), due to optimizations.

🗂️ Space Complexity:
- O(N), where N is the number of nodes.
*/

#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> rank;   // Rank: used to keep tree shallow
    vector<int> parent; // Parent: stores representative of each node

public:
    // Constructor: Initialize DSU for 'n' elements
    DisjointSet(int n) {
        rank.resize(n + 1, 0);   // All ranks start at 0
        parent.resize(n + 1);    // Each node is its own parent
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // 🔍 Find the ultimate parent of a node (with path compression)
    int FindUltimateParent(int node) {
        if (node == parent[node]) return node; // Base case
        return parent[node] = FindUltimateParent(parent[node]); // Path compression
    }

    // 🔗 Union of two nodes based on rank
    void unionByRank(int u, int v) {
        int ulp_u = FindUltimateParent(u); // Find representative of u
        int ulp_v = FindUltimateParent(v); // Find representative of v

        if (ulp_u == ulp_v) return; // They are already in the same set

        // Attach smaller rank tree under the higher rank tree
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            // If ranks are equal, make one root and increment its rank
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

int main() {
    DisjointSet ds(7);

    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // Initially, 3 and 7 are not connected
    if (ds.FindUltimateParent(3) == ds.FindUltimateParent(7)) {
        cout << "Same component\n";
    } else {
        cout << "Different component\n";
    }

    ds.unionByRank(3, 7); // Connect the components

    // Now, 3 and 7 are connected
    if (ds.FindUltimateParent(3) == ds.FindUltimateParent(7)) {
        cout << "Same component\n";
    } else {
        cout << "Different component\n";
    }

    return 0;
}

