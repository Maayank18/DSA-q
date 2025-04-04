#include <iostream>
#include <stack>
using namespace std;

// This function inserts 'num' at the bottom of the stack
void reversing(stack<int> &stack, int num) {
    // Base Case:
    // If the stack is empty, we have reached the bottom
    if (stack.empty()) {
        stack.push(num); // Push the number at the bottom
        return;
    }

    // Store the top element and remove it
    int topElement = stack.top();
    stack.pop();

    // Recursively call to go deeper into the stack
    reversing(stack, num);

    // Push back the stored element after num is inserted at the bottom
    stack.push(topElement);
}

// This function reverses the stack using recursion
void reverseStack(stack<int> &st) {
    // Base Case:
    // If the stack is empty, there's nothing to reverse
    if (st.empty()) {
        return;
    }

    // Remove the top element
    int topElement = st.top();
    st.pop();

    // Recursively reverse the remaining stack
    reverseStack(st);

    // Insert the removed element at the bottom
    reversing(st, topElement);
}

// Utility function to print the stack (Top to Bottom)
void printStack(stack<int> st) {
    cout << "Stack (Top to Bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

// Main function to test the reversal
int main() {
    stack<int> st;

    // Pushing elements into the stack
    // Stack Top -> 4, 3, 6, 5, 1 (4 is the top element pushed last)
    st.push(1);
    st.push(5);
    st.push(6);
    st.push(3);
    st.push(4);

    // Print original stack
    cout << "Original ";
    printStack(st);

    // Reverse the stack using recursion
    reverseStack(st);

    // Print reversed stack
    cout << "Reversed ";
    printStack(st);

    return 0;
}
