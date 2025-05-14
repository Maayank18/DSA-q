// our basic objective is found a susbet of given array such that if we 
// pick any two elemnsts from that subset thet are either wya divsible 
//  and the length of that subset should be maxest

// we can use Longest DIVISIBLE Subsequence

#include<iostream>
#include<vector>
using namespace std;

void f(int idx, int prevIdx, int n, vector<int>& arr, vector<int>& curr, vector<int>& best) {
    // base case
    if (idx == n) {
        if (curr.size() > best.size()) {
            best = curr;
        }
        return;
    }

    // take case
    if (prevIdx == -1 || arr[idx] % arr[prevIdx] == 0 || arr[prevIdx] % arr[idx] == 0) {
        curr.push_back(arr[idx]);
        f(idx + 1, idx, n, arr, curr, best);
        curr.pop_back(); // backtrack
    }

    // not take case
    f(idx + 1, prevIdx, n, arr, curr, best);
}

int main() {
    int n = 5;
    vector<int> arr = {1, 4, 7, 8, 16};

    vector<int> curr;
    vector<int> best;

    f(0, -1, n, arr, curr, best);

    cout << "Max Length of such subset is: " << best.size() << endl;
    cout << "Subset: ";
    for (int num : best) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}






// TRY MEMEOISATION AGAIN MAY BE NOT THE RIGHT APPROACH CODE IS DIFFICULT TO UNDERSTADN HEERER

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int idx, int prevIdx, vector<int>& nums, vector<vector<int>>& dp) {
    if (idx == nums.size()) return 0;

    if (dp[idx][prevIdx + 1] != -1) return dp[idx][prevIdx + 1];

    // Not take the current element
    int notTake = solve(idx + 1, prevIdx, nums, dp);

    // Take the current element if divisible
    int take = 0;
    if (prevIdx == -1 || nums[idx] % nums[prevIdx] == 0)
        take = 1 + solve(idx + 1, idx, nums, dp);

    return dp[idx][prevIdx + 1] = max(take, notTake);
}

void buildResult(int idx, int prevIdx, vector<int>& nums, vector<vector<int>>& dp, vector<int>& result) {
    if (idx == nums.size()) return;

    int notTake = solve(idx + 1, prevIdx, nums, dp);
    int take = 0;
    if (prevIdx == -1 || nums[idx] % nums[prevIdx] == 0)
        take = 1 + solve(idx + 1, idx, nums, dp);

    if (take >= notTake) {
        result.push_back(nums[idx]);
        buildResult(idx + 1, idx, nums, dp, result);
    } else {
        buildResult(idx + 1, prevIdx, nums, dp, result);
    }
}

int main() {
    vector<int> nums = {1, 4, 7, 8, 16};
    sort(nums.begin(), nums.end()); // Ensure ascending order for divisibility

    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));

    // Trigger memoization to fill dp table
    solve(0, -1, nums, dp);

    // Reconstruct the actual subset
    vector<int> result;
    buildResult(0, -1, nums, dp, result);

    cout << "Max Length: " << result.size() << endl;
    cout << "Subset: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}





//  SIMILARLY FOR THE TABULATION


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    vector<int> dp(n, 1);         // dp[i] = size of largest subset ending at index i
    vector<int> prev(n, -1);      // prev[i] = previous index in the subset
    int maxIndex = 0;             // index of the last element of the best subset

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > dp[maxIndex]) {
            maxIndex = i;
        }
    }

    // Reconstruct the subset
    vector<int> result;
    while (maxIndex != -1) {
        result.push_back(nums[maxIndex]);
        maxIndex = prev[maxIndex];
    }

    reverse(result.begin(), result.end());
    return result;
}

int main() {
    vector<int> arr = {1, 4, 7, 8, 16};
    vector<int> result = largestDivisibleSubset(arr);

    cout << "Max Length: " << result.size() << endl;
    cout << "Subset: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
