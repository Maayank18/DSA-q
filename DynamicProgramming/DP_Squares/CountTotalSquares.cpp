// NORMAL RECURSION SOLUTION 

#include <bits/stdc++.h>
using namespace std;

int solve(vector<vector<int>> &arr, int i, int j, int &maxi) {
    // Base case: If out of bounds
    if (i >= arr.size() || j >= arr[0].size())
        return 0;

    // Recursive calls
    int right = solve(arr, i, j + 1, maxi);
    int diagonal = solve(arr, i + 1, j + 1, maxi);
    int down = solve(arr, i + 1, j, maxi);

    int ans = 0;
    if (arr[i][j] == 1) {
        ans = 1 + min({right, diagonal, down});
        maxi = max(maxi, ans);  // update max square length
    }

    return ans;
}

int countMaxSquare(int n, int m, vector<vector<int>> &arr) {
    int maxi = 0;
    solve(arr, 0, 0, maxi);
    return maxi;
}

int main() {
    vector<vector<int>> arr = {
        {0, 1, 1, 1},
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    int n = 3, m = 4;
    int maxSquare = countMaxSquare(n, m, arr);
    cout << "The size of the largest square is: " << maxSquare << "\n";
    return 0;
}








// #include <bits/stdc++.h>
// using namespace std;

// int countSquares(int n, int m, vector<vector<int>> &arr) {
//     vector<vector<int>> dp(n, vector<int>(m, 0));

//     for (int j = 0; j < m; j++) dp[0][j] = arr[0][j];
//     for (int i = 0; i < n; i++) dp[i][0] = arr[i][0];

//     for (int i = 1; i < n; i++) {
//         for (int j = 1; j < m; j++) {
//             if (arr[i][j] == 0) dp[i][j] = 0;
//             else {
//                 dp[i][j] = 1 + min(dp[i - 1][j],
//                                    min(dp[i - 1][j - 1], dp[i][j - 1]));
//             }
//         }
//     }

//     int sum = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             sum += dp[i][j];
//         }
//     }
//     return sum;
// }

// int main() {

//     vector<vector<int>> arr = {
//         {0, 1, 1, 1}, {1, 1, 1, 1},
//         {0, 1, 1, 1}
//     };
//     int n = 3, m = 4;
//     int squares = countSquares(n, m, arr);
//     cout << "The number of squares: " << squares << "\n";
//     return 0;
// }