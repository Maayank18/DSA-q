#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, -1); // Initialize the result array with -1 for elements with no greater element
    stack<int> s; // Stack to store indices of elements

    // Iterate through the array twice to handle the circular array
    for (int i = 2 * n - 1; i >= 0; i--) {
        // Remove elements from the stack that are smaller or equal to the current element
        while (!s.empty() && nums[s.top()] <= nums[i % n]) {
            s.pop();
        }

        // If stack is not empty, the top of the stack is the next greater element
        if (!s.empty()) {
            result[i % n] = nums[s.top()];
        }

        // Push the current index onto the stack
        s.push(i % n);
    }

    return result;
}

int main() {
    vector<int> nums = {1, 2, 1};
    vector<int> result = nextGreaterElements(nums);

    cout << "Next Greater Elements: ";
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}


