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


// 🎯 Main function to solve the problem
int minOperation(int n, vector<vector<int>>& edges) {
    DisjointSet ds(n);
    int cntExtras = 0; // To count extra edges

    // 🧪 Process each edge
    for (auto it : edges) {
        int u = it[0];
        int v = it[1];
        if (ds.FindUltimateParent(u) == ds.FindUltimateParent(v)) {
            cntExtras++; // Edge creates a cycle
        } else {
            ds.unionBySize(u, v); // Merge the two components
        }
    }

    // 🧮 Count number of connected components
    int cntConnected = 0;
    for (int i = 0; i < n; i++) {
        if (ds.FindUltimateParent(i) == i) cntConnected++;
    }

    int operationsNeeded = cntConnected - 1;

    // ✅ If we have enough extra edges, we can connect all components
    if (cntExtras >= operationsNeeded) return operationsNeeded;

    // ❌ Not enough extra edges to connect all components
    return -1;
}

// 🧪 Driver Code for Testing
int main() {
    int n = 6; // Number of nodes (0 to 5)
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {0, 3}, {1, 4}
    };

    int result = minOperation(n, edges);
    cout << "Minimum operations needed to connect all components: " << result << endl;

    /*
        Sample Explanation:
        We have 6 nodes and 4 edges.
        Initially, nodes 0,1,2,3,4 will be in one component. Node 5 is disconnected.
        Total components = 2
        We need 1 operation (connect one edge) to make the graph fully connected.
        But we don’t have any extra edge, so answer = -1
    */

    return 0;
}