// approach first you have you buy a stock then only you can sell it
// keep on updating thebuying number after iterating through every number
//basic brute force approach
// in this method we are BUYING IT ONCE AND SELLING IT ONCE 

#include<iostream>
using namespace std;

int sell( int arr[], int n){
    int max_profit = 0;
    int buy = arr[0];
    for( int i = 1; i<n; i++){
        int cost = arr[i] - buy;
        max_profit = max(max_profit,cost);
        buy = min(arr[i],buy);
    }
    return max_profit;
}

int main(){
    int n = 6;
    int arr[6] = {7,1,4,6,2,3};

    int max_profit = sell(arr,n);

    cout<<" the maximum profit is : "<<max_profit<<endl;
    return 0;
}