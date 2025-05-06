/*
-----------------------------------------------------
📝 Problem: Detect Cycle in an Undirected Graph (DFS)

🔍 Description:
Using DFS, we explore each path and backtrack when necessary.
If we encounter a previously visited node that is **not the parent** of the current node,
a cycle exists in the graph.

📈 Time Complexity: O(V + E)
🧠 Space Complexity: O(V)
-----------------------------------------------------
*/

#include <iostream>
#include <vector>
using namespace std;

// Helper function to detect cycle via DFS
bool dfs(int node, int parent, vector<int> &visited, vector<int> adj[]) {
    visited[node] = 1;

    for (auto adjacentNode : adj[node]) {
        if (!visited[adjacentNode]) {
            // Recursively visit the neighbor
            if (dfs(adjacentNode, node, visited, adj)) {
                return true;
            }
        } else if (adjacentNode != parent) {
            // If already visited and not parent → cycle detected
            return true;
        }
    }

    return false;
}

// Main function to check for cycle in all components
bool isCycle(int v, vector<int> adj[]) {
    vector<int> visited(v, 0);

    // Check each component
    for (int i = 0; i < v; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, visited, adj)) {
                return true;
            }
        }
    }

    return false;
}

// Driver Code Example
int main() {
    int v = 5;
    vector<int> adj[v];

    // Example graph edges
    adj[0].push_back(1);
    adj[1].push_back(0);

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[2].push_back(3);
    adj[3].push_back(2);

    adj[3].push_back(4);
    adj[4].push_back(3);

    // Uncomment to add a cycle:
    // adj[4].push_back(1);
    // adj[1].push_back(4);

    if (isCycle(v, adj)) {
        cout << "Cycle Detected (DFS)" << endl;
    } else {
        cout << "No Cycle Detected (DFS)" << endl;
    }

    return 0;
}
