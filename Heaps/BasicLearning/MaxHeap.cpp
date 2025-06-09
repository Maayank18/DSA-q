// left child is calculated by 2*index + 1
// right child is calculated by 2*index + 2
// parent of both the child is calculated by : (index - 1)/2
// heap is always COMPLETE BINARY TREE               


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class maxHeap{
    int * arr;
    int size;  // total elements in array
    int total_size; // total size of the array
    
    public:

    maxHeap(int n){
        arr = new int[n];
        size = 0;
        total_size = n;
    }

    // insert into the heap
    void insert( int value ){
        // if there is space is heap or not 
        // overflow
        if( size == total_size){
            cout<<" heap overflow "<<endl;
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        //  putting at correct position
        while(index > 0 && arr[(index-1)/2] < arr[index]){
            swap(arr[(index-1)/2],arr[index]);
            index = (index-1)/2; //after swapping the updated index 
        }

        cout<<arr[index]<<" is inserted at correct position"<<endl;
    }


    // HEAPIFYING
    void heapify(int index ){

        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        // largest will store the index of elmeent which is gretaer 
        // between parent , left and right child

        if(leftChild < size && arr[leftChild] > arr[largest]){
            largest = leftChild;
        }

        if(rightChild < size && arr[rightChild] > arr[largest]){
            largest = rightChild;
        }


        if(largest != index){
            swap(arr[largest],arr[index]);
            heapify(largest);
        }
    }



    // deleting a given node that is always the top node
    void Delete(){
        if(size == 0){
            cout<<" heap is already empty "<<endl;
            return;
        }

        // replacing the element
        arr[0] = arr[size-1];
        size--;

        if(size == 0){
            return;
        }

        // putting the elemnt at coorect places again
        heapify(0); // name of the process given to put the top node  at correct position
    }

    void print(){
        for(int i = 0; i<size; i++){
            cout<<arr[i]<<" ";
        }
    }
};

int main(){
    maxHeap heap(6);
    heap.insert(4);
    heap.insert(14);
    heap.insert(11);
    heap.insert(6);
    heap.insert(13);
    heap.insert(7);
    heap.insert(10);
    heap.print();
    cout<<endl;
    heap.Delete();
    heap.print();
    return 0;
}