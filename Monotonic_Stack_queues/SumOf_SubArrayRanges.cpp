#include<iostream>
#include<vector>
using namespace std;

int SumOfSubArrayRanges(vector<int> arr){
    int n = arr.size();
    int sum = 0;

    for( int i = 0; i<n; i++){
        int largest = arr[i];
        int smallest = arr[i];
        for( int j = i; j<n; j++){
            largest = max(largest,arr[j]);
            smallest = min(smallest,arr[j]);
            sum+= largest-smallest;
        }
    }
    return sum;
}

int main(){
    vector<int> arr = {1,4,3,2};
    int result = SumOfSubArrayRanges(arr);
    cout<<" the sum of subArray Ranges : "<<result<<endl;
    return 0;
}