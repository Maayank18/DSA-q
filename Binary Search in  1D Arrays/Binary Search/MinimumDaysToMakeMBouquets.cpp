// the problem gives us an array which indicates the blooming day of flower
// it given m that is number of bouquets to be made
//  it gives k that tells the how many consecutive flower needed to make on bouquet
// and bouquet can only be formed if the flower is bloomed 
// eg [7,7,7,7,13,11,12,7] m = 2, k = 3

// if the day is 7 only flowers with blooming day 7 or less than seven can be used
// WE HAVE TO RETURN THE MINIMUM NUMBER OF DAYS TO MAKE THE M BOUQUETS

// if not possible return -1
//  this case is when m * k > arr.size()

// also my answer will always lie between smallest blooming day 
// in array and the highest blooming day



// BRUTE FORCE SOLUTION
// TC -> O(N) * O(maxi - min)
// SC -> O(1)
// #include<iostream>
// #include<vector>
// #include<bits/stdc++.h>
// using namespace std;

// bool possible(vector<int> &bloomingDays,int day, int m, int k){
//     int n = bloomingDays.size();
//     int cnt = 0;
//     int cntbouquets = 0;

//     for(int i = 0; i<n; i++){
//         if(bloomingDays[i] <= day){
//             cnt++;
//         }else{
//             cntbouquets += (cnt/k);
//             cnt = 0;
//         }
//     }
//     cntbouquets += (cnt/k);

//     if(cntbouquets >= m ) return true;
//     else return false;
// }

// int f(vector<int> &bloomingDays, int m, int k){
    
//     int n = bloomingDays.size();

//     // base case 
//     if( (m * k) > n) return -1;

//     // findnig the max and min value of array
//     int mini = INT_MAX;
//     int maxi = INT_MIN;

//     for(int i = 0; i<n; i++){
//         mini = min(mini,bloomingDays[i]);
//         maxi = max(maxi,bloomingDays[i]);
//     }

//     for(int day = mini; day<=maxi; day++){
//         if(possible(bloomingDays,day,m,k) == true){
//             return day;
//         }
//     }
//     return -1;

// }

// int main(){
//     vector<int> bloomingDays = {7,7,7,7,13,11,12,7};
//     int m = 2; // number of bouquets to be formed
//     int k = 3; // adjacent flowers required to make a bouquet
//     int minDays = f(bloomingDays,m,k);
//     cout<<" the minimum days required are : "<<minDays<<endl;
//     return 0;
// }






// OPTIMAL SOLUTION FOR BIANRY SEARCH 
//  TC-> O(N X log(max-min+1))
// SC -> O(1)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

bool possible(vector<int> &bloomingDays,int day, int m, int k){
    int n = bloomingDays.size();
    int cnt = 0;
    int cntbouquets = 0;

    for(int i = 0; i<n; i++){
        if(bloomingDays[i] <= day){
            cnt++;
        }else{
            cntbouquets += (cnt/k);
            cnt = 0;
        }
    }
    cntbouquets += (cnt/k);

    if(cntbouquets >= m ) return true;
    else return false;
}

int f(vector<int> &bloomingDays, int m, int k){
    
    int n = bloomingDays.size();

    // base case 
    if( (m * k) > n) return -1;

    // findnig the max and min value of array
    int mini = INT_MAX;
    int maxi = INT_MIN;

    for(int i = 0; i<n; i++){
        mini = min(mini,bloomingDays[i]);
        maxi = max(maxi,bloomingDays[i]);
    }

    int low = mini;
    int high = maxi;
    int ans = high; // my answer can always be the maximum day but findnfg the minimum day

    while(low<=high){
        int midDay = low + (high-low)/2;

        if(possible(bloomingDays,midDay,m,k) == true){
            ans = midDay;
            high = midDay - 1;

        }else{
            low = midDay + 1;
        }
    }
    return ans;
}

int main(){
    vector<int> bloomingDays = {7,7,7,7,13,11,12,7};
    int m = 2; // number of bouquets to be formed
    int k = 3; // adjacent flowers required to make a bouquet
    int minDays = f(bloomingDays,m,k);
    cout<<" the minimum days required are : "<<minDays<<endl;
    return 0;
}