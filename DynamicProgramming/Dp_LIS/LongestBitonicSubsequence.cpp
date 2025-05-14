// bitonic subsequences means 
// 1. either its first increasing then decreasing 
// 2. it also means only increasing 
// 3. it also means only decreasing 
// and what we have to do is first find the bitonic subsequence of longest length
// then printing that particular bitonic subsequnce

// the approach we gonna follow is find LIS first from front 
//  then find from back 

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Simple LIS function (from idx to end, with prev)
int LIS(int idx, int prev, int n, vector<int> &arr){
    if(idx == n) return 0;

    int length = 0;
    if(prev == -1 || arr[idx] > arr[prev]){
        length = max(length, 1 + LIS(idx+1, idx, n, arr));
    }

    length = max(length, LIS(idx+1, prev, n, arr));
    return length;
}

int main(){
    int n = 8;
    vector<int> arr = {1,11,2,10,4,5,2,1};

    // Step 1: Compute LIS ending at each index (from left)
    vector<int> LISLeft(n);
    for(int i = 0; i < n; i++){
        vector<int> temp(arr.begin(), arr.begin()+i+1);
        LISLeft[i] = LIS(0, -1, temp.size(), temp);
    }

    // Step 2: Reverse the array to simulate LDS using LIS logic
    vector<int> arrRev = arr;
    reverse(arrRev.begin(), arrRev.end());

    // Compute LIS on reversed array (which is LDS from original right)
    vector<int> LISRight(n);
    for(int i = 0; i < n; i++){
        vector<int> temp(arrRev.begin(), arrRev.begin()+i+1);
        LISRight[i] = LIS(0, -1, temp.size(), temp);
    }

    // Reverse the LDS array to align with original indices
    reverse(LISRight.begin(), LISRight.end());

    // Step 3: Combine LIS and LDS
    int maxLength = 0;
    for(int i = 0; i < n; i++){
        int bitonicLen = LISLeft[i] + LISRight[i] - 1;
        maxLength = max(maxLength, bitonicLen);
    }

    cout << "the length of longest bitonic is : " << maxLength << endl;
    return 0;
}
