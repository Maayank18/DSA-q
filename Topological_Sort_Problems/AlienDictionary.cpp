/*
Problem Statement:
-------------------
Given a sorted dictionary of an alien language having N words and k starting alphabets of standard dictionary. 
Find the order of characters in the alien language.

Input:
- N: Number of words in the dictionary
- K: Number of unique characters (from 'a' to any k-th alphabet)
- dict[]: Array of strings representing the dictionary sorted according to the alien language.

Output:
- A string denoting the characters in correct order of the alien language.

Constraints:
1 ≤ N ≤ 100
1 ≤ K ≤ 26
1 ≤ Length of words ≤ 100

Time Complexity: O(N + K + |E|) 
- N = number of words
- K = number of unique characters (nodes)
- E = number of edges (character relationships)

Space Complexity: O(K + |E|) 
- For adjacency list and in-degree array

Approach:
- Build a graph from the given dictionary (edges between characters).
- Perform Topological Sort using Kahn's Algorithm (BFS-based).
*/

#include <bits/stdc++.h>
using namespace std;

// Function to perform Topological Sort using Kahn's Algorithm
vector<int> topoSort(int V, vector<int> adj[]) {
    vector<int> inDegree(V, 0);     // Stores in-degree of each node
    vector<int> ans;                // Stores topologically sorted characters

    // Step 1: Calculate in-degrees
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            inDegree[it]++;
        }
    }

    // Step 2: Push all nodes with in-degree 0 into the queue
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: Process the queue
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ans.push_back(node); // Add current node to result

        // Decrease in-degree of adjacent nodes
        for (auto it : adj[node]) {
            inDegree[it]--;
            if (inDegree[it] == 0) {
                q.push(it); // If in-degree becomes 0, add to queue
            }
        }
    }

    return ans; // Return topological order
}

// Function to find order of characters in the alien dictionary
string findOrder(string dict[], int N, int K) {
    vector<int> adj[K]; // Adjacency list for K characters

    // Step 1: Create the graph by comparing adjacent words
    for (int i = 0; i < N - 1; i++) {
        string s1 = dict[i];
        string s2 = dict[i + 1];

        int len = min(s1.size(), s2.size());

        // Compare characters until the first mismatch
        for (int j = 0; j < len; j++) {
            if (s1[j] != s2[j]) {
                adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                break; // Only first mismatch matters
            }
        }
    }

    // Step 2: Perform Topological Sort on the graph
    vector<int> topo = topoSort(K, adj);

    // Step 3: Convert topological order to string
    string ans = "";
    for (auto it : topo) {
        ans += char(it + 'a'); // Convert index back to character
    }

    return ans;
}

// Driver Code for Testing
int main() {
    int N = 5, K = 4;
    string dict[] = {"baa", "abcd", "abca", "cab", "cad"};

    string order = findOrder(dict, N, K);
    cout << "Order of characters in alien language: " << order << endl;

    return 0;
}
