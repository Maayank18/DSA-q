#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

struct data{
    vector<int> start;
    vector<int> end;
    int position;
};

int NumberOfMeetingPossible(vector<int> start, vector<int> end, int n){
    data arr[n];

    for(int i = 0; i<n; i++){
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].position = i+1;
    }

    bool comp( data val1, data val2){
        return val1.end<val2.end;
    }

    sort(arr,arr+n,comp);
}