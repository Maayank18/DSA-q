// Maximum Consecutive Zeros III (Sliding Window Approach)
// The problem asks us to find the longest subarray that contains at most k
// zeros after flipping some zeros to ones.

// EXAMPLE 
// arr = [1,1,0,0,1,1,0,1,1,1,0], k = 2
// 8 (longest valid subarray)


#include<iostream>
#include<vector>
using namespace std;

int lengthLongestSubArrayWith1(vector<int> arr, int k){
    int n = arr.size();
    int maxlen = 0;

    for(int i = 0; i<n; i++){
        int zeroCounter = 0;
        for(int j = i; j<n; j++){
            if(arr[j] == 0){
                zeroCounter++;
            }
            if(zeroCounter<=k){
                maxlen = max(maxlen,j-i+1);
            }else{
                break;
            }
        }
    }
    return maxlen;
}

int main() {
    vector<int> arr = {1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0};
    int k = 2;
    
    cout << "Longest subarray length: " << lengthLongestSubArrayWith1(arr, k) << endl;
    return 0;
}


// This is the better solution where we would be using a sliding window and
// two pointer approach 
// TIME COMPLEXITY -> O(N) + O(N) = O(2N)
// SPACE COMPLEXITY -> O(1)
#include<iostream>
#include<vector>
using namespace std;

int lengthLongestSubArrayWith1(vector<int> arr, int k){
    int n = arr.size();
    int l = 0;
    int r = 0;
    int maxlen = 0;
    int zeroC = 0;

    while(r<n){
        if(arr[r] == 0){
            zeroC++;
        }
        while(zeroC>k){
            if(arr[l] == 0) zeroC--;
            l++;
        }
        if(zeroC<=k){
            maxlen = max(maxlen,r-l+1);
            r++;
        }
    }
    return maxlen;
}

int main() {
    vector<int> arr = {1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0};
    int k = 2;
    
    cout << "Longest subarray length: " << lengthLongestSubArrayWith1(arr, k) << endl;
    return 0;
}


// Till the better solution interviewer might be happy and somehwere we can even
// think and want to have O(n) instead of O(2n) and same space complexity
// so we wll have to remove internal while loop

#include <iostream>
#include <vector>
using namespace std;

int lengthLongestSubArrayWith1(vector<int> arr, int k) {
    int n = arr.size();
    int l = 0, r = 0;
    int maxlen = 0, zeroC = 0;

    while (r < n) {
        if (arr[r] == 0) zeroC++;

        // If zeros exceed k, shrink the window from left
        if (zeroC > k) {
            if (arr[l] == 0) zeroC--;
            l++;
        }

        // Only update max length and move right if within limit
            maxlen = max(maxlen, r - l + 1);
            r++;  // Move right pointer only inside this condition
    }

    return maxlen;
}

int main() {
    vector<int> arr = {1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0};
    int k = 2;

    cout << "Longest subarray length: " << lengthLongestSubArrayWith1(arr, k) << endl;
    return 0;
}
