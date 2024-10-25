#include<iostream>
using namespace std;

bool checking(int arr[], int n){
    for( int i =0; i<n; i++){
        if(arr[i]<=arr[i+1]){
        }else{
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    cout<<" enter the size of arrays :";
    cin>>n;
    int arr[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<" the array entered by user : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    bool check = checking(arr,n);

    if(check == true){
        cout<<" YES, the array is sorted";
    }else{
        cout<<" OOPS!, try again";
    }
    return 0;
}