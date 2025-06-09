// min heap is just opposite of the max heap problem where the parent element 
// is smaller than its child node

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class minHeap{
    int * arr;
    int size = 0; // elements in array
    int total_size = 0; // size of array 

    public:

    minHeap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // insertion in the array 
    void insert(int value){
        // check if my array is already filled 
        if(size == total_size){
            cout<<" heap overflow !"<<endl;
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        // putting at correct position
        while( index >= 0 && arr[index] < arr[(index-1)/2]){
            swap(arr[index], arr[(index-1)/2]);
            index = (index-1)/2;
        }
        cout<<arr[index]<<" inserted at correct position "<<endl;
    }

    void heapify(int index){

        int smallest = index;
        int leftChild = 2*index + 1;
        int rightChild = 2*index + 2;

        if(leftChild < size && arr[leftChild] < arr[smallest]){
            smallest = leftChild;
        }

        if(rightChild < size && arr[rightChild] < arr[smallest]){
            smallest = rightChild;
        }

        if(smallest != index){
            swap(arr[smallest], arr[index]); // FIXED: correct usage of swap
            heapify(smallest);
        }
    }

    // deleting the element in heap
    void Delete(){
        // check if our heap is empty or not 
        if( size == 0){
            cout<<" the heap underflow "<<endl;
            return;
        }

        // we always delete the root element and replace with the newest elemet added 
        arr[0] = arr[size-1];
        size--;

        // putting the element at 0th index to its correct place 
        heapify(0);
    }

    // printing the whole array of heap to see the positions
    void print(){
        for( int i = 0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl; // added to move to next line after printing
    }
};

int main(){
    minHeap heap(6);
    heap.insert(10);
    heap.insert(11);
    heap.insert(15);
    heap.insert(18);
    heap.insert(7);
    heap.print();
    heap.Delete();
    heap.print();
    return 0;
}
