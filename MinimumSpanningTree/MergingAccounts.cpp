/*
👨‍💻 Problem Statement: Merge accounts based on common emails.
You are given a list of accounts where each account[i] is a list of strings with:
- First element: the name of the person.
- Remaining elements: emails belonging to that person.

If two accounts have at least one email in common, they are the same person.
Merge such accounts and return a list where each element is:
- First: name
- Then: sorted list of unique emails

🕒 Time Complexity:
- O(N * α(N)) for DSU operations (where α is the inverse Ackermann function)
- O(NK log K) for sorting emails (N accounts, each with up to K emails)

💾 Space Complexity:
- O(NK) for storing email mappings and merged data
*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent;  // parent[i] is the representative of the set containing i
    vector<int> size;    // size[i] stores size of the tree rooted at i

public:
    // 🧱 Constructor to initialize DSU for n elements
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i; // Each node is initially its own parent
        }
    }

    // 🔍 Find with path compression
    int FindUltimateParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = FindUltimateParent(parent[node]); // Path compression
    }

    // 🔗 Union by size
    void unionBySize(int u, int v) {
        int ulp_u = FindUltimateParent(u);
        int ulp_v = FindUltimateParent(v);

        if (ulp_u == ulp_v) return; // Already in same set

        // Attach smaller set under the bigger one
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// 🌐 Main logic to merge email details
vector<vector<string>> mergeDetails(vector<vector<string>>& details) {
    int n = details.size();
    DisjointSet ds(n); // Create DSU for n accounts

    unordered_map<string, int> mapMailNode; // Maps email to a node (account index)

    // Step 1: Connect nodes that share at least one common email
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < details[i].size(); j++) { // Start from 1 as 0 is the name
            string mail = details[i][j];
            if (mapMailNode.find(mail) == mapMailNode.end()) {
                mapMailNode[mail] = i; // First occurrence of this mail
            } else {
                ds.unionBySize(i, mapMailNode[mail]); // Merge current node with existing
            }
        }
    }

    // Step 2: Group all emails by their ultimate parent
    vector<string> mergedMail[n];
    for (auto it : mapMailNode) {
        string mail = it.first;
        int node = ds.FindUltimateParent(it.second); // Find representative of the set
        mergedMail[node].push_back(mail);
    }

    // Step 3: Construct final merged accounts
    vector<vector<string>> ans;
    for (int i = 0; i < n; i++) {
        if (mergedMail[i].size() == 0) continue; // Skip empty groups

        sort(mergedMail[i].begin(), mergedMail[i].end()); // Sort mails

        vector<string> temp;
        temp.push_back(details[i][0]); // Add the name

        for (auto it : mergedMail[i]) {
            temp.push_back(it); // Add each email
        }

        ans.push_back(temp); // Add this merged account to result
    }

    return ans;
}

// 🧪 Driver code to test the function
int main() {
    vector<vector<string>> details = {
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"John", "johnnybravo@mail.com"},
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"Mary", "mary@mail.com"}
    };

    vector<vector<string>> res = mergeDetails(details);

    for (auto acc : res) {
        for (auto str : acc) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}
