// fidn the minimum partition required so that every strig is a pallindrome
// use front partitioning 

// #include<iostream>
// #include<string>
// #include<bits/stdc++.h>
// using namespace std;

// bool isPallindrome(string s){
//     string temp = s;

//     reverse(s.begin(),s.end());

//     for(int i = 0; i<s.size(); i++){
//         if(s[i] != temp[i]){
//             return false;
//         }
//     }
//     return true;
// }

// int f(int i,int n, string str){

//     // base case 1
//     if(i == n) return 0;

//     int mini = 1e9; 
//     int numberofPartition = 0;
//     string temp = "";
//     for(int j = i; j<n; j++){
//         temp+=str[j];
//         if(isPallindrome(temp)){
//             numberofPartition = 1 + f(j+1,n,str);
//             mini = min(mini,numberofPartition);
//         }
//     }
//     return mini;

// }

// int main(){
//     string str = "bababcbadcede";
//     int n = str.size();
//     int minPartition = f(0,n,str);
//     cout<<" the minimum partition required are : "<<minPartition<<endl;
//     return 0;
// }





// way 2 of doing it is memeoisation 
// #include<iostream>
// #include<string>
// #include<bits/stdc++.h>
// using namespace std;

// bool isPallindrome(string s){
//     string temp = s;

//     reverse(s.begin(),s.end());

//     for(int i = 0; i<s.size(); i++){
//         if(s[i] != temp[i]){
//             return false;
//         }
//     }
//     return true;
// }

// int f(int i,int n, string str, vector<int> &dp){

//     // base case 1
//     if(i == n) return 0;

//     // bas ecase 2
//     if(dp[i] != -1) return dp[i];

//     int mini = 1e9; 
//     int numberofPartition = 0;
//     string temp = "";
//     for(int j = i; j<n; j++){
//         temp+=str[j];
//         if(isPallindrome(temp)){
//             numberofPartition = 1 + f(j+1,n,str,dp);
//             mini = min(mini,numberofPartition);
//         }
//     }
//     return dp[i] = mini;

// }

// int main(){
//     string str = "bababcbadcede";
//     int n = str.size();
//     vector<int> dp(n,-1);
//     int minPartition = f(0,n,str,dp);
//     cout<<" the minimum partition required are : "<<minPartition<<endl;
//     return 0;
// }





// WAY 3 OF DOING IS TABULATION 


#include <bits/stdc++.h>
using namespace std;

// Function to check if a substring is a palindrome.
bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

// Function to find the minimum number of partitions for palindrome partitioning.
int palindromePartitioning(string str) {
    int n = str.size();
    // Create a DP array to store the minimum number of partitions.
    vector<int> dp(n + 1, 0);
    dp[n] = 0; // Initialize the last element to 0.

    // Loop through the string in reverse order.
    for (int i = n - 1; i >= 0; i--) {
        int minCost = INT_MAX;
        // Consider all possible substrings starting from the current index.
        for (int j = i; j < n; j++) {
            if (isPalindrome(i, j, str)) {
                // If the substring is a palindrome, calculate the cost and minimize it.
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    // Subtract 1 as it counts partitions, not cuts.
    return dp[0] - 1;
}

int main() {
    string str = "BABABCBADCEDE";
    int partitions = palindromePartitioning(str);
    cout << "The minimum number of partitions: " << partitions << "\n";
    return 0;
}

