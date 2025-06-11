// this question is magician and the chocolate
// our aim is to find the max number of chocolate  that 
// could be eaten in a given number of time 
// ex arr = {2,4,6,8,10} are number of chocolates
// the only twist is which ever chocolate you ate the magiciam will fill that by hlf of it again 

// considering time  = 5;
// step 1 -> eat 10 -> return 5  = 10
// step 2 -> eat 8 -> return 4 = 8
// step 3 -> eat 6 -> return 3 = 6
// step 4 -> eat 5 -> return the floor value = 2 = 5
// step 5 -> eat 4 -> return 2 = 4
// total chocolate eaten in 5 seconds are -> 10 + 8 + 6 + 5 + 4 = 33

// we can use a max priority queue


// if we use the array strtegy and shifting and right positioning 
//  time complexity becomes -> (time*n + nlogn)

// but in our priority queue apprsoch 
// TIME COMPLEXITY IS -> O(time * logn)

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding( vector<int> &arr, int time){
    int n = arr.size();
    // max heap priority queue
    priority_queue<int> pq;

    // all choclates inserted in our priority queue
    for(int i = 0; i<n; i++){
        pq.push(arr[i]);
    }

    int Maxchocolates = 0;

    while(time > 0 && !pq.empty()){
        int chocolates = pq.top();
        pq.pop();
        Maxchocolates += chocolates;
        pq.push(chocolates/2);
        time--;
    }
    return Maxchocolates;
}

int main(){
    vector<int> arr = {2,4,6,8,10};
    int time = 5;
    int maxChocolates = finding(arr,time);
    cout<<" the max number of choclates are : "<<maxChocolates<<endl;
    return 0;
}