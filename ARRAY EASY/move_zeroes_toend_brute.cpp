// this is the brute force solution having a time and 
//space complexity of O(1) as it doesnt have any internal 
//loops


#include<iostream>
#include<vector>
using namespace std;

void move_zeroes(vector<int> &num){
    vector<int> temp1;

    for( int i = 0; i<num.size(); i++){
        if(num[i]!=0){
            temp1.push_back(num[i]);
        }
    }
    int nz = temp1.size();
    for(int i = 0; i<nz; i++){
        num[i] = temp1[i];
    }

    for(int i = nz; i<num.size(); i++){
        num[i] = 0;
    }
}

int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    vector<int> num(n);
    for( int i = 0; i<num.size(); i++){
        cin>>num[i];
    }
    cout<<" Original array ";
    for( int i = 0; i<num.size(); i++){
        cout<<num[i]<<" ";
    }
    cout<<endl;

    move_zeroes(num);

    cout<<" after rotating array ";
    for( int i = 0; i<num.size(); i++){
        cout<<num[i]<<" ";
    }
    return 0;
}


// now talking about the optimal solution it may be using the two pointer approach
//having the time complexity of O(n) and space complexity of O(1) 

#include<iostream>
#include<vector>
using namespace std;

vector<int> sort_it_out(vector<int> &arr) {
    int j = -1;

    // Find the first occurrence of 0
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == 0 && j == -1) { // Fix: Only set `j` to the first occurrence of 0
            j = i;
        }
    }

    if (j == -1) return arr; // If no zero is found, return the array as it is.

    // Swap non-zero elements after the first zero
    for (int i = j + 1; i < arr.size(); i++) {
        if (arr[i] != 0) {
            swap(arr[i], arr[j]); // Use `swap` function for clarity
            j++;
        }
    }

    return arr;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr = sort_it_out(arr);

    cout << "After sorting 0s to the left: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
