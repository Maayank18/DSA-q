#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

struct data{
    int start;
    int end;
    int position;
};

bool comp(data val1, data val2){
    return val1.end<val2.end;
}

int NoOfMeeting(vector<int> start, vector<int> end, int N){ // n == size
    vector<data> arr(N);

    for(int i = 0; i<N; i++){
        arr[i].start = start[i];
        arr[i].end = end[i];
        arr[i].position = i+1;
    }

    sort(arr.begin(),arr.end(),comp);

    int count = 1;
    int freeTime = arr[0].end;
    vector<int> FindingPositionsFree;

    for(int i = 1; i<N-1; i++){
        if(arr[i].start>freeTime){
            count++;
            freeTime = arr[i].end;
            FindingPositionsFree.push_back(arr[i].position);
        }
    }

    return count;
}

int main(){
    int n = 6;
   vector<int> start = {1,3,0,5,8,5};
   vector<int> end = {2,4,5,7,9,9};
   int maxMeet = NoOfMeeting(start, end, n);
   cout<<" possible meetings are : "<<maxMeet<<endl;
   return 0;
}
