// WITHOUT SORTING
#include<iostream>
using namespace std;

int findlarge(int arr[], int n){
    int max = arr[0];
    int max_idx = -1;
    for(int i = 0; i<n; i++){
        if(arr[i]>max){
            max = arr[i];
            max_idx = i;
        }
    }
    return max_idx;
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
    arr[largest] = -1;
    int s_largest = findlarge(arr,n);
    cout<<" The second largest element is : "<<arr[s_largest];
    return 0;
}