#include<iostream>
using namespace std;

int count( int n){
    int cnt = 0;  // time complexity O(n) n = number of digits 
    while(n>0){
         cnt = cnt+1;
        n = n/10;
    }
    return cnt;
}
int main(){
    int n;
    cin>>n;
    int result = count(n);
    cout<<result;
    return 0;
}

// method 2

#include<bits/stdc++.h>
using namespace std;

int count( int n){  // time comlexity is O(1)
    int cnt = (int)(log10(n)+1);
    return cnt;
}
int main(){
    int n;
    cin>>n;
    int result = count(n);
    cout<<result;
    return 0;
}