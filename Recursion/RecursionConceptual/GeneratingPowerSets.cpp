#include <iostream>
#include <vector>
using namespace std;

// Recursive function to generate all subsets of a given vector
void solving(vector<int> &nums, vector<int> &output, int index, vector<vector<int>> &ans) {
    // Base Case: If we have considered all elements
    if (index >= nums.size()) {
        ans.push_back(output); // Store the generated subset
        return;
    }

    // Exclude the current element and move to the next
    solving(nums, output, index + 1, ans);

    // Include the current element
    output.push_back(nums[index]); // Add current element to output
    solving(nums, output, index + 1, ans);

    // Backtrack: Remove the element before returning
    output.pop_back();
}

// Function to generate all subsets of a given set of numbers
vector<vector<int>> generateAllSubsets(vector<int> &nums) {
    vector<vector<int>> ans;  // Stores all subsets
    vector<int> output;  // Temporary list to build subsets
    int index = 0;  // Start from the first index
    solving(nums, output, index, ans);
    return ans;  // Return the generated subsets
}

// Function to print all subsets
void printSubsets(vector<vector<int>> &subsets) {
    cout << "All Subsets:\n";
    for (auto subset : subsets) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}\n";
    }
}

// Main function
int main() {
    vector<int> nums = {1, 2, 3};  // Input set

    // Generate all subsets
    vector<vector<int>> subsets = generateAllSubsets(nums);

    // Print the subsets
    printSubsets(subsets);

    return 0;
}
