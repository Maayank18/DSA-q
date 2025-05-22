// in this problem our task in to find the subarray
//  whose product is maximum (CONTNOUS = SUBARRAY)
// eg. arr = [2,3,-2,4]
// ans = 6



// BRUTE-BETTER APPROACH 
// TC -> O(N^2)
// SC -> O(1) 
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int f(vector<int> &arr){
//     int n = arr.size();
//     int maxProduct = 0;
//     for(int i = 0; i<n; i++){
//         int product = 1;
//         for(int j = i; j<n; j++){
//             product *= arr[j];
//             maxProduct = max(maxProduct,product);
//         }
//     }
//     return maxProduct;
// }

// int main(){
//     vector<int> arr = {2,3,-2,4};
//     int maxProduct = f(arr);
//     cout<<" the product of maximum Subarray is : "<<maxProduct<<endl;
//     return 0;
// }




// NOW THERE EXIST  2 OPTIMAL APPROAHCES 
// 1. OBSERVATION
// 2. KADANES - NOT RECOMMENDED



// APPROACH 1 - OBSERVATION BASED YET MOST INTUITVE RECOMMENDED FOR INTERVIEWS
// CASES :
// 1. all positives
// 2. even number of negatives and positives
// 3. odd negative number , positive => max prefix or max suffix
// 4. if we ehave 0

// tc -> O(n)
// sc -> o(1)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int f(vector<int> &arr){
    int n = arr.size();
    int prefix = 1;
    int suffix = 1;
    int maxi = INT_MIN;
    for(int i = 0; i<n; i++){
        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;

        prefix = prefix * arr[i];
        suffix = suffix * arr[n-i-1];
        maxi = max(maxi,max(suffix,prefix));
    }
    return maxi;
}

int main(){
    vector<int> arr = {2,3,-2,4};
    int maxProduct = f(arr);
    cout<<" the product of maximum Subarray is : "<<maxProduct<<endl;
    return 0;
}