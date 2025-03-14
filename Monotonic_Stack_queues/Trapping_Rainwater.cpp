// #include<iostream>
// #include<vector>
// using namespace std;

// int prefixMax(int index, vector<int> arr){
//     int leftmax = 0;
//     for(int i = 0; i<=index; i++){
//         leftmax = max(leftmax,arr[i]);
//     }
//     return leftmax;
// }

// int suffixMax(int index, vector<int> arr){
//     int n = arr.size();
//     int rightmax = 0;
//     for(int i = n-1; i>=index; i--){
//         rightmax = max(rightmax,arr[i]);
//     }
//     return rightmax;
// }

// int find_trapped( vector<int> arr){
//     int n = arr.size();
//     int sum = 0;
//     for(int i = 0; i<n; i++){
//         int leftMax = prefixMax(i, arr);
//         int rightMax = suffixMax(i, arr);


//          if (arr[i] < leftMax && arr[i] < rightMax) {
//             sum += min(leftMax, rightMax) - arr[i];
//         }
//     }
//     return sum;
// }

// int main(){
//     vector<int> arr ={0,1,0,2,1,0,1,3,2,1,2,1};

//     int totalWater = find_trapped(arr);

//     cout<<" the total water tarpped is : "<<totalWater<<endl;

//     return 0;
// }


// An optimised better approach 

#include<iostream>
#include<vector>
using namespace std;

int find_trapped(vector<int> arr){
    int n = arr.size();
    int l = 0;
    int r = n-1;
    int lMax = 0;
    int rMax = 0;
    int totalW = 0;

    while (l <= r) {
        if (arr[l] <= arr[r]) {
            if (lMax > arr[l]) {
                totalW += lMax - arr[l];
            } else {
                lMax = arr[l];
            }
            l++;  // Update pointer
        } else {
            if (rMax > arr[r]) {
                totalW += rMax - arr[r];
            } else {
                rMax = arr[r];
            }
            r--;  // Update pointer
        }
    }
    return totalW;
}

int main(){
    vector<int> arr ={0,1,0,2,1,0,1,3,2,1,2,1};

    int totalWater = find_trapped(arr);

    cout<<" the total water tarpped is : "<<totalWater<<endl;

    return 0;
}