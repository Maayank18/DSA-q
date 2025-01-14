// this problem aims in rotating  the given array by 90 degrees

// brute force solution basically is a pen apper appproach where we have to figure out
// a pattern for placing the numbers after rotating
//TIME COMPLEXITY -> O(N^2)
//SPACE  COMPLEXITY -> O(N^2)

// #include<iostream>
// using namespace std;
// const int MAX_SIZE = 100;



// void Roate_90(int arr[MAX_SIZE][MAX_SIZE], int n, int m){
//     int ans[MAX_SIZE][MAX_SIZE];
//     for( int i = 0; i<n; i++){
//         for( int j = 0; j<m; j++){
//             ans[j][n-i-1] = arr[i][j];
//         }
//     }

//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             arr[i][j] = ans[i][j];
//         }
//     }
// }


// int main(){
//     int n;
//     cout<<" enter the numbers of rows : ";
//     cin>>n;

//     int m;
//     cout<<" enter the numbers of column : ";
//     cin>>m;
//     int arr[MAX_SIZE][MAX_SIZE];

//     cout<<"enter the values of matrix by user : ";
//     for(int i =0; i<n; i++){
//         for( int j = 0; j<m; j++){
//             cin>>arr[i][j];
//         }
//     }

//     cout<<" the matrix entered by user is :";
//     for(int i =0; i<n; i++){
//         for( int j = 0; j<m; j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }
//     cout<<endl;

//     Roate_90(arr,n,m);

//     cout<<" the matrix after setting to zero :";
//     for(int i =0; i<n; i++){
//         for( int j = 0; j<m; j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }

//     return 0;
// }


// AN OPTIMAL APPROACH WOULD AVOID USING EXTRA SPACE AND TRY TO MAKE CHANGES IN THE 
// GIVEN CODE ONLY
// THAT IS BY -> Transposing the matrix

#include<iostream>
using namespace std;
const int MAX_SIZE = 100;



void Roate_90(int arr[MAX_SIZE][MAX_SIZE], int n, int m){

    for( int i = 0; i<n; i++){
        for( int j = 0; j<m; j++){
            swap(arr[i][j],arr[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        int start = 0, end = m - 1;
        while (start < end) {
            swap(arr[i][start], arr[i][end]);
            start++;
            end--;
        }
    }
}


int main(){
    int n;
    cout<<" enter the numbers of rows : ";
    cin>>n;

    int m;
    cout<<" enter the numbers of column : ";
    cin>>m;
    int arr[MAX_SIZE][MAX_SIZE];

    cout<<"enter the values of matrix by user : ";
    for(int i =0; i<n; i++){
        for( int j = 0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    cout<<" the matrix entered by user is :";
    for(int i =0; i<n; i++){
        for( int j = 0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    Roate_90(arr,n,m);

    cout<<" the matrix after setting to zero :";
    for(int i =0; i<n; i++){
        for( int j = 0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}