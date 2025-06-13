// given a binary numder lets say 10111 find its decomal equivalent 
// so fro 10111 the decimal equivalent is : 23
// tc -> o(length)
// sc -> o(1)
#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int converting( string binaryNum ){
    int ans = 0;
    int len = binaryNum.length();
    int power = 1;
    for(int i = len-1; i>=0; i--){
        if(binaryNum[i] == '1'){
            ans = ans + power;
        }
        power = power * 2;
    }
    return ans;
}

int main(){
    string binaryNum = "10111";
    int decimal = converting(binaryNum);
    cout<<" the decimal of the given binary is : "<<decimal<<endl;
    return 0;
}