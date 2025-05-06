// Input:
// asteroids = [5, 10, -5]
// Explanation:
// The asteroid -5 is moving left and encounters 10, which is moving right.
// Since |-5| < 10, the asteroid -5 is destroyed.
// Output: [5, 10]

//BRUTE FORCE SOLUTION 
// TIME COMPLEXITY -> O(n)
// SPACE COMPLEXITY -> O(n)

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> A_C(vector<int> arr) {
    int n = arr.size();
    stack<int> st;

    for (int i = 0; i < n; i++) {
        int asteroid = arr[i];

        // Handle collisions
        while (!st.empty() && st.top() > 0 && asteroid < 0) {
            if (st.top() < abs(asteroid)) {
                // Pop the smaller positive asteroid
                st.pop();
            } else if (st.top() == abs(asteroid)) {
                // Both asteroids destroy each other
                st.pop();
                asteroid = 0;  // Set asteroid to 0 to indicate it's destroyed
                break;
            } else {
                // The current asteroid is destroyed
                asteroid = 0;
                break;
            }
        }

        // Push the asteroid to the stack if it is not destroyed
        if (asteroid != 0) {
            st.push(asteroid);
        }
    }

    // Convert stack to vector
    vector<int> result;
    while (!st.empty()) {
        result.insert(result.begin(), st.top());
        st.pop();
    }

    return result;
}

int main() {
    vector<int> arr = {5, 10, -5};

    vector<int> result = A_C(arr);

    for (int nums : result) {
        cout << nums << " ";
    }

    return 0;
}
