/*
Problem Statement:
------------------
You are given an **undirected weighted graph** with `V` vertices represented 
using an adjacency list. Your task is to find the **sum of weights** of the 
Minimum Spanning Tree (MST) using **Prim’s Algorithm**.

Input:
- V (int): Number of vertices
- adj (vector<vector<int>> adj[]): The adjacency list, where for each node `u`,
  adj[u] is a list of {v, weight} pairs representing an edge from u to v.

Output:
- Return the total weight (sum) of the Minimum Spanning Tree.

Approach:
- Use a priority queue to always pick the edge with the least weight.
- Keep track of visited nodes to avoid cycles.
- Accumulate weights of edges added to MST.

Time Complexity: O(E * logV), where E is number of edges
Space Complexity: O(V)

Note: No parent array is used since we only care about the sum.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int spanningTree(int V, vector<vector<int>> adj[]) {
    // Min-heap: stores (weight, node)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Visited array to track which nodes are included in MST
    vector<int> visited(V, 0);

    // Start with node 0, weight 0
    pq.push({0, 0});

    int sum = 0;

    while (!pq.empty()) {
        auto it = pq.top(); pq.pop();
        int weight = it.first;
        int node = it.second;

        // Skip if already visited
        if (visited[node]) continue;

        // Mark as visited and add to MST sum
        visited[node] = 1;
        sum += weight;

        // Traverse adjacent nodes
        for (auto &edge : adj[node]) {
            int adjNode = edge[0];
            int edgeWeight = edge[1];

            if (!visited[adjNode]) {
                pq.push({edgeWeight, adjNode});
            }
        }
    }

    return sum;
}


int main() {
    int V = 5;
    vector<vector<int>> adj[V];

    // Add edges: {neighbor, weight}
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});

    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});

    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});

    adj[1].push_back({3, 8});
    adj[3].push_back({1, 8});

    adj[1].push_back({4, 5});
    adj[4].push_back({1, 5});

    adj[2].push_back({4, 7});
    adj[4].push_back({2, 7});

    int mstSum = spanningTree(V, adj);
    cout << "Total weight of MST: " << mstSum << endl;

    return 0;
}
