// this is somehwere the brute force approach where we are taking and unnecessary a 
// k variable which is making our work O(n^3)


#include<iostream>
using namespace std;

int length_longest_subArray( int arr[], int n, int t){
    int len = 0;
    for( int i = 0; i<n; i++){
        int sum = 0;
        for( int j = i; j<n; j++){
             for( int k = i; k<j; k++){
                sum = sum + arr[k];
                if( sum == t){
                    len = max(len,j-i+1);
                }
             }
        }
    }
    return len;
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;
    cout<<endl;

    int t;
    cout<<" enter the sum required : ";
    cin>>t;

    int arr[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<" array entered by user : ";
    for( int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int length = length_longest_subArray(arr,n,t);

    cout<<" The length of longest SubArray is : "<<length;
    return 0;
}

// if we talk about the better solution the difference that will be made will 
// be we can remove an extra loop of k and it wont make any big difference 
// and our time comlexity will also become O(n^2)
#include<iostream>
using namespace std;

int length_longest_subArray( int arr[], int n, int t){
    int len = 0;
    for( int i = 0; i<n; i++){
        int sum = 0;
        for( int j = i; j<n; j++){
            sum = sum + arr[j];
            if(sum ==  t){
                len  = max(len,j-i+1);
            }
        }
    }
    return len;
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;
    cout<<endl;

    int t;
    cout<<" enter the sum required : ";
    cin>>t;

    int arr[n];

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<" array entered by user : ";
    for( int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int length = length_longest_subArray(arr,n,t);

    cout<<" The length of longest SubArray is : "<<length;
    return 0;
}

// npw talking about he hashing approach which is a better solution and will be 
// having a time comlexity of O(n) as we are covering the whole arrays once and even
// the space complexity will cost around O(n) for mapping all terms 
// IMPORTANT THING this particular code  cover exception for 0 if they come in between

#include <bits/stdc++.h>
using namespace std;

int length_longest_subArray(int arr[], int n, long long k) {
    map<long long, int> preSum; // To store the prefix sums and their first occurrence index
    int maxlen = 0;
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i]; // Incrementally add elements to the sum

        // Check if the current prefix sum equals the target
        if (sum == k) {
            maxlen = max(maxlen, i + 1); // Update maxlen if the whole subarray from 0 to i matches
        }

        // Check if (sum - k) is already in the map, meaning a subarray with sum k was found
        long long rem = sum - k;
        if (preSum.find(rem) != preSum.end()) {
            int len = i - preSum[rem]; // Calculate the length of the subarray
            maxlen = max(maxlen, len); // Update maxlen if this subarray is longer
        }

        // Store the current prefix sum in the map if not already present
        if (preSum.find(sum) == preSum.end()) { // covering the exception of zeroes
            preSum[sum] = i;
        }
    }

    return maxlen;
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

// optimal solution - a two pointer approach having time and space comlpecity 
//of O(n)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int length_longest_subArray(const vector<int>& arr, int n, int k) {
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int maxLen = 0;

    while (right < n) {
        // Reduce the window size from the left if the sum exceeds k
        while (left < right && sum > k) {
            sum -= arr[left];
            left++;
        }
        // Check if the sum matches k
        if (sum == k) {
            maxLen = max(maxLen, right - left + 1);
        }
        // Move the right pointer and add the next element
        right++;
        if (right < n) { // Ensure `right` is within bounds
            sum += arr[right];
        }
    }
    return maxLen;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int t;
    cout << "Enter the sum required: ";
    cin >> t;

    vector<int> arr(n);
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
