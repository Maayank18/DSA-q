// this question aims is to find the row which has max number of 1 in it 
// if more than 1 row has max number of one return the min row number or 
// the row number which came first

// BRUTE FORCE APPRAOCH
// TC -> O(N X M)
// SC -> O(1)
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int f(vector<vector<int>>& mat){
//     int n = mat.size(); // number of rows
//     int m = mat[0].size(); // number of column
//     int rowIdx = -1;
//     int maxi = INT_MIN;
//     for(int i = 0; i<n; i++){
//         int count = 0;
//         for(int j = 0; j<m; j++){
//             count += mat[i][j];
//         }
//         if(count > maxi ){
//             maxi = count;
//             rowIdx = i;
//         }
//     }
//     return rowIdx;
// }

// int main(){
//     vector<vector<int>> mat = {{0,0,1,1,1},{0,0,0,0,0},{0,1,1,1,1},{0,0,0,0,0},{0,1,1,1,1}};
//     int rowNum = f(mat);
//     cout<<" the row with max ones : "<<rowNum<<endl;
//     return 0;
// }





// OPTIMAL SOLUTION -> binary search approach 
// here we can see that rows are in soretd order
// we cant cahnge or touch the rows but can touch the columns
// so that tc of m can be reduced
// if there is no one with atleast one 1 return -1;

// TC -> O(N X log base 2 m)
// SC -> O(1)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& arr, int n, int x){
    int low = 0; 
    int high = n-1;
    int ans = n;

    while(low<=high){
        int mid = low + (high-low)/2;

        // may be our answer is mid
        if(arr[mid] >= x){
            ans = mid;
            // look for more small index on left 
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    return ans;
}

int f(vector<vector<int>>& mat){
    int n = mat.size();
    int m = mat[0].size();
    int maxi = 0;
    int rowIdx = -1;

    for(int i = 0; i<n; i++){
        int countOne = m - lowerBound(mat[i],m,1); // total elements in rows - the index from where one is starting
        if(countOne > maxi){
            maxi = countOne;
            rowIdx = i;
        } 
    }
    return rowIdx;
}

int main(){
    vector<vector<int>> mat = {{0,0,1,1,1},{0,0,0,0,0},{0,1,1,1,1},{0,0,0,0,0},{0,1,1,1,1}};
    int rowNum = f(mat);
    cout<<" the row with max ones : "<<rowNum<<endl;
    return 0;
}