// it will be the basic written to code approach conversion
// making sure that in this case we will have a stack storing the string

#include<iostream>
#include<stack>
#include<string>
using namespace std;

string Postfix_To_Infix(string s){
    stack<string> st;
    string con;
    int n = s.size();
    for( int i = 0; i<n; i++){
        char c = s[i];

        if((c >= 'A' && c <= 'Z') || (c>='a' && c<='z') || (c>='0' && c<='9')){
            st.push(string(1,c));
        }else{
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            con = '(' + t2 + s[i] + t1 + ')';
            st.push(con);
        }
    }
    return st.top();
}

int main(){
    string test = "ab+c*";
    string result = Postfix_To_Infix(test);
    cout<<"infix output is :"<<result<<endl;
    return 0;
}