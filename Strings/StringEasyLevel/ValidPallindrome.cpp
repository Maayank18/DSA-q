// What this problem ask us is to give the true or false after checking 
// whether the given string is pallindorme or not 
//  1. A = a will be accepted as same 
//  2. if it contain &,$ or any other specila character dont consider and remove them
//  3. only alpha numeric characetr will be used


// BRUTE FORCE APPRAOCH -> where we reverse and check if reversed and orginal is same 
//  using isalnum function
#include <iostream>
#include <string>
#include <algorithm>  // for reverse
using namespace std;

bool isPalindromeBrute(string s) {
    string cleaned = "";

    // Step 1: Clean the string
    for (char ch : s) {
        if (isalnum(ch)) {                // Keep only letters and digits
            cleaned += tolower(ch);       // Convert to lowercase
        }
    }

    // Create reversed copy
    string reversed = cleaned;
    reverse(reversed.begin(), reversed.end());

    //Compare cleaned string with reversed copy
    return cleaned == reversed;
}

int main() {
    string s = "Ac3?e3c&a";
    if (isPalindromeBrute(s)) {
        cout << "Yes, the string is palindromic." << endl;
    } else {
        cout << "No, the string is not palindromic." << endl;
    }
    return 0;
}





// BEST APPROCH force solution
//  tc -> O(n)
//  sc -> o(1)
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

bool isAlphanumeric( char ch){
    if( (tolower(ch) >= 'a' && tolower(ch) <= 'z') || (ch >='0' && ch <= '9') ){
        return true;
    }
    return false;
}

bool check(string &s){
    int n = s.length();
    int start = 0; 
    int end = n-1;

    while( start <= end){
        if(!isAlphanumeric(s[start])){
            start++;
            continue;
        }

        if(!isAlphanumeric(s[end])){
            end--;
            continue;
        }

        if(tolower(s[start]) != tolower(s[end])){ // if character doest match
            return false;
        }

        start++;
        end--;
    }
    return true;
}

int main(){
    string s = "Ac3?e3c&a";
    bool isPallindrome = check(s);
    cout<<" is the string pallindromic : "<<isPallindrome<<endl;
    return 0;
}