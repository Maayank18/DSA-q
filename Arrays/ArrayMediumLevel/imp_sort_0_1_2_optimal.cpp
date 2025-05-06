// brute force approach will wbe to apply merge sort whcih will traverse the
// array and merge it it can use any sorting technique and will end up having a time 
//complexity of O(nlogn) -> O(n^2)



// better solution will keeping a counter sytem and adding of arrays to a temproray 
// and overall time compelxity will be O(n) and space comlexity O(1)
void sort( int arr[], int n){
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;
    for( int i = 0; i<n; i++ ){
        if(arr[i] == 0){
            cnt0++;
        }else if (arr[i] == 1)
        {
            cnt1++;
        }else{
            cnt2++;
        }
    }

    for( int i = 0; i<cnt0; i++){
        arr[i] = 0;
    }
    for( int i = cnt0; i<cnt1 ;i++){
        arr[i] = 1;
    }
    for( int i = cnt0+cnt1; i<cnt2; i++){
        arr[i] = 2;
    }
}

// another better solution would include a simpler approach 
// having a time complexity O(n) and Space complexity O(n)

#include <iostream>
#include <vector>
using namespace std;

vector<int> sorting(vector<int> &arr) {
    int n = arr.size();
    vector<int> temp;
    vector<int> zero;
    vector<int> one;
    vector<int> two;

    // Separate the elements into 0, 1, and 2 buckets
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            zero.push_back(arr[i]);
        } else if (arr[i] == 1) {
            one.push_back(arr[i]);
        } else {
            two.push_back(arr[i]);
        }
    }

    // Merge all buckets back into the temp array
    for (int i = 0; i < zero.size(); i++) {
        temp.push_back(zero[i]);
    }
    for (int i = 0; i < one.size(); i++) {
        temp.push_back(one[i]);
    }
    for (int i = 0; i < two.size(); i++) {
        temp.push_back(two[i]);
    }
    return temp;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> array(n);

    cout << "Enter the elements of the array (only 0, 1, and 2): ";
    for (int i = 0; i < array.size(); i++) {
        cin >> array[i];
    }

    cout << "Entered array by user: ";
    for (int i = 0; i < array.size(); i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    vector<int> sortedArray = sorting(array);

    cout << "Sorted array: ";
    for (int i = 0; i < sortedArray.size(); i++) {
        cout << sortedArray[i] << " ";
    }
    return 0;
}


// DUTCH NATIONAL FLAG algorithm
//consider that from 0 to low-1  it will be having all zeroes 
// from low to mid-1 it will be having all ones 
// from mid to high it will be having unsorted array of 0/1/2 
// from high+1 to n-1 it will be having all twos

// timme complexity will e O(n) and space complexity is O(1)

#include<bits/stdc++.h>
using namespace std;

void sort_algo( int arr[], int n){
    int low = 0, mid = 0, high = n-1;
    while(mid<=high){
        if(arr[mid] == 0){
            swap(arr[mid],arr[low]);
            mid++;
            low++;
        }else if(arr[mid] == 1){
            mid++;
        }else{
            swap(arr[high],arr[mid]);
            high--;
        }
    }
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    int arr[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }
    cout<<" original array : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    sort_algo(arr,n);
    cout<<" soted array : ";
    for(int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}