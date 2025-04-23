/*
🌊 Problem Statement:
You are given a `n x m` grid where all cells are initially water (0).
You are given a list of `operators` that each add land (1) at a given position.
Return the number of **islands (i.e., connected components of land)** after each operation.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically.

🕒 Time Complexity: O(K * 4 * α(NM)) ≈ O(K), where K = number of operations, α = inverse Ackermann
💾 Space Complexity: O(N * M) for visited matrix and DSU arrays
*/

#include <bits/stdc++.h>
using namespace std;

// DSU class to manage connected components
class DisjointSet {
    vector<int> parent;  // parent[i] is the representative of the set containing i
    vector<int> size;    // size[i] stores size of the tree rooted at i

public:
    // 🧱 Constructor to initialize DSU for n elements
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    // 🔍 Find with path compression
    int FindUltimateParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = FindUltimateParent(parent[node]);
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

// 🔍 Check if a cell is valid (within bounds)
bool isValid(int nrow, int ncol, int n, int m) {
    return nrow >= 0 && nrow < n && ncol >= 0 && ncol < m;
}

// 🧮 Function to compute number of islands after each operation
vector<int> numOfIslands(int n, int m, vector<vector<int>>& operators) {
    DisjointSet ds(n * m); // Flattened grid of size n * m
    vector<vector<int>> visited(n, vector<int>(m, 0)); // 2D visited grid

    int cnt = 0; // Total number of islands
    vector<int> ans;

    for (auto it : operators) {
        int row = it[0];
        int column = it[1];

        // If it's already land, just return current count
        if (visited[row][column] == 1) {
            ans.push_back(cnt);
            continue;
        }

        visited[row][column] = 1;
        cnt++; // New land potentially creates a new island

        // Check 4 directions: up, right, down, left
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int nrow = row + drow[i];
            int ncol = column + dcol[i];

            if (isValid(nrow, ncol, n, m)) {
                if (visited[nrow][ncol] == 1) {
                    int nodeNo = row * m + column; // Current node index in DSU
                    int adjNodeNo = nrow * m + ncol; // Adjacent node index in DSU

                    // If not already connected, connect and reduce island count
                    if (ds.FindUltimateParent(nodeNo) != ds.FindUltimateParent(adjNodeNo)) {
                        cnt--;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        ans.push_back(cnt); // Save current count of islands
    }

    return ans;
}

// 🧪 Driver code
int main() {
    int n = 4, m = 5;
    vector<vector<int>> operators = {
        {1, 1}, {0, 1}, {3, 3}, {3, 4}
    };

    vector<int> result = numOfIslands(n, m, operators);
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
