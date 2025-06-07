// Modified version of counting all substring of a given string
//  here our task is to return the sub strings that are unique no repetition


// BRUTE FORCE APPROACH
// TC -> O(N^3) due to substr
// SC -> O(N)
#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int count( string &s){
    int n =  s.length();
    set<string> uniqueSubString;

    for(int i = 0; i<n; i++){
        for(int j = i; j<n; j++){
            uniqueSubString.insert(s.substr(i,j-i+1)); // start,length
        }
    }
    return uniqueSubString.size();
}

int main(){
    string s = "mayank";
    int substrings = count(s);
    cout<<" the total number of unique substring are : "<<substrings<<endl;
    return 0;
}