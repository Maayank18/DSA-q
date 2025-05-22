// what this problems ask us is that 
// we are given an array and we have to find all such 
// pair where the left elemnt is alwasy greater than right elemnt 
// i < j && arr[i] > arr[j]


// BRUTE FORCE SOLUTION - Generate all the possible pairs a
// and apply the condition to find the final count
// TC -> O(N^2)
// SC -> O(1)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int f(vector<int> &arr){
    int n = arr.size();
    int cnt = 0;

    for(int i = 0; i<n-1; i++){
        for(int j = i+1; j<n; j++){
            if( i<j && arr[i] > arr[j]){
                cnt++;
            }
        }
    }

    return cnt;
}

int main(){
    vector<int> arr = {5,3,2,4,1};
    int countInversion = f(arr);
    cout<<" total such pairs are : "<<countInversion<<endl;
    return 0;
}