// the string say return the largest odd number present in the string num

// BRUTE FORCE APPRAOCH 

string largestOddNumberBrute(string num) {
    string result = "";
    for (int i = 0; i < num.size(); ++i) {
        if ((num[i] - '0') % 2 == 1) {  // check odd ending
            string prefix = num.substr(0, i + 1);
            if (prefix.size() > result.size()) {
                result = prefix;
            }
        }
    }
    return result;
}


// OPTIMAL APPROACH
// TC -> O(N)
// SC -> O(N)
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

string check(string num) {
    for (int i = num.size() - 1; i >= 0; --i) {
        if ((num[i] - '0') % 2 == 1) { // check for odd digit
            return num.substr(0, i + 1);
        }
    }
    return "";
}


int main(){
    string num = "1224352";
    string largestOddNumber = check(num);
    cout<<" the largest odd num is : "<<largestOddNumber<<endl;
    return 0;
}