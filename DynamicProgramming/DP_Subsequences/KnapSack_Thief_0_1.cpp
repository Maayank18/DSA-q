// we are given a wt[] array conatianing certains weights of item 
//  we are having value[] correspodning to wt there is value
// there is a theif who has a bag with W which it could carry
// what maximum value could thief could get is what we have to find out 

// WHY ARENT WE USING GREEDY ALGO
// BECAUSE VALUE ARE NOT UNIFORM BECAUSE OF WHICH GREEDY APRROACH DONT WORK



// WAY 1 OF DOING is RECURSION
// TC -> 2^N
//  SC -> O(N) = REVURSION STACK SPACE 

// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int f(int n, vector<int> &wt, vector<int> &value, int W){

//     // base case
//     if( n == 0){
//         if(wt[0] <= W){
//             return value[0];
//         }else{
//             return 0;
//         }
//     }

//     int noTake = 0 + f(n-1,wt,value,W);
//     int take = INT_MIN;
//     if( wt[n] <= W){
//         take = value[n] + f(n-1,wt,value,W-wt[n]);
//     }
//     return max(take,noTake);
// }

// int main(){
//     int n = 3;
//     int W = 6; // thief bag
//     vector<int> wt = {3,2,5};
//     vector<int> value = {30,40,60};
//     int maxValue = f(n-1,wt,value,W);
//     cout<<" the max value be theif is : "<<maxValue<<endl;
//     return 0;
// }




// WAY 2 OF DOING IS MEMOISATION
// TC -> O(n x w)
// SC -> O( n x w) + O(n)

// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int f(int n, vector<int> &wt, vector<int> &value, int W, vector<vector<int>> &dp){

//     // base case
//     if( n == 0){
//         if(wt[0] <= W){
//             return value[0];
//         }else{
//             return 0;
//         }
//     }

//     // base case 2 for dp
//     if( dp[n][W] != -1){
//         return dp[n][W];
//     }

//     int noTake = 0 + f(n-1,wt,value,W,dp);
//     int take = -1e9;
//     if( wt[n] <= W){
//         take = value[n] + f(n-1,wt,value,W-wt[n],dp);
//     }
//     return dp[n][W] = max(take,noTake);
// }

// int main(){
//     int n = 3;
//     int W = 6; // thief bag
//     vector<int> wt = {3,2,5};
//     vector<int> value = {30,40,60};
//     vector<vector<int>> dp(n,vector<int>(W+1,-1));
//     int maxValue = f(n-1,wt,value,W,dp);
//     cout<<" the max value be theif is : "<<maxValue<<endl;
//     return 0;
// }




// WAY 3 OF DOING IS TABULATION 

#include <iostream>
#include <vector>
using namespace std;

int knapsackTabulation(int n, vector<int> &wt, vector<int> &value, int W) {
    // dp[i][w] = max value using items[0...i] with capacity w
    vector<vector<int>> dp(n, vector<int>(W + 1, 0));

    // Base case: fill the first row (0th item)
    for (int w = wt[0]; w <= W; w++) {
        dp[0][w] = value[0];  // if we can take the first item
    }

    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= W; w++) {
            int noTake = dp[i - 1][w];
            int take = -1e9;
            if (wt[i] <= w) {
                take = value[i] + dp[i - 1][w - wt[i]];
            }
            dp[i][w] = max(take, noTake);
        }
    }

    return dp[n - 1][W];
}

int main() {
    int n = 3;
    int W = 6;
    vector<int> wt = {3, 2, 5};
    vector<int> value = {30, 40, 60};

    int maxValue = knapsackTabulation(n, wt, value, W);
    cout << "The max value the thief can steal is: " << maxValue << endl;

    return 0;
}
