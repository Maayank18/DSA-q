#include<iostream>
#include<cmath>
#include<climits>
using namespace std;

/*
    Problem Statement:
    ------------------
    A frog is trying to reach the end of a staircase with 'n' steps,
    where each step has a height given in an array `arr[]`.

    The frog can jump either 1 step or 2 steps forward.
    The energy required to jump from one step to another is the 
    absolute difference of the heights of the two steps.

    Your task is to calculate the minimum total energy the frog 
    needs to reach the last step.

    Approach:
    ---------
    - Use recursion by converting the problem into index-based computation.
    - From any index 'n', the frog could have come from:
        1. Step 'n-1' (1 step)
        2. Step 'n-2' (2 steps) [only if n > 1]
    - For each case, recursively compute the minimum energy required.
    - Return the minimum of both cases.
*/

// Function to return the minimum energy required to reach step 'n'
int minimumEnergy(int n, int arr[]) {

    // Base case: If at the 0th step, no energy is required to stay there
    if (n == 0) {
        return 0;
    }

    // Case 1: Jump from (n - 1) to n (1 step)
    int left = minimumEnergy(n - 1, arr) + abs(arr[n] - arr[n - 1]);

    // Case 2: Jump from (n - 2) to n (2 steps) [only if n > 1]
    int right = INT_MAX;
    if (n > 1) {
        right = minimumEnergy(n - 2, arr) + abs(arr[n] - arr[n - 2]);
    }

    // Return the minimum energy required from the two options
    return min(left, right);
}

int main() {
    int arr[] = {30, 10, 60, 10, 60, 50};  // Heights of each step
    int n = sizeof(arr) / sizeof(arr[0]); // Number of steps

    // Call the function with the last index (n - 1) as the destination step
    cout << "Minimum energy that is to be spent is: " << minimumEnergy(n - 1, arr) << endl;

    return 0;
}




// Approach - WAY TWO: Memoization (Top-Down Dynamic Programming)
//     --------------------------------------------------------------
//     - This is an optimized version of the recursive solution.
//     - As we can see, many subproblems are being repeated.
//     - Hence, we can store their results in a DP array (`dp[]`) and
//       avoid recomputing them again and again.
// */

// Function to return the minimum energy required to reach step 'n'
int minimumEnergy(int n, int arr[], vector<int> &dp) {

    // Base case: If at the 0th step, no energy is required to stay there
    if (n == 0) {
        return 0;
    }

    // If the answer for this step is already computed, return it
    if (dp[n] != -1) {
        return dp[n];
    }

    // Case 1: Jump from (n - 1) to n (1 step)
    int left = minimumEnergy(n - 1, arr, dp) + abs(arr[n] - arr[n - 1]);

    // Case 2: Jump from (n - 2) to n (2 steps) [only if n > 1]
    int right = INT_MAX;
    if (n > 1) {
        right = minimumEnergy(n - 2, arr, dp) + abs(arr[n] - arr[n - 2]);
    }

    // Store and return the minimum of both options
    return dp[n] = min(left, right);
}

int main() {
    int arr[] = {30, 10, 60, 10, 60, 50};  // Heights of each step
    int n = sizeof(arr) / sizeof(arr[0]); // Number of steps

    // Initialize dp array with -1 (uncomputed)
    vector<int> dp(n + 1, -1);

    // Start the computation from the last step
    cout << "Minimum energy that is to be spent is: " << minimumEnergy(n - 1, arr, dp) << endl;

    return 0;
}





// Approach - WAY THREE: Tabulation (Bottom-Up Dynamic Programming)
//     ----------------------------------------------------------------
//     - This is the opposite of memoization in terms of flow.
//     - Instead of recursion, we use a loop to build the answer from base cases.
//     - No function calls, and optimal for both time and space.
// */

// Function to compute minimum energy using tabulation (iterative approach)
int minimumEnergy(int n, int arr[]) {

    // Create a dp array of size n to store minimum energy required at each step
    vector<int> dp(n, 0);  // Base case: dp[0] = 0 (no energy to stand at 0)

    for (int i = 1; i < n; i++) {
        // Case 1: Coming from (i - 1)
        int oneStep = dp[i - 1] + abs(arr[i] - arr[i - 1]);

        // Case 2: Coming from (i - 2), only if i >= 2
        int twoStep = INT_MAX;
        if (i > 1) {
            twoStep = dp[i - 2] + abs(arr[i] - arr[i - 2]);
        }

        // Store the minimum of both paths
        dp[i] = min(oneStep, twoStep);
    }

    // Minimum energy required to reach the last step
    return dp[n - 1];
}







// a fourth way 


#include <bits/stdc++.h>

using namespace std;


int main() {

  vector<int> height{30,10,60,10,60,50};
  int n=height.size();
  int prev=0;
  int prev2=0;
  for(int i=1;i<n;i++){
      
      int jumpTwo = INT_MAX;
      int jumpOne= prev + abs(height[i]-height[i-1]);
      if(i>1)
        jumpTwo = prev2 + abs(height[i]-height[i-2]);
    
      int cur_i=min(jumpOne, jumpTwo);
      prev2=prev;
      prev=cur_i;
        
  }
  cout<<prev;
}

