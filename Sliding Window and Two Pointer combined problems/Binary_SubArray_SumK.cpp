// 

// BRUTE FORCE SOLUTION : in this case we will be using the 2 for loop approach 
// and generate all subarray and calculate the sum and if the sum is equal to 
// k then we can increment the counetr and at last we can return the count

// TIME COMPLEXITY -> O(N^2)
// SPACE COMLEXITY -> O(1) auxillary space and O(N)-input space 
// #include<iostream>
// #include<vector>
// using namespace std;

// int SubArrayCount(vector<int> arr, int k){
//     int n = arr.size();
//     int count = 0;
//     for(int i = 0; i<n; i++){
//         int sum = 0;
//         for(int j = i; j<n; j++){
//             sum+=arr[j];
//             if(sum == k) count++;
//         }
//     }
//     return count;
// }

// int main(){
//     vector<int> arr = {1,0,1,0};
//     int totalSubArray = SubArrayCount(arr,2);
//     cout<<" the total count is : "<<totalSubArray<<endl;
//     return 0;
// }



// BETTER SOLUTION - A better solution will involve usage sliding window and 
// two pointer approach
// TIME COMLEXIYT -> O(N)
// SPACE COMPLEXITY -> O(1) 
#include<iostream>
#include<vector>
using namespace std;

int SubArrayCount(vector<int> arr, int k){
    int n = arr.size();
    int left = 0; 
    int right = 0;
    int counter = 0;
    int sum = 0;
    while(right<n){
        sum+=arr[right];
        if(sum>k && left<=right){
            sum-=arr[left++];
        }
        if(sum == k ){
            counter++;
        }
        right++;
    }
    return counter;
}

int main(){
    vector<int> arr = {1,0,1,0};
    int totalSubArray = SubArrayCount(arr,2);
    cout<<" the total count is : "<<totalSubArray<<endl;
    return 0;
}