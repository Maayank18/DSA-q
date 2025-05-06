// Given a list of distinct integers arr[] and a target sum K, find all unique 
// combinations of elements from the array that add up to K.
// You can pick an element multiple times.

#include <iostream>
#include <vector>
using namespace std;

void findCombination(int ind, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
    // Base case: when we reach the end of the array
    if (ind == arr.size()) {
        if (target == 0) {
            ans.push_back(ds); // Store the valid combination
        }
        return;
    }

    // Pick the current element (allowed multiple times)
    if (arr[ind] <= target) {
        ds.push_back(arr[ind]); // Choose the element
        findCombination(ind, target - arr[ind], arr, ans, ds); // Stay on same index
        ds.pop_back(); // Backtrack
    }

    // Don't pick the element
    findCombination(ind + 1, target, arr, ans, ds);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ans, ds);
    return ans;
}

// Optional: Main function for testing
int main() {
    vector<int> arr = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(arr, target);

    cout << "Combinations summing to " << target << ":\n";
    for (auto combo : result) {
        for (int num : combo)
            cout << num << " ";
        cout << endl;
    }

    return 0;
}
