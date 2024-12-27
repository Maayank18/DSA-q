// rotated sorted I - it basiaclly aims on finding the target element in sorted though 
//rotated array that is eg. [6,7,8,1,2,3,4,5] as we always though of shifting right
//if target is > mid and left if target is < mid but in this some condition will alter
// and we will consdier crossing and removing all the non needed leemnts 

// here be generally be checking which is the sorted ahlf half or which is not

// arr[low] <= arr[mid] <= arr[high]

// time complexity is O(log base 2 (n))

// no involvement of duplcates 

#include<iostream>
using namespace std;

int rotated_sorted_I( int arr[], int n, int t){
    int low = 0;
    int high = n-1;
    int ans = -1;

    while(low <= high){

        int mid = low + (high-low)/2;

        if( arr[mid] == t){
            ans = mid;
        }

        // check which is sorted and which is not
        if( arr[low] <= arr[mid]){ // case for left sorted 
            if( arr[low] <= t && t <= arr[mid]){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }else{
            if( arr[mid] <= t && t <= arr[high]){ // check for right sorted 
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        // check for right sorted 

    }
    return ans;
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    int t;
    cout<<" enter the target element : ";
    cin>>t;

    int arr[n];

    for( int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<endl;

    int result =  rotated_sorted_I(arr,n,t);

    cout<<" Hence the upper bound is present at : "<<result<<endl;
    return 0;
}