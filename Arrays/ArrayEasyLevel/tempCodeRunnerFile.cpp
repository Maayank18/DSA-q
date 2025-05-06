// the brute force solution contain a basic approach to find the solution where
// //General case for SORTED ARRAYS ONLY 
// // we can use a set data structure or map ds which would ensure that the following contains
// //only unique elemenst and no duplicates are present 
// //TC -> o(n1 logn)+O(n2 logn)+ O(n1+n2) and space complexity of O(n1+n2)

// #include<iostream>
// #include<bits/stdc++.h>
// using namespace std;

// vector<int> unionA (vector<int> a, vector<int> b){
//     vector<int> Union;
//     int n1 = a.size();
//     int n2 = b.size();
//     int i = 0;
//     int b = 0;

//     set<int> st;

//     for(int i = 0; i<n1; i++){
//         st.insert(a[i]);
//     }
//     for(int i = 0; i<n2; i++){
//         st.insert(b[i]);
//     }

//     for( auto it : st){
//         Union.push_back(it);
//     }

//     return Union;
// }

// int main() {
//     vector<int> arr1 = {1, 2, 4, 5, 6};
//     vector<int> arr2 = {2, 3, 5, 7};

//     vector<int> unionResult = unionA(arr1, arr2);

//     cout << "Union of the two sorted arrays: ";
//     for (int elem : unionResult) {
//         cout << elem << " ";
//     }

//     return 0;
// }