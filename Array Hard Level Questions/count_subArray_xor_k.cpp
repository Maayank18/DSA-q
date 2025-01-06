// This particular problem aims to find the sub-array having the value k after xoring
// the lements values present in it 
// for eg. arr = [4,2,2,6,4] , count the sub arrays which after xoring gives the value 
// passed that is == k or target

//BRUTE FORCE SOLUTION INLCUDE GENERATING ALL THE SUB - ARRAYS AND CHECKING IF IT IS 
// EQUAL TO THE K OR THE RESULT

// #include<iostream>
// using namespace std;

// int find( int arr[], int n, int t){
//     int count = 0;
//     for(int i = 0; i<n; i++){
//         for(int j = i; j<n; j++){
//             int xorr = 0;
//             for( int k = i; k<=j; k++){
//                 xorr = xorr ^ arr[k];
//             }
//             if( xorr == t){count++;}
//         }
//     }
//     return count;
// }

// int main(){
//     int n; cout<<" enter the size of array : ";
//     cin>>n;

//     int arr[n];

//     cout<<" enter the lements of array : ";
//     for(int i = 0; i<n; i++){
//         cin>>arr[i];
//     }

//     int t;
//     cout<<" enter the value u are looking for ";
//     cin>>t;

//     int answer = find(arr,n,t);

//     cout<<" the number of sub arrays are : "<<answer<<endl;
//     return 0;
// }


//BETTER SOLUTION WILL DEFINITELY BE LOOKING TO REMOVE OR REDUCE THE 3FOR LOOPS TO
// EITHER 2 OR MAKE SOMEWHAT BETTER

#include<iostream>
using namespace std;

int find(int arr[], int n, int t) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        int xorr = 0; // Initialize XOR for subarray starting at i
        for (int j = i; j < n; j++) {
            xorr ^= arr[j]; // Incrementally calculate XOR from i to j
            if (xorr == t) {
                count++;
            }
        }
    }
    return count;
}

int main(){
    int n; cout<<" enter the size of array : ";
    cin>>n;

    int arr[n];

    cout<<" enter the lements of array : ";
    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    int t;
    cout<<" enter the value u are looking for ";
    cin>>t;

    int answer = find(arr,n,t);

    cout<<" the number of sub arrays are : "<<answer<<endl;
    return 0;
}


// CHECK FOR OPTIMAL APPROACH AGAIN
