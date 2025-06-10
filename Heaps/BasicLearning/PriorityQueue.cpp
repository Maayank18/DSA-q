// Priority Queue in case of heap the implement as followed
// when a high number has a high priority we yse a max heap
// when a comapritively low number has high priority we use min heap

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    // priority_queue<int> p; // max heap;
    // p.push(10);
    // p.push(20);
    // p.push(11);
    // p.push(18);
    // p.push(15);

    // // top refers to max element in priority queue
    // cout<<p.top()<<endl;

    // // deleting
    // p.pop();
    // cout<<p.top()<<endl;

    // // printing all element 
    // while(!p.empty()){
    //     cout<<p.top()<<" ";
    //     p.pop();
    // }


    // SIMILARLY FROM MIN HEAP
    priority_queue<int, vector<int>, greater<int>> p;
    p.push(10);
    p.push(20);
    p.push(11);
    p.push(18);
    p.push(15);

    // printing all
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
    return 0;
}