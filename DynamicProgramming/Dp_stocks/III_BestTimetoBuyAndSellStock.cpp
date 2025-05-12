// This problem is a type of continuation only having a slight modefication
// here we can do atmost 2 transaction ie. is BSBS
// zyada se zyada 2 buys and 2 sells 

// WAY 1 OF DOING IT RECUSRION 
// TC -> exponential
//  SC -> O(n) recursion stack space
#include<iostream>
#include<vector>
using namespace std;

int f(int idx,int n, vector<int> &stocks,int buy, int capacity){


    // base case 1 if days are over 
    if(idx == n) return 0;
    // base case 2 if maximum capacity has been reached
    if(capacity == 0) return 0;

    int maxP = 0;

    if(buy){// if i have allowance of buying it 
        int BuyIt = -stocks[idx] + f(idx+1,n,stocks,0,capacity);
        int notBuyIt = 0 + f(idx+1,n,stocks,1,capacity);
        maxP = max(maxP,max(BuyIt,notBuyIt));

    }else{ // where i am selling the things up
        int sellIt = stocks[idx] + f(idx+1,n,stocks,1,capacity-1); // capacity decreases
        int notSellIT = 0 + f(idx+1,n,stocks,0,capacity);
        maxP = max(maxP,max(sellIt,notSellIT));
    }

    return maxP;

}

int main(){
    int n = 8;
    vector<int> stocks = {3,3,5,0,0,3,1,4};
    int capacity = 2; // atmost 2 transaction
    int buy = 1; // intially we could buy anything
    int maxProfit = f(0,n,stocks,buy,capacity);
    cout<<" the max profit aquired is : "<<maxProfit<<endl;
    return 0;
}





// WAY 2 OF DOING IT MEMOISATION

#include<iostream>
#include<vector>
using namespace std;

int f(int idx, int n, vector<int> &stocks, int buy, int cap, vector<vector<vector<int>>> &dp){
    if(idx == n || cap == 0) return 0;
    if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap];

    int profit = 0;

    if(buy){
        int BuyIt = -stocks[idx] + f(idx+1, n, stocks, 0, cap, dp);
        int notBuyIt = f(idx+1, n, stocks, 1, cap, dp);
        profit = max(BuyIt, notBuyIt);
    } else {
        int SellIt = stocks[idx] + f(idx+1, n, stocks, 1, cap - 1, dp);
        int notSellIt = f(idx+1, n, stocks, 0, cap, dp);
        profit = max(SellIt, notSellIt);
    }

    return dp[idx][buy][cap] = profit;
}

int main(){
    vector<int> stocks = {3,3,5,0,0,3,1,4};
    int n = stocks.size();
    int cap = 2;
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(cap + 1, -1)));
    cout << "Max Profit (Memoization): " << f(0, n, stocks, 1, cap, dp) << endl;
    return 0;
}




// WAY 3 OF DOING IT TABULATION 

#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();

    // 3D DP array: dp[day][buy][cap]
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));

    // Base case already handled by default initialization to 0:
    // When day == n → profit is 0
    // When cap == 0 → profit is 0

    for(int idx = n-1; idx >= 0; idx--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int cap = 1; cap <= 2; cap++) {
                if(buy == 1) {
                    dp[idx][buy][cap] = max(
                        -prices[idx] + dp[idx+1][0][cap],  // Buy
                        0 + dp[idx+1][1][cap]              // Skip
                    );
                } else {
                    dp[idx][buy][cap] = max(
                        prices[idx] + dp[idx+1][1][cap-1], // Sell
                        0 + dp[idx+1][0][cap]              // Skip
                    );
                }
            }
        }
    }

    // Start from day 0, with ability to buy, and 2 transactions allowed
    return dp[0][1][2];
}

int main() {
    vector<int> prices = {3,3,5,0,0,3,1,4};
    cout << "Max Profit (Tabulation, Striver Style): " << maxProfit(prices) << endl;
    return 0;
}

