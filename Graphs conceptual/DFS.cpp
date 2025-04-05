#include <iostream>
#include <vector>
using namespace std;

// Recursive DFS function
void dfs(int startNode, int visited[], vector<int> adj[], vector<int>& ans) {
    visited[startNode] = 1;           // Mark the current node as visited
    ans.push_back(startNode);         // Add node to the result (DFS traversal path)

    // Visit all the adjacent nodes of the current node
    for (auto it : adj[startNode]) {
        if (!visited[it]) {           // If the neighbor hasn't been visited yet
            dfs(it, visited, adj, ans);  // Recur for that neighbor
        }
    }
}

// DFS traversal function
vector<int> dfsList(int n, vector<int> adj[]) {
    vector<int> ans;                  // To store the final DFS traversal result
    int visited[n] = {0};             // Visited array to keep track of visited nodes

    int startNode = 0;                // Start DFS from node 0
    dfs(startNode, visited, adj, ans);

    return ans;                       // Return the traversal result
}

// Driver code to test the function
int main() {
    int n = 5; // Number of nodes
    vector<int> adj[n]; // Adjacency list

    // Sample edges
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[1].push_back(0);
    adj[1].push_back(3);
    adj[2].push_back(0);
    adj[2].push_back(4);
    adj[3].push_back(1);
    adj[4].push_back(2);

    // Call DFS function
    vector<int> result = dfsList(n, adj);

    // Print the result
    cout << "DFS Traversal starting from node 0: ";
    for (int node : result) {
        cout << node << " ";
    }

    return 0;
}
