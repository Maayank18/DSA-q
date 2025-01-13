// koko eating bananas - the problem basically states that - we are given piles of banans
//with each pile having with number of bananas and we are given h - that is number of hours
//and we need to find the k that is banana/hour such that they get finished with h time

// eg. [3,6,7,11] and h = 8 , find k such that k is MINIMUM 
// let k = 1 , time is 3+6+7+11 > h 
// ** wasted time is also counted and cant be adjusted 
// let k = 2, time is 2+3+4+6 > h
// let k = 3, time is 1+2+3+4 > h
// let k = 4, time is 1+2+2+3 == h , hence minimum k = 8

// brute force solution

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max_element(int arr[], int n){
    int max = arr[0];
    for( int i = 1; i<n; i++){
        if( arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int minimum_k( int arr[], int n, int hours){
    int maxPile = max_element(arr,n);
    int answer = -1;
    for( int k = 1; k<= maxPile; k++){
        int sum = 0;
        for( int i = 0; i<n; i++){
            sum+=(arr[i]+k-1)/k;
        }
        if( sum <= hours){
            answer = k;
            break;
        }
    }
    return answer;
}

int main(){
    int n;
    cout<<" enter the number of piles : ";
    cin>>n;

    int hours;
    cout<<" enter the time limit under which banana should be finished : ";
    cin>>hours;

    int arr[n];

    for( int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int answer = minimum_k(arr,n,hours);

    cout<<" the minimum bananas/hour = "<< answer <<endl;

    return 0;
}

// BINARY SEARCH APPROACH - now again we can see till some point the answer is valid
// and after that it goes in valid and hence here we can apply binary search
// to optimise the solution given above
// TC -> O(N) X o( max element)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max_element(int arr[], int n){
    int max = arr[0];
    for( int i = 1; i<n; i++){
        if( arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int minimum_k( int arr[], int n, int hours){
    int maxPile = max_element(arr,n);
    int low = 1;
    int high = maxPile;
    int answer = -1;

    while( low <= high){
        int mid  = low+ (high-low)/2;

        int sum = 0;
        for( int i = 0; i<n; i++){
            sum += (arr[i] + mid - 1)/mid;
        }
        if(sum <= hours ){
                answer = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
    }
    return answer;
}

int main(){
    int n;
    cout<<" enter the number of piles : ";
    cin>>n;

    int hours;
    cout<<" enter the time limit under which banana should be finished : ";
    cin>>hours;

    int arr[n];

    for( int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int answer = minimum_k(arr,n,hours);

    cout<<" the minimum bananas/hour = "<< answer <<endl;

    return 0;
}