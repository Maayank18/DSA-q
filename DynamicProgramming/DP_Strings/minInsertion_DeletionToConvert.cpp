//  this problem basically aims on identifying the min no. of 
//  insertion and deletion to be make on string s1 to convert it to s2

// eg. we have mayank = s1 and monkey = s2
//  in order to convert mayank to monkey 
// i will remove aya from mayank and add oey
//  so thats 3 deletion + 3 insertion total 6


//  here we will use basic logic of observance that is 
// deletion = n - LCS 
// insertion = m - LCS 
//  total = n + m - 2xLCS


#include<iostream>
#include<string>
using namespace std;

int f(string s1, int n, string s2, int m){

    //  base case
    if(n<0 || m<0){
        return 0;
    }

    //  cas eof taking and consideirng 
    if( s1[n] == s2[m]){
        return 1+ f(s1,n-1,s2,m-1);
    }

    // case of nonaccepting
    return max(f(s1,n-1,s2,m),f(s1,n,s2,m-1));
}

int main(){
    string s1 = "mayank";
    string s2 = "monkey";
    int n = s1.size();
    int m = s2.size();
    int LCS = f(s1,n-1,s2,m-1);
    cout<<" the minimum deletion + addition to convert s1 -> s2 : "<< n + m - (2*LCS)<<endl;
    return 0;

}




//  REST DP MEMOISATIONA DN TBAULATION CAN EASILY BE SOLVED THORUGH WATCHING ADNSEEING LCS CODE ONLY