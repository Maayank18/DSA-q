#include <iostream>
#include <stack>
using namespace std;

// This function inserts an element into the correct position in a sorted stack
void sortedStackInsert(stack<int> &st, int num) {
    // Base Case:
    // If stack is empty OR top element is smaller than or equal to num
    // then we have found the correct position to insert num
    if (st.empty() || st.top() <= num) {
        st.push(num); // Just push it
        return;
    }

    // If top element is greater than num, pop it and insert num recursively
    int topElement = st.top();
    st.pop();

    // Recursive call to insert num in the reduced stack
    sortedStackInsert(st, num);

    // After inserting num, push the top element back
    st.push(topElement);
}

// This function sorts the stack using recursion
void sortedStack(stack<int> &st) {
    // Base Case:
    // If stack is empty, there's nothing to sort
    if (st.empty()) {
        return;
    }

    // Pop the top element
    int num = st.top();
    st.pop();

    // Recursively sort the remaining stack
    sortedStack(st);

    // Insert the popped element back in the sorted stack
    sortedStackInsert(st, num);
}

// Utility function to print the stack (from top to bottom)
void printStack(stack<int> st) {
    cout << "Stack (Top to Bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

// Driver code
int main() {
    stack<int> st;

    // Pushing elements into the stack
    // Stack Top -> 4, 3, 6, 5, 1 (4 is the top)
    st.push(1);
    st.push(5);
    st.push(6);
    st.push(3);
    st.push(4);

    // Print original stack
    cout << "Original ";
    printStack(st);

    // Sort the stack using recursion
    sortedStack(st);

    // Print sorted stack
    cout << "Sorted ";
    printStack(st);

    return 0;
}
