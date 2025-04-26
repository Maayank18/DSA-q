// Problem Statement:
// Given an undirected graph with 'n' vertices and 'm' edges, find all the articulation points.
// An articulation point is a vertex that, if removed along with its edges, increases the number of connected components.
// If there are no articulation points, return -1.

// Time Complexity (TC): O(N + 2M)
// where N = number of vertices, M = number of edges
// (Each node and edge is visited once in DFS)

// Space Complexity (SC): O(4N)
// Visited array, insertion time array, lowest time array, and mark array all take O(N) space.

#include <bits/stdc++.h>
using namespace std;

int timer = 1; // Global timer to keep track of discovery times

// Depth First Search to find articulation points
void dfs(int node, int parent, vector<int> &visited, int insertionTime[], int lowestNeighbourTime[],
         vector<int> &markArticulationPoint, vector<int> adj[]) {
    
    visited[node] = 1; // Mark current node as visited
    insertionTime[node] = lowestNeighbourTime[node] = timer++; // Set discovery and low time
    int child = 0; // Count of children in DFS tree

    for (auto it : adj[node]) {
        if (it == parent) {
            continue; // Skip the edge to parent
        }

        if (!visited[it]) {
            // If the adjacent node is not visited
            dfs(it, node, visited, insertionTime, lowestNeighbourTime, markArticulationPoint, adj);
            // After visiting, update the low time of current node
            lowestNeighbourTime[node] = min(lowestNeighbourTime[node], lowestNeighbourTime[it]);

            // Check for articulation point (except for root node)
            if (lowestNeighbourTime[it] >= insertionTime[node] && parent != -1) {
                markArticulationPoint[node] = 1;
            }

            child++; // Increase child count
        } else {
            // If adjacent node already visited and not parent
            lowestNeighbourTime[node] = min(lowestNeighbourTime[node], insertionTime[it]);
        }
    }

    // Special case for root node
    if (parent == -1 && child > 1) {
        markArticulationPoint[node] = 1;
    }
}

// Main function to return list of articulation points
vector<int> articulationPoints(int n, vector<int> adj[]) {
    vector<int> visited(n, 0); // To keep track of visited nodes
    int insertionTime[n]; // Discovery times of nodes
    int lowestNeighbourTime[n]; // Lowest discovery time reachable
    vector<int> markArticulationPoint(n, 0); // Mark if node is articulation point

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, -1, visited, insertionTime, lowestNeighbourTime, markArticulationPoint, adj);
        }
    }

    vector<int> ans; // To store final articulation points

    for (int i = 0; i < n; i++) {
        if (markArticulationPoint[i] == 1) {
            ans.push_back(i);
        }
    }

    // If no articulation point found, return {-1}
    if (ans.size() == 0) {
        return {-1};
    }
    return ans;
}

// Example usage:
int main() {
    int n = 5; // Number of nodes
    vector<int> adj[n];
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);
    
    vector<int> articulation = articulationPoints(n, adj);
    for (auto point : articulation) {
        cout << point << " ";
    }

    return 0;
}

