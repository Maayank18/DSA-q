#include <bits/stdc++.h>
using namespace std;

int length_longest_subArray(int arr[], int n, long long k) {
    map<long long, int> preSum; // To store the prefix sums and their first occurrence index
    int maxlen = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Incrementally add elements to the sum

        // Check if the current prefix sum equals the target
        if (sum == k) {
            maxlen = max(maxlen, i + 1); // Update maxlen if the whole subarray from 0 to i matches
        }

        // Check if (sum - k) is already in the map, meaning a subarray with sum k was found
        long long rem = sum - k;
        if (preSum.find(rem) != preSum.end()) {
            int len = i - preSum[rem]; // Calculate the length of the subarray
            maxlen = max(maxlen, len); // Update maxlen if this subarray is longer
        }

        // Store the current prefix sum in the map if not already present
        if (preSum.find(sum) == preSum.end()) {
            preSum[sum] = i;
        }
    }

    return maxlen;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    long long t;
    cout << "Enter the sum required: ";
    cin >> t;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array entered by user: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int length = length_longest_subArray(arr, n, t);
    cout << "The length of the longest subarray is: " << length << endl;

    return 0;
}
