#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem Statement:
-------------------
Given a directed graph with V vertices, determine whether it contains a cycle or not using **Kahn's Algorithm**.
This approach is based on Topological Sort:
- If all nodes are visited in a topological sort, the graph is acyclic.
- If some nodes remain unvisited (due to in-degrees not reaching 0), a cycle exists.

Time Complexity:
----------------
O(V + E), where V is the number of vertices and E is the number of edges.

Space Complexity:
-----------------
O(V), for in-degree array and queue.
*/

bool isCyclicKahnAlgo(int V, vector<int> adj[]) {
    queue<int> q;
    int inDegree[V] = {0};

    // Step 1: Calculate in-degree of all vertices
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            inDegree[it]++;
        }
    }

    // Step 2: Enqueue vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: Process nodes
    int count = 0; // Count of visited nodes
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        // Reduce in-degree of neighbors
        for (auto it : adj[node]) {
            inDegree[it]--;
            if (inDegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // If count != V, there is a cycle
    return count != V;
}

// ----------- Driver Code with Cycle Detection & Optional Topo Sort -----------
int main() {
    int V = 6;
    vector<int> adj[V];

    // Add directed edges
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);
    // Uncomment the below to introduce a cycle:
    // adj[1].push_back(4); // Adds a cycle

    // Cycle Detection
    bool hasCycle = isCyclicKahnAlgo(V, adj);
    if (hasCycle) {
        cout << "Cycle detected in the graph!" << endl;
    } else {
        cout << "No cycle detected. The graph is a DAG." << endl;
    }

    return 0;
}
