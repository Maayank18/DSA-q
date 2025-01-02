// what does next permutation means is , let us suppose that we have [3,1,2] as the numbers
// and all possible permutation for it will be [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2]
// and [3,2,1] so the answer will be [3,2,1] in this case 
// 1. generate all sub-arrays using recurssion
// 2. linear search for given permutation
// 3. answer will be next index to linear search

// ** brute force solutionn will end up taking a very long n! x n timecomplexity which is 
// very very very high and we should generally avoid it 

// the better solution contains an INbuild fucntion next_permutation has we can directly
// jump on the  code for its inbuild fucntion as optimal solution

//  optimal solution :-

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> next_permu( vector<int> &arr){
    int n = arr.size();
    int idx = -1;
    for( int i = n-2; i>=0; i--){
        if(arr[i]<arr[i+1]){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for( int i = n-1; i>idx; i--){
        if(arr[i]>arr[idx]){
            swap(arr[i],arr[idx]);
            break;
        }
    }

    reverse(arr.begin() + idx + 1, arr.end());
    for(auto it :arr){
        cout<<it;
    }
    return arr;
}

int main(){
    int n = 7;
    vector<int> arr = {2,1,5,4,3,0,0};

    vector<int> answer = next_permu(arr);

    return 0;
}

