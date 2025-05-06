#include <iostream>
#include <vector>
using namespace std;

void generating(vector<int>& nums, int totalSum, int index, vector<int> output, 
                vector<vector<int>>& ans, int k) {
    // base case
    if (index == nums.size()) {
        if (totalSum == k) {
            ans.push_back(output);
        }
        return;
    }

    // Include nums[index]
    output.push_back(nums[index]);
    generating(nums, totalSum + nums[index], index + 1, output, ans, k);

    // Exclude nums[index]
    output.pop_back(); // optional, since passed by value, but adds clarity
    generating(nums, totalSum, index + 1, output, ans, k);
}

vector<vector<int>> SubArraySumK(vector<int> nums, int k) {
    vector<vector<int>> ans;
    vector<int> output;
    generating(nums, 0, 0, output, ans, k);
    return ans;
}
