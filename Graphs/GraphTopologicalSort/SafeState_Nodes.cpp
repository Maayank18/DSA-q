/*
    🧠 PROBLEM STATEMENT:

    - You are given a directed graph with 'V' vertices (0 to V-1) represented using an adjacency list.
    - A node is called a **terminal node** if it has no outgoing edges.
    - A node is called a **safe node** if every possible path starting from that node leads to a terminal node.
    - Your task is to return all the **safe nodes** in **ascending order**.

    ✅ Example:
       Input:
       V = 7
       adj = [[1,2], [2,3], [5], [0], [5], [], [4,5]]
       
       Output:
       Safe Nodes: 2 4 5 6

    💡 APPROACH:

    - Step 1: Reverse the graph.
    - Step 2: Track the in-degrees (which were out-degrees in the original graph).
    - Step 3: Use a queue to perform topological sorting (Kahn's Algorithm).
    - Step 4: Nodes which can reach terminal nodes only (i.e., no cycles) are collected.
    - Step 5: Return the sorted list of safe nodes.

    ⏱️ TIME COMPLEXITY:  O(V + E) → where V = number of vertices, E = number of edges
    🧠 SPACE COMPLEXITY: O(V + E) → for storing reverse graph and in-degree array
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find all safe nodes in the graph
vector<int> SafeStatesNodes(int V, vector<int> adj[]) {
    // Create reverse of the given graph
    vector<int> adjReverse[V];

    // Store the in-degree of each node in reverse graph
    vector<int> inDegree(V, 0);

    // Reversing the edges and calculating in-degrees
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            adjReverse[it].push_back(i); // Reverse the edge: i -> it becomes it -> i
            inDegree[i]++;               // Increase out-degree (becomes in-degree in reversed graph)
        }
    }

    // Queue to store nodes with in-degree 0 (i.e., terminal nodes in original graph)
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i); // Terminal or safe node candidate
        }
    }

    // Store safe nodes
    vector<int> SafeNodes;

    // Perform topological sort (Kahn's Algorithm)
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        SafeNodes.push_back(node); // Node is safe

        // Reduce in-degree of connected nodes in reverse graph
        for (auto it : adjReverse[node]) {
            inDegree[it]--;
            if (inDegree[it] == 0) {
                q.push(it); // If in-degree becomes 0, it's safe now
            }
        }
    }

    // Sort the safe nodes in ascending order
    sort(SafeNodes.begin(), SafeNodes.end());

    return SafeNodes;
}

// ------------------- Driver Code -------------------
int main() {
    // Number of nodes in the graph
    int V = 7;

    // Adjacency list representing the directed graph
    vector<int> adj[V];
    adj[0] = {1, 2};
    adj[1] = {2, 3};
    adj[2] = {5};
    adj[3] = {0};
    adj[4] = {5};
    adj[5] = {};     // Terminal node
    adj[6] = {4, 5};

    // Get the list of safe nodes
    vector<int> result = SafeStatesNodes(V, adj);

    // Output the result
    cout << "Safe Nodes: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
