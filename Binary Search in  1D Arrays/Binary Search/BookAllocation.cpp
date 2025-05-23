// this problems gives us an array that contains n books with their pages mentioned in it 
// and we are give number of children
// eg. PagesOfBook = {25,46,28,49,24}, students = 4;

// our task is to find the maximums pages assigned to a student should be minimum 
// given that :
// 1. each student should get atleast one book
// 2. each book should be given to one child only 
// 3. book should be given in continuous manner 

// 1 -> 25,46 | 28 | 49 | 24 -> max = 71
// 2 -> 25 | 46,28 | 49 | 24 -> max = 74
// 3 -> 25 | 46 | 28,49 | 24 -> max = 77
// 4 -> 25 | 46 | 28 | 49,24 -> max = 73

// return 71 as its the minimum of the maximum and -1 if not possible 




// BRUTE FORCE APPROACH 
// WE CAN DO A LINEAR SEARCH AND CHECK WHICH NUMBER SATIFIES ALL
// AND WHICH EVER SATISFIES THE THE FIRST WILL BE THE ANSWER
// base case if books < student so alloaction cant happen
// what will be our range for linear search -> highest of given pages to submission of all
// TC -> O(SUM-MAX) * O(N)
// SC -> O(1)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &pagesOfBooks, int pages){

    int n = pagesOfBooks.size();
    int studentCounter = 1;
    int pageswithstudent = 0;

    for(int i = 0; i<n; i++){
        if(pageswithstudent + pagesOfBooks[i] <= pages){
            pageswithstudent += pagesOfBooks[i];
        }else{
            studentCounter++;
            pageswithstudent = pagesOfBooks[i];
        }
    }
    return studentCounter;
}

int f(vector<int> &pagesOfBooks, int students ){

    int n = pagesOfBooks.size();

    // base case 
    if( n < students){
        return -1;
    }

    int mini = INT_MAX;
    int maxi = 0;

    // max range would be submission of all elements 
    for(int i = 0; i<n; i++){
        maxi += pagesOfBooks[i];
    }

    // min range would be highest element of array
    for(int i = 0; i<n; i++){
        mini = min(mini,pagesOfBooks[i]);
    }

    for(int pages = mini; pages<=maxi; pages++ ){
        int cntStudent = func(pagesOfBooks,pages);
        if(cntStudent == students){
            return pages;
        }
    }
}

int main(){
    vector<int> pagesOfBooks = {25,46,28,49,24};
    int students = 4;
    int minimumOfmaximumPages = f(pagesOfBooks,students);
    cout<<" the minimum of maximum is : "<<minimumOfmaximumPages<<endl;
    return 0;
}






// OPTIMAL APPROACH - BINARY SEARCH 

#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int func(vector<int> &pagesOfBooks, int pages){

    int n = pagesOfBooks.size();
    int studentCounter = 1;
    int pageswithstudent = 0;

    for(int i = 0; i<n; i++){
        if(pageswithstudent + pagesOfBooks[i] <= pages){
            pageswithstudent += pagesOfBooks[i];
        }else{
            studentCounter++;
            pageswithstudent = pagesOfBooks[i];
        }
    }
    return studentCounter;
}

int f(vector<int> &pagesOfBooks, int students ){

    int n = pagesOfBooks.size();

    // base case 
    if( n < students){
        return -1;
    }

    int mini = INT_MAX;
    int maxi = 0;

    // max range would be submission of all elements 
    for(int i = 0; i<n; i++){
        maxi += pagesOfBooks[i];
    }

    // min range would be highest element of array
    for(int i = 0; i<n; i++){
        mini = min(mini,pagesOfBooks[i]);
    }

    int low = mini;
    int high = maxi;

    while(low<=high){
        int mid = low + (high-low)/2;
        int cntStudent = func(pagesOfBooks,mid);

        if(cntStudent > students){
            low = mid + 1;
        }else{
            high = mid - 1;

        }
        
    }

    // for(int pages = mini; pages<=maxi; pages++ ){
    //     int cntStudent = func(pagesOfBooks,pages);
    //     if(cntStudent == students){
    //         return pages;
    //     }
    // }


    return low;
}

int main(){
    vector<int> pagesOfBooks = {25,46,28,49,24};
    int students = 4;
    int minimumOfmaximumPages = f(pagesOfBooks,students);
    cout<<" the minimum of maximum is : "<<minimumOfmaximumPages<<endl;
    return 0;
}