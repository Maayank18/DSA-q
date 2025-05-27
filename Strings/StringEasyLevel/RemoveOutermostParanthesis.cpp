// BRUTE FORCE SOLUTION

#include<iostream>
#include<string>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

string check(string s){
    stack<char> st;
    string result = "";
    string primitive ="";

    for( char ch : s){
        primitive += ch;

        if(ch == '('){
            st.push(ch);
        }else{
            st.pop();
        }

        if(st.empty()){
             result += primitive.substr(1, primitive.size() - 2);
            primitive = "";
        }
    }
    return result;
}

int main(){
    string s = "((()))";
    string ans = check(s);
    cout<<" the valid after operating string is : "<<ans<<endl;
    return 0;
}