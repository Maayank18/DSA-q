// shortest Job first SJF is a scheduling policy that selects the waiting time/process 
// with the smallest time of execution 

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int averageWaitingTime(vector<int> jobs){
    int n = jobs.size();
    sort(jobs.begin(),jobs.end());
    int t_time = 0;
    int waiting_time = 0;

    for(int i = 0; i<n; i++){
        waiting_time+=t_time;
        t_time+=jobs[i];
    }

    return (waiting_time/n);
}

int main() {
    vector<int> jobs = {4, 3, 7, 1, 2};
    
    cout << "Array Representing Job Durations: ";
    for(int i = 0; i < jobs.size(); i++){
        cout << jobs[i] << " ";
    }
    cout << endl;
    
    float ans = averageWaitingTime(jobs);
    cout << "Average waiting time: "<< ans;
    cout << endl;

    return 0;
}