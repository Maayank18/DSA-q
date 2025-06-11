// our task is to merge two binary max heap
// eg given arr1 = {10,5,6,2}  arr2 = {12,7,9}
// imagine mixing all these elemment and creating a new max heap



// BRUTE FORCE SOLUTION ->
// put each elmeent in a priority queue and make a max heap
// tc -> O((n+m)log(n+m))
// sc -> o(n+m)
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr1 = {10,5,6,2};
//     vector<int> arr2 = {12,7,9};

//     priority_queue<int> pq;

//     for(int i = 0; i<arr1.size(); i++){
//         pq.push(arr1[i]);
//     }

//     for(int i = 0; i<arr2.size(); i++){
//         pq.push(arr2[i]);
//     }

//     cout<<" the merged binary max heap is : ";
//     while(!pq.empty()){
//         cout<<pq.top()<<" ";
//         pq.pop();
//     }

//     return 0;
// }




// BETTER SOLUTION
// tc -> O(n+m)
// sc -> O(n+m)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

void insert(int index, vector<int> &result){
    
    while(index > 0 && result[(index-1)/2] < result[index]){
        swap(result[(index-1)/2] , result[index]);
        index = (index-1)/2;
    }
}

void finding(vector<int> &arr1, vector<int> &arr2, vector<int> &result){
    int n = arr1.size();
    int m = arr2.size();

    for(int i = 0; i<n; i++){
        result.push_back(arr1[i]);
        insert(result.size()-1,result);
    }

    for(int i = 0; i<m; i++){
        result.push_back(arr2[i]);
        insert(result.size()-1,result);
    }
}

int main(){
    vector<int> arr1 = {10,5,6,2};
    vector<int> arr2 = {12,7,9};
    int n = arr1.size();
    int m = arr2.size();
    vector<int> result;

    finding(arr1,arr2,result);

    for(int i = 0; i<result.size(); i++){
        cout<<result[i]<<" ";
    }

    return 0;
}
