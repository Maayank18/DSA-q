// we will be given tow arrays and what we have to do is merge them
// 1. both the arrays will be sorted
// eg. arr1 = [1,3,5,7] and arr2 = [0,2,4,6]
// merged array = [0,1,2,3,4,5,6,7]

// BRUTE FORCE APPROACH 
// tc -> O(N+M)
// sc -> O(N+M)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

vector<int> f(vector<int> &arr1, vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();
    int i = 0; 
    int j = 0;
    vector<int> ans;

    while(i<n && j<m){

        if(arr1[i] <= arr2[j]){
            ans.push_back(arr1[i]);
            i++;
        }else{
            ans.push_back(arr2[j]);
            j++;
        }
    }

    while(i<n){
        ans.push_back(arr1[i]);
        i++;
    }

    while(j<m){
        ans.push_back(arr2[j]);
        j++;
    }

    return ans;
}

int main(){
    // and in case these are not sorted sort using the sort function  
    vector<int> arr1  ={1,3,5,7};
    vector<int> arr2 = {0,2,4,6};
    vector<int> result = f(arr1,arr2);

    for(auto it : result){
        cout<<it<<" ";
    }
    return 0;
}





// OPTIMAL SOLUTION PART 1
// here we actually had a tradeoff
// tc -> O(min(n,m)) + O(nlogn) +O(mlogm)
// sc -> O(1)
#include <bits/stdc++.h>
using namespace std;

void merge(long long arr1[], long long arr2[], int n, int m) {

    //Declare 2 pointers:
    int left = n - 1;
    int right = 0;

    //Swap the elements until arr1[left] is
    // smaller than arr2[right]:
    while (left >= 0 && right < m) {
        if (arr1[left] > arr2[right]) {
            swap(arr1[left], arr2[right]);
            left--, right++;
        }
        else {
            break;
        }
    }

    // Sort arr1[] and arr2[] individually:
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}






// OPTIMAL APPROACH 2
// USE GAP METHOD  from shell sort technique
// just for basic understanding u may or may not use it 




#include <bits/stdc++.h>
using namespace std;

void swapIfGreater(long long arr1[], long long arr2[], int ind1, int ind2) {
    if (arr1[ind1] > arr2[ind2]) {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge(long long arr1[], long long arr2[], int n, int m) {
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}

int main()
{
    long long arr1[] = {1, 4, 8, 10};
    long long arr2[] = {2, 3, 9};
    int n = 4, m = 3;
    merge(arr1, arr2, n, m);
    cout << "The merged arrays are: " << "\n";
    cout << "arr1[] = ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << "\narr2[] = ";
    for (int i = 0; i < m; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}






