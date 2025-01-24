#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> NextGreaterElement( vector<int> arr){
    int n = arr.size();
    stack<int> st;

    for( int i = 0; i<n; i++){
        while(!st.empty() && ){

        }
    }
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