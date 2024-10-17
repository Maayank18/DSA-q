#include<bits/stdc++.h>
using namespace std;

int count( int n){
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