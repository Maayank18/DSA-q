#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value;
    int weight;
};

class Solution {
public:
    // Comparator function to sort Items by value/weight ratio
    static bool comp(const Item &a, const Item &b) {
        return (double)a.value / a.weight > (double)b.value / b.weight;
    }

    double fractionalKnapsack(int W, Item arr[], int n) {
        // Sorting items by value/weight ratio
        sort(arr, arr + n, comp);

        int curWeight = 0;
        double finalValue = 0.0;

        for (int i = 0; i < n; i++) {
            if (curWeight + arr[i].weight <= W) {
                curWeight += arr[i].weight;
                finalValue += arr[i].value;
            } else {
                int remain = W - curWeight;
                finalValue += (double)arr[i].value / arr[i].weight * remain;
                break;
            }
        }

        return finalValue;
    }
};

int main() {
    int n = 3, weight = 50;
    Item arr[] = {{100, 20}, {60, 10}, {120, 30}};
    
    Solution obj;
    double ans = obj.fractionalKnapsack(weight, arr, n);
    
    cout << "The maximum value is " << fixed << setprecision(2) << ans << endl;
    return 0;
}
