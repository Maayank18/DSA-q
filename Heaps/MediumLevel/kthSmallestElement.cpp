// given an array we need to find the kth smallest elemnt in the given array
// in heap sc is o(n)


// TO FIND THE SMALLEST ELEMENT USE THE MAX HEAP
// TO FIND TH LARGEST ELEMENT USE THE MIN HEAP



// BRUTE FORCE APPRAOCH
// tc -> nlogn + constant time to find the element 
// sc -> o(n)
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//     vector<int> arr = {10,3,7,4,8,9,2,6};
//     int k = 4;
//     sort(arr.begin(),arr.end());
//     cout<<"our fourth smallest element is : "<<arr[3]<<endl;
//     return 0;
// }



// BETTER SOLUTION 
// tc -> o(n) + klogn -> worst case (n log n )
//  sc -> o(1) 
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int finding(vector<int> &arr, int k){
//     int n = arr.size();

//     priority_queue<int, vector<int>, greater<int>> pq;

//     for(int i = 0; i<n; i++){
//         pq.push(arr[i]);
//     }

//     while(!pq.empty() && k > 1 ){
//         pq.pop();
//         k--;
//     }

//     return pq.top();
// }

// int main(){
//     vector<int> arr = {10,3,7,4,8,9,2,6};
//     int k = 4;
//     int kthsmallest = finding(arr,k);
//     cout<<"our fourth smallest element is : "<<kthsmallest<<endl;
//     return 0;
// }




// OPTIMAL SOLUTION -> VERY INTUTIVE AND PRACTICE BASED APPRAOCH
//  tc -> k + nlogk - klogk = nlogk
//  sc -> 
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int finding(vector<int> &arr, int k){
    int n = arr.size();

    priority_queue<int> pq;
    for(int i = 0; i<k; i++){
        pq.push(arr[i]);
    }

    for(int i = k; i<n; i++){
        if(arr[i] < pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }

    return pq.top();

}

int main(){
    vector<int> arr = {10,3,7,4,8,9,2,6};
    int k = 4;
    int kthsmallest = finding(arr,k);
    cout<<"our fourth smallest element is : "<<kthsmallest<<endl;
    return 0;
}