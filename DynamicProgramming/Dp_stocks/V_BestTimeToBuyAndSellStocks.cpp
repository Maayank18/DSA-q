// this code is also similar to thta of other stock problem 
// major difference is after selling stock there will be a cool down of 1 day
//  and only after that you will be able to buys
//  again we have to maximize the profit
// eg .{4,5,0,4,10}
// buying 4 selling 5 if sell at 5 we cant buys 0 as it is the cool down day 

#include<iostream>
#include<vector>
using namespace std;

int f(int idx, int n, vector<int> &stocks, int buy){

    int maxP = 0;

    // base case
    if( idx >= n){
        return 0;
    }

    // when we can buys the stock
    if(buy){
        int takeIt = -stocks[idx] + f(idx + 1, n, stocks,0);
        int notTakeIt = 0 + f(idx + 1,n,stocks,1);
        maxP = max(maxP,max(takeIt,notTakeIt));
    }

    else{  // if i have to sell it 
        int sellIt = stocks[idx] + f(idx + 2,n,stocks,1); // idx + 1 for next day + 1 for cool down period 
        int notSellIt = 0 + f(idx+1,n,stocks,0);
        maxP = max(maxP,max(sellIt,notSellIt));
    }

    return maxP;
}

int main(){
    int n = 5;
    vector<int> stocks = {4,9,0,4,10};
    int buy = 1; // initially we ould buys
    int maxiProfit = f(0,n,stocks,buy);
    cout<<" the max profit after cooling down is : "<<maxiProfit<<endl;
    return 0;
}





// WAY 2 OF SOLVING IS MEMOISATION 

#include<iostream>
#include<vector>
using namespace std;

int f(int idx, int n, vector<int>& stocks, int buy, vector<vector<int>>& dp) {
    if (idx >= n) return 0;

    if (dp[idx][buy] != -1) return dp[idx][buy];

    int maxProfit = 0;
    if (buy) {
        int take = -stocks[idx] + f(idx + 1, n, stocks, 0, dp);
        int skip = f(idx + 1, n, stocks, 1, dp);
        maxProfit = max(take, skip);
    } else {
        int sell = stocks[idx] + f(idx + 2, n, stocks, 1, dp);
        int hold = f(idx + 1, n, stocks, 0, dp);
        maxProfit = max(sell, hold);
    }

    return dp[idx][buy] = maxProfit;
}

int main() {
    vector<int> stocks = {4, 9, 0, 4, 10};
    int n = stocks.size();
    vector<vector<int>> dp(n + 2, vector<int>(2, -1)); // to handle idx+2
    int maxProfit = f(0, n, stocks, 1, dp);
    cout << "Max profit with cooldown (Memoization): " << maxProfit << endl;
    return 0;
}






//  WAY 3 OF SOLVING IS TABULATION


#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> stocks = {4, 9, 0, 4, 10};
    int n = stocks.size();

    vector<vector<int>> dp(n + 2, vector<int>(2, 0)); // +2 to avoid bounds at idx+2

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int buy = 0; buy <= 1; buy++) {
            int profit = 0;
            if (buy) {
                int take = -stocks[idx] + dp[idx + 1][0];
                int skip = dp[idx + 1][1];
                profit = max(take, skip);
            } else {
                int sell = stocks[idx] + dp[idx + 2][1];
                int hold = dp[idx + 1][0];
                profit = max(sell, hold);
            }
            dp[idx][buy] = profit;
        }
    }

    cout << "Max profit with cooldown (Tabulation): " << dp[0][1] << endl;
    return 0;
}
