// this particular problem aims at finding the longest sub array which has the sum 0

// brute force solution which is pretty basic and noy optimal as it have a 
// time complexity of O(n^2) in worst case 

// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int find( int arr[], int n){
    int answer = -1;
    for( int i = 0;i<n ; i++){
        int sum = 0;
        int count = 0;
        for(int j = i; j<n; j++ ){
            count++;
            sum += arr[j];
            if( sum == 0 ){
                answer = max(answer,count);
            }
        }
    }
    return answer;
}

int main() {
    int n;
    cout<<" enetr the size of array : ";
    cin>>n;
    
    int arr[n];
    
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    int result = find(arr,n);
    
    cout<<" the max sub-array is of lenght : "<<result<<endl;

    return 0;
}


// and good optimal solution is a mixture of algorithm and hashing 
// Runs for tc -> O(n)
// and will also have a space complexity as we are using hashmaps 
#include <iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;

int find( int arr[], int n){
    map<int,int> preSum;
    int sum = 0;
    int maxLen = 0;
    for( int i = 0; i<n; i++){
        sum += arr[i];
        
        if( sum == 0 ){
            maxLen = max(maxLen, i+1);
        }
        if(preSum.find(sum) != preSum.end()){
            maxLen = max(i-preSum[sum],maxLen);
        }else{
                 preSum[sum] = i; 
        }
    }
    return maxLen;
}

int main() {
    int n;
    cout<<" enetr the size of array : ";
    cin>>n;
    
    int arr[n];
    
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    
    int result = find(arr,n);
    
    cout<<" the max sub-array is of lenght : "<<result<<endl;

    return 0;
}