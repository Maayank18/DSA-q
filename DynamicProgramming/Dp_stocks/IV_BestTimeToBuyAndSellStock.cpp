//  IT IS SAME III problem just that here k is not har encoded by 2 
//  k can be any number 






#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Recursive solution (Not optimized for large inputs)
int f(int idx, int n, vector<int> &stocks, int buy, int capacity) {
    if (idx == n || capacity == 0) return 0;

    int maxP = 0;

    if (buy) {
        int BuyIt = -stocks[idx] + f(idx+1, n, stocks, 0, capacity);  // Buy
        int notBuyIt = f(idx+1, n, stocks, 1, capacity);              // Don't Buy
        maxP = max(maxP, max(BuyIt, notBuyIt));
    } else {
        int SellIt = stocks[idx] + f(idx+1, n, stocks, 1, capacity - 1); // Sell
        int notSellIt = f(idx+1, n, stocks, 0, capacity);                // Don't Sell
        maxP = max(maxP, max(SellIt, notSellIt));
    }

    return maxP;
}

// Memoization solution (Using 3D DP)
int f_memo(int idx, int n, vector<int> &stocks, int buy, int cap, vector<vector<vector<int>>> &dp) {
    if (idx == n || cap == 0) return 0;
    if (dp[idx][buy][cap] != -1) return dp[idx][buy][cap];

    int profit = 0;

    if (buy) {
        int BuyIt = -stocks[idx] + f_memo(idx+1, n, stocks, 0, cap, dp);   // Buy
        int notBuyIt = f_memo(idx+1, n, stocks, 1, cap, dp);               // Don't Buy
        profit = max(BuyIt, notBuyIt);
    } else {
        int SellIt = stocks[idx] + f_memo(idx+1, n, stocks, 1, cap - 1, dp); // Sell
        int notSellIt = f_memo(idx+1, n, stocks, 0, cap, dp);               // Don't Sell
        profit = max(SellIt, notSellIt);
    }

    return dp[idx][buy][cap] = profit;
}

// Tabulation solution (Striver's style)
int maxProfitTabulation(vector<int>& prices, int k) {
    int n = prices.size();
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

    for (int idx = n-1; idx >= 0; idx--) {
        for (int buy = 0; buy <= 1; buy++) {
            for (int cap = 1; cap <= k; cap++) {
                if (buy == 1) {
                    dp[idx][buy][cap] = max(
                        -prices[idx] + dp[idx+1][0][cap],  // Buy
                        0 + dp[idx+1][1][cap]              // Don't Buy
                    );
                } else {
                    dp[idx][buy][cap] = max(
                        prices[idx] + dp[idx+1][1][cap-1], // Sell
                        0 + dp[idx+1][0][cap]              // Don't Sell
                    );
                }
            }
        }
    }

    return dp[0][1][k];  // Start from day 0, can buy, and k transactions allowed
}

int main() {
    vector<int> stocks = {3,3,5,0,0,3,1,4};
    int n = stocks.size();
    int k = 2;  // Maximum number of transactions

    // 1. Recursive Solution (not optimal for large inputs)
    cout << "Max Profit (Recursion): " << f(0, n, stocks, 1, k) << endl;

    // 2. Memoization Solution
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
    cout << "Max Profit (Memoization): " << f_memo(0, n, stocks, 1, k, dp) << endl;

    // 3. Tabulation Solution (Striver's Style)
    cout << "Max Profit (Tabulation, Striver's Style): " << maxProfitTabulation(stocks, k) << endl;

    return 0;
}



