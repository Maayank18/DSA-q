/*
Problem Statement:
-------------------
Given an undirected unweighted graph with 'n' nodes and 'm' edges,
return the shortest path from the given 'source' node to all other nodes.

If a node is not reachable from the source, return -1 for that node.

Input:
- edges: 2D vector where each edge[i] = [u, v] represents an undirected edge between u and v
- n: number of nodes (numbered from 0 to n-1)
- m: number of edges
- source: the starting node to compute shortest distances from

Output:
- A vector of size 'n' where ans[i] = shortest distance from source to i, or -1 if unreachable

Constraints:
1 ≤ n ≤ 10^4
0 ≤ m ≤ 2 * 10^4

Time Complexity: O(n + m)
Space Complexity: O(n + m)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> ShortestPath(vector<vector<int>> &edges, int n, int m, int source) {
    // Step 1: Convert edge list to adjacency list
    vector<int> adj[n];
    for (auto it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]); // Since it's an undirected graph
    }

    // Step 2: Initialize distance array with a large number
    vector<int> distance(n, 1e9); // 1e9 is used to represent "infinity"
    distance[source] = 0;         // Distance to source is 0

    // Step 3: BFS queue
    queue<int> q;
    q.push(source);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Visit all neighbors
        for (auto it : adj[node]) {
            if (distance[node] + 1 < distance[it]) {
                distance[it] = distance[node] + 1;
                q.push(it); // Push into queue for further traversal
            }
        }
    }

    // Step 4: Prepare answer array with -1 for unreachable nodes
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (distance[i] != 1e9) {
            ans[i] = distance[i];
        }
    }

    return ans;
}

// Driver Code for Testing
int main() {
    int n = 6, m = 7;
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 5}
    };
    int source = 0;

    vector<int> result = ShortestPath(edges, n, m, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < result.size(); i++) {
        cout << "Node " << i << " : " << result[i] << endl;
    }

    return 0;
}
