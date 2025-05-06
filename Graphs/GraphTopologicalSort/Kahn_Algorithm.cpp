#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem Statement:
-------------------
Given a Directed Acyclic Graph (DAG) with V vertices, perform Topological Sort using **Kahn's Algorithm** (BFS).
Topological sorting is a linear ordering of vertices such that for every directed edge u → v,
vertex u comes before v in the ordering.

Kahn’s Algorithm uses **in-degree** of each node and a **queue** to process nodes with in-degree 0.

Time Complexity:
----------------
O(V + E), where V is the number of vertices and E is the number of edges.

Space Complexity:
-----------------
O(V), for in-degree array, queue, and result vector.
*/

vector<int> topoSortKahnAlgo(int V, vector<int> adj[]) {
    queue<int> q;
    int inDegree[V] = {0};

    // Step 1: Calculate in-degree of all vertices
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            inDegree[it]++;
        }
    }

    // Step 2: Push all nodes with in-degree 0 into the queue
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: BFS traversal to generate topological ordering
    vector<int> ansTopo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ansTopo.push_back(node);

        // Decrease in-degree of neighboring nodes
        for (auto it : adj[node]) {
            inDegree[it]--;
            if (inDegree[it] == 0) {
                q.push(it);
            }
        }
    }

    return ansTopo;
}

// ---------------- Driver Code ----------------
int main() {
    int V = 6;
    vector<int> adj[V];

    // Adding directed edges to form a DAG
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topo = topoSortKahnAlgo(V, adj);

    cout << "Topological Sort using Kahn's Algorithm: ";
    for (int node : topo) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
