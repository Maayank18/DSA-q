#include<iostream>
#include<stack>
#include<string>
using namespace std;

string Postfix_To_Infix(string s){
    stack<string> st;
    string con;
    int n = s.size();
    for( int i = n-1; i>=0; i--){
        char c = s[i];

        if((c >= 'A' && c <= 'Z') || (c>='a' && c<='z') || (c>='0' && c<='9')){
            st.push(string(1,c));
        }else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            con = '(' + t1 + s[i] + t2 + ')';
            st.push(con);
        }
    }
    return st.top();
}

int main(){
    string test = "*+abc";
    string result = Postfix_To_Infix(test);
    cout<<"infix output is :"<<result<<endl;
    return 0;
}