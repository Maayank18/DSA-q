// our task is to remove all the duplicate adjacent character present 
// eg. s = "abbaca" -> remove bb -> remove aa -> ans = ca
// and we have to provide with the final leftover string

// BRUTE FORCE APPRAOCH
// TC -> O(N^2)
// SC -> O(1)
// #include<iostream>
// #include<string>
// #include<bits/stdc++.h>
// using namespace std;

// void removeDuplicates(string &s){
//     bool flag = true;

//     while(flag){
//         flag = false;
//         for(int i = 0; i<s.length(); i++){
//             if(s[i] == s[i+1]){
//                 s.erase(i,2);
//                 flag = true;
//                 break;
//             }
//         }
//     }
// }

// int main(){
//     string s = "abbaca";
//     removeDuplicates(s);
//     cout<<" after removing adjacent duplicate elements string is : "<<s<<endl;
//     return 0;
// }





// OPTIMAL APPRAOCH -> using a stack
// tc -> o(n)
//  sc -> o(n)

#include<iostream>
#include<string>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

string removeDuplicates(string &s){
    stack<char> st;

    for( char ch : s){
        if(!st.empty() && st.top() == ch){
            st.pop();
        }else{
            st.push(ch);
        }
    }

    string updatedString = "";
    while(!st.empty()){
        updatedString += st.top();
        st.pop();
    }

    return updatedString;
}

int main(){
    string s = "abbaca";
    string newstring = removeDuplicates(s);
    cout<<" after removing adjacent duplicate elements string is : "<<newstring<<endl;
    return 0;
}