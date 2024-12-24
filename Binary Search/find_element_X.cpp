// this is kind of basic approach that is found in binary search 
//first we find mid element 
// secondly the array need to be sorted in binary search
// Time complexity =          & Space complxity = 


#include<iostream>
using namespace std;

int Bs( int arr[], int n, int t){
    int low = 0;
    int high = n-1;

    while (low <= high){
        int mid = low + (high-low)/2;

    if(arr[mid] == t){
        return mid;
    }
    else if( t > arr[mid]){
        low = mid +1;
    }
    else{
        high = mid -1;
    }
    }
    return -1;
}

int main(){
    int n;
    cout<<" enter the size of arrays : ";
    cin>>n;

    int t;
    cout<<" enter yhe target element: ";
    cin>>t;

    int arr[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    int result = Bs(arr,n,t);

    if(result != -1){
        cout<<" the required value is found at index : "<< result <<endl;
    }else{
        cout<<" Alas! Better luck next time ";
    }
    return 0;
}

// another way finding / implementing the bs is using recusrion technique 
// where a constant recursive call is applied to check th condition againa nd again
// now the time complexity is about O(log base 2 n)


#include<iostream>
using namespace std;

int bs( int arr[], int low, int high, int t){
    if( low > high) return -1;

    int mid = low + (high-low)/2;

    if(arr[mid] == t){
        return mid;
    }
    else if( t > arr[mid]){
        bs(arr,mid+1,high,t);
    }
    else{
        bs(arr,low,mid-1,t);
    }
}

int main(){
    int n;
    cout<<" enter the size of arrays : ";
    cin>>n;

    int t;
    cout<<" enter yhe target element: ";
    cin>>t;

    int arr[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }

    int low = 0;
    int high = n-1;

    int result = bs(arr,low,high,t);

    if(result != -1){
        cout<<" the required value is found at index : "<< result <<endl;
    }else{
        cout<<" Alas! Better luck next time ";
    }
    return 0;
}

