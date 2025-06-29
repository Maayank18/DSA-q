#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// GREEDY ALGORITHM

int f( vector<int> &greed, vector<int> &cookieSize){
    int n = greed.size();
    int m = cookieSize.size();
    int l = 0;
    int r = 0;
    sort(greed.begin(),greed.end());
    sort(cookieSize.begin(),cookieSize.end());
    while(l<n && r<m){
        
        if(greed[l] <= cookieSize[r]){
            l++;
        }

        r++;
    }

    return l;
}

int main(){
    vector<int> greed = {1,5,3,3,4};
    vector<int> cookieSize = {4,2,1,2,1,3};

    int satisfiedChildren = f(greed,cookieSize);
    cout<<" maximum satisfied are  :"<<satisfiedChildren<<endl;
    return 0;
}






// Solving This problem using RECURSION

// int f(int i, int j, vector<int>&greed, vector<int>&cookieSize){

//     // base case 1
//     if( i == greed.size() || j == cookieSize.size()){
//         return 0;
//     }

//     if(greed[i] <= cookieSize[j]){
//         return max(1 + f(i+1,j+1,greed,cookieSize),f(i,j+1,greed,cookieSize));
//     }else{
//         return f(i,j+1,greed,cookieSize);
//     }
// }

// int main(){
//     vector<int> greed = {1,5,3,3,4};
//     vector<int> cookieSize = {4,2,1,2,1,3};
//     sort(greed.begin(),greed.end());
//     sort(cookieSize.begin(),cookieSize.end());
//     int i = 0;
//     int j = 0;
//     int satisfiedChildren = f(i,j,greed,cookieSize);
//     cout<<" maximum satisfied are  :"<<satisfiedChildren<<endl;
//     return 0;
// }



//  SOLVING THROUGH MEMOISATION

// int f(int i, int j, vector<int>&greed, vector<int>&cookieSize, vector<vector<int>> &dp){

//     // base case 1
//     if( i == greed.size() || j == cookieSize.size()){
//         return 0;
//     }

//     // base case 2
//     if( dp[i][j] != -1){
//         return dp[i][j];
//     }

//     if(greed[i] <= cookieSize[j]){
//         return dp[i][j] = max(1 + f(i+1,j+1,greed,cookieSize,dp),f(i,j+1,greed,cookieSize,dp));
//     }else{
//         return dp[i][j] = f(i,j+1,greed,cookieSize,dp);
//     }
// }

// int main(){
//     vector<int> greed = {1,5,3,3,4};
//     vector<int> cookieSize = {4,2,1,2,1,3};
//     vector<vector<int>> dp(greed.size(),vector<int>(cookieSize.size(),-1));
//     sort(greed.begin(),greed.end());
//     sort(cookieSize.begin(),cookieSize.end());
//     int i = 0;
//     int j = 0;
//     int satisfiedChildren = f(i,j,greed,cookieSize,dp);
//     cout<<" maximum satisfied are  :"<<satisfiedChildren<<endl;
//     return 0;
// }




//  TABULATION METHOD 

int assignCookiesTabulation(vector<int> &greed, vector<int> &cookies) {
    int n = greed.size();
    int m = cookies.size();

    sort(greed.begin(), greed.end());
    sort(cookies.begin(), cookies.end());

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Build DP table from bottom-up
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (cookies[j] >= greed[i]) {
                dp[i][j] = max(1 + dp[i + 1][j + 1], dp[i][j + 1]);
            } else {
                dp[i][j] = dp[i][j + 1];
            }
        }
    }

    return dp[0][0];  // maximum satisfied children starting from 0th child and 0th cookie
}

int main() {
    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> cookies = {4, 2, 1, 2, 1, 3};

    int result = assignCookiesTabulation(greed, cookies);
    cout << "Maximum satisfied children: " << result << endl;
    return 0;
}