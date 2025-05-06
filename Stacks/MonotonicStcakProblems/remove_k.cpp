// You are given an integer that is k
// and you are given a string of numbers 
// what you have to do is that rmove k characters from the given string of numbers 
// to make the given string the smallest 
// eg. s ="123456" and k=3
// answer = "123"

#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string remove_k(string s, int k) {
    stack<char> st;

    // Process each character in the string
    for (int i = 0; i < s.size(); i++) {
        // Remove characters from the stack if they are greater than the current character and `k > 0`
        while (!st.empty() && k > 0 && st.top() > s[i]) {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }

    // Remove remaining characters if `k > 0`
    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    // Build the result string from the stack
    string result = "";
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    // Reverse the result to correct the order
    reverse(result.begin(), result.end());

    // Remove leading zeros
    while (result.size() > 1 && result[0] == '0') {
        result.erase(result.begin());
    }

    // If the result is empty, return "0"
    return result.empty() ? "0" : result;
}

int main() {
    string s = "123456";
    int k = 3;

    string answer = remove_k(s, k);

    cout << "The minimum string is: " << answer << endl;

    return 0;
}

