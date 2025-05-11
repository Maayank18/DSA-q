// this question basically aims to find the minimum number of insertion + deletion +REPLACEMENT 
// required to convert one string to another 
// is it always possible ? YES
// eg. s1 = "horse"  s2 = "ros"
// step 1 -> convert h to r = 1
//  step 2 -> delete r =  2
//  step 3 -> delete e = 3
//  hence minimum number of steps are 3



// WAY 1 RECURSION
// TC -> EXPONENTIAL 3^N X 3^M
//  SC -> O(N+M)
// #include<iostream>
// #include<vector>
// #include<string>
// #include<bits/stdc++.h>
// using namespace std;

// int f(string s1, int n, string s2, int m){

//     // base case 
//     // what if my s1 gets exhausted and reaches -1
//     // as because our s1 got exhausted we couldnt do anything 
//     if(n<0) return m+1;

//     // base case 2 if s2 gets exhausted 
//     if(m<0) return n+1;


//     int insert = 0;
//     int Delete = 0;
//     int replace = 0;
//     // case where both are characetr will match 
//     // if character matches we dont need to do any sort of operation 
//     if(s1[n] ==  s2[m]){
//         return 0 + f(s1,n-1,s2,m-1);
//     }else{
//         //  case where out character doent match 
//         // and we want insertion 
//         insert = 1 + f(s1,n,s2,m-1);

//         // case if i want deletion
//         Delete = 1 + f(s1,n-1,s2,m);

//         // if i want to replace the existing word there
//         replace = 1 + f(s1,n-1,s2,m-1);
//     }

//     return min(insert,min(Delete,replace));
// }

// int main(){
//     string s1 = "horse";
//     int n = s1.size();
//     string s2 = "ros";
//     int m = s2.size();
//     int minimumEDITS = f(s1,n-1,s2,m-1);
//     cout<<" the minimum operation required are :"<<minimumEDITS<<endl;
//     return 0;
// }





// WAY 2 CAN BE MEMOISATION
// TC ->  O(nxm)
//  SC-> o(nxm) + o(n+m)

#include<iostream>
#include<vector>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int f(string s1, int n, string s2, int m,vector<vector<int>> &dp){

    // base case 
    // what if my s1 gets exhausted and reaches -1
    // as because our s1 got exhausted we couldnt do anything 
    if(n<0) return m+1;

    // base case 2 if s2 gets exhausted 
    if(m<0) return n+1;

    // base case 3
    if(dp[n][m] != -1) return dp[n][m];
    int insert = 0;
    int Delete = 0;
    int replace = 0;
    // case where both are characetr will match 
    // if character matches we dont need to do any sort of operation 
    if(s1[n] ==  s2[m]){
        return dp[n][m] =  0 + f(s1,n-1,s2,m-1,dp);
    }else{
        //  case where out character doent match 
        // and we want insertion 
        insert = 1 + f(s1,n,s2,m-1,dp);

        // case if i want deletion
        Delete = 1 + f(s1,n-1,s2,m,dp);

        // if i want to replace the existing word there
        replace = 1 + f(s1,n-1,s2,m-1,dp);
    }

    return dp[n][m] =  min(insert,min(Delete,replace));
}

int main(){
    string s1 = "horse";
    int n = s1.size();
    string s2 = "ros";
    int m = s2.size();
    vector<vector<int>> dp(n,vector<int>(m,-1));
    int minimumEDITS = f(s1,n-1,s2,m-1,dp);
    cout<<" the minimum operation required are :"<<minimumEDITS<<endl;
    return 0;
}



// way 3 tabulation for removing recusrion stack space 

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int editDistanceTabulation(string s1, string s2) {
    int n = s1.size();
    int m = s2.size();

    // dp[i][j] = min operations to convert s1[0...i-1] to s2[0...j-1]
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Base cases
    for (int i = 0; i <= n; i++) {
        dp[i][0] = i;  // convert s1[0...i-1] to "" (delete all)
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = j;  // convert "" to s2[0...j-1] (insert all)
    }

    // Fill the table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                // characters match, no operation needed
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                int insertOp = 1 + dp[i][j - 1];
                int deleteOp = 1 + dp[i - 1][j];
                int replaceOp = 1 + dp[i - 1][j - 1];
                dp[i][j] = min({insertOp, deleteOp, replaceOp});
            }
        }
    }

    return dp[n][m];
}

int main() {
    string s1 = "horse";
    string s2 = "ros";

    int result = editDistanceTabulation(s1, s2);
    cout << "The minimum operations required are: " << result << endl;

    return 0;
}
