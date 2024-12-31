// this problem basically aims to return either the indices or the number which is
// singly present i.e. for eg.[1,1,2,2,3,4,4,5,5] in this case very number is in pair
// except the 3 so our answer is 3 or index number of 3

// brute force approach - where we find the following number without bianry search

// #include <iostream>
// #include <vector>
// using namespace std;

// int single(int arr[], int n)
// {
//     if (n == 1)
//     {
//         return 0; // Single element is at index 0
//     }

//     int ans = -1;
//     for (int i = 0; i < n; i++)
//     {
//         if (i == 0)
//         {
//             if (arr[i] != arr[i + 1])
//             {
//                 ans = i;
//             }
//         }
//         else if (i == n - 1)
//         {
//             if (arr[i] != arr[i - 1])
//             {
//                 ans = i;
//             }
//         }
//         else
//         {
//             if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
//             {
//                 ans = i;
//             }
//         }
//     }
//     return ans;
// }

// int main(){
//     int n;
//     cout << "Enter the size of the array: ";
//     cin >> n;

//     vector<int> arr(n);

//     cout << "Enter the array elements:" << endl;
//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//     }

//     int result = single(arr.data(), n);

//     if (result == -1){
//         cout << "No such element exists!" << endl;
//     }
//     else{
//         cout << "The resultant number is: " << arr[result] << endl;
//     }
//     return 0;
// }


// binary search approach - it basically will need some visualisation power that is :
// eg. [1,1,2,2,3,3,4,5,5,6,6] , before our single element is found the pair is going 
// (even,odd) -> indexes and after the single element is found it is going 
// (odd,even)

#include <iostream>
#include <vector>
using namespace std;

int single(int arr[], int n) {
    if (n == 1) return 0; // Single element
    if (arr[0] != arr[1]) return 0; // Single element at the start
    if (arr[n - 1] != arr[n - 2]) return n - 1; // Single element at the end

    int low = 1;
    int high = n - 2;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is the single element
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1]) {
            return mid;
        }

        // Decide which half to eliminate
        if ((mid % 2 == 0 && arr[mid] == arr[mid + 1]) || (mid % 2 == 1 && arr[mid] == arr[mid - 1])) {
            low = mid + 1; // Move to the right half
        } else {
            high = mid - 1; // Move to the left half
        }
    }
    return -1; // No unique element found
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the array elements:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = single(arr.data(), n);

    if (result == -1) {
        cout << "No such element exists!" << endl;
    } else {
        cout << "The resultant number is: " << arr[result] << endl;
    }
    return 0;
}
