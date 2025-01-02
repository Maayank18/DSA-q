#include<iostream>
using namespace std;

int GCD( int a, int b){
    while(a>0 && b>0){
        if(a>b){
             a = a-b;
        }else{
            b = b-a;
        }
    }
    if(a==0){
        return b;
    }else{
        return a;
    }
}

int main(){
    int a,b;
    cin>>a>>b;

    int result = GCD(a,b);
    cout<<result;
    return 0;
}