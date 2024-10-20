#include<iostream>
using namespace std;

void output( int n, int i){
    if(i<1){
        return;
    }
    cout<<i<<endl;
    output(n,i-1);
}

int main(){
    int n;
    cin>>n;

    output(n,n);
    return 0;
}