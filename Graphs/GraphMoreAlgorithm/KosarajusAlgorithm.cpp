// Problem Statement:
// Given a directed graph with 'V' vertices, find the number of Strongly Connected Components (SCCs)
// using Kosaraju's Algorithm.
// A Strongly Connected Component (SCC) is a group of nodes where every node is reachable from every other node in the group.

// Steps of Kosaraju's Algorithm:
// 1. Sort all nodes according to their finishing time using DFS.
// 2. Reverse all the edges of the graph.
// 3. Perform DFS in the order of the sorted nodes (from stack) to count SCCs.

// Time Complexity (TC): O(V + E)
// Space Complexity (SC): O(V + E)

#include <bits/stdc++.h>
using namespace std;

// Step 1: Normal DFS to store nodes according to finishing time
void dfs(int node, vector<int> &visited, vector<int> adj[], stack<int> &st) {
    visited[node] = 1;

    for (auto it : adj[node]) {
        if (!visited[it]) {
            dfs(it, visited, adj, st);
        }
    }

    st.push(node); // Push the node into stack after visiting its adjacent nodes
}

// Step 3: DFS on reversed graph
void dfsStep3(int node, vector<int> &visited, vector<int> adjR[]) {
    visited[node] = 1;

    for (auto it : adjR[node]) {
        if (!visited[it]) {
            dfsStep3(it, visited, adjR);
        }
    }
}

// Main function to find number of Strongly Connected Components
int kosaraju(int V, vector<int> adj[]) {
    vector<int> visited(V, 0);
    stack<int> st;

    // Step 1: Fill stack with nodes based on finishing times
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, visited, adj, st);
        }
    }

    // Step 2: Reverse the graph
    vector<int> adjR[V]; // New adjacency list for reversed graph
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            adjR[it].push_back(i); // Reverse the edge
        }
    }

    // Step 3: Do DFS on reversed graph in the order of stack
    for (int i = 0; i < V; i++) {
        visited[i] = 0; // Reset visited array for 2nd DFS
    }

    int SCC = 0; // Count of strongly connected components
    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            SCC++;
            dfsStep3(node, visited, adjR);
        }
    }

    return SCC;
}

// Example usage:
int main() {
    int V = 5;
    vector<int> adj[V];
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(3);
    adj[3].push_back(4);

    cout << kosaraju(V, adj) << endl; // Output: 2
    return 0;
}

