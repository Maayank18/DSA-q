// if we carefully observe 
//  eg. abcaa 
// here what will be our LCS aaa or aca and we have 2 more letter left 
//  eg 2. aata 
// here we can see our longest common subsequnce is aaa and 1 letter is left

// so we could figure out that 
// n - LongestCommonSubsequence = min insertion to form a pallindrome

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int f(string s1,int n, string s2, int m){

    // base case index out of bound
    if(n<0 || m<0){
        return 0;
    }
    
    // case where we our considering it as longest subsequence
    if(s1[n] == s2[m]){
        return 1+f(s1,n-1,s2,m-1);
    }

    // case where it is not a substring
    return max(f(s1,n-1,s2,m),f(s1,n,s2,m-1));
}

int main(){
    string s1 = "mayank";
    int n = s1.size()-1;
    string s2 = s1;
    int m = s2.size()-1;
    reverse(s2.begin(),s2.end());
    int originalLength = s1.size();
    int length_LCS = f(s1,n,s2,m);
    cout<<" minimum insertion required to make it pallindromic is : "<<originalLength - length_LCS<<endl;
    return 0;
}




// rest all methods will be same as LCS WE CAN CHECK OUT THERE ONLY