#include<iostream>
using namespace std;

int f(int n){
    if(n <= 0) return n;
    return f(n-1)+f(n-2);
}

int main(){
    int n;
    cin>>n;

    cout<<f(n);
    return 0;
}

