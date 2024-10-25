//RE DO RE WATCH RE ATTEMPT

#include<iostream>
#include<vector>
using namespace std;

void delete_dup( vector<int> arr,int n){
    for(int i = 0; i<arr.size()-1; i++){
        for( int j = i+1; j<arr.size(); j++){
            if(arr[i] == arr[j]){
                arr.erase(arr.begin()+i-1);
            }
        }
    }
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;
    vector<int> arr(n);

    for(int i = 0; i<arr.size(); i++){
         cin>>arr[i];
    }

    cout<<" the array entered by user : ";
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    delete_dup(arr,n);
    cout<<" the array after removing duplicates : ";
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}