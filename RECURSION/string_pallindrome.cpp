#include<bits/stdc++.h>
using namespace std;

bool pallindrome(string mayak, int i ){
    if(i>=mayak.size()/2) return true;
    if(mayak[i]!=mayak[mayak.size()-i-1]) return false;
    return pallindrome(mayak,i+1) ;

}

int main(){
    int i;

    string dsa = "madam";
     cout<<pallindrome(dsa,0);
    return 0;
}