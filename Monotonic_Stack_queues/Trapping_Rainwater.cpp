#include<iostream>
#include<vector>
using namespace std;

int prefixMax(int index, vector<int> arr){
    int leftmax = 0;
    for(int i = 0; i<=index; i++){
        leftmax = max(leftmax,arr[i]);
    }
    return leftmax;
}

int suffixMax(int index, vector<int> arr){
    int n = arr.size();
    int rightmax = 0;
    for(int i = n-1; i>=index; i--){
        rightmax = max(rightmax,arr[i]);
    }
    return rightmax;
}

int find_trapped( vector<int> arr){
    int n = arr.size();
    int sum = 0;
    for(int i = 0; i<n; i++){
        int leftMax = prefixMax(i, arr);
        int rightMax = suffixMax(i, arr);


         if (arr[i] < leftMax && arr[i] < rightMax) {
            sum += min(leftMax, rightMax) - arr[i];
        }
    }
    return sum;
}

int main(){
    vector<int> arr ={0,1,0,2,1,0,1,3,2,1,2,1};

    int totalWater = find_trapped(arr);

    cout<<" the total water tarpped is : "<<totalWater<<endl;

    return 0;
}