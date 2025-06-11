// our problem is basically asking us about maximising the profit
// given arr of number of differetn costinf seats empty 
// eg arr = {6,4,2,3} are the number of seats remaing the each seat cost same as the seat number 
// we have remaingseat  =5 which we could sell 
// and here is the game of maximising the profit 

// for given example our answer is 6 + 5 + 4 + 4 + 3 = 22

// tc -> nlogn 
// sc -> o(n)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding(vector<int> &arr, int remainingSeats){
    int n = arr.size();
    priority_queue<int> pq;

    for(int i = 0; i<n; i++){
        pq.push(arr[i]);
    }

    int maxiProfit = 0;

    while( remainingSeats > 0 && !pq.empty()){
        int profit = pq.top();
        pq.pop();
        maxiProfit += profit;

        if(profit - 1 > 0){
            pq.push(profit-1);
        }
        remainingSeats--;
    }
    return maxiProfit;
}

int main(){
    vector<int> arr = {6,4,2,3};
    int remainingSeats = 5;
    int maxProfit = finding(arr,remainingSeats);
    cout<<" out max profit will be : "<<maxProfit<<endl;
    return 0;
}