#include<iostream>
#include<stack>
#include<string>
using namespace std;

string Prefix_To_Postfix( string s){
    stack<string> st;
    int n = s.size();

    for(int i = n-1; i>=0; i--){
        char c = s[i];

    if((c >= 'A' && c <= 'Z') || (c>='a' && c<='z') || (c>='0' && c<='9')){
            st.push(string(1,c));
        }else{
            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();
            string con = t1 + t2  + s[i] ;
            st.push(con);
        }
    }
    return st.top();
}

int main(){
    string sample = "*+abc";
    string result = Prefix_To_Postfix(sample);
    cout<<result;
    return 0;
}