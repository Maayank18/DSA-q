// Understanding the Problem:
// A number is good if:
// Even indices (0, 2, 4, …) contain even digits (0, 2, 4, 6, 8).
// Odd indices (1, 3, 5, …) contain prime digits (2, 3, 5, 7).


//BRUTE FORCE SOLUTION
// TIME COMPLEXITY -> O(logN)
// SPACE COMPEXITY -> O(1)

// odd places = n/2
// even places = n/2 + n%2
#include <bits/stdc++.h>
using namespace std;

int countGoodNumbers(int n) {
    int evenChoices = 5; // {0, 2, 4, 6, 8}
    int primeChoices = 4; // {2, 3, 5, 7}
    
    int evenPlaces = (n + 1) / 2; // Count of even index places
    int primePlaces = n / 2;      // Count of odd index places
    
    int count = pow(evenChoices, evenPlaces) * pow(primeChoices, primePlaces);
    
    return count;
}

int main() {
    int n;
    cin >> n;
    cout << countGoodNumbers(n) << endl;
    return 0;
}



// another way of writitng this 

// #include <bits/stdc++.h>
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
