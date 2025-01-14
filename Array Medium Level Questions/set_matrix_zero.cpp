// SET MATRIX ZERO - it basiaclly wheneve encouters a zero at particular ppoint it converts
// that whole row and column as zero and again start finding zero and carries it move

// brute force - this solution in order to avoid any kind of error it first converts 
// the row and column to -1 and after wards it transform the -1 into 0

//TIME COMPLEXITY -> O(NxM) x O(N+M) + O(NxM)
//SPACE COMPLEXITY -> O(1)

// #include<iostream>
// using namespace std;
// const int MAX_SIZE = 100;

// void matrix_minus_one_row( int arr[MAX_SIZE][MAX_SIZE], int i, int j, int m){
//     for( int j = 0; j<m; j++){
//         if(arr[i][j] != 0){
//             arr[i][j] = -1;
//         }
//     }
// }

// void matrix_minus_one_column( int arr[MAX_SIZE][MAX_SIZE], int i, int j, int n){
//     for( int i = 0; i<n; i++){
//         if(arr[i][j] != 0){
//             arr[i][j] = -1;
//         }
//     }
// }

// void set_matrix_zero(int arr[MAX_SIZE][MAX_SIZE], int n, int m){
//     for( int i = 0; i<n; i++){
//         for(int j = 0; j<m; j++){
//             if( arr[i][j] == 0){
//                 matrix_minus_one_row(arr,i,j,m);
//                 matrix_minus_one_column(arr,i,j,n);
//             }
//         }
//     }

//     for( int i =0; i<n; i++){
//         for( int j = 0; j<m; j++){
//             if(arr[i][j] == -1){
//                 arr[i][j] = 0;
//             }
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
//             cout<<arr[i][j];
//         }
//     }
//     cout<<endl;

//     set_matrix_zero(arr,n,m);

//     cout<<" the matrix after setting to zero :";
//     for(int i =0; i<n; i++){
//         for( int j = 0; j<m; j++){
//             cout<<arr[i][j]<<" ";
//         }
//         cout<<endl;
//     }

//     return 0;
// }


// Better solution than brute force which aims to keep an marks on row number and 
// column number as soon as we encounter an 0;

// TIME COMPLEXITY -> O(NxM) + O(NxM)
//SPACE COMPLEXITY -> O(n) + O(m)

#include<iostream>
using namespace std;
const int MAX_SIZE = 100;



void set_matrix_zero(int arr[MAX_SIZE][MAX_SIZE], int n, int m){
    int col[m] = {0};
    int row[n] = {0};
    for( int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if( arr[i][j] == 0){
                col[j] = 1;
                row[i] = 1;
            }
        }
    }

    for( int i =0; i<n; i++){
        for( int j = 0; j<m; j++){
            if(col[j] || row[i]){
                arr[i][j] = 0;
            }
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

    set_matrix_zero(arr,n,m);

    cout<<" the matrix after setting to zero :";
    for(int i =0; i<n; i++){
        for( int j = 0; j<m; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}



// DO CHECK FOR OPTIMAL CASE AS WHAT CAN WE DO IS WE CANT FURTHER REDUCE THE TIME 
// COMPLEXITY BUT SOMETHING COULD HAVE BEEN DONE FOR THE SPACE 