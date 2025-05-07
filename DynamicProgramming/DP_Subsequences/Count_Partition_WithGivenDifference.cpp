// problem basically says that 
// find how many subsets are there which can be partitioned(exactlt 2) such that
// s1 >= s2
// s1 - s2 = Difference(gieven)

// What we can observe here is 
// s1 + s2 = totalsum
// s1 = totalSum - s2
// totalSum- s2 - s2 = Differecne
//  toalSum - difefrence /2 = s2
// hence our problem boils down to find subsets having target of toalSum - difefrence /2



// RECURSIVE SOLUTION


#include <iostream>
#include <vector>
using namespace std;

// int countSubsets(int index, int target, vector<int> &arr) {
//     // Base case: if we've considered all elements
//     if (index == 0) {
//         // Only one way to form sum = 0 => take nothing
//         if (target == 0 && arr[0] == 0) return 2; // both include/exclude 0
//         if (target == 0 || target == arr[0]) return 1;
//         return 0;
//     }

//     // Recursive calls: exclude or include current element
//     int notTake = countSubsets(index - 1, target, arr);
//     int take = 0;
//     if (arr[index] <= target)
//         take = countSubsets(index - 1, target - arr[index], arr);

//     return take + notTake;
// }

// int findingWays(vector<int> &arr, int target) {
//     return countSubsets(arr.size() - 1, target, arr);
// }

// int finding(int n, vector<int> &arr, int totalSum, int Targetdifference) {
//     if (totalSum - Targetdifference < 0) return 0;
//     if ((totalSum - Targetdifference) % 2 != 0) return 0;

//     return findingWays(arr, (totalSum - Targetdifference) / 2);
// }

// int main() {
//     int n = 4;
//     vector<int> arr = {5, 2, 6, 4};

//     int totalSum = 0;
//     for (int i = 0; i < n; i++) {
//         totalSum += arr[i];
//     }

//     int Targetdifference = 3;

//     int ans = finding(n, arr, totalSum, Targetdifference);
//     cout << "The partitions are: " << ans << endl;

//     return 0;
// }





// MEMOSIATION TECHNIQUE

// #include <iostream>
// #include <vector>
// using namespace std;

// int countSubsets(int index, int target, vector<int> &arr, vector<vector<int>> &dp) {
//     // Base case: if we've considered all elements
//     if (index == 0) {
//         // Only one way to form sum = 0 => take nothing
//         if (target == 0 && arr[0] == 0) return 2; // both include/exclude 0
//         if (target == 0 || target == arr[0]) return 1;
//         return 0;
//     }

//     if(dp[index][target] != -1){
//         return dp[index][target];
//     }

//     // Recursive calls: exclude or include current element
//     int notTake = countSubsets(index - 1, target, arr,dp);
//     int take = 0;
//     if (arr[index] <= target)
//         take = countSubsets(index - 1, target - arr[index], arr,dp);

//     return dp[index][target] = take + notTake;
// }

// int findingWays(vector<int> &arr, int target, vector<vector<int>> &dp) {
//     return countSubsets(arr.size() - 1, target, arr,dp);
// }

// int finding(int n, vector<int> &arr, int totalSum, int Targetdifference,
// vector<vector<int>> &dp) {
//     if (totalSum - Targetdifference < 0) return 0;
//     if ((totalSum - Targetdifference) % 2 != 0) return 0;

//     return findingWays(arr, (totalSum - Targetdifference) / 2,dp);
// }

// int main() {
//     int n = 4;
//     vector<int> arr = {5, 2, 6, 4};

//     int totalSum = 0;
//     for (int i = 0; i < n; i++) {
//         totalSum += arr[i];
//     }

//     vector<vector<int>> dp(n,vector<int>(totalSum+1,-1));


//     int Targetdifference = 3;

//     int ans = finding(n, arr, totalSum, Targetdifference,dp);
//     cout << "The partitions are: " << ans << endl;

//     return 0;
// }




// TABULATION METHOD


int findingWays(vector<int> &arr, int target) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    // Base cases
    if (arr[0] == 0) dp[0][0] = 2; // Include or exclude zero
    else dp[0][0] = 1; // Exclude element to get sum 0

    if (arr[0] != 0 && arr[0] <= target)
        dp[0][arr[0]] = 1;

    // Fill the DP table
    for (int i = 1; i < n; i++) {
        for (int sum = 0; sum <= target; sum++) {
            int notTake = dp[i - 1][sum];
            int take = 0;
            if (arr[i] <= sum)
                take = dp[i - 1][sum - arr[i]];
            dp[i][sum] = take + notTake;
        }
    }

    return dp[n - 1][target];
}

int finding(int n, vector<int> &arr, int totalSum, int Targetdifference) {
    if (totalSum - Targetdifference < 0) return 0;
    if ((totalSum - Targetdifference) % 2 != 0) return 0;

    return findingWays(arr, (totalSum - Targetdifference) / 2);
}

int main() {
    int n = 4;
    vector<int> arr = {1, 1, 2, 3}; // Change this to a valid test case
    int Targetdifference = 1;

    int totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    int ans = finding(n, arr, totalSum, Targetdifference);
    cout << "The number of valid partitions: " << ans << endl;

    return 0;
}