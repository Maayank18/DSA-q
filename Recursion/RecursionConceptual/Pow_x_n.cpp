// This partcular question aims on finding the answer of a number raise to power 
// something wheter positive or negative



// Brute force approach

// #include<iostream>
// using namespace std;

// float powerr(int n, int power) {
//     float sum = 1;

//     if (power > 0) { // Handle positive power
//         for (int i = 0; i < power; i++) {
//             sum *= n;
//         }
//     } else if (power < 0) { // Handle negative power
//         for (int i = 0; i < -power; i++) { // Use the absolute value of power
//             sum *= n;
//         }
//         sum = 1 / sum; // Take the reciprocal for negative powers
//     }
//     // power == 0 case
//     return sum; // sum remains 1 for power == 0
// }

// int main(){
//     float n;
//     cout<<" enter a number -> ";
//     cin>>n;

//     int power;
//     cout<<" enter the power to which n is to be raised : ";
//     cin>> power;

//     float result = powerr(n,power);

//     cout<<" the final answer is : "<<result<<endl;
//     return 0;

// }


// if we try to solve it using recursion approach

#include<iostream>
using namespace std;

float powerr(int n, int power) {
    if( power == 0) return 1;

    if( power > 0){
        return n*powerr(n,power-1);
    }

    return 1 / powerr(n,-power);


}

int main(){
    float n;
    cout<<" enter a number -> ";
    cin>>n;

    int power;
    cout<<" enter the power to which n is to be raised : ";
    cin>> power;

    float result = powerr(n,power);

    cout<<" the final answer is : "<<result<<endl;
    return 0;

}