#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Problem Statement:
-------------------
You are given 'n' courses labeled from 0 to n-1 and a list of prerequisites where each pair [a, b]
indicates that course 'a' depends on course 'b' (i.e., b → a).

Return any valid order to complete all courses.
If no such ordering exists (i.e., there's a cycle), return an empty vector.

Approach:
---------
Use **Kahn's Algorithm** (BFS) for topological sort.

Time Complexity: O(N + E), where N = number of courses, E = number of prerequisites.
Space Complexity: O(N + E)
*/

vector<int> findCourseOrder(int n, vector<pair<int, int>> &prerequisites) {
    vector<int> adj[n];

    // Step 1: Create adjacency list (b -> a, because a depends on b)
    for (auto it : prerequisites) {
        adj[it.second].push_back(it.first);
    }

    // Step 2: Compute in-degree of each course
    vector<int> inDegree(n, 0);
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

    // Step 4: BFS traversal (topological sort)
    vector<int> courseOrder;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        courseOrder.push_back(node);

        for (auto it : adj[node]) {
            inDegree[it]--;
            if (inDegree[it] == 0) {
                q.push(it);
            }
        }
    }

    // If we could process all courses, return the ordering
    if (courseOrder.size() == n) {
        return courseOrder;
    }

    // Cycle detected: return empty array
    return {};
}

// -------------------- Driver Code --------------------
int main() {
    int n = 4;
    vector<pair<int, int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    vector<int> order = findCourseOrder(n, prerequisites);

    if (order.empty()) {
        cout << "It is not possible to complete all courses (Cycle detected)." << endl;
    } else {
        cout << "Course completion order: ";
        for (int course : order) {
            cout << course << " ";
        }
        cout << endl;
    }

    return 0;
}
