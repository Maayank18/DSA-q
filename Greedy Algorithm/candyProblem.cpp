#include <iostream>
#include <vector>
using namespace std;

int minCandies(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> candies(n, 1);  // Step 1: Every child gets at least 1 candy

    // Step 2: Left to Right check
    for (int i = 1; i < n; i++) {
        if (ratings[i] > ratings[i - 1]) {
            candies[i] = candies[i - 1] + 1;
        }
    }

    // Step 3: Right to Left check
    for (int i = n - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            candies[i] = max(candies[i], candies[i + 1] + 1);
        }
    }

    // Step 4: Compute the total candies
    int totalCandies = 0;
    for (int c : candies) {
        totalCandies += c;
    }

    return totalCandies;
}

int main() {
    vector<int> ratings = {1, 0, 2};  // Example ratings
    cout << "Minimum candies required: " << minCandies(ratings) << endl;
    return 0;
}
