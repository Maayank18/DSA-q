// this question aims us to return the length of the longest pallindromic 
//  substring that is present of all the sub string that could be made



// BRUTE FORCE APPRAOCH 
// TC -> O(N^2)
//  SC- >O(1)
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

bool pallindrome(string &s, int start, int length){
    // madam -- m -- i = 0; j-i+1 = 1
    // ma -- i = 0; j-i+1 = 1
    string temp = "";
    for(int i = start; i<length; i++){
        temp += s[i];
    }

    string reversed = "";
    for(int i = length-1; i>=0; i--){
        reversed += s[i];
    }

    return temp == reversed;

}

int check(string &s){
    int n = s.length();
    int maxi = INT_MIN;

    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            if(pallindrome(s,i,j-i+1)){
                maxi = max(maxi,j-i+1);
            };
        }
    }
    return maxi;
}

int main(){
    string s = "madam";
    int lengthPallindromic = check(s);
    cout<<" the length of longest pallindromic substring "<<lengthPallindromic<<endl;
    return 0;
}



// better appraoch 
#include <iostream>
#include <string>
using namespace std;

// Function to return length of longest palindromic substring
int longestPalindromeLength(const string &s) {
    int n = s.size();
    int maxLength = 1; // at least 1 character is a palindrome

    for (int center = 0; center < n; center++) {
        // Case 1: Odd-length palindrome
        int left = center, right = center;
        while (left >= 0 && right < n && s[left] == s[right]) {
            maxLength = max(maxLength, right - left + 1);
            left--;
            right++;
        }

        // Case 2: Even-length palindrome
        left = center;
        right = center + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            maxLength = max(maxLength, right - left + 1);
            left--;
            right++;
        }
    }

    return maxLength;
}

int main() {
    string s = "madam";
    int result = longestPalindromeLength(s);
    cout << "Length of longest palindromic substring: " << result << endl;
    return 0;
}
