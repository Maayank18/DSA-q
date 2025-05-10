 #include <iostream>
#include <vector>
#include<bits/stdc++.h>
#include <string>
using namespace std;

// Function to find and return the Longest Common Subsequence (LCS)
string longestCommonSubsequence(string X, string Y) {
    int m = X.length();
    int n = Y.length();

    // Create DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Fill DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Backtrack to find the LCS string
    string lcs;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs += X[i - 1];
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // The LCS is built backwards, so reverse it
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    string result = longestCommonSubsequence(str1, str2);
    cout << "Longest Common Subsequence: " << result << endl;

    return 0;
}
