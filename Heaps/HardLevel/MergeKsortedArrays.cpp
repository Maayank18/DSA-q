// given a matrix consider 4x4 and first column represent frist element 
//  of each arrays which are in sorted order 
// our aim is to merge of all them into a single array in a sorted fashion


// BRUTE FORCE 
// tc -> O(nlogn)
// sc -> O(n)
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// vector<int> mergedkArrays(vector<vector<int>> &arr,int k){
//     vector<int> result;
//     int n = arr.size();
//     int m = arr[0].size();

//     for(int i = 0; i<n; i++){
//         for(int j = 0; j<m; j++){
//             result.push_back(arr[i][j]);
//         }
//     }

//     sort(result.begin(),result.end());

//     return result;
// }

// int main(){
//     vector<vector<int>> arr = {{1,2,3},
//                                {4,5,6},
//                                {7,8,9}};
//     int k = 3; // number of arrays;
//     vector<int> ans = mergedkArrays(arr,k);

//     cout<<" hence our merged array is : "<<endl;
//     for(int i = 0; i<ans.size(); i++){
//         cout<<ans[i]<<" ";
//     }
//     return 0;
// }




// BETTER APPRAOCH
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> mergedkArrays(vector<vector<int>> &arr,int k){
    
    vector<pair<int,pair<int,int>>> temp;
    for(int i = 0; i<k; i++){
        temp.push_back(make_pair(arr[i][0], make_pair(i,0)));
    }
    // creating a min heap
    priority_queue<pair<int,pair<int,int>>,
                        vector<pair<int,pair<int,int>>>,
                        greater<pair<int,pair<int,int>>>> pq(temp.begin(),temp.end());

    // passing data like (data,row,column)
    // our ans
    vector<int> ans; // were our sorted data is located

    pair<int,pair<int,int>> element;
    int i,j;

    while(!pq.empty()){
        element = pq.top();
        pq.pop();
        ans.push_back(element.first);
        i = element.second.first;
        j = element.second.second;

        if(j+1 < k){
            pq.push(make_pair(arr[i][j+1], make_pair(i,j+1)));
        }
    }

    return ans;

}

int main(){
    vector<vector<int>> arr = {{1,2,3},
                               {4,5,6},
                               {7,8,9}};
    int k = 3; // number of arrays;
    vector<int> ans = mergedkArrays(arr,k);

    cout<<" hence our merged array is : "<<endl;
    for(int i = 0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}




// we can also use the merge sort for solving