int solve(int arr[],vector<int>&dp, int n) {

   if(n == 0){
    return arr[0];
   } 

   if(n<0){
    return 0;
   }

   if(dp[n] != -1){
    return dp[n];
   }

   int include = arr[n] + solve(arr,dp,n-2);
   int exclude = 0 + solve(arr,dp,n-1);

   return dp[n] = max(include,exclude);
}