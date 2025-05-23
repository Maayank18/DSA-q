// What this problem state is we are given two arrays 
// what we need to do is SORT the arrays and then MERGE them
// Then we need to find the MEDIAN of the mergedsorted array
// if merge.size() = even answer is (arr[n/2] + arr[n/2 - 1])/2
// if merge.size() = odd answer is  arr[n/2]


// BRUTE FORCE APPROACH 

// #include <iostream>
// #include <vector>
// #include <algorithm>  // Don't use bits/stdc++.h in production code
// using namespace std;

// double f2(vector<int> &result) {
//     int n = result.size();
//     if (n % 2 == 1) {
//         return result[n / 2];
//     } else {
//         return (result[n / 2 - 1] + result[n / 2]) / 2.0;
//     }
// }

// vector<int> f(vector<int> &arr1, vector<int> &arr2) {
//     int n = arr1.size(), m = arr2.size();
//     int i = 0, j = 0;
//     vector<int> ans;

//     while (i < n && j < m) {
//         if (arr1[i] <= arr2[j]) {
//             ans.push_back(arr1[i++]);
//         } else {
//             ans.push_back(arr2[j++]);
//         }
//     }

//     while (i < n) ans.push_back(arr1[i++]);
//     while (j < m) ans.push_back(arr2[j++]);

//     return ans;
// }

// int main() {
//     vector<int> arr1 = {1, 3, 5, 7};
//     vector<int> arr2 = {0, 2, 4, 6};

//     vector<int> result = f(arr1, arr2);
//     double median = f2(result);

//     cout << "The median of the sorted array is: " << median << endl;

//     return 0;
// }





// better APPROACH 




#include <bits/stdc++.h>
using namespace std;

double median(vector<int>& a, vector<int>& b) {
    //size of two given arrays:
    int n1 = a.size(), n2 = b.size();
    int n = n1 + n2; //total size
    //required indices:
    int ind2 = n / 2;
    int ind1 = ind2 - 1;
    int cnt = 0;
    int ind1el = -1, ind2el = -1;

    //apply the merge step:
    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (a[i] < b[j]) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }
        else {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }
    }

    //copy the left-out elements:
    while (i < n1) {
        if (cnt == ind1) ind1el = a[i];
        if (cnt == ind2) ind2el = a[i];
        cnt++;
        i++;
    }
    while (j < n2) {
        if (cnt == ind1) ind1el = b[j];
        if (cnt == ind2) ind2el = b[j];
        cnt++;
        j++;
    }

    //Find the median:
    if (n % 2 == 1) {
        return (double)ind2el;
    }

    return (double)((double)(ind1el + ind2el)) / 2.0;
}

int main()
{
    vector<int> a = {1, 4, 7, 10, 12};
    vector<int> b = {2, 3, 6, 15};
    cout << "The median of two sorted array is " << fixed << setprecision(1)
         << median(a, b) << '\n';
}

