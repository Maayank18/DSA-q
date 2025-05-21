// This question aims to find the sum array whose sum equal to k our aims will be 
// counting the number of sub arrays whose sum = k



// BRUTE FORCE SOLUTION 
// TC -> O(N^2)
// SC -> O(1)
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int f(vector<int> &arr, int k){
//     int n = arr.size();

//     int cnt = 0;
//     for(int i = 0; i<n; i++){
//         int sum = 0;
//         for(int j = i; j<n; j++){
//             sum+=arr[j];

//             if(sum == k){
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }

// int main(){
//     vector<int> arr = {1,2,3,-3,1,1,1,4,2,-3};
//     int k = 3;
//     int count = f(arr,k);
//     cout<<" the total sub arrays with sum k are : "<<count<<endl;
//     return 0;
// }




// THE MOST OPTIMAL WAY OF SOLVING THIS WOULD BE USING A APPROACH 
//  WHERE WE WILL BE USING PREFIX SUM  + HASHING 

// #imp 1 -> target = prefix[j] - prefix[i-1];
// #imp 2 -> prefix[i-1] = prefix[j] - target;
// #imp 3 -> i < j always 

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int f(vector<int> &arr, int k, vector<int> &prefixSum){
    int n = arr.size();
    int count = 0;

    // logic for prefix sum
    prefixSum[0] = arr[0];
    for(int i = 1; i<n; i++){
        prefixSum[i] = arr[i] + prefixSum[i-1];
    }

    // stroing (prefixSum , its frequency)
    unordered_map<int,int> m;
    for(int j = 0; j<n; j++){
        if(prefixSum[j] == k){
            count++;
        }

        int val = prefixSum[j] - k;
        if(m.find(val) != m.end()){
            count += m[val];
        }

        if(m.find(prefixSum[j]) == m.end()){
            m[prefixSum[j]] = 0;
        }
        m[prefixSum[j]]++;
    }
    return count;
}

int main(){
    vector<int> arr = {9,4,0,20,3,10,5};
    int k = 33;
    int size = arr.size();
    vector<int> prefixSum(size,0);
    int count = f(arr,k,prefixSum);
    cout<<" the number of sub array with sum k : "<<count<<endl;
    return 0;
}