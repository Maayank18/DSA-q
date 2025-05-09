// RULES TO WRITE THE STRING SUBSEQUENCES
//  1. EXPRESS INDEX (INDEX 1, INDEX 2) as there are two strings simultaneoulsy
//  2. EXPLORE POSSIBILITY ON THAT INDEX
//  3.TAKE THE BEST AMONG THEM

//  for eg let us consider 
// s1 a string of size n
// s2 a string of size m
// f(n,m) -> find longest common substring in s[from 1 to n ] and s2[ from 0 to m]

// basically in case of integers and array we decide upon TAKE NOT TAKE
// but here in case of string we gonna have MATCH OR NO MATCH



// This is the way one of doing it the recussion approach 
// TC -> O(2^n) * O(2^m)
// SC -> recursion stack space O(n)
// #include<iostream>
// #include<string>
// using namespace std;

// int LCS(string s1, int n, string s2, int m ){
    
//     // base case where we exit
//     if( n<0 || m<0){
//         return 0;
//     }


//     // this is the case where the character matches
//     if(s1[n] == s2[m]){
//         return 1 + LCS(s1,n-1,s2,m-1);
//     }

//     // in case the character doesnt match
//     return max(LCS(s1,n-1,s2,m),LCS(s1,n,s2,m-1));
// }

// int main(){
//     string s1 = "acd";
//     string s2 = "ced";
//     int n = s1.size(); // size of s1
//     int m = s2.size(); // size of s2
//     int maxLengthSubsequence = LCS(s1,n-1,s2,m-1);
//     cout<<" the max length of common subsequnece is :"<<maxLengthSubsequence<<endl;
//     return 0;
// }




// Way 2 of doing it is Dynamaic Programming
//  TC -> O(n x m)
//  SC -> (N X M0 (for dp) + O(n + m) recursion stcak space
// #include<iostream>
// #include<string>
// #include<vector>
// using namespace std;

// int LCS(string s1, int n, string s2, int m, vector<vector<int>> &dp ){
    
//     // base case where we exit
//     if( n<0 || m<0){
//         return 0;
//     }


//     // this is the case where the character matches
    // if(s1[n] == s2[m]){
    //     return dp[n][m] =  1 + LCS(s1,n-1,s2,m-1,dp);
    // }

    // // base case for checking dp
    // if(dp[n][m] != -1){
    //     return dp[n][m];
    // }

    // // in case the character doesnt match
    // return dp[n][m] = max(LCS(s1,n-1,s2,m,dp),LCS(s1,n,s2,m-1,dp));
// }

// int main(){
//     string s1 = "acd";
//     string s2 = "ced";
//     int n = s1.size(); // size of s1
//     int m = s2.size(); // size of s2
//     vector<vector<int>> dp(n,vector<int>(m,-1));
//     int maxLengthSubsequence = LCS(s1,n-1,s2,m-1,dp);
//     cout<<" the max length of common subsequnece is :"<<maxLengthSubsequence<<endl;
//     return 0;
// }



// WAY THREE OF DOIN IS TABULATION
// TC -> 
// SC -> 

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int LCS(string s1, int n, string s2, int m, vector<vector<int>> &dp ){
    
    // COPY THE BASE CASE 
    // WRITE DOWN THE CHANGING PARAMETERS IN OPPOSITE FASHION
    // COPY THE RECUSION

    // base case ( we want shifting of index as -1 is incolved)
    // we are shifting one index to right 
    // n-1 = n
    //  1 = 0
    //  0 = -1
    if( n == 0 || m == 0){
        return 0;
    }
    for(int i = 0; i<=n; i++){
        dp[i][0] = 0;
    }
    for(int j = 0; j<=m; j++){
        dp[0][j] = 0;
    }



    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(s1[n] == s2[m]){
                return dp[n][m] =  1 + LCS(s1,n-1,s2,m-1,dp);
            }
            // in case the character doesnt match
             dp[n][m] = max(LCS(s1,n-1,s2,m,dp),LCS(s1,n,s2,m-1,dp));
        }
    }
    return dp[n][m];
}

int main(){
    string s1 = "acd";
    string s2 = "ced";
    int n = s1.size(); // size of s1
    int m = s2.size(); // size of s2
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    int maxLengthSubsequence = LCS(s1,n,s2,m,dp); // changed
    cout<<" the max length of common subsequnece is :"<<maxLengthSubsequence<<endl;
    return 0;
}