// THIS WILL NOT USE LongestCommonSubsequences

// this is new case of matchin things and counting ways 
// this problem aims to find the total number of subsequences in s1 of s2
//  eg. we have s1 = "babgbag" s2 = "bag"
// find the number of ways the s2 occurs in the s1 this is what are task is 


// WAY 1 OF DOING IS RECUSION 
//  TC- > O(2^N x 2^m)
// Sc -> o(N+M) STACK SPACE FOR RECUSRION
// #include<iostream>
// #include<string>
// #include<bits/stdc++.h>
// using namespace std;

// int f( string s1, int n, string s2, int m){

//     // base case what if our s2 reached negative that would mean 
//     // we have discovered all possible things and you giev 1
//     if(m<0) return 1;

//     // if s1 reached negative we didnt 
//     if(n<0) return 0;

//     // case where we can accept is one of the valid one
//     if(s1[n] == s2[m]){
//         return (f(s1,n-1,s2,m-1) + f(s1,n-1,s2,m));
//         // if match move both string one step back 
//         // what if we haev one more subsequence tehre so move only s1 back
//     }else{
//         // if not matching only move s1 back
//         return f(s1,n-1,s2,m);
//     }
// }

// int main(){
//     string s1 = "babgbag";
//     int n = s1.size();
//     string s2 = "bag";
//     int m = s2.size();

//     // our task is to find the disticnt number of way s2 can occurin s1
//     int distinctWays = f(s1,n-1,s2,m-1);
//     cout<<"disticnt ways are : "<<distinctWays<<endl;
//     return 0;
// }




// WAY 2 of doing is memeoisation 
// TC -> o(nxm)
// SC -> O(nxm) + O(n+m)
// #include<iostream>
// #include<string>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int f( string s1, int n, string s2, int m,vector<vector<int>>&dp){

//     // base case what if our s2 reached negative that would mean 
//     // we have discovered all possible things and you giev 1
//     if(m<0) return 1;

//     // if s1 reached negative we didnt 
//     if(n<0) return 0;

//     // third base case 
//     if(dp[n][m] != -1) return dp[n][m];

//     // case where we can accept is one of the valid one
//     if(s1[n] == s2[m]){
//         return dp[n][m] = (f(s1,n-1,s2,m-1,dp) + f(s1,n-1,s2,m,dp));
//         // if match move both string one step back 
//         // what if we haev one more subsequence tehre so move only s1 back
//     }else{
//         // if not matching only move s1 back
//         return dp[n][m] =  f(s1,n-1,s2,m,dp);
//     }
// }

// int main(){
//     string s1 = "babgbag";
//     int n = s1.size();
//     string s2 = "bag";
//     int m = s2.size();
//     vector<vector<int>> dp(n,vector<int>(m,-1));
//     // our task is to find the disticnt number of way s2 can occurin s1
//     int distinctWays = f(s1,n-1,s2,m-1,dp);
//     cout<<"disticnt ways are : "<<distinctWays<<endl;
//     return 0;
// }





// WAY 3 OF DOING WILL BE TABULATION 

#include<iostream>
#include<string>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int f( string s1, int n, string s2, int m,vector<vector<int>>&dp){

    // as we are dealing with negavtive indexes 0 -> -1, 1 -> 0 
    for(int i = 0; i<=n ; i++){
        dp[i][0] = 1;
    }
    for(int j = 1; j<=m; j++){
        dp[0][j] = 0; // as j = 0 was already writen 
    }

    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[n][m];
}

int main(){
    string s1 = "babgbag";
    int n = s1.size();
    string s2 = "bag";
    int m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    // our task is to find the disticnt number of way s2 can occurin s1
    int distinctWays = f(s1,n,s2,m,dp);
    cout<<"disticnt ways are : "<<distinctWays<<endl;
    return 0;
}