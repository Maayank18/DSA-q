// we need to find the number of LIS present 
//  eg . {1,3,5,4,7}
//  here we have 2 LIS -> {1,3,5,7} and {1,3,4,7}
// so return the 2

#include<iostream>
#include<vector>
using namespace std;

int maxLen = 0;  // Declaring maxLen globally to store the maximum length of LIS

// Function to calculate LIS
int LIS(int idx, int prev, vector<int>& arr, int len) {
    // Base case: when we reach the end of the array
    if (idx == arr.size()) {
        if (len > maxLen) maxLen = len;  // Update maxLen if current length is greater
        return (len == maxLen) ? 1 : 0;  // If current length matches maxLen, return 1, else return 0
    }

    int take = 0;
    if (prev == -1 || arr[idx] > arr[prev]) {
        take = LIS(idx + 1, idx, arr, len + 1);  // Include arr[idx] in the LIS
    }

    int notTake = LIS(idx + 1, prev, arr, len);  // Skip arr[idx] and move forward

    return take + notTake;  // Return total number of LIS found so far
}

int main() {
    vector<int> arr = {1, 3, 5, 4, 7};
    int n = arr.size();
    
    // Start LIS calculation from index 0, with no previous element (-1) and length 0
    int totalCount = LIS(0, -1, arr, 0);

    // Output the result
    cout << "Maximum Length of LIS: " << maxLen << endl;
    cout << "Total number of LIS of maximum length: " << totalCount << endl;

    return 0;
}






// MEMOISATION WAY OF DOING IT 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxLen = 0;  // Declaring maxLen globally to store the maximum length of LIS
vector<vector<int>> dp;  // DP table to store the result of subproblems

// Function to calculate LIS with memoization
int LIS(int idx, int prev, vector<int>& arr, int len) {
    // Base case: when we reach the end of the array
    if (idx == arr.size()) {
        if (len > maxLen) maxLen = len;  // Update maxLen if current length is greater
        return (len == maxLen) ? 1 : 0;  // If current length matches maxLen, return 1, else return 0
    }

    // Check if the subproblem has already been solved
    if (dp[idx][prev + 1] != -1) {
        return dp[idx][prev + 1];  // Return the stored result if available
    }

    int take = 0;
    if (prev == -1 || arr[idx] > arr[prev]) {
        take = LIS(idx + 1, idx, arr, len + 1);  // Include arr[idx] in the LIS
    }

    int notTake = LIS(idx + 1, prev, arr, len);  // Skip arr[idx] and move forward

    dp[idx][prev + 1] = take + notTake;  // Store the result in the DP table
    return dp[idx][prev + 1];
}

int main() {
    vector<int> arr = {1, 3, 5, 4, 7};
    int n = arr.size();

    // Initialize the dp table with -1
    dp.resize(n + 1, vector<int>(n + 1, -1));

    // Start LIS calculation from index 0, with no previous element (-1) and length 0
    int totalCount = LIS(0, -1, arr, 0);

    // Output the result
    cout << "Maximum Length of LIS: " << maxLen << endl;
    cout << "Total number of LIS of maximum length: " << totalCount << endl;

    return 0;
}
