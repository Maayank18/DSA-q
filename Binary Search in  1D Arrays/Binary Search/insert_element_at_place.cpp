// this problem basiaclly aims to give the index of number which is present in the sorted 
// array and if in case it is not present in sorted where where should it be inserted 
// eg, [1,2,4,7] let x=6 find index of 6 where it should it be actaully present in array

#include<iostream>
using namespace std;

int insert_find_index( int arr[], int n, int x){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high){
        int mid =  low + (high-low)/2;

        if( arr[mid] >= x){
            ans = mid;
            high = mid -1;
        }else{
            low = mid +1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    int x;
    cout<<" enter the number whose index is to be found : ";
    cin>>x;

    int arr[n];
    for( int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<endl;

    int result =  insert_find_index(arr,n,x);

    cout<<" the element need to be inserted / present at index : "<<result<<endl;

    return 0;
}