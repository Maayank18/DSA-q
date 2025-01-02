#include<iostream>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    cout<<endl;
    cin>>m;

    for(int i = min(n,m);i>=1; i--){
        if(n%i==0 && m%i==0){
            cout<<" The GCD is :"<<i;
            break;
        }
    }
    return 0;
}