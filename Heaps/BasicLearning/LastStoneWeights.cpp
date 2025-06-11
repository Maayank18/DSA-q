// our problem is last stone weight problem 
// this problem aims to return the weight of the stone that is last one to stand
// we will select the two biggest stone adn clash them 
// eg. 7 <-> 8  , so 7 being small will be destroyed completely 
//  and a part of 8 will be destroyed and we will be lft with the 1kg weight 
//  again finding the biggest weight and doing the needfull
//  if any where both our zeroes dont need to do anything and whenevr single stone is left retrun it 

//  eg arr = {2,7,4,1,8,1}
// first  7 -- 8 -> 1 = {2,1,4,1,1}
// second 4 -- 2 -> 2 = {2,1,1,1}
// third 2 -- 1 -> 1 = {1,1,1}
// fourth 1 -- 1 -> 0 = {1} return 1

// our best approach can be using the max heap appraoch
// using stl -> nlogn 
// every insertion and deletion take logn 

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding(vector<int> &arr){
    int n = arr.size();
    priority_queue<int> pq; // max heap

    for(int i = 0; i<n; i++){
        pq.push(arr[i]);
    }

    while(pq.size() > 1){
        int firstmax = pq.top();
        pq.pop();
        int secondmax = pq.top();
        pq.pop();
        int clashDiff = firstmax - secondmax;

        if(clashDiff == 0){
            continue;
        }else{
            pq.push(clashDiff);
        }
    }

    return pq.top();
}

int main(){
    vector<int> arr = {2,7,4,1,8,1};
    int lastStoneWeight = finding(arr);
    cout<<" the weight of last stone standing is : "<<lastStoneWeight<<endl;
    return 0;
}