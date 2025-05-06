#include<iostream>
#include<stack>
#include<string>
using namespace std;

string Postfix_To_prefix( string s){
    stack<string> st;
    int n = s.size();

    for(int i = 0; i<n; i++){
        char c = s[i];

        if((c >= 'A' && c <= 'Z') || (c>='a' && c<='z') || (c>='0' && c<='9')){
            st.push(string(1,c));
        }else{
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string con = s[i] + t2 + t1;
            st.push(con);
        }
    }
    return st.top();
}

int main(){
    string sample = "ab+c*";
    string result = Postfix_To_prefix(sample);
    cout<<result;
    return 0;
}