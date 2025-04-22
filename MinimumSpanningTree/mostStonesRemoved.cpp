/*
🧩 Problem: Most Stones Removed with Same Row or Column

📄 You are given a 2D array `stones` where each stone is at coordinate (x, y).
You can remove a stone if there is another stone in the same row or same column.

👉 Goal: Return the maximum number of stones you can remove.

🧪 Example:
Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
(You can leave just one connected component and remove the rest.)

🕒 Time Complexity:
- O(N * α(N)) where N = number of stones, and α is the inverse Ackermann function (almost constant).

🧠 Space Complexity:
- O(N), where N = number of stones.
*/


#include <bits/stdc++.h>
using namespace std;

// Disjoint Set Union (DSU) with path compression and union by size
class DisjointSet {
    vector<int> rank, parent, size;

public:
    // Constructor to initialize DSU for n elements
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i; // Initially, each element is its own parent
    }

    // Finds the ultimate parent of a node
    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]); // Path compression
    }

    // Union by size (connects smaller component to larger one)
    void unionBySize(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return; // Already connected
        if (size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0, maxCol = 0;

        // Find the maximum row and column number to size DSU
        for (auto it : stones) {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }

        // Create DSU for (maxRow + maxCol + 1) elements
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;

        // Connect each stone's row and column in DSU
        for (auto it : stones) {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1; // Offset columns to avoid overlap
            ds.unionBySize(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }

        // Count how many connected components are there
        int cnt = 0;
        for (auto it : stoneNodes) {
            if (ds.findUPar(it.first) == it.first) {
                cnt++; // It is a representative node
            }
        }

        // Answer = total stones - number of connected components
        return n - cnt;
    }
};


int main() {
    Solution sol;
    
    vector<vector<int>> stones = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 2},
        {2, 1},
        {2, 2}
    };

    int n = stones.size();

    cout << "Maximum stones that can be removed: " << sol.maxRemove(stones, n) << endl;

    return 0;
}
