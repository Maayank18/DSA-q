// it is same case as that of rotated sorted array DIIFERENCE LIES 
// IT INCLUDES DUPLICATES IN ROTATED SORTED ARRAYS 

// here the taret will exist and we dont need to tell the index and we just need 
// to retrun YES or NO

// consider the edge case where arr[] = {3,1,2,3,3,3,3} here mid = low = high
// from naked eyes we can find the difference but programtically this edge case will fail

// best case scneario is that we trim down the search space that is we do low++ and 
// high-- 

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

        if( arr[low] == arr[mid] && arr[mid] == arr[high]){ // only difference that will
            low++;                                          // exist and we will take our
            high--;                                         // problem as our advantage
            continue;                                       // trimming search space
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