//  our aim is to find the kth smallest number in our matrix



// BRUTE FORCE APPRAOCH
// 1 -> convert the matrix from 2d to 1d array
// 2 -> sort that 1d array 
// 3 -> find the kth smallest element in that 1d array
// tc -> O(n^2 log n)
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int finding(vector<vector<int>>&mat, int k){
//     int n = mat.size();
//     int m = mat[0].size();
//     vector<int> temp;

//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<m; j++){
//             temp.push_back(mat[i][j]);
//         }
//     }

//     sort(temp.begin(),temp.end());

//     return temp[k-1];
// }

// int main(){
//     vector<vector<int>> mat = {{16,28,60,64},
//                                {22,41,63,91},
//                                {27,50,87,93},
//                                {36,78,87,94}};

//     int k = 6;
//     int kthsmallest = finding(mat,k);
//     cout<<" the kth smallest in the matrix is : "<<kthsmallest<<endl;
//     return 0;
// }





// BETTER APPRAOCH
// what we can do is that we can take a temp array and pass each element in that 
// then instead of sorting we can form the min heap and find the kth smallest element
//  tc -> O(nm log(nm))
//  sc -> O(nm)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding(vector<vector<int>>&mat, int k){
    int n = mat.size();
    int m = mat[0].size();
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            pq.push(mat[i][j]);
        }
    }

    while(!pq.empty() && k > 1){
        pq.pop();
        k--;
    }

    return pq.top();
}

int main(){
    vector<vector<int>> mat = {{16,28,60,64},
                               {22,41,63,91},
                               {27,50,87,93},
                               {36,78,87,94}};

    int k = 6;
    int kthsmallest = finding(mat,k);
    cout<<" the kth smallest in the matrix is : "<<kthsmallest<<endl;
    return 0;
}



