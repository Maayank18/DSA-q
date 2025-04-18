/*
Problem Statement:
------------------
You are given an array `arr` of positive integers. Starting from a number `start`,
you can multiply it by any number in the array and take modulo 100000 (i.e., result = (start * arr[i]) % 100000).
Your goal is to transform the start number into the `end` number in the minimum number of such operations.

Return the **minimum number of multiplications** needed to reach `end` from `start`.
If it's not possible, return -1.

Time Complexity:
----------------
O(100000 * k), where:
- 100000 is the maximum range due to modulo operation
- k = size of input array `arr`

Space Complexity:
-----------------
O(100000), for the distance array and queue
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minimumMultiplication(vector<int>& arr, int start, int end) {
    queue<pair<int, int>> q; // {current number, steps taken}
    q.push({start, 0});

    vector<int> distance(100000, 1e9); // Stores minimum steps to reach each number
    distance[start] = 0;

    int mod = 100000;

    while (!q.empty()) {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        // Try multiplying with each number in the array
        for (auto it : arr) {
            int num = (it * node) % mod;

            // If this path gives fewer steps, consider it
            if (steps + 1 < distance[num]) {
                distance[num] = steps + 1;

                // If we reached the target
                if (num == end)
                    return steps + 1;

                q.push({num, steps + 1});
            }
        }
    }

    // If we can't reach the end
    return -1;
}


// ----------- Driver Code -----------

int main() {
    vector<int> arr = {2, 5, 7};
    int start = 3;
    int end = 30;

    int result = minimumMultiplication(arr, start, end);

    cout << "Minimum number of multiplications from " << start << " to " << end << " is: " << result << endl;

    return 0;
}
