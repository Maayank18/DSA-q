// the question aims to ask to maximize the profit = sell - bought should max
// in stock problem you hav eto buys first only then you could sell
// why this comes under DP = because when we are againa d again checking our currentMinimum 
// we are again and again remembering the past hence DP
//  TC -> O(N)
// SC -> O(1)

#include<iostream>
#include<vector>
using namespace std;

int f(int n, vector<int> &stock){
    int maxP = 0;
    int currentMinimum = stock[0];
    for(int i = 1; i<n; i++){
        int profit = stock[i] - currentMinimum;
        maxP = max(maxP,profit);
        currentMinimum = min(currentMinimum,stock[i]); // DP step
    }
    return maxP;
}

int main(){
    int n = 6;
    vector<int> stock = {7,1,5,3,6,4};
    int maxProfit = f(n-1,stock);
    cout<<" the max profit is : "<<maxProfit<<endl;
    return 0;
}