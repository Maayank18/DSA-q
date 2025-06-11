// our aim is to find the sum of elements between the k1 smallest element 
//  k2 smallest element present in the given array 
// eg arr = {20,8,22,4,12,10,14}
// k1 = 3
// k2 = 6


// BRUTE FORCE APPROACH
// tc -> nlogn
// sc -> 1
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// // 0 1  2  3  4  5  6
// // 4 8 10 12 14 20 22 


// int main(){
//     vector<int> arr = {20,8,22,4,12,10,14};
//     int k1 = 3;
//     int k2 = 6;

//     sort(arr.begin(),arr.end());
              
//     int sum = 0;
//     for(int i = k1; i<k2-1; i++){
//         sum += arr[i];
//     }

//     cout<<" the sum of eements between the k1 smallest and k2 smallest "<<sum<<endl;
//     return 0;
// }



// OPTIMAL SOLUTION
// find the max heap for k1 and k2-1 
// then subract the elements of k1 form k2-1
// add the remaing and that will be our answer
// tc -> o(nlogk) where k = max(k1,k2)
// sc -> o(k)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding(vector<int> &arr, int k1, int k2 ){
    int n = arr.size();

    priority_queue<int> pq1;
    priority_queue<int> pq2;

    for(int i = 0; i<k1; i++){
        pq1.push(arr[i]);
    }

    for(int i = 0; i<k2-1; i++){
        pq2.push(arr[i]);
    }

    for(int i = k1; i<n; i++){
        if(arr[i] < pq1.top()){
            pq1.pop();
            pq1.push(arr[i]);
        }
    }

    for(int i = k2-1; i<n; i++){
        if(arr[i] < pq2.top()){
            pq2.pop();
            pq2.push(arr[i]);
        }
    }


    int sum1 = 0;
    int sum2 = 0;

    while(!pq1.empty()){
        sum1+= pq1.top();
        pq1.pop();
    }

    while(!pq2.empty()){
        sum2 += pq2.top();
        pq2.pop();
    }

    return abs(sum2-sum1);

}

int main(){
    vector<int> arr = {20,8,22,4,12,10,14};
    int k1 = 3;
    int k2 = 6;
    int sum = finding(arr,k1,k2);
    cout<<" the sum of eements between the k1 smallest and k2 smallest "<<sum<<endl;
    return 0;
}