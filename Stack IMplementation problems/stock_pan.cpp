// This problem basically aims to find the maximum possible days when the stock 
// prize is less than current day stock prize by using a counter or and 
// we have to consider the current day as well
// [100, 80, 60, 70, 60, 75, 85]


// BRUTE FORCE SOLUTION -> Where basically we will be working on the two for
// loops and addressing each and every stock prize
//TIME COMPLEXITY -> O(N)*O(total less days )
// SPACE COMPLEXITY -> O(N)
// #include<iostream>
// #include<vector>
// using namespace std;

// vector<int> lessStock(vector<int> arr){
//     int n = arr.size();
//     vector<int> ans(n,1);
//     int count = 0;

//     for( int i = 0; i<n; i++){
//         count = 1;
//         for( int j = i-1; j>=0; j--){
//             if(arr[j]<arr[i]){
//                 count++;
//             }
//         }
//         ans[i] = count;
//     }
//     return ans;
// }

// int main(){
//     vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
//     vector<int> result = lessStock(arr);
//     for(int num : result){
//         cout<<num<<"";
//     }
//     return 0;
// }


//OPTIMAL SOLUTION - The problem that is occuring is TC O(n^2) and we somehow
// have to find the way to optimise it and that can be done when we can do 
// something so here we will use stack data structure
// Use previous greater element

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> StockPan(vector<int> arr){
    int n = arr.size();
    stack<int> st; // storing the indices
    vector<int> ans(n);

    for(int i = 0; i<n; i++){
        while(!st.empty() && arr[st.top()]<=arr[i]){
            st.pop();
        }

        ans[i] = (st.empty())?1:i-st.top();

        st.push(i);
    }
    return ans;
}

int main(){
    vector<int> arr = {100, 80, 60, 70, 60, 75, 85};
    vector<int> result = StockPan(arr);
    for(int num : result){
        cout<<num<<"";
    }
    return 0;
}