// in this we require to fint the no. of way in which the 
//  expression gives us a true 

#include <iostream>
#include <string>
using namespace std;

// Recursive function to count ways to evaluate the expression from index i to j
// such that it evaluates to isTrue (1 = True, 0 = False)
int f(int i, int j, int isTrue, string &s) {
    // Base case 1: invalid expression
    if (i > j) return 0;

    // Base case 2: only one symbol (either 'T' or 'F')
    if (i == j) {
        if (isTrue == 1)
            return s[i] == 'T'; // return 1 if it's 'T' and we want True
        else
            return s[i] == 'F'; // return 1 if it's 'F' and we want False
    }

    int ways = 0;

    // Loop through the expression to find operators at odd indices
    // Split the expression at every operator
    for (int index = i + 1; index < j; index += 2) {
        char op = s[index]; // Current operator (&, |, ^)

        // Recursively calculate ways for left and right parts
        int leftTrue = f(i, index - 1, 1, s);   // Left subexpression evaluates to True
        int leftFalse = f(i, index - 1, 0, s);  // Left subexpression evaluates to False
        int rightTrue = f(index + 1, j, 1, s);  // Right subexpression evaluates to True
        int rightFalse = f(index + 1, j, 0, s); // Right subexpression evaluates to False

        // Combine results based on operator and desired outcome
        if (op == '&') {
            if (isTrue)
                ways += leftTrue * rightTrue; // T & T = T
            else
                ways += (leftFalse * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightFalse); // all other combinations = F
        }
        else if (op == '|') {
            if (isTrue)
                ways += (leftTrue * rightTrue) + (leftTrue * rightFalse) + (leftFalse * rightTrue); // T|T, T|F, F|T = T
            else
                ways += leftFalse * rightFalse; // F|F = F
        }
        else if (op == '^') {
            if (isTrue)
                ways += (leftTrue * rightFalse) + (leftFalse * rightTrue); // T^F or F^T = T
            else
                ways += (leftTrue * rightTrue) + (leftFalse * rightFalse); // T^T or F^F = F
        }
    }

    return ways;
}

int main() {
    string s = "T|F&T"; // The boolean expression
    int n = s.size();
    int isTrue = 1; // We want to evaluate the expression to True

    int TotalWays = f(0, n - 1, isTrue, s); // Call the recursive function
    cout << "Total ways to evaluate to True: " << TotalWays << endl;

    return 0;
}







// MEMOISATION



#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int mod = 1000000007;

int f(int i, int j, int isTrue, string &exp, vector<vector<vector<ll>>> &dp) {
    // Base case 1: If i > j, it's an invalid expression, return 0.
    if (i > j) return 0;
    
    // Base case 2: If i and j are the same, evaluate the single character.
    if (i == j) {
        if (isTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    // If the result for this subproblem has been computed before, return it.
    if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];
    
    ll ways = 0;
    
    // Iterate through the expression.
    for (int ind = i + 1; ind <= j - 1; ind += 2) {
        ll lT = f(i, ind - 1, 1, exp, dp);  // Number of ways to make the left expression true.
        ll lF = f(i, ind - 1, 0, exp, dp);  // Number of ways to make the left expression false.
        ll rT = f(ind + 1, j, 1, exp, dp);  // Number of ways to make the right expression true.
        ll rF = f(ind + 1, j, 0, exp, dp);  // Number of ways to make the right expression false.

        // Check the operator at the current index and update ways accordingly.
        if (exp[ind] == '&') {
            if (isTrue) ways = (ways + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lF * rF) % mod) % mod;
        }
        else if (exp[ind] == '|') {
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod + (lT * rT) % mod) % mod;
            else ways = (ways + (lF * rF) % mod) % mod;
        }
        else {  // XOR operator
            if (isTrue) ways = (ways + (lF * rT) % mod + (lT * rF) % mod) % mod;
            else ways = (ways + (lF * rF) % mod + (lT * rT) % mod) % mod;
        }
    }
    
    // Store the result in the DP table and return it.
    return dp[i][j][isTrue] = ways;
}

int evaluateExp(string &exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));
    return f(0, n - 1, 1, exp, dp);  // Start evaluation with isTrue set to true.
}

int main() {
    string exp = "F|T^F";
    int ways = evaluateExp(exp);
    cout << "The total number of ways: " << ways << "\n";
    return 0;
}


