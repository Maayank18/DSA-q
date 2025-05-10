// the major difference between subsequence and substring is 
//  a subsequence means any forward sequence 
// eg "abcde" -> ab, acd, abde, bde all are subsequence not substring

// whereas substring means no gaps between them only a part of it 
// eg "abcde" -> abc, bcd, cde, abcd 

// best is to use a recusrion tree to understand
// WAY 1 IS RECURSION
// #include<iostream>
// #include<string>
// #include<bits/stdc++.h>
// using namespace std;

// int f(string s1, int n, string s2, int m, int count) {
//     // Base case: if any index goes out of bounds, return 0
//     if (n < 0 || m < 0) {
//         return count;
//     }
    
//     int currentCount = count;

//     // Case when the indexed characters match
//     if (s1[n] == s2[m]) {
//         currentCount = f(s1, n - 1, s2, m - 1, count + 1); // Increment count
//     }

//     // If current characters don't match, explore new paths and reset count to 0
//     int skipS1 = f(s1, n - 1, s2, m, 0);
//     int skipS2 = f(s1, n, s2, m - 1, 0);

//     return max({currentCount, skipS1, skipS2});
// }

// int main() {
//     string s1 = "abcjklp";
//     string s2 = "acjkp";
//     int n = s1.size() - 1; // length of s1 - 1 (for 0-based indexing)
//     int m = s2.size() - 1; // length of s2 - 1 (for 0-based indexing)
//     int count = 0;
//     int LengthOfSubstring = f(s1, n, s2, m, count);
//     cout << "The length of the Longest Common Substring is: " << LengthOfSubstring << endl;
//     return 0;
// }




// way 2 of doing it is memoisation

// #include<iostream>
// #include<string>
// #include<bits/stdc++.h>
// using namespace std;

// int f(string s1, int n, string s2, int m, int count, vector<vector<int>> &dp) {
//     // Base case: if any index goes out of bounds, return 0
//     if (n < 0 || m < 0) {
//         return count;
//     }
    
//     int currentCount = count;

//     // Case when the indexed characters match
//     if (s1[n] == s2[m]) {
//         currentCount = f(s1, n - 1, s2, m - 1, count + 1,dp); // Increment count
//     }

//     // If current characters don't match, explore new paths and reset count to 0
//     int skipS1 = f(s1, n - 1, s2, m, 0, dp);
//     int skipS2 = f(s1, n, s2, m - 1, 0,dp);

//     return max({currentCount, skipS1, skipS2});
// }

// int main() {
//     string s1 = "abcjklp";
//     string s2 = "acjkp";
//     int n = s1.size() - 1; // length of s1 - 1 (for 0-based indexing)
//     int m = s2.size() - 1; // length of s2 - 1 (for 0-based indexing)
//     int count = 0;
//     vector<vector<int>> dp(n,vector<int>(m,-1));
//     int LengthOfSubstring = f(s1, n, s2, m, count,dp);
//     cout << "The length of the Longest Common Substring is: " << LengthOfSubstring << endl;
//     return 0;
// }





// WAY 3 OF DOING IS TBAULATION

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int f(string s1, int n, string s2, int m, int count, vector<vector<int>>& dp) {
    // Initialize the DP table
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0;  // Base case: no common substring with an empty string
    }
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 0;  // Base case: no common substring with an empty string
    }

    int maxLength = 0; // To keep track of the maximum length of the common substring

    // Fill the DP table using bottom-up approach
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // If characters match, extend the current common substring
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // Increment the length of the common substring
                maxLength = max(maxLength, dp[i][j]); // Update the maximum length
            } else {
                dp[i][j] = 0; // No common substring ending at these characters
            }
        }
    }

    return maxLength; // Return the length of the longest common substring
}

int main() {
    string s1 = "abcjklp";
    string s2 = "acjkp";
    int n = s1.size(); // length of s1
    int m = s2.size(); // length of s2
    
    // Create the DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    
    int LengthOfSubstring = f(s1, n, s2, m, 0, dp);
    cout << "The length of the Longest Common Substring is: " << LengthOfSubstring << endl;
    
    return 0;
}





