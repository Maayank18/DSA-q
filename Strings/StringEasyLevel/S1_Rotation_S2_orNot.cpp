//  our aims is to find whether a given string s2 is the rotation of s1 or not 
//  eg s1 = "abcd"  s2 = "bcda"  thsi is rotation as movinf one chaacte left roation its working 


// BRUTE FROCE APPROACH 
//  TC -> O(N)
//  SC -> O(N)
// #include<iostream>
// #include<string>
// #include<bits/stdc++.h>
// using namespace std;

// bool check(string &s1, string &s2){

//     int n = s1.length();
//     if(s1.length() != s2.length()) return false;

//     string temp;

//     for(int i = 1; i<n; i++){
//         temp += s1[i];
//     }

//     temp += s1[0];

//     return (temp == s2);

// }

// int main(){
//     string s1 = "abcd";
//     string s2 = "bcda";

//     bool isRotation = check(s1,s2);

//     cout<<" is s2 the rotataion of s1 "<<isRotation<<endl;
//     return 0;
// }




// BETTER / OPTIMAL APPROACH
// TC -> O(N)
// SC -> O(1)
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

bool check(string &s1, string &s2){
    int n = s1.length();
    if (n != s2.length()) return false;

    // Check if s2[i] == s1[(i+1) % n]   VERY VERY IMPORTANT LEFT SHIFTING 
    for (int i = 0; i < n; i++) {
        if (s2[i] != s1[(i + 1) % n]) {
            return false;
        }
    }
    return true;
}

int main(){
    string s1 = "abcd";
    string s2 = "bcda";

    bool isRotation = check(s1,s2);

    cout<<" is s2 the rotataion of s1 "<<isRotation<<endl;
    return 0;
}
