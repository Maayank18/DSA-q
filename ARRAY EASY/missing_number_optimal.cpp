#include<iostream>
using namespace std;

int sum_of_arr( int arr[], int n){
    int sum = 0;
    for(int i = 0; i<n; i++){
        sum = sum + arr[i];
    }
    return sum;
}

int missing_opt( int arr[], int n){
    int value = sum_of_arr(arr,n);
    int sum_of_n = (n*(n+1))/2;

    return sum_of_n - value;
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

    int result = missing_opt(arr,n);
    cout << "The missing number is: " << result << endl;
    return 0;
}