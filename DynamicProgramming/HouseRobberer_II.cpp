// Problem Statement:
// You are a robber who is planning to rob houses along a street. However, 
// there are certain restrictions:

// You cannot rob two adjacent houses.

// The houses are arranged in a circle, so the first and the last houses are also adjacent.
// Your goal is to determine the maximum amount of money you can rob,
// considering the restriction of not robbing two adjacent houses.



// SIMILAR TO MAX SUM ADJACENT PROBLEM WITH A SLIGHT CHANGE FINDFING THE MAX 
// OUT OF first removing first and find answer 
// them remove lasta nd then find the naswer 
// at last max of two answer 


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class HouseRobber2 {
public:
    // Helper function for the DP logic (works for non-circular case)
    int robLinear(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev2 = 0; // Max sum excluding the previous element
        int prev1 = nums[0]; // Max sum including the first element
        
        for (int i = 1; i < n; i++) {
            int current = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = current;
        }
        
        return prev1;
    }

    // Function for solving the circular problem by solving two cases
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: Rob houses from index 0 to n-2 (exclude the last house)
        vector<int> nums1(nums.begin(), nums.end() - 1);
        // Case 2: Rob houses from index 1 to n-1 (exclude the first house)
        vector<int> nums2(nums.begin() + 1, nums.end());
        
        // Return the maximum of the two cases
        return max(robLinear(nums1), robLinear(nums2));
    }
};

int main() {
    HouseRobber2 solution;
    
    vector<int> nums = {2, 3, 2};  // Example input (House Robber II with circular arrangement)
    
    // Call the function to get the result
    cout << "Maximum amount of money that can be robbed: " << solution.rob(nums) << endl;
    
    return 0;
}
