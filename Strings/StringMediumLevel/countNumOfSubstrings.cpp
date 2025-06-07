// this question aims of counting the number of substring that are 
//  present for a give string input
// number of substrings are also given by -> n(n+1)/2

// BRUTE FORCE APPROACH
// TC -> O(N^2)
// SC -> O(1)
#include<iostream>
#include<bits/stdc++.h>
#include<string>
using namespace std;

int count(string &s){
    int ans = 0;
    int n = s.length();

    for(int i = 0; i<n ; i++){
        for(int j = i; j<n ; j++){
            ans++;
        }
    }
    return ans;
}

int main(){
    string s = "mayank";
    int Substrings = count(s);
    cout<<" the number of substring are : "<<Substrings<<endl;
    return 0;
}



// OPTIMAL APPRAOCH DO EXITS 
// use the formula n(n+1)/2
//  where n is the length of string
// TC -> O(1)
//  SC-> O(1) 
