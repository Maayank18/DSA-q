#include<iostream>
using namespace std;

int reversed(int n) {
    int reversednum = 0; // Initialize reversednum to 0
    while (n > 0) {
        int lastdigit = n % 10; // Get the last digit
        reversednum = (reversednum * 10) + lastdigit; // Update the reversed number
        n = n / 10; // Remove the last digit from n
    }
    return reversednum;
}

int main(){
    int n;
    cin>>n;

    int result = reversed(n);
    if( n == result){
        cout<<" YES";
    }else{
        cout<<" fck off";
    }
    return 0;
}