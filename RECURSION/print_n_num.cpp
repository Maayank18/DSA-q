#include<iostream>
using namespace std;

void print(int cnt, int n){
    if(cnt > n){
       return; 
    }
    cout<<cnt<<" ";
    print(cnt + 1,n);
}
int main(){
    int n;
    cin>>n;

    print(1,n);
    return 0;
}