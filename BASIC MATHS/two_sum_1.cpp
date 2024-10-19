#include <iostream>
#include <utility> // For std::pair
using namespace std;

pair<int, int> twosum(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                return make_pair(i, j); // Return the indices as a pair
            }
        }
    }
    return make_pair(-1, -1); // Return -1, -1 if no solution is found
}

int main() {
    int arr[5] = {1, 2, 4, 6, 7}; // Array size corrected to 5
    int n = 5;
    int target = 11;
    pair<int, int> result = twosum(arr, n, target);

    if (result.first != -1) {
        cout << "Indices: " << result.first << ", " << result.second << endl;
    } else {
        cout << "No two numbers found that sum up to the target." << endl;
    }

    return 0;
}
