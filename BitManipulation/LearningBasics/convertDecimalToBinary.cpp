// given a decimal type number lets say (23) base 10 
// our aim is to convert this decimal type to the binary number base 2

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

string convert(int decNum){
    string ans ="";

    while( decNum > 0){
        if( decNum % 2 == 1){
            ans += "1";
        }else{
            ans += "0";
        }

        decNum /= 2;
    }

    reverse(ans.begin(),ans.end());

    return ans;
}

int main(){
    int decNum = 23;
    string binNum = convert(decNum);
    cout<<" decNum to BinNum "<< binNum<<endl;
    return 0;
}