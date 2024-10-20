#include<iostream>
using namespace std;

void output(int i, int n){
    if(i>n){
        return ;
    }
    cout<<i<<endl;
    output(i+1,n);
}

int main(){
    int n;
    cin>>n;

    output(1,n);
    return 0;
}