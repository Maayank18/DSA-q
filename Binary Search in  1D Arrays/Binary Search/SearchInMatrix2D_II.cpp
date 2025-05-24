// this is the continuation problem of seacrh in matrix 1
// here if the element exist int he matrix we have to retrun the 
// cordinate of its row and columns 
// if we dont find we return -1,-1



// BRUTE FORCE SOLUTION
// TC -> O(n x m)
// SC -> O(1)
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// pair<int,int> f(vector<vector<int>> &mat, int target){
//     int n = mat.size();
//     int m = mat[0].size();

//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<m; j++){
//             if(mat[i][j] == target){
//                 return {i,j};
//             }
//         }
//     }
//     return {-1,-1};
// }

// int main(){
//     vector<vector<int>> mat = {{1,4,7,11,15},
//                                {2,5,8,12,19}, 
//                                {3,6,9,16,22},
//                                {10,13,14,17,24},
//                                {18,21,23,26,30} };
//     int target = 14;
//     pair<int,int> result = f(mat,target);
//     cout<<" the row is : "<<result.first<<" and columns is : "<<result.second<<endl;
//     return 0;

// }





// BETTER SOLUTION 
// TC -> O(n x log base 2 m)
// SC -> O(1)

#include<iostream>
#include<vector>
using namespace std;

pair<int,int> f2(vector<int> &row, int rowIndex, int m, int target){
    int low = 0, high = m - 1;

    while(low <= high){
        int mid = low + (high - low)/2;
        if(row[mid] == target){
            return {rowIndex, mid};
        } else if(row[mid] > target){
            high = mid - 1;
        } else{
            low = mid + 1;
        }
    }

    return {-1, -1}; // Not found
}

pair<int,int> f(vector<vector<int>> &mat, int target){
    int n = mat.size();
    int m = mat[0].size();

    for(int i = 0; i < n; i++){
        // Check if the target can be in this row
        if(mat[i][0] <= target && target <= mat[i][m-1]){
            pair<int,int> ans = f2(mat[i], i, m, target);
            if(ans.first != -1) return ans;
        }
    }

    return {-1, -1}; // Not found
}

int main(){
    vector<vector<int>> mat = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    int target = 14;
    pair<int,int> result = f(mat, target);

    cout << "The row is: " << result.first << " and column is: " << result.second << endl;
    return 0;
}






// OPTIMAL SOLUTION 

#include<iostream>
#include<vector>
using namespace std;

pair<int,int> f(vector<vector<int>> &mat, int target) {
    int n = mat.size();
    int m = mat[0].size();

    int i = 0, j = m - 1; // Start from top-right

    while(i < n && j >= 0) {
        if(mat[i][j] == target) {
            return {i, j};
        } else if(mat[i][j] > target) {
            j--; // Move left
        } else {
            i++; // Move down
        }
    }
    return {-1, -1}; // Not found
}

int main() {
    vector<vector<int>> mat = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    
    int target = 14;
    pair<int, int> result = f(mat, target);

    cout << "The row is: " << result.first << " and column is: " << result.second << endl;

    return 0;
}
