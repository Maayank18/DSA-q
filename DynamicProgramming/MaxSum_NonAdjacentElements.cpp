#include<iostream>
#include<vector>
using namespace std;

// int solve1(int arr[], int idx, int n) { // Function to find max sum of non-adjacent elements from index idx to n

//     // Base Case 1: If we're at the last index, only one element to pick
//     if (n == 0) {
//         return arr[0];
//     }

//     // Base Case 2: If current index goes beyond the array size, return 0
//     if (idx > n) {
//         return 0;
//     }

//     // Case 1: Include the current element and jump to idx + 2
//     // because we cannot pick adjacent elements
//     int include = arr[idx] + solve1(arr, idx + 2, n);

//     // Case 2: Exclude the current element and move to the next one (idx + 1)
//     int exclude = solve1(arr, idx + 1, n);

//     // Return the maximum of the two choices
//     return max(include, exclude);
// }



// int solve(int arr[], int n) { // Function to find max sum of non-adjacent elements from index 0 to n

//     // Base Case 1: If there's only one element, return its value
//     if (n == 0) {
//         return arr[0];
//     }

//     // Base Case 2: If index is negative, return 0 (no elements to pick)
//     if (n < 0) {
//         return 0;
//     }

//     // Case 1: Include the current element (arr[n]) and move to index n-2
//     // because we can't pick adjacent elements
//     int include = arr[n] + solve(arr, n - 2);

//     // Case 2: Exclude the current element and move to index n-1
//     int exclude = solve(arr, n - 1);

//     // Return the maximum of the two choices: including or excluding current element
//     return max(include, exclude);
// }


// int main(){
//     int n = 5;
//     int idx = 0;
//     int arr[5] = {9,9,8,2,9};
//     int ans = solve(arr,n-1);
//     int ans2 = solve1(arr,idx,n-1);
//     cout<<"the max sum is right to left : "<<ans<<endl;
//     cout<<"the max sum is left to right : "<<ans2<<endl;
//     return 0;
// }





//MEMOISATION METHOD  top to bottm -> right to left

// int solve(int arr[], vector<int>& dp, int n) { 
//     // Function to return the maximum sum of non-adjacent elements from index 0 to n
//     // Uses memoization to avoid recomputation of overlapping subproblems

//     // Base Case 1: If only one element is left, return it
//     if (n == 0) {
//         return arr[0];
//     }

//     // Base Case 2: If index becomes negative, return 0 (no elements to pick)
//     if (n < 0) {
//         return 0;
//     }

//     // Memoization Check: If already computed, return stored result
//     if (dp[n] != -1) {
//         return dp[n];
//     }

//     // Option 1: Include current element and move to index n-2
//     int include = arr[n] + solve(arr, dp, n - 2);

//     // Option 2: Exclude current element and move to index n-1
//     int exclude = solve(arr, dp, n - 1);

//     // Store and return the maximum of the two options
//     return dp[n] = max(include, exclude);
// }

// int main(){
//     int n = 5;
//     int arr[n] = {9,9,8,2,9};
//     vector<int> dp(n+1,-1);
//     int ans = solve(arr,dp,n-1);
//     cout<<"the max sum using dp is : "<<ans<<endl;
//     return 0;
// }



// Tabulation Method -> bottom to top approach -> left to right
// WATCH AGAIN
int maximumNonAdjacentSum(vector<int> &arr) {
    int n = arr.size();

    // Step 1: Handle base case
    vector<int> dp(n);
    dp[0] = arr[0];  // Only one element to take

    for (int i = 1; i < n; i++) {
        int take = arr[i]; // Include current element

        if (i > 1) {
            take += dp[i - 2]; // Add non-adjacent (i-2) if possible
        }

        int notTake = dp[i - 1]; // Exclude current element

        // Step 2: Choose max of taking or not taking current element
        dp[i] = max(take, notTake);
    }

    // Step 3: Final answer is at dp[n - 1]
    return dp[n - 1];
}


int main(){
    int n = 5;
    vector<int> arr =  {9,9,8,2,9};
    vector<int> dp(n,-1);
    int ans = maximumNonAdjacentSum(arr);
    cout<<"the max sum using dp is : "<<ans<<endl;
    return 0;
}




// SPACE OPTIMISATION 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr = {3, 2, 5, 10, 7};
    
    if (arr.empty()) {
        cout << "Maximum sum of non-adjacent elements: 0" << endl;
        return 0;
    }
    
    if (arr.size() == 1) {
        cout << "Maximum sum of non-adjacent elements: " << arr[0] << endl;
        return 0;
    }
    
    int prev2 = 0;  // Max sum excluding the previous element
    int prev1 = arr[0];  // Max sum including the first element
    
    for (int i = 1; i < arr.size(); ++i) {
        int current = max(prev1, prev2 + arr[i]);
        prev2 = prev1;
        prev1 = current;
    }
    
    cout << "Maximum sum of non-adjacent elements: " << prev1 << endl;
    
    return 0;
}
