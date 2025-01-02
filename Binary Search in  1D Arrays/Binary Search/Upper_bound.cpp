// upper bound has a similar concept to that of lower bound the only difference is 
// it will check smallest index giving the result arr[mid] > x , where x is the 
// target element and we dont have equal to sign but a greater sign so case will 
// similar and have almost same TIME COMPLEXITY  

#include<iostream>
using namespace std;

int upper_bound( int arr[], int n, int t){
    int low = 0;
    int high = n-1;
    int ans = n;
    
    while( low <= high){
        int mid = low + (high-low)/2;
        if(arr[mid] > t){
            ans = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
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

    int result =  upper_bound(arr,n,t);

    cout<<" Hence the upper bound is present at : "<<result<<endl;
    return 0;
}