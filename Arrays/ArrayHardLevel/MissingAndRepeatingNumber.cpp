// We will be given an array of integers and we have to find the 
// Repeating and the Misssing NUmber


// BRUTE FORCE APPROACH IS HASHING
// TC -> O(N)
// SC -> O(1)
// #include <iostream>
// using namespace std;

// void findMissingAndRepeating(int arr[], int n) {
//     int repeating = -1, missing = -1;

//     for (int i = 1; i <= n; i++) {
//         int count = 0;

//         // Count how many times i appears in the array
//         for (int j = 0; j < n; j++) {
//             if (arr[j] == i) {
//                 count++;
//             }
//         }

//         if (count == 0) {
//             missing = i;
//         } else if (count > 1) {
//             repeating = i;
//         }
//     }

//     cout << "Repeating number: " << repeating << endl;
//     cout << "Missing number: " << missing << endl;
// }

// int main() {
//     int arr[] = {4, 3, 6, 2, 1, 1};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     findMissingAndRepeating(arr, n);

//     return 0;
// }





// BETTER SOLUTION IS HASHING 
// THAT WILL BOIL DOWN THE TIME COMPLEXITY TO O(2N)
// BUT SC COMPLEXITY ALSO BECOMES O(N)


// #include <iostream>
// using namespace std;

// void findMissingAndRepeating(int arr[], int n) {
//     int repeating = -1;
//     int missing = -1;

//     int hash[n+1] = {0};

//     for(int i = 0; i<n; i++){
//         hash[arr[i]]++;
//     }

//     for(int j = 1; j<=n; j++){
//         if(hash[j] == 0){
//             missing = j;
//         }else if(hash[j] == 2){
//             repeating = j;
//         }

//         // if we found our requirement no need to iterate more and just break out
//         if(repeating != -1 && missing != -1){
//             break;
//         }
//     }
//     cout<<" repeating num is : "<<repeating<<endl;
//     cout<<"the missing num is : "<<missing<<endl;
// }

// int main() {
//     int arr[] = {4, 3, 6, 2, 1, 1};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     findMissingAndRepeating(arr, n);

//     return 0;
// }




// OPTIMAL SOLUTION 
// 1. MATHEMATICAL SOLUTION
// 2. XOR METHOD                     

// 1. solution use sum of first n , sum of first n square 
//  then sum of given and them sum of sqaures gievn
// and using basic mathematics we can found them 

// #include <iostream>
// using namespace std;

// void findMissingAndRepeating(int arr[], int n) {
//     // Step 1: Calculate the expected sum and expected sum of squares for numbers from 1 to n
//     long long S = (long long)n * (n + 1) / 2;                         // Sum of first n natural numbers
//     long long S_sq = (long long)n * (n + 1) * (2 * n + 1) / 6;       // Sum of squares of first n natural numbers

//     // Step 2: Calculate actual sum and sum of squares from the array
//     long long S1 = 0, S2 = 0;
//     for (int i = 0; i < n; i++) {
//         S1 += arr[i];                    // Actual sum of elements
//         S2 += (long long)arr[i] * arr[i]; // Actual sum of squares of elements
//     }

//     // Step 3: Use the equations:
//     // S1 - S = R - M       (Equation 1)
//     // S2 - S_sq = R^2 - M^2 = (R - M)(R + M) (Equation 2)

//     long long diff1 = S1 - S;       // R - M
//     long long diff2 = S2 - S_sq;    // R^2 - M^2

//     // Step 4: From Equation 2: diff2 / diff1 = R + M
//     long long sum = diff2 / diff1;  // R + M

//     // Step 5: Solve the two equations:
//     // R - M = diff1
//     // R + M = sum
//     // Add both → 2R = diff1 + sum → R = (diff1 + sum) / 2
//     int R = (diff1 + sum) / 2;
//     int M = R - diff1;

//     // Step 6: Output the result
//     cout << "Repeating number: " << R << endl;
//     cout << "Missing number: " << M << endl;
// }

// int main() {
//     int arr[] = {4, 3, 6, 2, 1, 1};  // Example input
//     int n = sizeof(arr) / sizeof(arr[0]);

//     findMissingAndRepeating(arr, n);

//     return 0;
// }




// second method will use XOR