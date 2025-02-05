#include<iostream>
#include<string>
using namespace std;

bool IsValid(string s, int idx, int count){
    int n = s.size();
    if(count < 0) return false;
    if(idx == n){
        return (count==0);
    }

    if(s[idx] == '('){
        return IsValid(s,idx+1,count+1);
    }

    if(s[idx] == ')'){
        return IsValid(s,idx+1,count-1);
    }

    if(s[idx] == '*'){
        return IsValid(s, idx + 1, count + 1) || // Treat '*' as '('
               IsValid(s, idx + 1, count - 1) || // Treat '*' as ')'
               IsValid(s, idx + 1, count); 
    }

    return false;
}

int main() {
    string s = "(*)";

    if (IsValid(s, 0, 0)) {
        cout << "Valid Parentheses\n";
    } else {
        cout << "Invalid Parentheses\n";
    }

    return 0;
}