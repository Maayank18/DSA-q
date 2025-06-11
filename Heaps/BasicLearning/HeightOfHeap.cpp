//  height refers to -  the lonegst path from root to leaf node
// the number of EDGES will be our height

// if we try pen paper appraoch and try to find the pattern
// 2 ^ height = number of nooes present


// TC -> log(N) = n is number of nodes
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> heap = {10, 3, 8, 9, 5, 13, 18, 14, 11, 70};
    int n = heap.size();

    if(n == 1){
        cout<<" the heigh of tree is "<< n;
    }else{
        int height = log2(n);
        cout<<" the height of given tree is : "<<height<<endl;
    }

    return 0;
}


// or we can do this also

// int height  =  0;

// while(n > 1){
//     height++;
//     n = n / 2;
// }

// return height;