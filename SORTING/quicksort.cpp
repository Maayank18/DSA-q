#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        }
        while(arr[j]>=pivot && j>low){
            j--;
        }
        if(i<j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    arr[low] = arr[j];
    arr[j] = pivot;
    return j;
}

void qs(int arr[], int low, int high){
    if (low < high){
        int p_index = partition(arr,low,high);
        qs(arr,low,p_index-1);
        qs(arr,p_index+1,high);
    }
}

void quicksort(int arr[],int n){
    qs(arr,0,n-1);
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
    quicksort(arr,n);

    cout<<" Elements after sortiing : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}