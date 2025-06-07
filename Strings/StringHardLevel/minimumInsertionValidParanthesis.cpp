// find the minimum number of insertion required for valid paranthesis 


// brute force approach
// TC -> O(N)
// SC -> O(1)
// #include<iostream>
// #include<string>
// #include<bits/stdc++.h>
// using namespace std;

// int check(string &s){
//     int insertions = 0;
//     int open = 0;

//     for( char c : s){
//         if(c == '('){
//             open++;
//         }else{
//             if(open > 0){
//                 open--;
//             }else{
//                 insertions++;
//             }
//         }
//     }
//     return insertions + open;
// }

// int main(){
//     string s = ")()()";
//     int requiredInsertion = check(s);
//     cout<<" the number of insertion required : "<<requiredInsertion<<endl;
//     return 0;
// }





// ANOTHER WAY CAN BE USING THE STACK APPRAOCH
#include<iostream>
#include<string>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

int check( string &s){
    int insertions = 0;
    stack<char> st;

    for(char c : s){
        if(c == '('){
            st.push(c);
        }else{ // )
            if(!st.empty() && st.top() == '('){
                st.pop();
            }else{
                insertions++;
            }
        }
    }
    return insertions + st.size();
}

int main(){
    string s = ")()()";
    int requiredInsertion = check(s);
    cout<<" the number of insertion required : "<<requiredInsertion<<endl;
    return 0;
}