#include<iostream>
#include<map>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    int arr[n];
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    map<int,int> mpp;
    for(auto it : arr){
        mpp[it]++;
    }

    int maxx_occured = INT_MIN;
    int num_max;
    int minn_occured = INT_MAX;
    int num_min;

    for(auto it : mpp){
        if (it.second > maxx_occured) {
                maxx_occured = it.second;
                num_max = it.first;
            }

        // Minimum frequency
        if (it.second < minn_occured) {
            minn_occured = it.second;
            num_min = it.first;
        }
    }

    cout << "The element with the highest frequency is " << num_max << " with " << maxx_occured << " occurrences." << endl;
    cout << "The element with the lowest frequency is " << num_min << " with " << minn_occured << " occurrences." << endl;
}