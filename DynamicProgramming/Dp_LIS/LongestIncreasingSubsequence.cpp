// what the question ask me is find the longest subsequence that is in increasing order
// eg = [10,9,3,5,2,6,7,8,1]
// we can have so many subsequences possible but the biggest is 3,5,6,7,8 of length 5
// and at end we want to retrun the length 



// // WAY 1 OF DOIN BY RECURSION
// // TC -> O(2^N)
// // SC -> O(N) = RECURSION STACK SPACE 
#include<iostream>
#include<vector>
using namespace std;

int f(int idx, int n, vector<int>&arr, int prevIdx){

    int length = 0;

    // BASE CASE IF OUR ARRAY GETS EXHAUSTED
    if(idx == n) return 0;


    // case where we can take that element 
    // we know that we can always take out element at 0 index at before it we have -1
    // also we have take any element if it is greater than its previous
    // TAKE CASE
    if(prevIdx == -1 || arr[idx] > arr[prevIdx]){
        int take = 1 + f(idx+1,n,arr,idx);
        length = max(length,take);
    }

    // not take case 
    // if i am not taking the element just skip the index
    int notTake = 0 + f(idx+1,n,arr,prevIdx);
    length = max(length,notTake);


    return length;
}

int main(){
    int n = 9;
    vector<int> arr = {10,9,3,5,2,6,7,8,1};
    int previousIndex = -1;
    int maxLength = f(0,n,arr,previousIndex);
    cout<<" the longest increasing subsequence is : "<<maxLength<<endl;
    return 0;
}





// // WAY 2 OF DOIN BY MEMOISATION
// // TC -> O(N)
// // SC -> O(N) = RECURSION STACK SPACE 
#include<iostream>
#include<vector>
using namespace std;

int f(int idx, int n, vector<int>&arr, int prevIdx, vector<vector<int>>&dp){

    int length = 0;

    // BASE CASE IF OUR ARRAY GETS EXHAUSTED
    if(idx == n) return 0;

    // base case 2
    if(dp[idx][prevIdx+1] != -1) return dp[idx][prevIdx];

    // case where we can take that element 
    // we know that we can always take out element at 0 index at before it we have -1
    // also we have take any element if it is greater than its previous
    // TAKE CASE
    if(prevIdx == -1 || arr[idx] > arr[prevIdx]){
        int take = 1 + f(idx+1,n,arr,idx,dp);
        length = max(length,take);
    }

    // not take case 
    // if i am not taking the element just skip the index
    int notTake = 0 + f(idx+1,n,arr,prevIdx,dp);
    length = max(length,notTake);


    return dp[idx][prevIdx+1] = length;
}

int main(){
    int n = 9;
    vector<int> arr = {10,9,3,5,2,6,7,8,1};
    int previousIndex = -1;
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    int maxLength = f(0,n,arr,previousIndex,dp);
    cout<<" the longest increasing subsequence is : "<<maxLength<<endl;
    return 0;
}




// WAY 3 OF DOIN BY tabulation
// TC -> O(N^2)
// SC -> O(N)x 2  
// as recursion started from 0 -> n
//  tabulation goes n-1 -> 0
#include <iostream>
#include <vector>
using namespace std;

int longestIncreasingSubsequence(vector<int>& arr) {
    int n = arr.size();
    
    // dp[i][prevIdx+1] represents the LIS starting from index i with prevIdx as the previous element index
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int idx = n-1; idx >= 0; idx--) {
        for(int prevIdx = idx-1; prevIdx >= -1; prevIdx--) {
            int notTake = dp[idx+1][prevIdx+1]; // Don't pick current element
            int take = 0;
            if(prevIdx == -1 || arr[idx] > arr[prevIdx]) {
                take = 1 + dp[idx+1][idx+1]; // Pick current element
            }
            dp[idx][prevIdx+1] = max(take, notTake);
        }
    }

    return dp[0][0]; // Starting from index 0 with no previous element
}

int main() {
    vector<int> arr = {10, 9, 3, 5, 2, 6, 7, 8, 1};
    int maxLength = longestIncreasingSubsequence(arr);
    cout << "The longest increasing subsequence is: " << maxLength << endl;
    return 0;
}












// way of printig the list 

#include <iostream>
#include <vector>
using namespace std;

void printLIS(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // Tabulation
    for (int idx = n - 1; idx >= 0; idx--) {
        for (int prevIdx = idx - 1; prevIdx >= -1; prevIdx--) {
            int notTake = dp[idx + 1][prevIdx + 1];
            int take = 0;
            if (prevIdx == -1 || arr[idx] > arr[prevIdx]) {
                take = 1 + dp[idx + 1][idx + 1];
            }
            dp[idx][prevIdx + 1] = max(take, notTake);
        }
    }

    // Reconstruct LIS from dp[0][0]
    vector<int> lis;
    int idx = 0, prevIdx = -1;
    while (idx < n) {
        int notTake = dp[idx + 1][prevIdx + 1];
        int take = 0;
        if (prevIdx == -1 || arr[idx] > arr[prevIdx]) {
            take = 1 + dp[idx + 1][idx + 1];
        }

        // Take the element if it leads to optimal answer
        if (take >= notTake) {
            lis.push_back(arr[idx]);
            prevIdx = idx;
        }
        idx++;
    }

    // Print the sequence
    cout << "Longest Increasing Subsequence: ";
    for (int x : lis) {
        cout << x << " ";
    }
    cout << endl;

    // Optionally, print the length
    cout << "Length of LIS: " << dp[0][0] << endl;
}

int main() {
    vector<int> arr = {10, 9, 3, 5, 2, 6, 7, 8, 1};
    printLIS(arr);
    return 0;
}
