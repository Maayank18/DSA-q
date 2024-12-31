// MINIMUM DAYS to make m bouquets -> this problem statement basically aims to find
// what are minimum number of days required to make m bouquets
// m -> no. of bouquets to be made 
// k -> no. of consequtive blooming days to create one bouquet

// BRUTE FORCE -> somehow solve the problem and for time being please forget about the
// optimisation and it will use linear search approach

#include<iostream>
using namespace std;

int largest( int arr[], int n){
    int max = arr[0];
    for(int i = 1; i<n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

int smallest ( int arr[], int n){
    int min = arr[0];
    for(int i = 1; i<n; i++){
        if(arr[i]<min){
            min = arr[i];
        }
    }
    return min;
}

int minimum_days( int arr[], int n, int m, int k){
    if ( m*k > n) return -1;

    int max_bloom = largest(arr,n);
    int min_bloom = smallest(arr,n);

    for( int i = min_bloom; i<=max_bloom; i++){
        int count = 0;
        int max_cnt = 0;
        for( int j = 0; j<n; j++){
            if(i >= arr[j]){
                count++;
            }else{
                int min_days = count/k;
                count = 0;
            }
        }
    }


}

int main(){
    int n;
    cout<<" enter the no. of blooms days : ";
    cin>>n;

    int arr[n];

    cout<<" enter the elments of array : "<<endl;
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int m;
    cout<<" enter the no. bouquets to be made : ";
    cin>>m;

    int k;
    cout<<" no. of alternative bloom days required for 1 bouquet : ";
    cin>>k;

    int result  = minimum_days(arr,n,m,k);

    if( result == -1){
        cout<<" SORRY CANT BE FORMED !"<<endl;
    }else{
        cout<<" minimum number of days required are : "<<result<<endl;
    }
    return 0;
}
