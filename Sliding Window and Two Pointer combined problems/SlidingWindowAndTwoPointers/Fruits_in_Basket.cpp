// Fruits in Baskets Problem Explanation
// The Fruits in Baskets problem is a variation of the Longest Subarray with At Most
// K Distinct Elements problem, specifically with K = 2.
// The goal is to find the longest contiguous subarray (or substring, if
// dealing with strings) that contains at most two distinct elements (fruit types).

// Examples
// vector<int> fruits = {1, 2, 1, 2, 3};
// output 4

// BRUTE FORCE -> this will include the usage of set data structure as only
// set data structure is the one which stores the unique element
// being the brute force solution we will generate all the subarray
// TIME COMPLEXITY -> O(N^2)
// SPACE COMPLEXITY -> O(1) because it is storing the k distinct fruit and
// in this case it is 2 and it is as good as O(1)

// #include<iostream>
// #include<set>
// #include<vector>
// using namespace std;

// int MaxLengthofDifferentFruits( vector<int> arr, int k){
//     int n = arr.size();
//     int maxlen = 0;
//     for(int i = 0;i<n; i++){
//         set<int> s;
//         for(int j = i; j<n; j++){
//             s.insert(arr[j]);
//             if(s.size()<=2){
//                 maxlen = max(maxlen,j-i+1);
//             }else{
//                 break;
//             }
//         }
//     }
//     return maxlen;
// }

// int main(){
//     vector<int> arr = {1, 2, 1, 2, 3};
//     int mLength = MaxLengthofDifferentFruits(arr,2);
//     cout<<" the max fruits of k different types are : "<<mLength<<endl;
//     return 0;
// }


// A better approach will include 2 pointer approach 
// TIME COMPLEXITY -> O(N) + O(N - for l almost)
// SPACE COMPLEXITY O(k = 2)
// #include <iostream>
// #include <map>
// #include <vector>
// using namespace std;

// int lengthOfMaxfruitsOfTypeK(vector<int> arr, int k)
// {
//     int n = arr.size();
//     int l = 0;
//     int r = 0;
//     int maxlen = 0;
//     map<int, int> mpp; // storing <differentType,frequency>

//     while (r < n)
//     {
//         mpp[arr[r]]++;

//         while (mpp.size() > k) {  // Shrink window if more than k types
//             mpp[arr[l]]--;
//             if (mpp[arr[l]] == 0) 
//                 mpp.erase(arr[l]);  // Remove fruit type if count is 0
//             l++;
//         }

        
//         maxlen = max(maxlen, r - l + 1);
//         r++;
//     }
//     return maxlen;
// }

//     int main()
//     {
//         vector<int> arr = {1, 2, 1, 2, 3};
//         int mLength = lengthOfMaxfruitsOfTypeK(arr, 2);
//         cout << " the max fruits of k different types are : " << mLength << endl;
//         return 0;
//     }



//OPTIMAL AOLUTION 

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int lengthOfMaxfruitsOfTypeK(vector<int> arr, int k)
{
    int n = arr.size();
    int l = 0;
    int r = 0;
    int maxlen = 0;
    map<int, int> mpp; // storing <differentType,frequency>

    while (r < n)
    {
        mpp[arr[r]]++;

        if(mpp.size()>k){
            mpp[arr[l]]--;
            if(mpp[arr[l]] == 0){
                mpp.erase(arr[l]);
            }
            l++;
        }

        
        maxlen = max(maxlen, r - l + 1);
        r++;
    }
    return maxlen;
}

    int main()
    {
        vector<int> arr = {1, 2, 1, 2, 3};
        int mLength = lengthOfMaxfruitsOfTypeK(arr, 2);
        cout << " the max fruits of k different types are : " << mLength << endl;
        return 0;
    }