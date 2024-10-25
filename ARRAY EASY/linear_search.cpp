#include<iostream>
using namespace std;

int linear( int arr[], int n, int target){
    for(int i = 0; i<n; i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;
    cout<<endl;

    int target;
    cout<<" enter the target element : ";
    cin>>target;
    cout<<endl;
    int arr[n];

    for( int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<" Elements of array are : ";
    for( int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int result = linear(arr,n,target);

    cout<<" the required element is present at idx : "<<result;
    return 0;
}