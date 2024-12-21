// this code basically aims for finding the element that only occurs once but 
//other elements occuring twice having a time comlexity of O(n) As the array is 
//being traversed only once and space complexity of O(1) 
// here in depth we are using the knowledge and workcase of xor 


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

// 1 1 2 3 3 4 4

#include<iostream>
using namespace std;

int count( int arr[], int n){
    for(int i =0; i<n; i++){
        int num = arr[i];
        int cnt = 0;
        for( int j = 0; j<n; j++){
            if(arr[j] == num){
                cnt++;
            }
        }
        if(cnt == 1) return num;
    }
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    int arr[n];

    for( int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<" The arrays entered by the user : ";
    for( int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int value = count(arr,n);
    cout<<" number appearing once : "<<value;
    return 0;
}