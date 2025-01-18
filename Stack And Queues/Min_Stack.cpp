// This problem basically aims to find a NEW OPERATION called min whi h find the 
// minimum operation present in the stack after before push pop and any other
// function call

// One of the brute force operation tells about like scanning the stack again and again
// which would increase the time complexity to O(N) so we will directly ignore
// it and think of better solution


//BETTER SOLUTION -> USING OF MIN() that is:
// TIME COMPLEXITY -> O(1)
// SPACE COMPLEXITY -> O(2N) storing the numbers in pair


// #include<iostream>
// #include<stack>
// using namespace std;

// class myStack{
//     stack<pair<int,int>> st;

//     public:
//     void pushValue( int value){
//         if(st.empty()){
//             st.push({value,value});
//         }else{
//             st.push({value, min(value,st.top().second)});
//         }
//         cout<<" the pushed value is "<<value<<endl;
//     }

//     void popValue(){
//         st.pop();
//     }

//     int getMin(){
//         return st.top().second;
//     }
// };

// int main(){
//     myStack s;
//     s.pushValue(10);
//     s.pushValue(7);
//     s.pushValue(31);
//     s.pushValue(2);
//     s.popValue();
//     cout<<" the minimum value in stack is : "<<s.getMin()<<endl;
//     return 0;

// }



// The optimal Solution having :
// TIME COMPLEXITY - O(1)
// SPACE COMPEXITY - O(N)
// There is a formula to be kept in mind 

// while pushing -> 2 x value - previvous_minimum = new_minimum
// while poping -> 2 x value - new_minimum = previous_minimum

#include <iostream>
#include <stack>
using namespace std;

class myStack {
    stack<int> st;
    int min;

public:

    void pushValue(int value) {
        if (st.empty()) {
            min = value;  // Initialize min when the stack is empty.
            st.push(value);
        } else {
            if (value >= min) {
                st.push(value);  // Normal push when value is greater than or equal to current min
            } else {
                st.push(2 * value - min);  // Encode new minimum value
                min = value;  // Update the current minimum value
            }
        }
    }

    void popValue() {
        if (st.empty()) {
            return;  // If the stack is empty, do nothing.
        } else {
            int x = st.top();
            st.pop();
            if (x < min) {  // This means the popped element was the minimum
                min = 2 * min - x;  // Recover the old minimum value
            }
        }
    }

    int getMin() {
        return min;  // Return the current minimum value
    }
};

int main() {
    myStack s;
    s.pushValue(10);
    s.pushValue(7);
    s.pushValue(31);
    s.pushValue(2);
    s.popValue();
    cout << "The minimum value in the stack is: " << s.getMin() << endl;  // Output should be 7
    return 0;
}
