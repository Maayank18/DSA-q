#include<iostream>
using namespace std;

void selectionsort( int arr[], int n){
    for( int i = 0; i<n-2; i++){
        int min = i;
        for(int j = i; j<n-1;j++){
            if(arr[j]>arr[min]){
                min = j;
            }
            int temp = arr[j];
            arr[j] = arr[min];
            arr[min] = temp;
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
    selectionsort(arr,n);

    cout<<" Elements after sortiing : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
