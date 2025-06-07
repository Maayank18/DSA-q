// our aim is to reverse each adn every word that is present in our string 
// eg. s = "hello world"
// return answer = "world hello"
// remvoe all the trailing spaes also

// BRUTE FROCE APPRAOCH 
// TC -> O(N)
// SC -> O(N)
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

string converting(string &s){
    string ans = "";
    int n = s.length();

    // step 1 reverse the whole s
    reverse(s.begin(),s.end());

    for(int i = 0; i<n; i++){
        string word = "";

        while(i<n && s[i] != ' '){
            word+=s[i];
            i++;
        }

        reverse(word.begin(),word.end());
        if(word.length() > 0){
            ans += " " + word;
        }
    }
    return ans.substr(1); // return from index 1
}

int main(){
    string s = "the sky is blue";
    string reversed = converting(s);
    cout<<"the reverse string is : "<<reversed<<endl;
    return 0; 
}