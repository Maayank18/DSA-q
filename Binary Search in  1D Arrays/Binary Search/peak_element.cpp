// peak element refers to that element in which the current element is greater than the
// number before and after 
// eg. [1,2,5,4,3] in this case the peak element will be 5 as it is greater than 2 and 4
// IMPORTANT - eg[ 1,2,3,4,5] in this case it is 5 as *** at both ends it is -ve infinty
// that means element -infinty 1,2,3,4,5 - infnity

// brute force solution - a linear iteration

#include<iostream>
using namespace std;

int peak ( int arr[], int n){
    if( n == 1 ) return arr[0];
    if( arr[0] > arr[1]) return arr[0];
    if( arr[n-1]> arr[n-2]) return arr[n-1];

    for( int i = 1; i<n-1; i++){
        if( arr[i] > arr[i+1] && arr[i]> arr[i-1]){
            return arr[i];
        }
    }
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    int arr[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int result = peak(arr,n);

    if( result == -1){
        cout<<" no peal element !"<<endl;
    }else{
        cout<<" the peak element is : "<<result;
    }
    return 0;
}


// binary search approach - always take an example of graph to understand it better 

#include<iostream>
using namespace std;

int peak( int arr[], int n){
    if( n == 1) return arr[0];
    if( arr[0] > arr[1]) return arr[0];
    if( arr[n-1]> arr[n-2]) return arr[n-1];

    int low = 1;
    int high = n-2;

    while( low<= high){
        int mid = low + (high-low)/2;

        if( arr[mid]> arr[mid-1] && arr[mid]> arr[mid+1]){
            return arr[mid];
        }else if( arr[mid+1] > arr[mid]){
           low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    int arr[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int result = peak(arr,n);

    if( result == -1){
        cout<<" no peal element !"<<endl;
    }else{
        cout<<" the peak element is : "<<result;
    }
    return 0;
}
