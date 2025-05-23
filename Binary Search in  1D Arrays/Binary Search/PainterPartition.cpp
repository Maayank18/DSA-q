// Painter partition Problem 
// We are given an arr in which we are given different time taken to paint wall
// we are given number of painters
// eg TimeWall = {10,20,30,40}
// painters = 2

// we can do like 
// 10 | 20,30,40 max = 90
// 10,20 | 30,40 max = 70
// 10,20,30 | 40 max = 60
// we have to return the min(max) = 60




// BRUTE FORCE APPROACH
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// int func(vector<int> &TimeWall, int Time){
//     int n = TimeWall.size();
//     int countingPainter = 1;
//     int timeWithPainter = 0;

//     for(int i = 0; i<n; i++){
//         if(timeWithPainter + TimeWall[i] <= Time){
//             timeWithPainter += TimeWall[i];
//         }else{
//             countingPainter++;
//             timeWithPainter = TimeWall[i];
//         }
//     }
//     return countingPainter;
// }

// int f(vector<int> &TimeWall, int painters){
//     int n = TimeWall.size();

//     // base case if wall 1 and 2 painters
//     if(n < painters){
//         return -1;
//     }

//     int mini = INT_MAX;
//     for(int i = 0; i<n; i++){
//         mini = min(mini,TimeWall[i]);
//     }

//     int maxi = 0;
//     for(int i = 0; i<n; i++){
//         maxi += TimeWall[i];
//     }

//     for(int Time = mini; Time<=maxi; Time++){
//         int cntPainters = func(TimeWall,Time);

//         if(cntPainters == painters){
//             return Time;
//         }
//     }

// }

// int main(){
//     vector<int> TimeWall = {10,20,30,40};
//     int painters = 2;
//     int minOfmax = f(TimeWall,painters);
//     cout<<" the maximum of minimum time is : "<<minOfmax<<endl;
//     return 0;
// }





// OPTIMAL APPROACH USING THE BIANRY SEARCH 

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &TimeWall, int Time){
    int n = TimeWall.size();
    int countingPainter = 1;
    int timeWithPainter = 0;

    for(int i = 0; i<n; i++){
        if(timeWithPainter + TimeWall[i] <= Time){
            timeWithPainter += TimeWall[i];
        }else{
            countingPainter++;
            timeWithPainter = TimeWall[i];
        }
    }
    return countingPainter;
}

int f(vector<int> &TimeWall, int painters){
    int n = TimeWall.size();

    // base case if wall 1 and 2 painters
    if(n < painters){
        return -1;
    }

    int mini = INT_MAX;
    for(int i = 0; i<n; i++){
        mini = min(mini,TimeWall[i]);
    }

    int maxi = 0;
    for(int i = 0; i<n; i++){
        maxi += TimeWall[i];
    }

    int low = mini;
    int high = maxi;

    while(low<=high){
        int mid = low + (high-low)/2;


        int cntPainter = func(TimeWall,mid);

        if(cntPainter > painters){
            low = mid + 1;
        }else{
            high = mid -1;
        }
    }

    // for(int Time = mini; Time<=maxi; Time++){
    //     int cntPainters = func(TimeWall,Time);

    //     if(cntPainters == painters){
    //         return Time;
    //     }
    // }
    return low;
}

int main(){
    vector<int> TimeWall = {10,20,30,40};
    int painters = 2;
    int minOfmax = f(TimeWall,painters);
    cout<<" the maximum of minimum time is : "<<minOfmax<<endl;
    return 0;
}