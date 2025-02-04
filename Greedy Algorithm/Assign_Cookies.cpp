#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int findContentChildren(vector<int> Greed, vector<int> CookieSize){
    int n = Greed.size();
    int m = CookieSize.size();
    int l = 0;
    int r = 0;
    sort(Greed.begin(),Greed.end());
    sort(CookieSize.begin(),CookieSize.end());

    while(l<n && r<m){
        if(Greed[l]<=CookieSize[r]){
            r++;
        }
        l++;
    }
    return r;
}

int main() {
    vector<int> greed = {1, 5, 3, 3, 4};
    vector<int> cookieSize = {4, 2, 1, 2, 1, 3};
    
    cout << "Array Representing Greed: ";
    for(int i = 0; i < greed.size(); i++){
        cout << greed[i] << " ";
    }
    cout << endl;
    cout << "Array Representing Cookie Size: ";
    for(int i = 0; i < cookieSize.size(); i++){
        cout << cookieSize[i] << " ";
    }
    
    int ans = findContentChildren(greed, cookieSize);
    
    cout << endl << "No. of kids assigned cookies "<< ans;
    cout << endl;

    return 0;
}