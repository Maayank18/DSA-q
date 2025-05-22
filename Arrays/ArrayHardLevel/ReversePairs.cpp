// this reverse array we can say is the continuation for COUNT INVERSION
// HERE OUR AIM WILL BE TO RETURN THE COUNT NUMBER OF PAIR WHERE
// 1. i < j && a[i] > 2xa[j] => left > right*2


// BRUTE FORCE SOLUTION -> generate all the pairs
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
            if(arr[i] > (2*arr[j])){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){
    vector<int> arr = {40,25,19,12,9,6,2};
    int reversePairs = f(arr);
    cout<<" the total count for reverse pair is : "<<reversePairs<<endl;
    return 0;
}





// A better or Optimal solution will again be opting
//  the MERGE SORT APPROACH AS USED IN MERGE SORT 