// finding the kth largest elment is the same problem just like smallest
//  the difference is here we need to find the kth largest element 

// HW -> find the kth largest in the stream

// BRUTE FORCE APPROACH
// tc -> nlogn sorting + constant time for finding the element
// sc -> o(n) sorting space in heap memeoy
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// // 0 1 2 3 4 5 6 7 
// // 2 3 4 5 6 7 8 10
// //  n - k = 8 - 3 = 5

// int main(){
//     vector<int> arr = {6,8,2,10,5,7,4,3};
//     int k = 3;
//     int n = arr.size();
//     sort(arr.begin(),arr.end());
//     cout<<" our 3rd largest element is : "<<arr[n-k]<<endl;
//     return 0;
// }



// BETTER APPRAOCH 
// tc -> nlogn
//  sc -> o(n)
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int finding(vector<int> &arr, int k){
//     int n =  arr.size();

//     priority_queue<int> pq;

//     // putting all the elements 
//     for(int i = 0; i<n; i++){
//         pq.push(arr[i]);
//     }

//     while(!pq.empty() && k > 1){
//         pq.pop();
//         k--;
//     }

//     return pq.top();
// }

// int main(){
//     vector<int> arr = {6,8,2,10,5,7,4,3};
//     int k = 3;
//     int kthlargest = finding(arr,k);
//     cout<<" our 3rd largest element is : "<<kthlargest<<endl;
//     return 0;
// }




// OPTIMAL APPRAOCH  -> very intutive appraoch
//  TC -> nlogk
//  SC -> o(k)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding(vector<int> &arr, int k){
    int n = arr.size();

    // min priority queue
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0; i<k; i++){
        pq.push(arr[i]);
    }

    for(int i = k; i<n; i++){
        if(arr[i] > pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();
}

int main(){
    vector<int> arr = {6,8,2,10,5,7,4,3};
    int k = 3;
    int kthlargest = finding(arr,k);
    cout<<" our 3rd largest element is : "<<kthlargest<<endl;
    return 0;
}