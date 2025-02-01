// This Problem basically aims to find the length of the longest substring 
// wothout repetition of any characters 

// Example 1:
// Input: s = ”abcabcbb”
// Output: 3
// Explanation: The answer is abc with length of 3.

// Example 2:
// Input: s = ”bbbbb”
// Output: 1
// Explanation: The answer is b with length of 1 units.


//BRUTE FORCE -> this is the naive solution where i am gonna generate
// all the possible subarrays and check the max length and return it
//Time Complexity -> o(n^2) two loops
//Space Complexity -> o(256) because i am storing it in ahsh array of this size
// #include<iostream>
// #include<string>
// #include<bits/stdc++.h>
// using namespace std;

// int LongestStringNonRepeated( string s){
//     int n = s.size();
//     int maxlen = INT_MIN;
//     for(int i = 0; i<n; i++){
//         int hash[255] = {0};
//         for( int j = i; j<n; j++){
//             if(hash[s[j]] == 1) break;
//             hash[s[j]] = 1;
//             maxlen = max(j-i+1,maxlen);
//         }
//     }
//     return maxlen;
// }

// int main() {
//   string str = "abcdbefa";
//   cout << "The length of the longest substring without repeating characters is " << 
//   LongestStringNonRepeated(str);
//   return 0;
// }


// A better and a brute force solution approach can be like using a sliding window
// and a two pinter approach where we can work upon certain frame and windows and 
// iterate accordingly

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int LongestStringNonRepeated( string s){
    int hash[256] = {0};
    int n = s.size();
    int left = 0;
    int right = 0;
    int maxlen = 0;

    while(right<n){
        if(hash[s[right]] != 0){
            if(hash[s[right]] >= left){
                left = hash[s[right]]+1;
            }
        }

        maxlen = max(maxlen,right-left+1);
        hash[s[right]] = right;
        right++;
    }
    return maxlen;
}

int main() {
  string str = "abcdbefa";
  cout << "The length of the longest substring without repeating characters is " << 
  LongestStringNonRepeated(str);
  return 0;
}