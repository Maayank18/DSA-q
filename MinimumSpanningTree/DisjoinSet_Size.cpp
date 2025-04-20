/*
🧠 Problem Statement:
----------------------
Implement the Disjoint Set Union (DSU) data structure using:
1. Union by Size optimization
2. Path Compression optimization

👉 This structure is helpful in:
- Grouping elements efficiently
- Solving cycle detection problems
- Building Minimum Spanning Trees (like Kruskal's Algorithm)
- Efficient merging and lookup of disjoint sets

🕒 Time Complexity:
- Nearly O(1) per operation (amortized) due to the optimizations.

🗂️ Space Complexity:
- O(N), where N is the number of nodes.
*/

#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    vector<int> parent;  // parent[i] is the representative of the set containing i
    vector<int> size;    // size[i] stores size of the tree rooted at i

public:
    // 🧱 Constructor to initialize DSU for n elements
    DisjointSet(int n) {
        parent.resize(n + 1); // Nodes are from 0 to n
        size.resize(n + 1, 1); // Initially each node is a component of size 1
        for (int i = 0; i <= n; i++) {
            parent[i] = i; // Each node is initially its own parent
        }
    }

    // 🔍 Find with path compression
    int FindUltimateParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = FindUltimateParent(parent[node]); // Path compression
    }

    // 🔗 Union by size
    void unionBySize(int u, int v) {
        int ulp_u = FindUltimateParent(u);
        int ulp_v = FindUltimateParent(v);

        if (ulp_u == ulp_v) return; // Already in same set

        // Attach smaller set under the bigger one
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main() {
    DisjointSet ds(7);

    ds.unionBySize(1, 2);
    ds.unionBySize(2, 3);
    ds.unionBySize(4, 5);
    ds.unionBySize(6, 7);
    ds.unionBySize(5, 6);

    if (ds.FindUltimateParent(3) == ds.FindUltimateParent(7)) {
        cout << "Same component\n";
    } else {
        cout << "Different components\n";
    }

    ds.unionBySize(3, 7);

    if (ds.FindUltimateParent(3) == ds.FindUltimateParent(7)) {
        cout << "Now same component\n";
    }

    return 0;
}
