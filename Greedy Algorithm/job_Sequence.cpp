#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job 
struct jobDetails {
    int job_id;
    int job_deadline;
    int job_profit;
};

// Comparison function to sort jobs in descending order of profit
bool comp(jobDetails val1, jobDetails val2) {
    return val1.job_profit > val2.job_profit;
}

// Function to compute maximum profit
pair<int, int> maxProfitJob(jobDetails arr[], int n) {
    sort(arr, arr + n, comp);  // Sort jobs by profit in descending order
    
    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        maxDeadline = max(maxDeadline, arr[i].job_deadline);
    }

    vector<int> hash(maxDeadline + 1, -1);  // Initialize all slots as empty (-1)

    int maxProfit = 0, count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = arr[i].job_deadline; j > 0; j--) {
            if (hash[j] == -1) {  // If the slot is free
                count++;
                hash[j] = arr[i].job_id;
                maxProfit += arr[i].job_profit;
                break;  // Move to the next job
            }
        }
    }
    return {count, maxProfit};
}

int main() {
    int n = 4;
    jobDetails arr[n] = {{1, 4, 20}, {2, 1, 10}, {3, 2, 40}, {4, 2, 30}};

    // Function call
    pair<int, int> ans = maxProfitJob(arr, n);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}
