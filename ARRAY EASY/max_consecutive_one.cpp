#include<bits/stdc++.h>
using namespace std;

int max_one(int arr[], int n){
    int max1 = 0;
    int cnt = 0;
    for( int i = 0; i<n; i++){
        if(arr[i] == 1){
            cnt++;
            max1 = max(cnt,max1);
        }else{
            cnt = 0;
        }
    }
    return max1;
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    int arr[n];

    for( int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<" The arrays entered by the user : ";
    for( int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int value = max_one(arr,n);
    cout<<" maximum number of ones are : "<<value;
    return 0;
}