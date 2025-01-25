#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> NextGreaterElement( vector<int> arr){
    int n = arr.size();
    vector<int> ans(n,-1);
    stack<int> st;

    for( int i = n-1; i>=0; i--){
        while(!st.empty() && st.top()>=arr[i]){
            st.pop();
        }

        if(!st.empty()){
            ans[i] = st.top();
        }

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