#include<iostream>
using namespace std;

int count( int n){
    int cnt = 0;
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