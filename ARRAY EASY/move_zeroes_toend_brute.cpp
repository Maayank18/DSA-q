#include<iostream>
#include<vector>
using namespace std;

void move_zeroes(vector<int> &num){
    vector<int> temp1;

    for( int i = 0; i<num.size(); i++){
        if(num[i]!=0){
            temp1.push_back(num[i]);
        }
    }
    int nz = temp1.size();
    for(int i = 0; i<nz; i++){
        num[i] = temp1[i];
    }

    for(int i = nz; i<num.size(); i++){
        num[i] = 0;
    }
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    vector<int> num(n);
    for( int i = 0; i<num.size(); i++){
        cin>>num[i];
    }
    cout<<" Original array ";
    for( int i = 0; i<num.size(); i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;

    move_zeroes(num);

    cout<<" after rotating array ";
    for( int i = 0; i<num.size(); i++){
        cout<<num[i]<<" ";
    }
    return 0;
}
