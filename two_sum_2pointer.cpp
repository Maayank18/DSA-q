#include<iostream>
using namespace std;

pair<int,int> find(int arr[], int n, int target){
    int left = 0;
    int right = n-1;
    while(left<right){
        if(arr[left]+arr[right]<target){
            left++;
        }else if (arr[left]+arr[right]>target)
        {
            right--;
        }else{
            return make_pair(left,right);
        }
        
    }
    return make_pair(-1,-1);
}
int main(){
    int arr[5] = {1,2,6,5,7};
    int n = 5;
    int target = 11;

    pair<int,int> result = find(arr,n,11);
    if (result.first != -1) {
        cout << "Indices: " << result.first << ", " << result.second << endl;
    } else {
        cout << "No pair found" << endl;
    }
    return 0;
}

