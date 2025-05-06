// this problem is somewhat similar to that of 2 sum , 3 sum problem 
// where we have to return the numbers making the sum up to the target elememt


// BRUTE FORCE SOLUTION -> would be the worse approach as it could take 
// upto O(n^4) as we gonna iterate among 4 loops lets see

// #include <iostream>
// #include <set>
// #include <vector>
// #include <algorithm> // For sort
// using namespace std;

// vector<vector<int>> sum_4(vector<int> arr, int target) {
//     int size = arr.size();
//     if (size < 4) return {}; // Return empty if less than 4 elements

//     set<vector<int>> st;

//     for (int i = 0; i < size; i++) {
//         for (int j = i + 1; j < size; j++) {
//             for (int k = j + 1; k < size; k++) {
//                 for (int l = k + 1; l < size; l++) {
//                     if (arr[i] + arr[j] + arr[k] + arr[l] == target) {
//                         vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
//                         sort(temp.begin(), temp.end()); // Sort quadruplet
//                         st.insert(temp); // Add to set
//                     }
//                 }
//             }
//         }
//     }

//     // Convert set to vector of vectors
//     vector<vector<int>> ans(st.begin(), st.end());
//     return ans;
// }

// int main() {
//     int n;
//     cout << "Enter the size of vector: ";
//     cin >> n;

//     if (n < 4) {
//         cout << "Size of the vector should be at least 4.\n";
//         return 0;
//     }

//     vector<int> arr(n);
//     cout << "Enter the elements of the vector: ";
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     int target;
//     cout << "Enter the target sum: ";
//     cin >> target;

//     vector<vector<int>> resultant = sum_4(arr, target);

//     cout << "Resultant quadruplets:\n";
//     for (int i = 0; i < resultant.size(); i++) {
//         for (int j = 0; j < resultant[i].size(); j++) {
//             cout << resultant[i][j] << " "; // Print each element in the row
//         }
//         cout << endl; // Move to the next row
//     }

//     return 0;
// }


// BETTER SOLUTION INCLUDES CHOPPING DOWN OF TIME COMPLEXITY FROM
// O(N^4) --> O(N^3)
// for this we would be using hashing approach

#include <iostream>
#include <set>
#include <vector>
#include <algorithm> // For sort
using namespace std;

vector<vector<int>> sum_4(vector<int> arr, int target) {
    set<vector<int>> st;

    // Iterate through all combinations of i, j, k
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            set<int> hashmap; 
            for (int k = j + 1; k < arr.size(); k++) {
                int fourth = target - (arr[i] + arr[j] + arr[k]);
                // Check if the fourth element exists in the hashmap
                if (hashmap.find(fourth) != hashmap.end()) {
                    vector<int> temp = {arr[i], arr[j], arr[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp); // Insert sorted quadruplet
                }
                hashmap.insert(arr[k]); // Add the current element to the hashmap
            }
        }
    }

    // Convert set to vector
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main() {
    int n;
    cout << "Enter the size of vector: ";
    cin >> n;

    if (n < 4) {
        cout << "Size of the vector should be at least 4.\n";
        return 0;
    }

    vector<int> arr(n);
    cout << "Enter the elements of the vector: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int target;
    cout << "Enter the target sum: ";
    cin >> target;

    vector<vector<int>> resultant = sum_4(arr, target);

    if (resultant.empty()) {
        cout << "No quadruplets found.\n";
    } else {
        cout << "Resultant quadruplets:\n";
        for (const auto& quad : resultant) {
            for (int num : quad) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}


// optimal approach 




#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size(); //size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    //calculating the quadruplets:
    for (int i = 0; i < n; i++) {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1]) continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l) {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target) {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++; l--;

                    //skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1]) k++;
                    while (k < l && nums[l] == nums[l + 1]) l--;
                }
                else if (sum < target) k++;
                else l--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    int target = 9;
    vector<vector<int>> ans = fourSum(nums, target);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}




