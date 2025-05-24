// so basically our aim isto find the median of the matrix
//  coniderinf that hypothetically the numbers are in 1D array
// matrix is row wise sorted


// BRUTE FORCE SOLUTION
//  TC -> O(nlogn) + O(n^2)
//  SC -> O(n)
#include<iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int medianElement(vector<int> &temp){
    int n = temp.size();

    if(n%2 == 1){
        return temp[n/2];
    }else if(n%2 == 0){
        return (temp[n/2] + temp[(n/2)-1])/2;
    }
}

int f(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    vector<int> temp;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            temp.push_back(mat[i][j]);
        }
    }

    sort(temp.begin(),temp.end());

    return medianElement(temp);
}

int main(){
    vector<vector<int>> mat = {{1,5,7,9,11},
                               {2,3,4,5,10},
                               {9,10,12,14,16}};
    
    int median = f(mat);
    cout<<" the median of this 2d matrix is "<< median << endl;
    return 0;
}







// OPTIMAL APPROACH 

                                    
#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &arr, int x, int n) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] > x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int x) {
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cnt += upperBound(matrix[i], x, n);
    }
    return cnt;
}

int median(vector<vector<int>> &matrix, int m, int n) {
    int low = INT_MAX, high = INT_MIN;

    //point low and high to right elements:
    for (int i = 0; i < m; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }

    int req = (n * m) / 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req) low = mid + 1;
        else high = mid - 1;
    }
    return low;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4, 5},
        {8, 9, 11, 12, 13},
        {21, 23, 25, 27, 29}
    };
    int m = matrix.size(), n = matrix[0].size();
    int ans = median(matrix, m, n);
    cout << "The median element is: " << ans << endl;
    return 0;
}
                                    
                                