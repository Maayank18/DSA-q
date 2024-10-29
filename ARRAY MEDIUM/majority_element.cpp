//brute force solution - searching thorugh whole array and counter ++
// for(int i = 0; i<n; i++){
//     int cnt = 0;
//     for( int j = 0; j<n; j++){
//         if(arr[i] == arr[j]){
//             cnt++;
//         }
//     }
//     if(cnt>n/2) return arr[i];
// }


// better solution - it will use hashing / hasmaps
// map<int,int>mpp
// for( int i =0; i<v.size(); i++){
//     mpp[v[i]]++;
// }
// for(auto it: mpp){
//     if(it.second>v.size()/2){
//         return it.first;
//     }
//     return -1; //nothing found no element greater than n/2
// }

// BEST MOORE VOTING ALGORITHM

#include<iostream>
using namespace std;

int moore_voting(int arr[], int n){
    int count = 0;
    int element;
    for( int i = 0; i<n; i++){
        if(count  == 0){
            element = arr[i];
            count++;
        }else if(arr[i] == element){
            count++;
        }else{
            count --;
        }
    }
    int count1;
    for( int i = 0; i<n; i++){
        if(arr[i] = element){
            count++;
        }
    }
    if(count1>n/2){
        return element;
    }
    return -1;
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

    int result = moore_voting(arr,n);
    cout<<" the maximum appearing element is equal to : "<<result;
    cout<<endl;
    return 0;
}