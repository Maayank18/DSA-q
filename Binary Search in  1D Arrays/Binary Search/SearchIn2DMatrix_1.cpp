// we are given a 2d matrix in which elements are present in sorted order
// we will be given an target we need to check whetehr the 
// target is present in that matrix or not



// BRUTE FORCE 
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool f(vector<vector<int>> &mat, int target){
    int n = mat.size();
    int m = mat[0].size();

    bool flag = false;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(mat[i][j] == target ){
                flag = true;
            }
        }
    }
    return flag;
}

int main(){
    vector<vector<int>> mat = {{3,4,7,9},{12,13,16,18},{20,21,23,29}};
    int target = 23;
    bool doesExist = f(mat,target);
    cout<<" does the target exist in matrix : "<< doesExist<<endl;
    return 0;
}




// OPTIMAL APPROACH - binary search as elements are in sorted order
// TC -> O( N X log base 2 m)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool findTarget(vector<int> &mat, int m, int target){

    int low = 0; int high = m-1;
    
    while(low<=high){
        int mid = low  + (high - low)/2;

        if(mat[mid] == target){
            return true;
        }else if(mat[mid] > target ){
            high = mid -1;
        }else{
            low = mid + 1;
        }
    }
    return false;
}

bool f(vector<vector<int>> &mat, int target){
    int n = mat.size();
    int m = mat[0].size();

    // bool flag = false; could also be used 

    for(int i = 0; i<n; i++){

        // base case that in a row 1 element shoudl be less tha equal to target
        // and last elment should be greater tha equal to the target

        if(mat[i][0] <= target && target <= mat[i][m-1]){
            return findTarget(mat[i],m,target);
        }
    }
    return false;;
}

int main(){
    vector<vector<int>> mat = {{3,4,7,9},{12,13,16,18},{20,21,23,29}};
    int target = 23;
    bool doesExist = f(mat,target);
    cout<<" does the target exist in matrix : "<< doesExist<<endl;
    return 0;
}




// there can be one more way 
// if we can flatten the 2D array into 1D array 
// we can may be linear search in that flattened one
// its not possible but what we can do this 
// possibly find the crdinate for 2d array
// to get rows cordinate-> idx/m
// to get column cordinate -> idx % m

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool f(vector<vector<int>> &mat, int target){
    int n = mat.size();
    int m = mat[0].size();
    int low  = 0;
    int high = n * m -1;

    while(low<=high){
        int mid = low+ (high-low)/2;

        int row = mid/m;
        int col = mid%m;

        if(mat[row][col] == target){
            return true;
        }else if( mat[row][col] < target){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return false;
}



int main(){
    vector<vector<int>> mat = {{3,4,7,9},{12,13,16,18},{20,21,23,29}};
    int target = 23;
    bool doesExist = f(mat,target);
    cout<<" does the target exist in matrix : "<< doesExist<<endl;
    return 0;
}