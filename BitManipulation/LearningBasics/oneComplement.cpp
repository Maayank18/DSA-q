// we are given either a binary num or decimal number 
// our aim is to find the one complemnet of it 
// what is one complement -> basically flipping of the bits
// if we are given 1 make it 0 , if 0 maek it 1
// eg binary num -> 101101 -> 010010

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

void onesComplement( string &ans ){
    int len = ans.size();

    for(int i = len-1; i>=0; i-- ){
        if(ans[i] == '1'){
            ans[i] = '0';
        }else if( ans[i] == '0'){
            ans[i] = '1';
        }
    }
}

string finding( int decimal ){
    string ans = "";
    
    while( decimal > 0){
        if(decimal % 2 == 1){
            ans += "1";
        }else{
            ans += "0";
        }
        decimal /= 2;
    }

    reverse(ans.begin(),ans.end());
    onesComplement(ans);
    return ans;
}

int main(){
    int decimal = 23;
    string OneComplement = finding(decimal);
    cout<<" the ones complement for 23 is  "<<OneComplement<<endl;
    return 0;
}