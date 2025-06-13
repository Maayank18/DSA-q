// our aim is to remove/delete the last set bit that is  
// the first occurence of 1 from right whene a decimal num
//  is converted to the binary we have to remove it 

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string deleting( string &ans){
    int n = ans.size();

    for(int i = n-1; i>=0; i--){
        if(ans[i] == '1'){
            ans.erase(i,1);
            break;
        }
    }

    return ans;
}

string removing( int num ){
    string ans ="";

    while( num > 0){
        if(num % 2 == 1){
            ans += '1';
        }else{
            ans += '0';
        }
        num /= 2;
    }
    reverse(ans.begin(),ans.end());

    string afterManipulation = deleting(ans);

    return afterManipulation;
}

int main(){
    int num = 12;
    cout<<" the binary form before deleting : 1100 "<<endl;
    string removeSet = removing(num);
    cout<<" the binary form after deleting : "<<removeSet<<endl;
    return 0;
}



// SIMILARLY CHECK IF NUMBER IS POWER OF 2
// IF( NUM & NUM -1 == 0) HENCE A POWER OF TWO

// SIMILARLY COUNT THE NUMBER OF SET BITS
// IT WILL BE DONE ON PURELY BRUTE FROCE APPRAOCH