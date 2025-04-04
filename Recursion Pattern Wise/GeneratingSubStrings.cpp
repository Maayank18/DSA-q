#include <iostream>
#include <vector>
using namespace std;

void solve(string str, string output, int index, vector<string>& ans) {
    // Base case
    if (index >= str.length()) {
        ans.push_back(output);
        return;
    }

    // Exclude
    solve(str, output, index + 1, ans);

    // Include
    char element = str[index];
    output.push_back(element);
    solve(str, output, index + 1, ans);
}

// Function to generate all substrings
vector<string> generateAllSubstrings(string str) {
    vector<string> ans;
    string output = "";
    solve(str, output, 0, ans);
    return ans;
}

// Function to print all substrings
void printSubstrings(vector<string>& substrings) {
    cout << "All Substrings:\n";
    for (string &s : substrings) {
        cout << "\"" << s << "\"\n";
    }
}

// Main function
int main() {
    string input = "abc";
    
    // Generate all substrings
    vector<string> substrings = generateAllSubstrings(input);
    
    // Print substrings
    printSubstrings(substrings);

    return 0;
}
