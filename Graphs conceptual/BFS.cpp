/*
Time Complexity: O(V + E)
- V: Number of vertices
- E: Number of edges
- Each node is visited once (O(V)), and all its adjacent nodes are traversed (O(E)).

Space Complexity: O(V)
- Visited array: O(V)
- Queue storage: O(V) (in worst case when all nodes are in the queue)
- BFS output: O(V)

Graph Type:
- The given adjacency list represents an **undirected graph**, meaning edges are bidirectional.
- If it were a directed graph, we would only add edges in one direction.
*/

#include <bits/stdc++.h>
using namespace std;

// Function to perform Breadth-First Search (BFS) on a graph
vector<int> bfsOfGraph(int v, vector<int> adj[]) {
    vector<int> bfs;  // Stores BFS traversal order
    vector<int> visited(v, 0);  // Visited array initialized with 0 (false)

    queue<int> q;  // Queue for BFS traversal
    visited[0] = 1;  // Mark the starting node (0) as visited
    q.push(0);  // Push the first node (assuming 0-based indexing)

    // BFS traversal
    while (!q.empty()) {
        int node = q.front();  // Get the front node of the queue
        q.pop();
        bfs.push_back(node);  // Store the node in BFS result

        // Traverse all adjacent nodes
        for (auto it : adj[node]) {
            if (!visited[it]) {  // If the node is not visited
                visited[it] = 1;  // Mark as visited
                q.push(it);  // Push into queue for processing
            }
        }
    }
    return bfs;
}

// Driver Code
int main() {
    int v = 5;  // Number of vertices
    vector<int> adj[v]; // Adjacency list representation

    // Sample graph edges (0-based indexing)
    // This represents an undirected graph
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};

    // Perform BFS and get the traversal order
    vector<int> bfs_result = bfsOfGraph(v, adj);

    // Print BFS traversal
    cout << "BFS Traversal: ";
    for (int node : bfs_result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}


