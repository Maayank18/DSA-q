// brute force approach will wbe to apply merge sort whcih will traverse the
// array and merge it



// better solution will keeping a counter sytem and adding of arrays 
// void sort( int arr[], int n){
//     int cnt0 = 0;
//     int cnt1 = 0;
//     int cnt2 = 0;
//     for( int i = 0; i<n; i++ ){
//         if(arr[i] == 0){
//             cnt0++;
//         }else if (arr[i] == 1)
//         {
//             cnt1++;
//         }else{
//             cnt2++;
//         }
//     }

//     for( int i = 0; i<cnt0; i++){
//         arr[i] = 0;
//     }
//     for( int i = cnt0; i<cnt1 ;i++){
//         arr[i] = 1;
//     }
//     for( int i = cnt0+cnt1; i<cnt2; i++){
//         arr[i] = 2;
//     }
// }


// dutch national flag algorithm
//(0 low-1)sorted 0 (low mid-1)sorted 1 (mid high)unsorted  (high n-1)sorted 2

#include<bits/stdc++.h>
using namespace std;

void sort_algo( int arr[], int n){
    int low = 0, mid = 0, high = n-1;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }else if(arr[mid] == 1){
            mid++;
        }else{
            swap(arr[high],arr[mid]);
            high--;
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
    cout<<" original array : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    sort_algo(arr,n);
    cout<<" soted array : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}