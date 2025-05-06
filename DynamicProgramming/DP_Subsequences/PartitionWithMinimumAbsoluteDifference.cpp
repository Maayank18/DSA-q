// only tbaulation will work here 
// last row of tbualtion will beof utmost importance to us

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int minSubsetDifference(vector<int>& arr, int n) {
    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    int k = totalSum;
    // Create a dp table where dp[i][j] is true if a subset with sum 'j' can be formed using first 'i' elements
    vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

    // Base case: We can always make sum 0 with 0 elements
    for (int i = 0; i < n; i++) dp[i][0] = true;

    // Base case: With only the first element
    if (arr[0] <= k) dp[0][arr[0]] = true;

    // Fill the DP table
    for (int i = 1; i < n; i++) {
        for (int target = 1; target <= k; target++) {
            bool notTake = dp[i - 1][target];
            bool take = false;
            if (arr[i] <= target) {
                take = dp[i - 1][target - arr[i]];
            }
            dp[i][target] = take || notTake;
        }
    }

    // Now find the minimum difference between two subset sums
    int mini = INT_MAX;
    for (int s1 = 0; s1 <= totalSum / 2; s1++) {
        if (dp[n - 1][s1] == true) {
            int s2 = totalSum - s1;
            mini = min(mini, abs(s1 - s2));
        }
    }

    return mini;
}

/*
    Time Complexity (TC): O(n * totalSum)
        - 'n' elements and 'totalSum' possible target values for each
    Space Complexity (SC): O(n * totalSum)
        - DP table of size n * totalSum

    Where:
    n = number of elements in the array
    totalSum = sum of all array elements
*/

int main() {
    vector<int> arr = {1, 2, 3, 9};
    int n = arr.size();
    cout << "Minimum Subset Sum Difference: " << minSubsetDifference(arr, n) << endl;
    return 0;
}
