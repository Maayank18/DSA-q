// here our aim is to return the sequence of count and say
//  as the name suggest 
// eg. if we have 111223
//  answer is 312213 -> 3 occurence of 1, 2 of 2 and 1 of 3
// we need to find the nth sequence;

#include<iostream>
#include<string>
#include<bits/stdc++.h>
using namespace std;

string find(int n){
    // base case first string 
    string current = "1";

    // number of sequence we will find as 1st is base 
    for(int i = 1; i<n; i++){
        string next = "";
        int count = 1; // atlesat behavinf 1 occurence

        for(int j = 1; j<current.length(); j++){
            if(current[j] == current[j-1]){
                count++;
            }else{
                next += to_string(count);
                next += current[j-1];
                count = 1;
            }
        }
        next += to_string(count);
        next += current.back();

        current = next;
    }
    return current;
}

int main(){
    cout<<" the nth sequence for count and say is "<<find(5)<<endl;
    return 0;
}