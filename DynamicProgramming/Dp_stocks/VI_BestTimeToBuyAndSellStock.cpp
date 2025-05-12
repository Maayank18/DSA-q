// this another set of problem for stock sell and buy 
// it say that whenevr we sell a stock we need to pay some fees

// WAY 1 OF DOING IT IS RECUSRION
#include<iostream>
#include<vector>
using namespace std;

int f(int idx, int n, vector<int> &stocks, int buy,int fees){

    int maxP = 0;

    // base case
    if( idx >= n){
        return 0;
    }

    // when we can buys the stock
    if(buy){
        int takeIt = -stocks[idx] + f(idx + 1, n, stocks,0,fees);
        int notTakeIt = 0 + f(idx + 1,n,stocks,1,fees);
        maxP = max(maxP,max(takeIt,notTakeIt));
    }

    else{  // if i have to sell it 
        int sellIt = stocks[idx] - fees + f(idx + 1,n,stocks,1,fees); // idx + 1 for next day + 1 for cool down period 
        int notSellIt = 0 + f(idx+1,n,stocks,0,fees);
        maxP = max(maxP,max(sellIt,notSellIt));
    }

    return maxP;
}

int main(){
    int n = 5;
    vector<int> stocks = {4,9,0,4,10};
    int buy = 1; // initially we ould buys
    int fees = 2;
    int maxiProfit = f(0,n,stocks,buy,fees);
    cout<<" the max profit after cooling down is : "<<maxiProfit<<endl;
    return 0;
}



// WAY 2 OF DOING IT MEMOISATION
#include<iostream>
#include<vector>
using namespace std;

int f(int idx, int n, vector<int> &stocks, int buy, int fees, vector<vector<int>> &dp){
    if (idx >= n) return 0;
    if (dp[idx][buy] != -1) return dp[idx][buy];

    int maxP = 0;
    if (buy) {
        int takeIt = -stocks[idx] + f(idx + 1, n, stocks, 0, fees, dp);
        int notTakeIt = f(idx + 1, n, stocks, 1, fees, dp);
        maxP = max(takeIt, notTakeIt);
    } else {
        int sellIt = stocks[idx] - fees + f(idx + 1, n, stocks, 1, fees, dp);
        int notSellIt = f(idx + 1, n, stocks, 0, fees, dp);
        maxP = max(sellIt, notSellIt);
    }

    return dp[idx][buy] = maxP;
}

int main(){
    vector<int> stocks = {4, 9, 0, 4, 10};
    int n = stocks.size();
    int fees = 2;

    // dp[n][2] for states: index and buy
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));

    int maxProfit = f(0, n, stocks, 1, fees, dp);
    cout << "Max profit with transaction fee (Memoization): " << maxProfit << endl;

    return 0;
}




// WAY 3 OF DOING IT IS TABULATION 
#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> stocks = {4, 9, 0, 4, 10};
    int n = stocks.size();
    int fees = 2;

    vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // dp[idx][buy]

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int buy = 0; buy <= 1; buy++) {
            int maxP = 0;
            if (buy) {
                int takeIt = -stocks[idx] + dp[idx + 1][0];
                int notTakeIt = dp[idx + 1][1];
                maxP = max(takeIt, notTakeIt);
            } else {
                int sellIt = stocks[idx] - fees + dp[idx + 1][1];
                int notSellIt = dp[idx + 1][0];
                maxP = max(sellIt, notSellIt);
            }
            dp[idx][buy] = maxP;
        }
    }

    cout << "Max profit with transaction fee (Tabulation): " << dp[0][1] << endl;

    return 0;
}

