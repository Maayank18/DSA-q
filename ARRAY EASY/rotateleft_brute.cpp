#include<iostream>
using namespace std;

void rotate(int arr[], int n){
    int num = arr[0];
    for(int i = 1; i<n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = num;
}

int main(){
    int n;
    cout<<" enter the size of array :";
    cin>>n;
    int arr[n];

    for( int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<" without rotating : ";
    for( int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    rotate(arr,n);
    cout<<" after rotating : ";
    for( int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}