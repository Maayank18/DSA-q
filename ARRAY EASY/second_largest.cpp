#include<iostream>
#include<vector>
using namespace std;

int SL(vector<int> &arr){
    int largest = arr[0];
    int sl = -1;
    for(int i = 1; i<arr.size(); i++){
        if(arr[i]>largest){
            sl = largest;
            largest = arr[i];
        }
        else if( arr[i]<largest && arr[i]>sl ){
            sl = arr[i];
        }
    }
    return sl;
}

int main(){
    int n;
    cout<<" enter the size of vector : ";
    cin>>n;
    vector<int> arr(n);
    for( int i = 0; i<arr.size();i++){
        cin>>arr[i];
    }

    int secondL = SL(arr);
    cout<<" the second largest element is : "<<secondL;
    return 0;
}


// ----------------------------------------------------------------------------------------

// this is one of the brute force solution existing having a complexity of O(n^2)
// #include<iostream>
// #include<vector>
// using namespace std;

// void bubble_sort(vector<int> &arr){
//     for(int i = 0; i<arr.size()-1; i++){
//         for(int j = i+1; j<arr.size(); j++){
//             if(arr[i]>arr[j]){
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }
//     return;
// }

// int main() {
//     int n;
//     cout<<" enter the number of elements in array : ";
//     cin>>n;

//     vector<int> arr(n);
//     for(int i = 0; i<arr.size(); i++){
//         cin>>arr[i];
//     }

//     bubble_sort(arr);

//     for(int i = n-2; i>=0; i--){
//         if(arr[i]!=arr[i+1]){
//             cout<<arr[i];
//             break;
//         }
//     }
//     return 0;
// }

// // ----------------------------------------------------------------------------------------

// // WITHOUT SORTING( mayank method )
// #include<iostream>
// using namespace std;

// int findlarge(int arr[], int n){
//     int max = arr[0];
//     int max_idx = -1;
//     for(int i = 0; i<n; i++){
//         if(arr[i]>max){
//             max = arr[i];
//             max_idx = i;
//         }
//     }
//     return max_idx;
// }
// int main(){
//     int n;
//     cout<<" enter the size of array : ";
//     cin>>n;

//     int arr[n];
//     for( int i = 0; i<n; i++){
//         cin>>arr[i];
//     }

//     cout<<" Elements of array are : ";
//     for( int i = 0; i<n; i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;

//     int largest = findlarge(arr,n);
//     arr[largest] = -1;
//     int s_largest = findlarge(arr,n);
//     cout<<" The second largest element is : "<<arr[s_largest];
//     return 0;
// }