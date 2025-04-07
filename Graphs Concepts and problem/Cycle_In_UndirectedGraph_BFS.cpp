/*
-----------------------------------------------------
📝 Problem: Detect Cycle in an Undirected Graph (BFS Approach)

🔍 Description:
Given an undirected graph with `v` vertices (0-based indexing) and an adjacency list `adj[]`,
determine whether the graph contains a **cycle**.

We use **BFS traversal** to detect cycles in the graph. A cycle is detected if a visited node
is encountered again and it's not the immediate parent of the current node (in undirected graphs).

📥 Input:
- v: number of vertices
- adj[]: adjacency list representing the undirected graph

📤 Output:
- true  → if the graph contains a cycle
- false → if the graph does not contain any cycle

-----------------------------------------------------
📈 Time Complexity: O(V + E)
- V = number of vertices
- E = number of edges
- Each node and edge is visited once in BFS.

🧠 Space Complexity: O(V)
- For visited array and queue used in BFS.

-----------------------------------------------------
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Helper function to perform BFS and detect cycle from the source node
bool detectCycleBFS(int source, vector<int> adj[], int visited[]) {
    visited[source] = 1; // Mark the source as visited

    // Queue stores (current node, parent node)
    queue<pair<int, int>> q;
    q.push({source, -1}); // For the first node, parent is -1 (no parent)

    while (!q.empty()) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        // Check all adjacent nodes
        for (auto adjacentNode : adj[node]) {
            // If the adjacent node is not visited, push it to the queue
            if (!visited[adjacentNode]) {
                visited[adjacentNode] = 1;
                q.push({adjacentNode, node});
            }
            // If already visited and not the parent, then it's a cycle
            else if (adjacentNode != parent) {
                return true; // Cycle detected
            }
        }
    }

    return false; // No cycle found in this component
}

// Main function to check for cycle in all connected components of the graph
bool isCycle(int v, vector<int> adj[]) {
    int visited[v] = {0}; // Initialize all nodes as unvisited

    // For disconnected graphs, check every component
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (detectCycleBFS(i, adj, visited)) {
                return true; // If any component has a cycle
            }
        }
    }

    return false; // No cycle in any component
}

// Example usage
int main() {
    int v = 5; // Number of vertices

    // Creating adjacency list for undirected graph
    vector<int> adj[v];

    // Adding edges
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    // adj[4].push_back(1); // Uncomment this line to introduce a cycle

    if (isCycle(v, adj)) {
        cout << "Cycle Detected in the Graph." << endl;
    } else {
        cout << "No Cycle in the Graph." << endl;
    }

    return 0;
}
