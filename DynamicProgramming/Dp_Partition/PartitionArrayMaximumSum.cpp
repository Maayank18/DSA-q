// the question ask us to return a maximum sum of partition 
//  eg. given arr = [1,15,7,9,2,5,10] and k = 3 axx length of partiton
// if we make partition as [1,15] [7,9,2] [2,5,10]
//  now we selelct the max of that partition adn add its n time taht is the lenght of partition
//  that is [15,15] [ 9,9,9 ] [10,10,10] = 77 and we need to max it

// as there are various solve to solve
//  so e try out all various way using the recusion 
//  and then we will take the best once


// express everthing in indexes
//  try every partition form that index
// take the best partition 
// base case 
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int f(int i, int n,int k,  vector<int> &arr){


    // base case 
    if(i == n) return 0;

    int len = 0;
    int maxi = -1e9;
    int sum = 0;
    int maxAns = -1e9;
    for(int j = i; j<min(n,i+k); j++){
        len++;
        maxi = max(maxi,arr[j]);
        sum = (len*maxi) + f(j+1,n,k,arr);
        maxAns = max(maxAns,sum);
    }

    return maxAns;
}

int main(){
    vector<int> arr = {1,15,7,9,2,5,10};
    int n = arr.size();
    int k = 3; // max lenghth of partition we can form
    int maxSum = f(0,n,k,arr);
    cout<<"the max partition sum is : "<<maxSum<<endl;
    return 0;
}





// MEMEOSIATION
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Recursive function with memoization
int f(int i, int n, int k, vector<int> &arr, vector<int> &dp) {
    if (i == n) return 0;
    if (dp[i] != -1) return dp[i];

    int len = 0, maxVal = -1e9, maxAns = -1e9;
    for (int j = i; j < min(n, i + k); j++) {
        len++;
        maxVal = max(maxVal, arr[j]);
        int sum = len * maxVal + f(j + 1, n, k, arr, dp);
        maxAns = max(maxAns, sum);
    }

    return dp[i] = maxAns;
}

int main() {
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int n = arr.size(), k = 3;
    vector<int> dp(n, -1);
    int maxSum = f(0, n, k, arr, dp);
    cout << "The max partition sum is: " << maxSum << endl;
    return 0;
}




// TABULATION

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int n = arr.size(), k = 3;
    vector<int> dp(n + 1, 0); // dp[n] = 0 (base case)

    for (int i = n - 1; i >= 0; i--) {
        int len = 0, maxVal = -1e9, maxAns = -1e9;
        for (int j = i; j < min(n, i + k); j++) {
            len++;
            maxVal = max(maxVal, arr[j]);
            int sum = len * maxVal + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        dp[i] = maxAns;
    }

    cout << "The max partition sum is: " << dp[0] << endl;
    return 0;
}
