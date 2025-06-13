//  we will be given two number 
//  how manys bits to be converted to convert a to b
// eg a = 10 and b = 7

// we can simply do a zor operation and count all the set bits

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string converting( int &ans ){
    string result = "";

    while( ans > 0){
        if( ans % 2 == 1){
            result += '1';
        }else{
            result += '0';
        }

        ans /= 2;
    }

    reverse(result.begin(),result.end());
    return result;
}

int main(){
    int a = 10;
    int b = 7;

    int ans = a^b;

    string binarycoded = converting(ans);

    int len = binarycoded.size();
    int count = 0;
    for(int i = len-1; i>=0; i--){
        if(binarycoded[i] == '1'){
            count++;
        }
    }

    cout<<" the minimum flips required is : "<<count<<endl;
    return 0;
}