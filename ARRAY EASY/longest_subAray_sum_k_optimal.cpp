#include<iostream>
using namespace std;

int length_longest_subArray( int arr[], int n, int k){
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int maxLen = 0;

    while(right<n){
        while(left<right && sum>k){
            sum -=arr[left];
            left++;
        }
        if( sum == k){
            maxLen = max(maxLen,right-left+1);
        }
        right++;
        sum=+arr[right];
    }
    return maxLen;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    long long t;
    cout << "Enter the sum required: ";
    cin >> t;

    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Array entered by user: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int length = length_longest_subArray(arr, n, t);
    cout << "The length of the longest subarray is: " << length << endl;

    return 0;
}