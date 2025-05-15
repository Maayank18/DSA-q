// What this problem ask us to do is we are given an array of different balloons
//  eg = [3,1,5,8]
// if we pop let us suppose 5 so total coins earned is 1 x 5 x 8
//  our task is maximise the number of coins
// here we work in opposite manner we will bursting that firdt which we think is our last guy


// WAY 1 OF DOING IS RECUSION
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> &balloons){

    if(i>j){
        return 0;
    }

    int maxi = -1e9;
    for(int index = i; index<=j ; index++){
        int coins = balloons[i-1]*balloons[index]*balloons[j+1] + f(index+1,j,balloons) + f(i,index-1,balloons);
        maxi = max(maxi,coins);
    }
    return maxi;
}

int main(){
    int n = 4;
    vector<int> balloons = {3,1,5,8};
    balloons.insert(balloons.begin(),1);
    balloons.push_back(1);
    int m = balloons.size();
    int maxCoins = f(1,n,balloons);
    cout<<" the max coins that we can get is : "<<maxCoins<<endl;
    return 0;
}




// Way 2 of doing is memeoisation

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int f(int i, int j, vector<int> &balloons, vector<vector<int>> &dp){

    if(i>j){
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];
    int maxi = -1e9;
    for(int index = i; index<=j ; index++){
        int coins = balloons[i-1]*balloons[index]*balloons[j+1] + f(index+1,j,balloons,dp) + f(i,index-1,balloons,dp);
        maxi = max(maxi,coins);
    }
    return dp[i][j] = maxi;
}

int main(){
    int n = 4;
    vector<int> balloons = {3,1,5,8};
    balloons.insert(balloons.begin(),1);
    balloons.push_back(1);
    int m = balloons.size();
    vector<vector<int>> dp(m,vector<int>(m,-1));
    int maxCoins = f(1,n,balloons,dp);
    cout<<" the max coins that we can get is : "<<maxCoins<<endl;
    return 0;
}







// way 3 of doing is tabulation 

#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int maxCoinsTabulation(vector<int> &balloons) {
    int n = balloons.size();
    // dp[i][j] = max coins from bursting balloons between i and j (exclusive)
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // length represents the size of the current subarray considered
    for (int length = 1; length <= n - 2; length++) {
        for (int i = 1; i <= n - length - 1; i++) {
            int j = i + length - 1;
            int maxi = 0;
            for (int index = i; index <= j; index++) {
                int coins = balloons[i - 1] * balloons[index] * balloons[j + 1]
                            + dp[i][index - 1] + dp[index + 1][j];
                maxi = max(maxi, coins);
            }
            dp[i][j] = maxi;
        }
    }

    return dp[1][n - 2];
}

int main() {
    vector<int> balloons = {3, 1, 5, 8};
    balloons.insert(balloons.begin(), 1);
    balloons.push_back(1);
    int maxCoins = maxCoinsTabulation(balloons);
    cout << "The max coins that we can get is: " << maxCoins << endl;
    return 0;
}
