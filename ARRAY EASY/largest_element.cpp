// this is optimal solution having a time complexity of O(n) { O(n)+O(n)+O(n)}
#include<iostream>
using namespace std;

int findlargest(int arr[], int n){
    int max = arr[0];
    for(int i = 0; i<n; i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}
int main(){
    int n;
    cout<<" enter the size of array : ";
    cin>>n;

    int arr[n];
    for( int i = 0; i<n; i++){
        cin>>arr[i];
    }

    cout<<" Elements of array are : ";
    for( int i = 0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    int largest = findlargest(arr,n);
    cout<<" The largest element is : "<<largest;
    return 0;
}

// -----------------------------------------------------------------------------------------------------------------
// ( Finding the largest element by sorting the array and giving back the last value)
// having a TC = O(n^2)
#include<iostream>
#include<vector>
using namespace std;

void bubble_sort(vector<int> &arr){
    for(int i = 0; i<arr.size(); i++){
        for(int j = i+1; j<arr.size(); j++){
            if(arr[i]>arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return;
}

int main(){
    int n;
    cout<<" enter the number of elements in array : ";
    cin>>n;

    vector<int> arr(n);
    for(int i = 0; i<arr.size(); i++){
        cin>>arr[i];
    }

    bubble_sort(arr);

    cout<<" THE LARGEST ELEMENT IS : "<<arr[n-1];
    return 0;
}
