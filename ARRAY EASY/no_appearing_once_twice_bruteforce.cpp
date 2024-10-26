// 1 1 2 3 3 4 4

#include<iostream>
using namespace std;

int count( int arr[], int n){
    for(int i =0; i<n; i++){
        int num = arr[i];
        int cnt = 0;
        for( int j = 0; j<n; j++){
            if(arr[j] == num){
                cnt++;
            }
        }
        if(cnt == 1) return num;
    }
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

    int value = count(arr,n);
    cout<<" number appearing once : "<<value;
    return 0;
}