// longest pallindromic subsequnece means 
// eg -> bbbab is our string 
// its all possible subsequnece can be b,bba.bbba,bab,bbbb
// out of these which is a pallindrome of longest length

#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int f(string s1, int n, string s2, int m){

    // base case 
    if( n<0 || m<0){return 0;}

    // case of matching 
    if(s1[n] ==  s2[m]){
        return 1+f(s1,n-1,s2,m-1);
    }

    // case of not matching
    return max(f(s1,n-1,s2,m),f(s1,n,s2,m-1));
}
int main(){
    string s1 = "bbbab";
    string s2 = s1;
    reverse(s1.begin(),s1.end());
    int n = s1.size()-1; // s1 length
    int m = s2.size()-1; // s2 length

    int LongestPallindromic = f(s1,n,s2,m);
    cout<<"longest is :"<<LongestPallindromic<<endl;
    return 0;
}


// SIMILARLY WE COULD WRITE THE MEMOISATION ADN TABULATION TECHNIQUE FOR THIS
//  USING THE BASE CONECEPT OF LONGEST COMMON SUBSEQUENCE