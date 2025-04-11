#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem Statement:
-------------------
You are given 'n' courses labeled from 0 to n-1 and a list of prerequisites where each pair [a, b] 
indicates that course 'a' depends on course 'b' (i.e., to take course 'a', you must first complete 'b').

Determine whether it is possible to finish all courses (i.e., check for cycle in course dependency graph).

Approach:
---------
Use **Kahn's Algorithm** for Topological Sorting (BFS-based).
- If all nodes can be processed (i.e., added to the topological order), it means no cycle exists.
- Otherwise, a cycle exists, and it's not possible to finish all courses.

Time Complexity:
----------------
O(N + E), where N is the number of courses and E is the number of prerequisite pairs.

Space Complexity:
-----------------
O(N + E), for adjacency list, in-degree array, queue, and result vector.
*/

bool isCourseSchedulingPossible(int n, vector<pair<int, int>> &prerequisites) {
    vector<int> adj[n];

    // Step 1: Convert prerequisite pairs into adjacency list
    for (auto it : prerequisites) {
        adj[it.second].push_back(it.first); // b -> a (a depends on b)
    }

    // Step 2: Compute in-degree for all nodes
    int inDegree[n] = {0};
    for (int i = 0; i < n; i++) {
        for (auto it : adj[i]) {
            inDegree[it]++;
        }
    }

    // Step 3: Enqueue all nodes with in-degree 0
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 4: Process topological order using BFS
    vector<int> ansTopo;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        ansTopo.push_back(node);

        for (auto it : adj[node]) {
            inDegree[it]--;
            if (inDegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // If all courses are in topo sort, scheduling is possible
    return ansTopo.size() == n;
}

// ---------------------- Driver Code ----------------------
int main() {
    int n = 4; // Number of courses

    // Format: (course, prerequisite)
    vector<pair<int, int>> prerequisites = {
        {1, 0},
        {2, 1},
        {3, 2}
        // No cycle => Should return true
    };

    // To test a cyclic dependency, uncomment below:
    // prerequisites.push_back({1, 3}); // Adds cycle: 3 -> 2 -> 1 -> 3

    if (isCourseSchedulingPossible(n, prerequisites)) {
        cout << "Yes, all courses can be completed." << endl;
    } else {
        cout << "No, it is not possible to complete all courses due to a cycle." << endl;
    }

    return 0;
}
