// lower bound is that case in which we find the minimum index such that 
// arr[index] >= x  , where x is a given number or we can say target element
// always remember its not necessary we get answer in one we may ahve to traverse
// right and left

// time complexity is somewhat about O(log base 2 (n))

#include<iostream>
using namespace std;

int lower_bound( int arr[], int n, int t){
    int low = 0;
    int high = n-1;
    int ans = n;
    while( low<= high){
        int mid = low + (high-low)/2;

        if(arr[mid] >= t){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
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

    int result =  lower_bound(arr,n,t);

    cout<<" Hence the lower bound is present at : "<<result<<endl;
    return 0;
}

//USING STL library for implementing lowerbound() 
// implementation : - 