#include<iostream>
using namespace std;
int cnt = 0;
int output(int i,int n){
    if(i>n){
        return cnt;
    }
    cnt = cnt + i;
    output(i+1,n);
}

int main(){
    int n;
    cin>>n;

    int result = output(1,n);
    cout<<result;
    return 0;
}