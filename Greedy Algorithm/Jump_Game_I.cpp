// Jump Game I - Greedy Algorithm
// Problem Statement:
// Given an array of non-negative integers nums, where each element represents your 
// maximum jump length at that position, determine if you can reach the last index 
// starting from the first index.
// CONSIDERING ONLY NON NEGATIVE INTEGERS

// Input: nums = [2, 3, 1, 1, 4]
// Output: return TRUE

#include<iostream>
#include<vector>
using namespace std;

bool CanIreach(vector<int> arr){
    int n = arr.size();
    int maxIdx = 0;

    for(int i = 0; i<n; i++){
        if(i>maxIdx) return false;

        maxIdx = max(maxIdx, i+arr[i]);
    }
    return true;
}

int main(){
    vector<int> arr = {2, 3, 1, 1, 4};
    bool CanI = CanIreach(arr);
    cout<<" Was i able to reach the final index : "<<CanI<<endl;
    return 0;
}
