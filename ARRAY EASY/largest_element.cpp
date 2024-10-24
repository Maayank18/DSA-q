#include<iostream>
using namespace std;

int findlarge(int arr[], int n){
    int max = arr[0];
    for(int i = 0; i<n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}
int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    int arr[n];
    for( int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<" Elements of array are : ";
    for( int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int largest = findlarge(arr,n);
    cout<<" The largest element is : "<<largest;
    return 0;
}