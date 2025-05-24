// what does this element say if indeed have to find the peak elemnt 
// but the element should be greater than
// its left , right , up and down element this is the only difference in the 2D array peak
// we have to return the cordinates of the peak element

//  we can also find the largest element in the 2d array 




// BRUTE FORCE APPROACH
// tc -> O(n x m x 4)  worst case
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

pair<int,int> f(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            if(mat[i][j] > mat[i-1][j] && mat[i][j] > mat[i+1][j]
            && mat[i][j] > mat[i][j-1] && mat[i][j] > mat[i][j+1]){
                return {i,j};
            }
        }
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> mat = {{4,2,5,1,4,5},
                               {2,9,3,2,3,2},
                               {1,7,6,0,1,3},
                               {3,6,2,3,7,2}};

    pair<int,int> peak = f(mat);
    cout<<" the cordinates of the peak elements are : "<<peak.first<<" and "<<peak.second<<endl;
    return 0;
    
}





// OPTIMAL CASE USES A VERY DEEP THINKNIG APPRAOCH
// LIKE CONSIDERING FROM 0 TO M-1 COLUMN TAKE THE MID COLUMN AND INT THAT COLUMN FIND THE MAX ELEMNT 
// CHECK ON LEFT AND RIGH AND WORK ACCORDING


#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int maxElementIdx(vector<vector<int>> &mat, int n, int mid){
    int maxEle = -1;
    int maxIdx = 0;

    for(int i = 0; i<n; i++){
        if(mat[i][mid] > maxEle){
            maxEle = mat[i][mid];
            maxIdx = i;
        }
    }
    return maxIdx;
}

pair<int,int> f(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    int low = 0;
    int high = m-1;

    while(low<=high){
        int mid = low + (high-low)/2;

        int rowNum = maxElementIdx(mat,n,mid);

        int leftEle = (mid-1 >= 0)? mat[rowNum][mid-1] : -1;
        int rightEle = (mid+1 <= m-1)? mat[rowNum][mid+1] : -1;

        if(mat[rowNum][mid] > leftEle && mat[rowNum][mid] > rightEle){
            return {rowNum,mid};
        }else if(mat[rowNum][mid] < leftEle){
            high = mid - 1 ;
        }else{
            low = mid + 1;
        }
    }
    return {-1,-1};
}

int main(){
    vector<vector<int>> mat = {{4,2,5,1,4,5},
                               {2,9,3,2,3,2},
                               {1,7,6,0,1,3},
                               {3,6,2,3,7,2}};

    pair<int,int> peak = f(mat);
    cout<<" the cordinates of the peak elements are : "<<peak.first<<" and "<<peak.second<<endl;
    return 0;
    
}