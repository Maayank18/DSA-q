#include <iostream>
using namespace std;

void reverse(int arr[], int left, int right) {
    if (left >= right) return;
    swap(arr[left], arr[right]);
    reverse(arr, left + 1, right - 1);
}

int main() {
    int n;
    cin >> n;
    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Reverse the array
    reverse(arr, 0, n - 1);

    // Output the reversed array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
