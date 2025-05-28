// this is the basic problem that aims at ki
// eg . s1 = "flower"  s2 = "fly"  s3 = "flowing";
// we have to return the longest common subsequence that is fl
// return "" if nothing found

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