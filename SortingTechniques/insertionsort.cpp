#include<iostream>
using namespace std;

void insertionsort(int arr[], int n){
    for(int i = 0; i<n-1; i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp = arr[j-1];
            arr[j-1] = arr[j];
            arr[j] = temp;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int arr[n];

    cout<<" taking inputs from the users : ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<" Elements before sortiing : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    insertionsort(arr,n);

    cout<<" Elements after sortiing : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}