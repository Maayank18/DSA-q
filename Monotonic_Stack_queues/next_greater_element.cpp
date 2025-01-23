// this problem aims in finding the next element which is greater to current element
// in array if we are traversing from left to right

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Function to find the Next Greater Element for each element in the array
vector<int> NextGreaterElement(vector<int> arr) {
    int n = arr.size();
    vector<int> ans(n);  // Vector to store the result
    stack<int> st;       // Stack to keep track of potential next greater elements

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack that are smaller than or equal to arr[i]
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack is empty, no greater element exists
        if (st.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = st.top();  // Top of the stack is the next greater element
        }

        // Push the current element onto the stack
        st.push(arr[i]);
    }

    return ans;
}

int main() {
    // Input array
    vector<int> arr = {4, 5, 2, 10, 8};

    // Call the function
    vector<int> result = NextGreaterElement(arr);

    // Print the result
    cout << "Next Greater Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
