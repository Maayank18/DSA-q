// While card matching is an interesting problem 
// here we have to return either tre or false whether our strings match or not
//  here we have 2 unique wildcards that are : 
// "?" which means it can match any ONE CHARACTER 
// "*"  which means it could match anything from length zero to infinte
// eg. s1 = "abc?" and s2 = "abcd" ans = TRUE
// eg. s1 = "ab*cd" and s2 = "abdefcd" ans = TRUE
// also wild card could only exist in s1

// WAY 1 OF DOING IT RECURSION 
#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

bool f(string s1, int n, string s2, int m){

    // base case 1
    // what if our string s1 gets exhaussted
    //  it is necessary to s1 and s2 to get exhaust together 
    if( n<0 && m<0) return true;
    if(n<0 && m>=0) return false;
    // base case 2
    //  if s2 is exhausted
    if(n>=0 && m<0){  // this would require a for loop 
        for(int i = 0; i<=n ; i++){
            if(s1[i] != '*') return false;
        }
        return true;
    }

    // cases where are string will match + ?
    if(s1[n] == s2[m] ||  s1[n] == '?'){
        return f(s1,n-1,s2,m-1);
    }

    // case of matching using *
    if(s1[n] == '*'){
        return f(s1,n-1,s2,m) || f(s1,n,s2,m-1);
    }

    // and wheneve rit will be a non matching case we will return false
    return false;


}

int main(){
    string s1 = "ab*cd";
    int n = s1.size();
    string s2 = "abdefcd";
    int m = s2.size();
    bool ismatched = f(s1,n-1,s2,m-1);
    cout<<" does the string matched : "<<ismatched<<endl;
    return 0;
}



// WAY 2 OF DOING IT MEMOISATION 
#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp){
    // base cases
    if(i < 0 && j < 0) return true;
    if(i < 0 && j >= 0) return false;
    if(i >= 0 && j < 0){
        for(int k = 0; k <= i; k++){
            if(s1[k] != '*') return false;
        }
        return true;
    }

    // memoization check
    if(dp[i][j] != -1) return dp[i][j];

    if(s1[i] == s2[j] || s1[i] == '?'){
        return dp[i][j] = f(i-1, j-1, s1, s2, dp);
    }

    if(s1[i] == '*'){
        return dp[i][j] = f(i-1, j, s1, s2, dp) || f(i, j-1, s1, s2, dp);
    }

    return dp[i][j] = false;
}

int main(){
    string s1 = "ab*cd";
    string s2 = "abdefcd";
    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    bool isMatched = f(n-1, m-1, s1, s2, dp);
    cout << "Does the string match: " << (isMatched ? "True" : "False") << endl;
    return 0;
}




// WAY 3 OF DOING IT 

#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool wildcardMatch(string s1, string s2){
    int n = s1.size();
    int m = s2.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

    // base case: empty string matches empty string
    dp[0][0] = true;

    // when s2 is empty
    for(int i = 1; i <= n; i++){
        if(s1[i-1] == '*')
            dp[i][0] = dp[i-1][0];
        else
            break;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1] || s1[i-1] == '?'){
                dp[i][j] = dp[i-1][j-1];
            }
            else if(s1[i-1] == '*'){
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
        }
    }

    return dp[n][m];
}

int main(){
    string s1 = "ab*cd";
    string s2 = "abdefcd";
    bool isMatched = wildcardMatch(s1, s2);
    cout << "Does the string match: " << (isMatched ? "True" : "False") << endl;
    return 0;
}
