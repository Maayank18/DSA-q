#include <iostream>
#include <vector>
#include <stack>
using namespace std;

/*
Problem Statement:
-------------------
Given a Directed Acyclic Graph (DAG) with V vertices, perform Topological Sort using DFS.
Topological sorting of a DAG is a linear ordering of its vertices such that for every directed edge u → v,
vertex u comes before v in the ordering.

This is only possible if the graph has no cycles (i.e., is a DAG).

Approach:
- Perform DFS traversal from every unvisited node.
- After visiting all adjacent nodes of a vertex, push it onto a stack.
- Once DFS is done, pop all elements from the stack to get the topological sort.

Time Complexity:
----------------
O(V + E), where V is the number of vertices and E is the number of edges.
Every vertex and edge is visited once.

Space Complexity:
-----------------
O(V) for visited array and stack used in the algorithm.
*/

void dfs(int node, vector<int> adj[], int visited[], stack<int>& st) {
    visited[node] = 1;

    // Visit all unvisited neighbors
    for (auto it : adj[node]) {
        if (!visited[it]) {
            dfs(it, adj, visited, st);
        }
    }

    // Push current node to stack after visiting all its neighbors
    st.push(node);
}

vector<int> topoSort(int V, vector<int> adj[]) {
    int visited[V] = {0};
    stack<int> st;
    vector<int> result;

    // Call DFS for all unvisited nodes
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, st);
        }
    }

    // Extract elements from the stack to get topological ordering
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}

// ---------------- Driver Code ----------------
int main() {
    int V = 6; // Number of vertices
    vector<int> adj[V];

    // Adding directed edges to form a DAG
    adj[5].push_back(0);
    adj[5].push_back(2);
    adj[4].push_back(0);
    adj[4].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(1);

    vector<int> topo = topoSort(V, adj);

    cout << "Topological Sort of the given DAG: ";
    for (int node : topo) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
