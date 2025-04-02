#include <bits/stdc++.h>
// using namespace std;
// const int MOD = 1e9 + 7;

// // Function to compute (base^exp) % MOD using Binary Exponentiation
// long long power(long long base, long long exp, long long mod) {
//     long long result = 1;
//     while (exp > 0) {
//         if (exp % 2 == 1) {  // If exponent is odd
//             result = (result * base) % mod;
//         }
//         base = (base * base) % mod; // Square the base
//         exp /= 2; // Reduce exponent
//     }
//     return result;
// }

// // Function to count good numbers efficiently
// int countGoodNumbers(long long n) {
//     long long evenPositions = (n + 1) / 2;  // (n+1)/2
//     long long oddPositions = n / 2;         // n/2
    
//     return (power(5, evenPositions, MOD) * power(4, oddPositions, MOD)) % MOD;
// }

// int main() {
//     long long n;
//     cin >> n;
//     cout << countGoodNumbers(n) << endl;
//     return 0;
// }
