// question aims to find the length of longest chain of vector string 
// eg {"a","b","ba","bca","bda","bdca"}
// here a -> ba -> bca/bda -> bdca = length = 4
// every current index string must differ from previous one by 1 character



#include <bits/stdc++.h>
using namespace std;

// Check if prev word is a valid predecessor of curr word
bool compare(string &curr, string &prev) {
    if (curr.size() != prev.size() + 1) return false;

    int i = 0, j = 0;
    // Traverse through both strings to see if prev is a predecessor of curr
    while (i < curr.size()) {
        if (j < prev.size() && curr[i] == prev[j]) {
            i++; j++;
        } else {
            i++; // Skip a character in curr
        }
    }

    // prev should be fully matched (j should be equal to prev.size())
    return j == prev.size();
}

// Recursive function similar to your format
int f(int idx, int prevIdx, int n, vector<string> &arr) {
    // base case: if the array is exhausted
    if (idx == n) return 0;

    int length = 0;

    // Take case: if it's the first word or valid predecessor
    if (prevIdx == -1 || compare(arr[idx], arr[prevIdx])) {
        int take = 1 + f(idx + 1, idx, n, arr); // include arr[idx] in the chain
        length = max(length, take);
    }

    // Not take case: skip arr[idx]
    int notTake = f(idx + 1, prevIdx, n, arr); // exclude arr[idx]
    length = max(length, notTake);

    return length;
}

int longestStrChain(vector<string> &arr) {
    // Sort the array by length of strings
    sort(arr.begin(), arr.end(), [](string &a, string &b) {
        return a.size() < b.size();
    });

    int n = arr.size();
    return f(0, -1, n, arr); // Start recursion
}

int main() {
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << "The length of the longest string chain is: " << longestStrChain(words) << endl;
    return 0;
}






// MEMOISATION

#include <bits/stdc++.h>
using namespace std;

// Check if prev word is a valid predecessor of curr word
bool compare(string &curr, string &prev) {
    if (curr.size() != prev.size() + 1) return false;

    int i = 0, j = 0;
    // Traverse through both strings to see if prev is a predecessor of curr
    while (i < curr.size()) {
        if (j < prev.size() && curr[i] == prev[j]) {
            i++; j++;
        } else {
            i++; // Skip a character in curr
        }
    }

    // prev should be fully matched (j should be equal to prev.size())
    return j == prev.size();
}

// Memoization helper function
int f(int idx, int prevIdx, int n, vector<string> &arr, vector<vector<int>>& dp) {
    // base case: if the array is exhausted
    if (idx == n) return 0;

    // Check if the result is already computed
    if (dp[idx][prevIdx + 1] != -1) {
        return dp[idx][prevIdx + 1];
    }

    int length = 0;

    // Take case: if it's the first word or valid predecessor
    if (prevIdx == -1 || compare(arr[idx], arr[prevIdx])) {
        int take = 1 + f(idx + 1, idx, n, arr, dp); // include arr[idx] in the chain
        length = max(length, take);
    }

    // Not take case: skip arr[idx]
    int notTake = f(idx + 1, prevIdx, n, arr, dp); // exclude arr[idx]
    length = max(length, notTake);

    // Store result in dp table
    dp[idx][prevIdx + 1] = length;
    return length;
}

int longestStrChain(vector<string> &arr) {
    // Sort the array by length of strings
    sort(arr.begin(), arr.end(), [](string &a, string &b) {
        return a.size() < b.size();
    });

    int n = arr.size();

    // Create memoization table
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    return f(0, -1, n, arr, dp); // Start recursion
}

int main() {
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    cout << "The length of the longest string chain is: " << longestStrChain(words) << endl;
    return 0;
}

