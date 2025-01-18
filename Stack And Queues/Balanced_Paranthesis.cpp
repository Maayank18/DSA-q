// this particular problem aims to check whether given string has balanced paranthesis 
// or not
// example .  (){[]} this is balanced why ?
// 1. it has opening and closing brackets for same type of brackets 
// 2. there are equal pair of same brackets
// 3. they are following the order

#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool check_balanced( string paranthesis){
    stack<char> st;
    for( int i = 0; i<paranthesis.size(); i++){
        if( paranthesis[i] == '(' || paranthesis[i] == '[' ||  paranthesis[i] == '{'){
            st.push(paranthesis[i]);
        }else{
            if(st.empty()) return false;

            char ch = st.top();
            if( paranthesis[i] == ')' && ch == '(' || paranthesis[i] == ']' && ch == '['
             || paranthesis[i] == '}' && ch == '{'){
            st.pop();
             }else{
                return false;
             }
        }
    }
    return st.empty();
}

int main(){
    string paranthesis = "()({[]})";
    bool result = check_balanced(paranthesis);
    cout<<" is it balanced : "<<result<<endl;
    return 0;
}