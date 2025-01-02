// Floor value -> it refers to the largest value which is <= x
// ceil value -> it refers to smallest value which is >= x ( somewhere it is lower_bound)
// x is the target element aroundwhich we are looking for our ceil and floor value

#include<iostream>
using namespace std;

int floor( int arr[], int n, int x){
    int low = 0;;
    int high = n-1;
    int ans = -1;

    while( low<=high){
        int mid = low+ (high-low)/2;

        if( arr[mid] <= x){
            ans = mid;
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return ans;
}

int ceil( int arr[], int n, int x){
    int low = 0;
    int high = n-1;
    int ans = n;
    while(low <= high){
        int mid =  low + (high-low)/2;

        if( arr[mid] >= x){
            ans = mid;
            high = mid -1;
        }else{
            low = mid +1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    int x;
    cout<<" enter the number whose index is to be found : ";
    cin>>x;

    int arr[n];
    for( int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<endl;

    int ceil_value =  ceil(arr,n,x);
    int floor_value = floor(arr,n,x);

    cout<<" the element need to be inserted / present at index at ceil : "<<arr[ceil_value]<<endl;

    cout<<" the element need to be inserted / present at index at floor: "<<arr[floor_value]<<endl;


    return 0;
}