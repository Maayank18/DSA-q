#include<iostream>
#include<vector>
using namespace std;
// brute force approach where the timecomplexity is about O(n)+O(n/2) and space o(n)
void alternate_arrangement( vector<int> &arr, int n){
    vector<int> pos;
    vector<int> neg;

    for(int i = 0; i<arr.size(); i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);
        }
    }
    int i = 0, j = 0, k= 0;

    while(i<pos.size() && j<neg.size()){
        arr[k++] = pos[i++];
        arr[k++] = neg[j++];
    }

    while(i<pos.size()){
        arr[k++] = pos[i++];
    }
    while(j<neg.size()){
        arr[k++] = neg[j++];
    }
}

int main(){
    int n;
    cout<<" enter the size of array ";
    cin>>n;
    vector<int> arr(n);

    for( int i = 0; i<arr.size(); i++){
        cin>>arr[i];
    }
    cout<<" the entered array by user is : ";
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i];
    }
    cout<<endl;

    alternate_arrangement(arr,n);

    cout<<" After the function call : ";
    for( int i = 0; i<arr.size(); i++){
        cout<<arr[i];
    }
    return 0;
}

// talking about the optimal approach which is gonna be we dont create any extra 
//vector space and directly assign the value in them

int n = num.size();
int posIN = 0, negIn = 1;
for( int i = 0; i<num.size(); i++){
    if(arr[i]>0){
        ans[posIN] = arr[i];
        posIN+=2;
    }else{
        ans[negIn] = arr[i];
        negIn+=2;
    }
    retunr ans;
}

// in this case the ans is the new vector where we stored our required new re arranged 
//array and the TIME COMPLEXITY IS O(n) and space is also o(n)