// conversion of infix expression to prefix expression
// 1. reverse the string 
// 2. reverse the opening and closinf brackets
// 3. solve it as infix to postfix expression 
// 4. again reverse it and rteurn 


#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;

int priority(char c) {
  if (c == '^')
    return 3;
  else if (c == '/' || c == '*')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

string Infix_To_Prefix( string s){
    reverse(s.begin(),s.end());

    for(int i = 0; i<s.size(); i++){
        if (s[i] == '(') {
            s[i] = ')';
        } else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    string ans = "";
    stack<char> st;
    for( int i = 0; i<s.size(); i++){
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
            ans+=c;
        }

        else if( c == '('){
            st.push('(');
        }

        else if( c == ')'){
            while(!st.empty() && st.top() != '('){
                ans+=st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            while(!st.empty() && priority(c)<=priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string neww = "a+b*(c^d-e)";
    string result = Infix_To_Prefix(neww);
    cout<<" thr postfix expression would be : "<<result<<endl;
    return 0;
}