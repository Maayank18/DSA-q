#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int minPlatformRequired(vector<int> coming, vector<int> departure, int n) {
    int maxiP = 1;  // At least one platform needed initially

    for (int i = 0; i < n; i++) {
        int counter = 1;  // Reset counter for each train

        for (int j = i + 1; j < n; j++) {
            // Check for overlapping intervals
            if ((coming[i] >= coming[j] && coming[i] <= departure[j]) ||
                (coming[j] >= coming[i] && coming[j] <= departure[i])) { 
                    // go through if condition again
                    
                counter++;  // Overlapping train found
            }
        }
        maxiP = max(maxiP, counter);  // Update maximum platforms required
    }
    return maxiP;
}

int main() {
    vector<int> coming = {900, 945, 955, 1100, 1500, 1800};
    vector<int> departure = {920, 1200, 1130, 1150, 1900, 2000};
    int n = 6;

    cout << "Minimum number of Platforms required: " 
         << minPlatformRequired(coming, departure, n) 
         << endl;

    return 0;
}
