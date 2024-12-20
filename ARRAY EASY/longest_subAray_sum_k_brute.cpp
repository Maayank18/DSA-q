// #include<iostream>
// using namespace std;

// int length_longest_subArray( int arr[], int n, int t){
//     int len = 0;
//     for( int i = 0; i<n; i++){
//         int sum = 0;
//         for( int j = i; j<n; j++){
//              for( int k = i; k<j; k++){
//                 sum = sum + arr[k];
//                 if( sum == t){
//                     len = max(len,j-i+1);
//                 }
//              }
//         }
//     }
//     return len;
// }

// int main(){
//     int n;
//     cout<<" enter the size of array : ";
//     cin>>n;
//     cout<<endl;

//     int t;
//     cout<<" enter the sum required : ";
//     cin>>t;

//     int arr[n];

//     for(int i = 0; i<n; i++){
//         cin>>arr[i];
//     }

//     cout<<" array entered by user : ";
//     for( int i = 0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;

//     int length = length_longest_subArray(arr,n,t);

//     cout<<" The length of longest SubArray is : "<<length;
//     return 0;
// }

// if we talk about the better solution the difference that will be made will 
// be we can remove an extra loop of k and it wont make any big difference 
// and our time comlexity will also become O(n^2)
#include<iostream>
using namespace std;

int length_longest_subArray( int arr[], int n, int t){
    int len = 0;
    for( int i = 0; i<n; i++){
        int sum = 0;
        for( int j = i; j<n; j++){
            sum = sum + arr[j];
            if(sum ==  t){
                len  = max(len,j-i+1);
            }
        }
    }
    return len;
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;
    cout<<endl;

    int t;
    cout<<" enter the sum required : ";
    cin>>t;

    int arr[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<" array entered by user : ";
    for( int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int length = length_longest_subArray(arr,n,t);

    cout<<" The length of longest SubArray is : "<<length;
    return 0;
}