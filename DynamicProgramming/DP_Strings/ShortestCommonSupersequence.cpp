// lets understand what does this question asked us to do 
//  eg. s1 = "brute"  s2 = "groot"
// a supersequnece is a string which contains both the strings in it 
// for eg "brutegroot" is a super sequnece
// but here we want SHORTEST COMMON SUPERSEQUENCE
//  that is it should be short + a supersequnece 
//  which is -> "bgruoote"

// INtution is the common part of LCS is taken once 
// s1 - LCS + s2 - LCS + LCS


// #include<iostream>
// #include<string>
// #include<bits/stdc++.h>
// using namespace std;

// int f( string s1, int n, string s2, int m){

//     // base case where index goes out of bound
//     if(n<0 || m<0) {return 0;}

//     // case where we can take the subsequence
//     if(s1[n] == s2[m]){
//         return 1+f(s1,n-1,s2,m-1);
//     }

//     // case where we cant take it and explorint different paths
//     return max(f(s1,n-1,s2,m),f(s1,n,s2,m-1));
// }

// int main(){
//     string s1 = "brute";
//     int n = s1.size();
//     string s2 = "broot";
//     int m = s2.size();
//     int LCS = f(s1,n-1,s2,m-1); // finding LCS for Shortest common supersequnece
//     cout<<"the shortest common subsequnece is : "<<n + m - LCS<<endl;
//     return 0;
// }


// MEMOISATION AND TABULATION SAME WOULD BE SAME AS USED IN LCS


// printing the shortest common supersubsequence
// for pritning it w would be needing the tabulation so writing it 
// or basecally filling the tabualtion table

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int f(string s1, int n, string s2, int m, vector<vector<int>>& dp) {
    // DP initialization for first row and first column
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int j = 0; j <= m; j++) dp[0][j] = 0;

    // Filling the DP table for LCS calculation
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[n][m];
}

string ShortestCommonSuperSequence(string s1, string s2, vector<vector<int>>& dp) {
    string ans = "";
    int n = s1.size();
    int m = s2.size();

    // Backtracking to find the SCS string
    while (n > 0 && m > 0) {
        if (s1[n - 1] == s2[m - 1]) {
            ans += s1[n - 1];  // or s2[m-1], since they are equal
            n--;
            m--;
        } else if (dp[n - 1][m] > dp[n][m - 1]) {
            ans += s1[n - 1];  // Add from s1 if LCS comes from here
            n--;
        } else {
            ans += s2[m - 1];  // Add from s2 if LCS comes from here
            m--;
        }
    }

    // Add remaining characters if any
    while (n > 0) {
        ans += s1[n - 1];
        n--;
    }

    while (m > 0) {
        ans += s2[m - 1];
        m--;
    }

    reverse(ans.begin(), ans.end());  // Reverse to get the correct order
    return ans;
}

int main() {
    string s1 = "brute";
    int n = s1.size();
    string s2 = "groot";
    int m = s2.size();

    // DP table for storing LCS results
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    // Finding LCS for the Shortest Common Supersequence
    int LCS = f(s1, n, s2, m, dp);

    // Calculating the length of the Shortest Common Supersequence
    cout << "The length of the shortest common supersequence is: " << n + m - LCS << endl;
    
    // Finding the actual Shortest Common Supersequence string
    string thestringis = ShortestCommonSuperSequence(s1, s2, dp);
    cout << "The shortest common supersequence is: " << thestringis << endl;

    return 0;
}
