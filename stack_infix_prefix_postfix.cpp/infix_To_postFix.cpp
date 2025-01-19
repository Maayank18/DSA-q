// this program will generally be focusing on the conversion of the given 
// infix string into the postfix string

#include<iostream>
#include<string>
#include<stack>
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

string Infix_To_Postfix( string s){
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.length(); i++) {
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
            while(!st.empty() && priority(c) < priority(st.top())){
                ans+=st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while(!st.empty()){
        ans+=st.top();
        st.pop();
    }
    return ans;
}


int main(){
    string infix = "a+b*(c^d-e)";
    string result = Infix_To_Postfix(infix);
    cout<<" thr postfix expression would be : "<<result<<endl;
    return 0;
}