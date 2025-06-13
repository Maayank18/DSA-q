// given two number lest say a = 5 and b = 6
// our task is to swap number and store a = 6 adn b = 5

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     int a = 5;
//     int b = 6;
//     cout<<" numbers before swapping : "<<a<<" and " <<b<<endl;

//     int temp = a;
//     a = b; 
//     b = temp;

//     cout<<" numbers after swapping : "<<a<<" and " <<b<<endl;
//     return 0;
// }





// USING XOR TO SWAP TWO NUMBERS
// xor of same number is 0
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 5;
    int b = 6;
    cout<<" numbers before swapping : "<<a<<" and " <<b<<endl;

    a = a^b;
    b = a^b; // -> (a^b)^b = a
    a = a^b; // -> (a^b)^a = b

    cout<<" numbers after swapping : "<<a<<" and " <<b<<endl;
    return 0;
}