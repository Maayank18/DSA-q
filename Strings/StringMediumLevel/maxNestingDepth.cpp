// 🧩 Problem Statement (Simplified):
// Given a valid parentheses string (VPS), find how deep the parentheses go 
// — meaning, how many parentheses are nested inside one another at maximum.
// s = "(a(b(c)))"  ans = 3




// OPTIMAL APPRAOCH
// TIME COMPLEXITY -> O(N)
// SPACE COMPLEXITY -> O(1)
#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int maxNesting(string &s){
    int currentDepth = 0;
    int maxDepth = 0;

    for( char c : s){
        if(c == '('){
            currentDepth++;
            if( currentDepth > maxDepth){
                maxDepth = currentDepth;
            }
        }else if(c == ')'){
            currentDepth--;
        }
    }
    return maxDepth;
}

int main(){
    string s = "(a(b(c)))";
    int maxDepth = maxNesting(s);
    cout<<" the maxDepth of the nestinf paranthesis is : "<<maxDepth<<endl;
    return 0;
}






// BRUTE FORCE APPRAOCH 
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int bruteForceMaxDepth(string s) {
    stack<char> st;
    int maxDepth = 0;

    for (char c : s) {
        if (c == '(') {
            st.push(c);
            if (st.size() > maxDepth)
                maxDepth = st.size();
        } else if (c == ')') {
            if (!st.empty()) st.pop();
        }
    }

    return maxDepth;
}

int main() {
    string s = "(1+(2*3)+((8)/4))+1";
    cout << "Maximum nesting depth (brute force): " << bruteForceMaxDepth(s) << endl;
    return 0;
}

