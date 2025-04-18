/*
Problem Statement:
------------------
You are given a weighted, undirected graph with 'n' nodes labeled from 0 to n-1.
Each edge is represented by a triplet [u, v, time] in the 'roads' vector,
which means there is a road between nodes u and v that takes 'time' units to travel.

Your task is to count the total number of different **shortest paths** from node 0 to node n-1.
Since the number of paths can be large, return it modulo 1e9 + 7.

Time Complexity:
----------------
O((n + m) * log n), where:
- n = number of nodes
- m = number of edges

Space Complexity:
-----------------
O(n + m), for:
- Adjacency list (O(m))
- Distance and ways arrays (O(n))
- Priority queue (O(n))

*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int countingPaths(int n, vector<vector<int>> &roads) {
    // Adjacency list: adj[u] contains pairs {v, weight}
    vector<pair<int,int>> adj[n];
    for(auto it : roads){
        adj[it[0]].push_back({it[1], it[2]}); // u -> v with weight
        adj[it[1]].push_back({it[0], it[2]}); // v -> u (undirected)
    }

    // Min-heap: stores {distance, node}
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

    vector<int> distance(n, 1e9); // Stores shortest distance from node 0
    vector<int> ways(n, 0);      // Stores number of shortest paths to each node

    distance[0] = 0; // Distance to self is 0
    ways[0] = 1;     // One way to reach node 0 (itself)
    pq.push({0, 0}); // Start from node 0

    int mod = 1e9 + 7;

    while(!pq.empty()){
        int dis = pq.top().first;  // Current distance from source
        int node = pq.top().second;// Current node
        pq.pop();

        for(auto it : adj[node]){
            int adjNode = it.first;     // Adjacent node
            int edgeWeight = it.second; // Weight of the edge to adjNode

            // Found a shorter path to adjNode
            if(dis + edgeWeight < distance[adjNode]){
                distance[adjNode] = dis + edgeWeight;        // Update distance
                pq.push({distance[adjNode], adjNode});       // Push to heap
                ways[adjNode] = ways[node];                  // Inherit the number of ways
            }
            // Found another shortest path to adjNode
            else if(dis + edgeWeight == distance[adjNode]){
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod; // Add ways modulo mod
            }
        }
    }

    return ways[n-1] % mod; // Return number of shortest paths to destination node
}


// ----------- Driver Code -----------

int main() {
    int n = 7; // number of nodes (0 to 6)
    vector<vector<int>> roads = {
        {0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3},
        {6, 3, 3}, {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 5, 2}
    };

    int result = countingPaths(n, roads);

    cout << "Number of different shortest paths from node 0 to node " << n-1 << " is: " << result << endl;

    return 0;
}
