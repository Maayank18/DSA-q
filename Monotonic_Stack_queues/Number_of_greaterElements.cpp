// This problem basically aims on find the the strictly greater next element that 
// is present 
// Example:
// Input: [3, 4, 2, 7, 5]
// Output: [3, 2, 2, 0, 0]
// Explanation:
// For 3: Greater elements to the right are [4, 7, 5] → count is 3.
// For 4: Greater elements to the right are [7, 5] → count is 2.
// For 2: Greater elements to the right are [7, 5] → count is 2.
// For 7: No greater elements → count is 0.
// For 5: No greater elements → count is 0.


// A naive solution would involve comparing every element to every other element
// on its right but this has O(n²) complexity.

// #include<iostream>
// #include<stack>
// #include<vector>
// using namespace std;

// vector<int> No_of_GreaterElements(vector<int> arr){
//     int n = arr.size();
//     vector<int> ans;

//     for( int i = 0; i<n; i++){
//         int count = 0;
//         for( int j = i+1; j<n; j++){
//             if(arr[j] > arr[i]){
//                 count++;
//             }
//         }
//         ans.push_back(count);
//     }
//     return ans;
// }

// int main(){
//     vector<int> arr = {3, 4, 2, 7, 5};

//     vector<int> result = No_of_GreaterElements(arr);
//     cout<<"The number of next greater elements are ";

//     for( int nums : result){
//         cout<<nums<<" ";
//     }
//     return 0;
// }


// A better and more optimal approach that can be used is of stack , which would
// help to solve the problem of remembering the numbers 

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> countNextGreaterElements(const vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, 0);  // To store the count of NGEs for each element
    stack<int> st;  // Stack to keep track of elements

    // Traverse from right to left
    for (int i = n - 1; i >= 0; --i) {
        // Pop elements from the stack that are <= current element
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // The size of the stack is the count of greater elements to the right
        result[i] = st.size();

        // Push the current element to the stack
        st.push(arr[i]);
    }

    return result;
}

int main() {
    vector<int> arr = {3, 4, 2, 7, 5};
    vector<int> result = countNextGreaterElements(arr);

    // Print the result
    for (int count : result) {
        cout << count << " ";
    }

    return 0;
}

