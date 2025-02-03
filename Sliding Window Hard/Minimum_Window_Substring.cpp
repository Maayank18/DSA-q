// #include<iostream>
// #include<string>
// #include<map>
// #include<bits/stdc++.h>
// using namespace std;

// string minimum_Length_Window(string s, string t){
//     int n = s.size();
//     int m = t.size();
//     int minLen = INT_MAX;
//     int sIndex = -1;

//     for(int i = 0;i<n; i++){
//         int hash[256] = {0};
//         int count = 0;
//         for(int j = 0; j<m; j++ ){
//             hash[t[j]]++;
//         }

//         for( int j = i; j<n; j++){
//             if(hash[s[j]]>0){
//                 count++;
//                 hash[s[j]]--;
//             }

//             if(count == m){
//                 minLen = min(j-i+1,minLen);
//                 sIndex = i;
//                 break;
//             }
//         }
//     }
//     return s.substr(sIndex,minLen);
// }

// int main(){
//     string s = "ddaaabbca";
//     string t = "abc";
//     string answer = minimum_Length_Window(s,t);
//     cout<<" the required minimal string is : "<<answer<<endl;
//     return 0;
// }



// An better / optimal approach using the window and two pointer approach


#include <iostream>
#include <climits>
#include <string>
#include <algorithm>
using namespace std;

string minimum_Length_Window(string s, string t) {
    int n = s.size();
    int m = t.size();
    int l = 0;  // Left pointer
    int r = 0;  // Right pointer
    int minLen = INT_MAX;
    int sIndex = -1;
    int hash[256] = {0};  // Frequency map for characters in t
    int count = 0;  // Count of characters matched

    // Initialize the hash map for characters in t
    for (int i = 0; i < m; i++) {
        hash[t[i]]++;
    }

    while (r < n) {
        // If the character at 'r' is in t, reduce its count and increase the matched count
        if (hash[s[r]] > 0) {
            count++;
            hash[s[r]]--;
        }

        // If all characters in t are matched, try to shrink the window
        while (count == m) {
            // Update the minimum length and starting index if a smaller valid window is found
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                sIndex = l;
            }

            // Move the left pointer to shrink the window
            hash[s[l]]++;
            if (hash[s[l]] > 0) {
                count--;
            }
            l++;
        }

        // Expand the window by moving the right pointer
        r++;
    }

    // If no valid window was found, return an empty string
    if (sIndex == -1) return "";

    // Return the minimum window substring
    return s.substr(sIndex, minLen);
}

int main() {
    string s = "ddaaabbca";
    string t = "abc";
    string answer = minimum_Length_Window(s, t);
    cout << "The required minimal string is: " << answer << endl;
    return 0;
}


