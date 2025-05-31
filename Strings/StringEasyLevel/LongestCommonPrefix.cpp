// this is the basic problem that aims at ki
// eg . s1 = "flower"  s2 = "fly"  s3 = "flowing";
// we have to return the longest common subsequence that is fl
// return "" if nothing found



// TC -> O(N X M)
//  SC -> O(1)
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

string check(vector<string> &str){
    if(str.empty()) return "";

    for(int i = 0; i<str[0].size(); i++){

        char firstChar = str[0][i]; // first character of first word in string

        for(int j = 1; j< str.size(); j++){ // check all the other string

            // if current string is shorter or char doesnt match
            // "car","cat","c"
            if(i >= str[j].size() || str[j][i] != firstChar){
                return str[0].substr(0,i);
            }
        }
    }
    return str[0];
}

int main(){
    vector<string> str = {"flower","fly","flowing"};
    string LongestCommonPrefix = check(str);
    cout<<" the longest common prefix is : "<<LongestCommonPrefix<<endl;
    return 0;
}




// BETTER APPROACH -> instead of traversing the whole lista nd each chaarcter us eth ebianry search approach 
// TC -> O(n x log m)
// SC -> O(1)
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to check if all strings have the same prefix of length len
bool isCommonPrefix(const vector<string>& strs, int len) {
    string prefix = strs[0].substr(0, len);
    for (int i = 1; i < strs.size(); i++) {
        if (strs[i].substr(0, len) != prefix) {
            return false;
        }
    }
    return true;
}

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";

    // Step 1: Find minimum string length
    int minLen = strs[0].size();
    for (int i = 1; i < strs.size(); i++) {
        minLen = min(minLen, (int)strs[i].size());
    }

    // Step 2: Binary Search on prefix length
    int low = 0, high = minLen;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (isCommonPrefix(strs, mid)) {
            low = mid + 1; // Try a longer prefix
        } else {
            high = mid - 1; // Try a shorter prefix
        }
    }

    // Final result is prefix of length (low + high) / 2
    return strs[0].substr(0, (low + high) / 2);
}

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    string result = longestCommonPrefix(strs);
    cout << "The longest common prefix is: " << result << endl;
    return 0;
}
