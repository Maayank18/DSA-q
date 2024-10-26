// basic linear search approach 

#include<iostream>
using namespace std;

int missing( int arr[], int n){
    int flag;
    for(int i = 1; i<=n; i++){
         flag = 0;
        for( int j = 0; j<n; j++){
            if(arr[j]==i){
                flag = 1;
                break;
            }
        }
        if(flag == 0) return i;
    }
    return -1;
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

    int result = missing(arr,n);
    cout<<" is the number missing :"<<result;
    return 0;
}