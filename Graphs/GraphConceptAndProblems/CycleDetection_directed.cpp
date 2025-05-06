#include <iostream>
#include <vector>
using namespace std;

/*
Problem Statement:
-------------------
Given a directed graph with V vertices, check whether the graph contains a cycle or not.
The graph is represented using an adjacency list. You need to return true if there is a cycle,
else return false.

This is a classic problem of cycle detection in a **Directed Graph** using **DFS** traversal
with the help of visited and pathVisited arrays.

Approach:
- We use Depth First Search (DFS) to explore nodes.
- 'visited[]' keeps track of all visited nodes globally.
- 'pathVisited[]' tracks the recursion stack to detect cycles within the current path.

Time Complexity:
----------------
O(V + E), where V = number of vertices and E = number of edges.
Each node and edge is visited once during DFS traversal.

Space Complexity:
-----------------
O(V), for the visited and pathVisited arrays and the recursion stack in the worst case.
*/

bool dfsCheck(int node, vector<int> adj[], int visited[], int pathVisited[]) {
    visited[node] = 1;
    pathVisited[node] = 1;

    for (auto it : adj[node]) {
        if (!visited[it]) {
            if (dfsCheck(it, adj, visited, pathVisited)) {
                return true;
            }
        } else if (pathVisited[it]) {
            return true; // A cycle is detected
        }
    }

    pathVisited[node] = 0; // Backtracking
    return false;
}

bool isCyclic(int V, vector<int> adj[]) {
    int visited[V] = {0};
    int pathVisited[V] = {0};

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfsCheck(i, adj, visited, pathVisited)) {
                return true;
            }
        }
    }
    return false;
}

// ---------------- Driver Code ----------------
int main() {
    int V = 4; // Number of vertices
    vector<int> adj[V];

    // Adding directed edges to the graph
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // This edge creates a cycle

    if (isCyclic(V, adj)) {
        cout << "Cycle detected in the directed graph." << endl;
    } else {
        cout << "No cycle in the directed graph." << endl;
    }

    return 0;
}
