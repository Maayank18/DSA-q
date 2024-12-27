// minimum element in rotated array can be found using binary search using somewhat
// similar concept of slashing out the unsorted arrays 

// step 1 -> storing the lowest in sorted array that is the mid
// step 2 -> find in unsorted array if it can replace the answer stored in it
// and similarly following this loop we can iterate

#include <iostream>
#include <climits> // For INT_MAX
using namespace std;

int minimum_in_rotated(int arr[], int n) {
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // If the subarray is sorted
        if (arr[low] <= arr[mid]) {
            ans = min(ans, arr[low]);
            low = mid + 1;
        } else {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans; // Return the minimum value
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

    int result = minimum_in_rotated(arr, n);
    cout << "The minimum element in the rotated array is: " << result << endl;

    return 0;
}
