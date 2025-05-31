// this problem ask us to return a true or false whether the string is isomorphic or not
// isophormic means -> a word should be mapped to a single word only 
// eg. s1 = "egg" , s2 = "add"
//  it is true as e is mapped with a and g is ampped with add




// BRUTE FORCE APPROACH 
// TIME COMPLEXITY -> O(N^2)
// SC -> O(1)
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

bool check(string &s1, string &s2){

    if(s1.length() != s2.length()) return false;

    int n = s1.length();

    for(int i = 0; i<n; i++){
        int cnt1 = 0;
        int cnt2 = 0;

        // its basically a pen apper approach where we are checking that 
        // chracater are lined parallely or not 
        for(int j = 0; j<i; j++){
            if(s1[i] == s1[j]) cnt1++;
            if(s2[i] == s2[j]) cnt2++;
        }

        if(cnt1 != cnt2) return false;
    }

    return true;
}

int main(){
    string s1 = "egg";
    string s2 = "add";
    bool isIsomorphic = check(s1,s2);
    cout<<" are string isomorphic : "<<isIsomorphic<<endl;
    return 0;
}





// BETTER SOLUTION

#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

bool check(string &s1, string &s2){

    if(s1.length() != s2.length()) return false;

    int n = s1.length();

    unordered_map<char,char> maps1;
    unordered_map<char,char> maps2;

    for(int i = 0; i<n; i++){

        char charS1 = s1[i];
        char charS2 = s2[i];

        if(maps1.count(charS1)){
            if(maps1[charS1] != charS2) return false;
        }else{
            // uss character pe map karado
            maps1[charS1] = charS2;
        }

        if(maps2.count(charS2)){
            if(maps2[charS2] != charS1) return false;
        }else{
            maps2[charS2] = charS1;
        }
    }
    return true;
}

int main(){
    string s1 = "egg";
    string s2 = "add";
    bool isIsomorphic = check(s1,s2);
    cout<<" are string isomorphic : "<<isIsomorphic<<endl;
    return 0;
}