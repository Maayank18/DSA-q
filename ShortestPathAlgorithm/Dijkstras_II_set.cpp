/*
Problem Statement:
-------------------
Given a weighted undirected graph with V vertices and edges in the form [weight, destination],
implement Dijkstra’s algorithm using a set to find the shortest distance from a source node
to all other nodes.

Input:
- v: Number of vertices
- adj: Adjacency list, where adj[u] contains vectors {weight, vertex}
- s: Source node

Output:
- A vector<int> where result[i] is the shortest distance from source 's' to node 'i'.

Time Complexity: O(E * log V) — due to set operations
Space Complexity: O(V + E)
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstras(int v, vector<vector<int>> adj[], int s) {
    set<pair<int, int>> st; // {distance, node}
    vector<int> distance(v, 1e9); // distance array initialized to "infinity"

    st.insert({0, s});
    distance[s] = 0;

    while (!st.empty()) {
        auto it = *(st.begin());  // smallest {distance, node}
        int node = it.second;
        int dist = it.first;
        st.erase(it); // remove the current node from set

        for (auto nbr : adj[node]) {
            int edgeWeight = nbr[0];
            int neighbouringNode = nbr[1];

            // Relaxation step
            if (dist + edgeWeight < distance[neighbouringNode]) {
                // If it was previously stored, erase the old {distance, node} pair
                if (distance[neighbouringNode] != 1e9) {
                    st.erase({distance[neighbouringNode], neighbouringNode});
                }
                // Update the distance
                distance[neighbouringNode] = dist + edgeWeight;
                // Insert updated value into the set
                st.insert({distance[neighbouringNode], neighbouringNode});
            }
        }
    }

    return distance;
}


int main() {
    int v = 5;
    vector<vector<int>> adj[5];

    // u --w--> v  => adj[u].push_back({w, v});
    adj[0].push_back({2, 1});
    adj[0].push_back({1, 4});
    adj[1].push_back({3, 2});
    adj[4].push_back({2, 2});
    adj[2].push_back({6, 3});
    adj[4].push_back({5, 3});

    int source = 0;
    vector<int> result = dijkstras(v, adj, source);

    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < v; i++) {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}

