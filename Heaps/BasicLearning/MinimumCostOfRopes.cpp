// our aim is to find the minimum cost of rope what that means is 
// example we have 4 ropes = {4,3,2,6};
// each rope has a cost of combining 
// and in order to minimise the cost we would alaways combine the minimum ropes
// 2 + 3 = 5 .... ropes left 5,4,6
// 4 + 5 = 9 .... ropes left 9,6
// 9 + 6 = 15 .... ropes left is 15
//  so our final answer is 5 + 9 + 15 = 29


// we wont use the funda of sorting because it will take as bad as n^2 
// due first performing and external insertig 

// we will use simple priority queue method that too MIN HEAP
// which will be as good as nlogn

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding(vector<int> &arr){
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    int cost = 0; // our answer

    for(int i = 0; i<n; i++){
        pq.push(arr[i]);
    }

    while(pq.size() > 1){
        int firstRope = pq.top();
        pq.pop();
        // int secondRope = pq.top();
        firstRope = firstRope + pq.top(); 
        pq.pop();

        cost = cost + firstRope;
        pq.push(firstRope);
    }
    return cost;
}

int main(){
    vector<int> arr = {4,3,2,6};
    int minCost = finding(arr);
    cout<<" the minimum cost is : "<<minCost<<endl;
    return 0;
}