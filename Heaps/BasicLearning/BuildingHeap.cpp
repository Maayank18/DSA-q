// min heap and max heap are giving the time complexity of O(nlogn)
// even if we build heap by step up that is comparinf child with parent 
// will again give us O(nlogn) and space o(n)

// BUT IF WE DO step down heapify mwthod
// we can achive the O(n) time complexity 
// n/2 -1 gives the index of last non leaf node
// leaf node =  ndoe with no children 



// BUILDING MAX HEAP
// TC -> O(N)
// SC -> O(logN)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &arr, int index){
    int n = arr.size();

    int largest = index;
    int leftChild = 2* index + 1;
    int rightChild = 2* index + 2;

    if(leftChild < n && arr[leftChild] > arr[largest]){
        largest = leftChild;
    }

    if(rightChild < n && arr[rightChild] > arr[largest]){
        largest = rightChild;
    }

    if(largest != index){
        swap(arr[largest],arr[index]);
        heapify(arr,largest); // RECUSRION O(LOGN)
    }

}

void buildMaxHeap(vector<int> &arr){
    int n = arr.size();

    // step down fro O(n)
    for(int i = n/2 - 1; i>=0; i--){
        heapify(arr,i);
    }

}


void printHeap(vector<int> &arr){
    for(int i = 0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    vector<int> arr = {10,3,8,9,5,13,18,14,11,70};
    buildMaxHeap(arr);
    printHeap(arr);
    return 0;
}