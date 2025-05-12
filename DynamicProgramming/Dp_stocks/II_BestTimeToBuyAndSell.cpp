// Stock sell problem 2
// This problem aims to find the max profit again only twist is 
// we can buys and sell as many stock as we want with little condition
// that is second should occur only after first sell
//  it can be bsbsbsbs but not bbbsssbbss
// also to make sure can we buy or not we will amitain another variable BUY


// WAY 1 OF DOING IT IS RECUSION
//  TC -> O(2^N) = due to take not take cases we have
//  SC -> O(N) = Auxillary Stack Space
// #include<iostream>
// #include<vector>
// using namespace std;

// int f(int i,int n, vector<int> &stocks, int buy){
//     int maxP = 0;

//     // base case
//     // what if i == n and we still hold a stock will will nullify it
//     if(i == n) return 0;

//     if(buy){ // if we can buys we will have two choices to make whteher to take ornot take
//         int buysIT = -stocks[i] + f(i+1,n,stocks,0);
//         int notBUYit = 0 + f(i+1,n,stocks,1);
//         maxP = max(maxP,max(buysIT,notBUYit));

//     }else{ // if we cant buy we have liberty to sell and here also we may or may not sell
//         int sellIT = stocks[i] + f(i+1,n,stocks,1);
//         int notSELLit = f(i+1,n,stocks,0);
//         maxP = max(maxP,max(sellIT,notSELLit));
//     }

//     return maxP;
// }

// int main(){
//     int n = 6;
//     vector<int> stocks = {7,1,5,3,6,4};
//     int buy = 1; // initially buy would be one as we have nothing and we can buy 
//     int maxProfit = f(0,n,stocks,buy);
//     cout<<" the max Profit is : "<<maxProfit<<endl;
//     return 0;
// }






// Way 2 of doin it is memoisation as it has over lapping subsequence
// TC -> O( n x 2)
//  SC -> O( nx 2) + O(N)
// #include<iostream>
// #include<vector>
// using namespace std;

// int f(int i,int n, vector<int> &stocks, int buy, vector<vector<int>> &dp){
//     int maxP = 0;

//     // base case
//     // what if i == n and we still hold a stock will will nullify it
//     if(i == n) return 0;

//     // base case 2
//     if(dp[i][buy] != -1) return dp[i][buy];

//     if(buy){ // if we can buys we will have two choices to make whteher to take ornot take
//         int buysIT = -stocks[i] + f(i+1,n,stocks,0,dp);
//         int notBUYit = 0 + f(i+1,n,stocks,1,dp);
//         maxP = max(maxP,max(buysIT,notBUYit));

//     }else{ // if we cant buy we have liberty to sell and here also we may or may not sell
//         int sellIT = stocks[i] + f(i+1,n,stocks,1,dp);
//         int notSELLit = f(i+1,n,stocks,0,dp);
//         maxP = max(maxP,max(sellIT,notSELLit));
//     }

//     return dp[i][buy] =  maxP;
// }

// int main(){
//     int n = 6;
//     vector<int> stocks = {7,1,5,3,6,4};
//     int buy = 1; // initially buy would be one as we have nothing and we can buy 
//     vector<vector<int>> dp(n,vector<int>(2,-1));
//     int maxProfit = f(0,n,stocks,buy,dp);
//     cout<<" the max Profit is : "<<maxProfit<<endl;
//     return 0;
// }






//  WAY 3 OF DOING IT IS TABULATION 
// TC -> O(2 x n)
// SC -> O( 2 x n)

// #include<iostream>
// #include<vector>
// using namespace std;

// int f(int i,int n, vector<int> &stocks, int buy, vector<vector<int>> &dp){
//     // base case 
//     dp[n][0] = dp[n][1] = 0;
    

//     for( int i = n-1; i>=0 ; i--){
//         for(int buy = 0; buy<=1; buy++){
//             int maxP = 0;
//             if(buy){ // if we can buys we will have two choices to make whteher to take ornot take
//                 int buysIT = -stocks[i] + dp[i+1][0];
//                 int notBUYit = 0 + dp[i+1][1];
//                 maxP = max(maxP,max(buysIT,notBUYit));

//             }else{ // if we cant buy we have liberty to sell and here also we may or may not sell
//                 int sellIT = stocks[i] + dp[i+1][1];
//                 int notSELLit = dp[i+1][0];
//                 maxP = max(maxP,max(sellIT,notSELLit));
//             }
//             dp[i][buy] =  maxP;
//         }
//     }
//     return dp[0][1]; // starting at day 0 with permission to buy
// }

// int main(){
//     int n = 6;
//     vector<int> stocks = {7,1,5,3,6,4};
//     int buy = 1; // initially buy would be one as we have nothing and we can buy 
//     vector<vector<int>> dp(n+1,vector<int>(2,0));
//     int maxProfit = f(0,n,stocks,buy,dp);
//     cout<<" the max Profit is : "<<maxProfit<<endl;
//     return 0;
// }





//  WAY 4 OF DOING IT IS SPACE OPTIMISATION

#include<iostream>
#include<vector>
using namespace std;

int f(int i,int n, vector<int> &stocks, int buy, vector<int> &ahead, vector<int> &curr){
    // base case 
    ahead[0] = ahead[1] = 0;
    

    for( int i = n-1; i>=0 ; i--){
        for(int buy = 0; buy<=1; buy++){
            int maxP = 0;
            if(buy){ // if we can buys we will have two choices to make whteher to take ornot take
                int buysIT = -stocks[i] + ahead[0];
                int notBUYit = 0 + ahead[1];
                maxP = max(maxP,max(buysIT,notBUYit));

            }else{ // if we cant buy we have liberty to sell and here also we may or may not sell
                int sellIT = stocks[i] + ahead[1];
                int notSELLit = ahead[0];
                maxP = max(maxP,max(sellIT,notSELLit));
            }
            curr[buy] =  maxP;
        }
        ahead = curr;
    }
    return ahead[1]; // starting at day 0 with permission to buy
}

int main(){
    int n = 6;
    vector<int> stocks = {7,1,5,3,6,4};
    int buy = 1; // initially buy would be one as we have nothing and we can buy 
    vector<int> ahead(2,0), curr(2,0);
    int maxProfit = f(0,n,stocks,buy,ahead,curr);
    cout<<" the max Profit is : "<<maxProfit<<endl;
    return 0;
}