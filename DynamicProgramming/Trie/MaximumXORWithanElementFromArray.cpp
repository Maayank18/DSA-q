// this question is about finding the maximum XOR 
// we are given array = {1,4,3,5,6}
// we are also given a queryArray [Xi,Ai] = {(1,0),(2,3),(3,3)}
// our task is to find the max xor when xi is xored with any number less than equal
//  to ai that is present in array 
// eg/ if we have (1,0) what we can do is 1 ^ -1 becasue no elemnt lessthan equal to zero
//  eg (2,3) = 2^ 1 or 3 as it is lesser than equal to 3

// Extreme BRUTE FORCE SOLUTION


#include <iostream>
#include <vector>
using namespace std;

vector<int> maxXorBruteForce(vector<int> &arr, vector<pair<int,int>> &queries) {
    vector<int> results;

    for(auto &q : queries) {
        int xi = q.first;
        int ai = q.second;
        int maxXor = -1;

        // Check all elements <= ai
        for(int val : arr) {
            if(val <= ai) {
                int currentXor = xi ^ val;
                if(currentXor > maxXor) {
                    maxXor = currentXor;
                }
            }
        }

        results.push_back(maxXor);
    }

    return results;
}

int main() {
    vector<int> arr = {1,4,3,5,6};
    vector<pair<int,int>> queries = {{1,0}, {2,3}, {3,3}};

    vector<int> results = maxXorBruteForce(arr, queries);

    for(int res : results) {
        cout << res << endl;
    }

    return 0;
}
