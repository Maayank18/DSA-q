#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

/*
Problem Statement:
You are given `n` cities (numbered from 0 to n-1), and a list of flights where each flight is 
represented as [from, to, cost]. You are also given a source city, a destination city, and 
an integer `k` representing the maximum number of stops (intermediate cities) allowed.

Your task is to return the **minimum cost** to travel from the source to the destination city
with at most `k` stops. If it's not possible, return -1.

Time Complexity: O(k * E) → E is the number of flights
Space Complexity: O(N + E) → For the adjacency list and distance array
*/

int cheapestFlight(int n, vector<vector<int>> &flight, int source, int destination, int k) {
    // Adjacency list: {node -> (adjacent node, cost)}
    vector<pair<int, int>> adj[n];
    for (auto it : flight) {
        adj[it[0]].push_back({it[1], it[2]});
    }

    // Queue stores: {stops, {node, cost_so_far}}
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {source, 0}}); // Starting with source node, 0 stops, and 0 cost

    // Distance array initialized with infinity
    vector<int> distance(n, 1e9);
    distance[source] = 0;

    while (!q.empty()) {
        auto it = q.front();
        q.pop();

        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;

        // If stops exceed the allowed limit, skip
        if (stops > k) continue;

        // Traverse all neighbors
        for (auto adjNode : adj[node]) {
            int nextNode = adjNode.first;
            int edgeCost = adjNode.second;

            // If going through this path is cheaper, update and push
            if (cost + edgeCost < distance[nextNode]) {
                distance[nextNode] = cost + edgeCost;
                q.push({stops + 1, {nextNode, cost + edgeCost}});
            }
        }
    }

    // If destination is still unreachable
    if (distance[destination] == 1e9) return -1;
    return distance[destination];
}

int main() {
    int n, e;
    cout << "Enter number of cities and number of flights: ";
    cin >> n >> e;

    vector<vector<int>> flights(e, vector<int>(3));
    cout << "Enter flights as [from to cost]:\n";
    for (int i = 0; i < e; ++i) {
        cin >> flights[i][0] >> flights[i][1] >> flights[i][2];
    }

    int source, destination, k;
    cout << "Enter source, destination, and maximum allowed stops (k): ";
    cin >> source >> destination >> k;

    int result = cheapestFlight(n, flights, source, destination, k);
    if (result == -1)
        cout << "No valid path within " << k << " stops.\n";
    else
        cout << "Cheapest cost within " << k << " stops: " << result << endl;

    return 0;
}

