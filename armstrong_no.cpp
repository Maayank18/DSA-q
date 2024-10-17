#include<bits/stdc++.h>
using namespace std;

int armstrong(int n) {
    int sum = 0; // Initialize reversednum to 0
    while (n > 0) {
        int lastdigit = n % 10; // Get the last digit
        sum = sum + (lastdigit*lastdigit*lastdigit); // Update the reversed number
        n = n / 10; // Remove the last digit from n
    }
    return sum;
}

int main(){
    int n;
    cout<<" enter the number";
    cin>>n;
    
    int digits = armstrong(n);

    if(digits == n){
        cout<<" it is armstrong"<<endl;
    }else{
        cout<<"not armstrong";
    }

    return 0;

}