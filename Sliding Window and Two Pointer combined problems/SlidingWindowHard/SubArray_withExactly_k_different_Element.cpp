

// BRUTE FORCE SOLUTION
// TIME COMPLEXITY -> O(N^2) - almost
// SPACE COMPLEXITY -> O(N) - in case all the numbers are unique
// #include<iostream>
// #include<vector>
// #include<map>
// using namespace std;

// int CountingSubArrays(vector<int> arr, int k){
//     int n = arr.size();
//     int counter  = 0;
//     for(int i = 0; i<n; i++){
//         map<int,int>mpp;
//         for(int j = i; j<n; j++){
//             mpp[arr[j]]++;
//             if(mpp.size() == k){
//                 counter++;
//             }else if(mpp.size()>k){
//                 break;
//             }
//         }
//     }
//     return counter;
// }

// int main(){
//     vector<int> arr ={1,2,1,3,4};
//     int result = CountingSubArrays(arr,3);
//     cout<<" the answer is : "<<result<<endl;
//     return 0;
// }


// NOT OPTIMAL BUT A BETTER 
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int f(vector<int> arr, int k){
    int n = arr.size();
    int l = 0;
    int countt = 0;
    map<int,int> mpp;

    for(int r = 0; r < n; r++){
        mpp[arr[r]]++;

        while(mpp.size() > k){
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0){
                mpp.erase(arr[l]);
            }
            l++; // Fix: Move `l` forward
        }

        countt += (r - l + 1); // Fix: Count all valid subarrays
    }
    return countt;
}

int CountingSubArrays(vector<int> arr, int k){
    return f(arr, k) - f(arr, k - 1);
}

int main(){
    vector<int> arr = {1, 2, 1, 3, 4};
    int result = CountingSubArrays(arr, 3);
    cout << "The answer is: " << result << endl;
    return 0;
}
