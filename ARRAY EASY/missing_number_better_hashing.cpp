#include<iostream>
using namespace std;

int missing_hash(int arr[], int n){
    int hash[n+1] = {0};

    for(int i = 0; i<n; i++){
        if (arr[i] <= n && arr[i] > 0){
            hash[arr[i]] = 1;
        }
    }

    for(int i = 1; i<=n; i++){
        if(hash[i] == 0){
             return i; // missing number is hash[arr[i]];
        }
    }
    return -1; // no missing number 
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

    int result = missing_hash(arr,n);
    if (result == -1) {
        cout << "No number is missing." << endl;
    } else {
        cout << "The missing number is: " << result << endl;
    }
    return 0;
}