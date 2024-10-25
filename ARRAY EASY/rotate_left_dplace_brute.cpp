#include<iostream>
#include<vector>
using namespace std;

void rotate_d( vector<int> &num, int n, int d){
    vector<int> temp;
    d = d % n;

    for(int i = 0; i<d; i++){
        temp.push_back(num[i]);
    }

    for( int i = d; i<n; i++){
        num[i-d] = num[i];
    }

    for(int i = n-d; i<n; i++){
        num[i] =  temp[i-(n-d)];
    }
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;
    cout<<endl;
    int d;
    cout<<" enter the number of spaces you want to shift : ";
    cin>>d;

    vector<int> num(n);
    for( int i = 0; i<num.size(); i++){
        cin>>num[i];
    }
    cout<<" Original array ";
    for( int i = 0; i<num.size(); i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;

    rotate_d(num,n,d);

    cout<<" after rotating array ";
    for( int i = 0; i<num.size(); i++){
        cout<<num[i]<<" ";
    }
    return 0;
}