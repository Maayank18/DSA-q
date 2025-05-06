/*
📌 Problem Statement:
You're given an `n x n` grid where:
- 1 represents a **land cell** (connected),
- 0 represents a **water cell** (can be converted to land once).

You can change **at most one** water cell (0) to land (1). Your goal is to return the **maximum size** of a connected group of land cells (i.e., an island) you can get after this change.

Two land cells are connected **4-directionally** (up, down, left, right).

Example:
Input: grid = [[1, 0], [0, 1]]
Output: 3
Explanation: Change one 0 to 1 (e.g., grid[0][1] = 1), then you have a connected island of size 3.

🧠 Time Complexity:
- O(N² * 4 * α(N²)) where α is the inverse Ackermann function (very small), due to DSU operations over each cell and its 4 neighbors.

🧠 Space Complexity:
- O(N²) for DSU parent and size arrays
- O(1) additional (excluding DSU)
*/

#include <bits/stdc++.h>
using namespace std;

// 👨‍👦‍👦 Disjoint Set Union with Union by Size and Path Compression
class DisjointSet {
    vector<int> parent;  // parent[i] = representative of the set containing i
    vector<int> size;    // size[i] = size of the component rooted at i

public:
    // 🧱 Constructor to initialize DSU for n elements
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1); // Every node initially in its own component of size 1
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each node is its own parent
        }
    }

    // 🔍 Find operation with path compression
    int FindUltimateParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = FindUltimateParent(parent[node]);
    }

    // 🔗 Union by size
    void unionBySize(int u, int v) {
        int ulp_u = FindUltimateParent(u);
        int ulp_v = FindUltimateParent(v);
        if (ulp_u == ulp_v) return;

        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    // 🔍 Get size of the component containing node
    int getSize(int node) {
        return size[FindUltimateParent(node)];
    }
};

// 🚀 Main function to get max connected island size after flipping at most one 0
int MaxConnections(vector<vector<int>>& grid) {
    int n = grid.size();
    DisjointSet ds(n * n);

    // Step 1: Connect all adjacent land cells (1s)
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (grid[row][col] == 0) continue;

            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1) {
                    int nodeNo = row * n + col;
                    int adjNode = nrow * n + ncol;
                    ds.unionBySize(nodeNo, adjNode);
                }
            }
        }
    }

    int mx = 0;

    // Step 2: Try flipping each 0 to 1 and calculate the size of resulting island
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (grid[row][col] == 1) continue;

            set<int> components;
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, 1, 0, -1};

            // Collect unique components of neighboring 1s
            for (int i = 0; i < 4; i++) {
                int nrow = row + drow[i];
                int ncol = col + dcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1) {
                    int neighborNode = nrow * n + ncol;
                    components.insert(ds.FindUltimateParent(neighborNode));
                }
            }

            int sizeTotal = 1; // Count the flipped cell as land
            for (auto it : components) {
                sizeTotal += ds.getSize(it);
            }
            mx = max(mx, sizeTotal);
        }
    }

    // Step 3: If grid has all 1s, find largest existing island
    for (int i = 0; i < n * n; i++) {
        mx = max(mx, ds.getSize(i));
    }

    return mx;
}

// 🧪 Driver Code
int main() {
    vector<vector<int>> grid = {
        {1, 0},
        {0, 1}
    };

    cout << "Maximum island size after flipping one 0: " << MaxConnections(grid) << endl;

    return 0;
}
