// what is basically means is consider a consoder an array [1,1,1,2,2,3,3,3,3] how many
//times a number occurs in array so basically we can just do last occurence - first occurnece
// as it is sorted array and all number in between will be like number 

#include<iostream>
using namespace std;

int first_o( int arr[], int n, int t){
    int low = 0;
    int high = n-1;
    int f = -1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == t){
            f = mid;
            high = mid - 1;
        }
        else if( arr[mid] > t){
            high = mid  - 1;
        }
        else{
            low  = mid + 1;
        }
    }
    return f;
}

int last_o( int arr[], int n, int t){
    int low = 0;
    int high = n-1;
    int l = -1;

    while(low <= high){
        int mid = low + (high-low)/2;

        if(arr[mid] == t){
            l = mid;
            low = mid + 1;
        }
        else if( arr[mid] < t){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return l;
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

    int first =  first_o(arr,n,t);
    int last = last_o(arr,n,t);

    if( first == -1 || last == -1){
        cout<<" sorry no duplicates "<<endl;
    }else{
        cout<<" the number of duplicates are : "<< last - first + 1 <<endl;
    }

    return 0;
}