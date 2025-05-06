#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Recursive function to generate valid parentheses
void CheckingParanthesis(string curr, int openingP, int closingP, int n, vector<string> &ans) {
    // Base case: when both opening and closing parentheses are used up
    if (openingP == n && closingP == n) {
        ans.push_back(curr);
        return;
    }

    // Adding an opening parenthesis if possible
    if (openingP < n) {
        CheckingParanthesis(curr + '(', openingP + 1, closingP, n, ans);
    }

    // Adding a closing parenthesis only if there are unmatched opening ones
    if (closingP < openingP) {
        CheckingParanthesis(curr + ')', openingP, closingP + 1, n, ans);
    }
}

// Function to generate all valid parentheses
vector<string> AllParanthesis(int n) {
    vector<string> ans;
    CheckingParanthesis("", 0, 0, n, ans);
    return ans;
}

// Function to print all valid combinations
void printParanthesis(vector<string> &parens) {
    cout << "Valid Parentheses Combinations:\n";
    for (string &s : parens) {
        cout << s << endl;
    }
}

// Main function
int main() {
    int n = 3; // Number of pairs of parentheses
    vector<string> result = AllParanthesis(n);
    
    // Print all valid combinations
    printParanthesis(result);

    return 0;
}
