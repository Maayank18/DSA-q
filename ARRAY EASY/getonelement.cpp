#include<iostream>
using namespace std;

int getoneelement( int arr[], int n){
    int xorr = 0;
    for( int i = 0; i<n; i++){
        xorr = xorr ^ arr[i];
    }
    return xorr;

}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int result = getoneelement(arr, n);

    cout<<" required number is :"<<result;    
    return 0;
}