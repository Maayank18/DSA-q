// sorting use a heap can be done in two ways 

// WAY 1
// we will use max heap for this
// when we delete an element the top most element the max element is popped/removed
// we can add that removed element to new datastructure and find our sortde heap in DESCENDING ORDER
// tc -> nlogn and sc -> n


// WAY 2 
// when we remove an eleemnt the last index is spared and is empty 
//  what we can do is when we swap we want decrease size of the heap array 
// instead we just apply the hapify operation from the one size less the original
//  no use of extra data structure
//  tc -> nlogn , sc -> o(1)


#include <iostream>
#include <vector>
#include <algorithm> // for swap
using namespace std;

// Fix 1: Remove shadowing of variable `n` inside heapify
void heapify(vector<int> &heap, int index, int n) {
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < n && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }

    if (rightChild < n && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(heap[largest], heap[index]);
        heapify(heap, largest, n);
    }
}

// Fix 2: Loop should go from n/2 - 1 **down to 0**, not i > 0
void BuildMaxHeap(vector<int> &heap) {
    int n = heap.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(heap, i, n); // Fix 3: Pass full heap size, not i
    }
}

// Convert max-heap to sorted array (heap sort)
void sortHeap(vector<int> &heap) {
    int n = heap.size();

    for (int i = n - 1; i >= 1; i--) {
        swap(heap[0], heap[i]); // Move max to end
        heapify(heap, 0, i);    // Re-heapify the reduced heap
    }
}

void printMaxHeap(const vector<int> &heap) {
    for (int val : heap) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    vector<int> heap = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};

    BuildMaxHeap(heap);   // Step 1: Build the max heap
    sortHeap(heap);       // Step 2: Heap sort
    printMaxHeap(heap);   // Step 3: Print sorted array

    return 0;
}
