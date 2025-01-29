// Largest Rectangle in Histogram – Explanation with Diagram
// The problem requires us to find the largest rectangular area that can be formed 
// within a histogram, given an array where each element represents the height of a bar.
// Initial Histogram:
//          |         
//          |   |     
//      |   |   |     
//      |   |   |     
//      |   |   |   |
//   |  |   |   |   |  |
//   --------------------
//   2  1   5   6   2   3


// BRUTE FORCE SOLUTION - where we gonna use the 2 loops for iterating and 
// calculating and storing each and every value of rectangle area 

// TIME COMPLEXITY -> O(N^2)
// SPACE COMPLEXITY -> O(1)

// #include<iostream>
// #include<bits/stdc++.h>
// #include<vector>
// using namespace std;

// int maxArea( vector<int> heights){
//     int n = heights.size();
//     int maxA = INT_MIN;
//     for(int i = 0; i<n; i++){
//         int minHeight = heights[i];
//         for( int j = i; j<n; j++){
//             minHeight = min(minHeight,heights[j]);
//             maxA = max(maxA, minHeight*(j-i+1));
//         }
//     }
//     return maxA;
// }

// int main(){
//     vector<int> arr = {2,1,5,6,2,3};
//     int maximumarearectangle = maxArea(arr);
//     cout<<" max area rectangle : "<<maximumarearectangle<<endl;
//     return 0;
// }


// BETTER SOLUTION ->

#include<iostream>
#include<stack>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int findNse(int index, vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> nse(n, n); // Default to 'n' if no NSE is found

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            nse[i] = st.top(); // Store the index of NSE
        }

        st.push(i);
    }
    return nse[index];
}

// Function to find the index of the previous smaller element
int findPse(int index, vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> pse(n, -1); // Default to '-1' if no PSE is found

    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] >= arr[i]) {
            st.pop();
        }

        if (!st.empty()) {
            pse[i] = st.top(); // Store the index of PSE
        }

        st.push(i);
    }
    return pse[index];
}


int maxArea (vector<int> arr){
    int n = arr.size();
    int maxA = 0;
    for( int i = 0; i<n; i++){
        int nse = findNse(i,arr);
        int pse = findPse(i,arr);
        maxA = max(maxA, arr[i]*(nse-pse-1));
    }
    return maxA;
}


int main(){
    vector<int> arr = {2,1,5,6,2,3};
    int maximumarearectangle = maxArea(arr);
    cout<<" max area rectangle : "<<maximumarearectangle<<endl;
    return 0;
}
