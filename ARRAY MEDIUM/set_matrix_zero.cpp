// SET MATRIX ZERO - it basiaclly wheneve encouters a zero at particular ppoint it converts
// that whole row and column as zero and again start finding zero and carries it move

// brute force - this solution in order to avoid any kind of error it first converts 
// the row and column to -1 and after wards it transform the -1 into 0

#include<iostream>
using namespace std;

void set_matrix_zero(int arr[], int n, int m){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(arr[i][j] == 0){
                mark_row(arr,n,m,i);
                mark_column(arr,n,m,j);
            }
        }
    }
}

void mark_row(int arr[], int n, int m, int i){
    for(int j = 0; j<m; j++){
        if(arr[i][j]!=0){
            arr[i][j] = -1;
        }
    }
}

void mark_column(int arr[], int n, int m, int j){
    for(int i = 0; i<n; i++){
        if(arr[i][j]!=0){
            arr[i][j] = -1;
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
    int arr[n][m];

    cout<<"enter the values of matrix by user : ";
    for(int i =0; i<n; i++){
        for( int j = 0; j<m; j++){
            cin>>arr[i][j];
        }
    }

    cout<<" the matrix entered by user is :";
    for(int i =0; i<n; i++){
        for( int j = 0; j<m; j++){
            cout<<arr[i][j];
        }
    }
    cout<<endl;

    set_matrix_zero(arr,n,m);

    cout<<" the matrix after setting to zero :";
    for(int i =0; i<n; i++){
        for( int j = 0; j<m; j++){
            cout<<arr[i][j];
        }
    }

    return 0;
}