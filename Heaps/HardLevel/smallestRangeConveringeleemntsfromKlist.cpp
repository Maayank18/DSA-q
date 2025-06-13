#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;

vector<int> smallestRange(vector<vector<int>> &arr){
    // min heap: stores {value, {row, column}}
    priority_queue<pair<int,pair<int,int>>,
                   vector<pair<int,pair<int,int>>>,
                   greater<pair<int,pair<int,int>>>> pq;    

    int minimum;
    int maximum = INT_MIN;  // Fix 1: Initialize maximum

    // Step 1: Push the first element of every list
    for(int i = 0; i < arr.size(); i++){
        pq.push(make_pair(arr[i][0], make_pair(i, 0)));
        maximum = max(maximum, arr[i][0]);
    }

    minimum = pq.top().first;
    vector<int> result(2);
    result[0] = minimum;
    result[1] = maximum;

    pair<int,pair<int,int>> temp;
    int element;
    int row;
    int column;

    while(pq.size() == arr.size()){
        temp = pq.top();
        pq.pop();
        element = temp.first;
        row = temp.second.first;
        column = temp.second.second;

        // Check if there's a next element in the same row
        if(column + 1 < arr[row].size()){
            column++;
            pq.push(make_pair(arr[row][column], make_pair(row, column)));
            maximum = max(maximum, arr[row][column]);
            minimum = pq.top().first;  // Fix 2: Always update minimum from top

            // Update the result if current range is smaller
            if(maximum - minimum < result[1] - result[0]){
                result[0] = minimum;
                result[1] = maximum;
            }
        } else {
            break;  // No more elements in this row, can't include all lists
        }
    }

    return result;
}

int main(){
    vector<vector<int>> arr = {
        {4, 10, 15, 24, 26},
        {0, 9, 12, 20},
        {5, 18, 22, 30}
    };
    
    vector<int> ans = smallestRange(arr);
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}
