// nth root of m refers to a number x such that when x is raised to power n it returns
// the number value m 
// for eg. cube root of 27 is 3 and if not found return a -1

// BRUTE FORCE APPROACH -  a linear search - a TIME COMPLEXITY OF AROUND O(nth root (n))

// #include<iostream>
// #include<cmath>
// using namespace std;

// int nth_root(int n, int m){
//     if ( m == 0) return 0;
//     int answer = -1;

//     for( int i = 1; i<=m ; i++){
//         if(pow(i,n) == m){
//             answer = i;
//         }else if( pow(i,n) > m) break; // make sure that we dont un-necessarily iterate
//     }
//     return answer;
// }

// int main(){
//     int n;
//     cout<<" enter the root that is need to be found : ";
//     cin>>n;

//     int m;
//     cout<<" enter the number whose nth root is needed to be found : ";
//     cin>>m;

//     int result = nth_root(n,m);

//     if(result == -1){
//         cout<<" nth root doesnt exist "<<endl;
//     }else{
//         cout<<" th nth root is : "<<result<<endl;
//     }
//     return 0;
// }


// optimal solution - as we see here till some point our answer is valid and after
// some time it will be invalid so binary search method will be best suited for it 

// kindly check its once a simple error of power and findiig limit case


#include <iostream>
#include <cmath>
#include <climits> // For INT_MAX
using namespace std;

// Helper function to compute mid^n and check for overflow
long long power(int mid, int n) {
    long long result = 1;
    for (int i = 0; i < n; i++) {
        result *= mid;
        if (result > INT_MAX) return -1; // Handle overflow
    }
    return result;
}

// Function to find the nth root of m
int nth_root(int n, int m) {
    if (m == 0) return 0;       // The nth root of 0 is always 0
    if (n == 1) return m;       // The 1st root of m is m itself

    int low = 1, high = m;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        long long mid_power = power(mid, n); // Compute mid^n once
        if (mid_power == m) {
            return mid; // Exact nth root found
        } else if (mid_power == -1 || mid_power > m) {
            high = mid - 1; // Too large or overflow
        } else {
            low = mid + 1; // Too small
        }
    }

    return -1; // Return -1 if no exact root exists
}

int main() {
    int n, m;
    cout << "Enter the root that needs to be found: ";
    cin >> n;
    cout << "Enter the number whose nth root is needed: ";
    cin >> m;

    int result = nth_root(n, m);

    if (result == -1) {
        cout << "Nth root doesn't exist as an integer." << endl;
    } else {
        cout << "The nth root is: " << result << endl;
    }

    return 0;
}

