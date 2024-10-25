//REDO REATCH REATTEMPT


#include <iostream>

using namespace std;

void move_zeroes(int arr[], int n) {
    int j = 0; // Pointer for the next non-zero element
    // Traverse the array
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            // Swap non-zero element with the element at index j
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            j++;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    move_zeroes(arr, n);

    cout << "Array after moving zeroes: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
