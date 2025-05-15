// this problem basically tells us ki we are given a wood of length let say 7
//  we are given the cut sizes [1,3,5,7]
// what is the minimum cost of cutting in length 7
//  cut sizes = cost of cutting 

// 1. sort this up
//  2. add 0 at front and length of stcik at end of cut size array 
// 3. then we can easilly perform our fucntion



// WAY 1 OF DOING IS RECURSION
//  TC -> EXPONENTIAL 
//  SC -> O(N) recusrion stack space 
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> &cuts){ // j  is actually length of stick

    // base case 1
    if( i > j){
        return 0; // i can never past j
    }
    int mini = INT_MAX;
    for(int index = i; index<=j; index++ ){
        int cost = cuts[j+1] - cuts[i-1] + f(i,index-1,cuts) + f(index+1,j,cuts);
        mini = min(mini,cost);
    }
    return mini;
}

int main(){
    int n = 7; // length of the wood
    vector<int> cuts = {1,3,4,5}; // cut sizes
    cuts.push_back(n); // adding length of stick at end
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());

    int minimumCost = f(1,cuts.size()-2,cuts);

    cout<<" minimum cost of cutting is : "<<minimumCost<<endl;
    return 0;
}




// WAY 2 OF DOING IT IS MEMOISATION
// TC -> almost m^3
// SC -> O(m^2) + O(m)

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> &cuts, vector<vector<int>>&dp){ // j  is actually length of stick

    // base case 1
    if( i > j){
        return 0; // i can never past j
    }

    // base case 2
    if(dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;
    for(int index = i; index<=j; index++ ){
        int cost = cuts[j+1] - cuts[i-1] + f(i,index-1,cuts,dp) + f(index+1,j,cuts,dp);
        mini = min(mini,cost);
    }
    return dp[i][j] =  mini;
}

int main(){
    int n = 7; // length of the wood
    vector<int> cuts = {1,3,4,5}; // cut sizes
    cuts.push_back(n); // adding length of stick at end
    cuts.insert(cuts.begin(),0);
    sort(cuts.begin(),cuts.end());
    int m =  cuts.size();
    vector<vector<int>> dp(m+1,vector<int>(m+1,-1));
    int minimumCost = f(1,cuts.size()-2,cuts,dp);

    cout<<" minimum cost of cutting is : "<<minimumCost<<endl;
    return 0;
}





// WAY 3 OF DOING IT IS TABULATION 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minCostToCutStick(int n, vector<int> &cuts) {
    cuts.push_back(0);
    cuts.push_back(n);
    sort(cuts.begin(), cuts.end());

    int m = cuts.size();
    vector<vector<int>> dp(m, vector<int>(m, 0));

    // length is the size of the current segment of cuts being considered
    for(int length = 1; length <= m - 2; length++) {
        for(int i = 1; i + length - 1 <= m - 2; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;
            for(int k = i; k <= j; k++) {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][k - 1] + dp[k + 1][j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[1][m - 2];
}

int main() {
    int n = 7;
    vector<int> cuts = {1, 3, 4, 5};
    int result = minCostToCutStick(n, cuts);
    cout << "Minimum cost of cutting is: " << result << endl;
    return 0;
}
