// this problem basically provides a list of list in which we are given some intervals
// if some of where interval merge at any point of time merge them and give
// the finals list of list after merging them

// #include<iostream>
// #include<bits/stdc++.h>
// #include<vector>
// using namespace std;

// vector<vector<int>> merging_subIntervals(vector<vector<int>> arr){
//     int n = arr.size();
//     sort(arr.begin(), arr.end());
//     vector<vector<int>> ans;

//     for (int i = 0; i < n; i++) {
//         int start = arr[i][0];
//         int end = arr[i][1];

//         if (!ans.empty() && end <= ans.back()[1]) {
//             continue;
//         }

//         for (int j = i + 1; j < n; j++) {
//             if (arr[j][0] <= end) {
//                 end = max(end, arr[j][1]);
//             } else {
//                 break;
//             }
//         }
//         ans.push_back({start, end});
//     }
//     return ans;
// }

// int main(){

//     vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

//     vector<vector<int>> result = merging_subIntervals(arr);

//     cout << "The merged intervals are: " << "\n";
//     for (auto it : result) {
//         cout << "[" << it[0] << ", " << it[1] << "] ";
//     }
//     cout << endl;
//     return 0;
// }


// OPTIMAL SOLUTION 


#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<vector<int>> merging_subIntervals(vector<vector<int>> arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for( int i = 0; i<n; i++){
        if( ans.empty() || ans.back()[1] < arr[i][0]){
            ans.push_back(arr[i]);

        }else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}

int main(){

    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> result = merging_subIntervals(arr);

    cout << "The merged intervals are: " << "\n";
    for (auto it : result) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}