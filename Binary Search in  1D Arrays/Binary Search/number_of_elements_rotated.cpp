// it basically helps us to determine number of minder elements rotated in a sorted array
// eg.  arr[1,2,3,4,5] -> answer = 0
// eg. arr[6,7,8,1,2,3,4,5] -> answer = 3
// eg. arr[5,1,2,3,4] -> answer = 1

// one of the basic approach is we can find the minimum number and return the index 
// unique elements must be present and this can be done after finding the minimum
// elements present 

#include<iostream>
using namespace std;

int minimum_no_rotated( int arr[], int n){
    int low  = 0;
    int high = n-1;
    int answer = INT8_MAX;
    int index = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if(arr[low] <= arr[high]){ // base case
            if( arr[low] < answer){
                index = low;
                answer = arr[low];
            }
            break;
        }

        // If the subarray is sorted
        if (arr[low] <= arr[mid]) {
            if( arr[low] < answer){
                index = low;
                answer = arr[low];
            }
            low = mid + 1;
        } else {
            if( arr[mid] < answer){
                index = mid;
                answer = arr[mid];
            }
            high = mid - 1;
        }
    }
    return index; // Return the minimum value
}

int main(){
    int n;
    cout<<" enter the size of array : "<<endl;
    cin>>n;

    int arr[n];

    cout<<" enter the elements of arrays : ";
    for( int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int result = minimum_no_rotated(arr,n);

    cout<<" the minimum number of elements that are rotated are : "<<result<<endl;

    return 0;
}
