// this question aims to ask us the return the number or integer upto 32 bits 
//  for given string of literal 
// rules:
// no white spaces 
// string should start with number otherwise 0
// positive negtative understand it

// OPTIMAL SOLUTION
// TIME COMPLEXITY -> O(N)
//  SPACE COMPLEXITY -> O(1)
#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int atoi(string &s){
    int n = s.length();
    int ans = 0;
    int sign = 1; // consider its a positive number

    // remove white space if any
    int i = 0;
    while(i < n && s[i] == ' ') i++;

    // operator must be present in starting or we wont consider it 
    if( s[i] == '-' || s[i] == '+'){
        sign = (s[i] == '-')? -1 : 1;
        i++;
    }

    // conversion of string to digit 
    while( i<n && isdigit(s[i])){
        ans = ans * 10 + (s[i] - '0');
        if( sign*ans >= INT_MAX) return INT_MAX;
        if( sign*ans <= INT_MIN) return INT_MIN;
        i++;
    }

    return sign*ans;
}

int main(){
    string s = "  -123abc45";
    int output = atoi(s);
    cout<<" the output of following atoi problem is : "<<output<<endl;
    return 0;
}






// BRUTE FORCE SOLUTION 
// directly using inbuilt function
#include <iostream>
#include <string>
using namespace std;

int bruteForceAtoi(string s) {
    string numStr = "";
    for (char c : s) {
        if (isdigit(c) || c == '-' || c == '+') {
            numStr += c;
        } else {
            break;
        }
    }

    // Convert using stoi (standard function)
    return stoi(numStr);
}

int main() {
    string s = "-123abc";
    int output = bruteForceAtoi(s);
    cout << "Output (brute force): " << output << endl;
    return 0;
}
