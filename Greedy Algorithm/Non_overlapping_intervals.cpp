#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool comp(vector<int> a, vector<int> b){
    return a[1]<b[1];
}

int eraseOverlapIntervals(vector<vector<int>> intervals){
    int n = intervals.size();
    sort(intervals.begin(),intervals.end(),comp);

    int Removalcounter = 0;
    int lastend = intervals[0][1];

    for(int i = 1; i<n; i++){
        if(intervals[i][0]<lastend){
            Removalcounter++;
        }else{
            lastend = intervals[i][1];
        }
    }
    return Removalcounter;
}

int main() {
    vector<vector<int>> intervals = {{1,2}, {2,3}, {3,4}, {1,3}};
    cout << "Minimum intervals to remove: " << eraseOverlapIntervals(intervals) << endl;
    return 0;
}