// anagram means we are given two strings s1 and s2
//  s1 = "LISTEN"   s2 = "SILENT"
//  if all the character  of s1 is in s2 then we can say strings are 
// anagram or s2 is anagram of s1



// // BETTER APPRAOCH
// // TIME COMPLEXITY -> O(N)
// // SPACE COMPLEXITY -> O(1)
#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<map>
using namespace std;

bool check(string &s1, string &s2){

    // base case 
    if( s1.length() != s2.length()) return false;
    
    // map data structure to map the letters
    map<char,int> mpp;
    int n = s1.length();

    // we are adding s1 and removing 2 and at last our mpp should be 0
    for(int i = 0; i<n; i++){
        mpp[s1[i]]++;
        mpp[s2[i]]--;
    }

    for(auto it : mpp){
        if(it.second != 0) return false;
    }

    return true;
}

int main(){
    string s1 = "LISTEN";
    string s2 = "SILENT";
    bool isAnagram = check(s1,s2);
    cout<<" are the strings anagram "<<isAnagram<<endl;
    return 0;
}





// BRUTE FORCE APPRAOCH 
// TIME COMPLEXITY -> O(N factorial)
// SPACE COMPLEXITY -> O(1)
#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<map>
using namespace std;

bool check(string &s1, string &s2){

    sort(s1.begin(),s1.end()); // LEXIGRAPHICAL ORDER AND GENERATING ALL THE PERMUTTAION PSSOIBLE 

    do{
        if(s1==s2) return true;
    }while(next_permutation(s1.begin(),s1.end()));

    return false;
}

int main(){
    string s1 = "LISTEN";
    string s2 = "SILENT";
    bool isAnagram = check(s1,s2);
    cout<<" are the strings anagram "<<isAnagram<<endl;
    return 0;
}



// EFFICIENT APPRAOCH 
// TIME COMPLEXITY -> O(N log n)
// SPACE COMPLEXITY -> O(1)
#include<iostream>
#include<bits/stdc++.h>
#include<string>
#include<map>
using namespace std;

bool check(string &s1, string &s2){

    sort(s1.begin(),s1.end());  
    sort(s2.begin(),s2.end());

    return s1==s2;
}

int main(){
    string s1 = "LISTEN";
    string s2 = "SILENT";
    bool isAnagram = check(s1,s2);
    cout<<" are the strings anagram "<<isAnagram<<endl;
    return 0;
}