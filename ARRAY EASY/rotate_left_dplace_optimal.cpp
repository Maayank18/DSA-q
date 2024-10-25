//revrese the from 0 to number of spaces to be rotated
// then reverse from d+1 to ending index 
// then reverse the whole array

#include<iostream>
using namespace std;

void reverse(int arr[], int low, int high){
    while(low<=high){
        int temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}

void rotate( int arr[], int n, int d){
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;
    cout<<endl;
    int d;
    cout<<" the number of spaces to be shifted : ";
    cin>>d;
    int arr[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<" original array : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    rotate(arr,n,d);
    cout<<" after rotation array : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}