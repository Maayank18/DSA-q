#include<iostream>
using namespace std;

void bubblesort( int arr[], int n){
    for(int i = n-1; i>=0; i--){
        for(int j = 0; j<i; j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
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
    bubblesort(arr,n);

    cout<<" Elements after sortiing : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}